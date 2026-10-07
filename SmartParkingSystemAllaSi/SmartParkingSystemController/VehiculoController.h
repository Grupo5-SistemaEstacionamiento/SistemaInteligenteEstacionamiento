#pragma once

namespace SmartParkingSystemController {
	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemModel;
	using namespace System;

	public ref class VehiculoController {
	private:
		List<Vehiculo^>^ listaVehiculos;
	public:
		VehiculoController();
		List<Vehiculo^>^ buscarTodosMemoria();
		Vehiculo^ buscarxIdMemoria(int idVehiculo);
		void registrarMemoria(Vehiculo^ veh);
		void modificarMemoria(Vehiculo^ veh);
		void eliminarMemoria(int idVehiculo);

		// Archivo
		List<Vehiculo^>^ buscarTodosArchivo();
		Vehiculo^ buscarxIdArchivo(int idVehiculo);
		void registrarArchivo(Vehiculo^ veh);
		void modificarArchivo(Vehiculo^ veh);
		void eliminarArchivo(int idVehiculo);
	};

}
