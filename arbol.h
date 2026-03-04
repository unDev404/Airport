#ifndef ARBOL_H
#define ARBOL_H

#include "vuelos.h"

struct nodoArBin 
{
    vuelos dato;
    nodoArBin* izq;
    nodoArBin* der;
};

bool mayorPrioridad(vuelos a, vuelos b);
{
// COMPARAR POR DÍA
    if (a.dia < b.dia) return true; // Si el día de 'a' es antes, tiene prioridad
    if (a.dia > b.dia) return false; // Si el día de 'a' es después, no la tiene
// COMPARAR POR HORA SI LOS DÍAS SON IGUALES
    [cite_start]if (a.horaProgramada < b.horaProgramada) return true; [cite: 10]
    [cite_start]if (a.horaProgramada == b.horaProgramada) { [cite: 11]
        return a.prioridad < b.prioridad; [cite_start]// EMERGENCIA (0) es mayor que VIP (1) [cite: 11, 12]
    }
    [cite_start]return false; [cite: 13]
}

        
void insertarEnArBin(nodoArBin*& raiz, vuelos v);

vuelos extraerMasPrioritario(nodoArBin*& raiz);

#endif
