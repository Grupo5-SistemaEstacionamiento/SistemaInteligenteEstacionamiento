#pragma once

namespace SmartParkingSystemModel {

	using namespace System;

	public enum class EstadoPeriferico {
		Activo,
		Desactivo,
		Averiado,
		Mantenimiento,
	};

	public ref class Periferico {

	private:

		int idPeriferico;
		String^ ubicacion;
		DateTime fechaInstalacion;
		DateTime fechaUltimoMant;
		EstadoPeriferico estado;
		bool hayEmergencia;

	public:

		Periferico();
		Periferico(
			int idPeriferico,
			String^ ubicacion,
			DateTime fechaInstalacion,
			DateTime fechaUltimoMant,
			EstadoPeriferico estado,
			bool hayEmergencia);

		int getIdPeriferico();
		String^ getUbicacion();
		DateTime getFechaInstalacion();
		DateTime getFechaUltimoMant();
		EstadoPeriferico getEstado();
		bool getHayEmergencia();

		void setIdPeriferico(int idPeriferico);
		void setUbicacion(String^ ubicacion);
		void setFechaInstalacion(DateTime fechaInstalacion);
		void setFechaUltimoMant(DateTime fechaUltimoMant);
		void setEstado(EstadoPeriferico estado);
		void setHayEmergencia(bool hayEmergencia);

	};


}