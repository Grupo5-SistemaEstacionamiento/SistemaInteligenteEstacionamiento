#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO {

    public ref class TurnoCajaDAO {

    private:
        String^ rutaArchivo;

        void verificarDirectorio();

    public:
        TurnoCajaDAO();

        // Métodos originales.
        List<TurnoCaja^>^ buscarTodosArchivo();
        TurnoCaja^ buscarxIdArchivo(int idTurno);

        void registrarTurnoArchivo(TurnoCaja^ turno);
        void modificarTurnoArchivo(TurnoCaja^ turno);
        void eliminarTurnoArchivos(int idTurno);

        void escribirArchivo(List<TurnoCaja^>^ listaTurnos);

        // Métodos adicionales.
        int obtenerSiguienteId();
        TurnoCaja^ buscarTurnoAbierto();
    };
}
