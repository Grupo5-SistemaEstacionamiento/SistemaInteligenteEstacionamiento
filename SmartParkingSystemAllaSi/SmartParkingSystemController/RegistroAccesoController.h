#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

	public ref class RegistroAccesoController {

	private:
		RegistroAccesoDAO^ registroDAO;

	public:
		RegistroAccesoController();

		List<RegistroAcceso^>^ listarRegistros();
		RegistroAcceso^ buscarRegistro(int idRegistro);
		bool registrarRegistro(DateTime fechaIngreso, DateTime fechaSalida, bool accesoAutorizado, String^ observacion, bool seHaPagado, double montoTotal);
		bool modificarRegistro(int idRegistro, DateTime fechaIngreso, DateTime fechaSalida, bool accesoAutorizado, String^ observacion, bool seHaPagado, double montoTotal);
		bool eliminarRegistro(int idRegistro);
		int obtenerSiguienteId();
	};
}
