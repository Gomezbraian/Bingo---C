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


struct cartonE{
    int carton[RENGLON][COLUMNA];
};

//----Constructor----
Carton cargarCartonAleatorio(){
    Carton m = malloc(sizeof(struct cartonE));
    int n;
    for(int i=0;i<RENGLON;i++){
        for(int j=0;j<COLUMNA;j++){
            m->carton[i][j]=0;
            do{
                n = rand()%91;
            }while (buscarEnMatriz(m,n)==1);
            m->carton[i][j]=n;
        }
    }
    return m;
}

Carton cargarCartonManual(int numero){
    Carton a = malloc(sizeof(struct cartonE));
    int n;
    for(int i=0;i<RENGLON;i++){
        for(int j=0;j<COLUMNA;j++){
            do{
                printf("\nIngrese un numero para el carton %d en el renglon %d y columna %d\n", numero+1, i+1, j+1);
                scanf("%d", &n);
                if(n <1 || n >90){
                    printf("Numero invalido, tiene que ser entre 1 y 90.");
                }
            }while(n<1 || n>90);
            while(buscarEnMatriz(a, n)==1){
                printf("Error! No se permiten numeros repetidos.\n");
				printf("\nIngrese un numero para el carton %d en el renglon %d y columna %d\n", numero+1, i+1, j+1);
				scanf("%d", &n);
                if(n<1 || n>90){
                    do{
                        printf("Debe ser un numero entre 1 y 90:\n");
                        scanf("%d", &n);
                    }while(n<1 || n>90);
                }
            }
            a->carton[i][j]=n;
        }
    }
    return a;
}

//----Destructor----
void destroy(Jugador j){
    free(j);
}


//----Mostrar----
void mostrarMatriz(Carton c, int n){
    printf("\n-----------------------------------\n");
    for(int i=0;i<RENGLON;i-=-1){
		for(int j=0;j<COLUMNA;j-=-1){
			if(c->carton[i][j] == n){
				c->carton[i][j] = c->carton[i][j] * -1;
			}
            if((c->carton[i][j]<10)&&(c->carton[i][j]>0)){
                printf("|   %d |",c->carton[i][j]);
            }
            if((c->carton[i][j]<1)&&(c->carton[i][j]>-10)){
                printf("|  %d |",c->carton[i][j]);
            }
            if((c->carton[i][j]<-9)&&(c->carton[i][j]>-91)){
			    printf("| %d |",c->carton[i][j]);
            }
            if((c->carton[i][j]>9)&&(c->carton[i][j]<91)){
			    printf("|  %d |",c->carton[i][j]);
            }
		}
		printf("\n");
	}
    printf("-----------------------------------\n");
}

//----Buscador----
int buscarEnMatriz(Carton c, int datoBuscado){
    int encontrado = -1; //cuando no lo encuentra da -1, de no ser asi da 1
    for (int i = 0 ; i<RENGLON; i++){
        for ( int j = 0; j<COLUMNA; j++){
            if(c->carton[i][j]==datoBuscado){
                encontrado = 1;
            }
        }
    }
    return encontrado;
}

int buscarEnVector(int c[], int datoBuscado){
      int encontrado = -1; //cuando no lo encuentra da -1, de no ser asi da 1
    for (int i = 0 ; i<90; i++){

         if(c[i]==datoBuscado){
                encontrado = 1;
            }
        }

    return encontrado;
}

//----Funciones----
void generarBolsa(int bolsa[]){
int numero=0;
for ( int i = 0; i<90; i++){
    bolsa[i]= 0;
}
for ( int i = 0; i<90; i++){
            	do{
                	numero = rand()%91+1;
            	}while (buscarEnVector(bolsa,numero)==1);
            	 bolsa[i]= numero;
			}
}

//----Procedimientos----
int linea(Carton c){
    int cont = 0;
    int linea = 0;
    int i,j;
    for(i=0;i<RENGLON;i++){
        for (j=0;j<COLUMNA;j++){
            if (c->carton[i][j]<1){
                cont++;
            }
        }
        if(cont<COLUMNA){
            cont=0;
        }
        if(cont==COLUMNA){
            linea = 1;
            i=RENGLON;
        }
    }
    return linea;
}

int columna(Carton c){
    int cont =0;
    int columna=0;
    int i,j;
    for(i=0;i<COLUMNA;i++){
        for (j=0;j<RENGLON;j++){
            if (c->carton[j][i]<1){
                cont++;
            }
        }
        if(cont<RENGLON){
            cont=0;
        }
        if(cont==RENGLON){
            columna = 1;
            i=COLUMNA;
        }
    }
    return columna;
}

int bingo(Carton c){
    int cont =0;
    int bingo =0;
    for(int i=0;i<RENGLON;i++){
        for (int j=0;j<COLUMNA;j++){
            if (c->carton[i][j]<1){
                cont++;
            }
        }
        if(cont==COLUMNA*RENGLON){
            bingo=1;
        }
        if(cont<COLUMNA*RENGLON){
            bingo=0;
        }
    }
    return bingo;
}

