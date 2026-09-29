/**
 * Project AllaSistema
 */


#ifndef _VEHICULO_H
#define _VEHICULO_H

class Vehiculo {
public: 
    
/**
 * @param idVehiculo
 * @param placa
 * @param marca
 * @param fechaRegistro
 * @param color
 * @param modelo
 */
void registrar(void idVehiculo, void placa, void marca, void fechaRegistro, void color, void modelo);
    
/**
 * @param placa
 */
bool validarPlaca(void placa);
    
void activar();
    
void desactivar();
private: 
    idvehiculo: int;
    placa: String;
    marca: String;
    fechaRegistro: DateTime;
    color: String;
    modelo: String;
};

#endif //_VEHICULO_H