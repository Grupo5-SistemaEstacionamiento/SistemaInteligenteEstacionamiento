#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController
{
    public ref class TarjetaRFIDController
    {
    private:
        TarjetaRFIDDAO^ tarjetaDAO;
        ClienteDAO^ clienteDAO;

    public:
        // Constructor.
        TarjetaRFIDController();

        // Métodos originales del repositorio clonado.
        List<TarjetaRFID^>^ listarTarjetas();
        TarjetaRFID^ buscarTarjeta(int idTarjeta);

        bool registrarTarjeta(
            String^ codigoUID,
            DateTime fechaEmision,
            DateTime fechaVencimiento,
            bool activa
        );

        bool modificarTarjeta(
            int idTarjeta,
            String^ codigoUID,
            DateTime fechaEmision,
            DateTime fechaVencimiento,
            bool activa
        );

        bool eliminarTarjeta(int idTarjeta);

        int obtenerSiguienteId();

        // Métodos compatibles con los formularios integrados.
        TarjetaRFID^ buscarPorId(int idTarjeta);
        TarjetaRFID^ buscarPorUID(String^ codigoUID);

        bool registrarTarjeta(
            int idCliente,
            String^ codigoUID,
            DateTime fechaVencimiento
        );

        bool modificarTarjeta(
            int idTarjeta,
            String^ codigoUID,
            DateTime fechaVencimiento
        );

        bool clienteTieneTarjetaActiva(
            int idCliente,
            int idTarjetaExcluir
        );

        bool desactivarTarjeta(int idTarjeta);
    };
}
