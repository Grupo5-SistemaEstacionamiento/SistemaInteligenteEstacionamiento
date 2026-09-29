/**
 * Project AllaSistema
 */


#ifndef _PAGO_H
#define _PAGO_H

class Pago {
public: 
    
/**
 * @param id
 * @param monto
 * @param tipo
 * @param fecha
 */
void registrarPago(void id, void monto, void tipo, void fecha);
private: 
    id: int;
    montoCuota: float;
    tipoPago: string;
    fechaHora: DateTime;
};

#endif //_PAGO_H