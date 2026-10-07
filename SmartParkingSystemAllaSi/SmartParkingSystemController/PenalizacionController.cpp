#include "pch.h"
#include "PenalizacionController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

PenalizacionController::PenalizacionController()
{
	penalizacionDAO = gcnew PenalizacionDAO();
}

List<Penalizacion^>^ PenalizacionController::listarPenalizaciones()
{
	return penalizacionDAO->listarPenalizaciones();
}

Penalizacion^ PenalizacionController::buscarPenalizacion(int idPenalizacion)
{
	if (idPenalizacion <= 0) return nullptr;
	return penalizacionDAO->buscarPenalizacion(idPenalizacion);
}

bool PenalizacionController::registrarPenalizacion(DateTime fechaHora, int tipo, String^ motivo, double monto, bool pagado)
{
	if (monto < 0) return false;
	int id = obtenerSiguienteId();
	Penalizacion^ p = gcnew Penalizacion(
		id,
		(TipoPenalizacion)tipo,
		fechaHora,
		pagado,
		DateTime::MinValue,
		motivo,
		monto,
		nullptr,
		nullptr
	);
	return penalizacionDAO->registrarPenalizacion(p);
}

bool PenalizacionController::modificarPenalizacion(int idPenalizacion, int tipo, DateTime fechaHora, bool pagado, DateTime fechaPago, String^ motivo, double monto)
{
	if (idPenalizacion <= 0) return false;
	if (buscarPenalizacion(idPenalizacion) == nullptr) return false;
	Penalizacion^ p = gcnew Penalizacion(
		idPenalizacion,
		(TipoPenalizacion)tipo,
		fechaHora,
		pagado,
		fechaPago,
		motivo,
		monto,
		nullptr,
		nullptr
	);
	return penalizacionDAO->modificarPenalizacion(p);
}

bool PenalizacionController::eliminarPenalizacion(int idPenalizacion)
{
	if (idPenalizacion <= 0) return false;
	if (buscarPenalizacion(idPenalizacion) == nullptr) return false;
	return penalizacionDAO->eliminarPenalizacion(idPenalizacion);
}

int PenalizacionController::obtenerSiguienteId()
{
	return penalizacionDAO->obtenerSiguienteId();
}
