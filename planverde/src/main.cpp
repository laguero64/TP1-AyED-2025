#include <iostream>
#include <string>
#include "include/main.h"   // Incluye el main header file.
#include "include/id.h"      // Incluye el id header file.

using namespace std;

int interaction = 0;

int main() {
    cout << "\nBienvenido al proyecto de Huertas Urbanas de Plan Verde!" << endl;
    cout << "Por favor, ingrese el número de la acción que desea realizar:" << endl;
    cout << "1. Cargar y procesar datos de una huerta" << endl;
    cout << "2. Mostrar resultados" << endl;
    cout << "3. Salir" << endl;

    while (1) {
        huerta datosHuerta;
        cin >> interaction;
        switch (interaction) {
            case 1:
                datosHuerta.id = generarID();
                cout << "Usted ha elegido cargar y procesar datos de una huerta. Se le ha asignado el número '" << datosHuerta.id << "' como identificador de huerta." << endl;
                cargarDatos();
                interaction = 0;
                break;
            case 2:
                cout << "Usted ha elegido mostrar los resultados de la huerta." << endl;
                mostrarDatos();
                interaction = 0;
                break;
            case 3:
                cout << "Usted ha elegido salir del programa." << endl;
                interaction = 0;
                abort();
                break;
            default:
                cout << "Opción no válida. Por favor, intente nuevamente." << endl;
                interaction = 0;
                break;
        }
    }
    return 0;
}