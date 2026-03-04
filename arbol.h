#ifndef ARBOL_H
#define ARBOL_H
//SIN CAMBIOS
#include "vuelos.h"

struct nodoArBin 
{
    vuelos dato;
    nodoArBin* izq;
    nodoArBin* der;
};

bool mayorPrioridad(vuelos a, vuelos b);

void insertarEnArBin(nodoArBin*& raiz, vuelos v);

vuelos extraerMasPrioritario(nodoArBin*& raiz);
#endif