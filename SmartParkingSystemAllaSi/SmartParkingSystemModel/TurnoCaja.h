#pragma once
#include "Movimiento.h"


namespace SmartParkingSystemModel {

	using namespace System;
	using namespace System::Collections::Generic;

	ref class Empleado;

	public ref class TurnoCaja {

	private:
		int idTurno;
		DateTime fechaHoraIngreso;
		DateTime fechaHoraSalida;
		double saldoInicial;
		double saldoFinal;
		String^ observacion;
		String^ estado;
		List<Movimiento^>^ listaMovimientos;
		Empleado^ empleado;


	public:
		TurnoCaja();
		TurnoCaja(
			int idTurno,
			DateTime fechaHoraIngreso,
			DateTime fechaHoraSalida,
			double saldoInicial,
			double saldoFinal,
			String^ observacion,
			String^ estado,
			List<Movimiento^>^ listaMovimientos,
			Empleado^ empleado
		);
		
		int getIdTurno();
		DateTime getFechaHoraIngreso();
		DateTime getFechaHoraSalida();
		double getSaldoInicial();
		double getSaldoFinal();
		String^ getObservacion();
		String^ getEstado();
		List<Movimiento^>^ getListaMovimientos();
		Empleado^ getEmpleado();


		void setIdTurno(int idTurno);
		void setFechaHoraIngreso(DateTime fechaHoraIngreso);
		void setFechaHoraSalida(DateTime fechaHoraSalida);
		void setSaldoInicial(double saldoInicial);
		void setSaldoFinal(double saldoFinal);
		void setObservacion(String^ observacion);
		void setEstado(String^ estado);
		void setListaMovimientos(List<Movimiento^>^ listaMovimientos);
		void setEmpleado(Empleado^ Empleado);
			

	};

}