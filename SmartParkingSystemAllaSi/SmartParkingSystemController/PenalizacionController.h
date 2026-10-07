#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

	public ref class PenalizacionController {

	private:
		PenalizacionDAO^ penalizacionDAO;

	public:
		PenalizacionController();

		List<Penalizacion^>^ listarPenalizaciones();
		Penalizacion^ buscarPenalizacion(int idPenalizacion);
		bool registrarPenalizacion(DateTime fechaHora, int tipo, String^ motivo, double monto, bool pagado);
		bool modificarPenalizacion(int idPenalizacion, int tipo, DateTime fechaHora, bool pagado, DateTime fechaPago, String^ motivo, double monto);
		bool eliminarPenalizacion(int idPenalizacion);
		int obtenerSiguienteId();
	};
}
