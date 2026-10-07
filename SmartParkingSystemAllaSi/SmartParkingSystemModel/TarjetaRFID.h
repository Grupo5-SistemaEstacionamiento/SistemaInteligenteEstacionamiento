#pragma once

namespace SmartParkingSystemModel {
	using namespace System;
	using namespace System::Collections::Generic;
	ref class LectorRFID;
	ref class Cliente;
	public ref class TarjetaRFID{

	private:

		int idTarjeta;
		String^ codigoUID;
		DateTime fechaEmision;
		DateTime fechaVencimiento;
		bool activa;

		List<LectorRFID^>^ listaLecturas;
		Cliente^ cliente;

	public:
		TarjetaRFID();
		TarjetaRFID(
			int idTarjeta,
			String^ codigoUID,
			DateTime fechaEmision,
			DateTime fechaVencimiento,
			bool activa,

			List<LectorRFID^>^ listaLecturas,
			Cliente^ cliente

		);

		int getIdTarjeta();
		String^ getCodigoUID();
		DateTime getFechaEmision();
		DateTime getFechaVencimiento();
		bool getActiva();

		List<LectorRFID^>^ getListaLecturas();
		Cliente^ getCliente();


		void setIdTarjeta(int idTarjeta);
		void setCodigoUID(String^ codigoUID);
		void setFechaEmision(DateTime fechaEmision);
		void setFechaVencimiento(DateTime fechaVencimiento);
		void setActiva(bool activa);

		void setListaLecturas(List<LectorRFID^>^ listaLecturas);
		void setCliente(Cliente^ cliente);
    };

}