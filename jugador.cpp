#include "jugador.h"
#include <iostream>

using namespace std;

string Jugador::getNombre() const
{
    return nombre;
}

void Jugador::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

int Jugador::getNumeroFichas() const
{
    return numeroFichas;
}

void Jugador::setNumeroFichas(int newNumeroFichas)
{
    numeroFichas = newNumeroFichas;
}

char Jugador::getColorFicha() const
{
    return colorFicha;
}

void Jugador::setColorFicha(char newColorFicha)
{
    colorFicha = newColorFicha;
}

Jugador::Jugador(string nombre, char colorFicha)
{
    this->nombre = nombre;
    this->colorFicha = colorFicha;
}

void Jugador::indicarPosicion(string &posicion, int &fila, int &columna)
{
    //Metodo para pedir posición al usuario
    int n=8;

    // Verificar que la entrada tenga el formato correcto
    if (posicion.length() != 2) {
        cout << "Entrada no válida. Debe tener exactamente una letra y un número." << endl;
    }

    // Extraer la letra y el número de la entrada
    char letra = posicion[0];
    int numero = posicion[1] - '0';

    // Verificar que la letra sea una letra válida (por ejemplo, 'A', 'B', 'C', ...)
    if (letra < 'A' || letra > 'Z'){
        cout << "Letra no válida. Debe ser una letra en mayúsculas." << endl;
    }

    // Verificar que el número sea un número válido (por ejemplo, 1, 2, 3, ...)
    if (numero < 1 || numero > n) {
        cout << "Número no válido. Debe estar en el rango de 1 a "<< n <<"." << endl;
    }

    // Calcular las coordenadas numéricas (ten en cuenta que 'A' se mapea a 0, 'B' a 1, 'C' a 2, ...)
    fila = letra - 'A';
    columna = numero - 1;
}
