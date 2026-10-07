#include "pch.h"
#include "Penalizacion.h"
#include "Vehiculo.h"
#include "Movimiento.h"

using namespace CocheraModel;

Penalizacion::Penalizacion() {

}
Penalizacion::Penalizacion(
	int idPenalizacion,
	TipoPenalizacion tipo,
	DateTime fechaHora,
	bool pagado,
	DateTime fechaPago,
	String^ motivo,
	double monto,

	Vehiculo^ vehiculo,
	List<Movimiento^>^ listaMovimientos
) {
	this->idPenalizacion = idPenalizacion;
	this->tipo = tipo;
	this->fechaHora = fechaHora;
	this->pagado = pagado;
	this->fechaPago = fechaPago;
	this->motivo = motivo;
	this->monto = monto;

	this->vehiculo = vehiculo;
	this->listaMovimientos = listaMovimientos;
}

int Penalizacion::getIdPenalizacion() {
	return this->idPenalizacion;
}
TipoPenalizacion Penalizacion::getTipo() {
	return this->tipo;
}
DateTime Penalizacion::getFechaHora() {
	return this->fechaHora;
}
bool Penalizacion::getPagado() {
	return this->pagado;
}
DateTime Penalizacion::getFechaPago() {
	return this->fechaPago;
}
String^ Penalizacion::getMotivo() {
	return this->motivo;
}
double Penalizacion::getMonto() {
	return this->monto;
}
Vehiculo^ Penalizacion::getVehiculo() {
	return this->vehiculo;
}
List<Movimiento^>^ Penalizacion::getListaMovimientos() {
	return this->listaMovimientos;
}


void Penalizacion::setIdPenalizacion(int idPenalizacion) {
	this->idPenalizacion = idPenalizacion;
}
void Penalizacion::setTipo(TipoPenalizacion tipo) {
	this->tipo = tipo;
}
void Penalizacion::setFechaHora(DateTime fechaHora) {
	this->fechaHora = fechaHora;
}
void Penalizacion::setPagado(bool pagado) {
	this->pagado = pagado;
}
void Penalizacion::setFechaPago(DateTime fechaPago) {
	this->fechaPago = fechaPago;
}
void Penalizacion::setMotivo(String^ motivo) {
	this->motivo = motivo;
}
void Penalizacion::setMonto(double monto) {
	this->monto = monto;
}
void Penalizacion::setVehiculo(Vehiculo^ vehiculo) {
	this->vehiculo = vehiculo;
}
void Penalizacion::setListaMovimientos(List<Movimiento^>^ listaMovimientos) {
	this->listaMovimientos = listaMovimientos;
}