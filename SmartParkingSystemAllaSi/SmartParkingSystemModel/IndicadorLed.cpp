#include "pch.h"
#include "IndicadorLed.h"

using namespace CocheraModel;

IndicdorLed::IndicdorLed() {

}
IndicdorLed::IndicdorLed(int idPeriferico,
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

String^ IndicdorLed::getColor() {
	return this->color;
}
int IndicdorLed::getIntesidad() {
	return this->intesidad;
}
bool IndicdorLed::getEstaEncendido() {
	return this->estaEncendido;
}
String^ IndicdorLed::getTipoLuz() {
	return this->tipoLuz;
}
String^ IndicdorLed::getModoOperacion() {
	return this->modoOperacion;
}



void IndicdorLed::setColor(String^ color) {
	this->color = color;
}
void IndicdorLed::setIntesidad(int intesidad) {
	this->intesidad = intesidad;
}
void IndicdorLed::setEstaEncendido(bool estaEncendido) {
	this->estaEncendido = estaEncendido;
}
void IndicdorLed::setTipoLuz(String^ tipoLuz) {
	this->tipoLuz = tipoLuz;
}
void IndicdorLed::setModoOperacion(String^ modoOperacion) {
	this->modoOperacion = modoOperacion;
}