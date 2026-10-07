#include "pch.h"
#include "EmpleadoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;

EmpleadoDAO::EmpleadoDAO() {

}

List<Empleado^>^ EmpleadoDAO::buscarTodosArchivo() {
	List<Empleado^>^ listaEmpleados = gcnew List<Empleado^>();
	if (!File::Exists("Empleados.txt")) return listaEmpleados;

	array<String^>^ lineas = File::ReadAllLines("Empleados.txt");
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');

		int idPersona = datos->Length > 0 ? Convert::ToInt32(datos[0]) : 0;
		String^ nombres = datos->Length > 1 ? datos[1] : String::Empty;
		String^ apellidos = datos->Length > 2 ? datos[2] : String::Empty;
		String^ documento = datos->Length > 3 ? datos[3] : String::Empty;
		String^ telefono = datos->Length > 4 ? datos[4] : String::Empty;
		String^ correo = datos->Length > 5 ? datos[5] : String::Empty;
		String^ fechaRegistroStr = datos->Length > 6 ? datos[6] : String::Empty;
		String^ estadoStr = datos->Length > 7 ? datos[7] : "0";
		String^ codigoEmpleado = datos->Length > 8 ? datos[8] : String::Empty;
		String^ cargo = datos->Length > 9 ? datos[9] : String::Empty;
		String^ turno = datos->Length > 10 ? datos[10] : String::Empty;
		String^ fechaContratacionStr = datos->Length > 11 ? datos[11] : String::Empty;
		String^ enTurnoStr = datos->Length > 12 ? datos[12] : "0";

		DateTime fechaRegistro = DateTime::MinValue;
		DateTime fechaContratacion = DateTime::MinValue;
		try { fechaRegistro = DateTime::Parse(fechaRegistroStr); } catch (...) { fechaRegistro = DateTime::MinValue; }
		try { fechaContratacion = DateTime::Parse(fechaContratacionStr); } catch (...) { fechaContratacion = DateTime::MinValue; }

		bool estado = (estadoStr->Equals("1") || estadoStr->ToLower()->Equals("true"));
		bool enTurno = (enTurnoStr->Equals("1") || enTurnoStr->ToLower()->Equals("true"));

		Empleado^ empleado = gcnew Empleado(
			idPersona,
			nombres,
			apellidos,
			documento,
			telefono,
			correo,
			fechaRegistro,
			estado,
			codigoEmpleado,
			cargo,
			turno,
			fechaContratacion,
			enTurno,
			nullptr,
			nullptr
		);

		listaEmpleados->Add(empleado);
	}

	return listaEmpleados;
}

Empleado^ EmpleadoDAO::buscarxCodigoArchivo(String^ codigo) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo();
	for (int i = 0; i < listaEmpleadosTodos->Count; i++) {
		if (listaEmpleadosTodos[i]->getCodigoEmpleado() == codigo) {
			return listaEmpleadosTodos[i];
		}
	}
	return nullptr;
}

void EmpleadoDAO::registrarEmpleadoArchivo(Empleado^ empleado) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); /*Recupero a todos los empleados del archivo*/
	listaEmpleadosTodos->Add(empleado); /*Agrego al nuevo a lista*/
	escribirArchivo(listaEmpleadosTodos);
}

void EmpleadoDAO::modificarEmpleadoArchivo(Empleado^ empleado) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); /*Recupero a todos los empleados del archivo*/
	for (int i = 0; i < listaEmpleadosTodos->Count; i++) {
		if (listaEmpleadosTodos[i]->getCodigoEmpleado() == empleado->getCodigoEmpleado()) {
			// Reemplazar todo el objeto empleado encontrado por el nuevo
			listaEmpleadosTodos[i] = empleado;
			break;
		}
	}
	escribirArchivo(listaEmpleadosTodos);
}

void EmpleadoDAO::eliminarEmpleadoArchivos(String^ codigo) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); /*Recupero a todos los empleados del archivo*/
	for (int i = 0; i < listaEmpleadosTodos->Count; i++) {
		if (listaEmpleadosTodos[i]->getCodigoEmpleado() == codigo) {
			listaEmpleadosTodos->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(listaEmpleadosTodos);
}

void EmpleadoDAO::escribirArchivo(List<Empleado^>^ listaEmpleados) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaEmpleados->Count);
	for (int i = 0; i < listaEmpleados->Count; i++) {
		Empleado^ empleado = listaEmpleados[i];
		String^ fechaRegistroStr = empleado->getFechaRegistro().ToString("o");
		String^ fechaContratacionStr = empleado->getFechaContratacion().ToString("o");
		String^ estadoStr = empleado->getEstado() ? "1" : "0";
		String^ enTurnoStr = empleado->getEnTurno() ? "1" : "0";

		lineasArchivo[i] = Convert::ToString( /*idPersona*/ 0) + ";" +
			empleado->getNombres() + ";" +
			empleado->getApellidos() + ";" +
			empleado->getDocumento() + ";" +
			/*telefono*/ String::Empty + ";" +
			/*correo*/ String::Empty + ";" +
			fechaRegistroStr + ";" +
			estadoStr + ";" +
			empleado->getCodigoEmpleado() + ";" +
			empleado->getCargo() + ";" +
			empleado->getTurno() + ";" +
			fechaContratacionStr + ";" +
			enTurnoStr;
	}
	File::WriteAllLines("Empleados.txt", lineasArchivo);
}