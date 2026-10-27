#include "pch.h"

#include "ClienteController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

ClienteController::ClienteController() {
	this->listaClientes = gcnew List<Cliente^>();
}

List<Cliente^>^ ClienteController::buscarTodosMemoria() {
	return this->listaClientes;
}

Cliente^ ClienteController::buscarxIdMemoria(int idPersona) {
	for (int i = 0; i < this->listaClientes->Count; i++) {
		if (this->listaClientes[i]->getIdPersona() == idPersona) {
			return this->listaClientes[i];
		}
	}
	return nullptr;
}

void ClienteController::registrarMemoria(Cliente^ cliente) {
	this->listaClientes->Add(cliente);
}

void ClienteController::modificarMemoria(int idPersona, Cliente^ cliente) {
	for (int i = 0; i < this->listaClientes->Count; i++) {
		if (this->listaClientes[i]->getIdPersona() == idPersona) {
			this->listaClientes[i] = cliente;
			return; // Salimos tras actualizar
		}
	}
}

void ClienteController::eliminarMemoria(int idPersona) {
	for (int i = 0; i < this->listaClientes->Count; i++) {
		if (this->listaClientes[i]->getIdPersona() == idPersona) {
			this->listaClientes->RemoveAt(i);
			return; // Salimos tras eliminar
		}
	}
}

List<Cliente^>^ ClienteController::buscarTodosArchivo() {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	return clientDao->buscarTodosArchivo();
}

Cliente^ ClienteController::buscarxIdArchivo(int idPersona) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	return clientDao->buscarxIdArchivo(idPersona);
}

void ClienteController::registrarArchivo(Cliente^ cliente) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	clientDao->registrarClienteArchivo(cliente);
}

void ClienteController::modificarArchivo(int idPersona, Cliente^ cliente) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	clientDao->modificarClienteArchivo(idPersona, cliente);
}

void ClienteController::eliminarArchivo(int idPersona) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	clientDao->eliminarClienteArchivos(idPersona);
}

// Lista todos los clientes registrados.
// Reutiliza el método existente del controlador.
List<Cliente^>^ ClienteController::listarClientes()
{
	return this->buscarTodosArchivo();
}

// Busca un cliente mediante su identificador.
// Reutiliza el método existente del controlador.
Cliente^ ClienteController::buscarClientePorId(int idPersona)
{
	return this->buscarxIdArchivo(idPersona);
}

List<Cliente^>^ ClienteController::FiltrarPorTipo(String^ tipoBuscado) {
	List<Cliente^>^ listaCompleta = this->buscarTodosArchivo();
	List<Cliente^>^ listaFiltrada = gcnew List<Cliente^>();

	for each (Cliente ^ c in listaCompleta) {
		// Filtramos según el atributo TipoCliente
		if (tipoBuscado == "Miembro" && c->getTipo() == TipoCliente::Miembro) {
			listaFiltrada->Add(c);
		}
		else if (tipoBuscado == "Normal" && c->getTipo() == TipoCliente::Normal) {
			listaFiltrada->Add(c);
		}
	}
	return listaFiltrada;
}


// Busca clientes por nombre, apellido o documento.
// La búsqueda no distingue mayúsculas de minúsculas.
List<Cliente^>^ ClienteController::buscarClientes(String^ criterio) {
	List<Cliente^>^ clientes = buscarTodosArchivo();

	if (String::IsNullOrWhiteSpace(criterio))
		return clientes;

	List<Cliente^>^ resultados =
		gcnew List<Cliente^>();

	String^ texto = criterio->Trim();

	for each (Cliente ^ cliente in clientes)
	{
		if (cliente == nullptr)
			continue;

		String^ nombres = cliente->getNombres();
		String^ apellidos = cliente->getApellidos();
		String^ documento = cliente->getDocumento();

		bool coincide =
			(!String::IsNullOrEmpty(nombres) &&
				nombres->StartsWith(
					texto,
					StringComparison::OrdinalIgnoreCase)) ||
			(!String::IsNullOrEmpty(apellidos) &&
				apellidos->StartsWith(
					texto,
					StringComparison::OrdinalIgnoreCase)) ||
			(!String::IsNullOrEmpty(documento) &&
				documento->StartsWith(
					texto,
					StringComparison::OrdinalIgnoreCase));

		if (coincide)
			resultados->Add(cliente);
	}

	return resultados;
}
