#include "pch.h"
#include "PerifericoDAO.h"
using namespace SmartParkingSystemDAO;
using namespace System::IO;  

PerifericoDAO::PerifericoDAO() {

}

List<IndicadorLed^>^ PerifericoDAO::buscarTodosIndicadoresLedArchivo() {
	List<IndicadorLed^>^ lista = gcnew List<IndicadorLed^>();

	String^ path = "IndicadorLed.txt";
	if (!File::Exists(path))
		return lista;

	array<String^>^ lineas = File::ReadAllLines(path);
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea))
			continue;

		array<String^>^ datos = linea->Split(separadores->ToCharArray());

		// Formato: id;ubicacion;fechaInst;fechaUltMant;estado;hayEmergencia;color;intensidad;estaEncendido;tipoLuz;modoOperacion
		if (datos->Length < 11)
			continue;

		int id = Int32::Parse(datos[0]);
		String^ ubi = datos[1];
		DateTime finst = DateTime::Parse(datos[2]);
		DateTime fult = DateTime::Parse(datos[3]);
		EstadoPeriferico estado = (EstadoPeriferico)Enum::Parse(EstadoPeriferico::typeid, datos[4]);
		bool emergencia = Boolean::Parse(datos[5]);
		String^ color = datos[6];
		int intensidad = Int32::Parse(datos[7]);
		bool estaEnc = Boolean::Parse(datos[8]);
		String^ tipoLuz = datos[9];
		String^ modoOp = datos[10];

		IndicadorLed^ led = gcnew IndicadorLed(id, ubi, finst, fult, estado, emergencia, color, intensidad, estaEnc, tipoLuz, modoOp);
		lista->Add(led);
	}
	return lista;
}

IndicadorLed^ PerifericoDAO::buscarIndicadorLedxIdArchivo(int idPeriferico) {
	List<IndicadorLed^>^ lista = buscarTodosIndicadoresLedArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == idPeriferico)
			return lista[i];
	}
	return nullptr;
}

void PerifericoDAO::registrarIndicadorLedArchivo(IndicadorLed^ led) {
	List<IndicadorLed^>^ lista = buscarTodosIndicadoresLedArchivo();
	lista->Add(led);
	escribirIndicadoresLedArchivo(lista);
}

void PerifericoDAO::modificarIndicadorLedArchivo(IndicadorLed^ led) {
	List<IndicadorLed^>^ lista = buscarTodosIndicadoresLedArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == led->getIdPeriferico()) {
			lista[i]->setUbicacion(led->getUbicacion());
			lista[i]->setFechaInstalacion(led->getFechaInstalacion());
			lista[i]->setFechaUltimoMant(led->getFechaUltimoMant());
			lista[i]->setEstado(led->getEstado());
			lista[i]->setHayEmergencia(led->getHayEmergencia());
			lista[i]->setColor(led->getColor());
			lista[i]->setIntesidad(led->getIntesidad());
			lista[i]->setEstaEncendido(led->getEstaEncendido());
			lista[i]->setTipoLuz(led->getTipoLuz());
			lista[i]->setModoOperacion(led->getModoOperacion());
			break;
		}
	}
	escribirIndicadoresLedArchivo(lista);
}

void PerifericoDAO::eliminarIndicadorLedArchivo(int idPeriferico) {
	List<IndicadorLed^>^ lista = buscarTodosIndicadoresLedArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == idPeriferico) {
			lista->RemoveAt(i);
			break;
		}
	}
	escribirIndicadoresLedArchivo(lista);
}

void PerifericoDAO::escribirIndicadoresLedArchivo(List<IndicadorLed^>^ lista) {
	String^ path = "IndicadorLed.txt";
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		IndicadorLed^ e = lista[i];
		lineas[i] =
			e->getIdPeriferico().ToString() + ";" +
			e->getUbicacion() + ";" +
			e->getFechaInstalacion().ToString("o") + ";" +
			e->getFechaUltimoMant().ToString("o") + ";" +
			e->getEstado().ToString() + ";" +
			e->getHayEmergencia().ToString() + ";" +
			e->getColor() + ";" +
			e->getIntesidad().ToString() + ";" +
			e->getEstaEncendido().ToString() + ";" +
			e->getTipoLuz() + ";" +
			e->getModoOperacion();
	}
	File::WriteAllLines(path, lineas);
}

// ============================================================
// SERVOMOTOR
// ============================================================
List<ServoMotor^>^ PerifericoDAO::buscarTodosServosArchivo() {
	List<ServoMotor^>^ lista = gcnew List<ServoMotor^>();
	String^ path = "ServoMotor.txt";
	if (!File::Exists(path))
		return lista;

	array<String^>^ lineas = File::ReadAllLines(path);
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea))
			continue;

		array<String^>^ d = linea->Split(separadores->ToCharArray());
		// id;ubi;fechaInst;fechaUltMant;estado;hayEmergencia;anguloActual;anguloMaxApertura;torque
		if (d->Length < 9)
			continue;

		int id = Int32::Parse(d[0]);
		String^ ubi = d[1];
		DateTime finst = DateTime::Parse(d[2]);
		DateTime fult = DateTime::Parse(d[3]);
		EstadoPeriferico estado = (EstadoPeriferico)Enum::Parse(EstadoPeriferico::typeid, d[4]);
		bool emergencia = Boolean::Parse(d[5]);
		double ang = Double::Parse(d[6]);
		double angMax = Double::Parse(d[7]);
		double torque = Double::Parse(d[8]);

		ServoMotor^ s = gcnew ServoMotor(id, ubi, finst, fult, estado, emergencia, ang, angMax, torque);
		lista->Add(s);
	}
	return lista;
}

ServoMotor^ PerifericoDAO::buscarServoMotorxIdArchivo(int idPeriferico) {
	List<ServoMotor^>^ lista = buscarTodosServosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == idPeriferico)
			return lista[i];
	}
	return nullptr;
}

void PerifericoDAO::registrarServoMotorArchivo(ServoMotor^ servo) {
	List<ServoMotor^>^ lista = buscarTodosServosArchivo();
	lista->Add(servo);
	escribirServosArchivo(lista);
}

void PerifericoDAO::modificarServoMotorArchivo(ServoMotor^ servo) {
	List<ServoMotor^>^ lista = buscarTodosServosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == servo->getIdPeriferico()) {
			lista[i]->setUbicacion(servo->getUbicacion());
			lista[i]->setFechaInstalacion(servo->getFechaInstalacion());
			lista[i]->setFechaUltimoMant(servo->getFechaUltimoMant());
			lista[i]->setEstado(servo->getEstado());
			lista[i]->setHayEmergencia(servo->getHayEmergencia());
			lista[i]->setAnguloActual(servo->getAnguloActual());
			lista[i]->setAnguloMaxApertura(servo->getAnguloMaxApertura());
			lista[i]->setTorque(servo->getTorque());
			break;
		}
	}
	escribirServosArchivo(lista);
}

void PerifericoDAO::eliminarServoMotorArchivo(int idPeriferico) {
	List<ServoMotor^>^ lista = buscarTodosServosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == idPeriferico) {
			lista->RemoveAt(i);
			break;
		}
	}
	escribirServosArchivo(lista);
}

void PerifericoDAO::escribirServosArchivo(List<ServoMotor^>^ lista) {
	String^ path = "ServoMotor.txt";
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		ServoMotor^ s = lista[i];
		lineas[i] = s->getIdPeriferico().ToString() + ";" + s->getUbicacion() + ";" + s->getFechaInstalacion().ToString("o") + ";" + s->getFechaUltimoMant().ToString("o") + ";" + s->getEstado().ToString() + ";" + s->getHayEmergencia().ToString() + ";" + s->getAnguloActual().ToString() + ";" + s->getAnguloMaxApertura().ToString() + ";" + s->getTorque().ToString();
	}
	File::WriteAllLines(path, lineas);
}

// ============================================================
// SENSOR OCUPACION
// ============================================================
List<SensorOcupacion^>^ PerifericoDAO::buscarTodosSensoresOcupacionArchivo() {
	List<SensorOcupacion^>^ lista = gcnew List<SensorOcupacion^>();
	String^ path = "SensorOcupacion.txt";
	if (!File::Exists(path))
		return lista;

	array<String^>^ lineas = File::ReadAllLines(path);
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea))
			continue;

		array<String^>^ d = linea->Split(separadores->ToCharArray());
		// id;ubi;fechaInst;fechaUltMant;estado;hayEmergencia;umbral;valor;detecta;fechaUltLect
		if (d->Length < 10)
			continue;

		int id = Int32::Parse(d[0]);
		String^ ubi = d[1];
		DateTime finst = DateTime::Parse(d[2]);
		DateTime fult = DateTime::Parse(d[3]);
		EstadoPeriferico estado = (EstadoPeriferico)Enum::Parse(EstadoPeriferico::typeid, d[4]);
		bool emergencia = Boolean::Parse(d[5]);
		double umbral = Double::Parse(d[6]);
		double valor = Double::Parse(d[7]);
		bool detecta = Boolean::Parse(d[8]);
		DateTime fultlect = DateTime::Parse(d[9]);

		SensorOcupacion^ s = gcnew SensorOcupacion(id, ubi, finst, fult, estado, emergencia, umbral, valor, detecta, fultlect);
		lista->Add(s);
	}
	return lista;
}

SensorOcupacion^ PerifericoDAO::buscarSensorOcupacionxIdArchivo(int idPeriferico) {
	List<SensorOcupacion^>^ lista = buscarTodosSensoresOcupacionArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == idPeriferico) {
			return lista[i];
		}
	}
	return nullptr;
}

void PerifericoDAO::registrarSensorOcupacionArchivo(SensorOcupacion^ sensor) {
	List<SensorOcupacion^>^ l = buscarTodosSensoresOcupacionArchivo();
	l->Add(sensor);
	escribirSensoresOcupacionArchivo(l);
}

void PerifericoDAO::modificarSensorOcupacionArchivo(SensorOcupacion^ sensor) {
	List<SensorOcupacion^>^ lista = buscarTodosSensoresOcupacionArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == sensor->getIdPeriferico()) {
			lista[i]->setUbicacion(sensor->getUbicacion());
			lista[i]->setFechaInstalacion(sensor->getFechaInstalacion());
			lista[i]->setFechaUltimoMant(sensor->getFechaUltimoMant());
			lista[i]->setEstado(sensor->getEstado());
			lista[i]->setHayEmergencia(sensor->getHayEmergencia());
			lista[i]->setUmbralDeteccion(sensor->getUmbralDeteccion());
			lista[i]->setValorLectura(sensor->getValorLectura());
			lista[i]->setDetectaVehiculo(sensor->getDetectaVehiculo());
			lista[i]->setFechaUltimaLectura(sensor->getFechaUltimaLectura());
			break;
		}
	}
	escribirSensoresOcupacionArchivo(lista);
}

void PerifericoDAO::eliminarSensorOcupacionArchivo(int idPeriferico) {
	List<SensorOcupacion^>^ l = buscarTodosSensoresOcupacionArchivo();
	for (int i = 0; i < l->Count; i++) {
		if (l[i]->getIdPeriferico() == idPeriferico) {
			l->RemoveAt(i); break;
		}
	}
	escribirSensoresOcupacionArchivo(l);
}

void PerifericoDAO::escribirSensoresOcupacionArchivo(List<SensorOcupacion^>^ lista) {
	String^ path = "SensorOcupacion.txt";
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		SensorOcupacion^ s = lista[i];
		lineas[i] = s->getIdPeriferico().ToString() + ";" + s->getUbicacion() + ";" + s->getFechaInstalacion().ToString("o") + ";" + s->getFechaUltimoMant().ToString("o") + ";" + s->getEstado().ToString() + ";" + s->getHayEmergencia().ToString() + ";" + s->getUmbralDeteccion().ToString() + ";" + s->getValorLectura().ToString() + ";" + s->getDetectaVehiculo().ToString() + ";" + s->getFechaUltimaLectura().ToString("o");
	}
	File::WriteAllLines(path, lineas);
}

// ============================================================
// LECTOR RFID
// ============================================================
List<LectorRFID^>^ PerifericoDAO::buscarTodosLectoresRFIDArchivo() {
	List<LectorRFID^>^ lista = gcnew List<LectorRFID^>();
	String^ path = "LectorRFID.txt";
	if (!File::Exists(path))
		return lista;

	array<String^>^ lineas = File::ReadAllLines(path);
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea))
			continue;

		array<String^>^ d = linea->Split(separadores->ToCharArray());
		// id;ubi;fechaInst;fechaUltMant;estado;hayEmergencia;frecOperacion;distanciaLecturaMax;idUltimaTarjeta;protocolo;esLecturaEntrada;potencia
		if (d->Length < 12) continue;
		int id = Int32::Parse(d[0]);
		String^ ubi = d[1];
		DateTime finst = DateTime::Parse(d[2]);
		DateTime fult = DateTime::Parse(d[3]);
		EstadoPeriferico estado = (EstadoPeriferico)Enum::Parse(EstadoPeriferico::typeid, d[4]);
		bool emergencia = Boolean::Parse(d[5]);
		double frec = Double::Parse(d[6]);
		double dist = Double::Parse(d[7]);
		String^ idTarj = d[8];
		String^ proto = d[9];
		bool esEntrada = Boolean::Parse(d[10]);
		double potencia = Double::Parse(d[11]);

		LectorRFID^ l = gcnew LectorRFID(id, ubi, finst, fult, estado, emergencia, frec, dist, idTarj, proto, esEntrada, potencia);
		lista->Add(l);
	}
	return lista;
}

LectorRFID^ PerifericoDAO::buscarLectorRFIDxIdArchivo(int idPeriferico) {
	List<LectorRFID^>^ lista = buscarTodosLectoresRFIDArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == idPeriferico) {
			return lista[i];
		}
	}
	return nullptr;
}

void PerifericoDAO::registrarLectorRFIDArchivo(LectorRFID^ lector) {
	List<LectorRFID^>^ l = buscarTodosLectoresRFIDArchivo();
	l->Add(lector);
	escribirLectoresRFIDArchivo(l);
}

void PerifericoDAO::modificarLectorRFIDArchivo(LectorRFID^ lector) {
	List<LectorRFID^>^ lista = buscarTodosLectoresRFIDArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == lector->getIdPeriferico()) {
			lista[i]->setUbicacion(lector->getUbicacion());
			lista[i]->setFechaInstalacion(lector->getFechaInstalacion());
			lista[i]->setFechaUltimoMant(lector->getFechaUltimoMant());
			lista[i]->setEstado(lector->getEstado());
			lista[i]->setHayEmergencia(lector->getHayEmergencia());
			lista[i]->setFrecOperacion(lector->getFrecOperacion());
			lista[i]->setDistanciaLecturaMax(lector->getDistanciaLecturaMax());
			lista[i]->setIdUltimaTarjeta(lector->getIdUltimaTarjeta());
			lista[i]->setProtocoloComunicacion(lector->getProtocoloComunicacion());
			lista[i]->setEsLecturaEntrada(lector->getEsLecturaEntrada());
			lista[i]->setPotenciaTransmicion(lector->getPotenciaTransmicion());
			break;
		}
	}
	escribirLectoresRFIDArchivo(lista);
}

void PerifericoDAO::eliminarLectorRFIDArchivo(int idPeriferico) {
	List<LectorRFID^>^ l = buscarTodosLectoresRFIDArchivo();
	for (int i = 0; i < l->Count; i++) {
		if (l[i]->getIdPeriferico() == idPeriferico) {
			l->RemoveAt(i); break;
		}
	}
	escribirLectoresRFIDArchivo(l);
}

void PerifericoDAO::escribirLectoresRFIDArchivo(List<LectorRFID^>^ lista) {
	String^ path = "LectorRFID.txt";
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		LectorRFID^ e = lista[i];
		lineas[i] = e->getIdPeriferico().ToString() + ";" + e->getUbicacion() + ";" + e->getFechaInstalacion().ToString("o") + ";" + e->getFechaUltimoMant().ToString("o") + ";" + e->getEstado().ToString() + ";" + e->getHayEmergencia().ToString() + ";" + e->getFrecOperacion().ToString() + ";" + e->getDistanciaLecturaMax().ToString() + ";" + e->getIdUltimaTarjeta() + ";" + e->getProtocoloComunicacion() + ";" + e->getEsLecturaEntrada().ToString() + ";" + e->getPotenciaTransmicion().ToString();
	}
	File::WriteAllLines(path, lineas);
}

// ============================================================
// BARRERA ACCESO
// ============================================================
List<BarreraAcceso^>^ PerifericoDAO::buscarTodasBarrerasAccesoArchivo() {
	List<BarreraAcceso^>^ lista = gcnew List<BarreraAcceso^>();
	String^ path = "BarreraAcceso.txt";
	if (!File::Exists(path))
		return lista;

	array<String^>^ lineas = File::ReadAllLines(path);
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea))
			continue;

		array<String^>^ d = linea->Split(separadores->ToCharArray());
		// id;ubi;fechaInst;fechaUltMant;estado;hayEmergencia;hayImpedimento;esEntrada;estaAbierto
		if (d->Length < 9) continue;
		int id = Int32::Parse(d[0]);
		String^ ubi = d[1];
		DateTime finst = DateTime::Parse(d[2]);
		DateTime fult = DateTime::Parse(d[3]);
		EstadoPeriferico estado = (EstadoPeriferico)Enum::Parse(EstadoPeriferico::typeid, d[4]);
		bool emergencia = Boolean::Parse(d[5]);
		bool imped = Boolean::Parse(d[6]);
		bool esEntrada = Boolean::Parse(d[7]);
		bool estaAb = Boolean::Parse(d[8]);

		/*BarreraAcceso^ b = gcnew BarreraAcceso(id, ubi, finst, fult, estado, emergencia, imped, esEntrada, estaAb);
		lista->Add(b); //Esta huevada estaba buggeando todo*/

		BarreraAcceso^ b = gcnew BarreraAcceso(imped, esEntrada, estaAb, nullptr, nullptr, nullptr, nullptr);
		// Inyectamos los datos base usando los métodos heredados
		b->setUbicacion(ubi);
		b->setFechaInstalacion(finst);
		b->setFechaUltimoMant(fult);
		b->setEstado(estado);
		b->setHayEmergencia(emergencia);
		b->setIdPeriferico(id);
	}
	return lista;
}

BarreraAcceso^ PerifericoDAO::buscarBarreraAccesoxIdArchivo(int idPeriferico) {
	List<BarreraAcceso^>^ l = buscarTodasBarrerasAccesoArchivo();
	for (int i = 0; i < l->Count; i++) {
		if (l[i]->getIdPeriferico() == idPeriferico) {
			return l[i];
		}
	}
	return nullptr;
}

void PerifericoDAO::registrarBarreraAccesoArchivo(BarreraAcceso^ barrera) {
	List<BarreraAcceso^>^ l = buscarTodasBarrerasAccesoArchivo();
	l->Add(barrera);
	escribirBarrerasAccesoArchivo(l);
}

void PerifericoDAO::modificarBarreraAccesoArchivo(BarreraAcceso^ barrera) {
	List<BarreraAcceso^>^ lista = buscarTodasBarrerasAccesoArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPeriferico() == barrera->getIdPeriferico()) {
			lista[i]->setUbicacion(barrera->getUbicacion());
			lista[i]->setFechaInstalacion(barrera->getFechaInstalacion());
			lista[i]->setFechaUltimoMant(barrera->getFechaUltimoMant());
			lista[i]->setEstado(barrera->getEstado());
			lista[i]->setHayEmergencia(barrera->getHayEmergencia());
			lista[i]->setHayImpedimento(barrera->getHayImpedimento());
			lista[i]->setEsEntrada(barrera->getEsEntrada());
			lista[i]->setEstaAbierto(barrera->getEstaAbierto());
			break;
		}
	}
	escribirBarrerasAccesoArchivo(lista);
}

void PerifericoDAO::eliminarBarreraAccesoArchivo(int idPeriferico) {
	List<BarreraAcceso^>^ l = buscarTodasBarrerasAccesoArchivo();
	for (int i = 0; i < l->Count; i++) {
		if (l[i]->getIdPeriferico() == idPeriferico) {
			l->RemoveAt(i); break;
		}
	}
	escribirBarrerasAccesoArchivo(l);
}

void PerifericoDAO::escribirBarrerasAccesoArchivo(List<BarreraAcceso^>^ lista) {
	String^ path = "BarreraAcceso.txt";
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		BarreraAcceso^ b = lista[i];
		lineas[i] = b->getIdPeriferico().ToString() + ";" + b->getUbicacion() + ";" + b->getFechaInstalacion().ToString("o") + ";" + b->getFechaUltimoMant().ToString("o") + ";" + b->getEstado().ToString() + ";" + b->getHayEmergencia().ToString() + ";" + b->getHayImpedimento().ToString() + ";" + b->getEsEntrada().ToString() + ";" + b->getEstaAbierto().ToString();
	}
	File::WriteAllLines(path, lineas);
}

