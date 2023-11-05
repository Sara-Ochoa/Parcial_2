#include "tablero.h"
#include <iostream>

using namespace std;

int Tablero::getTamano() const
{
    return tamano;
}

char** Tablero::getTablero() const
{
    return tablero;
}

void Tablero::dibujarTablero(int TableroTamano, char** tablero)
{
    cout << "   ";
    for (int i = 0; i < TableroTamano; i++) {
        cout << static_cast<char>('A' + i) << ' ';
    }
    cout << endl;

    for (int i = 0; i < TableroTamano; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < TableroTamano; j++) {
            cout << "|" << tablero[i][j];
        }
        cout << "|" << endl;
    }
}

void Tablero::TableroInicial(int TableroTamano, char** tablero)
{
    for (int i = 0; i < TableroTamano; i++) {
        for (int j = 0; j < TableroTamano; j++) {
            tablero[i][j] =  ' ';
        }
    }

    tablero[(TableroTamano / 2) - 1][(TableroTamano / 2) - 1] = '-';
    tablero[(TableroTamano / 2) - 1][TableroTamano / 2] = '*';
    tablero[TableroTamano / 2][(TableroTamano / 2) - 1] = '*';
    tablero[TableroTamano / 2][TableroTamano / 2] = '-';
}


Tablero::Tablero(int tamanoTablero)
{
    this->tamano = tamanoTablero;
    this->tablero = new char* [tamano];
    for (int i = 0; i < tamanoTablero; i++) {
        this->tablero[i] = new char[tamano];
    }
}

Tablero::~Tablero()
{
    // Liberar la memoria utilizada por el arreglo bidimensional
    if (tablero != nullptr) {
        for (int i = 0; i < tamano; i++) {
            delete[] tablero[i];
        }
        delete[] tablero;
        tablero = nullptr;
    }
}

