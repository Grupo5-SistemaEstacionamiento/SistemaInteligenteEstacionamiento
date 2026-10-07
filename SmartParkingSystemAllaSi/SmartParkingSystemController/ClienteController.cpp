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

Cliente^ ClienteController::buscarxIndiceMemoria(int indice) {
	if (indice >= 0 && indice < this->listaClientes->Count) return this->listaClientes[indice];
	return nullptr;
}

void ClienteController::registrarMemoria(Cliente^ cliente) {
	this->listaClientes->Add(cliente);
}

void ClienteController::modificarMemoria(int indice, Cliente^ cliente) {
	if (indice >= 0 && indice < this->listaClientes->Count) {
		this->listaClientes[indice] = cliente;
	}
}

void ClienteController::eliminarMemoria(int indice) {
	if (indice >= 0 && indice < this->listaClientes->Count) {
		this->listaClientes->RemoveAt(indice);
	}
}

List<Cliente^>^ ClienteController::buscarTodosArchivo() {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	return clientDao->buscarTodosArchivo();
}

Cliente^ ClienteController::buscarxIndiceArchivo(int indice) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	return clientDao->buscarxIndiceArchivo(indice);
}

void ClienteController::registrarArchivo(Cliente^ cliente) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	clientDao->registrarClienteArchivo(cliente);
}

void ClienteController::modificarArchivo(int indice, Cliente^ cliente) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	clientDao->modificarClienteArchivo(indice, cliente);
}

void ClienteController::eliminarArchivo(int indice) {
	ClienteDAO^ clientDao = gcnew ClienteDAO();
	clientDao->eliminarClienteArchivos(indice);
}
