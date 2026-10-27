#pragma once

namespace SmartParkingSystemDAO {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::IO;
    using namespace SmartParkingSystemModel;

    public ref class EspacioEstacionamientoDAO {
    public:
        EspacioEstacionamientoDAO();
        List<EspacioEstacionamiento^>^ ObtenerTodos();
        void ActualizarEstado(int idEspacio, bool estaOcupado);
    };
}