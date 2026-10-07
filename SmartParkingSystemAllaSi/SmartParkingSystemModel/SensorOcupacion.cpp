#include "pch.h"
#include "SensorOcupacion.h"

using namespace CocheraModel;

SensorOcupacion::SensorOcupacion() {

}
SensorOcupacion::SensorOcupacion(
	int idPeriferico,
	String^ ubicacion,
	DateTime fechaInstalacion,
	DateTime fechaUltimoMant,
	EstadoPeriferico estado,
	bool hayEmergencia,
	double umbralDeteccion,
	double valorLectura,
	bool detectaVehiculo,
	DateTime fechaUltimaLectura
) {

	this->umbralDeteccion = umbralDeteccion;
	this->valorLectura = valorLectura;
	this->detectaVehiculo = detectaVehiculo;
	this->fechaUltimaLectura = fechaUltimaLectura;
}

double SensorOcupacion::getUmbralDeteccion() {
	return this->umbralDeteccion;
}
double SensorOcupacion::getValorLectura() {
	return this->valorLectura;
}
bool SensorOcupacion::getDetectaVehiculo() {
	return this->detectaVehiculo;
}
DateTime SensorOcupacion::getFechaUltimaLectura() {
	return this->fechaUltimaLectura;
}



void SensorOcupacion::setUmbralDeteccion(double umbralDeteccion) {
	this->umbralDeteccion = umbralDeteccion;
}
void SensorOcupacion::setValorLectura(double valorLectura) {
	this->valorLectura = valorLectura;
}
void SensorOcupacion::setDetectaVehiculo(bool detectaVehiculo) {
	this->detectaVehiculo = detectaVehiculo;
}
void SensorOcupacion::setFechaUltimaLectura(DateTime fechaUltimaLectura) {
	this->fechaUltimaLectura = fechaUltimaLectura;
}