#include "pch.h"
#include "TarjetaRFIDController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

TarjetaRFIDController::TarjetaRFIDController()
{
	tarjetaDAO = gcnew TarjetaRFIDDAO();
}

List<TarjetaRFID^>^ TarjetaRFIDController::listarTarjetas()
{
	return tarjetaDAO->listarTarjetas();
}

TarjetaRFID^ TarjetaRFIDController::buscarTarjeta(int idTarjeta)
{
	if (idTarjeta <= 0) return nullptr;
	return tarjetaDAO->buscarTarjeta(idTarjeta);
}

bool TarjetaRFIDController::registrarTarjeta(String^ codigoUID, DateTime fechaEmision, DateTime fechaVencimiento, bool activa)
{
	if (String::IsNullOrWhiteSpace(codigoUID)) return false;
	int id = obtenerSiguienteId();
	TarjetaRFID^ t = gcnew TarjetaRFID(
		id,
		codigoUID,
		fechaEmision,
		fechaVencimiento,
		activa,
		nullptr,
		nullptr
	);
	return tarjetaDAO->registrarTarjeta(t);
}

bool TarjetaRFIDController::modificarTarjeta(int idTarjeta, String^ codigoUID, DateTime fechaEmision, DateTime fechaVencimiento, bool activa)
{
	if (idTarjeta <= 0) return false;
	if (buscarTarjeta(idTarjeta) == nullptr) return false;
	TarjetaRFID^ t = gcnew TarjetaRFID(
		idTarjeta,
		codigoUID,
		fechaEmision,
		fechaVencimiento,
		activa,
		nullptr,
		nullptr
	);
	return tarjetaDAO->modificarTarjeta(t);
}

bool TarjetaRFIDController::eliminarTarjeta(int idTarjeta)
{
	if (idTarjeta <= 0) return false;
	if (buscarTarjeta(idTarjeta) == nullptr) return false;
	return tarjetaDAO->eliminarTarjeta(idTarjeta);
}

int TarjetaRFIDController::obtenerSiguienteId()
{
	return tarjetaDAO->obtenerSiguienteId();
}
