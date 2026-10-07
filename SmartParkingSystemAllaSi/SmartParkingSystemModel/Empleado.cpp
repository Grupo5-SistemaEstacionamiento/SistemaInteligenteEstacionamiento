#include "pch.h"
#include "Empleado.h"
#include "TurnoCaja.h"

namespace SmartParkingSystemModel {

	Empleado::Empleado() {
		this->listaTurnosCaja = gcnew List<TurnoCaja^>();

	}
	Empleado::Empleado(
		int idPersona,
		String^ nombres,
		String^ apellidos,
		String^ documento,
		String^ telefono,
		String^ correo,
		DateTime fechaRegistro,
		bool estado,

		String^ codigoEmpleado,
		String^ cargo,
		String^ turno,
		DateTime fechaContratacion,
		bool enTurno,

		RegistroAcceso^ registroAcceso,
		List<TurnoCaja^>^ listaTurnosCaja
	) {


	}

	String^ Empleado::getCodigoEmpleado() {
		return this->codigoEmpleado;
	}
	String^ Empleado::getCargo() {
		return this->cargo;
	}
	String^ Empleado::getTurno() {
		return this->turno;
	}
	DateTime Empleado::getFechaContratacion() {
		return this->fechaContratacion;
	}
	bool Empleado::getEnTurno() {
		return this->enTurno;
	}
	RegistroAcceso^ Empleado::getRegistroAcceso() {
		return this->registroAcceso;
	}
	List<TurnoCaja^>^ Empleado::getListaTurnosCaja() {
		return this->listaTurnosCaja;
	}



	void Empleado::setCodigoEmpleado(String^ codigoEmpleado) {
		this->codigoEmpleado = codigoEmpleado;
	}
	void Empleado::setCargo(String^ cargo) {
		this->cargo = cargo;
	}
	void Empleado::setTurno(String^ turno) {
		this->turno = turno;
	}
	void Empleado::setFechaContratacion(DateTime fechaContratacion) {
		this->fechaContratacion = fechaContratacion;
	}
	void Empleado::setEnTurno(bool enTurno) {
		this->enTurno = enTurno;
	}
	void Empleado::setRegistroAcceso(RegistroAcceso^ registroAcceso) {
		this->registroAcceso = registroAcceso;
	}
	void Empleado::setListaTurnosCaja(List<TurnoCaja^>^ listaTurnosCaja) {
		this->listaTurnosCaja = listaTurnosCaja;
	}
}