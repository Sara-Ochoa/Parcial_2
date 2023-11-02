#ifndef ADMINISTRARJUEGO_H
#define ADMINISTRARJUEGO_H
#include <iostream>


class administrarJuego
{
public:
    administrarJuego();
    bool validarMovimientos(char &fichaActual,char &fichaOponente, int &tamanoTablero);
    bool movimientoValido(int fila, int columna, int tamanoTablero, char fichaActual,
                          char fichaOponente);
    void hacerJugada(int &fila, int &columna);
    void terminarJuego();
    void MenuPrincipal();
    void guardarInformacion(std::string &nombre1, std::string &nombre2, int &numeroFichas1, int &numeroFichas2);
    void verHistorial();
};

#endif // ADMINISTRARJUEGO_H
