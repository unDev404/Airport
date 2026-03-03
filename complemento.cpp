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

void crearVuelo(nodoArBin*& raiz, vuelos vueloNuevo){
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
    op = selecArray(5);
    vueloNuevo.aerolinea = aerolineas[op];
    vueloNuevo.ID = crearID(op);

    if(vueloNuevo.operacion)
    {
    cout<<"Seleccione la ciudad de origen: "<<endl;
    mostrarArray(ciudades, 4);
    op = selecArray(4);
    vueloNuevo.origen = ciudades[op];

    vueloNuevo.destino = ciudades[0];
    }else
    {   
    vueloNuevo.origen = ciudades[0];

    cout<<"Seleccione la ciudad de destino: "<<endl;
    mostrarArray(ciudades, 4);
    op = selecArray(4);
    vueloNuevo.destino = ciudades[op];
    }

    cout << "Prioridad (0:Emergencia, 1:VIP, 2:Comercial, 3:Reprogramado): ";
    cin >> op;
     vueloNuevo.prioridad = (clase)op;

    vueloNuevo.estado = PROGRAMADO;
    
    do
    {
        cout<<"Ingrese la hora programada (en formato 24 horas, ej: 14 para 2pm): ";
        cin>>vueloNuevo.horaProgramada;
        if(!(vueloNuevo.horaProgramada>=0 && vueloNuevo.horaProgramada<24))
        cout<<"Opcion invalida"<<endl;
    } while (!(vueloNuevo.horaProgramada>=0 && vueloNuevo.horaProgramada<24));

    insertarEnArBin(raiz, vueloNuevo);
    insertarHash(vueloNuevo);
    
}