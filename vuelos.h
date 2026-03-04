#ifndef VUELO_H
#define VUELO_H

#include <string>
using namespace std;

enum clase {EMERGENCIA, VIP, COMERCIAL, REPROGRAMADO, CANCELADO};
enum proceso {PROGRAMADO, EN_PISTA, FINALIZADO};
enum dias {LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO}; 

struct vuelos
{
    string aerolinea; //nombre de la empresa a la que pertenece el avión ARRAY STRING
    string ID; //código único de identificación Ej: AN123 (CLAVE PARA HASH)
    string origen; //ciudad de la que viene el vuelo ARRAY STRING
    string destino; //ciudad a la que se dirige el vuelo
    clase prioridad; //preferencia jerarquica del vuelo 
    proceso estado; //desarrollo del vuelo
    int horaProgramada; //Hora en la que debería estar en la pista del aeropuerto
    bool operacion; //false = DESPEGUE, true = ATERRIZAJE
    dias dia; //Día en que el avión está en la pista.
};

#endif
