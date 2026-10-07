#include "pch.h"
#include "VehiculoDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;

VehiculoDAO::VehiculoDAO() {

}

List<Vehiculo^>^ VehiculoDAO::buscarTodosArchivo() {
	List<Vehiculo^>^ lista = gcnew List<Vehiculo^>();
	String^ path = "Vehiculos.txt";
	if (!File::Exists(path)) return lista;
	for each (String^ line in File::ReadAllLines(path)) {
		if (String::IsNullOrWhiteSpace(line)) continue;
		array<String^>^ p = line->Split(';');
		int id = p->Length > 0 && !String::IsNullOrWhiteSpace(p[0]) ? Convert::ToInt32(p[0]) : 0;
		String^ placa = p->Length > 1 ? p[1] : String::Empty;
		String^ marca = p->Length > 2 ? p[2] : String::Empty;
		String^ modelo = p->Length > 3 ? p[3] : String::Empty;
		String^ color = p->Length > 4 ? p[4] : String::Empty;
		int tipoIdx = p->Length > 5 && !String::IsNullOrWhiteSpace(p[5]) ? Convert::ToInt32(p[5]) : 0;
		String^ anot = p->Length > 6 ? p[6] : String::Empty;

		Vehiculo^ v = gcnew Vehiculo();
		v->setIdVehiculo(id);
		v->setPlaca(placa);
		v->setMarca(marca);
		v->setModelo(modelo);
		v->setColor(color);
		v->setTipo(static_cast<TipoVehiculo>(tipoIdx));
		v->setAnotaciones(anot);
		lista->Add(v);
	}
	return lista;
}

Vehiculo^ VehiculoDAO::buscarxIdArchivo(int idVehiculo) {
	List<Vehiculo^>^ lista = buscarTodosArchivo();
	for each (Vehiculo^ v in lista) if (v->getIdVehiculo() == idVehiculo) return v;
	return nullptr;
}

void VehiculoDAO::registrarVehiculoArchivo(Vehiculo^ veh) {
	List<Vehiculo^>^ lista = buscarTodosArchivo();
	lista->Add(veh);
	escribirArchivo(lista);
}

void VehiculoDAO::modificarVehiculoArchivo(Vehiculo^ veh) {
	List<Vehiculo^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdVehiculo() == veh->getIdVehiculo()) { lista[i] = veh; break; }
	}
	escribirArchivo(lista);
}

void VehiculoDAO::eliminarVehiculoArchivo(int idVehiculo) {
	List<Vehiculo^>^ lista = buscarTodosArchivo();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->getIdVehiculo() == idVehiculo) { lista->RemoveAt(i); break; }
	}
	escribirArchivo(lista);
}

void VehiculoDAO::escribirArchivo(List<Vehiculo^>^ listaVeh) {
	List<String^>^ lines = gcnew List<String^>();
	for each (Vehiculo^ v in listaVeh) {
		String^ l = String::Format("{0};{1};{2};{3};{4};{5};{6}",
			v->getIdVehiculo(), v->getPlaca(), v->getMarca(), v->getModelo(), v->getColor(), Convert::ToString((int)v->getTipo()), v->getAnotaciones());
		lines->Add(l);
	}
	File::WriteAllLines("Vehiculos.txt", lines->ToArray());
}
