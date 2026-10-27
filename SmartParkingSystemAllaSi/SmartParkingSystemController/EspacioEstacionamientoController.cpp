#include "pch.h"
#include "EspacioEstacionamientoController.h"

using namespace SmartParkingSystemController;

EspacioEstacionamientoController::EspacioEstacionamientoController() {
    this->dao = gcnew EspacioEstacionamientoDAO();
}

List<EspacioEstacionamiento^>^ EspacioEstacionamientoController::ObtenerEspacios() {
    // 1. Obtener los datos básicos (ID, Código, Estado) desde el archivo de texto
    List<EspacioEstacionamiento^>^ espacios = dao->ObtenerTodos();

    // 2. Inyectar las coordenadas visuales (Rectangle) a cada espacio según su ID
    for (int i = 0; i < espacios->Count; i++) {
        EspacioEstacionamiento^ espacio = espacios[i];
        int id = espacio->getIdEspacio();

        // Convertir IDs del 31-90 a posiciones equivalentes del 1 al 30
        int idRelativo = ((id - 1) % 30) + 1;

        // Evaluar idRelativo en lugar del id real
        switch (idRelativo) {
            // --- COLUMNA 1 (Pared Izquierda: X = 64) ---
        case 1: espacio->setArea(Rectangle(64, 128, 64, 64)); break;
        case 2: espacio->setArea(Rectangle(64, 192, 64, 64)); break;
        case 3: espacio->setArea(Rectangle(64, 256, 64, 64)); break;
        case 4: espacio->setArea(Rectangle(64, 320, 64, 64)); break;
        case 5: espacio->setArea(Rectangle(64, 384, 64, 64)); break;// Discapacitado Izq

            // --- COLUMNA 2 (Isla 1 Izquierda: X = 256) ---
        case 6:  espacio->setArea(Rectangle(256, 128, 64, 64)); break;
        case 7:  espacio->setArea(Rectangle(256, 192, 64, 64)); break;
        case 8:  espacio->setArea(Rectangle(256, 256, 64, 64)); break;
        case 9:  espacio->setArea(Rectangle(256, 320, 64, 64)); break;
        case 10: espacio->setArea(Rectangle(256, 384, 64, 64)); break;

            // --- COLUMNA 3 (Isla 1 Derecha: X = 384) ---
        case 11: espacio->setArea(Rectangle(384, 128, 64, 64)); break;
        case 12: espacio->setArea(Rectangle(384, 192, 64, 64)); break;
        case 13: espacio->setArea(Rectangle(384, 256, 64, 64)); break;
        case 14: espacio->setArea(Rectangle(384, 320, 64, 64)); break;
        case 15: espacio->setArea(Rectangle(384, 384, 64, 64)); break;

            // --- COLUMNA 4 (Isla 2 Izquierda: X = 576) ---
        case 16: espacio->setArea(Rectangle(576, 128, 64, 64)); break;
        case 17: espacio->setArea(Rectangle(576, 192, 64, 64)); break;
        case 18: espacio->setArea(Rectangle(576, 256, 64, 64)); break;
        case 19: espacio->setArea(Rectangle(576, 320, 64, 64)); break;
        case 20: espacio->setArea(Rectangle(576, 384, 64, 64)); break;

            // --- COLUMNA 5 (Isla 2 Derecha: X = 704) ---
        case 21: espacio->setArea(Rectangle(704, 128, 64, 64)); break;
        case 22: espacio->setArea(Rectangle(704, 192, 64, 64)); break;
        case 23: espacio->setArea(Rectangle(704, 256, 64, 64)); break;
        case 24: espacio->setArea(Rectangle(704, 320, 64, 64)); break;
        case 25: espacio->setArea(Rectangle(704, 384, 64, 64)); break;

            // --- COLUMNA 6 (Pared Derecha: X = 896) ---
        case 26: espacio->setArea(Rectangle(896, 128, 64, 64)); break;
        case 27: espacio->setArea(Rectangle(896, 192, 64, 64)); break;
        case 28: espacio->setArea(Rectangle(896, 256, 64, 64)); break;
        case 29: espacio->setArea(Rectangle(896, 320, 64, 64)); break;
        case 30: espacio->setArea(Rectangle(896, 384, 64, 64)); break;// Discapacitado Der

        default: espacio->setArea(Rectangle(0, 0, 0, 0)); break;
        }
    }

    return espacios;
}

bool EspacioEstacionamientoController::ProcesarClic(int x, int y, List<EspacioEstacionamiento^>^ espacios, int pisoActual) {
    bool estadoCambiado = false;

    for each (EspacioEstacionamiento ^ espacio in espacios) {
        // 1. Calcular a qué piso pertenece el cajón evaluado (1-30=Piso1, 31-60=Piso2, 61-90=Piso3)
        int id = espacio->getIdEspacio();
        int pisoDelEspacio = ((id - 1) / 30) + 1;

        // 2. Verificar que el cajón es del piso visible Y que el clic está en su área
        if (pisoDelEspacio == pisoActual && espacio->getArea().Contains(x, y)) {

            // Invertir estado
            bool nuevoEstado = !espacio->getEstaOcupado();
            espacio->setEstaOcupado(nuevoEstado);

            // Guardar el nuevo estado en el archivo .txt a través del DAO
            dao->ActualizarEstado(id, nuevoEstado);

            estadoCambiado = true;
            break; // Detener la búsqueda
        }
    }

    return estadoCambiado; // Si devuelve true, la Vista sabrá que debe hacer Invalidate()
}