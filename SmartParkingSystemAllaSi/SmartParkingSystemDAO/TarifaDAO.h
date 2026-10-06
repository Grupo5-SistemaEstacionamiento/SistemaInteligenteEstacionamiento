#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemDAO {

    public ref class TarifaDAO {

    private:
        String^ rutaArchivo;

        // Crea la carpeta de datos si todavía no existe.
        void verificarDirectorio();
        bool guardarTarifas(List<Tarifa^>^ tarifas);

    public:
        // Constructor
        TarifaDAO();

        // Recupera todas las tarifas almacenadas.
        List<Tarifa^>^ listarTarifas();

        // Busca una tarifa por su ID.
        Tarifa^ buscarTarifa(int idTarifa);

        // Guarda una nueva tarifa.
        bool registrarTarifa(Tarifa^ tarifa);

        // Actualiza una tarifa existente.
        bool modificarTarifa(Tarifa^ tarifa);

        // Elimina una tarifa existente.
        bool eliminarTarifa(int idTarifa);

        // Obtiene el siguiente ID disponible.
        int obtenerSiguienteId();
    };
}