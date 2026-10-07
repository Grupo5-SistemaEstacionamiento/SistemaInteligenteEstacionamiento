#pragma once
#include "Persona.h"
#include "RegistroAcceso.h"



namespace SmartParkingSystemModel {

	ref class TurnoCaja;

	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Empleado : Persona {

	private:
		String^ codigoEmpleado;
		String^ cargo;
		String^ turno;
		DateTime fechaContratacion;
		bool enTurno;
		RegistroAcceso^ registroAcceso;
		List<TurnoCaja^>^ listaTurnosCaja;

	public:

		Empleado();
		Empleado(
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
		);

		String^ getCodigoEmpleado();
		String^ getCargo();
		String^ getTurno();
		DateTime getFechaContratacion();
		bool getEnTurno();
		RegistroAcceso^ getRegistroAcceso();
		List<TurnoCaja^>^ getListaTurnosCaja();

		void setCodigoEmpleado(String^ codigoEmpleado);
		void setCargo(String^ cargo);
		void setTurno(String^ turno);
		void setFechaContratacion(DateTime fechaContratacion);
		void setEnTurno(bool enTurno);
		void setRegistroAcceso(RegistroAcceso^ registroAcceso);
		void setListaTurnosCaja(List<TurnoCaja^>^ listaTurnosCaja);

	};


}