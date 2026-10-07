#pragma once
#include "Periferico.h"

namespace SmartParkingSystemModel {

	using namespace System;
	public ref class IndicdorLed : Periferico {

	private:
		String^ color;
		int intesidad;
		bool estaEncendido;
		String^ tipoLuz;
		String^ modoOperacion;

	public:
		IndicdorLed();
		IndicdorLed(int idPeriferico,
			String^ ubicacion,
			DateTime fechaInstalacion,
			DateTime fechaUltimoMant,
			EstadoPeriferico estado,
			bool hayEmergencia,
			String^ color,
		int intesidad,
		bool estaEncendido,
		String^ tipoLuz,
		String^ modoOperacion);

		String^ getColor();
		int getIntesidad();
		bool getEstaEncendido();
		String^ getTipoLuz();
		String^ getModoOperacion();

		void setColor(String^ color);
		void setIntesidad(int intesidad);
		void setEstaEncendido(bool estaEncendido);
		void setTipoLuz(String^ tipoLuz);
		void setModoOperacion(String^ modoOperacion);

	};


}