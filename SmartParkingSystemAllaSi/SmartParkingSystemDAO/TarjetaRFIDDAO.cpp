#include "pch.h"

#include "TarjetaRFIDDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

// Constructor: localiza la raíz del repositorio.
TarjetaRFIDDAO::TarjetaRFIDDAO()
{
    String^ directorio =
        AppDomain::CurrentDomain->BaseDirectory;

    // Busca la carpeta que contiene la capa Model.
    while (!String::IsNullOrEmpty(directorio) &&
        !Directory::Exists(
            Path::Combine(
                directorio, "SmartParkingSystemModel")))
    {
        DirectoryInfo^ padre =
            Directory::GetParent(directorio);

        if (padre == nullptr)
        {
            throw gcnew DirectoryNotFoundException(
                "No se encontró la raíz de SmartParkingSystem."
            );
        }

        directorio = padre->FullName;
    }

    rutaArchivo = Path::Combine(
        directorio,
        "Data",
        "TXT",
        "tarjetasRFID.txt"
    );

    verificarDirectorio();
}

// Crea la carpeta Data/TXT si no existe.
void TarjetaRFIDDAO::verificarDirectorio()
{
    String^ carpeta =
        Path::GetDirectoryName(rutaArchivo);

    Directory::CreateDirectory(carpeta);

    if (!File::Exists(rutaArchivo))
    {
        File::WriteAllText(rutaArchivo, "");
    }
}

// Lee todas las tarjetas registradas.
List<TarjetaRFID^>^ TarjetaRFIDDAO::listarTarjetas()
{
    List<TarjetaRFID^>^ lista =
        gcnew List<TarjetaRFID^>();

    if (!File::Exists(rutaArchivo))
        return lista;

    array<String^>^ lineas =
        File::ReadAllLines(rutaArchivo);

    for each (String ^ linea in lineas)
    {
        if (String::IsNullOrWhiteSpace(linea))
            continue;

        array<String^>^ campos = linea->Split('|');

        // Se admiten formatos de seis y siete campos.
        if (campos->Length != 6 && campos->Length != 7)
        {
            throw gcnew FormatException(
                "Registro RFID con cantidad incorrecta de campos."
            );
        }

        int id = 0;
        int idCliente = 0;
        DateTime emision;
        DateTime vencimiento;
        DateTime ultimoUso = DateTime::MinValue;

        bool ok =
            Int32::TryParse(campos[0], id) &&
            DateTime::TryParse(
                campos[2],
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind,
                emision) &&
            DateTime::TryParse(
                campos[3],
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind,
                vencimiento) &&
            Int32::TryParse(campos[5], idCliente);

        if (!ok || id <= 0 || idCliente < 0 ||
            (campos[4] != "0" && campos[4] != "1"))
        {
            throw gcnew FormatException(
                "Registro RFID con datos inválidos."
            );
        }

        // El séptimo campo almacena el último uso.
        if (campos->Length == 7 &&
            !String::IsNullOrWhiteSpace(campos[6]))
        {
            if (!DateTime::TryParse(
                campos[6],
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind,
                ultimoUso))
            {
                throw gcnew FormatException(
                    "Fecha de último uso RFID inválida."
                );
            }
        }

        bool activa = campos[4] == "1";

        TarjetaRFID^ tarjeta = gcnew TarjetaRFID(
            id,
            campos[1],
            emision,
            vencimiento,
            activa,
            nullptr,
            nullptr
        );

        tarjeta->setIdCliente(idCliente);
        tarjeta->setUltimoUso(ultimoUso);

        lista->Add(tarjeta);
    }

    return lista;
}

// Guarda todas las tarjetas sin perder el historial.
bool TarjetaRFIDDAO::guardarTarjetas(
    List<TarjetaRFID^>^ tarjetas)
{
    if (tarjetas == nullptr)
        return false;

    try
    {
        List<String^>^ lineas =
            gcnew List<String^>();

        for each (TarjetaRFID ^ t in tarjetas)
        {
            if (t == nullptr)
                return false;

            String^ ultimoUso = "";

            if (t->getUltimoUso() != DateTime::MinValue)
            {
                ultimoUso = t->getUltimoUso().ToString(
                    "o",
                    CultureInfo::InvariantCulture
                );
            }

            // Formato:
            // id|UID|emision|vencimiento|activa|cliente|uso
            String^ linea =
                t->getIdTarjeta().ToString() + "|" +
                t->getCodigoUID() + "|" +
                t->getFechaEmision().ToString(
                    "o", CultureInfo::InvariantCulture) + "|" +
                t->getFechaVencimiento().ToString(
                    "o", CultureInfo::InvariantCulture) + "|" +
                (t->getActiva() ? "1" : "0") + "|" +
                t->getIdCliente().ToString() + "|" +
                ultimoUso;

            lineas->Add(linea);
        }

        String^ temporal = rutaArchivo + ".tmp";

        File::WriteAllLines(
            temporal,
            lineas->ToArray()
        );

        // Sustituye el archivo solamente después
        // de escribir correctamente el temporal.
        if (File::Exists(rutaArchivo))
        {
            File::Replace(
                temporal,
                rutaArchivo,
                nullptr
            );
        }
        else
        {
            File::Move(temporal, rutaArchivo);
        }

        return true;
    }
    catch (Exception^)
    {
        return false;
    }
}

// Busca una tarjeta por ID.
TarjetaRFID^ TarjetaRFIDDAO::buscarTarjeta(
    int idTarjeta)
{
    List<TarjetaRFID^>^ lista = listarTarjetas();

    for each (TarjetaRFID ^ t in lista)
    {
        if (t->getIdTarjeta() == idTarjeta)
            return t;
    }

    return nullptr;
}

// Método compatible con el formulario integrado.
TarjetaRFID^ TarjetaRFIDDAO::buscarPorId(
    int idTarjeta)
{
    return buscarTarjeta(idTarjeta);
}

// Busca una tarjeta mediante su código UID.
TarjetaRFID^ TarjetaRFIDDAO::buscarPorUID(
    String^ codigoUID)
{
    if (String::IsNullOrWhiteSpace(codigoUID))
        return nullptr;

    String^ uid = codigoUID->Trim();

    List<TarjetaRFID^>^ lista = listarTarjetas();

    for each (TarjetaRFID ^ t in lista)
    {
        if (String::Equals(
            t->getCodigoUID(),
            uid,
            StringComparison::OrdinalIgnoreCase))
        {
            return t;
        }
    }

    return nullptr;
}

// Registra una nueva tarjeta RFID.
bool TarjetaRFIDDAO::registrarTarjeta(
    TarjetaRFID^ tarjeta)
{
    if (tarjeta == nullptr ||
        tarjeta->getIdTarjeta() <= 0 ||
        String::IsNullOrWhiteSpace(tarjeta->getCodigoUID()))
        return false;

    List<TarjetaRFID^>^ lista = listarTarjetas();

    for each (TarjetaRFID ^ t in lista)
    {
        if (t->getIdTarjeta() == tarjeta->getIdTarjeta())
            return false;

        if (String::Equals(
            t->getCodigoUID(),
            tarjeta->getCodigoUID(),
            StringComparison::OrdinalIgnoreCase))
            return false;
    }

    lista->Add(tarjeta);

    return guardarTarjetas(lista);
}

// Modifica una tarjeta existente.
bool TarjetaRFIDDAO::modificarTarjeta(
    TarjetaRFID^ tarjeta)
{
    if (tarjeta == nullptr)
        return false;

    List<TarjetaRFID^>^ lista = listarTarjetas();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdTarjeta() ==
            tarjeta->getIdTarjeta())
        {
            int idClienteOriginal =
                lista[i]->getIdCliente();

            // Evita modificar el propietario.
            if (tarjeta->getIdCliente() != 0 &&
                idClienteOriginal != 0 &&
                tarjeta->getIdCliente() != idClienteOriginal)
            {
                return false;
            }

            tarjeta->setIdCliente(idClienteOriginal);

            // Conserva el último uso si el formulario
            // no lo proporciona.
            if (tarjeta->getUltimoUso() ==
                DateTime::MinValue)
            {
                tarjeta->setUltimoUso(
                    lista[i]->getUltimoUso()
                );
            }

            // Conserva las lecturas del objeto cargado.
            if (tarjeta->getListaLecturas() == nullptr ||
                tarjeta->getListaLecturas()->Count == 0)
            {
                tarjeta->setListaLecturas(
                    lista[i]->getListaLecturas()
                );
            }

            // Impide duplicar el UID de otra tarjeta.
            for each (TarjetaRFID ^ otra in lista)
            {
                if (otra->getIdTarjeta() !=
                    tarjeta->getIdTarjeta() &&
                    String::Equals(
                        otra->getCodigoUID(),
                        tarjeta->getCodigoUID(),
                        StringComparison::OrdinalIgnoreCase))
                {
                    return false;
                }
            }

            lista[i] = tarjeta;
            return guardarTarjetas(lista);
        }
    }

    return false;
}

// Desactiva una tarjeta sin eliminar su registro.
bool TarjetaRFIDDAO::desactivarTarjeta(
    int idTarjeta)
{
    List<TarjetaRFID^>^ lista = listarTarjetas();

    for each (TarjetaRFID ^ t in lista)
    {
        if (t->getIdTarjeta() == idTarjeta)
        {
            if (!t->estaActiva())
                return false;

            t->desactivar();
            return guardarTarjetas(lista);
        }
    }

    return false;
}

// Eliminación física original del repositorio.
bool TarjetaRFIDDAO::eliminarTarjeta(int idTarjeta)
{
    List<TarjetaRFID^>^ lista = listarTarjetas();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdTarjeta() == idTarjeta)
        {
            lista->RemoveAt(i);
            return guardarTarjetas(lista);
        }
    }

    return false;
}

// Obtiene el siguiente identificador disponible.
int TarjetaRFIDDAO::obtenerSiguienteId()
{
    List<TarjetaRFID^>^ lista = listarTarjetas();

    int mayorId = 0;

    for each (TarjetaRFID ^ t in lista)
    {
        if (t->getIdTarjeta() > mayorId)
            mayorId = t->getIdTarjeta();
    }

    return mayorId + 1;
}
