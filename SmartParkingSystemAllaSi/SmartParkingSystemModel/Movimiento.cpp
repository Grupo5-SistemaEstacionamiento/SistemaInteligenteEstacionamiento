#include "pch.h"
#include "Movimiento.h"

using namespace SmartParkingSystemModel;

Movimiento::Movimiento() {
	this->listaPagos = gcnew List<Pago^>();
	this->listaMembresias = gcnew List<Membresia^>();
	this->listaRegistroAccesos = gcnew List<RegistroAcceso^>();
	this->listaPenalizaciones = gcnew List<Penalizacion^>();
}
Movimiento::Movimiento(
	int idMovimiento,
	String^ descripcion,
	double monto,
	bool anulada,
	DateTime fechaHoraMovimento,
	String^ tipoMovimiento,
	List<Pago^>^ listaPagos,
	List<Membresia^>^ listaMembresias,
	List<RegistroAcceso^>^ listaRegistroAccesos,
	List<Penalizacion^>^ listaPenalizaciones
) {
	this->idMovimiento = idMovimiento;
	this->descripcion = descripcion;
	this->monto = monto;
	this->anulada = anulada;
	this->fechaHoraMovimento = fechaHoraMovimento;
	this->tipoMovimiento = tipoMovimiento;
	this->listaPagos = listaPagos;
	this->listaMembresias = listaMembresias;
	this->listaRegistroAccesos = listaRegistroAccesos;
	this->listaPenalizaciones = listaPenalizaciones;

}

int Movimiento::getIdMovimiento() {
	return this->idMovimiento;
}
String^ Movimiento::getDescripcion() {
	return this->descripcion;
}
double Movimiento::getMonto() {
	return this->monto;
}
bool Movimiento::getAnulada() {
	return this->anulada;
}
DateTime Movimiento::getFechaHoraMovimento() {
	return this->fechaHoraMovimento;
}
String^ Movimiento::getTipoMovimiento() {
	return this->tipoMovimiento;
}
List<Pago^>^ Movimiento::getListaPagos() {
	return this->listaPagos;
}
List<Membresia^>^ Movimiento::getListaMembresias() {
	return this->listaMembresias;
}
List<RegistroAcceso^>^ Movimiento::getListaRegistroAccesos() {
	return this->listaRegistroAccesos;
}
List<Penalizacion^>^ Movimiento::getListaPenalizaciones() {
	return this->listaPenalizaciones;
}


void Movimiento::setIdMovimiento(int idMovimiento) {
	this->idMovimiento = idMovimiento;
}
void Movimiento::setDescripcion(String^ descripcion) {
	this->descripcion = descripcion;
}
void Movimiento::setMonto(double monto) {
	this->monto = monto;
}
void Movimiento::setAnulada(bool anulada) {
	this->anulada = anulada;
}
void Movimiento::setFechaHoraMovimento(DateTime fechaHoraMovimento) {
	this->fechaHoraMovimento = fechaHoraMovimento;
}
void Movimiento::setTipoMovimiento(String^ tipoMovimiento) {
	this->tipoMovimiento = tipoMovimiento;
}
void Movimiento::setListaPagos(List<Pago^>^ listaPagos) {
	this->listaPagos = listaPagos; 
}
void Movimiento::setListaMembresias(List<Membresia^>^ listaMembresias) {
	this->listaMembresias = listaMembresias;
}
void Movimiento::setListaRegistroAccesos(List<RegistroAcceso^>^ listaRegistroAccesos) {
	this->listaRegistroAccesos = listaRegistroAccesos;
}
void Movimiento::setListaPenalizaciones(List<Penalizacion^>^ listaPenalizaciones) {
	this->listaPenalizaciones = listaPenalizaciones;
}