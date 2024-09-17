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


struct puntosE{
   float linea;
   float columna;
   float bingo;
   float puntajeTotal;
   float multiplicador;
};

//----Constructor----
Puntos crearPuntaje(){
   Puntos p = malloc(sizeof(struct puntosE));
   p->linea=0;
   p->columna=0;
   p->bingo=0;
   p->puntajeTotal=0;
};

//----Mostrar puntajes----
void mostrarPuntajes(Puntos p);


//----Gets----
int getLinea(Puntos p){
   return p->linea;
};
int getBingo(Puntos p){
   return p->bingo;
};
int getColumna(Puntos p){
   return p->columna;
};
int getPuntajeTotal(Puntos p){
   return p->puntajeTotal;
};
int getMultiplicador(Puntos p){
   return p->multiplicador;
}


//----Sets----
void setLinea(Puntos p, int n){
 p->linea = n;
};
void setBingo(Puntos p, int n){
p->bingo = n;
};
void setColumna(Puntos p, int n){
p->columna = n;
};
void setPuntajeTotal(Puntos p, int n){
p->puntajeTotal = n;
};

void calcularPuntaje(Puntos p, Jugador j){

		p->puntajeTotal = p->bingo + p->linea + p->columna;

		 if(getBingo(p)>=70){
                if(getCont(j) < 30){
                    p->puntajeTotal = p->puntajeTotal * 2;
                    p->multiplicador = 2;
                }else if(getCont(j) >=30 && getCont(j) < 50){
                    p->puntajeTotal = p->puntajeTotal * 1.7;
                    p->multiplicador = 1.7;
                }else if(getCont(j) >= 50 && getCont(j) < 70){
                    p->puntajeTotal = p->puntajeTotal * 1.5;
                    p->multiplicador = 1.5;
                }else{
                    p->puntajeTotal = p->puntajeTotal;
                    p->multiplicador = 1;
                }
		}

		printf("\nPuntaje Total: %.2f",p->puntajeTotal);
		printf("\nMultiplicador: x%.1f\n",p->multiplicador);



}
void tabla(){
   printf("\n---- HISTORIAL ----\n");
	FILE * tabla;
	tabla = fopen("historial.txt", "r");
    while (!feof(tabla)){
    	char aux[50] = " ";
    	fgets(aux, 50,tabla);
    	printf("%s",aux);

	}
	fclose(tabla);
}

void guardarArchivo(Puntos p, Jugador j){

	FILE * Puntos;
	Puntos = fopen("historial.txt", "a");
	fprintf(Puntos, "\n=====================================\n             PUNTAJE");
	fprintf(Puntos, "\n=====================================\n");
	fprintf(Puntos, "Usuario: %s \n",getNombre(j));
	fprintf(Puntos, "Linea: %f\n",p->linea);
	fprintf(Puntos, "Columna: %f\n",p->columna);
	fprintf(Puntos, "Bingo: %f\n",p->bingo);
	fprintf(Puntos, "Puntos Totales: %f\n",p->bingo);
	fprintf(Puntos, "\n=====================================");
	fclose(Puntos);
}
