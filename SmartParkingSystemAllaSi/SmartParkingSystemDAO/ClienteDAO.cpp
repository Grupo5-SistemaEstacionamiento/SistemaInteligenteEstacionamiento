#include "pch.h"
#include "ClienteDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;

ClienteDAO::ClienteDAO() {

}

List<Cliente^>^ ClienteDAO::buscarTodosArchivo() {
	List<Cliente^>^ lista = gcnew List<Cliente^>();
	if (!File::Exists("Clientes.txt")) return lista;

	array<String^>^ lineas = File::ReadAllLines("Clientes.txt");
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');

		String^ fechaStr = datos->Length > 0 ? datos[0] : String::Empty;
		String^ tipoStr = datos->Length > 1 ? datos[1] : "0";
		String^ observaciones = datos->Length > 2 ? datos[2] : String::Empty;
		String^ saldoStr = datos->Length > 3 ? datos[3] : "0";
		String^ requierePrefStr = datos->Length > 4 ? datos[4] : "0";
		String^ discapacidad = datos->Length > 5 ? datos[5] : String::Empty;

		DateTime fecha = DateTime::MinValue;
		try { fecha = DateTime::Parse(fechaStr); } catch (...) { fecha = DateTime::MinValue; }
		TipoCliente tipo = static_cast<TipoCliente>(Convert::ToInt32(tipoStr));
		double saldo = 0.0;
		try { saldo = Convert::ToDouble(saldoStr); } catch (...) { saldo = 0.0; }
		bool requiere = (requierePrefStr->Equals("1") || requierePrefStr->ToLower()->Equals("true"));

		Cliente^ c = gcnew Cliente(fecha, tipo, observaciones, saldo, requiere, discapacidad, nullptr, nullptr, nullptr, nullptr);
		lista->Add(c);
	}

	return lista;
}

Cliente^ ClienteDAO::buscarxIndiceArchivo(int indice) {
	List<Cliente^>^ lista = buscarTodosArchivo();
	if (indice >= 0 && indice < lista->Count) return lista[indice];
	return nullptr;
}

void ClienteDAO::registrarClienteArchivo(Cliente^ cliente) {
	List<Cliente^>^ lista = buscarTodosArchivo();
	lista->Add(cliente);
	escribirArchivo(lista);
}

void ClienteDAO::modificarClienteArchivo(int indice, Cliente^ cliente) {
	List<Cliente^>^ lista = buscarTodosArchivo();
	if (indice >= 0 && indice < lista->Count) {
		lista[indice] = cliente;
		escribirArchivo(lista);
	}
}

void ClienteDAO::eliminarClienteArchivos(int indice) {
	List<Cliente^>^ lista = buscarTodosArchivo();
	if (indice >= 0 && indice < lista->Count) {
		lista->RemoveAt(indice);
		escribirArchivo(lista);
	}
}

void ClienteDAO::escribirArchivo(List<Cliente^>^ listaClientes) {
	array<String^>^ lineas = gcnew array<String^>(listaClientes->Count);
	for (int i = 0; i < listaClientes->Count; i++) {
		Cliente^ c = listaClientes[i];
		String^ fechaStr = c->getFechaAfiliacion().ToString("o");
		String^ tipoStr = Convert::ToString((int)c->getTipo());
		String^ observ = c->getObservaciones();
		String^ saldoStr = Convert::ToString(c->getSaldo());
		String^ reqStr = c->getRequierePreferencial() ? "1" : "0";
		String^ disc = c->getDiscapacidad();
		lineas[i] = fechaStr + ";" + tipoStr + ";" + observ + ";" + saldoStr + ";" + reqStr + ";" + disc;
	}
	File::WriteAllLines("Clientes.txt", lineas);
}
