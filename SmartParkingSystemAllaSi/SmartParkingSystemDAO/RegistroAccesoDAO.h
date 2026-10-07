#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO {

	public ref class RegistroAccesoDAO {

	private:
		String^ rutaArchivo;
		void verificarDirectorio();
		bool guardarRegistros(List<RegistroAcceso^>^ registros);

	public:
		RegistroAccesoDAO();

		List<RegistroAcceso^>^ listarRegistros();
		RegistroAcceso^ buscarRegistro(int idRegistro);
		bool registrarRegistro(RegistroAcceso^ registro);
		bool modificarRegistro(RegistroAcceso^ registro);
		bool eliminarRegistro(int idRegistro);
		int obtenerSiguienteId();
	};
}
