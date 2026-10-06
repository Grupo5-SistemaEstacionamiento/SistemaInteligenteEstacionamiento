#include "pch.h"
#include "Tarifa.h"

using namespace SmartParkingSystemModel;

// Constructor vacío
Tarifa::Tarifa() {
    idTarifa = 0;
    valorHora = 0.0;
    valorFraccion15min = 0.0;
    descuentoMembresia = 0.0;
    penalizacionTicketPerdido = 0.0;
}

// Constructor con parámetros
Tarifa::Tarifa(int idTarifa,
    double valorHora,
    double valorFraccion15min,
    double descuentoMembresia,
    double penalizacionTicketPerdido) {

    this->idTarifa = idTarifa;
    this->valorHora = valorHora;
    this->valorFraccion15min = valorFraccion15min;
    this->descuentoMembresia = descuentoMembresia;
    this->penalizacionTicketPerdido = penalizacionTicketPerdido;
}

// Métodos get

int Tarifa::getIdTarifa() {
    return idTarifa;
}

double Tarifa::getValorHora() {
    return valorHora;
}

double Tarifa::getValorFraccion15min() {
    return valorFraccion15min;
}

double Tarifa::getDescuentoMembresia() {
    return descuentoMembresia;
}

double Tarifa::getPenalizacionTicketPerdido() {
    return penalizacionTicketPerdido;
}

// Métodos set

void Tarifa::setIdTarifa(int idTarifa) {
    this->idTarifa = idTarifa;
}

void Tarifa::setValorHora(double valorHora) {
    this->valorHora = valorHora;
}

void Tarifa::setValorFraccion15min(double valorFraccion15min) {
    this->valorFraccion15min = valorFraccion15min;
}

void Tarifa::setDescuentoMembresia(double descuentoMembresia) {
    this->descuentoMembresia = descuentoMembresia;
}

void Tarifa::setPenalizacionTicketPerdido(double penalizacionTicketPerdido) {
    this->penalizacionTicketPerdido = penalizacionTicketPerdido;
}

// Calcula el costo según las horas utilizadas
double Tarifa::calcularCosto(double horas) {
    return valorHora * horas;
}

// Calcula el monto correspondiente al descuento
double Tarifa::calcularDescuento(double monto) {
    return monto * (descuentoMembresia / 100.0);
}