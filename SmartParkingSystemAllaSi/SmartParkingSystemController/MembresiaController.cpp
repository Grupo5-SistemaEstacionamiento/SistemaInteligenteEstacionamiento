#include "pch.h"

#include "MembresiaController.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemController;

// Constructor.
MembresiaController::MembresiaController()
{
    membresiaDAO = gcnew MembresiaDAO();
    clienteDAO = gcnew ClienteDAO();
}

// =====================================================
// MÉTODOS EXISTENTES DEL REPOSITORIO CLONADO
// =====================================================

// Lista todas las membresías.
List<Membresia^>^ MembresiaController::listarMembresias()
{
    return membresiaDAO->listarMembresias();
}

// Busca una membresía por ID.
Membresia^ MembresiaController::buscarMembresia(
    int idMembresia)
{
    if (idMembresia <= 0)
        return nullptr;

    return membresiaDAO->buscarMembresia(idMembresia);
}

// Registro utilizado por los formularios del compañero.
bool MembresiaController::registrarMembresia(
    DateTime fechaInicio,
    DateTime fechaFin,
    double porcentajeDescuento,
    bool activo,
    double precio,
    int tipo)
{
    if (fechaFin <= fechaInicio)
        return false;

    if (porcentajeDescuento < 0 ||
        porcentajeDescuento > 100)
        return false;

    if (precio < 0)
        return false;

    int id = obtenerSiguienteId();

    Membresia^ m = gcnew Membresia(
        id,
        fechaInicio,
        fechaFin,
        porcentajeDescuento,
        activo,
        precio,
        (TipoMembresia)tipo,
        nullptr,
        nullptr
    );

    return membresiaDAO->registrarMembresia(m);
}

// Modificación utilizada por el repositorio clonado.
bool MembresiaController::modificarMembresia(
    int idMembresia,
    DateTime fechaInicio,
    DateTime fechaFin,
    double porcentajeDescuento,
    bool activo,
    double precio,
    int tipo)
{
    Membresia^ original = buscarMembresia(idMembresia);

    if (original == nullptr)
        return false;

    if (fechaFin <= fechaInicio)
        return false;

    if (porcentajeDescuento < 0 ||
        porcentajeDescuento > 100)
        return false;

    if (precio < 0)
        return false;

    Membresia^ m = gcnew Membresia(
        idMembresia,
        fechaInicio,
        fechaFin,
        porcentajeDescuento,
        activo,
        precio,
        (TipoMembresia)tipo,
        original->getListaMovimientos(),
        original->getCliente()
    );

    // Conserva el ID del cliente al reconstruir el objeto.
    m->setIdCliente(original->getIdCliente());

    return membresiaDAO->modificarMembresia(m);
}

// Eliminación física existente del repositorio.
bool MembresiaController::eliminarMembresia(
    int idMembresia)
{
    if (idMembresia <= 0)
        return false;

    if (buscarMembresia(idMembresia) == nullptr)
        return false;

    return membresiaDAO->eliminarMembresia(idMembresia);
}

// Genera el siguiente ID.
int MembresiaController::obtenerSiguienteId()
{
    return membresiaDAO->obtenerSiguienteId();
}

// =====================================================
// MÉTODOS COMPATIBLES CON LOS FORMULARIOS INTEGRADOS
// =====================================================

// Lista todos los clientes del archivo.
List<Cliente^>^ MembresiaController::listarClientes()
{
    return clienteDAO->buscarTodosArchivo();
}

// Busca clientes por nombre, apellido o documento.
List<Cliente^>^ MembresiaController::buscarClientes(
    String^ criterio)
{
    List<Cliente^>^ resultados =
        gcnew List<Cliente^>();

    List<Cliente^>^ clientes =
        clienteDAO->buscarTodosArchivo();

    if (String::IsNullOrWhiteSpace(criterio))
        return clientes;

    String^ texto = criterio->Trim();

    for each (Cliente ^ c in clientes)
    {
        if (c == nullptr)
            continue;

        String^ nombres =
            c->getNombres() == nullptr
            ? "" : c->getNombres();

        String^ apellidos =
            c->getApellidos() == nullptr
            ? "" : c->getApellidos();

        String^ documento =
            c->getDocumento() == nullptr
            ? "" : c->getDocumento();

        // Búsqueda por prefijo, sin distinguir mayúsculas.
        bool coincide =
            nombres->StartsWith(
                texto,
                StringComparison::OrdinalIgnoreCase) ||
            apellidos->StartsWith(
                texto,
                StringComparison::OrdinalIgnoreCase) ||
            documento->StartsWith(
                texto,
                StringComparison::OrdinalIgnoreCase);

        if (coincide)
            resultados->Add(c);
    }

    return resultados;
}

// Busca un cliente mediante su identificador.
Cliente^ MembresiaController::buscarClientePorId(
    int idCliente)
{
    if (idCliente <= 0)
        return nullptr;

    return clienteDAO->buscarxIdArchivo(idCliente);
}

// Obtiene el historial de membresías de un cliente.
List<Membresia^>^
MembresiaController::listarMembresiasPorCliente(
    int idCliente)
{
    return membresiaDAO->listarPorCliente(idCliente);
}

// Registra una membresía recibida como objeto.
bool MembresiaController::registrarMembresia(
    Membresia^ membresia)
{
    if (membresia == nullptr)
        return false;

    if (membresia->getIdMembresia() <= 0)
        return false;

    if (membresia->getFechaFin() <=
        membresia->getFechaInicio())
        return false;

    if (membresia->getPrecio() < 0)
        return false;

    if (membresia->getPorcentajeDescuento() < 0 ||
        membresia->getPorcentajeDescuento() > 100)
        return false;

    Cliente^ cliente = buscarClientePorId(
        membresia->getIdCliente()
    );

    if (cliente == nullptr)
        return false;

    // Un cliente no puede tener dos membresías activas.
    if (clienteTieneMembresiaActiva(
        membresia->getIdCliente()))
        return false;

    // Conserva la relación con el objeto Cliente.
    membresia->setCliente(cliente);

    return membresiaDAO->registrarMembresia(membresia);
}

// Modifica una membresía recibida como objeto.
bool MembresiaController::modificarMembresia(
    Membresia^ membresia)
{
    if (membresia == nullptr)
        return false;

    Membresia^ original =
        membresiaDAO->buscarPorId(
            membresia->getIdMembresia()
        );

    if (original == nullptr)
        return false;

    // No permite editar membresías canceladas.
    if (!original->getActivo())
        return false;

    // El cliente asociado no puede cambiarse.
    if (original->getIdCliente() !=
        membresia->getIdCliente())
        return false;

    if (membresia->getFechaFin() <=
        membresia->getFechaInicio())
        return false;

    if (membresia->getPrecio() < 0)
        return false;

    if (membresia->getPorcentajeDescuento() < 0 ||
        membresia->getPorcentajeDescuento() > 100)
        return false;

    Cliente^ cliente = buscarClientePorId(
        original->getIdCliente()
    );

    if (cliente == nullptr)
        return false;

    // Conserva las relaciones del modelo clonado.
    membresia->setCliente(cliente);
    membresia->setListaMovimientos(
        original->getListaMovimientos()
    );

    return membresiaDAO->modificarMembresia(membresia);
}

// Cancela una membresía conservando su historial.
bool MembresiaController::cancelarMembresia(
    int idMembresia)
{
    if (idMembresia <= 0)
        return false;

    Membresia^ m = membresiaDAO->buscarPorId(idMembresia);

    if (m == nullptr || !m->getActivo())
        return false;

    return membresiaDAO->cancelarMembresia(idMembresia);
}

// Busca una membresía por ID.
Membresia^ MembresiaController::buscarMembresiaPorId(
    int idMembresia)
{
    if (idMembresia <= 0)
        return nullptr;

    return membresiaDAO->buscarPorId(idMembresia);
}

// Comprueba si el cliente tiene una membresía activa.
bool MembresiaController::clienteTieneMembresiaActiva(
    int idCliente)
{
    if (idCliente <= 0)
        return false;

    List<Membresia^>^ lista =
        membresiaDAO->listarPorCliente(idCliente);

    for each (Membresia ^ m in lista)
    {
        if (m->getActivo())
            return true;
    }

    return false;
}

// Obtiene el estado visible de una membresía.
String^ MembresiaController::obtenerEstadoMembresia(
    Membresia^ membresia)
{
    if (membresia == nullptr)
        return "";

    if (!membresia->getActivo())
        return "Cancelada";

    if (membresia->getFechaFin().Date < DateTime::Today)
        return "Vencida";

    return "Activa";
}
