#pragma once

namespace SmartParkingSystemController {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SmartParkingSystemModel;
    using namespace SmartParkingSystemDAO;

    public ref class BalancesController {
    public:
        BalancesController();

        // --- GESTIÓN DE TURNOS ---
        static TurnoCaja^ ObtenerTurnoAbiertoActual();
        static bool AbrirTurno(int idTurno, double saldoInicial, Empleado^ empleado);
        static bool CerrarTurnoActual(int idTurno, double saldoFinal, String^ observacion);

        // --- GESTIÓN DE MOVIMIENTOS (Regla: exige caja abierta) ---
        static bool RegistrarMovimientoEnTurnoActual(Movimiento^ mov);

        // --- BALANCES DIARIOS E HISTORIAL ---
        static BalanceDiario^ CalcularBalanceDelDia(DateTime fechaConsultar);
        static BalanceDiario^ BuscarBalancePorFecha(DateTime fecha);
        static void EliminarBalancePorFecha(DateTime fecha);
        static List<BalanceDiario^>^ ObtenerHistorialBalances();
    };
}
