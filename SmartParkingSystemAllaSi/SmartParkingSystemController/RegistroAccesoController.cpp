#include "pch.h"
#include "RegistroAccesoController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

RegistroAccesoController::RegistroAccesoController()
{
	registroDAO = gcnew RegistroAccesoDAO();
}

List<RegistroAcceso^>^ RegistroAccesoController::listarRegistros()
{
	return registroDAO->listarRegistros();
}

RegistroAcceso^ RegistroAccesoController::buscarRegistro(int idRegistro)
{
	if (idRegistro <= 0) return nullptr;
	return registroDAO->buscarRegistro(idRegistro);
}

bool RegistroAccesoController::registrarRegistro(DateTime fechaIngreso, DateTime fechaSalida, bool accesoAutorizado, String^ observacion, bool seHaPagado, double montoTotal)
{
	if (montoTotal < 0) return false;
	int id = obtenerSiguienteId();
	RegistroAcceso^ r = gcnew RegistroAcceso(
		id,
		fechaIngreso,
		fechaSalida,
		accesoAutorizado,
		observacion,
		seHaPagado,
		montoTotal,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr
	);
	return registroDAO->registrarRegistro(r);
}

bool RegistroAccesoController::modificarRegistro(int idRegistro, DateTime fechaIngreso, DateTime fechaSalida, bool accesoAutorizado, String^ observacion, bool seHaPagado, double montoTotal)
{
	if (idRegistro <= 0) return false;
	if (buscarRegistro(idRegistro) == nullptr) return false;
	RegistroAcceso^ r = gcnew RegistroAcceso(
		idRegistro,
		fechaIngreso,
		fechaSalida,
		accesoAutorizado,
		observacion,
		seHaPagado,
		montoTotal,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr
	);
	return registroDAO->modificarRegistro(r);
}

bool RegistroAccesoController::eliminarRegistro(int idRegistro)
{
	if (idRegistro <= 0) return false;
	if (buscarRegistro(idRegistro) == nullptr) return false;
	return registroDAO->eliminarRegistro(idRegistro);
}

int RegistroAccesoController::obtenerSiguienteId()
{
	return registroDAO->obtenerSiguienteId();
}
