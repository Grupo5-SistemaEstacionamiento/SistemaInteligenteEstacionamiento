#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemModel;
using namespace System::IO::Ports; //Libreria para chambear con el ESP32S3

namespace SmartParkingSystemController {

    public ref class PerifericoController {
    private:
        PerifericoDAO^ dao;
        static System::IO::Ports::SerialPort^ puertoESP32; 

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

        //Operaciones para el ESP32S3 (o cualquier otro microncontrolador)

        static void InicializarPuerto(String^ portName); //nicializa el puerto GPIO
        static void CerrarPuerto(); //Cierra el puerto GPIO
        static void ActivarHardwareEmergencia(); //Manda un 1 al puerto del ESP32S3
        static void DesactivarHardwareEmergencia(); //Manda un 0 al puerto 2 del ESP32S3
        static String^ LeerMensajeESP32S3(); //Lee el estado del switch y retorna un string
        static void SolicitarEstadoHardware(); //Lee el estado del switch al iniciar el programa

    };
}