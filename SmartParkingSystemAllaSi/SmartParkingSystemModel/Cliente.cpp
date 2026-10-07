#include "pch.h"
#include "Cliente.h"
#include "Membresia.h"
#include "Vehiculo.h"
#include "TarjetaRFID.h"


using namespace SmartParkingSystemModel;

Cliente::Cliente() {

}
Cliente::Cliente(
	DateTime fechaAfiliacion,
	TipoCliente tipo,
	String^ observaciones,
	double saldo,
	bool requierePreferencial,
	String^ discapacidad,
	EspacioEstacionamiento^ espacioEstacionamiento,
	List<Membresia^>^ listasMembresias,
	List<TarjetaRFID^>^ listaTarjetasRFID,
	List<Vehiculo^>^ listaVehiculos
) {
	this->fechaAfiliacion = fechaAfiliacion;
	this->tipo = tipo;
	this->observaciones = observaciones;
	this->saldo = saldo;
	this->requierePreferencial = requierePreferencial;
	this->discapacidad = discapacidad;

	this->espacioEstacionamiento = espacioEstacionamiento;
	this->listasMembresias = listasMembresias;
	this->listaTarjetasRFID = listaTarjetasRFID;
	this->listaVehiculos = listaVehiculos;
}


DateTime Cliente::getFechaAfiliacion() {
	return this->fechaAfiliacion;
}
TipoCliente Cliente::getTipo() {
	return this->tipo;
}
String^ Cliente::getObservaciones() {
	return this->observaciones;
}
double Cliente::getSaldo() {
	return this->saldo;
}
bool Cliente::getRequierePreferencial() {
	return this->requierePreferencial;
}
String^ Cliente::getDiscapacidad() {
	return this->discapacidad;
}

EspacioEstacionamiento^ Cliente::getEspacioEstacionamiento() {
	return this->espacioEstacionamiento;
}
List<Membresia^>^ Cliente::getListasMembresias() {
	return this->listasMembresias;
}
List<TarjetaRFID^>^ Cliente::getListaTarjetasRFID() {
	return this->listaTarjetasRFID;
}
List<Vehiculo^>^ Cliente::getListaVehiculos() {
	return this->listaVehiculos;
}



void Cliente::setFechaAfiliacion(DateTime fechaAfiliacion) {
	this->fechaAfiliacion = fechaAfiliacion;
}
void Cliente::setTipo(TipoCliente tipo) {
	this->tipo = tipo;
}
void Cliente::setObservaciones(String^ observaciones) {
	this->observaciones = observaciones;
}
void Cliente::setSaldo(double saldo) {
	this->saldo = saldo;
}
void Cliente::setRequierePreferencial(bool requierePreferencial) {
	this->requierePreferencial = requierePreferencial;
}
void Cliente::setDiscapacidad(String^ discapacidad) {
	this->discapacidad = discapacidad;
}
void Cliente::setEspacioEstacionamiento(EspacioEstacionamiento^ espacioEstacionamiento) {
	this->espacioEstacionamiento = espacioEstacionamiento;
}
void Cliente::setListasMembresias(List<Membresia^>^ listasMembresias) {
	this->listasMembresias = listasMembresias;
}
void Cliente::setListaTarjetasRFID(List<TarjetaRFID^>^ listaTarjetasRFID) {
	this->listaTarjetasRFID = listaTarjetasRFID;
}
void Cliente::setListaVehiculos(List<Vehiculo^>^ listaVehiculos) {
	this->listaVehiculos = listaVehiculos;
}