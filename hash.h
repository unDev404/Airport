#ifndef HASH_H
#define HASH_H
#include "vuelos.h"
#include <string>
#include<iostream>

struct nodohash {
    vuelos dato;
    nodohash* siguiente;
};
const int tamanoHash = 100;
extern nodohash* tablaHash[100];

int funcionhash (string ID);

vuelos* buscarvuelohash(string IDbuscar);

void insertarHash(vuelos vueloNuevo);
#endif