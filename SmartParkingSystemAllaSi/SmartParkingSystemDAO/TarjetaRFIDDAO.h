#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO {

	public ref class TarjetaRFIDDAO {

	private:
		String^ rutaArchivo;
		void verificarDirectorio();
		bool guardarTarjetas(List<TarjetaRFID^>^ tarjetas);

	public:
		TarjetaRFIDDAO();

		List<TarjetaRFID^>^ listarTarjetas();
		TarjetaRFID^ buscarTarjeta(int idTarjeta);
		bool registrarTarjeta(TarjetaRFID^ tarjeta);
		bool modificarTarjeta(TarjetaRFID^ tarjeta);
		bool eliminarTarjeta(int idTarjeta);
		int obtenerSiguienteId();
	};
}
