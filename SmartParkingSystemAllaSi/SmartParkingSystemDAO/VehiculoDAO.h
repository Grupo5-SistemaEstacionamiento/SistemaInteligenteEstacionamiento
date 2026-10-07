#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	public ref class VehiculoDAO {
	public:
		VehiculoDAO();
		List<Vehiculo^>^ buscarTodosArchivo();
		Vehiculo^ buscarxIdArchivo(int idVehiculo);
		void registrarVehiculoArchivo(Vehiculo^ veh);
		void modificarVehiculoArchivo(Vehiculo^ veh);
		void eliminarVehiculoArchivo(int idVehiculo);
		void escribirArchivo(List<Vehiculo^>^ listaVeh);
	};

}
