#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define COLUMNA 5
#define RENGLON 3
#define ptsColumna 10
#define ptsLinea 20
#define ptsBingo 70
#include "jugador.h"
#include "carton.h"
#include "puntos.h"



int main(){
    srand(time(NULL));
    Jugador jugador;
    Jugador pc;
    int opc=0;
    printf("\n=====================================");
    printf("\n|         BIENVENIDO AL BINGO       |");
    printf("\n=====================================\n");
    Sleep(800);
    printf("Cargando programa...");
    Sleep(500);
    printf("..");
    Sleep(500);
    printf(".");
    system("cls");
    do{

        printf("\n----------- Inicio ------------");
        printf("\n|1. Iniciar una nueva partida.|");
        printf("\n|2. Ver historial de puntajes.|");
        printf("\n|3. Salir del juego.          |\n-------------------------------");
        printf("\n\n%cIngrese una opcion: ",175);
        scanf("%d", &opc);
        switch(opc){
            case 1:

                jugador = cargarJugador();
                pc = cargarMaquina(jugador);
                system("cls");
                mostrarDatos(jugador);
                printf("\n");
                jugar(jugador, pc);
            break;
            case 2:
                tabla();
            break;
            case 3:
                printf("\nGracias por jugar, saliendo del programa...");
                Sleep(300);
                printf(".");
                Sleep(300);
                printf(".");
            break;
            default:
                printf("\nError! Opcion no valida para este menu.\n");
                break;
        }

    }while(opc!=3);

    return 0;
}
