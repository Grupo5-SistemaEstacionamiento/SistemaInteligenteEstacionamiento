#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	public ref class ClienteDAO {

	public:
		ClienteDAO();
		List<Cliente^>^ buscarTodosArchivo();
		Cliente^ buscarxIndiceArchivo(int indice);
		void registrarClienteArchivo(Cliente^ cliente);
		void modificarClienteArchivo(int indice, Cliente^ cliente);
		void eliminarClienteArchivos(int indice);
		void escribirArchivo(List<Cliente^>^ listaClientes);
	};

}
