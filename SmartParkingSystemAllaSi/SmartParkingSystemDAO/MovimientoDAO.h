#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	public ref class MovimientoDAO {
	public:
		MovimientoDAO();
		List<Movimiento^>^ buscarTodosArchivo();
		Movimiento^ buscarxIdArchivo(int idMovimiento);
		void registrarMovimientoArchivo(Movimiento^ mov);
		void modificarMovimientoArchivo(Movimiento^ mov);
		void eliminarMovimientoArchivo(int idMovimiento);
		void escribirArchivo(List<Movimiento^>^ listaMov);
	};

}
