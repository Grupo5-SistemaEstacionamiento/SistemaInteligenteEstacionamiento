#include "pch.h"

#include "PenalizacionDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

// Constructor.
PenalizacionDAO::PenalizacionDAO()
{
    String^ directorio =
        AppDomain::CurrentDomain->BaseDirectory;

    DirectoryInfo^ carpeta =
        gcnew DirectoryInfo(directorio);

    // Busca la raíz de la solución.
    while (carpeta != nullptr)
    {
        if (File::Exists(Path::Combine(
            carpeta->FullName,
            "SmartParkingSystemAllaSi.slnx")) ||
            Directory::Exists(Path::Combine(
                carpeta->FullName,
                "SmartParkingSystemViewGUI")))
        {
            break;
        }

        carpeta = carpeta->Parent;
    }

    if (carpeta == nullptr)
    {
        throw gcnew DirectoryNotFoundException(
            "No se encontró la carpeta de la solución.");
    }

    rutaArchivo = Path::Combine(
        carpeta->FullName,
        "Data",
        "TXT",
        "penalizaciones.txt"
    );

    verificarDirectorio();
}

// Verifica la carpeta y crea el archivo si no existe.
void PenalizacionDAO::verificarDirectorio()
{
    String^ directorio =
        Path::GetDirectoryName(rutaArchivo);

    if (!Directory::Exists(directorio))
    {
        Directory::CreateDirectory(directorio);
    }

    if (!File::Exists(rutaArchivo))
    {
        File::Create(rutaArchivo)->Close();
    }
}

// Guarda todos los registros.
bool PenalizacionDAO::guardarPenalizaciones(
    List<Penalizacion^>^ penalizaciones)
{
    try
    {
        verificarDirectorio();

        StreamWriter^ escritor =
            gcnew StreamWriter(rutaArchivo, false);

        try
        {
            for each (Penalizacion ^ p in penalizaciones)
            {
                String^ fechaRegistro = p->getFechaHora().ToString(
                    "dd/MM/yyyy HH:mm:ss",
                    CultureInfo::InvariantCulture
                );

                String^ fechaPago = p->getPagado()
                    ? p->getFechaPago().ToString(
                        "dd/MM/yyyy HH:mm:ss",
                        CultureInfo::InvariantCulture)
                    : String::Empty;

                escritor->WriteLine(
                    p->getIdPenalizacion().ToString() + "|" +
                    p->getPlacaVehiculo() + "|" +
                    ((int)p->getTipo()).ToString() + "|" +
                    fechaRegistro + "|" +
                    p->getPagado().ToString() + "|" +
                    fechaPago + "|" +
                    p->getMotivo() + "|" +
                    p->getMonto().ToString(
                        "F2", CultureInfo::InvariantCulture)
                );
            }
        }
        finally
        {
            escritor->Close();
        }

        return true;
    }
    catch (Exception^)
    {
        return false;
    }
}

// Lista todas las penalizaciones.
List<Penalizacion^>^
PenalizacionDAO::listarPenalizaciones()
{
    List<Penalizacion^>^ lista =
        gcnew List<Penalizacion^>();

    verificarDirectorio();

    array<String^>^ lineas =
        File::ReadAllLines(rutaArchivo);

    for each (String ^ linea in lineas)
    {
        if (String::IsNullOrWhiteSpace(linea))
            continue;

        array<String^>^ datos = linea->Split('|');

        if (datos->Length != 8)
            continue;

        try
        {
            int id = Int32::Parse(datos[0]);

            String^ placa = datos[1];

            int tipo = Int32::Parse(datos[2]);

            array<String^>^ formatos = gcnew array<String^>
            {
                "dd/MM/yyyy HH:mm:ss",
                    "o"
            };

            DateTime fechaHora = DateTime::ParseExact(
                datos[3],
                formatos,
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind
            );

            bool pagado = Boolean::Parse(datos[4]);

            DateTime fechaPago = DateTime::MinValue;

            if (!String::IsNullOrWhiteSpace(datos[5]))
            {
                fechaPago = DateTime::ParseExact(
                    datos[5],
                    formatos,
                    CultureInfo::InvariantCulture,
                    DateTimeStyles::RoundtripKind
                );
            }

            String^ motivo = datos[6];

            double monto = Double::Parse(
                datos[7],
                CultureInfo::InvariantCulture);

            Penalizacion^ p = gcnew Penalizacion(
                id,
                (TipoPenalizacion)tipo,
                fechaHora,
                pagado,
                fechaPago,
                motivo,
                monto,
                nullptr,
                nullptr
            );

            p->setPlacaVehiculo(placa);

            lista->Add(p);
        }
        catch (Exception^)
        {
            // Omite registros inválidos.
        }
    }

    return lista;
}

// Busca una penalización por ID.
Penalizacion^ PenalizacionDAO::buscarPenalizacion(
    int idPenalizacion)
{
    List<Penalizacion^>^ lista =
        listarPenalizaciones();

    for each (Penalizacion ^ p in lista)
    {
        if (p->getIdPenalizacion() == idPenalizacion)
            return p;
    }

    return nullptr;
}

// Registra una penalización.
bool PenalizacionDAO::registrarPenalizacion(
    Penalizacion^ penalizacion)
{
    if (penalizacion == nullptr)
        return false;

    List<Penalizacion^>^ lista =
        listarPenalizaciones();

    for each (Penalizacion ^ p in lista)
    {
        if (p->getIdPenalizacion() ==
            penalizacion->getIdPenalizacion())
        {
            return false;
        }
    }

    lista->Add(penalizacion);

    return guardarPenalizaciones(lista);
}

// Modifica una penalización existente.
bool PenalizacionDAO::modificarPenalizacion(
    Penalizacion^ penalizacion)
{
    if (penalizacion == nullptr)
        return false;

    List<Penalizacion^>^ lista =
        listarPenalizaciones();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdPenalizacion() ==
            penalizacion->getIdPenalizacion())
        {
            lista[i] = penalizacion;
            return guardarPenalizaciones(lista);
        }
    }

    return false;
}

// Elimina una penalización por ID.
bool PenalizacionDAO::eliminarPenalizacion(
    int idPenalizacion)
{
    List<Penalizacion^>^ lista =
        listarPenalizaciones();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdPenalizacion() ==
            idPenalizacion)
        {
            lista->RemoveAt(i);
            return guardarPenalizaciones(lista);
        }
    }

    return false;
}

// Obtiene el siguiente ID disponible.
int PenalizacionDAO::obtenerSiguienteId()
{
    List<Penalizacion^>^ lista =
        listarPenalizaciones();

    int mayorId = 0;

    for each (Penalizacion ^ p in lista)
    {
        if (p->getIdPenalizacion() > mayorId)
            mayorId = p->getIdPenalizacion();
    }

    return mayorId + 1;
}
