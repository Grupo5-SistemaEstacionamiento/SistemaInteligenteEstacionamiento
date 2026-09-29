/**
 * Project AllaSistema
 */


#ifndef _TURNOCAJA_H
#define _TURNOCAJA_H

class TurnoCaja {
public: 
    
/**
 * @param id
 * @param apertura
 * @param operario
 * @param saldoInicial
 */
void registrarApertura(void id, void apertura, void operario, void saldoInicial);
    
/**
 * @param observacion
 */
void declararObs(void observacion);
    
/**
 * @param estado
 */
void actualizarEstadoCaja(void estado);
    
/**
 * @param movimiento
 */
void registrarMovimiento(void movimiento);
    
/**
 * @param cierre
 * @param saldoFinal
 */
void registrarCierre(void cierre, void saldoFinal);
private: 
    id: int;
    apertura: date;
    cierre: date;
    operario: string;
    saldoInicial: float;
    saldoFinal: float;
    observacion: string;
    estado: string;
    movimientos: List~Movimiento~;
};

#endif //_TURNOCAJA_H