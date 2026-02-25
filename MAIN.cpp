#include<iostream>

using namespace std;

struct vuelos
{
    string ID; //código único de identificación Ej: AN023 (de momento en el struct)
    string aerolinea; //nombre de la empresa a la que pertenece el avión
    string origen; //ciudad de la que viene el vuelo
    string destino; //ciudad a la que se dirige el vuelo
    string prioridad; //preferencia jerarquica del vuelo {Comercial, VIP, Emergencia, Reprogramado, Cancelado}
    int horaProgramada; //Hora en la que debería estar en la pista del aeropuerto
    int estado; //desarrollo del vuelo: 0: PROGRAMADO, 1:  EN_PISTA, 2: FINALIZADO
    bool operación; //false = DESPEGUE, true = ATERRIZAJE
    int día[7]; //Día en que el avión está en la pista, cola circular (de momento)
};

//FUNCIONES PRINCIPALES

/*
1. Registro de Vuelos
2. Clasificación por Prioridad/horario
3. Filtros de búsqueda
4. Observar Lista de Vuelos

*/


//REGISTRO DE VUELOS

/*
1. crear vuelos en una lista
2. Aquí se usa la tabla hash, el ID es la clave y el struct la info.
3. Ver Lista de Vuelos
*/


//CLASIFICACIÓN POR PRIORIDAD/HORARIO

/*
1. Aquí se usa el arbol Binario, recibe la lista de vuelo y los ordena por Prioridad/horario
*/


//ADMINISTRACIÓN DE ATERRIZAJES/DESPEGUES

/*
1. Recibe los vuelos ordenados
2. separa los vuelos por despegue/aterrizaje en colas
3. Simular que se tiene 3 pistas en simultáneo
4. Desarrollo de la operación de Pista hasta Finalizado
5. usar una función random para que exista la posibilidad de que sean cancelados o reprogramados
    de ser cancelados, se eliminan; de ser reprogramados, vuelven al árbol quizás con menor prioridad
*/