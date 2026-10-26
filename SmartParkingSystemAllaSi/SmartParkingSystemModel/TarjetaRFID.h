#pragma once

namespace SmartParkingSystemModel
{
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Cliente;
    ref class LectorRFID;

    public ref class TarjetaRFID
    {
    private:
        int idTarjeta;
        int idCliente;

        String^ codigoUID;
        DateTime fechaEmision;
        DateTime fechaVencimiento;
        DateTime ultimoUso;
        bool activa;

        // Relaciones originales del repositorio clonado.
        List<LectorRFID^>^ listaLecturas;
        Cliente^ cliente;

    public:
        // Constructor por defecto.
        TarjetaRFID();

        // Constructor original del repositorio clonado.
        TarjetaRFID(
            int idTarjeta,
            String^ codigoUID,
            DateTime fechaEmision,
            DateTime fechaVencimiento,
            bool activa,
            List<LectorRFID^>^ listaLecturas,
            Cliente^ cliente
        );

        // Constructor del módulo integrado.
        TarjetaRFID(
            String^ codigoUID,
            DateTime fechaVencimiento
        );

        // Getters.
        int getIdTarjeta();
        int getIdCliente();
        String^ getCodigoUID();
        DateTime getFechaEmision();
        DateTime getFechaVencimiento();
        DateTime getUltimoUso();
        bool getActiva();

        List<LectorRFID^>^ getListaLecturas();
        Cliente^ getCliente();

        // Setters.
        void setIdTarjeta(int idTarjeta);
        void setIdCliente(int idCliente);
        void setCodigoUID(String^ codigoUID);
        void setFechaEmision(DateTime fechaEmision);
        void setFechaVencimiento(DateTime fechaVencimiento);
        void setUltimoUso(DateTime ultimoUso);
        void setActiva(bool activa);

        void setListaLecturas(
            List<LectorRFID^>^ listaLecturas
        );

        void setCliente(Cliente^ cliente);

        // Operaciones adicionales.
        bool estaActiva();
        bool estaVigente();
        void registrarUso();
        void desactivar();
    };
}
