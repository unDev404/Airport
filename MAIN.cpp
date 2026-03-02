#include<iostream>

using namespace std;


enum clase {EMERGENCIA, VIP, COMERCIAL, REPROGRAMADO, CANCELADO};


struct vuelos
{
    string aerolinea; //nombre de la empresa a la que pertenece el avión ARRAY STRING
    string ID; //código único de identificación Ej: AN023 (CLAVE PARA HASH)
    string origen; //ciudad de la que viene el vuelo ARRAY STRING
    string destino; //ciudad a la que se dirige el vuelo
    clase prioridad; //preferencia jerarquica del vuelo {Comercial, VIP, Emergencia, Reprogramado, Cancelado}
    int horaProgramada; //Hora en la que debería estar en la pista del aeropuerto
    int estado; //desarrollo del vuelo: 0: PROGRAMADO, 1:  EN_PISTA, 2: FINALIZADO
    bool operación; //false = DESPEGUE, true = ATERRIZAJE
    int día[7]; //Día en que el avión está en la pista, cola circular (de momento)
};



void mostrarArray(string opciones[], int tam)
{
for(int i = 0; i < tam; i++)
{
    cout<< i+1 << ". " << opciones[i]<< endl;
}
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

int main()
{

    string aerolíneas[5] = {"Conviasa", "Rutaca", "Avior", "LASER", "KAYAK"}; //aerolíneas disponibles en el aeropuerto
    string ciudades[4] = {"Puerto Ordaz", "Maturin", "Barquisimeto", "Caracas"}; //aerolíneas disponibles en el aeropuerto

    mostrarArray(ciudades, 4);
    int selection = selecArray(4);

    cout << selection+1 << ". " << ciudades[selection] << endl;
    
    return 0;
}