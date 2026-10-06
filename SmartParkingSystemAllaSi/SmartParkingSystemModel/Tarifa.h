#pragma once

using namespace System;

namespace SmartParkingSystemModel {

    public ref class Tarifa {

    private:
        int idTarifa;
        double valorHora;
        double valorFraccion15min;
        double descuentoMembresia;
        double penalizacionTicketPerdido;

    public:
        // Constructor
        Tarifa();

        // Constructor con parámetros
        Tarifa(int idTarifa,
            double valorHora,
            double valorFraccion15min,
            double descuentoMembresia,
            double penalizacionTicketPerdido);

        // Métodos get
        int getIdTarifa();
        double getValorHora();
        double getValorFraccion15min();
        double getDescuentoMembresia();
        double getPenalizacionTicketPerdido();

        // Métodos set
        void setIdTarifa(int idTarifa);
        void setValorHora(double valorHora);
        void setValorFraccion15min(double valorFraccion15min);
        void setDescuentoMembresia(double descuentoMembresia);
        void setPenalizacionTicketPerdido(double penalizacionTicketPerdido);

        // Métodos de negocio
        double calcularCosto(double horas);
        double calcularDescuento(double monto);
    };
}