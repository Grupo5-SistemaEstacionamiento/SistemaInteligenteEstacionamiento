#include "pch.h"
#include "TarifaDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

// Constructor
TarifaDAO::TarifaDAO()
{
    // Obtiene la carpeta donde se encuentra el ejecutable.    
    String^ rutaEjecucion =
        AppDomain::CurrentDomain->BaseDirectory;

    // Retrocede hasta la carpeta raíz
    // de la solución SmartParkingSystem.
    String^ rutaSolucion =
        Path::GetFullPath(
            Path::Combine(rutaEjecucion, "..\\..\\")
        );

    // Construye la ruta final:
    // SmartParkingSystem\Data\tarifas.txt
    rutaArchivo =
        Path::Combine(
            rutaSolucion,
            "Data",
            "tarifas.txt"
        );

    verificarDirectorio();
}

// Verifica que exista la carpeta donde se almacenarán los datos.
void TarifaDAO::verificarDirectorio() {

    String^ directorioDatos =
        Path::GetDirectoryName(rutaArchivo);

    if (!Directory::Exists(directorioDatos)) {
        Directory::CreateDirectory(directorioDatos);
    }
}

bool TarifaDAO::guardarTarifas(List<Tarifa^>^ tarifas)
{
    try
    {
        StreamWriter^ escritor =
            gcnew StreamWriter(rutaArchivo, false);

        for each(Tarifa ^ tarifa in tarifas)
        {
            escritor->WriteLine(
                tarifa->getIdTarifa().ToString() + "|" +
                tarifa->getValorHora().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                tarifa->getValorFraccion15min().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                tarifa->getDescuentoMembresia().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                tarifa->getPenalizacionTicketPerdido().ToString(
                    "F2", CultureInfo::InvariantCulture)
            );
        }

        escritor->Close();

        return true;
    }
    catch (Exception^)
    {
        return false;
    }
}

// Recupera todas las tarifas almacenadas en el archivo.
List<Tarifa^>^ TarifaDAO::listarTarifas() {

    List<Tarifa^>^ listaTarifas = gcnew List<Tarifa^>();

    if (!File::Exists(rutaArchivo)) {
        return listaTarifas;
    }

    array<String^>^ lineas = File::ReadAllLines(rutaArchivo);

    for each (String ^ linea in lineas) {

        if (String::IsNullOrWhiteSpace(linea)) {
            continue;
        }

        array<String^>^ datos = linea->Split('|');

        // Cada tarifa debe tener exactamente 5 campos.
        if (datos->Length != 5) {
            continue;
        }

        int idTarifa;
        double valorHora;
        double valorFraccion15min;
        double descuentoMembresia;
        double penalizacionTicketPerdido;

        bool datosValidos =
            Int32::TryParse(datos[0], idTarifa) &&
            Double::TryParse(
                datos[1],
                NumberStyles::Float,
                CultureInfo::InvariantCulture,
                valorHora) &&
            Double::TryParse(
                datos[2],
                NumberStyles::Float,
                CultureInfo::InvariantCulture,
                valorFraccion15min) &&
            Double::TryParse(
                datos[3],
                NumberStyles::Float,
                CultureInfo::InvariantCulture,
                descuentoMembresia) &&
            Double::TryParse(
                datos[4],
                NumberStyles::Float,
                CultureInfo::InvariantCulture,
                penalizacionTicketPerdido);

        // Si una línea está dañada, se omite.
        if (!datosValidos) {
            continue;
        }

        Tarifa^ tarifa = gcnew Tarifa(
            idTarifa,
            valorHora,
            valorFraccion15min,
            descuentoMembresia,
            penalizacionTicketPerdido
        );

        listaTarifas->Add(tarifa);
    }

    return listaTarifas;
}

// Busca una tarifa según su identificador.
Tarifa^ TarifaDAO::buscarTarifa(int idTarifa) {

    List<Tarifa^>^ listaTarifas = listarTarifas();

    for each (Tarifa ^ tarifa in listaTarifas) {

        if (tarifa->getIdTarifa() == idTarifa) {
            return tarifa;
        }
    }

    return nullptr;
}

// Registra una nueva tarifa.
bool TarifaDAO::registrarTarifa(Tarifa^ tarifa) {

    if (tarifa == nullptr) {
        return false;
    }

    // Evita IDs duplicados.
    if (buscarTarifa(tarifa->getIdTarifa()) != nullptr) {
        return false;
    }

    StreamWriter^ escritor =
        gcnew StreamWriter(rutaArchivo, true);

    escritor->WriteLine(
        tarifa->getIdTarifa().ToString() + "|" +
        tarifa->getValorHora().ToString("F2", CultureInfo::InvariantCulture) + "|" +
        tarifa->getValorFraccion15min().ToString("F2", CultureInfo::InvariantCulture) + "|" +
        tarifa->getDescuentoMembresia().ToString("F2", CultureInfo::InvariantCulture) + "|" +
        tarifa->getPenalizacionTicketPerdido().ToString("F2", CultureInfo::InvariantCulture)
    );

    escritor->Close();

    return true;
}

// Modifica una tarifa existente.
bool TarifaDAO::modificarTarifa(Tarifa^ tarifaModificada) {

    if (tarifaModificada == nullptr) {
        return false;
    }

    List<Tarifa^>^ listaTarifas = listarTarifas();

    bool encontrada = false;

    for (int i = 0; i < listaTarifas->Count; i++) {

        if (listaTarifas[i]->getIdTarifa() ==
            tarifaModificada->getIdTarifa()) {

            listaTarifas[i] = tarifaModificada;
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        return false;
    }

    StreamWriter^ escritor =
        gcnew StreamWriter(rutaArchivo, false);

    for each (Tarifa ^ tarifa in listaTarifas) {

        escritor->WriteLine(
            tarifa->getIdTarifa().ToString() + "|" +
            tarifa->getValorHora().ToString("F2", CultureInfo::InvariantCulture) + "|" +
            tarifa->getValorFraccion15min().ToString("F2", CultureInfo::InvariantCulture) + "|" +
            tarifa->getDescuentoMembresia().ToString("F2", CultureInfo::InvariantCulture) + "|" +
            tarifa->getPenalizacionTicketPerdido().ToString("F2", CultureInfo::InvariantCulture)
        );
    }

    escritor->Close();

    return true;
}

// Elimina una tarifa según su identificador.
bool TarifaDAO::eliminarTarifa(int idTarifa)
{
    List<Tarifa^>^ tarifas = listarTarifas();

    bool encontrado = false;

    // Busca y elimina la tarifa indicada.
    for (int i = 0; i < tarifas->Count; i++)
    {
        if (tarifas[i]->getIdTarifa() == idTarifa)
        {
            tarifas->RemoveAt(i);
            encontrado = true;
            break;
        }
    }

    // Si no encontró el ID, no realiza cambios.
    if (!encontrado)
    {
        return false;
    }

    // Renumera los ID para mantenerlos consecutivos.
    for (int i = 0; i < tarifas->Count; i++)
    {
        tarifas[i]->setIdTarifa(i + 1);
    }

    try
    {
        StreamWriter^ escritor =
            gcnew StreamWriter(rutaArchivo, false);

        for each(Tarifa ^ tarifa in tarifas)
        {
            escritor->WriteLine(
                tarifa->getIdTarifa().ToString() + "|" +
                tarifa->getValorHora().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                tarifa->getValorFraccion15min().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                tarifa->getDescuentoMembresia().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                tarifa->getPenalizacionTicketPerdido().ToString(
                    "F2", CultureInfo::InvariantCulture)
            );
        }

        escritor->Close();

        return true;
    }
    catch (Exception^)
    {
        return false;
    }
}

// Genera el siguiente ID consecutivo.
int TarifaDAO::obtenerSiguienteId()
{
    // Obtiene todas las tarifas registradas.
    List<Tarifa^>^ tarifas = listarTarifas();

    // Como los ID siempre son consecutivos,
    // el siguiente corresponde a la cantidad + 1.
    return tarifas->Count + 1;
}