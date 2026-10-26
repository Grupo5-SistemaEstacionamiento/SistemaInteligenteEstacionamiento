
#pragma once

namespace SmartParkingSystemModel
{
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Movimiento;
    ref class Cliente;

    // Se conserva el enumerado del repositorio clonado.
    public enum class TipoMembresia
    {
        Regular,
        Premium
    };

    public ref class Membresia
    {
    private:
        int idMembresia;
        int idCliente;

        DateTime fechaInicio;
        DateTime fechaFin;
        double porcentajeDescuento;
        bool activo;
        double precio;
        TipoMembresia tipo;

        // Relaciones existentes del proyecto clonado.
        List<Movimiento^>^ listaMovimientos;
        Cliente^ cliente;

    public:
        // Constructor por defecto.
        Membresia();

        // Constructor original del repositorio clonado.
        Membresia(
            int idMembresia,
            DateTime fechaInicio,
            DateTime fechaFin,
            double porcentajeDescuento,
            bool activo,
            double precio,
            TipoMembresia tipo,
            List<Movimiento^>^ listaMovimientos,
            Cliente^ cliente
        );

        // Constructor compatible con los formularios integrados.
        Membresia(
            int idMembresia,
            int idCliente,
            DateTime fechaInicio,
            DateTime fechaFin,
            double porcentajeDescuento,
            bool activo,
            double precio,
            TipoMembresia tipo
        );

        // Getters.
        int getIdMembresia();
        int getIdCliente();
        DateTime getFechaInicio();
        DateTime getFechaFin();
        double getPorcentajeDescuento();
        bool getActivo();
        double getPrecio();
        TipoMembresia getTipo();
        List<Movimiento^>^ getListaMovimientos();
        Cliente^ getCliente();

        // Setters.
        void setIdMembresia(int idMembresia);
        void setIdCliente(int idCliente);
        void setFechaInicio(DateTime fechaInicio);
        void setFechaFin(DateTime fechaFin);
        void setPorcentajeDescuento(double porcentajeDescuento);
        void setActivo(bool activo);
        void setPrecio(double precio);
        void setTipo(TipoMembresia tipo);
        void setListaMovimientos(List<Movimiento^>^ listaMovimientos);
        void setCliente(Cliente^ cliente);

        // Operaciones de la membresía.
        void activar();
        void desactivar();
        void renovarMembresia(DateTime nuevaFechaFin);
    };
}
