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
    for each (EspacioEstacionamiento ^ espacio in espacios) {
        int id = espacio->getIdEspacio();

        // Aquí debes colocar las coordenadas (X, Y, Ancho, Alto) reales de tu imagen
        switch (id) {
            // --- COLUMNA 1 (Pared Izquierda: X = 86) ---
        case 1: espacio->setArea(Rectangle(86, 142, 64, 64)); break;
        case 2: espacio->setArea(Rectangle(86, 206, 64, 64)); break;
        case 3: espacio->setArea(Rectangle(86, 270, 64, 64)); break;
        case 4: espacio->setArea(Rectangle(86, 334, 64, 64)); break;
        case 5: espacio->setArea(Rectangle(86, 398, 64, 64)); break;// Discapacitado Izq

            // --- COLUMNA 2 (Isla 1 Izquierda: X = 278) ---
        case 6:  espacio->setArea(Rectangle(278, 142, 64, 64)); break;
        case 7:  espacio->setArea(Rectangle(278, 206, 64, 64)); break;
        case 8:  espacio->setArea(Rectangle(278, 270, 64, 64)); break;
        case 9:  espacio->setArea(Rectangle(278, 334, 64, 64)); break;
        case 10: espacio->setArea(Rectangle(278, 398, 64, 64)); break;

            // --- COLUMNA 3 (Isla 1 Derecha: X = 406) ---
        case 11: espacio->setArea(Rectangle(406, 142, 64, 64)); break;
        case 12: espacio->setArea(Rectangle(406, 206, 64, 64)); break;
        case 13: espacio->setArea(Rectangle(406, 270, 64, 64)); break;
        case 14: espacio->setArea(Rectangle(406, 334, 64, 64)); break;
        case 15: espacio->setArea(Rectangle(406, 398, 64, 64)); break;

            // --- COLUMNA 4 (Isla 2 Izquierda: X = 598) ---
        case 16: espacio->setArea(Rectangle(598, 142, 64, 64)); break;
        case 17: espacio->setArea(Rectangle(598, 206, 64, 64)); break;
        case 18: espacio->setArea(Rectangle(598, 270, 64, 64)); break;
        case 19: espacio->setArea(Rectangle(598, 334, 64, 64)); break;
        case 20: espacio->setArea(Rectangle(598, 398, 64, 64)); break;

            // --- COLUMNA 5 (Isla 2 Derecha: X = 726) ---
        case 21: espacio->setArea(Rectangle(726, 142, 64, 64)); break;
        case 22: espacio->setArea(Rectangle(726, 206, 64, 64)); break;
        case 23: espacio->setArea(Rectangle(726, 270, 64, 64)); break;
        case 24: espacio->setArea(Rectangle(726, 334, 64, 64)); break;
        case 25: espacio->setArea(Rectangle(726, 398, 64, 64)); break;

            // --- COLUMNA 6 (Pared Derecha: X = 918) ---
        case 26: espacio->setArea(Rectangle(918, 142, 64, 64)); break;
        case 27: espacio->setArea(Rectangle(918, 206, 64, 64)); break;
        case 28: espacio->setArea(Rectangle(918, 270, 64, 64)); break;
        case 29: espacio->setArea(Rectangle(918, 334, 64, 64)); break;
        case 30: espacio->setArea(Rectangle(918, 398, 64, 64)); break;// Discapacitado Der
            

        default: espacio->setArea(Rectangle(0, 0, 0, 0)); break;
        }
    }

    return espacios;
}

bool EspacioEstacionamientoController::ProcesarClic(int x, int y, List<EspacioEstacionamiento^>^ espacios) {
    bool estadoCambiado = false;

    for each (EspacioEstacionamiento ^ espacio in espacios) {
        // Si el clic del mouse ocurrió dentro de los límites del rectángulo de este cajón
        if (espacio->getArea().Contains(x, y)) {
            // Invertir estado (si era true pasa a false y viceversa)
            bool nuevoEstado = !espacio->getEstaOcupado();
            espacio->setEstaOcupado(nuevoEstado);

            // Guardar el nuevo estado en el archivo .txt a través del DAO
            dao->ActualizarEstado(espacio->getIdEspacio(), nuevoEstado);

            estadoCambiado = true;
            break; // Detener la búsqueda, ya encontramos el cajón clickeado
        }
    }

    return estadoCambiado; // Si devuelve true, la Vista sabrá que debe hacer Invalidate()
}