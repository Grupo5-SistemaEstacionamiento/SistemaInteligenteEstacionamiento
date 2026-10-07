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
		Cliente^ buscarxIndiceMemoria(int indice);
		void registrarMemoria(Cliente^ cliente);
		void modificarMemoria(int indice, Cliente^ cliente);
		void eliminarMemoria(int indice);

		/*Archivos*/
		List<Cliente^>^ buscarTodosArchivo();
		Cliente^ buscarxIndiceArchivo(int indice);
		void registrarArchivo(Cliente^ cliente);
		void modificarArchivo(int indice, Cliente^ cliente);
		void eliminarArchivo(int indice);
	};

}
