#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

	public ref class TarjetaRFIDController {

	private:
		TarjetaRFIDDAO^ tarjetaDAO;

	public:
		TarjetaRFIDController();

		List<TarjetaRFID^>^ listarTarjetas();
		TarjetaRFID^ buscarTarjeta(int idTarjeta);
		bool registrarTarjeta(String^ codigoUID, DateTime fechaEmision, DateTime fechaVencimiento, bool activa);
		bool modificarTarjeta(int idTarjeta, String^ codigoUID, DateTime fechaEmision, DateTime fechaVencimiento, bool activa);
		bool eliminarTarjeta(int idTarjeta);
		int obtenerSiguienteId();
	};
}
