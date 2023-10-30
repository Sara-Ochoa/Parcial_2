#include <iostream>
#include <jugador.h>
#include <tablero.h>
#include <string>

using namespace std;

int main()
{
    Jugador jugador1("Sara",'-');
    int x=0;
    int y=0;
    string posicion = "F8";
    jugador1.indicarPosicion(posicion,x,y);
    cout << "Coordenadas numericas: fila = " << x << ", columna = " << y <<"y ademas "<<jugador1.getNumeroFichas()<< endl;

    return 0;
}
