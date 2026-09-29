/**
 * Project AllaSistema
 */


#ifndef _TIPOPENALIZACION_H
#define _TIPOPENALIZACION_H

class TipoPenalizacion {
public: 
    
/**
 * @param codigo
 * @param descrip
 * @param montoAPagar
 */
void agregarTipo(void codigo, void descrip, void montoAPagar);
    
void revocarTipo();
private: 
    codigo: string;
    penalizacionNom: string;
    descripcion: string;
    montoAPagar: float;
    valido: bool;
};

#endif //_TIPOPENALIZACION_H