/**
 * Project AllaSistema
 */


#ifndef _BARRERAACCESO_H
#define _BARRERAACCESO_H

#include "Periferico.h"


class BarreraAcceso: public Periferico {
public: 
    
void BarreraAcceso();
    
/**
 * @param atributos
 */
void BarreraAcceso(void atributos);
    
double getAnguloActual();
    
/**
 * @param anguloActual
 */
void setAnguloActual(void anguloActual);
    
bool getEstaAbierta();
    
/**
 * @param estaAbierta
 */
void setEstaAbierta(void estaAbierta);
    
void abrirBarrera();
    
void cerrarBarrera();
private: 
    anguloActual: double;
    anguloMaxApertura: double;
    estaAbierta: bool;
    tiempoApertura: double;
    torque: double;
    estaBloqueada: bool;
    esCarrilEntrada: bool;
};

#endif //_BARRERAACCESO_H