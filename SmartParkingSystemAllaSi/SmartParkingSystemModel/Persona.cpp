#include "pch.h"
#include "Persona.h"

using namespace SmartParkingSystemModel;

Persona::Persona() {

}
Persona::Persona(
	int idPersona,
	String^ nombres,
	String^ apellidos,
	String^ documento,
	String^ telefono,
	String^ correo,
	DateTime fechaRegistro,
	bool estado
) {
	this->idPersona = idPersona;
	this->nombres = nombres;
	this->apellidos = apellidos;
	this->documento = documento;
	this->telefono = telefono;
	this->correo = correo;
	this->fechaRegistro = fechaRegistro;
	this->estado = estado;

}

/*geters*/
int Persona::getIdPersona() {
	return this->idPersona;
}
String^ Persona::getNombres() {
	return this->nombres;
}
String^ Persona::getApellidos() {
	return this->apellidos;
}
String^ Persona::getDocumento() {
	return this->documento;
}
String^ Persona::getTelefono() {
	return this->telefono;
}
String^ Persona::getCorreo() {
	return this->correo;
}
DateTime Persona::getFechaRegistro() {
	return this->fechaRegistro;
}
bool Persona::getEstado() {
	return this->estado;
}

/*seters*/
void Persona::setIdPersona(int idPersona) {
	this->idPersona = idPersona;
}
void Persona::setNombres(String^ nombres) {
	this->nombres = nombres;
}
void Persona::setNpellidos(String^ apellidos) {
	this->apellidos = apellidos;
}
void Persona::setDocumento(String^ documento) {
	this->documento = documento;
}
void Persona::setTelefono(String^ telefono) {
	this->telefono = telefono;
}
void Persona::setCorreo(String^ correo) {
	this->correo = correo;
}
void Persona::setFechaRegistro(DateTime fechaRegistro) {
	this->fechaRegistro = fechaRegistro;
}
void Persona::setEstado(bool estado) {
	this->estado = estado;
}