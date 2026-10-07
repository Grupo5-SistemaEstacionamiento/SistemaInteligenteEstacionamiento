#include "pch.h"
#include "MembresiaDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

MembresiaDAO::MembresiaDAO()
{
	String^ rutaEjecucion = AppDomain::CurrentDomain->BaseDirectory;
	String^ rutaSolucion = Path::GetFullPath(Path::Combine(rutaEjecucion, "..\\..\\"));
	rutaArchivo = Path::Combine(rutaSolucion, "Data", "membresias.txt");
	verificarDirectorio();
}

void MembresiaDAO::verificarDirectorio()
{
	String^ directorioDatos = Path::GetDirectoryName(rutaArchivo);
	if (!Directory::Exists(directorioDatos)) {
		Directory::CreateDirectory(directorioDatos);
	}
}

bool MembresiaDAO::guardarMembresias(List<Membresia^>^ membresias)
{
	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, false);
		for each (Membresia ^ m in membresias) {
			// Formato: id|fechaInicio|fechaFin|porcentajeDescuento|activo|precio|tipo|clienteId
			escritor->WriteLine(
				m->getIdMembresia().ToString() + "|" +
				m->getFechaInicio().ToString("o") + "|" +
				m->getFechaFin().ToString("o") + "|" +
				m->getPorcentajeDescuento().ToString("F2", CultureInfo::InvariantCulture) + "|" +
				(m->getActivo() ? "1" : "0") + "|" +
				m->getPrecio().ToString("F2", CultureInfo::InvariantCulture) + "|" +
				((int)m->getTipo()).ToString() + "|" +
				(m->getCliente() == nullptr ? "0" : m->getCliente()->getIdPersona().ToString())
			);
		}
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

List<Membresia^>^ MembresiaDAO::listarMembresias()
{
	List<Membresia^>^ lista = gcnew List<Membresia^>();
	if (!File::Exists(rutaArchivo)) return lista;

	array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ campos = linea->Split('|');
		if (campos->Length < 7) continue;

		int id;
		DateTime fechaInicio;
		DateTime fechaFin;
		double porcentaje;
		bool activo;
		double precio;
		int tipoInt;

		bool ok =
			Int32::TryParse(campos[0], id) &&
			DateTime::TryParse(campos[1], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaInicio) &&
			DateTime::TryParse(campos[2], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaFin) &&
			Double::TryParse(campos[3], NumberStyles::Float, CultureInfo::InvariantCulture, porcentaje) &&
			Double::TryParse(campos[5], NumberStyles::Float, CultureInfo::InvariantCulture, precio) &&
			Int32::TryParse(campos[6], tipoInt);

		activo = (campos[4] == "1");

		if (!ok) continue;

		Membresia^ m = gcnew Membresia(
			id,
			fechaInicio,
			fechaFin,
			porcentaje,
			activo,
			precio,
			(TipoMembresia)tipoInt,
			nullptr,
			nullptr
		);

		lista->Add(m);
	}

	return lista;
}

Membresia^ MembresiaDAO::buscarMembresia(int idMembresia)
{
	List<Membresia^>^ lista = listarMembresias();
	for each (Membresia ^ m in lista) {
		if (m->getIdMembresia() == idMembresia) return m;
	}
	return nullptr;
}

bool MembresiaDAO::registrarMembresia(Membresia^ membresia)
{
	if (membresia == nullptr) return false;
	if (buscarMembresia(membresia->getIdMembresia()) != nullptr) return false;

	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, true);
		escritor->WriteLine(
			membresia->getIdMembresia().ToString() + "|" +
			membresia->getFechaInicio().ToString("o") + "|" +
			membresia->getFechaFin().ToString("o") + "|" +
			membresia->getPorcentajeDescuento().ToString("F2", CultureInfo::InvariantCulture) + "|" +
			(membresia->getActivo() ? "1" : "0") + "|" +
			membresia->getPrecio().ToString("F2", CultureInfo::InvariantCulture) + "|" +
			((int)membresia->getTipo()).ToString() + "|" +
			(membresia->getCliente() == nullptr ? "0" : membresia->getCliente()->getIdPersona().ToString())
		);
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

bool MembresiaDAO::modificarMembresia(Membresia^ membresia)
{
	if (membresia == nullptr) return false;
	List<Membresia^>^ lista = listarMembresias();
	bool encontrada = false;
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdMembresia() == membresia->getIdMembresia()) {
			lista[i] = membresia;
			encontrada = true;
			break;
		}
	}
	if (!encontrada) return false;
	return guardarMembresias(lista);
}

bool MembresiaDAO::eliminarMembresia(int idMembresia)
{
	List<Membresia^>^ lista = listarMembresias();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdMembresia() == idMembresia) {
			lista->RemoveAt(i);
			return guardarMembresias(lista);
		}
	}
	return false;
}

int MembresiaDAO::obtenerSiguienteId()
{
	List<Membresia^>^ lista = listarMembresias();
	int maxId = 0;
	for each (Membresia ^ m in lista) {
		if (m->getIdMembresia() > maxId) maxId = m->getIdMembresia();
	}
	return maxId + 1;
}
