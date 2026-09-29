/**
 * Project AllaSistema
 */


#ifndef _SENSOROCUPACION_H
#define _SENSOROCUPACION_H

#include "Periferico.h"


class SensorOcupacion: public Periferico {
public: 
    
/**
 * @param id
 * @param ubi
 * @param fechaInstalacion
 */
void registrarSensor(void id, void ubi, void fechaInstalacion);
    
void requiereMant();
    
/**
 * @param fechaUltMant
 */
DateTime registrarUltMant(void fechaUltMant);
    
/**
 * @param valorLectura
 */
double leerValoresLectura(void valorLectura);
private: 
    umbralDeteccion: double;
    valorLectura: double;
    detectaVehiculo: bool;
    fechaUltLect: DateTime;
};

#endif //_SENSOROCUPACION_H