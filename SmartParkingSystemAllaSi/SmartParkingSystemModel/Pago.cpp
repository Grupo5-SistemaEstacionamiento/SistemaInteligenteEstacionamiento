#include "pch.h"
#include "Pago.h"


using namespace SmartParkingSystemModel;


Pago::Pago(){

}
Pago::Pago(int idPago,
	String^ numeroComprovante,
	double montoTotal,
	MetodoPago metodoPago,
	DateTime fechaHora) {

	this->idPago = idPago;
	this->numeroComprovante = numeroComprovante;
	this->montoTotal = montoTotal;
	this->metodoPago = metodoPago;
	this->fechaHora = fechaHora;


}

/*geters*/
int  Pago::getIdPago() {
	return this->idPago;

}
String^ Pago::getNumeroComprovante() {
	return this->numeroComprovante;

}
double      Pago::getMontoTotal() {
	return this->montoTotal;

}
MetodoPago Pago::getMetodoPago() {
	return this->metodoPago;

}
DateTime    Pago::getFechaHora() {
	return this->fechaHora;

}

/*seters*/
void    Pago::setIdPago(int idPago) {
	this->idPago = idPago; 

}
void    Pago::setNumeroComprovante(String^ numeroComprovante) {
	this->numeroComprovante = numeroComprovante;

}
void    Pago::setMontoTotal(double montoTotal) {
	this->montoTotal = montoTotal;

}
void    Pago::setMetodoPago(MetodoPago metodoPago) {
	this->metodoPago = metodoPago;

}
void    Pago::setFechaHora(DateTime fechaHora) {
	this->fechaHora = fechaHora;

}