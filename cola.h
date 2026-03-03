#ifndef COLA_H
#define COLA_H
#include "vuelos.h"
#include <iostream>
#include "hash.h"

const int maxPista = 10; // Capacidad máxima de cada pista
 struct ColaPista {
 vuelos aviones[maxPista];
 int frente;
 int final;
 int contadorPista;

   ColaPista() {
    frente = 0;
    final = 0;
    contadorPista = 0;
}
};

ColaPista pistaterrizaje;
ColaPista pistadespegue;

void encolarprioridad(ColaPista &cola, vuelos vueloNuevo);

void mandarapista(string IDbuscar);

void procesarvuelo(ColaPista &cola, string tipopista);

void  mostrarpistas();
#endif