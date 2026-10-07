#include "pch.h"
#include "EspacioEstacionamiento.h"
#include "IndicadorLed.h"
#include "SensorOcupacion.h"
#include "Cliente.h"

using namespace SmartParkingSystemModel;

EspacioEstacionamiento::EspacioEstacionamiento() {


}
EspacioEstacionamiento::EspacioEstacionamiento(

	int idEspacio,
	String^ codigo,
	TipoEstacionamiento tipo,
	double largo,
	double ancho,
	bool estaOcupado,

	SensorOcupacion^ sensorOcupacion,
	IndicadorLed^ indicadorLed,
	List<Cliente^>^ listaClientes
) {

	this->idEspacio = idEspacio;
	this->codigo = codigo;
	this->tipo = tipo;
	this->largo = largo;
	this->ancho = ancho;
	this->estaOcupado = estaOcupado;

	this->sensorOcupacion = sensorOcupacion;
	this->indicadorLed = indicadorLed;
	this->listaClientes = listaClientes;

}

int EspacioEstacionamiento::getIdEspacio() {
	return this->idEspacio;
}
String^ EspacioEstacionamiento::getCodigo() {
	return this->codigo;
}
TipoEstacionamiento EspacioEstacionamiento::getTipo() {
	return this->tipo;
}
double EspacioEstacionamiento::getLargo() {
	return this->largo;
}
double EspacioEstacionamiento::getAncho() {
	return this->ancho;
}
bool EspacioEstacionamiento::getEstaOcupado() {
	return this->estaOcupado;
}
SensorOcupacion^ EspacioEstacionamiento::getSensorOcupacion() {
	return this->sensorOcupacion;
}
IndicadorLed^ EspacioEstacionamiento::getIndicadorLed() {
	return this->indicadorLed;
}
List<Cliente^>^ EspacioEstacionamiento::getListaClientes() {
	return this->listaClientes;
}



void EspacioEstacionamiento::setIdEspacio(int idEspacio) {
	this->idEspacio = idEspacio;
}
void EspacioEstacionamiento::setCodigo(String^ codigo) {
	this->codigo = codigo;
}
void EspacioEstacionamiento::setTipo(TipoEstacionamiento tipo) {
	this->tipo = tipo;
}
void EspacioEstacionamiento::setLargo(double largo) {
	this->largo = largo;
}
void EspacioEstacionamiento::setAncho(double ancho) {
	this->ancho = ancho;
}
void EspacioEstacionamiento::setEstaOcupado(bool estaOcupado) {
	this->estaOcupado = estaOcupado;
}
void EspacioEstacionamiento::setSensorOcupacion(SensorOcupacion^ sensorOcupacion) {
	this->sensorOcupacion = sensorOcupacion;
}
void EspacioEstacionamiento::setIndicadorLed(IndicadorLed^ indicadorLed) {
	this->indicadorLed = indicadorLed;
}
void EspacioEstacionamiento::setListaClientes(List<Cliente^>^ listaClientes) {
	this->listaClientes = listaClientes;
}