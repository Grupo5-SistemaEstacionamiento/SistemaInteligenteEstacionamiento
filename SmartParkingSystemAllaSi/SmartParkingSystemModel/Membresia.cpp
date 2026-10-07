#include "pch.h"
#include "Membresia.h"

using namespace CocheraModel;

Membresia::Membresia() {
	this->listaMovimientos = gcnew List<Movimiento^>();
}
Membresia::Membresia(
	int idMembresia,
	DateTime fechaInicio,
	DateTime fechaFin,
	double porcentajeDescuento,
	bool activo,
	double precio,
	TipoMembresia tipo,

	List<Movimiento^>^ listaMovimientos,
	Cliente^ cliente
) {
	this->idMembresia = idMembresia;
	this->fechaInicio = fechaInicio;
	this->fechaFin = fechaFin;
	this->porcentajeDescuento = porcentajeDescuento;
	this->activo = activo;
	this->precio = precio;
	this->listaMovimientos = listaMovimientos;
	this->cliente = cliente;
}

int Membresia::getIdMembresia() {
	return this->idMembresia;
}
DateTime Membresia::getFechaInicio() {
	return this->fechaInicio;
}
DateTime Membresia::getFechaFin() {
	return this->fechaFin;
}
double Membresia::getPorcentajeDescuento() {
	return this->porcentajeDescuento;
}
bool Membresia::getActivo() {
	return this->activo;
}
double Membresia::getPrecio() {
	return this->precio;
}
TipoMembresia Membresia::getTipo() {
	return this->tipo;
}
List<Movimiento^>^ Membresia::getListaMovimientos() {
	return this->listaMovimientos;
}
Cliente^ Membresia::getCliente() {
	return this->cliente;
}


void Membresia::setIdMembresia(int idMembresia) {
	this->idMembresia = idMembresia;
}
void Membresia::setFechaInicio(DateTime fechaInicio) {
	this->fechaInicio = fechaInicio;
}
void Membresia::setFechaFin(DateTime fechaFin) {
	this->fechaFin = fechaFin;
}
void Membresia::setPorcentajeDescuento(double porcentajeDescuento) {
	this->porcentajeDescuento = porcentajeDescuento;
}
void Membresia::setActivo(bool activo) {
	this->activo = activo;
}
void Membresia::setPrecio(double precio) {
	this->precio = precio;
}
void Membresia::setTipo(TipoMembresia tipo) {
	this->tipo = tipo;
}
void Membresia::setListaMovimientos(List<Movimiento^>^ listaMovimientos) {
	this->listaMovimientos = listaMovimientos;
}
void Membresia::setCliente(Cliente^ cliente) {
	this->cliente = cliente;
}
