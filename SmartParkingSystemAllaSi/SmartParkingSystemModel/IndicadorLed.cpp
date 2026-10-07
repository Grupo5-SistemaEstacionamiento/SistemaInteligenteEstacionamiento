#include "pch.h"
#include "IndicadorLed.h"

using namespace SmartParkingSystemModel;

IndicadorLed::IndicadorLed() {

}
IndicadorLed::IndicadorLed(int idPeriferico,
	String^ ubicacion,
	DateTime fechaInstalacion,
	DateTime fechaUltimoMant,
	EstadoPeriferico estado,
	bool hayEmergencia,
	String^ color,
	int intesidad,
	bool estaEncendido,
	String^ tipoLuz,
	String^ modoOperacion) {

	this->color = color;
	this->intesidad = intesidad;
	this->estaEncendido = estaEncendido;
	this->tipoLuz = tipoLuz;
	this->modoOperacion = modoOperacion;

}

String^ IndicadorLed::getColor() {
	return this->color;
}
int IndicadorLed::getIntesidad() {
	return this->intesidad;
}
bool IndicadorLed::getEstaEncendido() {
	return this->estaEncendido;
}
String^ IndicadorLed::getTipoLuz() {
	return this->tipoLuz;
}
String^ IndicadorLed::getModoOperacion() {
	return this->modoOperacion;
}



void IndicadorLed::setColor(String^ color) {
	this->color = color;
}
void IndicadorLed::setIntesidad(int intesidad) {
	this->intesidad = intesidad;
}
void IndicadorLed::setEstaEncendido(bool estaEncendido) {
	this->estaEncendido = estaEncendido;
}
void IndicadorLed::setTipoLuz(String^ tipoLuz) {
	this->tipoLuz = tipoLuz;
}
void IndicadorLed::setModoOperacion(String^ modoOperacion) {
	this->modoOperacion = modoOperacion;
}