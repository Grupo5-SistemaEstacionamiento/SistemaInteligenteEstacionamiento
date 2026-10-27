#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SmartParkingSystemModel 
{	
	ref class Vehiculo;
	ref class Movimiento;

	public enum class TipoPenalizacion 
	{
		PERDIDA_TARJETA,
		TIEMPO_EXCEDIDO,
		ESPACIO_NO_AUTORIZADO,
		DANOS_ESTRUCTURALES,

	};

	public ref class Penalizacion 
	{
	private:

		int idPenalizacion;
		String^ placaVehiculo;
		TipoPenalizacion tipo;
		DateTime fechaHora;
		bool pagado;
		DateTime fechaPago;
		String^ motivo;
		double monto;

		Vehiculo^ vehiculo;
		List<Movimiento^>^ listaMovimientos;

	public:

		Penalizacion();
		Penalizacion(
			int idPenalizacion,
			TipoPenalizacion tipo,
			DateTime fechaHora,
			bool pagado,
			DateTime fechaPago,
			String^ motivo,
			double monto,

			Vehiculo^ vehiculo,
			List<Movimiento^>^ listaMovimientos
		);

		int getIdPenalizacion();
		String^ getPlacaVehiculo();
		TipoPenalizacion getTipo();
		DateTime getFechaHora();
		bool getPagado();
		DateTime getFechaPago();
		String^ getMotivo();
		double getMonto();

		Vehiculo^ getVehiculo();
		List<Movimiento^>^ getListaMovimientos();

		void setIdPenalizacion(int idPenalizacion);
		void setPlacaVehiculo(String^ placa);
		void setTipo(TipoPenalizacion tipo);
		void setFechaHora(DateTime fechaHora);
		void setPagado(bool pagado);
		void setFechaPago(DateTime fechaPago);
		void setMotivo(String^ motivo);
		void setMonto(double monto);

		void setVehiculo(Vehiculo^ vehiculo);
		void setListaMovimientos(List<Movimiento^>^ listaMovimientos);

		// Registra el pago de una penalización.
		bool registrarPagoPenalidad(DateTime fecha);
		// Indica si la penalización está pendiente de pago.
		bool estaPendiente();
	};
}
