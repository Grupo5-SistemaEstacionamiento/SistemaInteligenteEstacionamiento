#include "pch.h"
#include "Vehiculo.h"
#include "Cliente.h"
#include "RegistroAcceso.h"
#include "Penalizacion.h"

using namespace CocheraModel;

Vehiculo::Vehiculo() {
	this->listaRegistros = gcnew List<RegistroAcceso^>();
	this->listaPenlaizaciones = gcnew List<Penalizacion^>();
}
Vehiculo::Vehiculo(
	int idVehiculo,
	String^ placa,
	String^ marca,
	String^ modelo,
	String^ color,
	TipoVehiculo tipo,
	String^ anotaciones,

	Cliente^ cliente,
	List<RegistroAcceso^>^ listaRegistros,
	List<Penalizacion^>^ listaPenlaizaciones
) {
	this->idVehiculo = idVehiculo;
	this->placa = placa;
	this->marca = marca;
	this->modelo = modelo;
	this->color = color;
	this->tipo = tipo;
	this->anotaciones = anotaciones;

	this->cliente = cliente;
	this->listaRegistros = listaRegistros;
	this->listaPenlaizaciones = listaPenlaizaciones;
}


int Vehiculo::getIdVehiculo() {
	return this->idVehiculo;
}
String^ Vehiculo::getPlaca() {
	return this->placa;
}
String^ Vehiculo::getMarca() {
	return this->marca;
}
String^ Vehiculo::getModelo() {
	return this->modelo;
}
String^ Vehiculo::getColor() {
	return this->color;
}
TipoVehiculo Vehiculo::getTipo() {
	return this->tipo;
}
String^ Vehiculo::getAnotaciones() {
	return this->anotaciones;
}
Cliente^ Vehiculo::getCliente() {
	return this->cliente;
}
List<RegistroAcceso^>^ Vehiculo::getListaRegistros() {
	return this->listaRegistros;
}
List<Penalizacion^>^ Vehiculo::getListaPenlaizaciones() {
	return this->listaPenlaizaciones;
}



void Vehiculo::setIdVehiculo(int idVehiculo) {
	this->idVehiculo = idVehiculo;
}
void Vehiculo::setPlaca(String^ placa) {
	this->placa = placa;
}
void Vehiculo::setMarca(String^ marca) {
	this->marca = marca;
}
void Vehiculo::setModelo(String^ modelo) {
	this->modelo = modelo;
}
void Vehiculo::setColor(String^ color) {
	this->color = color;
}
void Vehiculo::setTipo(TipoVehiculo tipo) {
	this->tipo = tipo;
}
void Vehiculo::setAnotaciones(String^ anotaciones) {
	this->anotaciones = anotaciones;
}
void Vehiculo::setCliente(Cliente^ cliente) {
	this->cliente = cliente;
}
void Vehiculo::setListaRegistros(List<RegistroAcceso^>^ listaRegistros) {
	this->listaRegistros = listaRegistros;
}
void Vehiculo::setListaPenlaizaciones(List<Penalizacion^>^ listaPenlaizaciones) {
	this->listaPenlaizaciones = listaPenlaizaciones;
}