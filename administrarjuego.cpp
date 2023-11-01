#include "administrarjuego.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

administrarJuego::administrarJuego()
{

}

bool administrarJuego::validarMovimientos(char)
{
    //recibe un char que es el color de ficha para comprobar si esa tiene movimientos posibles o si le toca
    //ceder el turno.
}

bool administrarJuego::verificarJugada(int &fila, int &columna)
{
    //mira si en esa posicion donde el jugador quiere colocar una ficha si se puede (que esté libre)
    //y si sí encirra fichas del oponente.
}

void administrarJuego::hacerJugada(int &fila, int &columna)
{
    //realiza el movimiento y cambia las fichas necesarias.
}

void administrarJuego::terminarJuego()
{
    //termina el juego y escribe en el txt la información pedida
}

void administrarJuego::guardarInformacion(string &nombre1, string &nombre2, int &numeroFichas1,
                                          int &numeroFichas2)
{
    ofstream archivo("informacion.txt", std::ios::app);
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
    }
    time_t tiempoAhora;
    time(&tiempoAhora);
    struct tm *miTiempo=localtime(&tiempoAhora);

    if(numeroFichas1>numeroFichas2){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1
                <<"/"<< miTiempo->tm_year+ 1900<<","<<nombre1<<","<<numeroFichas1<<endl;
    }
    else{
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1
                <<"/"<< miTiempo->tm_year+ 1900<<","<<nombre2<<","<<numeroFichas2<<endl;
    }
    archivo.close();
}

void administrarJuego::verHistorial()
{
    ifstream archivo("informacion.txt");
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
    }
    string linea;
    while (getline(archivo, linea)) {
        if(linea.length() !=0){
            // Variables para almacenar los valores
            string valor1, valor2, valor3, valor4, valor5;

            // Utiliza un índice para rastrear la posición en la línea
            int index = 0;
            int inicio = 0;

            // Recorre la línea carácter por carácter
            for (int i = 0; i < linea.length(); ++i) {
                if (linea[i] == ',') {
                    // Cuando encuentres una coma, guarda el valor entre 'inicio' e 'i' en la variable correspondiente
                    if (index == 0) {
                        valor1 = linea.substr(inicio, i - inicio);
                    } else if (index == 1) {
                        valor2 = linea.substr(inicio, i - inicio);
                    } else if (index == 2) {
                        valor3 = linea.substr(inicio, i - inicio);
                    } else if (index == 3) {
                        valor4 = linea.substr(inicio, i - inicio);
                    } else if (index == 4) {
                        valor5 = linea.substr(inicio, i - inicio);
                    }
                    inicio = i + 1; // Actualiza el inicio para el próximo valor
                    index++; // Incrementa el índice
                }
            }

            // Después del bucle, el último valor no termina con una coma
            // Así que lo guardamos aquí
            if (index == 0) {
                valor1 = linea.substr(inicio);
            } else if (index == 1) {
                valor2 = linea.substr(inicio);
            } else if (index == 2) {
                valor3 = linea.substr(inicio);
            } else if (index == 3) {
                valor4 = linea.substr(inicio);
            } else if (index == 4) {
                valor5 = linea.substr(inicio);
            }

            // Ahora puedes hacer lo que quieras con los valores
            cout << "Nombre jugador 1: " << valor1 << endl;
            cout << "Nombre jugador 2: " << valor2 << endl;
            cout << "Fecha y hora: " << valor3 << endl;
            cout << "Ganador: " << valor4 << endl;
            cout << "Numero de fichas: " << valor5 << endl;
        }
        else{
            cout<<"No hay información para mostrar."<<endl;
        }
    }

    archivo.close();
}
/*
void administrarJuego::MenuPrincipal()
{
    cout<<endl;
    cout<<"*********** Menu parcial 2 ***********"<<endl;
    cout<<endl;
    cout<<"1. Jugar"<<endl;
    cout<<"2. Ver historial"<<endl;
    cout<<endl;
}*/
