#include "pch.h"

#include "Membresia.h"
#include "Cliente.h"

using namespace SmartParkingSystemModel;

// Constructor por defecto.
Membresia::Membresia()
{
    idMembresia = 0;
    idCliente = 0;
    fechaInicio = DateTime::Now;
    fechaFin = DateTime::Now;
    porcentajeDescuento = 0.0;
    activo = true;
    precio = 0.0;
    tipo = TipoMembresia::Regular;

    listaMovimientos = gcnew List<Movimiento^>();
    cliente = nullptr;
}

// Constructor original del repositorio clonado.
Membresia::Membresia(
    int idMembresia,
    DateTime fechaInicio,
    DateTime fechaFin,
    double porcentajeDescuento,
    bool activo,
    double precio,
    TipoMembresia tipo,
    List<Movimiento^>^ listaMovimientos,
    Cliente^ cliente)
{
    this->idMembresia = idMembresia;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->porcentajeDescuento = porcentajeDescuento;
    this->activo = activo;
    this->precio = precio;
    this->tipo = tipo;

    this->listaMovimientos =
        (listaMovimientos == nullptr)
        ? gcnew List<Movimiento^>()
        : listaMovimientos;

    this->cliente = cliente;
    this->idCliente =
        (cliente == nullptr) ? 0 : cliente->getIdPersona();
}

// Constructor compatible con el proyecto original.
Membresia::Membresia(
    int idMembresia,
    int idCliente,
    DateTime fechaInicio,
    DateTime fechaFin,
    double porcentajeDescuento,
    bool activo,
    double precio,
    TipoMembresia tipo)
{
    this->idMembresia = idMembresia;
    this->idCliente = idCliente;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->porcentajeDescuento = porcentajeDescuento;
    this->activo = activo;
    this->precio = precio;
    this->tipo = tipo;

    this->listaMovimientos = gcnew List<Movimiento^>();
    this->cliente = nullptr;
}

// Getters.
int Membresia::getIdMembresia()
{
    return idMembresia;
}

int Membresia::getIdCliente()
{
    return idCliente;
}

DateTime Membresia::getFechaInicio()
{
    return fechaInicio;
}

DateTime Membresia::getFechaFin()
{
    return fechaFin;
}

double Membresia::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}

bool Membresia::getActivo()
{
    return activo;
}

double Membresia::getPrecio()
{
    return precio;
}

TipoMembresia Membresia::getTipo()
{
    return tipo;
}

List<Movimiento^>^ Membresia::getListaMovimientos()
{
    return listaMovimientos;
}

Cliente^ Membresia::getCliente()
{
    return cliente;
}

// Setters.
void Membresia::setIdMembresia(int idMembresia)
{
    this->idMembresia = idMembresia;
}

void Membresia::setIdCliente(int idCliente)
{
    this->idCliente = idCliente;

    // Evita mantener un objeto Cliente de otro ID.
    if (cliente != nullptr &&
        cliente->getIdPersona() != idCliente)
    {
        cliente = nullptr;
    }
}

void Membresia::setFechaInicio(DateTime fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

void Membresia::setFechaFin(DateTime fechaFin)
{
    this->fechaFin = fechaFin;
}

void Membresia::setPorcentajeDescuento(
    double porcentajeDescuento)
{
    this->porcentajeDescuento = porcentajeDescuento;
}

void Membresia::setActivo(bool activo)
{
    this->activo = activo;
}

void Membresia::setPrecio(double precio)
{
    this->precio = precio;
}

void Membresia::setTipo(TipoMembresia tipo)
{
    this->tipo = tipo;
}

void Membresia::setListaMovimientos(
    List<Movimiento^>^ listaMovimientos)
{
    this->listaMovimientos =
        (listaMovimientos == nullptr)
        ? gcnew List<Movimiento^>()
        : listaMovimientos;
}

void Membresia::setCliente(Cliente^ cliente)
{
    this->cliente = cliente;

    // Mantiene sincronizado el identificador.
    if (cliente != nullptr)
    {
        this->idCliente = cliente->getIdPersona();
    }
    // Si se retira el objeto de memoria, se conserva
    // el ID persistido para no perder la asociación.
}

// Activa una membresía.
void Membresia::activar()
{
    activo = true;
}

// Cancela o desactiva una membresía.
void Membresia::desactivar()
{
    activo = false;
}

// Renueva una membresía.
void Membresia::renovarMembresia(DateTime nuevaFechaFin)
{
    if (nuevaFechaFin > fechaInicio)
    {
        fechaFin = nuevaFechaFin;
        activo = true;
    }
}
