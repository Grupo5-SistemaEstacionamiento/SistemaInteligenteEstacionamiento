#include "pch.h"
#include "RegistroAccesoDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

RegistroAccesoDAO::RegistroAccesoDAO()
{
	String^ rutaEjecucion = AppDomain::CurrentDomain->BaseDirectory;
	String^ rutaSolucion = Path::GetFullPath(Path::Combine(rutaEjecucion, "..\\..\\"));
	rutaArchivo = Path::Combine(rutaSolucion, "Data", "registros_acceso.txt");
	verificarDirectorio();
}

void RegistroAccesoDAO::verificarDirectorio()
{
	String^ directorioDatos = Path::GetDirectoryName(rutaArchivo);
	if (!Directory::Exists(directorioDatos)) {
		Directory::CreateDirectory(directorioDatos);
	}
}

bool RegistroAccesoDAO::guardarRegistros(List<RegistroAcceso^>^ registros)
{
	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, false);
		for each (RegistroAcceso ^ r in registros) {
			// Formato: id|fechaIngreso|fechaSalida|accesoAutorizado|observacion|seHaPagado|montoTotal|espacioId|tarifaId|vehiculoId|empleadoId
			escritor->WriteLine(
				r->getIdRegistro().ToString() + "|" +
				r->getFechaHoraIngreso().ToString("o") + "|" +
				r->getFechaHoraSalida().ToString("o") + "|" +
				(r->getAccesoAutorizado() ? "1" : "0") + "|" +
				(r->getObservacion() == nullptr ? "" : r->getObservacion()) + "|" +
				(r->getSeHaPagado() ? "1" : "0") + "|" +
				r->getMontoTotalServicio().ToString("F2", CultureInfo::InvariantCulture) + "|" +
				"0|0|0|0"
			);
		}
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

List<RegistroAcceso^>^ RegistroAccesoDAO::listarRegistros()
{
	List<RegistroAcceso^>^ lista = gcnew List<RegistroAcceso^>();
	if (!File::Exists(rutaArchivo)) return lista;

	array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ campos = linea->Split('|');
		if (campos->Length < 7) continue;

		int id;
		DateTime fechaIngreso;
		DateTime fechaSalida;
		bool accesoAutorizado;
		String^ observacion = campos[4];
		bool seHaPagado;
		double monto;

		bool ok =
			Int32::TryParse(campos[0], id) &&
			DateTime::TryParse(campos[1], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaIngreso) &&
			DateTime::TryParse(campos[2], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaSalida) &&
			Double::TryParse(campos[6], NumberStyles::Float, CultureInfo::InvariantCulture, monto);

		accesoAutorizado = (campos[3] == "1");
		seHaPagado = (campos[5] == "1");

		if (!ok) continue;

		RegistroAcceso^ r = gcnew RegistroAcceso(
			id,
			fechaIngreso,
			fechaSalida,
			accesoAutorizado,
			observacion,
			seHaPagado,
			monto,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr
		);

		lista->Add(r);
	}

	return lista;
}

RegistroAcceso^ RegistroAccesoDAO::buscarRegistro(int idRegistro)
{
	List<RegistroAcceso^>^ lista = listarRegistros();
	for each (RegistroAcceso ^ r in lista) {
		if (r->getIdRegistro() == idRegistro) return r;
	}
	return nullptr;
}

bool RegistroAccesoDAO::registrarRegistro(RegistroAcceso^ registro)
{
	if (registro == nullptr) return false;
	if (buscarRegistro(registro->getIdRegistro()) != nullptr) return false;

	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, true);
		escritor->WriteLine(
			registro->getIdRegistro().ToString() + "|" +
			registro->getFechaHoraIngreso().ToString("o") + "|" +
			registro->getFechaHoraSalida().ToString("o") + "|" +
			(registro->getAccesoAutorizado() ? "1" : "0") + "|" +
			(registro->getObservacion() == nullptr ? "" : registro->getObservacion()) + "|" +
			(registro->getSeHaPagado() ? "1" : "0") + "|" +
			registro->getMontoTotalServicio().ToString("F2", CultureInfo::InvariantCulture) + "|" +
			"0|0|0|0"
		);
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

bool RegistroAccesoDAO::modificarRegistro(RegistroAcceso^ registro)
{
	if (registro == nullptr) return false;
	List<RegistroAcceso^>^ lista = listarRegistros();
	bool encontrada = false;
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdRegistro() == registro->getIdRegistro()) {
			lista[i] = registro;
			encontrada = true;
			break;
		}
	}
	if (!encontrada) return false;
	return guardarRegistros(lista);
}

bool RegistroAccesoDAO::eliminarRegistro(int idRegistro)
{
	List<RegistroAcceso^>^ lista = listarRegistros();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdRegistro() == idRegistro) {
			lista->RemoveAt(i);
			return guardarRegistros(lista);
		}
	}
	return false;
}

int RegistroAccesoDAO::obtenerSiguienteId()
{
	List<RegistroAcceso^>^ lista = listarRegistros();
	int maxId = 0;
	for each (RegistroAcceso ^ r in lista) {
		if (r->getIdRegistro() > maxId) maxId = r->getIdRegistro();
	}
	return maxId + 1;
}
