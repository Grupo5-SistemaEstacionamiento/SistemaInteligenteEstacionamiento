#pragma once
#include "Periferico.h"

namespace SmartParkingSystemModel {

	public ref class ServoMotor : Periferico {

	private:
		double anguloActual;
		double anguloMaxApertura;
		double torque;

	public:
		ServoMotor();
		ServoMotor(int idPeriferico,
			String^ ubicacion,
			DateTime fechaInstalacion,
			DateTime fechaUltimoMant,
			EstadoPeriferico estado,
			bool hayEmergencia,
		    double anguloActual,
		    double anguloMaxApertura,
		    double torque);

		double getAnguloActual();
		double getAnguloMaxApertura();
		double getTorque();

		void setAnguloActual(double anguloActual);
		void setAnguloMaxApertura(double anguloMaxApertura);
		void setTorque(double torque);



	};

}