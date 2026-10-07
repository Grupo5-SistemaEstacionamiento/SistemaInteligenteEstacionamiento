#pragma once

namespace SmartParkingSystemController {
	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemModel;
	using namespace System;

	public ref class PagoController {
	private:
		List<Pago^>^ listaPagos;
	public:
		PagoController();
		List<Pago^>^ buscarTodosMemoria();
		Pago^ buscarxIdMemoria(int idPago);
		void registrarMemoria(Pago^ pago);
		void modificarMemoria(Pago^ pago);
		void eliminarMemoria(int idPago);

		// Archivo
		List<Pago^>^ buscarTodosArchivo();
		Pago^ buscarxIdArchivo(int idPago);
		void registrarArchivo(Pago^ pago);
		void modificarArchivo(Pago^ pago);
		void eliminarArchivo(int idPago);
	};

}
