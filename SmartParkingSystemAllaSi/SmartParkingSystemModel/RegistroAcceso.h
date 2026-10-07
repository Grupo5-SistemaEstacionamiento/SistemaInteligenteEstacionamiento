#pragma once
namespace SmartParkingSystemModel {
	using namespace System;
	using namespace System::Collections::Generic;
	ref class EspacioEstacionamiento;
	ref class Tarifa;
	ref class Vehiculo;
	ref class Empleado;
	ref class Movimiento;
	public ref class RegistroAcceso {


	private:
		int idRegistro;
		DateTime fechaHoraIngreso;
		DateTime fechaHoraSalida;
		bool accesoAutorizado;
		String^ observacion;
		bool seHaPagado;
		double montoTotalServicio;

		EspacioEstacionamiento^ espacioEstacionamiento;
		Tarifa^ tarifa;
		Vehiculo^ vehiculo;
		Empleado^ empleado;
		List<Movimiento^>^ listaMoviminetos;


	public:
		RegistroAcceso();
		RegistroAcceso(
			int idRegistro,
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
			);

		int getIdRegistro();
		DateTime getFechaHoraIngreso();
		DateTime getFechaHoraSalida();
		bool getAccesoAutorizado();
		String^ getObservacion();
		bool getSeHaPagado();
		double getMontoTotalServicio();

		EspacioEstacionamiento^ getEspacioEstacionamiento();
		Tarifa^ getTarifa();
		Vehiculo^ getVehiculo();
		Empleado^ getEmpleado();
		List<Movimiento^>^ getListaMoviminetos();


		void setIdRegistro(int idRegistro);
		void setFechaHoraIngreso(DateTime fechaHoraIngreso);
		void setFechaHoraSalida(DateTime fechaHoraSalida);
		void setAccesoAutorizado(bool accesoAutorizado);
		void setObservacion(String^ observacion);
		void setSeHaPagado(bool seHaPagado);
		void setMontoTotalServicio(double montoTotalServicio);

		void setTarifa(Tarifa^ espacioEstacionamiento);
		void setVehiculo(Vehiculo^ tarifa);
		void setEmpleado(Empleado^ vehiculo);
		void setListaMoviminetos(List<Movimiento^>^ listaMoviminetos);

	};

 
}