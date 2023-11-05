#include "administrarjuego.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

administrarJuego::administrarJuego()
{

}

bool administrarJuego::validarMovimientos(char fichaActual,char fichaOponente, int tamanoTablero, char** tablero)
{
    //recibe un char que es el color de ficha para comprobar si esa tiene movimientos posibles o si le toca
    //ceder el turno.
    for (int fila = 0; fila < tamanoTablero; fila++){
        for (int columna = 0; columna < tamanoTablero; columna++){
            if (tablero[fila][columna] == ' ' && movimientoValido(fila, columna, tamanoTablero,fichaActual,fichaOponente, false, tablero)){
                return true;
            }
        }
    }
    return false;
}

bool administrarJuego::movimientoValido(int fila, int columna, int TableroTamano, char fichaActual,
                                        char fichaOponente, bool modo, char** tablero)
{
    // Verificar si la casilla en la posición (fila, columna) está vacía
    if (tablero[fila][columna] != ' ') {
        return false;  // La casilla no está vacía, el movimiento no es válido.
    }

    // Direcciones en las que se pueden voltear fichas del oponente
    int direcciones[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    bool movimientoValido = false;
    for (int dir = 0; dir < 8; dir++) {
        int r = fila + direcciones[dir][0];
        int c = columna + direcciones[dir][1];

        bool voltea = false;
        while (r >= 0 && r < TableroTamano && c >= 0 && c < TableroTamano && tablero[r][c] == fichaOponente) {
            voltea = true;
            r += direcciones[dir][0];
            c += direcciones[dir][1];
        }

        if (voltea && r >= 0 && r < TableroTamano && c >= 0 && c < TableroTamano && tablero[r][c] == fichaActual) {
            movimientoValido = true;
            r = fila + direcciones[dir][0];
            c = columna + direcciones[dir][1];

            if(modo==true){
                while (r >= 0 && r < TableroTamano && c >= 0 && c < TableroTamano && tablero[r][c] == fichaOponente) {
                    tablero[r][c] = fichaActual;
                    r += direcciones[dir][0];
                    c += direcciones[dir][1];
                }
            }
        }
    }

    return movimientoValido;
}


bool administrarJuego::hacerJugada(int fila, int columna, int TamanoTablero, char jugador, char oponente, char** tablero)
{
    //realiza el movimiento y cambia las fichas necesarias.
    if (movimientoValido(fila, columna, TamanoTablero, jugador, oponente, true, tablero)) {
        tablero[fila][columna] = jugador;
        return true;
    }
    return false;
}

// Contar las fichas de cada jugador
pair<int, int> administrarJuego::cuentafichas(int TableroTamano, char J1, char J2, char** tablero)
{
    int contadorJ1 = 0;
    int contadorJ2 = 0;

    for (int i = 0; i < TableroTamano; i++) {
        for (int j = 0; j < TableroTamano; j++) {
            if (tablero[i][j] == J1) {
                contadorJ1++;
            }
            else if (tablero[i][j] == J2) {
                contadorJ2++;
            }
        }
    }
    return { contadorJ1, contadorJ2 };
}


void administrarJuego::guardarInformacion(string nombre1, string nombre2, pair<int,int> conteos)
{
    ofstream archivo("informacion.txt", std::ios::app);
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
    }
    time_t tiempoAhora  ;
    time(&tiempoAhora);
    struct tm *miTiempo=localtime(&tiempoAhora);

    if(conteos.first>conteos.second){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1<<"/"
        << miTiempo->tm_year+ 1900<<" "<< miTiempo->tm_hour <<":"<< miTiempo->tm_min
                <<":"<< miTiempo->tm_sec<<","<<nombre1<<","<<conteos.first<<"-"<<conteos.second<<endl;
    }
    else if(conteos.second>conteos.first){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1<<"/"
        << miTiempo->tm_year+ 1900<<" "<< miTiempo->tm_hour - 17 <<":"<< miTiempo->tm_min
        <<":"<< miTiempo->tm_sec<<","<<nombre2<<","<<conteos.second<<"-"<<conteos.first<<endl;
    }
    else if(conteos.second==conteos.first){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1<<"/"
        << miTiempo->tm_year+ 1900<<" "<< miTiempo->tm_hour - 17 <<":"<< miTiempo->tm_min
        <<":"<< miTiempo->tm_sec<<",empate,"<<conteos.first<<"-"<<conteos.second<<endl;
    }
    archivo.close();
}

void administrarJuego::verHistorial()
{
    ifstream archivo("informacion.txt");
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
    }
    if(archivo.peek() == std::ifstream::traits_type::eof()){
        cout<<"No hay informacion para mostrar."<<endl;
    }
    string linea;
    while (getline(archivo, linea)) {
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
        cout<<"*****************************"<<endl;
        cout << "Nombre jugador 1: " << valor1 << endl;
        cout << "Nombre jugador 2: " << valor2 << endl;
        cout << "Fecha y hora: " << valor3 << endl;
        cout << "Ganador: " << valor4 << endl;
        cout << "Numero de fichas: " << valor5 << endl;
        cout<<"*****************************"<<endl;
    }

    archivo.close();
}

void administrarJuego::MenuPrincipal()
{
    cout<<endl;
    cout<<"*********** Menu parcial 2 ***********"<<endl;
    cout<<endl;
    cout<<"1. Jugar"<<endl;
    cout<<"2. Ver historial"<<endl;
    cout<<"0. Pasar salir"<<endl;
    cout<<endl;
}
