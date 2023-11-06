#include <iostream>
#include <jugador.h>
#include <tablero.h>
#include "administrarjuego.h"
#include <string>

using namespace std;

int main()
{
    int opcion = 1;
    while(opcion!=0){
        administrarJuego juego;
        juego.MenuPrincipal();
        cin>>opcion;
        switch (opcion) {
        case 1:
        {
            const int tamano =8;
            Tablero tabla(tamano);
            tabla.TableroInicial(tamano,tabla.getTablero());

            string jugador1, jugador2;
            cout<<"Ingrese el nombre del primer jugador: "<<endl;
            cin>>jugador1;
            cout<<"Ingrese el nombre del segundo jugador: "<<endl;
            cin>>jugador2;
            Jugador jugadorUno(jugador1, '*');
            Jugador jugadorDos(jugador2, '-');

            cout<<"El jugador 1 ("<<jugadorUno.getNombre()<<") tiene la ficha: "<<jugadorUno.getColorFicha()<<endl;
            cout<<"El jugador 2 ("<<jugadorDos.getNombre()<<") tiene la ficha: "<<jugadorDos.getColorFicha()<<endl;
            cout<<"Inicia el jugador 1"<<endl;
            char jugadorActual = '*';
            cout<<"------------------------"<<endl;
            while(true)
            {
                tabla.dibujarTablero(tabla.getTamano(), tabla.getTablero());
                cout<<endl;
                char oponente = (jugadorActual ==  '*') ? '-' : '*';                
                if(juego.validarMovimientos(jugadorActual, oponente,tabla.getTamano(), tabla.getTablero())!=true){
                    jugadorActual = (jugadorActual ==  '*') ? '-' : '*';
                    oponente = (jugadorActual ==  '*') ? '-' : '*';
                    if(juego.validarMovimientos(jugadorActual, oponente,tabla.getTamano(), tabla.getTablero())!=true){
                        // Verificar el final del juego
                        pair<int, int> conteoFichas = juego.cuentafichas(tabla.getTamano(), '*','-', tabla.getTablero());
                        if ((juego.validarMovimientos(jugadorActual, oponente, tabla.getTamano(), tabla.getTablero())) && (juego.validarMovimientos(oponente, jugadorActual, tabla.getTamano(), tabla.getTablero()))
                            || (conteoFichas.first + conteoFichas.second == tamano * tamano)) {
                            tabla.dibujarTablero(tabla.getTamano(), tabla.getTablero());
                            juego.guardarInformacion(jugadorUno.getNombre(),jugadorDos.getNombre(), conteoFichas);
                            if (conteoFichas.first > conteoFichas.second) {
                                cout << "¡Jugador * gana "<<conteoFichas.first <<" - "<<conteoFichas.second<<"!" << endl;
                                tabla.~Tablero();
                            }
                            else if (conteoFichas.first < conteoFichas.second) {
                                cout << "¡Jugador - gana "<<conteoFichas.second <<" - "<<conteoFichas.first<<"!"  << endl;
                                tabla.~Tablero();
                            }
                            else {
                                cout << "¡Empate a "<<conteoFichas.first<<"!" << endl;
                                tabla.~Tablero();
                            }
                            break;
                        }
                    }
                }
                cout << "Turno del jugador " << jugadorActual << endl;
                cout<<"El oponente es: "<<oponente<<endl;

                pair<int, int> conteos = juego.cuentafichas(tabla.getTamano(), jugadorActual, oponente, tabla.getTablero());
                cout << jugadorActual<<" tiene " << conteos.first << " puntos. "<<oponente<<" tiene " << conteos.second << " puntos." << endl;

                int fila=0;
                int columna=0;
                bool entradaValida = false;

                while(!entradaValida){
                    jugadorUno.indicarPosicion(fila, columna, tamano);

                    if (!juego.movimientoValido(fila, columna,tabla.getTamano(), jugadorActual,oponente, false, tabla.getTablero())) {
                        cout << "Movimiento no valido. Intentalo de nuevo." << endl;
                    }
                    else {
                        entradaValida = true;
                    }
                }
                if (juego.hacerJugada(fila, columna, tabla.getTamano(),jugadorActual, oponente, tabla.getTablero())) {
                    jugadorActual = (jugadorActual ==  '*') ? '-' : '*';
                }
            }
            break;
        }
        case 2:
        {
            juego.verHistorial();
            break;
        }
        default:
            if(opcion!=0)
                cout<<"Opcion no valida"<<endl;
            break;
        }
    }
    return 0;
}

