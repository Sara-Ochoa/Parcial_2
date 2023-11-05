#include "jugador.h"
#include <iostream>

using namespace std;

string Jugador::getNombre() const
{
    return nombre;
}

char Jugador::getColorFicha() const
{
    return colorFicha;
}

Jugador::Jugador(string nombre, char colorFicha)
{
    this->nombre = nombre;
    this->colorFicha = colorFicha;
}

void Jugador::indicarPosicion(int &fila, int &columna, int tamano)
{
    //Metodo para pedir posición al usuario
    char letra;
    int numero;
    string posicion;
    while(true){
        cout<<"Ingresa una posicion en el formato letra y numero (por ejemplo, A3): ";
        cin>>posicion;
        cout<<endl;
        // Verificar que la entrada tenga el formato correcto

        if (posicion.length() != 2) {
            cout << "Entrada no valida. Debe tener exactamente una letra y un numero." << endl;
        }

        // Extraer la letra y el número de la entrada
        letra = toupper(posicion[0]);//Cambia la letra a mayúscula
        numero = posicion[1] - '0';

        // Verificar que la letra sea una letra válida (por ejemplo, 'A', 'B', 'C', ...)
        if (letra < 'A' || letra > 'A'+ tamano){
            cout << "Letra no valida." << endl;
        }

        // Verificar que el número sea un número válido (por ejemplo, 1, 2, 3, ...)
        else if (numero < 1 || numero > tamano) {
            cout << "Numero no valido. Debe estar en el rango de 1 a "<< tamano <<"." << endl;
        }
        else{
            break;
        }
    }
    // Calcular las coordenadas numéricas (ten en cuenta que 'A' se mapea a 0, 'B' a 1, 'C' a 2, ...)
    columna = letra - 'A';
    fila = numero - 1;
}
