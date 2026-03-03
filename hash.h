#ifndef HASH.H
#define HASH.H
#include "vuelos.h"

struct nodohash {
    vuelos dato;
    nodohash* siguiente;
};
const int tamanoHash = 100;
nodohash* tablaHash[100]={NULL};

int funcionhash (string ID);

vuelos* buscarvuelohash(string IDbuscar);

void insertarvuelo(vuelos vueloNuevo);
#endif