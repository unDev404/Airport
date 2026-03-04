#include "arbol.h"
//SIN CAMBIO
bool mayorPrioridad(vuelos a, vuelos b) 
{
    if (a.horaProgramada < b.horaProgramada) return true;
    if (a.horaProgramada == b.horaProgramada) {
        return a.prioridad < b.prioridad; // EMERGENCIA (0) es mayor que VIP (1)
    }
    return false;
}

void insertarEnArBin(nodoArBin*& raiz, vuelos v) 
{
    if (raiz == nullptr) {
        raiz = new nodoArBin{v, nullptr, nullptr};
        return;
    }
    if (mayorPrioridad(v, raiz->dato)) {
        insertarEnArBin(raiz->izq, v);
    } else {
        insertarEnArBin(raiz->der, v);
    }
}

// Extraer el vuelo con mayor prioridad (el más a la izquierda) 
vuelos extraerMasPrioritario(nodoArBin*& raiz) 
{
    if (raiz->izq == nullptr) {
        vuelos v = raiz->dato;
        nodoArBin* temp = raiz;
        raiz = raiz->der;
        delete temp;
        return v;
    }
    return extraerMasPrioritario(raiz->izq);
}