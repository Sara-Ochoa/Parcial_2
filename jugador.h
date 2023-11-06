#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador
{
    string nombre;
    char colorFicha;

public:
    Jugador(string nombre, char colorFicha);
    void indicarPosicion(int &fila, int &columna, int tamano);
    string getNombre() const;
    char getColorFicha() const;
};

#endif // JUGADOR_H
