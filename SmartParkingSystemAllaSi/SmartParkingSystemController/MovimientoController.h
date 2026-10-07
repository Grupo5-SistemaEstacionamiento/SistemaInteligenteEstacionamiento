#pragma once

namespace SmartParkingSystemController {
	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemModel;
	using namespace System;

	public ref class MovimientoController {
	private:
		List<Movimiento^>^ listaMovimientos;
	public:
		MovimientoController();
		List<Movimiento^>^ buscarTodosMemoria();
		Movimiento^ buscarxIdMemoria(int idMovimiento);
		void registrarMemoria(Movimiento^ mov);
		void modificarMemoria(Movimiento^ mov);
		void eliminarMemoria(int idMovimiento);

		// Archivo
		List<Movimiento^>^ buscarTodosArchivo();
		Movimiento^ buscarxIdArchivo(int idMovimiento);
		void registrarArchivo(Movimiento^ mov);
		void modificarArchivo(Movimiento^ mov);
		void eliminarArchivo(int idMovimiento);
	};

}
