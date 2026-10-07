#include "pch.h"
#include "MovimientoController.h"


using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

MovimientoController::MovimientoController() {
	this->listaMovimientos = gcnew List<Movimiento^>();
}

List<Movimiento^>^ MovimientoController::buscarTodosMemoria() {
	return this->listaMovimientos;
}

Movimiento^ MovimientoController::buscarxIdMemoria(int idMovimiento) {
	for each (Movimiento^ m in this->listaMovimientos) if (m->getIdMovimiento() == idMovimiento) return m;
	return nullptr;
}

void MovimientoController::registrarMemoria(Movimiento^ mov) {
	this->listaMovimientos->Add(mov);
}

void MovimientoController::modificarMemoria(Movimiento^ mov) {
	for (int i = 0; i < this->listaMovimientos->Count; i++) {
		if (this->listaMovimientos[i]->getIdMovimiento() == mov->getIdMovimiento()) { this->listaMovimientos[i] = mov; break; }
	}
}

void MovimientoController::eliminarMemoria(int idMovimiento) {
	for (int i = 0; i < this->listaMovimientos->Count; i++) {
		if (this->listaMovimientos[i]->getIdMovimiento() == idMovimiento) { this->listaMovimientos->RemoveAt(i); break; }
	}
}

List<Movimiento^>^ MovimientoController::buscarTodosArchivo() {
	MovimientoDAO^ movimientoDao = gcnew MovimientoDAO();
	return movimientoDao->buscarTodosArchivo();
}

Movimiento^ MovimientoController::buscarxIdArchivo(int idMovimiento) {
	MovimientoDAO^ movimientoDao = gcnew MovimientoDAO();
	return movimientoDao->buscarxIdArchivo(idMovimiento);
}

void MovimientoController::registrarArchivo(Movimiento^ mov) {
	MovimientoDAO^ movimientoDao = gcnew MovimientoDAO();
	movimientoDao->registrarMovimientoArchivo(mov);
}

void MovimientoController::modificarArchivo(Movimiento^ mov) {
	MovimientoDAO^ movimientoDao = gcnew MovimientoDAO();
	movimientoDao->modificarMovimientoArchivo(mov);
}

void MovimientoController::eliminarArchivo(int idMovimiento) {
	MovimientoDAO^ movimientoDao = gcnew MovimientoDAO();
	movimientoDao->eliminarMovimientoArchivo(idMovimiento);
}
