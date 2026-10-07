#pragma once


namespace SmartParkingSystemModel {

	using namespace System;

	public enum class MetodoPago {
		Efectivo,
		TarjetaCredito,
		TarjetaDebito,
		Transferencia,
		YapePlin
	};

	public ref class Pago {

	private:

		int idPago;
		String^ numeroComprovante;
		double montoTotal;
		MetodoPago metodoPago;
		DateTime fechaHora;


	public:



		Pago();
		Pago(int idPago,
			String^ numeroComprovante,
			double montoTotal,
			MetodoPago metodoPago,
			DateTime fechaHora);

		/*geters*/
		int         getIdPago();
		String^ getNumeroComprovante();
		double      getMontoTotal();
		MetodoPago getMetodoPago();
		DateTime    getFechaHora();

		/*seters*/
		void    setIdPago(int idPago);
		void    setNumeroComprovante(String^ numeroComprovante);
		void    setMontoTotal(double montoTotal);
		void    setMetodoPago(MetodoPago metodoPago);
		void    setFechaHora(DateTime fechaHora);

	};

}