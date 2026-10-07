#pragma once
#include"Periferico.h"

namespace SmartParkingSystemModel {
	public ref class LectorRFID : Periferico {

	private:

		    double frecOperacion;
			double distanciaLecturaMax;
			String^ idUltimaTarjeta;
			String^ protocoloComunicacion;
			bool esLecturaEntrada;
			double potenciaTransmicion;

	public:
		LectorRFID();
		LectorRFID(int idPeriferico,
			String^ ubicacion,
			DateTime fechaInstalacion,
			DateTime fechaUltimoMant,
			EstadoPeriferico estado,
			bool hayEmergencia,
		double frecOperacion,
		double distanciaLecturaMax,
		String^ idUltimaTarjeta,
		String^ protocoloComunicacion,
		bool esLecturaEntrada,
		double potenciaTransmicion );

		double getFrecOperacion();
		double getDistanciaLecturaMax();
		String^ getIdUltimaTarjeta();
		String^ getProtocoloComunicacion();
		bool getEsLecturaEntrada();
		double getPotenciaTransmicion();

		void setFrecOperacion(double frecOperacion);
		void setDistanciaLecturaMax(double distanciaLecturaMax);
		void setIdUltimaTarjeta(String^ idUltimaTarjeta);
		void setProtocoloComunicacion(String^ protocoloComunicacion);
		void setEsLecturaEntrada(bool esLecturaEntrada);
		void setPotenciaTransmicion(double potenciaTransmicion);
	};

}