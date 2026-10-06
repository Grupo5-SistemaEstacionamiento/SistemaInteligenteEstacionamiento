#include "pch.h"
#include "TarifaController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

// Constructor
TarifaController::TarifaController() {

    tarifaDAO = gcnew TarifaDAO();
}

// Devuelve todas las tarifas registradas.
List<Tarifa^>^ TarifaController::listarTarifas() {

    return tarifaDAO->listarTarifas();
}

// Busca una tarifa mediante su ID.
Tarifa^ TarifaController::buscarTarifa(int idTarifa) {

    if (idTarifa <= 0) {
        return nullptr;
    }

    return tarifaDAO->buscarTarifa(idTarifa);
}

// Registra una nueva tarifa.
bool TarifaController::registrarTarifa(
    double valorHora,
    double valorFraccion15min,
    double descuentoMembresia,
    double penalizacionTicketPerdido) {

    // Verifica que los valores ingresados sean válidos.
    if (!validarTarifa(
        valorHora,
        valorFraccion15min,
        descuentoMembresia,
        penalizacionTicketPerdido)) {

        return false;
    }

    // El ID se genera automáticamente.
    int idTarifa = obtenerSiguienteId();

    Tarifa^ tarifa = gcnew Tarifa(
        idTarifa,
        valorHora,
        valorFraccion15min,
        descuentoMembresia,
        penalizacionTicketPerdido
    );

    return tarifaDAO->registrarTarifa(tarifa);
}

// Modifica una tarifa existente.
bool TarifaController::modificarTarifa(
    int idTarifa,
    double valorHora,
    double valorFraccion15min,
    double descuentoMembresia,
    double penalizacionTicketPerdido) {

    if (idTarifa <= 0) {
        return false;
    }

    // Comprueba que la tarifa exista.
    if (buscarTarifa(idTarifa) == nullptr) {
        return false;
    }

    // Verifica los nuevos valores.
    if (!validarTarifa(
        valorHora,
        valorFraccion15min,
        descuentoMembresia,
        penalizacionTicketPerdido)) {

        return false;
    }

    Tarifa^ tarifa = gcnew Tarifa(
        idTarifa,
        valorHora,
        valorFraccion15min,
        descuentoMembresia,
        penalizacionTicketPerdido
    );

    return tarifaDAO->modificarTarifa(tarifa);
}

// Elimina una tarifa mediante su ID.
bool TarifaController::eliminarTarifa(int idTarifa) {

    if (idTarifa <= 0) {
        return false;
    }

    if (buscarTarifa(idTarifa) == nullptr) {
        return false;
    }

    return tarifaDAO->eliminarTarifa(idTarifa);
}

// Obtiene el siguiente ID disponible.
int TarifaController::obtenerSiguienteId() {

    return tarifaDAO->obtenerSiguienteId();
}

// Valida los valores correspondientes a una tarifa.
bool TarifaController::validarTarifa(
    double valorHora,
    double valorFraccion15min,
    double descuentoMembresia,
    double penalizacionTicketPerdido) {

    // Los precios no pueden ser negativos.
    if (valorHora <= 0) {
        return false;
    }

    if (valorFraccion15min <= 0) {
        return false;
    }

    if (penalizacionTicketPerdido < 0) {
        return false;
    }

    // El descuento debe encontrarse entre 0 % y 100 %.
    if (descuentoMembresia < 0 ||
        descuentoMembresia > 100) {

        return false;
    }

    return true;
}