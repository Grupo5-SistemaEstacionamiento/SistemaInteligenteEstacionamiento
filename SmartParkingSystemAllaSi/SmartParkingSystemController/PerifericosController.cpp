#include "pch.h"
#include "PerifericosController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

// Constructor
PerifericoController::PerifericoController() {
    dao = gcnew PerifericoDAO();
}

// Consolidamos todos los archivos en una sola lista (Superclase)

List<Periferico^>^ PerifericoController::ListarTodosLosPerifericos() {
    List<Periferico^>^ listaGeneral = gcnew List<Periferico^>();

    List<IndicadorLed^>^ leds = dao->buscarTodosIndicadoresLedArchivo();
    for (int i = 0; i < leds->Count; i++) {
        listaGeneral->Add(leds[i]);
    }

    List<ServoMotor^>^ servos = dao->buscarTodosServosArchivo();
    for (int i = 0; i < servos->Count; i++) {
        listaGeneral->Add(servos[i]);
    }

    List<SensorOcupacion^>^ sensores = dao->buscarTodosSensoresOcupacionArchivo();
    for (int i = 0; i < sensores->Count; i++) {
        listaGeneral->Add(sensores[i]);
    }

    List<LectorRFID^>^ lectores = dao->buscarTodosLectoresRFIDArchivo();
    for (int i = 0; i < lectores->Count; i++) {
        listaGeneral->Add(lectores[i]);
    }

    List<BarreraAcceso^>^ barreras = dao->buscarTodasBarrerasAccesoArchivo();
    for (int i = 0; i < barreras->Count; i++) {
        listaGeneral->Add(barreras[i]);
    }

    return listaGeneral;
}

// Filtro para el ComboBox de la interfaz
List<Periferico^>^ PerifericoController::FiltrarPorTipo(String^ tipoBuscado) {
    List<Periferico^>^ listaGeneral = gcnew List<Periferico^>();

    if (tipoBuscado == "Indicadores LED") {
        List<IndicadorLed^>^ leds = dao->buscarTodosIndicadoresLedArchivo();
        for (int i = 0; i < leds->Count; i++) {
            listaGeneral->Add(leds[i]);
        }
    }
    else if (tipoBuscado == "Servomotores") {
        List<ServoMotor^>^ servos = dao->buscarTodosServosArchivo();
        for (int i = 0; i < servos->Count; i++) {
            listaGeneral->Add(servos[i]);
        }
    }
    else if (tipoBuscado == "Lectores RFID") {
        List<LectorRFID^>^ lectoresRFID = dao->buscarTodosLectoresRFIDArchivo();
        for (int i = 0; i < lectoresRFID->Count; i++) {
            listaGeneral->Add(lectoresRFID[i]);
        }
    }
    else if (tipoBuscado == "Sensores IR") {
        List<SensorOcupacion^>^ sensoresIR = dao->buscarTodosSensoresOcupacionArchivo();
        for (int i = 0; i < sensoresIR->Count; i++) {
            listaGeneral->Add(sensoresIR[i]);
        }
    }
    else if (tipoBuscado == "Barreras de Acceso") {
        List<BarreraAcceso^>^ barreras = dao->buscarTodasBarrerasAccesoArchivo();
        for (int i = 0; i < barreras->Count; i++) {
            listaGeneral->Add(barreras[i]);
        }
    }
    
    return listaGeneral;
}

void PerifericoController::ModificarPeriferico(Periferico^ PerifericoMod) {
    // El objeto PerifericoMod ya viene desde la Interfaz con las fechas y datos cambiados

    if (dynamic_cast<IndicadorLed^>(PerifericoMod) != nullptr) {
        dao->modificarIndicadorLedArchivo(dynamic_cast<IndicadorLed^>(PerifericoMod));
    }
    else if (dynamic_cast<ServoMotor^>(PerifericoMod) != nullptr) {
        dao->modificarServoMotorArchivo(dynamic_cast<ServoMotor^>(PerifericoMod));
    }
    else if (dynamic_cast<SensorOcupacion^>(PerifericoMod) != nullptr) {
        dao->modificarSensorOcupacionArchivo(dynamic_cast<SensorOcupacion^>(PerifericoMod));
    }
    else if (dynamic_cast<LectorRFID^>(PerifericoMod) != nullptr) {
        dao->modificarLectorRFIDArchivo(dynamic_cast<LectorRFID^>(PerifericoMod));
    }
    else if (dynamic_cast<BarreraAcceso^>(PerifericoMod) != nullptr) {
        dao->modificarBarreraAccesoArchivo(dynamic_cast<BarreraAcceso^>(PerifericoMod));
    }
}

void PerifericoController::AddPeriferico(Periferico^ NuevoPeriferico) {
    if (dynamic_cast<IndicadorLed^>(NuevoPeriferico) != nullptr) {
        dao->registrarIndicadorLedArchivo(dynamic_cast<IndicadorLed^>(NuevoPeriferico));
    }
    else if (dynamic_cast<ServoMotor^>(NuevoPeriferico) != nullptr) {
        dao->registrarServoMotorArchivo(dynamic_cast<ServoMotor^>(NuevoPeriferico));
    }
    else if (dynamic_cast<SensorOcupacion^>(NuevoPeriferico) != nullptr) {
        dao->registrarSensorOcupacionArchivo(dynamic_cast<SensorOcupacion^>(NuevoPeriferico));
    }
    else if (dynamic_cast<LectorRFID^>(NuevoPeriferico) != nullptr) {
        dao->registrarLectorRFIDArchivo(dynamic_cast<LectorRFID^>(NuevoPeriferico));
    }
    else if (dynamic_cast<BarreraAcceso^>(NuevoPeriferico) != nullptr) {
        dao->registrarBarreraAccesoArchivo(dynamic_cast<BarreraAcceso^>(NuevoPeriferico));
    }
}

// 1. El método "buscador" que revisa los 5 archivos de tu compañero
Periferico^ PerifericoController::BuscarPerifericoxID(int idPeriferico) {
    Periferico^ PerifericoBuscado = nullptr;

    PerifericoBuscado = dao->buscarIndicadorLedxIdArchivo(idPeriferico);
    if (PerifericoBuscado != nullptr) {
        return PerifericoBuscado;
    }   

    PerifericoBuscado = dao->buscarServoMotorxIdArchivo(idPeriferico);
    if (PerifericoBuscado != nullptr) {
        return PerifericoBuscado;
    }

    PerifericoBuscado = dao->buscarSensorOcupacionxIdArchivo(idPeriferico);
    if (PerifericoBuscado != nullptr) {
        return PerifericoBuscado;
    }

    PerifericoBuscado = dao->buscarLectorRFIDxIdArchivo(idPeriferico);
    if (PerifericoBuscado != nullptr) {
        return PerifericoBuscado;
    }

    PerifericoBuscado = dao->buscarBarreraAccesoxIdArchivo(idPeriferico);
    if (PerifericoBuscado != nullptr) {
        return PerifericoBuscado;
    }

    return nullptr; // Si no existe en ningún TXT
}

void PerifericoController::EliminarPeriferico(int idPeriferico) {
  
    Periferico^ PerifericoBuscado = BuscarPerifericoxID(idPeriferico);

    if (PerifericoBuscado == nullptr) {
        return; // Si por algún error no existe, abortamos para que no pete pete pete KABOOM!!!
    }

    // Usamos dynamic_cast para saber a qué método del DAO mandarlo a borrar
    if (dynamic_cast<IndicadorLed^>(PerifericoBuscado) != nullptr) {
        dao->eliminarIndicadorLedArchivo(idPeriferico);
    }
    else if (dynamic_cast<ServoMotor^>(PerifericoBuscado) != nullptr) {
        dao->eliminarServoMotorArchivo(idPeriferico);
    }
    else if (dynamic_cast<SensorOcupacion^>(PerifericoBuscado) != nullptr) {
        dao->eliminarSensorOcupacionArchivo(idPeriferico);
    }
    else if (dynamic_cast<LectorRFID^>(PerifericoBuscado) != nullptr) {
        dao->eliminarLectorRFIDArchivo(idPeriferico);
    }
    else if (dynamic_cast<BarreraAcceso^>(PerifericoBuscado) != nullptr) {
        dao->eliminarBarreraAccesoArchivo(idPeriferico);
    }
}
