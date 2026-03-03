#include "complemento.h"


using namespace std;


int contadorVuelos = 0;
string aerolineas[5] = {"Conviasa", "Rutaca", "Avior", "LASER", "KAYAK"}; //aerolíneas disponibles en el aeropuerto
string ciudades[4] = {"Puerto Ordaz", "Maturin", "Barquisimeto", "Caracas"}; //aerolíneas disponibles en el aeropuerto
void mostrarArray(string opciones[], int tam)
{
for(int i = 0; i < tam; i++)
{
    cout<< i+1 << ". " << opciones[i]<< endl;
}
}

string crearID(int num)
{
    string codeAir[5] = {"CV", "RT", "AV", "LS", "KY"};
    string digits = to_string(contadorVuelos);
    string cero = "";
    int x = (3 - digits.length());
    for(int i = 0; i<x; i++)
    {
        cero = cero + "0"; 
    }
    
    string code = codeAir[num] + cero + digits;
    contadorVuelos++;
    return code;
}

int selecArray(int tam)
{
    int x = 0;
    bool verify = true;
    do
    {
        cout << "\nIngresa tu eleccion: ";
        cin >> x;
        if(x>0 && x<tam) verify = false;
        else cout << "\nOpcion Invalida, Intente nuevamente" << endl;

    }while(verify);
   
    return x-1;
}

void crearVuelo(vuelos vueloNuevo){
    cout<<"--Registro de vuelo--"<<endl;
    int op;
    do{
    cout<<"Tipo de operación: "<<endl;
    cout<<"0. DESPEGUE\t1. ATERRIZAJE"<<endl;
    cout<<"Seleccione:";
    cin>>op;

    if(op!=0 && op!=1)
        cout<<"Opcion invalida"<<endl;
    } while(op!=0 && op!=1);

    vueloNuevo.operacion = (op == 1); // true para aterrizaje, false para despegue

    cout<<"Seleccione la aerolínea de vuelo: "<<endl;
    mostrarArray(aerolineas, 5);
    int selection = selecArray(5);
    vueloNuevo.aerolinea = aerolineas[selection];
    vueloNuevo.ID = crearID(selection);

    if(vueloNuevo.operacion)
    {
    cout<<"Seleccione la ciudad de origen: "<<endl;
    mostrarArray(ciudades, 4);
    int seleccionorigen = selecArray(4);
    vueloNuevo.origen = ciudades[seleccionorigen];

    vueloNuevo.destino = ciudades[0];
    }else
    {   
    vueloNuevo.origen = ciudades[0];

    cout<<"Seleccione la ciudad de destino: "<<endl;
    mostrarArray(ciudades, 4);
    int selecciondestino = selecArray(4);
    vueloNuevo.destino = ciudades[selecciondestino];
    }


    vueloNuevo.estado = PROGRAMADO;
    
    do
    {
        cout<<"Ingrese la hora programada (en formato 24 horas, ej: 14 para 2pm): ";
        cin>>vueloNuevo.horaProgramada;
        if(!(vueloNuevo.horaProgramada>=0 && vueloNuevo.horaProgramada<24))
        cout<<"Opcion invalida"<<endl;
    } while (!(vueloNuevo.horaProgramada>=0 && vueloNuevo.horaProgramada<24));

    cout<<"\nSeleccione la prioridad del vuelo: "<<endl;
    cout<<"0. EMERGENCIA | 1. VIP | 2. COMERCIAL | 3. REPROGRAMADO | 4. CANCELADO"<<endl;
    int prioridad;
    do{
        cout<<"Ingrese su eleccion: ";
        cin>>prioridad;
    }while(prioridad < 0 || prioridad > 4);
    vueloNuevo.prioridad = (clase)(prioridad);


    cout << "\nSeleccione el dia de la semana que va a volar. " << endl;
    mostrarArray(diasSemana, 7);
    int diaSeleccionado = selecArray(7);
    vueloNuevo.dia = (dias)diaSeleccionado;
    

}

void mostrarVuelos(){

    cout<< "\n========== HISTORIAL DE VUELOS EN GENERAL =========="<<endl; 

    bool hayVuelos = false;

    for (int i = 0; i < tamanoHash; i++) {
        nodohash* temp = tablaHash[i];
        while (temp != NULL) {
            hayVuelos = true;   
            
            cout << "-----------------------------" << endl;
            cout << "ID: " << temp->dato.ID << ", Aerolínea: " << temp->dato.aerolinea 
                 << ", Origen: " << temp->dato.origen << ", Destino: " << temp->dato.destino 
                 << ", Prioridad: " << clases[temp->dato.prioridad] << ", Estado: " << procesoactual[temp->dato.estado] 
                 << ", Hora Programada: " << temp->dato.horaProgramada << ":00" 
                 << ", Operación: " << (temp->dato.operacion ? "Aterrizaje" : "Despegue")
                 << ", Dia: " << diasSemana[temp->dato.dia] << "\n"
                 << endl;
            temp = temp->siguiente;
        }
    }
     if (hayVuelos == false){
            cout << "No hay vuelos registrados." <<endl;
        }
}

void mostrarVuelosPorDia() {
    cout << "\n========== HISTORIAL DE VUELOS POR DIA ==========" << endl;
    
   
    for (int i = 0; i < 7; i++) {
        cout << "\n--- VUELOS DEL " << diasSemana[i] << " ---" << endl;
        bool diaTieneVuelos = false; //<--- para saber si hay vuelos o nei.

        for (int j = 0; j <= 23; j++) {                 //<---- esto es para ordenar por horas. 

        // Recorremos la tabla buscando vuelos que coincidan con el dia actual 'j'
        for (int k = 0; k < tamanoHash; k++) {
            nodohash* temp = tablaHash[k];

            while (temp != NULL) {
                if (temp->dato.dia == i && temp->dato.horaProgramada == j) { // Si el dia del vuelo coincide con 'i' y la hora es 'j'
                    diaTieneVuelos = true;
                    cout << "Hora: " << temp->dato.horaProgramada << ":00"  
                         << " \n| ID: " << temp->dato.ID 
                         << " \n| Aerolinea: " << temp->dato.aerolinea 
                         << " \n| Origen: " << temp->dato.origen 
                         << " \n| Destino: " << temp->dato.destino 
                         << " \n| Prioridad: " << clases[temp->dato.prioridad] 
                         << " \n| Estado: " << procesoactual[temp->dato.estado] 
                         << " \n| Operacion: " << (temp->dato.operacion ? "Aterrizaje" : "Despegue")
                         << " \n| Dia: " << diasSemana[temp->dato.dia] << "\n"
                         << endl;
                }
                temp = temp->siguiente;
            }
        }
    }

        // Si terminó de buscar en toda la tabla hash y no encontró vuelos para este dia, que imprima:
        if (!diaTieneVuelos) {
            cout << "  No hay vuelos programados para este dia." << endl; 
        }
    }
    cout << "=================================================" << endl;
}
