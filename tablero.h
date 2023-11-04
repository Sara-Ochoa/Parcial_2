#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
    int tamano;
    char** tablero = nullptr;

public:
    Tablero(int tamanoTablero);
    int getTamano() const;
    char** getTablero() const;
    void setTamano(int newTamano);
    void dibujarTablero(int TableroTamano, char** tablero);
    void TableroInicial(int TableroTamano, char** tablero);
    void asignarMemoria(int TableroTamano,char**tablero);
    void liberarMemoria(int TableroTamano, char** tablero);

    void setTablero(char **newTablero);
};

#endif // TABLERO_H
