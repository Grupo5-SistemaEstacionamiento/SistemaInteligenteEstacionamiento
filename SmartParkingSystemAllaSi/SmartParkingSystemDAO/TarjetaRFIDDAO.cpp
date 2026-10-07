#include "pch.h"
#include "TarjetaRFIDDAO.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

TarjetaRFIDDAO::TarjetaRFIDDAO()
{
	String^ rutaEjecucion = AppDomain::CurrentDomain->BaseDirectory;
	String^ rutaSolucion = Path::GetFullPath(Path::Combine(rutaEjecucion, "..\\..\\"));
	rutaArchivo = Path::Combine(rutaSolucion, "Data", "tarjetas.txt");
	verificarDirectorio();
}

void TarjetaRFIDDAO::verificarDirectorio()
{
	String^ directorioDatos = Path::GetDirectoryName(rutaArchivo);
	if (!Directory::Exists(directorioDatos)) {
		Directory::CreateDirectory(directorioDatos);
	}
}

bool TarjetaRFIDDAO::guardarTarjetas(List<TarjetaRFID^>^ tarjetas)
{
	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, false);
		for each (TarjetaRFID ^ t in tarjetas) {
			// Formato: id|codigoUID|fechaEmision|fechaVencimiento|activa|clienteId
			escritor->WriteLine(
				t->getIdTarjeta().ToString() + "|" +
				(t->getCodigoUID() == nullptr ? "" : t->getCodigoUID()) + "|" +
				t->getFechaEmision().ToString("o") + "|" +
				t->getFechaVencimiento().ToString("o") + "|" +
				(t->getActiva() ? "1" : "0") + "|" +
				(t->getCliente() == nullptr ? "0" : t->getCliente()->getIdPersona().ToString())
			);
		}
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

List<TarjetaRFID^>^ TarjetaRFIDDAO::listarTarjetas()
{
	List<TarjetaRFID^>^ lista = gcnew List<TarjetaRFID^>();
	if (!File::Exists(rutaArchivo)) return lista;

	array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ campos = linea->Split('|');
		if (campos->Length < 6) continue;

		int id;
		String^ codigo = campos[1];
		DateTime fechaEmision;
		DateTime fechaVencimiento;
		bool activa;

		bool ok =
			Int32::TryParse(campos[0], id) &&
			DateTime::TryParse(campos[2], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaEmision) &&
			DateTime::TryParse(campos[3], CultureInfo::InvariantCulture, DateTimeStyles::None, fechaVencimiento);

		activa = (campos[4] == "1");

		if (!ok) continue;

		TarjetaRFID^ t = gcnew TarjetaRFID(
			id,
			codigo,
			fechaEmision,
			fechaVencimiento,
			activa,
			nullptr,
			nullptr
		);

		lista->Add(t);
	}

	return lista;
}

TarjetaRFID^ TarjetaRFIDDAO::buscarTarjeta(int idTarjeta)
{
	List<TarjetaRFID^>^ lista = listarTarjetas();
	for each (TarjetaRFID ^ t in lista) {
		if (t->getIdTarjeta() == idTarjeta) return t;
	}
	return nullptr;
}

bool TarjetaRFIDDAO::registrarTarjeta(TarjetaRFID^ tarjeta)
{
	if (tarjeta == nullptr) return false;
	if (buscarTarjeta(tarjeta->getIdTarjeta()) != nullptr) return false;

	try {
		StreamWriter^ escritor = gcnew StreamWriter(rutaArchivo, true);
		escritor->WriteLine(
			tarjeta->getIdTarjeta().ToString() + "|" +
			(tarjeta->getCodigoUID() == nullptr ? "" : tarjeta->getCodigoUID()) + "|" +
			tarjeta->getFechaEmision().ToString("o") + "|" +
			tarjeta->getFechaVencimiento().ToString("o") + "|" +
			(tarjeta->getActiva() ? "1" : "0") + "|" +
			(tarjeta->getCliente() == nullptr ? "0" : tarjeta->getCliente()->getIdPersona().ToString())
		);
		escritor->Close();
		return true;
	}
	catch (Exception^) { return false; }
}

bool TarjetaRFIDDAO::modificarTarjeta(TarjetaRFID^ tarjeta)
{
	if (tarjeta == nullptr) return false;
	List<TarjetaRFID^>^ lista = listarTarjetas();
	bool encontrada = false;
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdTarjeta() == tarjeta->getIdTarjeta()) {
			lista[i] = tarjeta;
			encontrada = true;
			break;
		}
	}
	if (!encontrada) return false;
	return guardarTarjetas(lista);
}

bool TarjetaRFIDDAO::eliminarTarjeta(int idTarjeta)
{
	List<TarjetaRFID^>^ lista = listarTarjetas();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdTarjeta() == idTarjeta) {
			lista->RemoveAt(i);
			return guardarTarjetas(lista);
		}
	}
	return false;
}

int TarjetaRFIDDAO::obtenerSiguienteId()
{
	List<TarjetaRFID^>^ lista = listarTarjetas();
	int maxId = 0;
	for each (TarjetaRFID ^ t in lista) {
		if (t->getIdTarjeta() > maxId) maxId = t->getIdTarjeta();
	}
	return maxId + 1;
}
