#include "pch.h"
#include "PagoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;
using namespace SmartParkingSystemModel;

PagoDAO::PagoDAO() {

}

List<Pago^>^ PagoDAO::buscarTodosArchivo() {
	List<Pago^>^ lista = gcnew List<Pago^>();
	String^ path = "Pagos.txt";
	if (!File::Exists(path)) return lista;
	for each (String^ line in File::ReadAllLines(path)) {
		if (String::IsNullOrWhiteSpace(line)) continue;
		array<String^>^ parts = line->Split(';');
		// Formato: idPago;numeroComprovante;montoTotal;metodoIndex;fechaISO
		int id = parts->Length > 0 && !String::IsNullOrWhiteSpace(parts[0]) ? Convert::ToInt32(parts[0]) : 0;
		String^ numero = parts->Length > 1 ? parts[1] : String::Empty;
		double monto = 0.0;
		try { monto = Convert::ToDouble(parts[2]); } catch (...) { monto = 0.0; }
		int metodoIndex = parts->Length > 3 && !String::IsNullOrWhiteSpace(parts[3]) ? Convert::ToInt32(parts[3]) : 0;
		DateTime fecha = DateTime::MinValue;
		try { fecha = DateTime::Parse(parts[4]); } catch (...) { fecha = DateTime::MinValue; }

		MetodoPago metodo = static_cast<MetodoPago>(metodoIndex);
		Pago^ pago = gcnew Pago(id, numero, monto, metodo, fecha);
		lista->Add(pago);
	}
	return lista;
}

Pago^ PagoDAO::buscarxIdArchivo(int idPago) {
	List<Pago^>^ lista = buscarTodosArchivo();
	for each (Pago^ p in lista) if (p->getIdPago() == idPago) return p;
	return nullptr;
}

void PagoDAO::registrarPagoArchivo(Pago^ pago) {
	List<Pago^>^ lista = buscarTodosArchivo();
	lista->Add(pago);
	escribirArchivo(lista);
}

void PagoDAO::modificarPagoArchivo(Pago^ pago) {
	List<Pago^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPago() == pago->getIdPago()) {
			lista[i] = pago; break;
		}
	}
	escribirArchivo(lista);
}

void PagoDAO::eliminarPagoArchivo(int idPago) {
	List<Pago^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdPago() == idPago) { lista->RemoveAt(i); break; }
	}
	escribirArchivo(lista);
}

void PagoDAO::escribirArchivo(List<Pago^>^ listaPagos) {
	List<String^>^ lines = gcnew List<String^>();
	for each (Pago^ p in listaPagos) {
		String^ l = String::Format("{0};{1};{2};{3};{4}",
			p->getIdPago(), p->getNumeroComprovante(), p->getMontoTotal(), Convert::ToString((int)p->getMetodoPago()), p->getFechaHora().ToString("o"));
		lines->Add(l);
	}
	File::WriteAllLines("Pagos.txt", lines->ToArray());
}

