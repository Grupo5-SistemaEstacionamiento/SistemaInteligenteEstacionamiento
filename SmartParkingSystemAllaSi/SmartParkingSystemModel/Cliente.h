#pragma once
namespace SmartParkingSystemModel {

	using namespace System;
	ref class Membresia;
	ref class Vehiculo;
	ref class TarjetaRFID;
	ref class EspacioEstacionamiento;

	using namespace System::Collections::Generic;

	public enum class TipoCliente {

		MIEMBRO,
		NO_MIEMBRO,

	};
	public ref class Cliente {

	private:
		DateTime fechaAfiliacion;
		TipoCliente tipo;
		String^ observaciones;
		double saldo;
		bool requierePreferencial;
		String^ discapacidad;

		EspacioEstacionamiento^ espacioEstacionamiento;
		List<Membresia^>^ listasMembresias;
		List<TarjetaRFID^>^ listaTarjetasRFID;
		List<Vehiculo^>^ listaVehiculos;


	public:
		Cliente();
		Cliente(
			DateTime fechaAfiliacion,
			TipoCliente tipo,
			String^ observaciones,
			double saldo,
			bool requierePreferencial,
			String^ discapacidad,
			EspacioEstacionamiento^ espacioEstacionamiento,
			List<Membresia^>^ listasMembresias,
			List<TarjetaRFID^>^ listaTarjetasRFID,
			List<Vehiculo^>^ listaVehiculos
		);


		DateTime getFechaAfiliacion();
		TipoCliente getTipo();
		String^ getObservaciones();
		double getSaldo();
		bool getRequierePreferencial();
		String^ getDiscapacidad();

		EspacioEstacionamiento^ getEspacioEstacionamiento();
		List<Membresia^>^ getListasMembresias();
		List<TarjetaRFID^>^ getListaTarjetasRFID();
		List<Vehiculo^>^ getListaVehiculos();



		void setFechaAfiliacion(DateTime fechaAfiliacion);
		void setTipo(TipoCliente tipo);
		void setObservaciones(String^ observaciones);
		void setSaldo(double saldo);
		void setRequierePreferencial(bool requierePreferencial);
		void setDiscapacidad(String^ discapacidad);

		void setEspacioEstacionamiento(EspacioEstacionamiento^ espacioEstacionamiento);
		void setListasMembresias(List<Membresia^>^ listasMembresias);
		void setListaTarjetasRFID(List<TarjetaRFID^>^ listaTarjetasRFID);
		void setListaVehiculos(List<Vehiculo^>^ listaVehiculos);
	};

}