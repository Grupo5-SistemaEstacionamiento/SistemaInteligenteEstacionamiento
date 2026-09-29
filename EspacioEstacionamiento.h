/**
 * Project AllaSistema
 */


#ifndef _ESPACIOESTACIONAMIENTO_H
#define _ESPACIOESTACIONAMIENTO_H

class EspacioEstacionamiento {
public: 
    
/**
 * @param fila
 * @param grupo
 */
void crearCodigo(void fila, void grupo);
    
/**
 * @param tipoEst
 */
void describTipo(void tipoEst);
    
void actualizarDimensiones();
private: 
    codigo: string;
    tipo: TipoEstacionamiento;
    largo: double;
    ancho: double;
};

#endif //_ESPACIOESTACIONAMIENTO_H