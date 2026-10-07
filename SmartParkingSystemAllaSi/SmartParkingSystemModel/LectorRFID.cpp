#include "pch.h"
#include "LectorRFID.h"

using namespace CocheraModel;

LectorRFID::LectorRFID() {

}
LectorRFID::LectorRFID(int idPeriferico,
	String^ ubicacion,
	DateTime fechaInstalacion,
	DateTime fechaUltimoMant,
	EstadoPeriferico estado,
	bool hayEmergencia,
	double frecOperacion,
	double distanciaLecturaMax,
	String^ idUltimaTarjeta,
	String^ protocoloComunicacion,
	bool esLecturaEntrada,
	double potenciaTransmicion) {

	this->frecOperacion = frecOperacion;
	this->distanciaLecturaMax = distanciaLecturaMax;
	this->idUltimaTarjeta = idUltimaTarjeta;
	this->protocoloComunicacion = protocoloComunicacion;
	this->esLecturaEntrada = esLecturaEntrada;
	this->potenciaTransmicion = potenciaTransmicion;


}

double LectorRFID::getFrecOperacion() {
	return this->frecOperacion;
}
double LectorRFID::getDistanciaLecturaMax() {
	return this->distanciaLecturaMax;
}
String^ LectorRFID::getIdUltimaTarjeta() {
	return this->idUltimaTarjeta;
}
String^ LectorRFID::getProtocoloComunicacion() {
	return this->protocoloComunicacion;
}
bool LectorRFID::getEsLecturaEntrada() {
	return this->esLecturaEntrada;
}
double LectorRFID::getPotenciaTransmicion() {
	return this->potenciaTransmicion;
}


void LectorRFID::setFrecOperacion(double frecOperacion) {
	this->frecOperacion = frecOperacion;
}
void LectorRFID::setDistanciaLecturaMax(double distanciaLecturaMax) {
	this->distanciaLecturaMax = distanciaLecturaMax;
}
void LectorRFID::setIdUltimaTarjeta(String^ idUltimaTarjeta) {
	this->idUltimaTarjeta = idUltimaTarjeta;
}
void LectorRFID::setProtocoloComunicacion(String^ protocoloComunicacion) {
	this->protocoloComunicacion = protocoloComunicacion;
}
void LectorRFID::setEsLecturaEntrada(bool esLecturaEntrada) {
	this->esLecturaEntrada = esLecturaEntrada;
}
void LectorRFID::setPotenciaTransmicion(double potenciaTransmicion) {
	this->potenciaTransmicion = potenciaTransmicion;
}
