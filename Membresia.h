/**
 * Project AllaSistema
 */


#ifndef _MEMBRESIA_H
#define _MEMBRESIA_H

class Membresia {
public: 
    
/**
 * @param id
 * @param tipo
 * @param inicio
 * @param duracion
 */
void agregarMembresia(void id, void tipo, void inicio, void duracion);
    
void desactivar();
private: 
    id: int;
    tipo: TipoMembresia;
    fechaInicio: date;
    fechaFin: date;
    duracionPlan: date;
    porcentajeDescento: float;
    activo: bool;
};

#endif //_MEMBRESIA_H