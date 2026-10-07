#include "pch.h"
#include "MovimientoDAO.h"
#include "PagoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;

MovimientoDAO::MovimientoDAO() {

}

List<Movimiento^>^ MovimientoDAO::buscarTodosArchivo() {
	List<Movimiento^>^ lista = gcnew List<Movimiento^>();
	String^ path = "Movimientos.txt";
	if (!File::Exists(path)) return lista;
	for each (String^ line in File::ReadAllLines(path)) {
		if (String::IsNullOrWhiteSpace(line)) continue;
		array<String^>^ parts = line->Split(';');
		// Formato esperado: id;descripcion;monto;anulada;fechaISO;tipo;listaPagosIds(comma)
		int id = parts->Length > 0 && !String::IsNullOrWhiteSpace(parts[0]) ? Convert::ToInt32(parts[0]) : 0;
		String^ descripcion = parts->Length > 1 ? parts[1] : String::Empty;
		double monto = 0.0; try { monto = Convert::ToDouble(parts[2]); } catch (...) { monto = 0.0; }
		bool anulada = parts->Length > 3 && parts[3] == "1";
		DateTime fecha = DateTime::MinValue; try { fecha = DateTime::Parse(parts[4]); } catch (...) { fecha = DateTime::MinValue; }
		String^ tipo = parts->Length > 5 ? parts[5] : String::Empty;

		List<Pago^>^ listaPagos = gcnew List<Pago^>();
		if (parts->Length > 6 && !String::IsNullOrWhiteSpace(parts[6])) {
			array<String^>^ pagosIds = parts[6]->Split(',');
			PagoDAO^ pagoDao = gcnew PagoDAO();
			for each (String^ s in pagosIds) {
				try {
					int pid = Convert::ToInt32(s);
					Pago^ p = pagoDao->buscarxIdArchivo(pid);
					if (p != nullptr) listaPagos->Add(p);
				}
				catch (...) {}
			}
		}

		Movimiento^ m = gcnew Movimiento();
		m->setIdMovimiento(id);
		m->setDescripcion(descripcion);
		m->setMonto(monto);
		m->setAnulada(anulada);
		m->setFechaHoraMovimento(fecha);
		m->setTipoMovimiento(tipo);
		m->setListaPagos(listaPagos);
		m->setListaMembresias(gcnew List<Membresia^>());
		m->setListaRegistroAccesos(gcnew List<RegistroAcceso^>());
		m->setListaPenalizaciones(gcnew List<Penalizacion^>());

		lista->Add(m);
	}
	return lista;
}

Movimiento^ MovimientoDAO::buscarxIdArchivo(int idMovimiento) {
	List<Movimiento^>^ lista = buscarTodosArchivo();
	for each (Movimiento^ m in lista) if (m->getIdMovimiento() == idMovimiento) return m;
	return nullptr;
}

void MovimientoDAO::registrarMovimientoArchivo(Movimiento^ mov) {
	List<Movimiento^>^ lista = buscarTodosArchivo();
	lista->Add(mov);
	escribirArchivo(lista);
}

void MovimientoDAO::modificarMovimientoArchivo(Movimiento^ mov) {
	List<Movimiento^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdMovimiento() == mov->getIdMovimiento()) { lista[i] = mov; break; }
	}
	escribirArchivo(lista);
}

void MovimientoDAO::eliminarMovimientoArchivo(int idMovimiento) {
	List<Movimiento^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdMovimiento() == idMovimiento) { lista->RemoveAt(i); break; }
	}
	escribirArchivo(lista);
}

void MovimientoDAO::escribirArchivo(List<Movimiento^>^ listaMov) {
	List<String^>^ lines = gcnew List<String^>();
	for each (Movimiento^ m in listaMov) {
		// serializar listaPagos como ids separados por ','
		List<String^>^ pagosIds = gcnew List<String^>();
		for each (Pago^ p in m->getListaPagos()) pagosIds->Add(Convert::ToString(p->getIdPago()));
		String^ pagosStr = String::Join(",", pagosIds->ToArray());

		String^ l = String::Format("{0};{1};{2};{3};{4};{5};{6}",
			m->getIdMovimiento(), m->getDescripcion(), m->getMonto(), m->getAnulada() ? "1" : "0", m->getFechaHoraMovimento().ToString("o"), m->getTipoMovimiento(), pagosStr);
		lines->Add(l);
	}
	File::WriteAllLines("Movimientos.txt", lines->ToArray());
}
