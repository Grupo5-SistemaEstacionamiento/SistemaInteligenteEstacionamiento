#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	public ref class TurnoCajaDAO {

	public:
		TurnoCajaDAO();
		List<TurnoCaja^>^ buscarTodosArchivo();
		TurnoCaja^ buscarxIdArchivo(int idTurno);
		void registrarTurnoArchivo(TurnoCaja^ turno);
		void modificarTurnoArchivo(TurnoCaja^ turno);
		void eliminarTurnoArchivos(int idTurno);
		void escribirArchivo(List<TurnoCaja^>^ listaTurnos);
	};

}
