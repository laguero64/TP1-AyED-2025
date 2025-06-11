#ifndef MAIN_H // Si el header no existe;
#define MAIN_H // Definir el header.
#include <iostream>
#include <string>

using namespace std;

enum Cultivo
{
    H,
    F,
    A,
    L,
    O
};

struct Huerta
{
    int id;
    string barrio;
    Cultivo tipoCultivo;
    float superficieCultivada;
    float produccionMensual;
    bool fertilizante;
};

void mostrarMenuPrincipal()
{
    cout << "\nBienvenido al proyecto de Huertas Urbanas de Plan Verde!" << endl;
    cout << "Por favor, ingrese el número de la acción que desea realizar:" << endl;
    cout << "1. Cargar y procesar datos de una huerta" << endl;
    cout << "2. Mostrar resultados" << endl;
    cout << "3. Salir" << endl;
}

void cargarDatoIndividual(Huerta &huertaCargada, string parametro)
{
    if (parametro == "barrio")
    {
        cout << "\nIngrese el barrio: ";
        cin >> huertaCargada.barrio;
    }
    else if (parametro == "tipoCultivo")
    {
        char tipoCultivo;
        cout << "\nElija el tipo de cultivo principal:\n(H): Hortalizas\n(F): Frutas\n(A): Aromáticas\n(L): Legumbres\n(O): Otros" << endl;
        cin >> tipoCultivo;

        switch (tipoCultivo)
        {
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
        default:
            cout << "Opción inválida, usando valor por defecto (Hortalizas)." << endl;
            huertaCargada.tipoCultivo = H;
        }
    }
    else if (parametro == "superficieCultivada")
    {
        cout << "\nIngrese la superficie cultivada (en metros cuadrados): ";
        cin >> huertaCargada.superficieCultivada;
    }
    else if (parametro == "produccionMensual")
    {
        cout << "\nIngrese la producción mensual (en kilogramos): ";
        cin >> huertaCargada.produccionMensual;
    }
    else if (parametro == "fertilizante")
    {
        char respuesta;
        cout << "Utiliza fertilizante la huerta:\n(S): Si\n(N): No" << endl;
        cin >> respuesta;
        huertaCargada.fertilizante = (respuesta == 'S' || respuesta == 's');
    }
}

Huerta cargarDatos()
{
    Huerta huertaCargada;

    huertaCargada.id = generarID();

    cargarDatoIndividual(huertaCargada, "barrio");
    cargarDatoIndividual(huertaCargada, "tipoCultivo");
    cargarDatoIndividual(huertaCargada, "superficieCultivada");
    cargarDatoIndividual(huertaCargada, "produccionMensual");
    cargarDatoIndividual(huertaCargada, "fertilizante");

    return huertaCargada;
}

void mostrarDatos()
{
}

#endif