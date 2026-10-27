#include "pch.h"

#include "TarjetaRFIDController.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemController;

// Constructor.
TarjetaRFIDController::TarjetaRFIDController()
{
    tarjetaDAO = gcnew TarjetaRFIDDAO();
    clienteDAO = gcnew ClienteDAO();
}

// =====================================================
// MÉTODOS EXISTENTES DEL REPOSITORIO CLONADO
// =====================================================

// Lista todas las tarjetas RFID.
List<TarjetaRFID^>^
TarjetaRFIDController::listarTarjetas()
{
    return tarjetaDAO->listarTarjetas();
}

// Busca una tarjeta por ID.
TarjetaRFID^ TarjetaRFIDController::buscarTarjeta(
    int idTarjeta)
{
    if (idTarjeta <= 0)
        return nullptr;

    return tarjetaDAO->buscarTarjeta(idTarjeta);
}

// Registro utilizado por el repositorio clonado.
bool TarjetaRFIDController::registrarTarjeta(
    String^ codigoUID,
    DateTime fechaEmision,
    DateTime fechaVencimiento,
    bool activa)
{
    if (String::IsNullOrWhiteSpace(codigoUID))
        return false;

    if (fechaVencimiento <= fechaEmision)
        return false;

    codigoUID = codigoUID->Trim();

    if (tarjetaDAO->buscarPorUID(codigoUID) != nullptr)
        return false;

    int idTarjeta = obtenerSiguienteId();

    TarjetaRFID^ tarjeta = gcnew TarjetaRFID(
        idTarjeta,
        codigoUID,
        fechaEmision,
        fechaVencimiento,
        activa,
        nullptr,
        nullptr
    );

    return tarjetaDAO->registrarTarjeta(tarjeta);
}

// Modificación utilizada por el repositorio clonado.
bool TarjetaRFIDController::modificarTarjeta(
    int idTarjeta,
    String^ codigoUID,
    DateTime fechaEmision,
    DateTime fechaVencimiento,
    bool activa)
{
    if (idTarjeta <= 0 ||
        String::IsNullOrWhiteSpace(codigoUID))
        return false;

    if (fechaVencimiento <= fechaEmision)
        return false;

    TarjetaRFID^ tarjeta = buscarTarjeta(idTarjeta);

    if (tarjeta == nullptr)
        return false;

    codigoUID = codigoUID->Trim();

    TarjetaRFID^ existente =
        tarjetaDAO->buscarPorUID(codigoUID);

    if (existente != nullptr &&
        existente->getIdTarjeta() != idTarjeta)
        return false;

    // Modifica los campos editables.
    tarjeta->setCodigoUID(codigoUID);
    tarjeta->setFechaEmision(fechaEmision);
    tarjeta->setFechaVencimiento(fechaVencimiento);
    tarjeta->setActiva(activa);

    return tarjetaDAO->modificarTarjeta(tarjeta);
}

// Eliminación física original del repositorio.
bool TarjetaRFIDController::eliminarTarjeta(
    int idTarjeta)
{
    if (idTarjeta <= 0)
        return false;

    if (buscarTarjeta(idTarjeta) == nullptr)
        return false;

    return tarjetaDAO->eliminarTarjeta(idTarjeta);
}

// Genera el siguiente identificador.
int TarjetaRFIDController::obtenerSiguienteId()
{
    return tarjetaDAO->obtenerSiguienteId();
}

// =====================================================
// MÉTODOS PARA LOS FORMULARIOS INTEGRADOS
// =====================================================

// Busca una tarjeta mediante su identificador.
TarjetaRFID^ TarjetaRFIDController::buscarPorId(
    int idTarjeta)
{
    return buscarTarjeta(idTarjeta);
}

// Busca una tarjeta mediante su UID.
TarjetaRFID^ TarjetaRFIDController::buscarPorUID(
    String^ codigoUID)
{
    if (String::IsNullOrWhiteSpace(codigoUID))
        return nullptr;

    return tarjetaDAO->buscarPorUID(codigoUID->Trim());
}

// Registra una tarjeta asociada a un cliente.
bool TarjetaRFIDController::registrarTarjeta(
    int idCliente,
    String^ codigoUID,
    DateTime fechaVencimiento)
{
    if (idCliente <= 0)
        return false;

    // Comprueba que el cliente exista.
    Cliente^ cliente =
        clienteDAO->buscarxIdArchivo(idCliente);

    if (cliente == nullptr)
        return false;

    // Solo se permite una tarjeta activa por cliente.
    if (clienteTieneTarjetaActiva(idCliente, 0))
        return false;

    if (String::IsNullOrWhiteSpace(codigoUID))
        return false;

    codigoUID = codigoUID->Trim();

    if (codigoUID->Contains("|"))
        return false;

    if (fechaVencimiento.Date <= DateTime::Today)
        return false;

    // No permite códigos UID duplicados.
    if (tarjetaDAO->buscarPorUID(codigoUID) != nullptr)
        return false;

    int idTarjeta = obtenerSiguienteId();

    TarjetaRFID^ tarjeta = gcnew TarjetaRFID(
        codigoUID,
        fechaVencimiento
    );

    tarjeta->setIdTarjeta(idTarjeta);
    tarjeta->setCliente(cliente);

    return tarjetaDAO->registrarTarjeta(tarjeta);
}

// Modifica el UID y vencimiento de una tarjeta.
bool TarjetaRFIDController::modificarTarjeta(
    int idTarjeta,
    String^ codigoUID,
    DateTime fechaVencimiento)
{
    if (idTarjeta <= 0)
        return false;

    if (String::IsNullOrWhiteSpace(codigoUID))
        return false;

    codigoUID = codigoUID->Trim();

    if (codigoUID->Contains("|"))
        return false;

    if (fechaVencimiento.Date <= DateTime::Today)
        return false;

    TarjetaRFID^ tarjeta =
        tarjetaDAO->buscarPorId(idTarjeta);

    if (tarjeta == nullptr)
        return false;

    // Una tarjeta desactivada queda como historial.
    if (!tarjeta->estaActiva())
        return false;

    TarjetaRFID^ mismoUID =
        tarjetaDAO->buscarPorUID(codigoUID);

    if (mismoUID != nullptr &&
        mismoUID->getIdTarjeta() != idTarjeta)
        return false;

    // No se cambia el cliente asociado.
    tarjeta->setCodigoUID(codigoUID);
    tarjeta->setFechaVencimiento(fechaVencimiento);

    return tarjetaDAO->modificarTarjeta(tarjeta);
}

// Comprueba si un cliente posee una tarjeta activa.
bool TarjetaRFIDController::clienteTieneTarjetaActiva(
    int idCliente,
    int idTarjetaExcluir)
{
    if (idCliente <= 0)
        return false;

    List<TarjetaRFID^>^ tarjetas =
        tarjetaDAO->listarTarjetas();

    for each (TarjetaRFID ^ tarjeta in tarjetas)
    {
        if (tarjeta->getIdTarjeta() == idTarjetaExcluir)
            continue;

        if (tarjeta->getIdCliente() == idCliente &&
            tarjeta->estaActiva())
        {
            return true;
        }
    }

    return false;
}

// Desactiva una tarjeta conservando el historial.
bool TarjetaRFIDController::desactivarTarjeta(
    int idTarjeta)
{
    if (idTarjeta <= 0)
        return false;

    TarjetaRFID^ tarjeta =
        tarjetaDAO->buscarPorId(idTarjeta);

    if (tarjeta == nullptr)
        return false;

    if (!tarjeta->estaActiva())
        return false;

    return tarjetaDAO->desactivarTarjeta(idTarjeta);
}
