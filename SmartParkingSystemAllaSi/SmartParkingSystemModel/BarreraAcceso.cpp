#include "pch.h"
#include "BarreraAcceso.h"
#include "LectorRFID.h"
#include "SensorOcupacion.h"
#include "ServoMotor.h"
#include "RegistroAcceso.h"

namespace CocheraModel {

	BarreraAcceso::BarreraAcceso() {
		this->listaRegistrosAcceso = gcnew List<RegistroAcceso^>();
	}
	BarreraAcceso::BarreraAcceso(
		bool hayImpedimento,
		bool esEntrada,
		bool estaAbierto,

		LectorRFID^ lectorRFID,
		SensorOcupacion^ sensorOcupacion,
		ServoMotor^ servoMotor,
		List<RegistroAcceso^>^ listaRegistrosAcceso

	) {
		this->hayImpedimento = hayImpedimento;
		this->esEntrada = esEntrada;
		this->estaAbierto = estaAbierto;

		this->lectorRFID = lectorRFID;
		this->sensorOcupacion = sensorOcupacion;
		this->servoMotor = servoMotor;
		this->listaRegistrosAcceso = listaRegistrosAcceso;

	}

	bool BarreraAcceso::getHayImpedimento() {
		return this->hayImpedimento;
	}
	bool BarreraAcceso::getEsEntrada() {
		return this->esEntrada;
	}
	bool BarreraAcceso::getEstaAbierto() {
		return this->estaAbierto;
	}

	LectorRFID^ BarreraAcceso::getLectorRFID() {
		return this->lectorRFID;
	}
	SensorOcupacion^ BarreraAcceso::getSensorOcupacion() {
		return this->sensorOcupacion;
	}
	ServoMotor^ BarreraAcceso::getServoMotor() {
		return this->servoMotor;
	}
	List<RegistroAcceso^>^ BarreraAcceso::getListaRegistrosAcceso() {
		return this->listaRegistrosAcceso;
	}


	void BarreraAcceso::setHayImpedimento(bool hayImpedimento) {
		this->hayImpedimento = hayImpedimento;
	}
	void BarreraAcceso::setEsEntrada(bool esEntrada) {
		this->esEntrada = esEntrada;
	}
	void BarreraAcceso::setEstaAbierto(bool estaAbierto) {
		this->estaAbierto = estaAbierto;
	}
	void BarreraAcceso::setLectorRFID(LectorRFID^ lectorRFID) {
		this->lectorRFID = lectorRFID;
	}
	void BarreraAcceso::setSensorOcupacion(SensorOcupacion^ sensorOcupacion) {
		this->sensorOcupacion = sensorOcupacion;
	}
	void BarreraAcceso::setServoMotor(ServoMotor^ servoMotor) {
		this->servoMotor = servoMotor;
	}
	void BarreraAcceso::setListaRegistrosAcceso(List<RegistroAcceso^>^ listaRegistrosAcceso) {
		this->listaRegistrosAcceso = listaRegistrosAcceso;
	}
}
