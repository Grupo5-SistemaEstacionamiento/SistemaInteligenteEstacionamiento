#pragma once

namespace SmartParkingSystemController {

	using namespace System::Collections::Generic; //para usar la lista
	using namespace SmartParkingSystemModel; //para usar las propiedades de la clase Empleado
	using namespace System; //Para usar el string

	public ref class EmpleadoController {
	private:
		List<Empleado^>^ listaEmpleados; //Lista para trabajar con memoria

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
		List<Empleado^>^ listarEmpleadosArchivo();
		Empleado^ buscarxCodigoArchivo(String^ codigo);
		void registrarArchivo(Empleado^ empleado);
		void modificarArchivo(Empleado^ empleado);
		void eliminarArchivo(String^ codigo);
	};
}
