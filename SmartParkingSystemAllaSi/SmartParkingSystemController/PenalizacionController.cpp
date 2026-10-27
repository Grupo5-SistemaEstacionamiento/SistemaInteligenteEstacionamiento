#include "pch.h"

#include "PenalizacionController.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemController;

// Constructor.
PenalizacionController::PenalizacionController()
{
    penalizacionDAO = gcnew PenalizacionDAO();
}

// Lista todas las penalizaciones.
List<Penalizacion^>^
PenalizacionController::listarPenalizaciones()
{
    return penalizacionDAO->listarPenalizaciones();
}

// Busca una penalización por ID.
Penalizacion^ PenalizacionController::buscarPenalizacion(
    int idPenalizacion)
{
    if (idPenalizacion <= 0)
        return nullptr;

    return penalizacionDAO->buscarPenalizacion(
        idPenalizacion);
}

// Busca por placa, admitiendo coincidencias parciales.
List<Penalizacion^>^
PenalizacionController::buscarPorPlaca(String^ placa)
{
    List<Penalizacion^>^ resultados =
        gcnew List<Penalizacion^>();

    String^ criterio =
        String::IsNullOrWhiteSpace(placa)
        ? String::Empty
        : placa->Trim();

    for each (Penalizacion ^ p in listarPenalizaciones())
    {
        String^ placaRegistrada =
            p->getPlacaVehiculo();

        if (String::IsNullOrWhiteSpace(criterio) ||
            (!String::IsNullOrEmpty(placaRegistrada) &&
                placaRegistrada->IndexOf(
                    criterio,
                    StringComparison::OrdinalIgnoreCase) >= 0))
        {
            resultados->Add(p);
        }
    }

    return resultados;
}

// Valida los datos antes de registrar o modificar.
bool PenalizacionController::validarDatos(
    String^ placa,
    int tipo,
    DateTime fechaHora,
    String^ motivo,
    double monto)
{
    if (String::IsNullOrWhiteSpace(placa))
        return false;

    if (placa->Trim()->Length > 15 ||
        placa->Contains("|"))
        return false;

    // Valores actuales de TipoPenalizacion: 0, 1, 2 y 3.
    if (tipo < 0 || tipo > 3)
        return false;

    if (fechaHora == DateTime::MinValue ||
        fechaHora > DateTime::Now)
        return false;

    if (String::IsNullOrWhiteSpace(motivo) ||
        motivo->Contains("|"))
        return false;

    if (Double::IsNaN(monto) ||
        Double::IsInfinity(monto) ||
        monto <= 0)
        return false;

    return true;
}

// Registra una nueva penalización.
bool PenalizacionController::registrarPenalizacion(
    String^ placa,
    int tipo,
    DateTime fechaHora,
    String^ motivo,
    double monto)
{
    if (!validarDatos(
        placa, tipo, fechaHora, motivo, monto))
    {
        return false;
    }

    Penalizacion^ p = gcnew Penalizacion(
        obtenerSiguienteId(),
        (TipoPenalizacion)tipo,
        fechaHora,
        false,
        DateTime::MinValue,
        motivo->Trim(),
        monto,
        nullptr,
        nullptr
    );

    p->setPlacaVehiculo(placa);

    return penalizacionDAO->registrarPenalizacion(p);
}

// Modifica una penalización existente.
bool PenalizacionController::modificarPenalizacion(
    int idPenalizacion,
    String^ placa,
    int tipo,
    DateTime fechaHora,
    String^ motivo,
    double monto,
    bool pagado)
{
    Penalizacion^ anterior =
        buscarPenalizacion(idPenalizacion);

    if (anterior == nullptr)
        return false;

    if (!validarDatos(
        placa, tipo, fechaHora, motivo, monto))
    {
        return false;
    }

    DateTime fechaPago = DateTime::MinValue;

    if (pagado)
    {
        fechaPago = anterior->getPagado()
            ? anterior->getFechaPago()
            : DateTime::Now;
    }

    Penalizacion^ p = gcnew Penalizacion(
        idPenalizacion,
        (TipoPenalizacion)tipo,
        fechaHora,
        pagado,
        fechaPago,
        motivo->Trim(),
        monto,
        anterior->getVehiculo(),
        anterior->getListaMovimientos()
    );

    p->setPlacaVehiculo(placa);

    return penalizacionDAO->modificarPenalizacion(p);
}

// Compatibilidad con el método original de registro.
// La firma antigua no recibe placa.
bool PenalizacionController::registrarPenalizacion(
    DateTime fechaHora,
    int tipo,
    String^ motivo,
    double monto,
    bool pagado)
{
    // No registrar datos incompletos.
    return false;
}

// Compatibilidad con el método original de modificación.
bool PenalizacionController::modificarPenalizacion(
    int idPenalizacion,
    int tipo,
    DateTime fechaHora,
    bool pagado,
    DateTime fechaPago,
    String^ motivo,
    double monto)
{
    Penalizacion^ anterior =
        buscarPenalizacion(idPenalizacion);

    if (anterior == nullptr)
        return false;

    return modificarPenalizacion(
        idPenalizacion,
        anterior->getPlacaVehiculo(),
        tipo,
        fechaHora,
        motivo,
        monto,
        pagado
    );
}

// Elimina una penalización.
bool PenalizacionController::eliminarPenalizacion(
    int idPenalizacion)
{
    if (idPenalizacion <= 0)
        return false;

    if (buscarPenalizacion(idPenalizacion) == nullptr)
        return false;

    return penalizacionDAO->eliminarPenalizacion(
        idPenalizacion);
}

// Genera el siguiente ID.
int PenalizacionController::obtenerSiguienteId()
{
    return penalizacionDAO->obtenerSiguienteId();
}
