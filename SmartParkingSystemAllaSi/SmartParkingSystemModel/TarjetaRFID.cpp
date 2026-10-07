#include "pch.h"
#include "TarjetaRFID.h"
#include "LectorRFID.h"
#include "Cliente.h"

using namespace CocheraModel;

TarjetaRFID::TarjetaRFID() {

	this->listaLecturas = gcnew List<LectorRFID^>();

}
TarjetaRFID::TarjetaRFID(
	int idTarjeta,
	String^ codigoUID,
	DateTime fechaEmision,
	DateTime fechaVencimiento,
	bool activa,

	List<LectorRFID^>^ listaLecturas,
	Cliente^ cliente

) {
	this->idTarjeta = idTarjeta;
	this->codigoUID = codigoUID;
	this->fechaEmision = fechaEmision;
	this->fechaVencimiento = fechaVencimiento;
	this->activa = activa;

	this->listaLecturas = listaLecturas;
	this->cliente = cliente;

}

int TarjetaRFID::getIdTarjeta() {
	return this->idTarjeta;
}
String^ TarjetaRFID::getCodigoUID() {
	return this->codigoUID;
}
DateTime TarjetaRFID::getFechaEmision() {
	return this->fechaEmision;
}
DateTime TarjetaRFID::getFechaVencimiento() {
	return this->fechaVencimiento;
}
bool TarjetaRFID::getActiva() {
	return this->activa;
}
List<LectorRFID^>^ TarjetaRFID::getListaLecturas() {
	return this->listaLecturas;
}
Cliente^ TarjetaRFID::getCliente() {
	return this->cliente;
}


void TarjetaRFID::setIdTarjeta(int idTarjeta) {
	this->idTarjeta = idTarjeta;
}
void TarjetaRFID::setCodigoUID(String^ codigoUID) {
	this->codigoUID = codigoUID;
}
void TarjetaRFID::setFechaEmision(DateTime fechaEmision) {
	this->fechaEmision = fechaEmision;
}
void TarjetaRFID::setFechaVencimiento(DateTime fechaVencimiento) {
	this->fechaVencimiento = fechaVencimiento;
}
void TarjetaRFID::setActiva(bool activa) {
	this->activa = activa;
}
void TarjetaRFID::setListaLecturas(List<LectorRFID^>^ listaLecturas) {
	this->listaLecturas = listaLecturas;
}
void TarjetaRFID::setCliente(Cliente^ cliente) {
	this->cliente = cliente;
}