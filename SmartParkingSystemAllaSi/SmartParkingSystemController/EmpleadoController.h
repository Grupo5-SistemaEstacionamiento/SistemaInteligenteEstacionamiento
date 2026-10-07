#pragma once

namespace SmartParkingSystemController {

	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemModel;
	using namespace System;

	public ref class EmpleadoController {
	private:
		List<Empleado^>^ listaEmpleados;

	public:
		/*Memoria*/
		EmpleadoController();
		List<Empleado^>^ buscarTodosMemoria();
		Empleado^ buscarxCodigoMemoria(String^ codigo);
		void registrarMemoria(Empleado^ empleado);
		void modificarMemoria(Empleado^ empleado);
		void eliminarMemoria(String^ codigo);

		/*Archivos*/
		List<Empleado^>^ buscarTodosArchivo();
		Empleado^ buscarxCodigoArchivo(String^ codigo);
		void registrarArchivo(Empleado^ empleado);
		void modificarArchivo(Empleado^ empleado);
		void eliminarArchivo(String^ codigo);
	};
}
