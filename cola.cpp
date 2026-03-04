#include "cola.h"

using namespace std;

ColaPista pistaterrizaje;
ColaPista pistadespegue;

// Funciones de las colas

void encolarprioridad(ColaPista &cola, vuelos vueloNuevo) {
   if (cola.contadorPista==maxPista) {
        cout<<"Pista saturada... "<<vueloNuevo.ID<<"Debe esperar en zona de espera externa"<<endl;
        return;
}

if(cola.contadorPista==0){
    cola.aviones[cola.final] = vueloNuevo;
} else {
    int i = cola.final;
    cola.aviones[i] = cola.aviones[(i - 1 + maxPista) % maxPista];
    while (i != cola.frente && cola.aviones[(i - 1 + maxPista) % maxPista].prioridad > vueloNuevo.prioridad) {
            cola.aviones[i] = cola.aviones[(i - 1 + maxPista) % maxPista];
        i = (i - 1 + maxPista) % maxPista;
    }
    cola.aviones[i] = vueloNuevo;
}
cola.final = (cola.final + 1) % maxPista;
cola.contadorPista++;
cout<<"[Pista] Vuelo "<<vueloNuevo.ID<<" ha estrado a la fila (prioridad:"<<vueloNuevo.prioridad<<")."<<endl;
}

void mandarapista( string IDbuscar){
    vuelos* vuelo = buscarvuelohash(IDbuscar);
    if(vuelo == NULL) {
        cout << "Error: No se encontró un vuelo con ese ID." << IDbuscar<<endl;
        return;
     }
     vuelo->estado = EN_PISTA;
    if(vuelo->operacion) {
        encolarprioridad(pistaterrizaje, *vuelo);
    } else {
   encolarprioridad(pistadespegue, *vuelo);
    }
	}

void procesarvuelo(ColaPista &cola, string tipopista) {
        if (cola.contadorPista == 0) {
            cout << "No hay vuelos en la pista de " << tipopista << "." << endl;
            return;
        }
        vuelos vueloProcesado = cola.aviones[cola.frente];
       vuelos* vueloenhash= buscarvuelohash(vueloProcesado.ID);

        if(vueloenhash!=NULL){
		 vueloenhash->estado = FINALIZADO;
	 }

		//Nodo para el historial
    	nodohash* nuevoNodoHistorial = new nodohash();
		nuevoNodoHistorial->dato = vueloProcesado;
    	nuevoNodoHistorial->dato.estado = FINALIZADO; // Nos aseguramos que el estado sea final

		//Conectar al inicio de la lista 'historial'
    	nuevoNodoHistorial->siguiente = historial;
    	historial = nuevoNodoHistorial;
	
        cola.frente = (cola.frente + 1) % maxPista;
        cola.contadorPista--;

        cout<<"Torre de control: Vuelo "<<vueloProcesado.ID<<" ha finalizado su "<<tipopista<<"."<<endl;
    }
    
void  mostrarpistas() {
        cout<<"----------------------------------------"<<endl;
        cout << "\nEstado de operaciones de las pistas: " << endl;
        cout<<"-----------------------------------------"<<endl;
        cout << "Pista de aterrizaje: [" << pistaterrizaje.contadorPista << " aviones]:" << endl;
        if(pistaterrizaje.contadorPista == 0)
        cout<<"[Pista de aterrizaje vacia]"<<endl;
        else {
            int index = pistaterrizaje.frente;
            for (int i = 0; i < pistaterrizaje.contadorPista; i++) {
                cout << " [" << i+1 << "] " << pistaterrizaje.aviones[index].ID << " (Prioridad: " << pistaterrizaje.aviones[index].prioridad << ")" << endl;
       index = (index + 1) % maxPista;
            }
        }

        // PISTA DE DESPEGUE
       cout << "\nPista de despegue: [" << pistadespegue.contadorPista << " aviones]:" << endl;
        if(pistadespegue.contadorPista == 0)
        cout<<"[Pista de despegue vacia]"<<endl;
        else {
            int index = pistadespegue.frente;
            for (int i = 0; i < pistadespegue.contadorPista; i++) {
                cout << " [" << i+1 << "] " << pistadespegue.aviones[index].ID << " (Prioridad: " << pistadespegue.aviones[index].prioridad << ")" << endl; 
         index = (index + 1) % maxPista;
        }
    }
    cout<<"----------------------------------------"<<endl;

    }
