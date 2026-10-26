#pragma once

namespace SmartParkingSystemDAO {

	using namespace System;
	using namespace System::Collections::Generic;
	
	using namespace SmartParkingSystemModel;

	public ref class ClienteDAO {

	public:
		ClienteDAO();
		List<Cliente^>^ buscarTodosArchivo();
		Cliente^ buscarxIdArchivo(int idPersona);

		//Cliente^ buscarxIndiceArchivo(int indice);
		void registrarClienteArchivo(Cliente^ cliente);
		void modificarClienteArchivo(int idPersona, Cliente^ cliente);
		void eliminarClienteArchivos(int idPersona);
		void escribirArchivo(List<Cliente^>^ listaClientes);
	};

}
