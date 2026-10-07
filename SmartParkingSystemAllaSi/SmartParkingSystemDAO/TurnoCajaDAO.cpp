#include "pch.h"
#include "TurnoCajaDAO.h"
#include "EmpleadoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;

TurnoCajaDAO::TurnoCajaDAO() {

}

List<TurnoCaja^>^ TurnoCajaDAO::buscarTodosArchivo() {
	List<TurnoCaja^>^ lista = gcnew List<TurnoCaja^>();
	if (!File::Exists("TurnosCaja.txt")) return lista;

	array<String^>^ lineas = File::ReadAllLines("TurnosCaja.txt");
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');

		int id = datos->Length > 0 ? Convert::ToInt32(datos[0]) : 0;
		String^ fechaIngresoStr = datos->Length > 1 ? datos[1] : String::Empty;
		String^ fechaSalidaStr = datos->Length > 2 ? datos[2] : String::Empty;
		String^ saldoIniStr = datos->Length > 3 ? datos[3] : "0";
		String^ saldoFinStr = datos->Length > 4 ? datos[4] : "0";
		String^ observacion = datos->Length > 5 ? datos[5] : String::Empty;
		String^ estado = datos->Length > 6 ? datos[6] : String::Empty;
		String^ empleadoCodigo = datos->Length > 7 ? datos[7] : String::Empty;

		DateTime fechaIngreso = DateTime::MinValue;
		DateTime fechaSalida = DateTime::MinValue;
		try { fechaIngreso = DateTime::Parse(fechaIngresoStr); } catch (...) { fechaIngreso = DateTime::MinValue; }
		try { fechaSalida = DateTime::Parse(fechaSalidaStr); } catch (...) { fechaSalida = DateTime::MinValue; }

		double saldoIni = 0.0; double saldoFin = 0.0;
		try { saldoIni = Convert::ToDouble(saldoIniStr); } catch (...) { saldoIni = 0.0; }
		try { saldoFin = Convert::ToDouble(saldoFinStr); } catch (...) { saldoFin = 0.0; }

		// Intentar recuperar empleado por codigo usando EmpleadoDAO si está disponible
		Empleado^ empleado = nullptr;
		try {
			EmpleadoDAO^ empDao = gcnew EmpleadoDAO();
			empleado = empDao->buscarxCodigoArchivo(empleadoCodigo);
		}
		catch (...) { empleado = nullptr; }

		TurnoCaja^ t = gcnew TurnoCaja();
		t->setIdTurno(id);
		t->setFechaHoraIngreso(fechaIngreso);
		t->setFechaHoraSalida(fechaSalida);
		t->setSaldoInicial(saldoIni);
		t->setSaldoFinal(saldoFin);
		t->setObservacion(observacion);
		t->setEstado(estado);
		t->setEmpleado(empleado);
		t->setListaMovimientos(gcnew List<Movimiento^>());

		lista->Add(t);
	}

	return lista;
}

TurnoCaja^ TurnoCajaDAO::buscarxIdArchivo(int idTurno) {
	List<TurnoCaja^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdTurno() == idTurno) return lista[i];
	}
	return nullptr;
}

void TurnoCajaDAO::registrarTurnoArchivo(TurnoCaja^ turno) {
	List<TurnoCaja^>^ lista = buscarTodosArchivo();
	lista->Add(turno);
	escribirArchivo(lista);
}

void TurnoCajaDAO::modificarTurnoArchivo(TurnoCaja^ turno) {
	List<TurnoCaja^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdTurno() == turno->getIdTurno()) {
			lista[i] = turno;
			break;
		}
	}
	escribirArchivo(lista);
}

void TurnoCajaDAO::eliminarTurnoArchivos(int idTurno) {
	List<TurnoCaja^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdTurno() == idTurno) {
			lista->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(lista);
}

void TurnoCajaDAO::escribirArchivo(List<TurnoCaja^>^ listaTurnos) {
	array<String^>^ lineas = gcnew array<String^>(listaTurnos->Count);
	for (int i = 0; i < listaTurnos->Count; i++) {
		TurnoCaja^ t = listaTurnos[i];
		String^ fechaIngresoStr = t->getFechaHoraIngreso().ToString("o");
		String^ fechaSalidaStr = t->getFechaHoraSalida().ToString("o");
		String^ saldoIniStr = Convert::ToString(t->getSaldoInicial());
		String^ saldoFinStr = Convert::ToString(t->getSaldoFinal());
		String^ observ = t->getObservacion();
		String^ estado = t->getEstado();
		String^ empCodigo = t->getEmpleado() != nullptr ? t->getEmpleado()->getCodigoEmpleado() : String::Empty;

		lineas[i] = Convert::ToString(t->getIdTurno()) + ";" + fechaIngresoStr + ";" + fechaSalidaStr + ";" + saldoIniStr + ";" + saldoFinStr + ";" + observ + ";" + estado + ";" + empCodigo;
	}
	File::WriteAllLines("TurnosCaja.txt", lineas);
}
