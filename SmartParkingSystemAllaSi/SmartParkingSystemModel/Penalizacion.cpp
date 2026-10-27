#include "pch.h"

#include "Penalizacion.h"
#include "Vehiculo.h"
#include "Movimiento.h"

using namespace SmartParkingSystemModel;

Penalizacion::Penalizacion() {
	idPenalizacion = 0;
	placaVehiculo = String::Empty;
	tipo = TipoPenalizacion::PERDIDA_TARJETA;
	fechaHora = DateTime::Now;
	pagado = false;
	fechaPago = DateTime::MinValue;
	motivo = String::Empty;
	monto = 0;
	vehiculo = nullptr;
	listaMovimientos = gcnew List<Movimiento^>();
}

Penalizacion::Penalizacion(
	int idPenalizacion,
	TipoPenalizacion tipo,
	DateTime fechaHora,
	bool pagado,
	DateTime fechaPago,
	String^ motivo,
	double monto,

	Vehiculo^ vehiculo,
	List<Movimiento^>^ listaMovimientos
) {
	this->idPenalizacion = idPenalizacion;
	this->placaVehiculo = 
		(vehiculo == nullptr) ? String::Empty : vehiculo->getPlaca();

	this->tipo = tipo;
	this->fechaHora = fechaHora;
	this->pagado = pagado;
	this->fechaPago = fechaPago;
	this->motivo = motivo;
	this->monto = monto;

	this->vehiculo = vehiculo;
	this->listaMovimientos = 
		(listaMovimientos == nullptr)
		? gcnew List<Movimiento^>()
		: listaMovimientos;
}

int Penalizacion::getIdPenalizacion() {
	return this->idPenalizacion;
}
TipoPenalizacion Penalizacion::getTipo() {
	return this->tipo;
}
DateTime Penalizacion::getFechaHora() {
	return this->fechaHora;
}
bool Penalizacion::getPagado() {
	return this->pagado;
}
DateTime Penalizacion::getFechaPago() {
	return this->fechaPago;
}
String^ Penalizacion::getMotivo() {
	return this->motivo;
}
double Penalizacion::getMonto() {
	return this->monto;
}
Vehiculo^ Penalizacion::getVehiculo() {
	return this->vehiculo;
}
List<Movimiento^>^ Penalizacion::getListaMovimientos() {
	return this->listaMovimientos;
}

void Penalizacion::setIdPenalizacion(int idPenalizacion) {
	this->idPenalizacion = idPenalizacion;
}
void Penalizacion::setTipo(TipoPenalizacion tipo) {
	this->tipo = tipo;
}
void Penalizacion::setFechaHora(DateTime fechaHora) {
	this->fechaHora = fechaHora;
}
void Penalizacion::setPagado(bool pagado) {
	this->pagado = pagado;
}
void Penalizacion::setFechaPago(DateTime fechaPago) {
	this->fechaPago = fechaPago;
}
void Penalizacion::setMotivo(String^ motivo) {
	this->motivo = motivo;
}
void Penalizacion::setMonto(double monto) {
	this->monto = monto;
}
void Penalizacion::setVehiculo(Vehiculo^ vehiculo) {
	this->vehiculo = vehiculo;
}
void Penalizacion::setListaMovimientos(List<Movimiento^>^ listaMovimientos) {
	this->listaMovimientos = listaMovimientos;
}

String^ Penalizacion::getPlacaVehiculo() { 
	return placaVehiculo; 
}
void Penalizacion::setPlacaVehiculo(String^ placa) { 
	placaVehiculo = placa == nullptr 
		? String::Empty 
		: placa->Trim()->ToUpperInvariant(); 
}

// Registra el pago de una penalización pendiente.
bool Penalizacion::registrarPagoPenalidad(DateTime fecha)
{
	// No permite registrar nuevamente una penalización pagada.
	if (this->pagado)
		return false;

	// La fecha de pago no puede ser anterior a la penalización.
	if (fecha < this->fechaHora)
		return false;

	// La fecha de pago no puede ser futura.
	if (fecha > DateTime::Now)
		return false;

	this->pagado = true;
	this->fechaPago = fecha;

	return true;
}

// Verifica si la penalización sigue pendiente.
bool Penalizacion::estaPendiente()
{
	return !this->pagado;
}
