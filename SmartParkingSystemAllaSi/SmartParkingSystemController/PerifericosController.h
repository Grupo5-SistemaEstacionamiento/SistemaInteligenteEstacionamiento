#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemController {

    public ref class PerifericoController {
    private:
        PerifericoDAO^ dao;

    public:
        // Constructor
        PerifericoController();

        // Operaciones CRUD
        List<Periferico^>^ ListarTodosLosPerifericos();
        void AddPeriferico(Periferico^ NuevoPeriferico);
        void ModificarPeriferico(Periferico^ PerifericoMod);
        void EliminarPeriferico(int idPeriferico);
            
        // Operaciones extra
        Periferico^ BuscarPerifericoxID(int idPeriferico);
        List<Periferico^>^ FiltrarPorTipo(String^ tipoBuscado);
    };
}