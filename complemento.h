#ifndef COMPLEMENTO_H
#define COMPLEMENTO_H
//CORREGIDO
#include<string>
#include<iostream>
#include "vuelos.h"
#include "arbol.h"
#include "hash.h"
#include "cola.h"



extern int contadorVuelos;
extern string aerolineas[5]; //aerolíneas disponibles en el aeropuerto
extern string ciudades[4]; //aerolíneas disponibles en el aeropuerto
//Traductor del enum a text
extern string clases[5];
extern string procesoactual[3];
extern string diasSemana[7]; //días de la semana para el historial

void mostrarArray(string opciones[], int tam);

std::string crearID(int num);

int selecArray(int tam);

void crearVuelo(nodoArBin*& raiz, vuelos &vueloNuevo);

void mostrarVuelos();

void mostrarVuelosPorDia();

void simularTorre(nodoArBin*& raiz);
void reproducir();
void pausaparasegundo();

#endif