#include "pch.h"
#include "TurnoCajaController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

TurnoCajaController::TurnoCajaController() {
	this->listaTurnos = gcnew List<TurnoCaja^>();
}

List<TurnoCaja^>^ TurnoCajaController::buscarTodosMemoria() {
	return this->listaTurnos;
}

TurnoCaja^ TurnoCajaController::buscarxIdMemoria(int idTurno) {
	for (int i = 0; i < this->listaTurnos->Count; i++) {
		if (this->listaTurnos[i]->getIdTurno() == idTurno) return this->listaTurnos[i];
	}
	return nullptr;
}

void TurnoCajaController::registrarMemoria(TurnoCaja^ turno) {
	this->listaTurnos->Add(turno);
}

void TurnoCajaController::modificarMemoria(TurnoCaja^ turno) {
	for (int i = 0; i < this->listaTurnos->Count; i++) {
		if (this->listaTurnos[i]->getIdTurno() == turno->getIdTurno()) {
			this->listaTurnos[i] = turno;
			break;
		}
	}
}

void TurnoCajaController::eliminarMemoria(int idTurno) {
	for (int i = 0; i < this->listaTurnos->Count; i++) {
		if (this->listaTurnos[i]->getIdTurno() == idTurno) {
			this->listaTurnos->RemoveAt(i);
			break;
		}
	}
}

List<TurnoCaja^>^ TurnoCajaController::buscarTodosArchivo() {
	TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
	return turnoDao->buscarTodosArchivo();
}

TurnoCaja^ TurnoCajaController::buscarxIdArchivo(int idTurno) {
	TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
	return turnoDao->buscarxIdArchivo(idTurno);
}

void TurnoCajaController::registrarArchivo(TurnoCaja^ turno) {
	TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
	turnoDao->registrarTurnoArchivo(turno);
}

void TurnoCajaController::modificarArchivo(TurnoCaja^ turno) {
	TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
	turnoDao->modificarTurnoArchivo(turno);
}

void TurnoCajaController::eliminarArchivo(int idTurno) {
	TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
	turnoDao->eliminarTurnoArchivos(idTurno);
}
