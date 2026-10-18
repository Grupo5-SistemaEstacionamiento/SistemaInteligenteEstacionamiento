#pragma once
#include"Periferico.h"
namespace SmartParkingSystemModel {
	public ref class LectorRFID : public Periferico {

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

		virtual String^ getTipoString() override {
			return "Lector RFID";
		}

		virtual String^ getDetallesResumen() override {
			return "Frecuencia de Operación: " + this->frecOperacion.ToString() + " Hz | Dist. Máx.: " + this->distanciaLecturaMax.ToString() + " cm | Protocolo: " + this->protocoloComunicacion + " | Potencia: " + this->potenciaTransmicion + " W | Rol: " + (this->esLecturaEntrada ? "Entrada" : "Salida");
		}
	};

}