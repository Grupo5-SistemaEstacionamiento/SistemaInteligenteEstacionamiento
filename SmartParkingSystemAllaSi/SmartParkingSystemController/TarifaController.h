#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

    public ref class TarifaController {

    private:
        TarifaDAO^ tarifaDAO;

    public:
        // Constructor
        TarifaController();

        // Obtiene todas las tarifas registradas.
        List<Tarifa^>^ listarTarifas();

        // Busca una tarifa mediante su ID.
        Tarifa^ buscarTarifa(int idTarifa);

        // Registra una nueva tarifa.
        bool registrarTarifa(double valorHora,
            double valorFraccion15min,
            double descuentoMembresia,
            double penalizacionTicketPerdido);

        // Modifica una tarifa existente.
        bool modificarTarifa(int idTarifa,
            double valorHora,
            double valorFraccion15min,
            double descuentoMembresia,
            double penalizacionTicketPerdido);

        // Elimina una tarifa mediante su ID.
        bool eliminarTarifa(int idTarifa);

        // Obtiene el siguiente ID disponible.
        int obtenerSiguienteId();

        // Valida los valores de una tarifa.
        bool validarTarifa(double valorHora,
            double valorFraccion15min,
            double descuentoMembresia,
            double penalizacionTicketPerdido);
    };
}