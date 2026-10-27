#include "pch.h"

#include "TurnoCajaDAO.h"
#include "EmpleadoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemModel;

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Globalization;
using namespace System::Collections::Generic;

// Constructor.
TurnoCajaDAO::TurnoCajaDAO()
{
    DirectoryInfo^ carpeta = gcnew DirectoryInfo(
        AppDomain::CurrentDomain->BaseDirectory);

    // Buscar la raíz que contiene los proyectos de la solución.
    while (carpeta != nullptr)
    {
        if (Directory::Exists(Path::Combine(
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
            "No se encontró la carpeta de SmartParkingSystem.");
    }

    rutaArchivo = Path::Combine(
        carpeta->FullName,
        "Data",
        "TXT",
        "turnosCaja.txt");

    verificarDirectorio();
}

// Crear carpeta y archivo cuando no existan.
void TurnoCajaDAO::verificarDirectorio()
{
    String^ directorio =
        Path::GetDirectoryName(rutaArchivo);

    Directory::CreateDirectory(directorio);

    if (!File::Exists(rutaArchivo))
    {
        File::WriteAllText(
            rutaArchivo,
            String::Empty,
            gcnew UTF8Encoding(false));
    }
}

// Recuperar todos los turnos.
List<TurnoCaja^>^ TurnoCajaDAO::buscarTodosArchivo()
{
    List<TurnoCaja^>^ lista = gcnew List<TurnoCaja^>();

    verificarDirectorio();

    array<String^>^ lineas = File::ReadAllLines(
        rutaArchivo, Encoding::UTF8);

    array<String^>^ formatos = gcnew array<String^>
    {
        "dd/MM/yyyy HH:mm:ss",
            "o"
    };

    for each (String ^ linea in lineas)
    {
        if (String::IsNullOrWhiteSpace(linea))
            continue;

        // Compatibilidad con archivos antiguos y nuevos.
        wchar_t separador = linea->Contains("|") ? '|' : ';';

        array<String^>^ datos = linea->Split(separador);

        if (datos->Length != 8)
        {
            throw gcnew FormatException(
                "Registro de turno con número de campos incorrecto.");
        }

        int id = Int32::Parse(datos[0]);

        DateTime ingreso;
        DateTime salida = DateTime::MinValue;

        // Leer fechas antiguas ISO 8601 con zona horaria
        // y fechas nuevas en formato dd/MM/yyyy.
        if (!DateTime::TryParseExact(
            datos[1],
            formatos,
            CultureInfo::InvariantCulture,
            DateTimeStyles::RoundtripKind,
            ingreso))
        {
            throw gcnew FormatException(
                L"Fecha de ingreso incorrecta en turno " +
                datos[0]);
        }

        // Un turno abierto puede tener SIN_CIERRE.
        if (!String::IsNullOrWhiteSpace(datos[2]) &&
            !String::Equals(
                datos[2],
                "SIN_CIERRE",
                StringComparison::OrdinalIgnoreCase))
        {
            if (!DateTime::TryParseExact(
                datos[2],
                formatos,
                CultureInfo::InvariantCulture,
                DateTimeStyles::RoundtripKind,
                salida))
            {
                throw gcnew FormatException(
                    L"Fecha de salida incorrecta en turno " +
                    datos[0]);
            }
        }

        double saldoInicial = Double::Parse(
            datos[3], CultureInfo::InvariantCulture);

        double saldoFinal = Double::Parse(
            datos[4], CultureInfo::InvariantCulture);

        String^ observacion = datos[5];
        String^ estado = datos[6];
        String^ codigoEmpleado = datos[7];

        EmpleadoDAO^ empleadoDAO = gcnew EmpleadoDAO();

        Empleado^ empleado =
            empleadoDAO->buscarxCodigoArchivo(codigoEmpleado);

        if (empleado == nullptr)
        {
            throw gcnew InvalidDataException(
                "No se encontró el empleado del turno " +
                id.ToString() + ".");
        }

        TurnoCaja^ turno = gcnew TurnoCaja(
            id,
            ingreso,
            salida,
            saldoInicial,
            saldoFinal,
            observacion,
            estado,
            nullptr,
            empleado);

        lista->Add(turno);
    }

    return lista;
}

// Buscar por ID.
TurnoCaja^ TurnoCajaDAO::buscarxIdArchivo(int idTurno)
{
    for each (TurnoCaja ^ turno in buscarTodosArchivo())
    {
        if (turno->getIdTurno() == idTurno)
            return turno;
    }

    return nullptr;
}

// Registrar turno sin duplicar ID.
void TurnoCajaDAO::registrarTurnoArchivo(TurnoCaja^ turno)
{
    if (turno == nullptr)
        throw gcnew ArgumentNullException("turno");

    List<TurnoCaja^>^ lista = buscarTodosArchivo();

    for each (TurnoCaja ^ existente in lista)
    {
        if (existente->getIdTurno() == turno->getIdTurno())
        {
            throw gcnew InvalidOperationException(
                "Ya existe un turno con ese ID.");
        }
    }

    lista->Add(turno);
    escribirArchivo(lista);
}

// Modificar turno existente.
void TurnoCajaDAO::modificarTurnoArchivo(TurnoCaja^ turno)
{
    if (turno == nullptr)
        throw gcnew ArgumentNullException("turno");

    List<TurnoCaja^>^ lista = buscarTodosArchivo();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdTurno() == turno->getIdTurno())
        {
            lista[i] = turno;
            escribirArchivo(lista);
            return;
        }
    }

    throw gcnew InvalidOperationException(
        "No se encontró el turno que desea modificar.");
}

// Eliminar turno existente.
void TurnoCajaDAO::eliminarTurnoArchivos(int idTurno)
{
    List<TurnoCaja^>^ lista = buscarTodosArchivo();

    for (int i = 0; i < lista->Count; i++)
    {
        if (lista[i]->getIdTurno() == idTurno)
        {
            lista->RemoveAt(i);
            escribirArchivo(lista);
            return;
        }
    }

    throw gcnew InvalidOperationException(
        "No se encontró el turno que desea eliminar.");
}

// Guardar todos los turnos.
void TurnoCajaDAO::escribirArchivo(
    List<TurnoCaja^>^ listaTurnos)
{
    verificarDirectorio();

    List<String^>^ lineas = gcnew List<String^>();

    for each (TurnoCaja ^ turno in listaTurnos)
    {
        if (turno == nullptr || turno->getEmpleado() == nullptr)
        {
            throw gcnew InvalidOperationException(
                "El turno debe tener un empleado asociado.");
        }

        String^ codigo =
            turno->getEmpleado()->getCodigoEmpleado();

        if (String::IsNullOrWhiteSpace(codigo))
        {
            throw gcnew InvalidOperationException(
                "El empleado no tiene código válido.");
        }

        String^ observacion = turno->getObservacion();

        if (String::IsNullOrEmpty(observacion))
            observacion = String::Empty;

        if (observacion->Contains("|") ||
            codigo->Contains("|"))
        {
            throw gcnew ArgumentException(
                "Los campos no pueden contener el carácter |.");
        }

        String^ ingreso = turno->getFechaHoraIngreso().ToString(
            "dd/MM/yyyy HH:mm:ss",
            CultureInfo::InvariantCulture);

        String^ salida = turno->getEstado() == "Cerrado"
            ? turno->getFechaHoraSalida().ToString(
                "dd/MM/yyyy HH:mm:ss",
                CultureInfo::InvariantCulture)
            : String::Empty;

        String^ linea =
            turno->getIdTurno().ToString() + "|" +
            ingreso + "|" +
            salida + "|" +
            turno->getSaldoInicial().ToString(
                "F2", CultureInfo::InvariantCulture) + "|" +
            turno->getSaldoFinal().ToString(
                "F2", CultureInfo::InvariantCulture) + "|" +
            observacion + "|" +
            turno->getEstado() + "|" +
            codigo;

        lineas->Add(linea);
    }

    // Escribir primero un archivo temporal para evitar
    // truncar el archivo principal si falla la escritura.
    String^ temporal = rutaArchivo + ".tmp";

    File::WriteAllLines(
        temporal,
        lineas->ToArray(),
        gcnew UTF8Encoding(false));

    if (File::Exists(rutaArchivo))
        File::Replace(temporal, rutaArchivo, nullptr);
    else
        File::Move(temporal, rutaArchivo);
}

// Siguiente ID.
int TurnoCajaDAO::obtenerSiguienteId()
{
    int mayor = 0;

    for each (TurnoCaja ^ turno in buscarTodosArchivo())
    {
        if (turno->getIdTurno() > mayor)
            mayor = turno->getIdTurno();
    }

    return mayor + 1;
}

// Buscar turno que sigue abierto.
TurnoCaja^ TurnoCajaDAO::buscarTurnoAbierto()
{
    for each (TurnoCaja ^ turno in buscarTodosArchivo())
    {
        if (String::Equals(
            turno->getEstado(), "Abierto",
            StringComparison::OrdinalIgnoreCase))
        {
            return turno;
        }
    }

    return nullptr;
}
