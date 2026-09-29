/**
 * Project AllaSistema
 */


#ifndef _MOVIMIENTO_H
#define _MOVIMIENTO_H

class Movimiento {
public: 
    
string imprimirComprobante();
    
/**
 * @param id
 * @param idTurno
 * @param descrip
 * @param monto
 */
void registrarMov(void id, void idTurno, void descrip, void monto);
    
void anularMov();
private: 
    id: int;
    idTurnoCaja: int;
    descripcionMov: string;
    montoTotal: float;
    anulada: bool;
    cuotas: List~Pago~;
};

#endif //_MOVIMIENTO_H