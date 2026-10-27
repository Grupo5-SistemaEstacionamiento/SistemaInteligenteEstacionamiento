#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO
{
    public ref class MembresiaDAO
    {
    private:
        String^ rutaArchivo;

        // Verifica la existencia del directorio.
        void verificarDirectorio();

        // Guarda todas las membresías.
        bool guardarMembresias(
            List<Membresia^>^ membresias
        );

    public:
        // Constructor.
        MembresiaDAO();

        // Métodos existentes del repositorio.
        List<Membresia^>^ listarMembresias();
        Membresia^ buscarMembresia(int idMembresia);
        bool registrarMembresia(Membresia^ membresia);
        bool modificarMembresia(Membresia^ membresia);
        bool eliminarMembresia(int idMembresia);
        int obtenerSiguienteId();

        // Métodos compatibles con los formularios.
        List<Membresia^>^ listarPorCliente(int idCliente);
        Membresia^ buscarPorId(int idMembresia);

        // Cancelación lógica: conserva el historial.
        bool cancelarMembresia(int idMembresia);
    };
}
