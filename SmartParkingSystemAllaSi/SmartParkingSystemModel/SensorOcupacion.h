#pragma once
#include "Periferico.h"

namespace SmartParkingSystemModel {

	public ref class SensorOcupacion : public Periferico{

	private:
		double umbralDeteccion;
		double valorLectura;
		bool detectaVehiculo;
		DateTime fechaUltimaLectura;

	public:
		SensorOcupacion();
		SensorOcupacion(
			int idPeriferico,
			String^ ubicacion,
			DateTime fechaInstalacion,
			DateTime fechaUltimoMant,
			EstadoPeriferico estado,
			bool hayEmergencia,
			double umbralDeteccion,
		    double valorLectura,
		    bool detectaVehiculo,
		    DateTime fechaUltimaLectura
		);

		double getUmbralDeteccion();
		double getValorLectura();
		bool getDetectaVehiculo();
		DateTime getFechaUltimaLectura();


		void setUmbralDeteccion(double umbralDeteccion);
		void setValorLectura(double valorLectura);
		void setDetectaVehiculo(bool detectaVehiculo);
		void setFechaUltimaLectura(DateTime fechaUltimaLectura);

	};


}