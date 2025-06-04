#ifndef MAIN_H      // Si el header no existe;
#define MAIN_H      // Definir el header.
#include <iostream>
#include <string>

using namespace std;

struct huerta {
    int id = 0;
    string barrio;
    string tipo[5] = {"H", "F", "A", "L", "O"};
    float superficieCultivada = 0;
    float produccionMensual = 0;
    int fertilizante = true;
};

void cargarDatos() {
    
    return;
}

void mostrarDatos() {

    return;
}

#endif