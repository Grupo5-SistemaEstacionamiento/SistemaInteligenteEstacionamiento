#pragma once

namespace SmartParkingSystemController {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Drawing;
    using namespace SmartParkingSystemModel;
    using namespace SmartParkingSystemDAO;

    public ref class EspacioEstacionamientoController {
    private:
        EspacioEstacionamientoDAO^ dao;

    public:
        EspacioEstacionamientoController();

        // Obtiene la lista del TXT y le inyecta las coordenadas gráficas
        List<EspacioEstacionamiento^>^ ObtenerEspacios();

        // Recibe el clic, busca qué auto se tocó, cambia su estado y guarda en el TXT
        // Devuelve true si un espacio cambió de estado (para saber si hay que redibujar)
        bool ProcesarClic(int x, int y, List<EspacioEstacionamiento^>^ espacios, int pisoActual);
    };
}