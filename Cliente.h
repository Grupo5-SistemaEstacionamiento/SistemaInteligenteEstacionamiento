/**
 * Project AllaSistema
 */


#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "Persona.h"


class Cliente: public Persona {
public: 
    
/**
 * @param Placa
 */
void registrarVehiculo(void Placa);
    
/**
 * @param observaciones
 * @param placa
 */
void consultarVehiculo(void observaciones, void placa);
    
/**
 * @param tarjeta
 */
void actualizarTarjetaVIgente(void tarjeta);
private: 
    Vehiculos: List~Vehiculo~;
    fechaAfiliacion: DateTime;
    tipo TipoCliente;
    cantidadVehiculos: int;
    observaciones: String;
    tarjeta: TarjetaRFID;
    memb: Membresia;
};

#endif //_CLIENTE_H