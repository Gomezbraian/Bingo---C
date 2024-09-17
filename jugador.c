#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#define COLUMNA 5
#define RENGLON 3
#define ptsColumna 10
#define ptsLinea 20
#define ptsBingo 70
#include "jugador.h"
#include "carton.h"
#include "puntos.h"


struct jugadorE{
    char nombre[40];
    char apellido[40];
    char dni[9];
    int cantCartones;
    int flagBingo;
    int bolita;
    int cont;
    Carton carton[3];
    Puntos puntaje;
};

Jugador cargarJugador(){
    Jugador j = malloc(sizeof(struct jugadorE));
    j->puntaje = crearPuntaje();
    char auxNombre[40] = " ";
    char auxApellido[40] = " ";
    char auxDNI[9] = " ";
    int cantidad;
    int opcion;
    int verificador=0;
    int flag=0;

    printf("\n=========== REGISTRO ===========\n");
    printf("\nIngrese su nombre: ");
    fflush(stdin);
    gets(auxNombre);
    strcpy(j->nombre, auxNombre);
    printf("\n--------------------------------\n");
    printf("\nIngrese su apellido: ");
    fflush(stdin);
    gets(auxApellido);
    strcpy(j->apellido, auxApellido);
    printf("\n--------------------------------\n");
    do{
        printf("\nIngrese su DNI: ");
        fflush(stdin);
        gets(auxDNI);
        strcpy(j->dni, auxDNI);
        if(checkDNI(j)!=8){
            printf("DNI invalido, intente nuevamente.");
        }
    }while(checkDNI(j)!=8);
    printf("\n== Registro completado de forma exitosa! ==   \nBienvenido %s al Bingo\n", j->nombre);
    Sleep(1000);
    printf("\nCargando menu de cartones...");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    printf("\nAccediendo al menu de cartones.");
    Sleep(800);
    system("cls");
    mostrarDatos(j);
    do{
    printf("\n------------ Menu de cartones -----------\n");
    printf("|1. Elegir cantidad de cartones a jugar.|\n");
    printf("|2. Generar carton aleatorio.           |\n");
    printf("|3. Generar carton personalizado.       |\n");
    printf("|4. Jugar.                              |\n-----------------------------------------\n ");
    printf("\n%cIngrese una opcion: ",175);
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
                system("cls");
                cantidad = eleccionCartones();
                j->cantCartones = cantidad;
                verificador=1;
        break;
        case 2:
            if(verificador==2){
                printf("\nYa cargaste los cartones!");
                Sleep(800);
                system("cls");
            }
            if(verificador==1){
                    verificador=2;
            system("cls");
            printf("\nElegiste cargar los cartones aleatorios.\n");
            for(int i=0;i<cantidad;i++){
                j->carton[i]=cargarCartonAleatorio();
            }
            if(j->cantCartones==1){
                printf("\n----------Carton cargado----------\n");
                Sleep(500);
                printf("\nVolviendo al menu de cartones...");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
            }else{
                printf("\n----------Cartones cargados--------\n");
                Sleep(500);
                printf("\nVolviendo al menu de cartones...");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
            }
            flag=1;
            Sleep(500);
            system("cls");
            }
            if(verificador==0){
                system("cls");
                printf("\nPrimero tenes que elegir la cantidad de cartones que queres usar!\n");
                Sleep(500);
            }
        break;
        case 3:
            if(verificador==1){
            system("cls");
            printf("\nElegiste cargar los cartones personalizados-\n");
            for(int i=0;i<cantidad;i++){
                j->carton[i]=cargarCartonManual(i);
                printf("\n----------Carton cargado----------\n");
                Sleep(500);
                printf("\nVolviendo al menu de cartones...");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
            }
            if(j->cantCartones>1){
                printf("\n----------Cartones cargados----------\n");
                Sleep(500);
                printf("\nVolviendo al menu de cartones...");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
            }
            flag=1;
            Sleep(500);
            system("cls");
            }
            if(verificador==0){
                system("cls");
                printf("\nPrimero tenes que elegir la cantidad de cartones que queres usar!\n");
                Sleep(500);
            }
        break;
        case 4:
            if(flag==0){
                printf("\nNo podes empezar a jugar una partida si no tenes los cartones listos!\n");
            }
            if(flag==1){
            system("cls");
            printf("\nCargaste todo! En breve empezara tu partida %s.\n\n", j->nombre);
            printf("Cargando partida...");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            system("cls");
            printf("\nPartida cargada con exito.");
            opcion=5;
            }

        break;
        default:
            printf("\nERROR! Opcion no valida.");
            Sleep(500);
            system("cls");
            break;
    }

    }while(opcion != 5);

    return j;
}
Jugador cargarMaquina(Jugador j){
    Jugador pc = malloc(sizeof(struct jugadorE));
    pc->puntaje = crearPuntaje();
    char aux[40] = "PC";
    strcpy(pc->nombre, aux);
    for(int i=0;i<j->cantCartones;i++){
        pc->carton[i]=cargarCartonAleatorio();
    }
    return pc;
}

//----Check----
int checkDNI(Jugador x){
    int n=0;
    char num[11] = "0123456789";
    for (int i=0;i<11;i++){
        for (int j=0;j<strlen(x->dni);j++){
            if(num[i] == x->dni[j]){
                n++;
            }
        }
    }
    return n;
}


//----Mostrar----
void mostrarDatos(Jugador j){
    printf("----------- Jugador  %s -----------\n", j->nombre);
    printf("Nombre: %s\n", j->nombre);
    printf("Apellido: %s\n", j->apellido);
    printf("DNI: %s\n", j->dni);
    printf("--------------------------------------\n");
}


//----Funciones----
int eleccionCartones(){
	int cantiCartones=-1 ;
	printf("\nCon cuantos cartones quiere jugar?\n");
    printf("\nHay disponible 3 cartones para elegir, puede jugar con 1, 2 o 3.\n");
	do{
		scanf("%d",&cantiCartones);
		if((cantiCartones>3) || (cantiCartones<1)){
		printf("Error! Minimo 1 carton y maximo 3 cartones.\n");
		}
		}while((cantiCartones<1)||(cantiCartones>3));

    if(cantiCartones==1){
        printf("\nElegiste jugar con 1 carton.\n\n");
    }
    if(cantiCartones==2){
        printf("\nElegiste jugar con 2 cartones.\n\n");
    }
    if(cantiCartones==3){
        printf("\nElegiste jugar con 3 cartones.\n\n");
    }
	return cantiCartones;
}


//----Procedimientos----
void jugar(Jugador jugador, Jugador pc){

    int i=0;
    int bolsa[90];
    int opcion;
    int verificarLinea=0;
    int verificarColumna=0;
    int verificarBingo=0;
    int cantidad = jugador->cantCartones;
    int flagLinea = 0;
    int flagColumna = 0;

    for(int j=0;j<90;j++){
        bolsa[j]=0;
    }
    generarBolsa(bolsa);


    for(i=0;i<90;i++){
        jugador->bolita=bolsa[i];
        pc->bolita=bolsa[i];
        jugador->cont++;
        pc->cont++;
        printf("\nRONDA %d", i);
        printf("\nSalio el numero %d\n", bolsa[i]);

        if(jugador->cantCartones==1){
            printf("\n------- Carton del jugador --------\n");
        }
        if(jugador->cantCartones>1){
            printf("\n------ Cartones del jugador -------\n");
        }
        for(int t=0;t<cantidad;t++){
            mostrarMatriz(jugador->carton[t], jugador->bolita);
            if(bingo(jugador->carton[t])==1 && verificarBingo !=1){
                setBingo(jugador->puntaje, 70);
                verificarBingo=1;
                printf("\n%s consiguio hacer bingo! +70 puntos.\n", jugador->nombre);
                jugador->flagBingo=1;
                i=90;
            }
            if(linea(jugador->carton[t])==1 && verificarLinea !=1){
                verificarLinea=1;
                setLinea(jugador->puntaje, 20);
                printf("\n%s consiguio linea! +20 puntos.\n", jugador->nombre);
            }
            if(columna(jugador->carton[t])==1 && verificarColumna !=1){
                verificarColumna=1;
                setColumna(jugador->puntaje, 10);
                printf("\n%s consiguio columna! +10 puntos.\n", jugador->nombre);
            }
        }
        printf("\n\n");
        if(jugador->cantCartones==1){
            printf("\n--------- Carton de la PC ---------\n");
        }
        if(jugador->cantCartones>1){
            printf("\n-------- Cartones de la PC --------\n");
        }
        for(int t=0;t<cantidad;t++){
            mostrarMatriz(pc->carton[t], pc->bolita);
            if(bingo(pc->carton[t])==1 && verificarBingo!=1){
                setBingo(pc->puntaje, 70);
                verificarBingo=1;
                printf("\n%s consiguio hacer bingo! +70 puntos.\n", pc->nombre);
                pc->flagBingo=1;
                i=90;
            }
            if(linea(pc->carton[t])==1 && verificarLinea !=1){
                verificarLinea=1;
                setLinea(pc->puntaje, 20);
                printf("\n%s consiguio linea! +20 puntos.\n", pc->nombre);
            }
            if(columna(pc->carton[t])==1 && verificarColumna !=1){
                verificarColumna=1;
                setColumna(pc->puntaje, 10);
                printf("\n%s consiguio columna! +10 puntos.\n", pc->nombre);
            }
        }
        Sleep(500);
        system("cls");

    }
    printf("\n%s: ", jugador->nombre);
	calcularPuntaje(jugador->puntaje, jugador);
	printf("\nPC: ");
	calcularPuntaje(pc->puntaje, pc);
	printf("\n");
    guardarArchivo(jugador->puntaje, jugador);
    guardarArchivo(pc->puntaje, pc);
}
void inicializar(Jugador j, Jugador pc){
    setBolita(j,0);
    setFlagBingo(j,0);
    setBingo(j->puntaje,0);
    setLinea(j->puntaje,0);
    setColumna(j->puntaje,0);
    setPuntajeTotal(j->puntaje,0);
    setBingo(pc->puntaje,0);
    setLinea(pc->puntaje,0);
    setColumna(pc->puntaje,0);
    setPuntajeTotal(pc->puntaje,0);
}

void setFlagBingo(Jugador j, int n){
    j->flagBingo= n;
}
void setBolita(Jugador j, int n){
    j->bolita= n;
}
int getFlagBingo(Jugador j){
return j->flagBingo;
};
int getCantiCartones(Jugador j){
return j->cantCartones;
};
char *getApellido(Jugador j){
    return j->apellido;
}
char *getNombre(Jugador j){
    return j->nombre;
}

int getCont(Jugador j){
    return j->cont;
}


