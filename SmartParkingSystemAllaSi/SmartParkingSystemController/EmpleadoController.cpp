#include "pch.h"
#include "EmpleadoController.h"
using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

EmpleadoController::EmpleadoController() {
	this->listaEmpleados = gcnew List<Empleado^>();
}

List<Empleado^>^ EmpleadoController::buscarTodosMemoria() {
	return this->listaEmpleados;
}

Empleado^ EmpleadoController::buscarxCodigoMemoria(String^ codigo) {
	for (int i = 0; i < this->listaEmpleados->Count; i++) {
		if (this->listaEmpleados[i]->getCodigoEmpleado() == codigo) {
			return this->listaEmpleados[i];
		}
	}
	return nullptr;
}

void EmpleadoController::registrarMemoria(Empleado^ empleado) {
	this->listaEmpleados->Add(empleado);
}

void EmpleadoController::modificarMemoria(Empleado^ empleado) {
	for (int i = 0; i < this->listaEmpleados->Count; i++) {
		if (this->listaEmpleados[i]->getCodigoEmpleado() == empleado->getCodigoEmpleado()) {
			this->listaEmpleados[i]->setDocumento(empleado->getDocumento());
			this->listaEmpleados[i]->setNombres(empleado->getNombres());
			this->listaEmpleados[i]->setNpellidos(empleado->getApellidos());
			this->listaEmpleados[i]->setEstado(empleado->getEstado());
			break;
		}
	}
}

void EmpleadoController::eliminarMemoria(String^ codigo) {
	for (int i = 0; i < this->listaEmpleados->Count; i++) {
		if (this->listaEmpleados[i]->getCodigoEmpleado() == codigo) {
			this->listaEmpleados->RemoveAt(i);
			break;
		}
	}
}


List<Empleado^>^ EmpleadoController::buscarTodosArchivo() {
	EmpleadoDAO^ empleadoDAO = gcnew EmpleadoDAO();
	return empleadoDAO->buscarTodosArchivo();
}

Empleado^ EmpleadoController::buscarxCodigoArchivo(String^ codigo) {
	EmpleadoDAO^ empleadoDAO = gcnew EmpleadoDAO();
	return empleadoDAO->buscarxCodigoArchivo(codigo);
}

void EmpleadoController::registrarArchivo(Empleado^ empleado) {
	EmpleadoDAO^ empleadoDAO = gcnew EmpleadoDAO();
	empleadoDAO->registrarEmpleadoArchivo(empleado);
}

void EmpleadoController::modificarArchivo(Empleado^ empleado) {
	EmpleadoDAO^ empleadoDAO = gcnew EmpleadoDAO();
	empleadoDAO->modificarEmpleadoArchivo(empleado);
}

void EmpleadoController::eliminarArchivo(String^ codigo) {
	EmpleadoDAO^ empleadoDAO = gcnew EmpleadoDAO();
	empleadoDAO->eliminarEmpleadoArchivos(codigo);
}