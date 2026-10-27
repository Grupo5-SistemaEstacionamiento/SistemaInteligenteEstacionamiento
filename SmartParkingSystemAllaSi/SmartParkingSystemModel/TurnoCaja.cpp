#include "pch.h"

#include "TurnoCaja.h"
#include "Empleado.h"

namespace SmartParkingSystemModel {

	// Constructor predeterminado.
	TurnoCaja::TurnoCaja()
	{
		idTurno = 0;
		fechaHoraIngreso = DateTime::MinValue;
		fechaHoraSalida = DateTime::MinValue;
		saldoInicial = 0.0;
		saldoFinal = 0.0;
		observacion = String::Empty;
		estado = "Cerrado";
		empleado = nullptr;
		listaMovimientos = gcnew List<Movimiento^>();
	}

	// Constructor completo.
	TurnoCaja::TurnoCaja(
		int idTurno,
		DateTime fechaHoraIngreso,
		DateTime fechaHoraSalida,
		double saldoInicial,
		double saldoFinal,
		String^ observacion,
		String^ estado,
		List<Movimiento^>^ listaMovimientos,
		Empleado^ empleado)
	{
		this->idTurno = idTurno;
		this->fechaHoraIngreso = fechaHoraIngreso;
		this->fechaHoraSalida = fechaHoraSalida;
		this->saldoInicial = saldoInicial;
		this->saldoFinal = saldoFinal;
		this->observacion = observacion;
		this->estado = estado;
		this->empleado = empleado;

		this->listaMovimientos =
			listaMovimientos == nullptr
			? gcnew List<Movimiento^>()
			: listaMovimientos;
	}

	// Constructor para iniciar un turno.
	TurnoCaja::TurnoCaja(
		int idTurno,
		double saldoInicial,
		Empleado^ empleado)
	{
		this->idTurno = idTurno;
		this->fechaHoraIngreso = DateTime::Now;
		this->fechaHoraSalida = DateTime::MinValue;
		this->saldoInicial = saldoInicial;
		this->saldoFinal = 0.0;
		this->observacion = String::Empty;
		this->estado = "Abierto";
		this->empleado = empleado;
		this->listaMovimientos = gcnew List<Movimiento^>();
	}

	void TurnoCaja::CerrarTurno(double saldoFinal, String^ observacion) {
		this->fechaHoraSalida = DateTime::Now; 
		this->saldoFinal = saldoFinal;
		this->observacion = observacion;
		this->estado = "Cerrado";
	}

	int TurnoCaja::getIdTurno() {
		return this->idTurno;
	}
	DateTime TurnoCaja::getFechaHoraIngreso() {
		return this->fechaHoraIngreso;
	}
	DateTime TurnoCaja::getFechaHoraSalida() {
		return this->fechaHoraSalida;
	}
	double TurnoCaja::getSaldoInicial() {
		return this->saldoInicial;
	}
	double TurnoCaja::getSaldoFinal() {
		return this->saldoFinal;
	}
	String^ TurnoCaja::getObservacion() {
		return this->observacion;
	}
	String^ TurnoCaja::getEstado() {
		return this->estado;
	}
	List<Movimiento^>^ TurnoCaja::getListaMovimientos() {
		return this->listaMovimientos;
	}
	Empleado^ TurnoCaja::getEmpleado() {
		return this->empleado;
	}

	void TurnoCaja::setIdTurno(int idTurno) {
		this->idTurno = idTurno;
	}
	void TurnoCaja::setFechaHoraIngreso(DateTime fechaHoraIngreso) {
		this->fechaHoraIngreso = fechaHoraIngreso;
	}
	void TurnoCaja::setFechaHoraSalida(DateTime fechaHoraSalida) {
		this->fechaHoraSalida = fechaHoraSalida;
	}
	void TurnoCaja::setSaldoInicial(double saldoInicial) {
		this->saldoInicial = saldoInicial;
	}
	void TurnoCaja::setSaldoFinal(double saldoFinal) {
		this->saldoFinal = saldoFinal;
	}
	void TurnoCaja::setObservacion(String^ observacion) {
		this->observacion = observacion;
	}
	void TurnoCaja::setEstado(String^ estado) {
		this->estado = estado;
	}
	void TurnoCaja::setListaMovimientos(List<Movimiento^>^ listaMovimientos) {
		this->listaMovimientos = listaMovimientos;
	}
	void TurnoCaja::setEmpleado(Empleado^ empleado) {
		this->empleado = empleado;
	}
}