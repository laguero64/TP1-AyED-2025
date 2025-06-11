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

int totalHuertas(listaHuertas)
{
}

void mostrarProduccionMensual(listaHuertas)
{
    for (int i = 0; i < totalHuertas; i++)
    {
        cout << "Huerta " << i << ": " << listaHuertas[i].produccionMensual << endl;
    }
}

Cultivo cultivoMasFrecuente(listaHuertas)
{
}

float porcentajeUsoFertilizantes(listaHuertas)
{
}

char cultivoMasFrecuente(listaHuertas)
{
}

float superficiePromedioHuerta(listaHuertas)
{
}

void mostrarHuertasPorBarrio(listaHuertas)
{
}

void mostrarDatos(listaHuertas) // Se debe ingresar un array con las huertas existentes
{
    cout << "Huertas registradas: " << totalHuertas(listaHuertas) << endl;
    cout << "Producción mensual por huerta (en kg):" << endl;
    mostrarProduccionMensual(listaHuertas);
    cout << "Porcentaje de huertas que utilizan fertilizante: " << porcentajeUsoFertilizante(listaHuertas) << endl;
    cout << "Tipo de cultivo mas frecuente: " << cultivoMasFrecuente(listaHuertas) << endl;
    cout << "Superficie promedio por huerta: " << superficiePromedioHuerta(listaHuertas) << endl;
    cout << "Huertas por barrio: " << endl;
    mostrarHuertasPorBarrio(listaHuertas);
}

#endif