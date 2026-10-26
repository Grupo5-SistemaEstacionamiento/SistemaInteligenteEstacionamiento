#pragma once

namespace SmartParkingSystemModel {

    using namespace System;

    public ref class BalanceDiario {
    private:
        DateTime fecha;
        double totalSaldoInicialTurnos;
        double totalSaldoFinalTurnos;
        double totalIngresosMovimientos;
        double totalEgresosMovimientos;
        int cantidadTurnos;

    public:
        BalanceDiario();
        BalanceDiario(DateTime fecha, double saldoIni, double saldoFin, double ingresos, double egresos, int turnos);

        DateTime getFecha();
        void setFecha(DateTime fecha);

        double getTotalSaldoInicialTurnos();
        void setTotalSaldoInicialTurnos(double total);

        double getTotalSaldoFinalTurnos();
        void setTotalSaldoFinalTurnos(double total);

        double getTotalIngresosMovimientos();
        void setTotalIngresosMovimientos(double ingresos);

        double getTotalEgresosMovimientos();
        void setTotalEgresosMovimientos(double egresos);

        int getCantidadTurnos();
        void setCantidadTurnos(int cantidad);

        String^ ObtenerResumenFormateado();
    };
}
