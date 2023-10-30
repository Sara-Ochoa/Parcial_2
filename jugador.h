#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador
{
    string nombre;
    int numeroFichas=2;
    char colorFicha;

public:
    Jugador(string nombre, char colorFicha);
    void indicarPosicion(string &posicion, int &fila, int &columna);
    string getNombre() const;
    void setNombre(const string &newNombre);
    int getNumeroFichas() const;
    void setNumeroFichas(int newNumeroFichas);
    char getColorFicha() const;
    void setColorFicha(char newColorFicha);
};

#endif // JUGADOR_H
