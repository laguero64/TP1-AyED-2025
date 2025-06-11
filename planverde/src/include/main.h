#ifndef MAIN_H // Si el header no existe;
#define MAIN_H // Definir el header.
#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Cultivo {
    H, F, A, L, O
};

struct Huerta {
    int id;
    string barrio;
    Cultivo tipoCultivo;
    float superficieCultivada;
    float produccionMensual;
    char fertilizante;
};

Huerta listaHuertas[100];
int cantidadHuertas;

void agregarHuerta(const Huerta& huerta) {
    if (cantidadHuertas < 100) {
        listaHuertas[cantidadHuertas++] = huerta;
    } else {
        cout << "Error: No se pueden cargar más huertas, se alcanzó el límite máximo." << endl;
    }
}

void cargarDatoIndividual(Huerta &huertaCargada, string parametro) {
    if (parametro == "barrio") {
        cout << "\nIngrese el barrio: ";
        cin >> huertaCargada.barrio;
    }
    else if (parametro == "tipoCultivo") {
        char tipoCultivo;
        cout << "\nElija el tipo de cultivo principal:\n(H): Hortalizas\n(F): Frutas\n(A): Aromáticas\n(L): Legumbres\n(O): Otros" << endl;
        cin >> tipoCultivo;

        switch (tipoCultivo) {
        case 'H':
            huertaCargada.tipoCultivo = H;
            break;
        case 'F':
            huertaCargada.tipoCultivo = F;
            break;
        case 'A':
            huertaCargada.tipoCultivo = A;
            break;
        case 'L':
            huertaCargada.tipoCultivo = L;
            break;
        case 'O':
            huertaCargada.tipoCultivo = O;
            break;
        }
    }
    else if (parametro == "superficieCultivada") {
        cout << "\nIngrese la superficie cultivada (en metros cuadrados): ";
        cin >> huertaCargada.superficieCultivada;
    }
    else if (parametro == "produccionMensual") {
        cout << "\nIngrese la producción mensual (en kilogramos): ";
        cin >> huertaCargada.produccionMensual;
    }
    else if (parametro == "fertilizante") {
        char respuesta;
        cout << "Utiliza fertilizante la huerta:\n(S): Si\n(N): No" << endl;
        cin >> respuesta;
        huertaCargada.fertilizante = respuesta;
    }
}

int generarID() {
    static int ultimoID = 0;
    return ++ultimoID;
}

Huerta cargarDatos() {
    Huerta huertaCargada;

    huertaCargada.id = generarID();

    cargarDatoIndividual(huertaCargada, "barrio");
    cargarDatoIndividual(huertaCargada, "tipoCultivo");
    cargarDatoIndividual(huertaCargada, "superficieCultivada");
    cargarDatoIndividual(huertaCargada, "produccionMensual");
    cargarDatoIndividual(huertaCargada, "fertilizante");

    agregarHuerta(huertaCargada);
    return huertaCargada;
}

int totalHuertas() {
    return cantidadHuertas;
}

void mostrarProduccionMensual(Huerta lista[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Huerta " << i << ": " << lista[i].produccionMensual << " kg" << endl;
    }
}

int cultivoMasFrecuente(Huerta lista[], int cantidad) {
    int contador[5] = {0}; // Contadores para cada tipo de cultivo
    for (int i = 0; i < cantidad; i++) {
        switch (lista[i].tipoCultivo) {
            case H:
                contador[0]++;
                break;
            case F:
                contador[1]++;
                break;
            case A:
                contador[2]++;
                break;
            case L:
                contador[3]++;
                break;
            case O:
                contador[4]++;
                break;
            default:
                break;
            }   
    }
    int maxIndex = contador[0];
    for (int i = 1; i < 5; ++i) {
        if (contador[i] > contador[maxIndex]) {
            maxIndex = i;
        }
    }   
    return maxIndex;
}

float porcentajeUsoFertilizantes(Huerta lista[], int cantidad) {
    int conFertilizante = 0;
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].fertilizante == 'S' || lista[i].fertilizante == 's') {
            conFertilizante++;
        }
    }
    return conFertilizante;
}

string nombreCultivo(int c) {
    switch(c) {
        case 0: return "Hortalizas";
        case 1: return "Frutas";
        case 2: return "Aromáticas";
        case 3: return "Legumbres";
        case 4: return "Otros";
        default: return "Desconocido";
    }
}

int n = 0;
float superficiePromedioHuerta(Huerta lista[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        n += lista[i].superficieCultivada;
    }
    float promedio = n/cantidad;
    return promedio;
}

void mostrarHuertasPorBarrio(Huerta lista[], int cantidad) {
    struct Barrio {
        string nombre;
        int huertas;
    };
    Barrio barrios[100];
    for (int i = 0; i < cantidad; i++) {
        barrios[i].nombre = lista[i].barrio;
        cout << barrios[i].nombre << ": Huerta " << i << endl;
    }
}

void mostrarDatos() { 
    int cantidad = cantidadHuertas;
    cout << "Huertas registradas: " << totalHuertas() << endl;
    cout << "Producción mensual por huerta (en kg):" << endl;
    mostrarProduccionMensual(listaHuertas, cantidadHuertas);
    cout << "Porcentaje de huertas que utilizan fertilizante: " << porcentajeUsoFertilizantes(listaHuertas, cantidadHuertas) << "%" << endl;
    int cultivo = cultivoMasFrecuente(listaHuertas, cantidadHuertas);
    cout << "Tipo de cultivo mas frecuente: " << nombreCultivo(cultivo) << endl;
    cout << "Superficie promedio por huerta: " << superficiePromedioHuerta(listaHuertas, cantidadHuertas) << endl;
    cout << "Huertas por barrio: " << endl;
    mostrarHuertasPorBarrio(listaHuertas, cantidadHuertas);
}

#endif