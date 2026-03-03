#ifndef COMPLEMENTO_H
#define COMPLEMENTO_H



#include<string>
#include<iostream>
#include "vuelos.h"


extern int contadorVuelos;
extern string aerolineas[5]; //aerolíneas disponibles en el aeropuerto
extern string ciudades[4]; //aerolíneas disponibles en el aeropuerto


void mostrarArray(string opciones[], int tam);

std::string crearID(int num);

int selecArray(int tam);

void crearVuelo(vuelos vueloNuevo);
#endif