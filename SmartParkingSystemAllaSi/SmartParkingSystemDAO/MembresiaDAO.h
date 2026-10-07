#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO {

	public ref class MembresiaDAO {

	private:
		String^ rutaArchivo;
		void verificarDirectorio();
		bool guardarMembresias(List<Membresia^>^ membresias);

	public:
		MembresiaDAO();

		List<Membresia^>^ listarMembresias();
		Membresia^ buscarMembresia(int idMembresia);
		bool registrarMembresia(Membresia^ membresia);
		bool modificarMembresia(Membresia^ membresia);
		bool eliminarMembresia(int idMembresia);
		int obtenerSiguienteId();
	};
}
