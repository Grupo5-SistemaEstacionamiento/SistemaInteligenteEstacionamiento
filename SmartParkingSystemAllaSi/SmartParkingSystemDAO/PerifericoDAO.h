
#pragma once

namespace SmartParkingSystemDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SmartParkingSystemModel;

	// ============================================================
	// CLASE: PerifericoDAO
	// ============================================================
	// Data Access Object (DAO) para las entidades Periferico y sus
	// subclases: IndicadorLed, ServoMotor, SensorOcupacion,
	// LectorRFID, BarreraAcceso.
	// Cada tipo se persistirá en su propio archivo de texto plano
	// ubicado en la carpeta de vistas (CocheraView).
	// Formato por archivo: una línea por objeto, campos separados
	// por ';'. Los campos y su orden deben coincidir con los
	// atributos de cada clase en SmartParkingSystemModel.
	public ref class PerifericoDAO {

	public:
		PerifericoDAO();

		// ---------- OPERACIONES PARA INDICADOR LED ----------
		List<IndicadorLed^>^ buscarTodosIndicadoresLedArchivo();
		IndicadorLed^ buscarIndicadorLedxIdArchivo(int idPeriferico);
		void registrarIndicadorLedArchivo(IndicadorLed^ led);
		void modificarIndicadorLedArchivo(IndicadorLed^ led);
		void eliminarIndicadorLedArchivo(int idPeriferico);
		void escribirIndicadoresLedArchivo(List<IndicadorLed^>^ lista);

		// ---------- OPERACIONES PARA SERVOMOTOR ----------
		List<ServoMotor^>^ buscarTodosServosArchivo();
		ServoMotor^ buscarServoMotorxIdArchivo(int idPeriferico);
		void registrarServoMotorArchivo(ServoMotor^ servo);
		void modificarServoMotorArchivo(ServoMotor^ servo);
		void eliminarServoMotorArchivo(int idPeriferico);
		void escribirServosArchivo(List<ServoMotor^>^ lista);

		// ---------- OPERACIONES PARA SENSOR DE OCUPACIÓN ----------
		List<SensorOcupacion^>^ buscarTodosSensoresOcupacionArchivo();
		SensorOcupacion^ buscarSensorOcupacionxIdArchivo(int idPeriferico);
		void registrarSensorOcupacionArchivo(SensorOcupacion^ sensor);
		void modificarSensorOcupacionArchivo(SensorOcupacion^ sensor);
		void eliminarSensorOcupacionArchivo(int idPeriferico);
		void escribirSensoresOcupacionArchivo(List<SensorOcupacion^>^ lista);

		// ---------- OPERACIONES PARA LECTOR RFID ----------
		List<LectorRFID^>^ buscarTodosLectoresRFIDArchivo();
		LectorRFID^ buscarLectorRFIDxIdArchivo(int idPeriferico);
		void registrarLectorRFIDArchivo(LectorRFID^ lector);
		void modificarLectorRFIDArchivo(LectorRFID^ lector);
		void eliminarLectorRFIDArchivo(int idPeriferico);
		void escribirLectoresRFIDArchivo(List<LectorRFID^>^ lista);

		// ---------- OPERACIONES PARA BARRERA DE ACCESO ----------
		List<BarreraAcceso^>^ buscarTodasBarrerasAccesoArchivo();
		BarreraAcceso^ buscarBarreraAccesoxIdArchivo(int idPeriferico);
		void registrarBarreraAccesoArchivo(BarreraAcceso^ barrera);
		void modificarBarreraAccesoArchivo(BarreraAcceso^ barrera);
		void eliminarBarreraAccesoArchivo(int idPeriferico);
		void escribirBarrerasAccesoArchivo(List<BarreraAcceso^>^ lista);
	};

}
