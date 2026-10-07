#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	public ref class PagoDAO {
	public:
		PagoDAO();
		List<Pago^>^ buscarTodosArchivo();
		Pago^ buscarxIdArchivo(int idPago);
		void registrarPagoArchivo(Pago^ pago);
		void modificarPagoArchivo(Pago^ pago);
		void eliminarPagoArchivo(int idPago);
		void escribirArchivo(List<Pago^>^ listaPagos);
	};

}
