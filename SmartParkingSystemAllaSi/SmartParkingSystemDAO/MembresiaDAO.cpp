#include "pch.h"

#include "MembresiaDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

// Constructor. Establece la ruta de persistencia.
MembresiaDAO::MembresiaDAO()
{
    // Obtiene la carpeta donde se ejecuta el programa.
    String^ rutaEjecucion =
        AppDomain::CurrentDomain->BaseDirectory;

    // Busca la carpeta raíz del proyecto SmartParkingSystem.
    String^ directorio = gcnew String(rutaEjecucion);

    while (!String::IsNullOrEmpty(directorio) &&
        !Directory::Exists(
            Path::Combine(directorio, "SmartParkingSystemModel")))
    {
        DirectoryInfo^ padre = Directory::GetParent(directorio);

        if (padre == nullptr)
            break;

        directorio = padre->FullName;
    }

    // Establece la carpeta Data/TXT.
    String^ carpetaDatos =
        Path::Combine(directorio, "Data", "TXT");

    // Crea las carpetas si todavía no existen.
    Directory::CreateDirectory(carpetaDatos);

    // Ruta completa del archivo de membresías.
    rutaArchivo =
        Path::Combine(carpetaDatos, "membresias.txt");
}

// Crea el directorio cuando no existe.
void MembresiaDAO::verificarDirectorio()
{
    String^ directorio = Path::GetDirectoryName(rutaArchivo);

    if (!Directory::Exists(directorio))
    {
        Directory::CreateDirectory(directorio);
    }
}

// Reescribe el archivo conservando su formato original.
bool MembresiaDAO::guardarMembresias(
    List<Membresia^>^ membresias)
{
    if (membresias == nullptr)
        return false;

    try
    {
        List<String^>^ lineas = gcnew List<String^>();

        for each (Membresia ^ m in membresias)
        {
            if (m == nullptr)
                return false;

            // Formato del repositorio clonado:
            // id|inicio|fin|descuento|activo|precio|tipo|idCliente
            String^ linea =
                m->getIdMembresia().ToString() + "|" +
                m->getFechaInicio().ToString("o") + "|" +
                m->getFechaFin().ToString("o") + "|" +
                m->getPorcentajeDescuento().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                (m->getActivo() ? "1" : "0") + "|" +
                m->getPrecio().ToString(
                    "F2", CultureInfo::InvariantCulture) + "|" +
                ((int)m->getTipo()).ToString() + "|" +
                m->getIdCliente().ToString();

            lineas->Add(linea);
        }

        // Archivo temporal para evitar escritura parcial.
        String^ temporal = rutaArchivo + ".tmp";
        File::WriteAllLines(temporal, lineas->ToArray());

        if (File::Exists(rutaArchivo))
        {
            File::Replace(temporal, rutaArchivo, nullptr);
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

// Lista las membresías del archivo.
List<Membresia^>^ MembresiaDAO::listarMembresias()
{
    List<Membresia^>^ lista =
        gcnew List<Membresia^>();

    if (!File::Exists(rutaArchivo))
        return lista;

    array<String^>^ lineas = File::ReadAllLines(rutaArchivo);

    for each (String ^ linea in lineas)
    {
        if (String::IsNullOrWhiteSpace(linea))
            continue;

        array<String^>^ campos = linea->Split('|');

        // El formato actual contiene ocho campos.
        if (campos->Length != 8)
            continue;

        int id = 0;
        int idCliente = 0;
        int tipoInt = 0;

        DateTime inicio;
        DateTime fin;

        double descuento = 0.0;
        double precio = 0.0;

        bool ok =
            Int32::TryParse(campos[0], id) &&
            DateTime::TryParse(
                campos[1],
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind,
                inicio) &&
            DateTime::TryParse(
                campos[2],
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind,
                fin) &&
            Double::TryParse(
                campos[3],
                NumberStyles::Float,
                CultureInfo::InvariantCulture,
                descuento) &&
            Double::TryParse(
                campos[5],
                NumberStyles::Float,
                CultureInfo::InvariantCulture,
                precio) &&
            Int32::TryParse(campos[6], tipoInt) &&
            Int32::TryParse(campos[7], idCliente);

        if (!ok)
            continue;

        if (campos[4] != "1" && campos[4] != "0")
            continue;

        bool activo = (campos[4] == "1");

        Membresia^ m = gcnew Membresia(
            id,
            idCliente,
            inicio,
            fin,
            descuento,
            activo,
            precio,
            (TipoMembresia)tipoInt
        );

        lista->Add(m);
    }

    return lista;
}

// Busca una membresía mediante su ID.
Membresia^ MembresiaDAO::buscarMembresia(
    int idMembresia)
{
    List<Membresia^>^ lista = listarMembresias();

    for each (Membresia ^ m in lista)
    {
        if (m->getIdMembresia() == idMembresia)
            return m;
    }

    return nullptr;
}

// Método compatible con el proyecto original.
Membresia^ MembresiaDAO::buscarPorId(int idMembresia)
{
    return buscarMembresia(idMembresia);
}

// Lista el historial de membresías de un cliente.
List<Membresia^>^ MembresiaDAO::listarPorCliente(
    int idCliente)
{
    List<Membresia^>^ resultado =
        gcnew List<Membresia^>();

    List<Membresia^>^ lista = listarMembresias();

    for each (Membresia ^ m in lista)
    {
        if (m->getIdCliente() == idCliente)
            resultado->Add(m);
    }

    return resultado;
}

// Registra una nueva membresía.
bool MembresiaDAO::registrarMembresia(
    Membresia^ membresia)
{
    if (membresia == nullptr)
        return false;

    if (membresia->getIdMembresia() <= 0)
        return false;

    if (buscarMembresia(
        membresia->getIdMembresia()) != nullptr)
        return false;

    try
    {
        List<Membresia^>^ lista = listarMembresias();
        lista->Add(membresia);

        return guardarMembresias(lista);
    }
    catch (Exception^)
    {
        return false;
    }
}

// Modifica una membresía existente.
bool MembresiaDAO::modificarMembresia(
    Membresia^ membresia)
{
    if (membresia == nullptr)
        return false;

    List<Membresia^>^ lista = listarMembresias();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdMembresia() ==
            membresia->getIdMembresia())
        {
            int idClienteOriginal =
                lista[i]->getIdCliente();

            // Los formularios antiguos pueden construir
            // la membresía sin asignarle un cliente.
            if (membresia->getIdCliente() == 0)
            {
                membresia->setIdCliente(idClienteOriginal);
            }
            else if (idClienteOriginal != 0 &&
                membresia->getIdCliente() != idClienteOriginal)
            {
                // Impide cambiar el propietario existente.
                return false;
            }

            lista[i] = membresia;
            return guardarMembresias(lista);
        }
    }

    return false;
}

// Cancela una membresía sin eliminar su historial.
bool MembresiaDAO::cancelarMembresia(int idMembresia)
{
    List<Membresia^>^ lista = listarMembresias();

    for each (Membresia ^ m in lista)
    {
        if (m->getIdMembresia() == idMembresia)
        {
            if (!m->getActivo())
                return false;

            m->desactivar();
            return guardarMembresias(lista);
        }
    }

    return false;
}

// Eliminación física conservada del repositorio clonado.
bool MembresiaDAO::eliminarMembresia(int idMembresia)
{
    List<Membresia^>^ lista = listarMembresias();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdMembresia() == idMembresia)
        {
            lista->RemoveAt(i);
            return guardarMembresias(lista);
        }
    }

    return false;
}

// Obtiene el siguiente identificador disponible.
int MembresiaDAO::obtenerSiguienteId()
{
    List<Membresia^>^ lista = listarMembresias();

    int mayorId = 0;

    for each (Membresia ^ m in lista)
    {
        if (m->getIdMembresia() > mayorId)
            mayorId = m->getIdMembresia();
    }

    return mayorId + 1;
}
