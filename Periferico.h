/**
 * Project AllaSistema
 */


#ifndef _PERIFERICO_H
#define _PERIFERICO_H

class Periferico {
public: 
    
/**
 * @param id
 * @param ubi
 * @param fechaInstalacion
 */
void registrarPeriferico(void id, void ubi, void fechaInstalacion);
    
void requiereMant();
    
/**
 * @param fechaUltMant
 */
DateTime registrarUltMant(void fechaUltMant);
    
/**
 * @param valorLectura
 */
double leerValoresLectura(void valorLectura);
    
double getCorrienteOperacion();
    
/**
 * @param corrienteOperacion
 */
void setCorrienteOperacion(void corrienteOperacion);
    
double getVoltajeOperacion();
    
/**
 * @param voltajeOperacion
 */
void setVoltajeOperacion(void voltajeOperacion);
private: 
    id: int;
    ubi: string;
    fechaInstalacion: DateTime;
    fechaUltMant: DateTime;
    estado: EstadoPeriferico;
    detectaVehiculo: bool;
    fechaUltLect: DateTime;
    voltajeOperacion: double;
    corrienteOperacion: double;
};

#endif //_PERIFERICO_H