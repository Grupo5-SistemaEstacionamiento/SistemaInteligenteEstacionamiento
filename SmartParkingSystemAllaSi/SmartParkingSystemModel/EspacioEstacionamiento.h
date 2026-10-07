#pragma once

namespace SmartParkingSystemModel {

	using namespace System;
	using namespace System::Collections::Generic;
	ref class IndicadorLed;
	ref class SensorOcupacion;
	ref class Cliente;

	public enum class TipoEstacionamiento {

		Normal,
	    Discapacitado,
		Reservado,

	};

	public ref class EspacioEstacionamiento{

	private:

		int idEspacio;
		String^ codigo;
		TipoEstacionamiento tipo;
		double largo;
		double ancho;
		bool estaOcupado;

		SensorOcupacion^ sensorOcupacion;
		IndicadorLed^ indicadorLed;
		List<Cliente^>^ listaClientes;

	public:

		EspacioEstacionamiento();
		EspacioEstacionamiento(
		
			int idEspacio,
			String^ codigo,
			TipoEstacionamiento tipo,
			double largo,
			double ancho,
			bool estaOcupado,

			SensorOcupacion^ sensorOcupacion,
			IndicadorLed^ indicadorLed,
			List<Cliente^>^ listaClientes
		);

		int getIdEspacio();
		String^ getCodigo();
		TipoEstacionamiento getTipo();
		double getLargo();
		double getAncho();
		bool getEstaOcupado();

		SensorOcupacion^ getSensorOcupacion();
		IndicadorLed^ getIndicadorLed();
		List<Cliente^>^ getListaClientes();




		void setIdEspacio(int idEspacio);
		void setCodigo(String^ codigo);
		void setTipo(TipoEstacionamiento tipo);
		void setLargo(double largo);
		void setAncho(double ancho);
		void setEstaOcupado(bool estaOcupado);

		void setSensorOcupacion(SensorOcupacion^ sensorOcupacion);
		void setIndicadorLed(IndicadorLed^ indicadorLed);
		void setListaClientes(List<Cliente^>^ listaClientes);
	};

}