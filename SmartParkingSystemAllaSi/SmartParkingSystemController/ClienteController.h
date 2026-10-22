#pragma once

namespace SmartParkingSystemController {

	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemModel;
	using namespace System;

	public ref class ClienteController {
	private:
		List<Cliente^>^ listaClientes;

	public:
		ClienteController();
		List<Cliente^>^ buscarTodosMemoria();

		// CORRECCIÓN: Se agregó la 'r' faltante (buscarx...)
		Cliente^ buscarxIdMemoria(int idPersona);
		void registrarMemoria(Cliente^ cliente);
		void modificarMemoria(int idPersona, Cliente^ cliente);
		void eliminarMemoria(int idPersona);

		/*Archivos*/
		List<Cliente^>^ buscarTodosArchivo();

		// CORRECCIÓN: Se agregó la 'r' faltante (buscarx...)
		Cliente^ buscarxIdArchivo(int idPersona);
		void registrarArchivo(Cliente^ cliente);
		void modificarArchivo(int idPersona, Cliente^ cliente);
		void eliminarArchivo(int idPersona);

		//Para la interfaz añadi esto (para el filtro de miembro/no miembro
		List<Cliente^>^ FiltrarPorTipo(String^ tipoBuscado);
	};

}