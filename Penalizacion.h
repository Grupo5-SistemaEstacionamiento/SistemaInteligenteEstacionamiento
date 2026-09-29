/**
 * Project AllaSistema
 */


#ifndef _PENALIZACION_H
#define _PENALIZACION_H

class Penalizacion {
public: 
    
/**
 * @param codigo
 * @param placa
 * @param tipo
 * @param fecha
 */
void nuevaPenalizacion(void codigo, void placa, void tipo, void fecha);
    
/**
 * @param fechaPago
 */
void actualizarEstadoPenal(void fechaPago);
private: 
    codigo: int;
    placa: string;
    tipo: TipoPenalizacion;
    fecha: date;
    cancelado: bool;
    fechaPago: date;
};

#endif //_PENALIZACION_H