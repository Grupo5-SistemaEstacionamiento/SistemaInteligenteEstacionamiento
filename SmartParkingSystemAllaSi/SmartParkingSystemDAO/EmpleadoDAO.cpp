#include "pch.h"
#include "EmpleadoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO; //Tiene las clases de manejo de archivos

EmpleadoDAO::EmpleadoDAO() {

}

List<Empleado^>^ EmpleadoDAO::buscarTodosArchivo() {
	List<Empleado^>^ listaEmpleados = gcnew List<Empleado^>();
	if (!File::Exists("Empleados.txt")) {  //Si no existe el archivo entrega la lista vacia
		return listaEmpleados;
	}

	array<String^>^ lineas = File::ReadAllLines("Empleados.txt"); //Genera un array que contiene las lineas del archivo

	for each (String ^ linea in lineas) { //Abstraemos los datos de cada linea tomando en cuenta los separadores

		if (String::IsNullOrWhiteSpace(linea)) {
			continue; //Si hay un espcio en blanco , se salta esa linea
		}
		String^ separador = ";"; //Separador de datos

		array<String^>^ datos = linea->Split(separador->ToCharArray()); //Conseguimos los datos a partir de los separadores

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

		// CORRECCIÓN: Instanciamos vacío y seteamos manualmente para evitar el constructor roto
		Empleado^ empleado = gcnew Empleado();

		// Atributos de Persona
		empleado->setNombres(nombres);
		empleado->setApellidos(apellidos);
		empleado->setDocumento(documento);
		empleado->setEstado(estado);

		// Atributos de Empleado
		empleado->setCodigoEmpleado(codigoEmpleado);
		empleado->setCargo(cargo);
		empleado->setTurno(turno);
		empleado->setFechaContratacion(fechaContratacion);
		empleado->setEnTurno(enTurno);

		listaEmpleados->Add(empleado); //Agregamos el empleado a la lista de empleados cada iteracion del for each
	}

	return listaEmpleados; //Retorna la lista de empleados que se obtuvo del archivo
}

Empleado^ EmpleadoDAO::buscarxCodigoArchivo(String^ codigo) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); //Obtener todos los empleados del archivo (llamado de función)

	for (int i = 0; i < listaEmpleadosTodos->Count; i++) { //Revisamos toda la lista de completa
		
		if (listaEmpleadosTodos[i]->getCodigoEmpleado() == codigo) { //De lo que dentro de la lista contenga el codigo que se ha buscado 
			return listaEmpleadosTodos[i]; //si encuentra el codigo, retorna el empleado encontrado
		}
	}
	return nullptr; //Si no encuentra al empleado, retorna un puntero nulo
}

void EmpleadoDAO::registrarEmpleadoArchivo(Empleado^ empleado) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); // Recupero a todos los empleados del archivo para colocar al nuevo al final de la lista
	listaEmpleadosTodos->Add(empleado); //Agrego al nuevo empleado a la lista
	escribirArchivo(listaEmpleadosTodos); //Escribimos la nueva lista de empleados en el archivo, incluyendo al nuevo empleado
}

void EmpleadoDAO::modificarEmpleadoArchivo(Empleado^ empleado) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); //Recupero a todos los empleados del archivo

	for (int i = 0; i < listaEmpleadosTodos->Count; i++) {
		if (listaEmpleadosTodos[i]->getCodigoEmpleado() == empleado->getCodigoEmpleado()) { //Si los codigos coiciden se modifica el empleado encontrado por el nuevo
			// Reemplazar todo el objeto empleado encontrado por el nuevo
			listaEmpleadosTodos[i] = empleado;
			break;
		}
	}
	escribirArchivo(listaEmpleadosTodos); //reescribimos la lista actualizada
}

void EmpleadoDAO::eliminarEmpleadoArchivos(String^ codigo) {
	List<Empleado^>^ listaEmpleadosTodos = buscarTodosArchivo(); //Recupero a todos los empleados del archivo

	for (int i = 0; i < listaEmpleadosTodos->Count; i++) {
		if (listaEmpleadosTodos[i]->getCodigoEmpleado() == codigo) { //Si el codigo del empleado coincide con el codigo que se quiere eliminar se elimina de la lista
			listaEmpleadosTodos->RemoveAt(i); //Eliminamos de la lista
			break;
		}
	}
	escribirArchivo(listaEmpleadosTodos); //reescribimos la lista actualizada
}

void EmpleadoDAO::escribirArchivo(List<Empleado^>^ listaEmpleados) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaEmpleados->Count); ///Contamos la cantidad de lineas en el archivo .txt

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
			/*telefono*/ String::Empty + ";" + //Colocamos String::Empty para los campos que no se usan en la clase Empleado
			/*correo*/ String::Empty + ";" +
			fechaRegistroStr + ";" +
			estadoStr + ";" +
			empleado->getCodigoEmpleado() + ";" +
			empleado->getCargo() + ";" +
			empleado->getTurno() + ";" +
			fechaContratacionStr + ";" +
			enTurnoStr;
	}
	File::WriteAllLines("Empleados.txt", lineasArchivo); //Escribimos todas las lineas en el archivo, reemplazando el contenido anterior (reescribiendo)
}