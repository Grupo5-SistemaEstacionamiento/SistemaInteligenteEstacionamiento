#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemController
{
    public ref class MembresiaController
    {
    private:
        MembresiaDAO^ membresiaDAO;
        ClienteDAO^ clienteDAO;

    public:
        // Constructor.
        MembresiaController();

        // Operaciones existentes del repositorio.
        List<Membresia^>^ listarMembresias();
        Membresia^ buscarMembresia(int idMembresia);

        bool registrarMembresia(
            DateTime fechaInicio,
            DateTime fechaFin,
            double porcentajeDescuento,
            bool activo,
            double precio,
            int tipo
        );

        bool modificarMembresia(
            int idMembresia,
            DateTime fechaInicio,
            DateTime fechaFin,
            double porcentajeDescuento,
            bool activo,
            double precio,
            int tipo
        );

        bool eliminarMembresia(int idMembresia);
        int obtenerSiguienteId();

        // Operaciones para los formularios integrados.
        List<Cliente^>^ listarClientes();
        List<Cliente^>^ buscarClientes(String^ criterio);
        Cliente^ buscarClientePorId(int idCliente);

        List<Membresia^>^ listarMembresiasPorCliente(
            int idCliente
        );

        // Sobrecargas que reciben un objeto Membresia.
        bool registrarMembresia(Membresia^ membresia);
        bool modificarMembresia(Membresia^ membresia);

        // Cancelación sin eliminación física.
        bool cancelarMembresia(int idMembresia);

        Membresia^ buscarMembresiaPorId(int idMembresia);

        bool clienteTieneMembresiaActiva(int idCliente);

        String^ obtenerEstadoMembresia(
            Membresia^ membresia
        );
    };
}
