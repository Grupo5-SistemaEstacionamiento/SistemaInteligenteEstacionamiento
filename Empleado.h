/**
 * Project AllaSistema
 */


#ifndef _EMPLEADO_H
#define _EMPLEADO_H

#include "Persona.h"


class Empleado: public Persona {
public: 
    
/**
 * @param codigoEmpleado
 * @param claveAcceso
 */
bool autenticar(void codigoEmpleado, void claveAcceso);
    
/**
 * @param enTurno
 * @param horaIngreso
 */
bool iniciarTurno(void enTurno, void horaIngreso);
    
/**
 * @param enTurno
 * @param horaSalida
 */
bool finalizarTurno(void enTurno, void horaSalida);
private: 
    codigoEmpleado: String;
    cargo: String;
    turno: String;
    claveAcceso: String;
    horaIngreso: DateTime;
    horaSalida: DateTime;
    fechaContratacion: DateTime;
    enTurno: bool;
};

#endif //_EMPLEADO_H