#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
    int tamano;
    char** tablero = nullptr;

public:
    Tablero(int tamanoTablero);
    ~Tablero();
    int getTamano() const;
    char** getTablero() const;
    void dibujarTablero(int TableroTamano, char** tablero);
    void TableroInicial(int TableroTamano, char** tablero);
};


#endif // TABLERO_H
