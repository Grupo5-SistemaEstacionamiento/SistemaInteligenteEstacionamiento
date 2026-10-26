#include "pch.h"
#include "TurnoCajaController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

TurnoCajaController::TurnoCajaController() {
	this->listaTurnos = gcnew List<TurnoCaja^>();
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
