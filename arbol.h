#ifndef ARBOL.H
#define ARBOL.H

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