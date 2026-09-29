/**
 * Project AllaSistema
 */


#ifndef _PERSONA_H
#define _PERSONA_H

class Persona {
public: 
    
/**
 * @param Telefono
 * @param correo
 */
void actualizarDatos(void Telefono, void correo);
    
void activar();
    
void desactivar();
    
String consultarDatos();
    
void registrar();
private: 
    idPersona: int;
    Nombres: String;
    Apellidos: String;
    Documento: String;
    Telefono: String;
    correo: String;
    fechaRegistro: DateTime;
    estado: bool;
};

#endif //_PERSONA_H