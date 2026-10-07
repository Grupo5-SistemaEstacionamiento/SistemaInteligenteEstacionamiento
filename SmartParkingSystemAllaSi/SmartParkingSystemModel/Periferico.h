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

		void getIdPeriferico(int idPeriferico);
		void getUbicacion(String^ ubicacion);
		void getFechaInstalacion(DateTime fechaInstalacion);
		void getFechaUltimoMant(DateTime fechaUltimoMant);
		void getEstado(EstadoPeriferico estado);
		void getHayEmergencia(bool hayEmergencia);

	};


}