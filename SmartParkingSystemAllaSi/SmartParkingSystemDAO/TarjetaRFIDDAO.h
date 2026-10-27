#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO
{
    public ref class TarjetaRFIDDAO
    {
    private:
        String^ rutaArchivo;

        // Verifica el directorio de persistencia.
        void verificarDirectorio();

        // Reescribe las tarjetas registradas.
        bool guardarTarjetas(
            List<TarjetaRFID^>^ tarjetas
        );

    public:
        // Constructor.
        TarjetaRFIDDAO();

        // Métodos del repositorio clonado.
        List<TarjetaRFID^>^ listarTarjetas();
        TarjetaRFID^ buscarTarjeta(int idTarjeta);
        bool registrarTarjeta(TarjetaRFID^ tarjeta);
        bool modificarTarjeta(TarjetaRFID^ tarjeta);
        bool eliminarTarjeta(int idTarjeta);
        int obtenerSiguienteId();

        // Métodos compatibles con el proyecto original.
        TarjetaRFID^ buscarPorId(int idTarjeta);
        TarjetaRFID^ buscarPorUID(String^ codigoUID);
        bool desactivarTarjeta(int idTarjeta);
    };
}
