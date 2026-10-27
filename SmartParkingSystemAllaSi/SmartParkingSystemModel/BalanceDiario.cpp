#include "pch.h"
#include "BalanceDiario.h"

namespace SmartParkingSystemModel {

    BalanceDiario::BalanceDiario() {
        this->fecha = DateTime::Today;
        this->totalSaldoInicialTurnos = 0.0;
        this->totalSaldoFinalTurnos = 0.0;
        this->totalIngresosMovimientos = 0.0;
        this->totalEgresosMovimientos = 0.0;
        this->cantidadTurnos = 0;
    }

    BalanceDiario::BalanceDiario(DateTime fecha, double saldoIni, double saldoFin, double ingresos, double egresos, int turnos) {
        this->fecha = fecha.Date;
        this->totalSaldoInicialTurnos = saldoIni;
        this->totalSaldoFinalTurnos = saldoFin;
        this->totalIngresosMovimientos = ingresos;
        this->totalEgresosMovimientos = egresos;
        this->cantidadTurnos = turnos;
    }

    DateTime BalanceDiario::getFecha() { return fecha; }
    void BalanceDiario::setFecha(DateTime fecha) { this->fecha = fecha; }

    double BalanceDiario::getTotalSaldoInicialTurnos() { return totalSaldoInicialTurnos; }
    void BalanceDiario::setTotalSaldoInicialTurnos(double total) { this->totalSaldoInicialTurnos = total; }

    double BalanceDiario::getTotalSaldoFinalTurnos() { return totalSaldoFinalTurnos; }
    void BalanceDiario::setTotalSaldoFinalTurnos(double total) { this->totalSaldoFinalTurnos = total; }

    double BalanceDiario::getTotalIngresosMovimientos() { return totalIngresosMovimientos; }
    void BalanceDiario::setTotalIngresosMovimientos(double ingresos) { this->totalIngresosMovimientos = ingresos; }

    double BalanceDiario::getTotalEgresosMovimientos() { return totalEgresosMovimientos; }
    void BalanceDiario::setTotalEgresosMovimientos(double egresos) { this->totalEgresosMovimientos = egresos; }

    int BalanceDiario::getCantidadTurnos() { return cantidadTurnos; }
    void BalanceDiario::setCantidadTurnos(int cantidad) { this->cantidadTurnos = cantidad; }

    String^ BalanceDiario::ObtenerResumenFormateado() {
        return String::Format("Fecha: {0:dd/MM/yyyy} | Turnos: {1} | Ingresos: S/. {2:F2} | Egresos: S/. {3:F2}",
            fecha, cantidadTurnos, totalIngresosMovimientos, totalEgresosMovimientos);
    }
}