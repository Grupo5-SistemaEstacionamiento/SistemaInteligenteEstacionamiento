#include "pch.h"
#include "TurnoCaja.h"
#include "Empleado.h"

namespace SmartParkingSystemModel {

	TurnoCaja::TurnoCaja() {
		this->listaMovimientos = gcnew List<Movimiento^>();

	}
	TurnoCaja::TurnoCaja(
		int idTurno,
		DateTime fechaHoraIngreso,
		DateTime fechaHoraSalida,
		double saldoInicial,
		double saldoFinal,
		String^ observacion,
		String^ estado,
		List<Movimiento^>^ listaMovimientos,
		Empleado^ empleado

	) {
		this->idTurno = idTurno;
		this->fechaHoraIngreso = fechaHoraIngreso;
		this->fechaHoraSalida = fechaHoraSalida;
		this->saldoInicial = saldoInicial;
		this->saldoFinal = saldoFinal;
		this->observacion = observacion;
		this->estado = estado;
		this->listaMovimientos = listaMovimientos;
		this->empleado = empleado;

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