#include<iostream>
#include<string>
#include "arbol.h"
#include "hash.h"
#include "vuelos.h"
#include "complemento.h"

using namespace std;
  

int main()
{

    vuelos vueloNuevo;
    crearVuelo(vueloNuevo);
    insertarvuelo(vueloNuevo);


    
    
    return 0;
}