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

		String^ claveHash; //de momento sera un simple string aunque seria bueno hablar con el profe para ver si hacemos la encriptacion


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
		    bool estado,
			String^ claveHash //Clave
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
		String^ getClaveHash(); //Clave

		/*seters*/
		void setIdPersona(int idPersona);
		void setNombres(String^ nombres);
		void setApellidos(String^ apellidos);
		void setDocumento(String^ documento);
		void setTelefono(String^ telefono);
		void setCorreo(String^ correo);
		void setFechaRegistro(DateTime fechaRegistro);
		void setEstado(bool estado);
		void setClaveHash(String^ claveHash); //Clave 

	};



}