#include "pch.h"
#include "PerifericosController.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;

using namespace System::Windows;

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

// 1. El método "buscador" que revisa los 5 archivos 
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

// Hvdas del ESP32S3: ------------------------------------------------------------------------------------------------------------

void PerifericoController::SolicitarEstadoHardware() { //preguntamos por el estado inicial al abrir la pantalla 
    if (puertoESP32 != nullptr && puertoESP32->IsOpen) {
        try {
            puertoESP32->Write("2\n");
        }
        catch (Exception^) {}
    }
}

void PerifericoController::InicializarPuerto(String^ portName) {
    if (puertoESP32 == nullptr) {
        puertoESP32 = gcnew System::IO::Ports::SerialPort(); // lo creamos si aun no esta en memoria
    }

    if (!puertoESP32->IsOpen) {
        puertoESP32->PortName = portName; // es para los COM
        puertoESP32->BaudRate = 115200;   // Debe coincidir con el microcontrolador
        puertoESP32->DtrEnable = true;    // CRÍTICO para ESP32-S3
        puertoESP32->RtsEnable = true;    // CAMBIADO A TRUE: El USB nativo del S3 necesita ambos activos
        puertoESP32->Handshake = Handshake::None;
        puertoESP32->ReadTimeout = 500;
        puertoESP32->WriteTimeout = 500;

        puertoESP32->Open();
    }
}

void PerifericoController::CerrarPuerto() {
    // Añadido el blindaje != nullptr por seguridad
    if (puertoESP32 != nullptr && puertoESP32->IsOpen) {
        puertoESP32->Close();
    }
}

void PerifericoController::ActivarHardwareEmergencia() {
    if (puertoESP32 != nullptr && puertoESP32->IsOpen) {
        try {
            puertoESP32->Write("1\n"); // Añadido el salto de línea para forzar la lectura en el buffer del S3
        }
        catch (Exception^) {
            // El catch vacío absorbe el "semaphore timeout" sin que la aplicación explote ni se congele
        }
    }
}

void PerifericoController::DesactivarHardwareEmergencia() {
    if (puertoESP32 != nullptr && puertoESP32->IsOpen) {
        try {
            puertoESP32->Write("0\n"); // Añadido el salto de línea
        }
        catch (Exception^) {
            // Absorbe el error silenciosamente
        }
    }
}

String^ PerifericoController::LeerMensajeESP32S3() {
    if (puertoESP32 != nullptr && puertoESP32->IsOpen) {
        if (puertoESP32->BytesToRead > 0) {
            try { 
                return puertoESP32->ReadLine()->Trim(); // Leemos el mensaje que mandó el ESP32
            }
            catch (Exception^) {
            }
        }
    }
    return ""; // Retornamos vacío si no hay mensajes nuevos
}

