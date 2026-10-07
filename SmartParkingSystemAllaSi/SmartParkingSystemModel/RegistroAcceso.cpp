#include "pch.h"
#include "RegistroAcceso.h"

using namespace CocheraModel;

RegistroAcceso::RegistroAcceso() {
	this->listaMoviminetos = gcnew List<Movimiento^>();
}
RegistroAcceso::RegistroAcceso(int idRegistro,
	DateTime fechaHoraIngreso,
	DateTime fechaHoraSalida,
	bool accesoAutorizado,
	String^ observacion,
	bool seHaPagado,
	double montoTotalServicio,

	EspacioEstacionamiento^ espacioEstacionamiento,
	Tarifa^ tarifa,
	Vehiculo^ vehiculo,
	Empleado^ empleado,
	List<Movimiento^>^ listaMoviminetos
) {

	this->idRegistro = idRegistro;
	this->fechaHoraIngreso = fechaHoraIngreso;
	this->fechaHoraSalida = fechaHoraSalida;
	this->accesoAutorizado = accesoAutorizado;
	this->observacion = observacion;
	this->seHaPagado = seHaPagado;
	this->montoTotalServicio = montoTotalServicio;
	this->espacioEstacionamiento = espacioEstacionamiento;
	this->tarifa = tarifa;
	this->vehiculo = vehiculo;
	this->empleado = empleado;
	this->listaMoviminetos = listaMoviminetos;
}

int RegistroAcceso::getIdRegistro() {
	return this->idRegistro;
}
DateTime RegistroAcceso::getFechaHoraIngreso() {
	return this->fechaHoraIngreso;
}
DateTime RegistroAcceso::getFechaHoraSalida() {
	return this->fechaHoraSalida;
}
bool RegistroAcceso::getAccesoAutorizado() {
	return this->accesoAutorizado;
}
String^ RegistroAcceso::getObservacion() {
	return this->observacion;
}
bool RegistroAcceso::getSeHaPagado() {
	return this->seHaPagado;
}
double RegistroAcceso::getMontoTotalServicio() {
	return this->montoTotalServicio;
}
EspacioEstacionamiento^ RegistroAcceso::getEspacioEstacionamiento() {
	return this->espacioEstacionamiento;
}
Tarifa^ RegistroAcceso::getTarifa() {
	return this->tarifa;
}
Vehiculo^ RegistroAcceso::getVehiculo() {
	return this->vehiculo;
}
Empleado^ RegistroAcceso::getEmpleado() {
	return this->empleado;
}
List<Movimiento^>^ RegistroAcceso::getListaMoviminetos() {
	return this->listaMoviminetos;
}


void RegistroAcceso::setIdRegistro(int idRegistro) {
	this->idRegistro = idRegistro;
}
void RegistroAcceso::setFechaHoraIngreso(DateTime fechaHoraIngreso) {
	this->fechaHoraIngreso = fechaHoraIngreso;
}
void RegistroAcceso::setFechaHoraSalida(DateTime fechaHoraSalida) {
	this->fechaHoraSalida = fechaHoraSalida;
}
void RegistroAcceso::setAccesoAutorizado(bool accesoAutorizado) {
	this->accesoAutorizado = accesoAutorizado;
}
void RegistroAcceso::setObservacion(String^ observacion) {
	this->observacion = observacion;
}
void RegistroAcceso::setSeHaPagado(bool seHaPagado) {
	this->seHaPagado = seHaPagado;
}
void RegistroAcceso::setMontoTotalServicio(double montoTotalServicio) {
	this->montoTotalServicio = montoTotalServicio;
}

void RegistroAcceso::setTarifa(Tarifa^ tarifa) {
	this->tarifa = tarifa;
}
void RegistroAcceso::setVehiculo(Vehiculo^ vehiculo) {
	this->vehiculo = vehiculo;
}
void RegistroAcceso::setEmpleado(Empleado^ empleado) {
	this->empleado = empleado;
}
void RegistroAcceso::setListaMoviminetos(List<Movimiento^>^ listaMoviminetos) {
	this->listaMoviminetos = listaMoviminetos;
}