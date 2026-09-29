/**
 * Project AllaSistema
 */


#ifndef _REGISTROAFORO_H
#define _REGISTROAFORO_H

class RegistroAforo {
public: 
    
/**
 * @param id
 * @param tarjetaEnUso
 * @param horaIngreso
 */
void registrarEntrada(void id, void tarjetaEnUso, void horaIngreso);
    
/**
 * @param horaIntentoIngreso
 * @param razonAccesoNegado
 */
void registrarAccesoNegado(void horaIntentoIngreso, void razonAccesoNegado);
    
/**
 * @param horaSalida
 * @param espacioOcupado
 */
void registrarSalida(void horaSalida, void espacioOcupado);
private: 
    id: int;
    tarjetaEnUso: string;
    horaIngreso: DateTime;
    horaSalida: DateTime;
    espacioOcupado: string;
    acessoAutorizado: bool;
    horaIntentoIngreso: DateTime;
    razonAccesoNegado: string;
};

#endif //_REGISTROAFORO_H