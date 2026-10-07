#include "pch.h"
#include "VehiculoController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

VehiculoController::VehiculoController() {
	this->listaVehiculos = gcnew List<Vehiculo^>();
}

List<Vehiculo^>^ VehiculoController::buscarTodosMemoria() {
	return this->listaVehiculos;
}

Vehiculo^ VehiculoController::buscarxIdMemoria(int idVehiculo) {
	for each (Vehiculo^ v in this->listaVehiculos) if (v->getIdVehiculo() == idVehiculo) return v;
	return nullptr;
}

void VehiculoController::registrarMemoria(Vehiculo^ veh) {
	this->listaVehiculos->Add(veh);
}

void VehiculoController::modificarMemoria(Vehiculo^ veh) {
	for (int i = 0; i < this->listaVehiculos->Count; i++) {
		if (this->listaVehiculos[i]->getIdVehiculo() == veh->getIdVehiculo()) { this->listaVehiculos[i] = veh; break; }
	}
}

void VehiculoController::eliminarMemoria(int idVehiculo) {
	for (int i = 0; i < this->listaVehiculos->Count; i++) {
		if (this->listaVehiculos[i]->getIdVehiculo() == idVehiculo) { this->listaVehiculos->RemoveAt(i); break; }
	}
}

List<Vehiculo^>^ VehiculoController::buscarTodosArchivo() {
	VehiculoDAO^ vehiculoDao = gcnew VehiculoDAO();
	return vehiculoDao->buscarTodosArchivo();
}

Vehiculo^ VehiculoController::buscarxIdArchivo(int idVehiculo) {
	VehiculoDAO^ vehiculoDao = gcnew VehiculoDAO();
	return vehiculoDao->buscarxIdArchivo(idVehiculo);
}

void VehiculoController::registrarArchivo(Vehiculo^ veh) {
	VehiculoDAO^ vehiculoDao = gcnew VehiculoDAO();
	vehiculoDao->registrarVehiculoArchivo(veh);
}

void VehiculoController::modificarArchivo(Vehiculo^ veh) {
	VehiculoDAO^ vehiculoDao = gcnew VehiculoDAO();
	vehiculoDao->modificarVehiculoArchivo(veh);
}

void VehiculoController::eliminarArchivo(int idVehiculo) {
	VehiculoDAO^ vehiculoDao = gcnew VehiculoDAO();
	vehiculoDao->eliminarVehiculoArchivo(idVehiculo);
}
