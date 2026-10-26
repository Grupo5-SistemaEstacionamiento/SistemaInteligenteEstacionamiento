#include "pch.h"

#include "TarjetaRFID.h"
#include "Cliente.h"
#include "LectorRFID.h"

using namespace SmartParkingSystemModel;

// Constructor por defecto.
TarjetaRFID::TarjetaRFID()
{
    idTarjeta = 0;
    idCliente = 0;
    codigoUID = "";
    fechaEmision = DateTime::Now;
    fechaVencimiento = DateTime::Now;
    ultimoUso = DateTime::MinValue;
    activa = true;

    listaLecturas = gcnew List<LectorRFID^>();
    cliente = nullptr;
}

// Constructor original del repositorio clonado.
TarjetaRFID::TarjetaRFID(
    int idTarjeta,
    String^ codigoUID,
    DateTime fechaEmision,
    DateTime fechaVencimiento,
    bool activa,
    List<LectorRFID^>^ listaLecturas,
    Cliente^ cliente)
{
    this->idTarjeta = idTarjeta;
    this->codigoUID = codigoUID;
    this->fechaEmision = fechaEmision;
    this->fechaVencimiento = fechaVencimiento;
    this->ultimoUso = DateTime::MinValue;
    this->activa = activa;

    this->listaLecturas =
        listaLecturas == nullptr
        ? gcnew List<LectorRFID^>()
        : listaLecturas;

    this->cliente = cliente;
    this->idCliente =
        cliente == nullptr ? 0 : cliente->getIdPersona();
}

// Constructor para registrar una tarjeta nueva.
TarjetaRFID::TarjetaRFID(
    String^ codigoUID,
    DateTime fechaVencimiento)
{
    idTarjeta = 0;
    idCliente = 0;
    this->codigoUID = codigoUID;
    fechaEmision = DateTime::Now;
    this->fechaVencimiento = fechaVencimiento;
    ultimoUso = DateTime::MinValue;
    activa = true;

    listaLecturas = gcnew List<LectorRFID^>();
    cliente = nullptr;
}

// Getters.
int TarjetaRFID::getIdTarjeta()
{
    return idTarjeta;
}

int TarjetaRFID::getIdCliente()
{
    return idCliente;
}

String^ TarjetaRFID::getCodigoUID()
{
    return codigoUID;
}

DateTime TarjetaRFID::getFechaEmision()
{
    return fechaEmision;
}

DateTime TarjetaRFID::getFechaVencimiento()
{
    return fechaVencimiento;
}

DateTime TarjetaRFID::getUltimoUso()
{
    return ultimoUso;
}

bool TarjetaRFID::getActiva()
{
    return activa;
}

List<LectorRFID^>^ TarjetaRFID::getListaLecturas()
{
    return listaLecturas;
}

Cliente^ TarjetaRFID::getCliente()
{
    return cliente;
}

// Setters.
void TarjetaRFID::setIdTarjeta(int idTarjeta)
{
    this->idTarjeta = idTarjeta;
}

void TarjetaRFID::setIdCliente(int idCliente)
{
    this->idCliente = idCliente;

    if (cliente != nullptr &&
        cliente->getIdPersona() != idCliente)
    {
        cliente = nullptr;
    }
}

void TarjetaRFID::setCodigoUID(String^ codigoUID)
{
    this->codigoUID = codigoUID;
}

void TarjetaRFID::setFechaEmision(DateTime fechaEmision)
{
    this->fechaEmision = fechaEmision;
}

void TarjetaRFID::setFechaVencimiento(
    DateTime fechaVencimiento)
{
    this->fechaVencimiento = fechaVencimiento;
}

void TarjetaRFID::setUltimoUso(DateTime ultimoUso)
{
    this->ultimoUso = ultimoUso;
}

void TarjetaRFID::setActiva(bool activa)
{
    this->activa = activa;
}

void TarjetaRFID::setListaLecturas(
    List<LectorRFID^>^ listaLecturas)
{
    this->listaLecturas =
        listaLecturas == nullptr
        ? gcnew List<LectorRFID^>()
        : listaLecturas;
}

void TarjetaRFID::setCliente(Cliente^ cliente)
{
    this->cliente = cliente;

    if (cliente != nullptr)
        idCliente = cliente->getIdPersona();
}

// Indica si la tarjeta está activa.
bool TarjetaRFID::estaActiva()
{
    return activa;
}

// Comprueba que esté activa y no vencida.
bool TarjetaRFID::estaVigente()
{
    return activa &&
        DateTime::Now <= fechaVencimiento;
}

// Registra el último uso.
void TarjetaRFID::registrarUso()
{
    ultimoUso = DateTime::Now;
}

// Desactiva la tarjeta conservando su historial.
void TarjetaRFID::desactivar()
{
    activa = false;
}
