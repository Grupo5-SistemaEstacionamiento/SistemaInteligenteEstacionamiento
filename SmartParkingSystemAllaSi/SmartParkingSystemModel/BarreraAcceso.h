#pragma once
#include "Periferico.h"

namespace SmartParkingSystemModel {

	ref class LectorRFID;
	ref class SensorOcupacion;
	ref class ServoMotor;
	ref class RegistroAcceso;
	using namespace System::Collections::Generic;

	public ref class BarreraAcceso : public Periferico { //creamos la herencia

	private:
		bool hayImpedimento;
		bool esEntrada;
		bool estaAbierto;

		LectorRFID^ lectorRFID;
		SensorOcupacion^ sensorOcupacion;
		ServoMotor^ servoMotor;
		List<RegistroAcceso^>^ listaRegistrosAcceso;

	public:
		BarreraAcceso();
		BarreraAcceso(
			bool hayImpedimento,
			bool esEntrada,
			bool estaAbierto,
			LectorRFID^ lectorRFID,
			SensorOcupacion^ sensorOcupacion,
			ServoMotor^ servoMotor,
			List<RegistroAcceso^>^ listaRegistrosAcceso
		);

		bool getHayImpedimento();
		bool getEsEntrada();
		bool getEstaAbierto();

		LectorRFID^ getLectorRFID();
		SensorOcupacion^ getSensorOcupacion();
		ServoMotor^ getServoMotor();
		List<RegistroAcceso^>^ getListaRegistrosAcceso();

		void setHayImpedimento(bool hayImpedimento);
		void setEsEntrada(bool esEntrada);
		void setEstaAbierto(bool estaAbierto);

		void setLectorRFID(LectorRFID^ lectorRFID);
		void setSensorOcupacion(SensorOcupacion^ sensorOcupacion);
		void setServoMotor(ServoMotor^ servoMotor);
		void setListaRegistrosAcceso(List<RegistroAcceso^>^ listaRegistrosAcceso);



	};

}
