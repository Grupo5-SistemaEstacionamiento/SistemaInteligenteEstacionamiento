#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

    public ref class TurnoCajaController {

    private:
        List<TurnoCaja^>^ listaTurnos;
        TurnoCajaDAO^ turnoDAO;

    public:
        TurnoCajaController();

        // Métodos originales.
        List<TurnoCaja^>^ buscarTodosArchivo();
        TurnoCaja^ buscarxIdArchivo(int idTurno);
        void registrarArchivo(TurnoCaja^ turno);
        void modificarArchivo(TurnoCaja^ turno);
        void eliminarArchivo(int idTurno);

        // Métodos adicionales.
        int obtenerSiguienteId();
        TurnoCaja^ buscarTurnoAbierto();

        bool iniciarTurno(
            Empleado^ empleado,
            double saldoInicial);

        bool cerrarTurno(
            String^ codigoEmpleado,
            double saldoFinal,
            String^ observacion);
    };
}
