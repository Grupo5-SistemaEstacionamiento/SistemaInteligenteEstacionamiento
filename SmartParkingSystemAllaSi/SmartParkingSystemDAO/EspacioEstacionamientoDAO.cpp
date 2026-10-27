#include "pch.h"
#include "EspacioEstacionamientoDAO.h"

using namespace SmartParkingSystemDAO;

EspacioEstacionamientoDAO::EspacioEstacionamientoDAO() {
    // Constructor vacío, no inicializamos variables globales
}

List<EspacioEstacionamiento^>^ EspacioEstacionamientoDAO::ObtenerTodos() {
    List<EspacioEstacionamiento^>^ lista = gcnew List<EspacioEstacionamiento^>();

    // Se usa la ruta directamente aquí
    if (!File::Exists("espacios.txt")) {
        return lista;
    }

    array<String^>^ lineas = File::ReadAllLines("espacios.txt");
    for each (String ^ linea in lineas) {
        array<String^>^ partes = linea->Split(',');
        if (partes->Length >= 3) {
            EspacioEstacionamiento^ espacio = gcnew EspacioEstacionamiento();
            espacio->setIdEspacio(Convert::ToInt32(partes[0]));
            espacio->setCodigo(partes[1]);
            espacio->setEstaOcupado(Convert::ToBoolean(partes[2]));

            lista->Add(espacio);
        }
    }
    return lista;
}

void EspacioEstacionamientoDAO::ActualizarEstado(int idEspacio, bool estaOcupado) {
    if (!File::Exists("espacios.txt")) return;

    List<String^>^ nuevasLineas = gcnew List<String^>();
    array<String^>^ lineas = File::ReadAllLines("espacios.txt");

    for each (String ^ linea in lineas) {
        array<String^>^ partes = linea->Split(',');
        if (partes->Length >= 3) {
            int idActual = Convert::ToInt32(partes[0]);
            if (idActual == idEspacio) {
                nuevasLineas->Add(idActual + "," + partes[1] + "," + estaOcupado.ToString());
            }
            else {
                nuevasLineas->Add(linea);
            }
        }
    }

    // Se guarda usando la ruta directamente
    File::WriteAllLines("espacios.txt", nuevasLineas->ToArray());
}