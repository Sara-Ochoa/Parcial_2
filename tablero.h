#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
    int tamano;
public:
    Tablero(int tamano);
    int getTamano() const;
    void setTamano(int newTamano);
};

#endif // TABLERO_H
