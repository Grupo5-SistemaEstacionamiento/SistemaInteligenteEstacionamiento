#pragma once
namespace SmartParkingSystemModel{
	using namespace System;
	ref class Movimiento;
	ref class Cliente;
	using namespace System::Collections::Generic;
	
	public enum class TipoMembresia {

		Regular,
		Premium,

	};

	public ref class Membresia{

	private:
		int idMembresia;
		DateTime fechaInicio;
		DateTime fechaFin;
		double porcentajeDescuento;
		bool activo;
		double precio;
		TipoMembresia tipo;
		List<Movimiento^>^ listaMovimientos;
		Cliente^ cliente;

	public:
		Membresia();
		Membresia(
			int idMembresia,
			DateTime fechaInicio,
			DateTime fechaFin,
			double porcentajeDescuento,
			bool activo,
			double precio,
			TipoMembresia tipo,

			List<Movimiento^>^ listaMovimientos,
		    Cliente^ cliente
		);

		int getIdMembresia();
		DateTime getFechaInicio();
		DateTime getFechaFin();
		double getPorcentajeDescuento();
		bool getActivo();
		double getPrecio();
		TipoMembresia getTipo();
		List<Movimiento^>^ getListaMovimientos();
		Cliente^ getCliente();


		void setIdMembresia(int idMembresia);
		void setFechaInicio(DateTime fechaInicio);
		void setFechaFin(DateTime fechaFin);
		void setPorcentajeDescuento(double porcentajeDescuento);
		void setActivo(bool activo);
		void setPrecio(double precio);
		void setTipo(TipoMembresia tipo);
		void setListaMovimientos(List<Movimiento^>^ listaMovimientos);
		void setCliente(Cliente^ cliente);

	};
}