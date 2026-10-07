#pragma once

namespace SmartParkingSystemModel {

	ref class Cliente;
	ref class RegistroAcceso;
	ref class Penalizacion;
	using namespace System;
	using namespace System::Collections::Generic;


	public enum class TipoVehiculo {

		automovil,
		motocicleta,
	};
	public ref class Vehiculo {


	private:
		int idVehiculo;
		String^ placa;
		String^ marca;
		String^ modelo;
		String^ color;
		TipoVehiculo tipo;
		String^ anotaciones;

		Cliente^ cliente;
		List<RegistroAcceso^>^ listaRegistros;
		List<Penalizacion^>^ listaPenlaizaciones;

	public:
		Vehiculo();
		Vehiculo(
			int idVehiculo,
			String^ placa,
			String^ marca,
			String^ modelo,
			String^ color,
			TipoVehiculo tipo,
			String^ anotaciones,

			Cliente^ cliente,
			List<RegistroAcceso^>^ listaRegistros,
			List<Penalizacion^>^ listaPenlaizaciones
		);

		int getIdVehiculo();
		String^ getPlaca();
		String^ getMarca();
		String^ getModelo();
		String^ getColor();
		TipoVehiculo getTipo();
		String^ getAnotaciones();


		Cliente^ getCliente();
		List<RegistroAcceso^>^ getListaRegistros();
		List<Penalizacion^>^ getListaPenlaizaciones();




		void setIdVehiculo(int idVehiculo);
		void setPlaca(String^ placa);
		void setMarca(String^ marca);
		void setModelo(String^ modelo);
		void setColor(String^ color);
		void setTipo(TipoVehiculo tipo);
		void setAnotaciones(String^ anotaciones);

		void setCliente(Cliente^ cliente);
		void setListaRegistros(List<RegistroAcceso^>^ listaRegistros);
		void setListaPenlaizaciones(List<Penalizacion^>^ listaPenlaizaciones);
	};
}