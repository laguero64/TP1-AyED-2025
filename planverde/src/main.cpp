#include <iostream>
#include "include/main.h"   // Incluye el main header file.
#include "include/id.h"      // Incluye el id header file.

using namespace std;

struct huertas {
    int id = 0;
    string barrio;
    string tipo[5] = {"H", "F", "A", "L", "O"};
    float superficieCultivada = 0;
    float produccionMensual = 0;
    bool fertilizante = true;
};

int interaction = 0;

int main() {

    cout << "Bienvenido al proyecto de Huertas Urbanas de Plan Verde!" << endl;
    cout << "Por favor, ingrese el número de la acción que desea realizar:" << endl;
    cout << "1. Cargar y procesar datos de una huerta" << endl;
    cout << "2. Mostrar resultados" << endl;
    cout << "3. Salir" << endl;

    cin >> interaction;
    
    return 0;
}