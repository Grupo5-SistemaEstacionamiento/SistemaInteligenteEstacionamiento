/**
 * Project AllaSistema
 */


#ifndef _LECTORRFID_H
#define _LECTORRFID_H

#include "Periferico.h"


class LectorRFID: public Periferico {
public: 
    
void LectorRFID();
    
/**
 * @param atributos
 */
void LectorRFID(void atributos);
    
String getIdUltimaTarjeta();
    
/**
 * @param idUltimaTarjeta
 */
void setIdUltimaTarjeta(void idUltimaTarjeta);
    
bool getEsLecturaEntrada();
    
/**
 * @param esLecturaEntrada
 */
void setEsLecturaEntrada(void esLecturaEntrada);
    
/**
 * @param idTarjeta
 */
bool validarAccesoTarjeta(void idTarjeta);
private: 
    frecOperacion: double;
    distanciaLecturaMax: double;
    idUltimaTarjeta: String;
    protocoloComunicacion: String;
    esLecturaEntrada: bool;
    potenciaTransmision: double;
};

#endif //_LECTORRFID_H