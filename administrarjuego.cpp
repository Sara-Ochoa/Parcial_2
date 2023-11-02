#include "administrarjuego.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

administrarJuego::administrarJuego()
{

}

bool administrarJuego::validarMovimientos(char &fichaActual,char &fichaOponente, int &tamanoTablero)
{
    //recibe un char que es el color de ficha para comprobar si esa tiene movimientos posibles o si le toca
    //ceder el turno.
    for (int fila = 0; fila < tamanoTablero; fila++){
        for (int columna = 0; columna < tamanoTablero; columna++){
            if (tablero[fila][columna] == " " && movimientoValido(fila, columna, tamanoTablero,fichaActual,fichaOponente)){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

bool administrarJuego::movimientoValido(int fila, int columna, int tamanoTablero, char fichaActual, char fichaOponente)
{
    // Verificar si la casilla en la posición (fila, columna) está vacía
    if (tablero[fila][columna] != " ") {
        return false;  // La casilla no está vacía, el movimiento no es válido.
    }

    bool movimientoValido = false;

    // Direcciones en las que se pueden voltear fichas del oponente
    int direcciones[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < tamanoTablero; i++) {
        int dx = direcciones[i][0];
        int dy = direcciones[i][1];

        // Variables para rastrear si se pueden voltear fichas del oponente en esta dirección
        bool fichasParaVoltear = false;
        int x = fila + dx;
        int y = columna + dy;

        while (x >= 0 && x < tamanoTablero && y >= 0 && y < tamanoTablero) {
            if (tablero[x][y] == fichaOponente) {
                fichasParaVoltear = true;
            } else if (tablero[x][y] == fichaActual) {
                if (fichasParaVoltear) {
                    movimientoValido = true;
                }
                break;
            } else {
                break;
            }

            x += dx;
            y += dy;
        }
    }

    return movimientoValido;
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
    time_t tiempoAhora  ;
    time(&tiempoAhora);
    struct tm *miTiempo=localtime(&tiempoAhora);

    if(numeroFichas1>numeroFichas2){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1<<"/"
        << miTiempo->tm_year+ 1900<<" "<< miTiempo->tm_hour - 17 <<":"<< miTiempo->tm_min
                <<":"<< miTiempo->tm_sec<<","<<nombre1<<","<<numeroFichas1<<"-"<<numeroFichas2<<endl;
    }
    else if(numeroFichas2>numeroFichas1){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1<<"/"
        << miTiempo->tm_year+ 1900<<" "<< miTiempo->tm_hour - 17 <<":"<< miTiempo->tm_min
        <<":"<< miTiempo->tm_sec<<","<<nombre2<<","<<numeroFichas2<<"-"<<numeroFichas1<<endl;
    }
    else if(numeroFichas2==numeroFichas1){
        archivo<<nombre1<<","<<nombre2<<","<<miTiempo->tm_mday<<"/"<< miTiempo->tm_mon+ 1<<"/"
        << miTiempo->tm_year+ 1900<<" "<< miTiempo->tm_hour - 17 <<":"<< miTiempo->tm_min
        <<":"<< miTiempo->tm_sec<<",empate,"<<numeroFichas2<<"-"<<numeroFichas1<<endl;
    }
    archivo.close();
}

void administrarJuego::verHistorial()
{
    ifstream archivo("archivo.txt");
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

void administrarJuego::MenuPrincipal()
{
    cout<<endl;
    cout<<"*********** Menu parcial 2 ***********"<<endl;
    cout<<endl;
    cout<<"1. Jugar"<<endl;
    cout<<"2. Ver historial"<<endl;
    cout<<endl;
}
