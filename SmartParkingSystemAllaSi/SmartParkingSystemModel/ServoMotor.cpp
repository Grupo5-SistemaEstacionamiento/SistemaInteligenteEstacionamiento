#include "pch.h"
#include "ServoMotor.h"

using namespace CocheraModel;

ServoMotor::ServoMotor() {

}
ServoMotor::ServoMotor(int idPeriferico,
	String^ ubicacion,
	DateTime fechaInstalacion,
	DateTime fechaUltimoMant,
	EstadoPeriferico estado,
	bool hayEmergencia,
	double anguloActual,
	double anguloMaxApertura,
	double torque) {

	this->anguloActual = anguloActual;
	this->anguloMaxApertura = anguloMaxApertura;
	this->torque = torque;

}

double ServoMotor::getAnguloActual() {
	return this->anguloActual;
}
double ServoMotor::getAnguloMaxApertura() {
	return this->anguloMaxApertura;
}
double ServoMotor::getTorque() {
	return this->torque;
}



void ServoMotor::setAnguloActual(double anguloActual) {
	this->anguloActual = anguloActual;
}
void ServoMotor::setAnguloMaxApertura(double anguloMaxApertura) {
	this->anguloMaxApertura = anguloMaxApertura;
}
void ServoMotor::setTorque(double torque) {
	this->torque = torque;
}