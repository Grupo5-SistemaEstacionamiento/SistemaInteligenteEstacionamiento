#pragma once
#include "Pago.h"
#include "Membresia.h"
#include "RegistroAcceso.h"
#include "Penalizacion.h"

namespace SmartParkingSystemModel {

	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Movimiento {


	private:
		int idMovimiento;
		String^ descripcion;
		double monto;
		bool anulada;
		DateTime fechaHoraMovimento;
		String^ tipoMovimiento;
		List<Pago^>^ listaPagos;
		List<Membresia^>^ listaMembresias;
		List<RegistroAcceso^>^ listaRegistroAccesos;
		List<Penalizacion^>^ listaPenalizaciones;

	public:
		Movimiento();
		Movimiento(
			int idMovimiento,
			String^ descripcion,
			double monto,
			bool anulada,
			DateTime fechaHoraMovimento,
			String^ tipoMovimiento,
			List<Pago^>^ listaPagos,
			List<Membresia^>^ listaMembresias,
			List<RegistroAcceso^>^ listaRegistroAccesos,
			List<Penalizacion^>^ listaPenalizaciones
		);

		int getIdMovimiento();
		String^ getDescripcion();
		double getMonto();
		bool getAnulada();
		DateTime getFechaHoraMovimento();
		String^ getTipoMovimiento();
		List<Pago^>^ getListaPagos();
		List<Membresia^>^ getListaMembresias();
		List<RegistroAcceso^>^ getListaRegistroAccesos();
		List<Penalizacion^>^ getListaPenalizaciones();

		void setIdMovimiento(int idMovimiento);
		void setDescripcion(String^ descripcion);
		void setMonto(double monto);
		void setAnulada(bool anulada);
		void setFechaHoraMovimento(DateTime fechaHoraMovimento);
		void setTipoMovimiento(String^ tipoMovimiento);
		void setListaPagos(List<Pago^>^ listaPagos);
		void setListaMembresias(List<Membresia^>^ listaMembresias);
		void setListaRegistroAccesos(List<RegistroAcceso^>^ listaRegistroAccesos);
		void setListaPenalizaciones(List<Penalizacion^>^ listaPenalizaciones);


	};
}