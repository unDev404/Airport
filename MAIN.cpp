#include<iostream>
#include<string>
#include "arbol.h"
#include "hash.h"
#include "vuelos.h"
#include "complemento.h"
#include "cola.h"

using namespace std;
  

int main()
{
 int opcion;
    string idAux;
    vuelos temp;
    nodoArBin* raiz = {NULL};


    do {
        cout << "\n======================================" << endl;
        cout << "   SISTEMA DE CONTROL DE AEROPUERTO" << endl;
        cout << "======================================" << endl;
        cout << "1. Registrar Vuelo (Entrada al sistema)" << endl;
        cout << "2. Autorizar Pista (Mover a la fila)" << endl;
        cout << "3. Atender Siguiente (Despegar/Aterrizar)" << endl;
        cout << "4. Ver Radar de Pistas (Estado actual)" << endl;
        cout << "5. Mostrar Vuelos en Sistema" << endl;
        cout << "6. Mostrar Vuelos por Dia" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                crearVuelo(raiz, temp); 
                
                
                cout << "Vuelo registrado exitosamente con ID: (Copiar este ID)" << temp.ID << endl;
                break;
            case 2:
                if (raiz == nullptr) {
                    cout << "\n[!] No hay vuelos registrados en el sistema para autorizar." << endl;
                } else {
                    // Extraemos automáticamente el vuelo con mayor prioridad del árbol
                    vuelos vueloPrioritario = extraerMasPrioritario(raiz); 
                    
                    cout << "\n[Torre de Control] Autorizando automáticamente vuelo con mayor prioridad..." << endl;
                    cout << "ID: " << vueloPrioritario.ID << " | Aerolinea: " << vueloPrioritario.aerolinea << endl;

                    // Lo mandamos a la pista usando su ID
                    mandarapista(vueloPrioritario.ID); 
                }
                break;
            case 3:
                if (pistaterrizaje.contadorPista > 0) {
                    procesarvuelo(pistaterrizaje, "ATERRIZAJE");
                } else if (pistadespegue.contadorPista > 0) {
                    procesarvuelo(pistadespegue, "DESPEGUE");
                } else {
                    cout << "\n[!] No hay aviones esperando en pista." << endl;
                }
                break;
            case 4:
                mostrarpistas();
                break;
                case 5:
              mostrarVuelos();
              break;
            case 6:
              mostrarVuelosPorDia();
              break;
            case 0:
                cout << "Cerrando sistemas de control..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(opcion != 0);
    return 0;
}