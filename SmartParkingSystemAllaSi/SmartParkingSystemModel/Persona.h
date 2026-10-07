#pragma once

namespace SmartParkingSystemModel {

	using namespace System; 
	public ref class Persona {

	private:
		int idPersona;
		String^ nombres;
		String^ apellidos;
		String^ documento;
		String^ telefono;
		String^ correo;
		DateTime fechaRegistro;
		bool estado;


	public:

		Persona();
		Persona(
			int idPersona,
		    String^ nombres,
		    String^ apellidos,
		    String^ documento,
		    String^ telefono,
		    String^ correo,
		    DateTime fechaRegistro,
		    bool estado
		);

		/*geters*/
		int getIdPersona();
		String^ getNombres();
		String^ getApellidos();
		String^ getDocumento();
		String^ getTelefono();
		String^ getCorreo();
		DateTime getFechaRegistro();
		bool getEstado();

		/*seters*/
		void setIdPersona(int idPersona);
		void setNombres(String^ nombres);
		void setNpellidos(String^ apellidos);
		void setDocumento(String^ documento);
		void setTelefono(String^ telefono);
		void setCorreo(String^ correo);
		void setFechaRegistro(DateTime fechaRegistro);
		void setEstado(bool estado);

	};



}