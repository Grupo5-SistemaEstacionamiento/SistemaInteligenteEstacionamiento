/**
 * Project AllaSistema
 */


#ifndef _INDICADORLED_H
#define _INDICADORLED_H

#include "Periferico.h"


class IndicadorLed: public Periferico {
public: 
    
/**
 * @param id
 * @param ubi
 * @param fechaInstalacion
 */
void registrarLed(void id, void ubi, void fechaInstalacion);
    
/**
 * @param fechaUltMant
 */
DateTime registrarUltMant(void fechaUltMant);
    
bool requiereMant();
    
/**
 * @param color
 * @param intesidad
 * @param modoOperacion
 */
void configLed(void color, void intesidad, void modoOperacion);
    
void activar();
    
void desactivar();
    
string getColor();
    
/**
 * @param color
 */
void setColor(void color);
    
bool getEstaEncendido();
    
/**
 * @param estaEncendido
 */
void setEstaEncendido(void estaEncendido);
private: 
    color: String;
    intesidad: int;
    estaEncendido: bool;
    tipoLuz: String;
    modoOperacion: String;
};

#endif //_INDICADORLED_H