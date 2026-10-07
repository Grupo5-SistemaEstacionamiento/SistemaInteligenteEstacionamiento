#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

	public ref class MembresiaController {

	private:
		MembresiaDAO^ membresiaDAO;

	public:
		MembresiaController();

		List<Membresia^>^ listarMembresias();
		Membresia^ buscarMembresia(int idMembresia);
		bool registrarMembresia(DateTime fechaInicio, DateTime fechaFin, double porcentajeDescuento, bool activo, double precio, int tipo);
		bool modificarMembresia(int idMembresia, DateTime fechaInicio, DateTime fechaFin, double porcentajeDescuento, bool activo, double precio, int tipo);
		bool eliminarMembresia(int idMembresia);
		int obtenerSiguienteId();
	};
}
