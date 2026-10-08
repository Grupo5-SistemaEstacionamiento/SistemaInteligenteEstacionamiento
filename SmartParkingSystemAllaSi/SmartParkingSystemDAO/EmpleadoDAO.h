#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	public ref class EmpleadoDAO {

	public:
		EmpleadoDAO();
		List<Empleado^>^ buscarTodosArchivo(); //Busca a todos los empleados en el archivo, y devuelve una lista de ellos
		Empleado^ buscarxCodigoArchivo(String^ codigo);
		void registrarEmpleadoArchivo(Empleado^ empleado);
		void modificarEmpleadoArchivo(Empleado^ empleado);
		void eliminarEmpleadoArchivos(String^ codigo);
		void escribirArchivo(List<Empleado^>^ listaEmpleados);
	};
}
