#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO {

	public ref class PenalizacionDAO {

	private:
		String^ rutaArchivo;
		void verificarDirectorio();
		bool guardarPenalizaciones(List<Penalizacion^>^ penalizaciones);

	public:
		PenalizacionDAO();

		List<Penalizacion^>^ listarPenalizaciones();
		Penalizacion^ buscarPenalizacion(int idPenalizacion);
		bool registrarPenalizacion(Penalizacion^ penalizacion);
		bool modificarPenalizacion(Penalizacion^ penalizacion);
		bool eliminarPenalizacion(int idPenalizacion);
		int obtenerSiguienteId();
	};
}
