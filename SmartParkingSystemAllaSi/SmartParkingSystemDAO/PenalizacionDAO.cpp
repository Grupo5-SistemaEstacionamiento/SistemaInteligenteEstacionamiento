#include "pch.h"
#include "PenalizacionDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

PenalizacionDAO::PenalizacionDAO()
{
	String^ rutaEjecucion = AppDomain::CurrentDomain->BaseDirectory;
	String^ rutaSolucion = Path::GetFullPath(Path::Combine(rutaEjecucion, "..\\..\\"));
	rutaArchivo = Path::Combine(rutaSolucion, "Data", "penalizaciones.txt");
	verificarDirectorio();
}

void PenalizacionDAO::verificarDirectorio()
{
	String^ directorioDatos = Path::GetDirectoryName(rutaArchivo);
	if (!Directory::Exists(directorioDatos)) {
		Directory::CreateDirectory(directorioDatos);
	}
}

bool PenalizacionDAO::guardarPenalizaciones(List<Penalizacion^>^ penalizaciones)
{
	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, false);
		for each (Penalizacion ^ p in penalizaciones) {
			// Formato: id|tipo|fechaHora|pagado|fechaPago|motivo|monto|vehiculoId
			escritor->WriteLine(
				p->getIdPenalizacion().ToString() + "|" +
				((int)p->getTipo()).ToString() + "|" +
				p->getFechaHora().ToString("o") + "|" +
				(p->getPagado() ? "1" : "0") + "|" +
				p->getFechaPago().ToString("o") + "|" +
				(p->getMotivo() == nullptr ? "" : p->getMotivo()) + "|" +
				p->getMonto().ToString("F2", CultureInfo::InvariantCulture) + "|" +
				(p->getVehiculo() == nullptr ? "0" : p->getVehiculo()->getIdVehiculo().ToString())
			);
		}
		escritor->Close();
		return true;
	}
	catch (Exception^) {
		return false;
	}
}

List<Penalizacion^>^ PenalizacionDAO::listarPenalizaciones()
{
	List<Penalizacion^>^ lista = gcnew List<Penalizacion^>();
	if (!File::Exists(rutaArchivo)) return lista;

	array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ campos = linea->Split('|');
		if (campos->Length < 7) continue;

		int id;
		int tipoInt;
		DateTime fechaHora;
		bool pagado;
		DateTime fechaPago;
		String^ motivo = campos[5];
		double monto;

		bool ok =
			Int32::TryParse(campos[0], id) &&
			Int32::TryParse(campos[1], tipoInt) &&
			DateTime::TryParse(campos[2], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaHora) &&
			Int32::TryParse(campos[3], tipoInt) && // reuse tipoInt variable temporarily
			DateTime::TryParse(campos[4], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaPago) &&
			Double::TryParse(campos[6], NumberStyles::Float, CultureInfo::InvariantCulture, monto);

		// Interpret pagado from campos[3]
		pagado = (campos[3] == "1");

		if (!ok) continue;

		Penalizacion^ p = gcnew Penalizacion(
			id,
			(TipoPenalizacion)tipoInt,
			fechaHora,
			pagado,
			fechaPago,
			motivo,
			monto,
			nullptr,
			nullptr
		);

		lista->Add(p);
	}

	return lista;
}

Penalizacion^ PenalizacionDAO::buscarPenalizacion(int idPenalizacion)
{
	List<Penalizacion^>^ lista = listarPenalizaciones();
	for each (Penalizacion ^ p in lista) {
		if (p->getIdPenalizacion() == idPenalizacion) return p;
	}
	return nullptr;
}

bool PenalizacionDAO::registrarPenalizacion(Penalizacion^ penalizacion)
{
	if (penalizacion == nullptr) return false;
	if (buscarPenalizacion(penalizacion->getIdPenalizacion()) != nullptr) return false;

	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, true);
		escritor->WriteLine(
			penalizacion->getIdPenalizacion().ToString() + "|" +
			((int)penalizacion->getTipo()).ToString() + "|" +
			penalizacion->getFechaHora().ToString("o") + "|" +
			(penalizacion->getPagado() ? "1" : "0") + "|" +
			penalizacion->getFechaPago().ToString("o") + "|" +
			(penalizacion->getMotivo() == nullptr ? "" : penalizacion->getMotivo()) + "|" +
			penalizacion->getMonto().ToString("F2", CultureInfo::InvariantCulture) + "|" +
			(penalizacion->getVehiculo() == nullptr ? "0" : penalizacion->getVehiculo()->getIdVehiculo().ToString())
		);
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

bool PenalizacionDAO::modificarPenalizacion(Penalizacion^ penalizacion)
{
	if (penalizacion == nullptr) return false;

	List<Penalizacion^>^ lista = listarPenalizaciones();
	bool encontrada = false;
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPenalizacion() == penalizacion->getIdPenalizacion()) {
			lista[i] = penalizacion;
			encontrada = true;
			break;
		}
	}

	if (!encontrada) return false;

	return guardarPenalizaciones(lista);
}

bool PenalizacionDAO::eliminarPenalizacion(int idPenalizacion)
{
	List<Penalizacion^>^ lista = listarPenalizaciones();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPenalizacion() == idPenalizacion) {
			lista->RemoveAt(i);
			return guardarPenalizaciones(lista);
		}
	}
	return false;
}

int PenalizacionDAO::obtenerSiguienteId()
{
	List<Penalizacion^>^ lista = listarPenalizaciones();
	int maxId = 0;
	for each (Penalizacion ^ p in lista) {
		if (p->getIdPenalizacion() > maxId) maxId = p->getIdPenalizacion();
	}
	return maxId + 1;
}
