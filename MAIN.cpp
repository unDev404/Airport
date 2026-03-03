#include<iostream>
#include<string>

using namespace std;

int contadorVuelos = 7;
enum clase {EMERGENCIA, VIP, COMERCIAL, REPROGRAMADO, CANCELADO};
enum proceso {PROGRAMADO, EN_PISTA, FINALIZADO};

    string aerolíneas[5] = {"Conviasa", "Rutaca", "Avior", "LASER", "KAYAK"}; //aerolíneas disponibles en el aeropuerto
    string ciudades[4] = {"Puerto Ordaz", "Maturin", "Barquisimeto", "Caracas"}; //aerolíneas disponibles en el aeropuerto

struct vuelos
{
    string aerolinea; //nombre de la empresa a la que pertenece el avión ARRAY STRING
    string ID; //código único de identificación Ej: AN123 (CLAVE PARA HASH)
    string origen; //ciudad de la que viene el vuelo ARRAY STRING
    string destino; //ciudad a la que se dirige el vuelo
    clase prioridad; //preferencia jerarquica del vuelo 
    proceso estado; //desarrollo del vuelo
    int horaProgramada; //Hora en la que debería estar en la pista del aeropuerto
    bool operación; //false = DESPEGUE, true = ATERRIZAJE
    //int día[7]; //Día en que el avión está en la pista, cola circular (de momento)
};



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
    for(int i = 0; i<(3 - digits.length()); i++)
    {
        cero = cero + "0"; 
    }
    
    string code = codeAir[num] + cero + to_string(contadorVuelos);
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


int main()
{

   

    
    
    return 0;
}