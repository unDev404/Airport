#include <iostream>
#include <string>

using namespace std;

// --- DEFINICIONES Y ENUMS (Basado en tu MAIN.cpp) ---
enum clase { EMERGENCIA, VIP, COMERCIAL, REPROGRAMADO, CANCELADO };
enum proceso { PROGRAMADO, EN_PISTA, FINALIZADO };

struct Vuelo 
{
    string aerolinea;
    string ID; // Clave para la Tabla Hash
    string origen;
    string destino;
    clase prioridad; 
    proceso estado;
    int horaProgramada; // Formato militar (ej: 1430 para 2:30 PM)
    bool operacion; // true = ATERRIZAJE, false = DESPEGUE
};

// --- ESTRUCTURAS DE DATOS ---

// 1. Nodo para Listas Enlazadas (Usado en Tabla Hash y Colas)
struct NodoLista 
{
    Vuelo dato;
    NodoLista* siguiente;
};

// 2. Tabla Hash (Encadenamiento Separado) 
const int TAM_HASH = 10;
NodoLista* tablaHash[TAM_HASH];

// 3. Árbol Binario de Prioridades [cite: 154]
struct NodoBST 
{
    Vuelo dato;
    NodoBST* izq;
    NodoBST* der;
};

// --- FUNCIONES DE APOYO ---

// Función Hash simple para IDs (ej: "AN123") [cite: 551]
int funcionHash(string id) 
{
    int suma = 0;
    for (char c : id) suma += c;
    return suma % TAM_HASH;
}

// Comparación de Prioridad: Hora primero, luego nivel de emergencia
bool tieneMayorPrioridad(Vuelo a, Vuelo b) 
{
    if (a.horaProgramada < b.horaProgramada) return true;
    if (a.horaProgramada == b.horaProgramada) {
        return a.prioridad < b.prioridad; // EMERGENCIA (0) es mayor que VIP (1)
    }
    return false;
}

// --- GESTIÓN DE TABLA HASH (Repositorio Global) ---

void insertarEnHash(Vuelo v) 
{
    int indice = funcionHash(v.ID);
    NodoLista* nuevo = new NodoLista{v, tablaHash[indice]};
    tablaHash[indice] = nuevo;
}

Vuelo* buscarEnHash(string id) 
{
    int indice = funcionHash(id);
    NodoLista* temp = tablaHash[indice];
    while (temp) {
        if (temp->dato.ID == id) return &(temp->dato);
        temp = temp->siguiente;
    }
    return nullptr;
}

// --- GESTIÓN DE ÁRBOL BST (Organización por Prioridad) [cite: 193] ---

void insertarEnBST(NodoBST*& raiz, Vuelo v) 
{
    if (raiz == nullptr) {
        raiz = new NodoBST{v, nullptr, nullptr};
        return;
    }
    if (tieneMayorPrioridad(v, raiz->dato)) {
        insertarEnBST(raiz->izq, v);
    } else {
        insertarEnBST(raiz->der, v);
    }
}

// Extraer el vuelo con mayor prioridad (el más a la izquierda) 
Vuelo extraerMasPrioritario(NodoBST*& raiz) 
{
    if (raiz->izq == nullptr) {
        Vuelo v = raiz->dato;
        NodoBST* temp = raiz;
        raiz = raiz->der;
        delete temp;
        return v;
    }
    return extraerMasPrioritario(raiz->izq);
}

// --- GESTIÓN DE COLAS (Secuencia de Pista) ---

void encolar(NodoLista*& frente, NodoLista*& final, Vuelo v) 
{
    NodoLista* nuevo = new NodoLista{v, nullptr};
    if (frente == nullptr) {
        frente = final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}

// --- LÓGICA DEL SISTEMA ---

string aerolineasArr[5] = {"Conviasa", "Rutaca", "Avior", "LASER", "KAYAK"};
string ciudadesArr[4] = {"Puerto Ordaz", "Maturin", "Barquisimeto", "Caracas"};

void registrarVuelo(NodoBST*& arbolActivos) 
{
    Vuelo v;
    int sel;

    cout << "\n--- REGISTRO DE VUELO ---\n";
    cout << "ID del Vuelo (Ej: AN123): "; cin >> v.ID;
    
    // Evitar duplicados en Hash
    if (buscarEnHash(v.ID)) 
    {
        cout << "Error: El ID ya existe.\n";
        return;
    }

    cout << "Seleccione Aerolinea (1-5):\n";
    for(int i=0; i<5; i++) cout << i+1 << ". " << aerolineasArr[i] << endl;
    cin >> sel; v.aerolinea = aerolineasArr[sel-1];

    cout << "Seleccione Destino (1-4):\n";
    for(int i=0; i<4; i++) cout << i+1 << ". " << ciudadesArr[i] << endl;
    cin >> sel; v.destino = ciudadesArr[sel-1];
    v.origen = "Bolivar (Base)";

    cout << "Prioridad (0:Emergencia, 1:VIP, 2:Comercial, 3:Reprogramado): ";
    cin >> sel; v.prioridad = (clase)sel;

    cout << "Hora Programada (HHMM): ";
    cin >> v.horaProgramada;

    cout << "Operacion (1: Aterrizaje, 0: Despegue): ";
    cin >> sel; v.operacion = (sel == 1);

    v.estado = PROGRAMADO;

    // Almacenar en ambas estructuras
    insertarEnHash(v);
    insertarEnBST(arbolActivos, v);
    cout << "Vuelo registrado exitosamente.\n";
}

void simularTorre(NodoBST*& arbol, NodoLista*& fPista, NodoLista*& finPista) 
{
    if (arbol == nullptr) 
    {
        cout << "No hay vuelos programados para procesar.\n";
        return;
    }
    
    // Se toma el de mayor prioridad del árbol y se pasa a la cola de pista
    Vuelo proximo = extraerMasPrioritario(arbol);
    proximo.estado = EN_PISTA;
    encolar(fPista, finPista, proximo);
    
    cout << "\n>>> TORRE DE CONTROL <<<\n";
    cout << "Vuelo " << proximo.ID << " de " << proximo.aerolinea 
         << " movido a PISTA para " << (proximo.operacion ? "ATERRIZAJE" : "DESPEGUE") << ".\n";
}

void mostrarPista(NodoLista* frente) 
{
    cout << "\n--- VUELOS EN PISTA ---\n";
    if (!frente) cout << "Pista vacia.\n";
    while (frente) 
    {
        cout << "[" << frente->dato.ID << "] " << frente->dato.aerolinea 
             << " - " << (frente->dato.operacion ? "Aterrizando" : "Despegando") << endl;
        frente = frente->siguiente;
    }
}

int main() {
    // Inicializar estructuras
    for(int i=0; i<TAM_HASH; i++) tablaHash[i] = nullptr;
    NodoBST* arbolPrioridad = nullptr;
    NodoLista *frentePista = nullptr, *finalPista = nullptr;

    int opcion;
    do {
        cout << "\n=== SISTEMA DE AEROPUERTO ===\n";
        cout << "1. Registrar Vuelo\n";
        cout << "2. Procesar Siguiente (BST -> Pista)\n";
        cout << "3. Ver Cola de Pista\n";
        cout << "4. Buscar Vuelo por ID (Hash)\n";
        cout << "5. Salir\n";
        cout << "Opcion: "; cin >> opcion;

        switch(opcion) 
        {
            case 1: registrarVuelo(arbolPrioridad); break;
            case 2: simularTorre(arbolPrioridad, frentePista, finalPista); break;
            case 3: mostrarPista(frentePista); break;
            case 4: {
                string id; cout << "Ingrese ID: "; cin >> id;
                Vuelo* hallado = buscarEnHash(id);
                if (hallado) cout << "Vuelo encontrado: " << hallado->aerolinea << " con destino " << hallado->destino << endl;
                else cout << "No encontrado.\n";
                break;
            }
        }
    } while (opcion != 5);

    return 0;
}