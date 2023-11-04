#ifndef ADMINISTRARJUEGO_H
#define ADMINISTRARJUEGO_H
#include <iostream>

using namespace std;

class administrarJuego
{
public:
    administrarJuego();
    bool validarMovimientos(char fichaActual,char fichaOponente, int tamanoTablero, char** tablero);
    bool movimientoValido(int fila, int columna, int TableroTamano, char fichaActual, char fichaOponente,
                          bool modo,char** tablero);
    bool hacerJugada(int fila, int col, int tamano, char jugador, char oponente, char** tablero);
    pair<int, int> cuentafichas(int TableroTamano,char J1,char J2, char** tablero);
    void terminarJuego();
    void MenuPrincipal();
    void guardarInformacion(string nombre1, string nombre2, pair<int,int> conteos);
    void verHistorial();
};

#endif // ADMINISTRARJUEGO_H
