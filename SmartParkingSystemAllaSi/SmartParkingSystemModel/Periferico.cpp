#include "pch.h"
#include "Periferico.h"

using namespace CocheraModel;

Periferico::Periferico() {

}
Periferico::Periferico(
	int idPeriferico,
	String^ ubicacion,
	DateTime fechaInstalacion,
	DateTime fechaUltimoMant,
	EstadoPeriferico estado,
	bool hayEmergencia) {

	this->idPeriferico=idPeriferico;
	this->ubicacion = ubicacion;
	this->fechaInstalacion = fechaInstalacion;
	this->fechaUltimoMant = fechaUltimoMant;
	this->estado = estado;
	this->hayEmergencia = hayEmergencia;
}

int Periferico::getIdPeriferico() {
	return this->idPeriferico;
}
String^ Periferico::getUbicacion() {
	return this->ubicacion;
}
DateTime Periferico::getFechaInstalacion() {
	return this->fechaInstalacion;
}
DateTime Periferico::getFechaUltimoMant() {
	return this->fechaUltimoMant;
}
EstadoPeriferico Periferico::getEstado() {
	return this->estado;
}
bool Periferico::getHayEmergencia() {
	return this->hayEmergencia;
}

void Periferico::getIdPeriferico(int idPeriferico) {
	this->idPeriferico = idPeriferico;
}
void Periferico::getUbicacion(String^ ubicacion) {
	this->ubicacion = ubicacion;
}
void Periferico::getFechaInstalacion(DateTime fechaInstalacion) {
	this->fechaInstalacion = fechaInstalacion;
}
void Periferico::getFechaUltimoMant(DateTime fechaUltimoMant) {
	this->fechaUltimoMant = fechaUltimoMant;
}
void Periferico::getEstado(EstadoPeriferico estado) {
	this->estado = estado;
}
void Periferico::getHayEmergencia(bool hayEmergencia) {
	this->hayEmergencia = hayEmergencia;
}