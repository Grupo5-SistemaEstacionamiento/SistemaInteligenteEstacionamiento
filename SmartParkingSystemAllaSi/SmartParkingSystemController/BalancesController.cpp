#include "pch.h"
#include "BalancesController.h"
#include "TurnoCajaController.h"
#include "MovimientoController.h"

namespace SmartParkingSystemController {

    BalancesController::BalancesController() {
    }

    // Devuelve el turno activo actual, o nullptr si no hay ninguno abierto
    TurnoCaja^ BalancesController::ObtenerTurnoAbiertoActual() {
        TurnoCajaController^ ctrl = gcnew TurnoCajaController();
        List<TurnoCaja^>^ turnos = ctrl->buscarTodosArchivo();
        for each (TurnoCaja ^ t in turnos) {
            if (t->getEstado() == "Abierto") {
                return t;
            }
        }
        return nullptr;
    }

    // Abre un nuevo turno validando que no exista otro abierto
    bool BalancesController::AbrirTurno(int idTurno, double saldoInicial, Empleado^ empleado) {
        if (ObtenerTurnoAbiertoActual() != nullptr) {
            throw gcnew Exception("No se puede abrir un nuevo turno porque ya existe una caja abierta.");
        }

        // Usa el constructor rápido que agregamos al modelo TurnoCaja
        TurnoCaja^ nuevo = gcnew TurnoCaja(idTurno, saldoInicial, empleado);
        TurnoCajaController^ ctrl = gcnew TurnoCajaController();
        ctrl->registrarArchivo(nuevo);
        return true;
    }

    // Cierra el turno actual y genera/actualiza su balance histórico automáticamente
    bool BalancesController::CerrarTurnoActual(int idTurno, double saldoFinal, String^ observacion) {
        TurnoCaja^ turnoAbierto = ObtenerTurnoAbiertoActual();

        if (turnoAbierto == nullptr) {
            throw gcnew Exception("Acción denegada: No hay ningún turno abierto para cerrar.");
        }

        if (turnoAbierto->getIdTurno() != idTurno) {
            throw gcnew Exception("El ID del turno a cerrar no coincide con el turno actualmente abierto.");
        }

        // Método de cierre formal en el modelo TurnoCaja
        turnoAbierto->CerrarTurno(saldoFinal, observacion);

        TurnoCajaController^ ctrl = gcnew TurnoCajaController();
        ctrl->modificarArchivo(turnoAbierto);

        // Al cerrar el turno, calculamos el consolidado del día y lo guardamos en el historial persistente
        BalanceDiario^ balanceDelDia = CalcularBalanceDelDia(turnoAbierto->getFechaHoraIngreso());
        BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
        balanceDao->registrarBalanceArchivo(balanceDelDia);

        return true;
    }

    // Registra un movimiento garantizando que obligatoriamente exista una caja abierta
    bool BalancesController::RegistrarMovimientoEnTurnoActual(Movimiento^ mov) {
        TurnoCaja^ turnoAbierto = ObtenerTurnoAbiertoActual();

        if (turnoAbierto == nullptr) {
            throw gcnew Exception("Acción denegada: No se puede registrar un movimiento si no hay una caja/turno activo.");
        }

        // Guardamos el movimiento mediante su controlador existente
        MovimientoController^ movCtrl = gcnew MovimientoController();
        movCtrl->registrarArchivo(mov);

        // Lo vinculamos a la lista del turno abierto y actualizamos
        if (turnoAbierto->getListaMovimientos() == nullptr) {
            turnoAbierto->setListaMovimientos(gcnew List<Movimiento^>());
        }
        turnoAbierto->getListaMovimientos()->Add(mov);

        TurnoCajaController^ turnoCtrl = gcnew TurnoCajaController();
        turnoCtrl->modificarArchivo(turnoAbierto);

        return true;
    }

    // Calcula el balance consolidado del día agrupando todos los turnos transcurridos en esa fecha
    BalanceDiario^ BalancesController::CalcularBalanceDelDia(DateTime fechaConsultar) {
        double saldoIniTotal = 0.0;
        double saldoFinTotal = 0.0;
        double ingresosTotal = 0.0;
        double egresosTotal = 0.0;
        int turnosCount = 0;

        TurnoCajaController^ ctrlTurno = gcnew TurnoCajaController();
        List<TurnoCaja^>^ turnos = ctrlTurno->buscarTodosArchivo();

        for each (TurnoCaja ^ turno in turnos) {
            if (turno->getFechaHoraIngreso().Date == fechaConsultar.Date) {
                turnosCount++;
                saldoIniTotal += turno->getSaldoInicial();

                if (turno->getEstado() == "Cerrado") {
                    saldoFinTotal += turno->getSaldoFinal();
                }

                if (turno->getListaMovimientos() != nullptr) {
                    for each (Movimiento ^ mov in turno->getListaMovimientos()) {
                        if (!mov->getAnulada()) {
                            if (mov->getTipoMovimiento() == "Ingreso") {
                                ingresosTotal += mov->getMonto();
                            }
                            else if (mov->getTipoMovimiento() == "Egreso") {
                                egresosTotal += mov->getMonto();
                            }
                        }
                    }
                }
            }
        }

        return gcnew BalanceDiario(fechaConsultar, saldoIniTotal, saldoFinTotal, ingresosTotal, egresosTotal, turnosCount);
    }

    // Buscar balance histórico por fecha
    BalanceDiario^ BalancesController::BuscarBalancePorFecha(DateTime fecha) {
        BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
        return balanceDao->buscarPorFechaArchivo(fecha);
    }

    // Eliminar balance histórico por fecha
    void BalancesController::EliminarBalancePorFecha(DateTime fecha) {
        BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
        balanceDao->eliminarBalanceArchivo(fecha);
    }

    // Obtener la lista completa del historial de balances registrados
    List<BalanceDiario^>^ BalancesController::ObtenerHistorialBalances() {
        BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
        return balanceDao->buscarTodosArchivo();
    }
}