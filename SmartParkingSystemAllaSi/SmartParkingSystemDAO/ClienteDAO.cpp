#include "pch.h"

#include "ClienteDAO.h"

using namespace System::IO;
using namespace SmartParkingSystemDAO;

// Obtiene la ruta común de persistencia de Clientes.
static String^ ObtenerRutaClientes()
{
    String^ directorio =
        AppDomain::CurrentDomain->BaseDirectory;

    while (true)
    {
        if (Directory::Exists(
            Path::Combine(
                directorio,
                "SmartParkingSystemModel")))
        {
            String^ carpetaDatos = Path::Combine(
                directorio, "Data", "TXT"
            );

            Directory::CreateDirectory(carpetaDatos);

            return Path::Combine(
                carpetaDatos, "clientes.txt"
            );
        }

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
}

ClienteDAO::ClienteDAO() {

}

List<Cliente^>^ ClienteDAO::buscarTodosArchivo() {
    List<Cliente^>^ lista = gcnew List<Cliente^>();
    if (!File::Exists(ObtenerRutaClientes())) return lista;

    array<String^>^ lineas = File::ReadAllLines(ObtenerRutaClientes());
    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;
        array<String^>^ datos = linea->Split(';');

        // Validamos que la línea tenga los 14 datos mínimos completos antes de leer
        if (datos->Length < 15) continue;

        // 1. Parseo de datos heredados de Persona
        int idPersona = 0; try { idPersona = Convert::ToInt32(datos[0]); }
        catch (...) {}
        String^ nombres = datos[1];
        String^ apellidos = datos[2];
        String^ documento = datos[3];
        String^ telefono = datos[4];
        String^ correo = datos[5];
        String^ claveHash = datos[6];
        DateTime fechaRegistro = DateTime::MinValue; try { fechaRegistro = DateTime::Parse(datos[7]); }
        catch (...) {}
        bool estado = (datos[8]->Equals("1") || datos[8]->ToLower()->Equals("true"));

        // 2. Parseo de datos propios de Cliente
        DateTime fechaAfiliacion = DateTime::MinValue; try { fechaAfiliacion = DateTime::Parse(datos[9]); }
        catch (...) {}
        TipoCliente tipo = static_cast<TipoCliente>(Convert::ToInt32(datos[10]));
        String^ observaciones = datos[11];
        double saldo = 0.0; try { saldo = Convert::ToDouble(datos[12]); }
        catch (...) {}
        bool requierePref = (datos[13]->Equals("1") || datos[13]->ToLower()->Equals("true"));
        String^ discapacidad = datos[14];

        // 3. Creación del objeto usando el constructor de 19 parámetros
        Cliente^ c = gcnew Cliente(
            idPersona, nombres, apellidos, documento, telefono, correo, fechaRegistro, estado, claveHash,
            fechaAfiliacion, tipo, observaciones, saldo, requierePref, discapacidad,
            nullptr, nullptr, nullptr, nullptr
        );
        lista->Add(c);
    }

    return lista;
}

Cliente^ ClienteDAO::buscarxIdArchivo(int idPersona) {
    List<Cliente^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdPersona() == idPersona) {
            return lista[i];
        }
    }
    return nullptr;
}

void ClienteDAO::registrarClienteArchivo(Cliente^ cliente) {
    List<Cliente^>^ lista = buscarTodosArchivo();
    lista->Add(cliente);
    escribirArchivo(lista);
}

void ClienteDAO::modificarClienteArchivo(int idPersona, Cliente^ clienteActualizado) {
    List<Cliente^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdPersona() == idPersona) {
            lista[i] = clienteActualizado;
            escribirArchivo(lista);
            return;
        }
    }
}

void ClienteDAO::eliminarClienteArchivos(int idPersona) {
    List<Cliente^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdPersona() == idPersona) {
            lista->RemoveAt(i);
            escribirArchivo(lista);
            return;
        }
    }
}

void ClienteDAO::escribirArchivo(List<Cliente^>^ listaClientes) {
    array<String^>^ lineas = gcnew array<String^>(listaClientes->Count);
    for (int i = 0; i < listaClientes->Count; i++) {
        Cliente^ c = listaClientes[i];

        // Empaquetado completo de los 14 atributos en una sola línea
        String^ lineaFormateada =
            c->getIdPersona() + ";" +
            c->getNombres() + ";" +
            c->getApellidos() + ";" +
            c->getDocumento() + ";" +
            c->getTelefono() + ";" +
            c->getCorreo() + ";" +
            c->getClaveHash() + ";" + 
            c->getFechaRegistro().ToString("o") + ";" +
            (c->getEstado() ? "1" : "0") + ";" +
            c->getFechaAfiliacion().ToString("o") + ";" +
            Convert::ToString((int)c->getTipo()) + ";" +
            c->getObservaciones() + ";" +
            Convert::ToString(c->getSaldo()) + ";" +
            (c->getRequierePreferencial() ? "1" : "0") + ";" +
            c->getDiscapacidad();

        lineas[i] = lineaFormateada;
    }
    File::WriteAllLines(ObtenerRutaClientes(), lineas);
}