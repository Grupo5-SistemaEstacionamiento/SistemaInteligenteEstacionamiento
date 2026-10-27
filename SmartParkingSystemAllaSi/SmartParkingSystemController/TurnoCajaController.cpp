#include "pch.h"

#include "TurnoCajaController.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemModel;

// Constructor.
TurnoCajaController::TurnoCajaController()
{
    listaTurnos = gcnew List<TurnoCaja^>();
    turnoDAO = gcnew TurnoCajaDAO();
}

// Listar turnos.
List<TurnoCaja^>^ TurnoCajaController::buscarTodosArchivo()
{
    return turnoDAO->buscarTodosArchivo();
}

// Buscar por ID.
TurnoCaja^ TurnoCajaController::buscarxIdArchivo(int idTurno)
{
    return turnoDAO->buscarxIdArchivo(idTurno);
}

// Conservar operación original de registro.
void TurnoCajaController::registrarArchivo(TurnoCaja^ turno)
{
    if (turno == nullptr ||
        turno->getEmpleado() == nullptr ||
        String::IsNullOrWhiteSpace(
            turno->getEmpleado()->getCodigoEmpleado()))
    {
        throw gcnew ArgumentException(
            "El turno debe tener un empleado válido.");
    }

    if (turno->getEstado() == "Abierto" &&
        buscarTurnoAbierto() != nullptr)
    {
        throw gcnew InvalidOperationException(
            "Ya existe un turno abierto.");
    }

    turnoDAO->registrarTurnoArchivo(turno);
}

// Modificar registro existente.
void TurnoCajaController::modificarArchivo(TurnoCaja^ turno)
{
    turnoDAO->modificarTurnoArchivo(turno);
}

// Eliminar registro existente.
void TurnoCajaController::eliminarArchivo(int idTurno)
{
    turnoDAO->eliminarTurnoArchivos(idTurno);
}

// Obtener siguiente ID.
int TurnoCajaController::obtenerSiguienteId()
{
    return turnoDAO->obtenerSiguienteId();
}

// Buscar turno abierto.
TurnoCaja^ TurnoCajaController::buscarTurnoAbierto()
{
    return turnoDAO->buscarTurnoAbierto();
}

// Iniciar turno del empleado autenticado.
bool TurnoCajaController::iniciarTurno(
    Empleado^ empleado,
    double saldoInicial)
{
    // Validar empleado.
    if (empleado == nullptr)
        return false;

    if (String::IsNullOrWhiteSpace(
        empleado->getCodigoEmpleado()))
        return false;

    if (!empleado->getEstado())
        return false;

    // Validar saldo.
    if (Double::IsNaN(saldoInicial) ||
        Double::IsInfinity(saldoInicial) ||
        saldoInicial < 0)
        return false;

    // Impedir turnos simultáneos.
    if (buscarTurnoAbierto() != nullptr)
        return false;

    TurnoCaja^ turno = gcnew TurnoCaja(
        obtenerSiguienteId(),
        saldoInicial,
        empleado);

    turnoDAO->registrarTurnoArchivo(turno);

    return true;
}

// Cerrar turno del empleado autenticado.
bool TurnoCajaController::cerrarTurno(
    String^ codigoEmpleado,
    double saldoFinal,
    String^ observacion)
{
    if (String::IsNullOrWhiteSpace(codigoEmpleado))
        return false;

    if (Double::IsNaN(saldoFinal) ||
        Double::IsInfinity(saldoFinal) ||
        saldoFinal < 0)
        return false;

    if (observacion == nullptr)
        observacion = String::Empty;

    if (observacion->Contains("|"))
        return false;

    TurnoCaja^ turno = buscarTurnoAbierto();

    if (turno == nullptr)
        return false;

    Empleado^ empleado = turno->getEmpleado();

    if (empleado == nullptr)
        return false;

    // Solo el empleado asociado puede cerrar su turno.
    if (!String::Equals(
        empleado->getCodigoEmpleado(),
        codigoEmpleado->Trim(),
        StringComparison::OrdinalIgnoreCase))
    {
        return false;
    }

    turno->CerrarTurno(
        saldoFinal,
        observacion->Trim());

    turnoDAO->modificarTurnoArchivo(turno);

    return true;
}
