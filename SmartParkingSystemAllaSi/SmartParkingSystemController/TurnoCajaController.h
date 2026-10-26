#pragma once

namespace SmartParkingSystemController {

	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemModel;
	using namespace System;

	public ref class TurnoCajaController {
	private:
		List<TurnoCaja^>^ listaTurnos;

	public:
		TurnoCajaController();
		/*Archivos*/
		List<TurnoCaja^>^ buscarTodosArchivo();
		TurnoCaja^ buscarxIdArchivo(int idTurno);
		void registrarArchivo(TurnoCaja^ turno);
		void modificarArchivo(TurnoCaja^ turno);
		void eliminarArchivo(int idTurno);
	};

}
