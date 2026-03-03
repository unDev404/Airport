#ifndef COLA_H
#define COLA_H
#include "vuelos.h"
#include <iostream>
#include "hash.h"

using namespace std;

const int maxPista = 10; // Capacidad máxima de cada pista
 struct ColaPista {
 vuelos aviones[maxPista];
 int frente;
 int final;
 int contadorPista;

   ColaPista();
};

extern ColaPista pistaterrizaje;
extern ColaPista pistadespegue;

void encolarprioridad(ColaPista &cola, vuelos vueloNuevo);

void mandarapista(string IDbuscar);

void procesarvuelo(ColaPista &cola, string tipopista);

void  mostrarpistas();

#endif
