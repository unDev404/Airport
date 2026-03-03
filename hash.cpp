#include "hash.h"

using namespace std;

nodohash* tablaHash[100]={NULL};

int funcionhash (string ID)
{
    int suma = 0;
    int x = ID.length();
    for (int i = 0; i < x; i++) {
        suma += (int)ID[i]; // Suma el valor ASCII de cada carácter
    }
    return suma % tamanoHash; // Devuelve el índice en la tabla hash
}

vuelos* buscarvuelohash(string IDbuscar)
{
    int indice = funcionhash(IDbuscar);
    nodohash* temp = tablaHash[indice];
    while (temp != NULL) {
        if (temp->dato.ID == IDbuscar) {
            return &(temp->dato); // Devuelve un puntero al vuelo encontrado
        }
        
        temp = temp->siguiente;
    }
    return NULL; // No se encontró el vuelo
}

void insertarvuelo(vuelos vueloNuevo){
    if(buscarvuelohash(vueloNuevo.ID) != NULL) {
        cout << "Error: Ya existe un vuelo con ese ID." << endl;
        return;
    }
    int indice = funcionhash(vueloNuevo.ID);
    nodohash* nuevoNodo = new nodohash();
    nuevoNodo->dato = vueloNuevo;
    nuevoNodo->siguiente = tablaHash[indice];
    tablaHash[indice] = nuevoNodo; // Inserta el nuevo nodo al inicio de la lista en ese índice
    cout<<"registro en posicion:"<<indice<<endl;
}