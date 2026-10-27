#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController {

    public ref class PenalizacionController {

    private:
        PenalizacionDAO^ penalizacionDAO;

        bool validarDatos(
            String^ placa,
            int tipo,
            DateTime fechaHora,
            String^ motivo,
            double monto);

    public:
        PenalizacionController();

        List<Penalizacion^>^ listarPenalizaciones();

        Penalizacion^ buscarPenalizacion(
            int idPenalizacion);

        List<Penalizacion^>^ buscarPorPlaca(
            String^ placa);

        int obtenerSiguienteId();

        // Métodos originales del repositorio.
        bool registrarPenalizacion(
            DateTime fechaHora,
            int tipo,
            String^ motivo,
            double monto,
            bool pagado);

        bool modificarPenalizacion(
            int idPenalizacion,
            int tipo,
            DateTime fechaHora,
            bool pagado,
            DateTime fechaPago,
            String^ motivo,
            double monto);

        // Nuevos métodos con placa.
        bool registrarPenalizacion(
            String^ placa,
            int tipo,
            DateTime fechaHora,
            String^ motivo,
            double monto);

        bool modificarPenalizacion(
            int idPenalizacion,
            String^ placa,
            int tipo,
            DateTime fechaHora,
            String^ motivo,
            double monto,
            bool pagado);

        bool eliminarPenalizacion(
            int idPenalizacion);
    };
}
