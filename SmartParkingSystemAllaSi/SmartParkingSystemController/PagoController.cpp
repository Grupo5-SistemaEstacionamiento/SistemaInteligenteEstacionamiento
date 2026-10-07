#include "pch.h"
#include "PagoController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

PagoController::PagoController() {
	this->listaPagos = gcnew List<Pago^>();
}

List<Pago^>^ PagoController::buscarTodosMemoria() {
	return this->listaPagos;
}

Pago^ PagoController::buscarxIdMemoria(int idPago) {
	for each (Pago^ p in this->listaPagos) if (p->getIdPago() == idPago) return p;
	return nullptr;
}

void PagoController::registrarMemoria(Pago^ pago) {
	this->listaPagos->Add(pago);
}

void PagoController::modificarMemoria(Pago^ pago) {
	for (int i = 0; i < this->listaPagos->Count; i++) {
		if (this->listaPagos[i]->getIdPago() == pago->getIdPago()) { this->listaPagos[i] = pago; break; }
	}
}

void PagoController::eliminarMemoria(int idPago) {
	for (int i = 0; i < this->listaPagos->Count; i++) {
		if (this->listaPagos[i]->getIdPago() == idPago) { this->listaPagos->RemoveAt(i); break; }
	}
}

List<Pago^>^ PagoController::buscarTodosArchivo() {
	PagoDAO^ pagoDao = gcnew PagoDAO();
	return pagoDao->buscarTodosArchivo();
}

Pago^ PagoController::buscarxIdArchivo(int idPago) {
	PagoDAO^ pagoDao = gcnew PagoDAO();
	return pagoDao->buscarxIdArchivo(idPago);
}

void PagoController::registrarArchivo(Pago^ pago) {
	PagoDAO^ pagoDao = gcnew PagoDAO();
	pagoDao->registrarPagoArchivo(pago);
}

void PagoController::modificarArchivo(Pago^ pago) {
	PagoDAO^ pagoDao = gcnew PagoDAO();
	pagoDao->modificarPagoArchivo(pago);
}

void PagoController::eliminarArchivo(int idPago) {
	PagoDAO^ pagoDao = gcnew PagoDAO();
	pagoDao->eliminarPagoArchivo(idPago);
}
