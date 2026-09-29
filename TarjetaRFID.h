/**
 * Project AllaSistema
 */


#ifndef _TARJETARFID_H
#define _TARJETARFID_H

class TarjetaRFID {
public: 
    
/**
 * @param codigo
 * @param fechaEmision
 * @param fechaVenci
 */
void registrarTarjeta(void codigo, void fechaEmision, void fechaVenci);
    
void desactivarTarjeta();
private: 
    codigo: string;
    fechaEmision: DateTime;
    fechaVenci: DateTime;
    ultimoUso: DateTime;
    activa: bool;
};

#endif //_TARJETARFID_H