#include "pch.h"
#include "MembresiaController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

MembresiaController::MembresiaController()
{
	membresiaDAO = gcnew MembresiaDAO();
}

List<Membresia^>^ MembresiaController::listarMembresias()
{
	return membresiaDAO->listarMembresias();
}

Membresia^ MembresiaController::buscarMembresia(int idMembresia)
{
	if (idMembresia <= 0) return nullptr;
	return membresiaDAO->buscarMembresia(idMembresia);
}

bool MembresiaController::registrarMembresia(DateTime fechaInicio, DateTime fechaFin, double porcentajeDescuento, bool activo, double precio, int tipo)
{
	if (porcentajeDescuento < 0 || porcentajeDescuento > 100) return false;
	if (precio < 0) return false;
	int id = obtenerSiguienteId();
	Membresia^ m = gcnew Membresia(
		id,
		fechaInicio,
		fechaFin,
		porcentajeDescuento,
		activo,
		precio,
		(TipoMembresia)tipo,
		nullptr,
		nullptr
	);
	return membresiaDAO->registrarMembresia(m);
}

bool MembresiaController::modificarMembresia(int idMembresia, DateTime fechaInicio, DateTime fechaFin, double porcentajeDescuento, bool activo, double precio, int tipo)
{
	if (idMembresia <= 0) return false;
	if (buscarMembresia(idMembresia) == nullptr) return false;
	Membresia^ m = gcnew Membresia(
		idMembresia,
		fechaInicio,
		fechaFin,
		porcentajeDescuento,
		activo,
		precio,
		(TipoMembresia)tipo,
		nullptr,
		nullptr
	);
	return membresiaDAO->modificarMembresia(m);
}

bool MembresiaController::eliminarMembresia(int idMembresia)
{
	if (idMembresia <= 0) return false;
	if (buscarMembresia(idMembresia) == nullptr) return false;
	return membresiaDAO->eliminarMembresia(idMembresia);
}

int MembresiaController::obtenerSiguienteId()
{
	return membresiaDAO->obtenerSiguienteId();
}
