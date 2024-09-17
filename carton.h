
#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct cartonE;

typedef struct cartonE * Carton;


//- - - - Constructor - - - -
//PRE:El usuario elije la cantidad de cartones con las que se jugara;
//POST:Se cargan los cartones de forma manual;
Carton cargarCartonManual(int numero);
//PRE:El usuario elije la cantidad de cartones con las que se jugara;
//POST:Se cargan los cartones aleatoriamente de forma automatica;
Carton cargarCartonAleatorio();

//- - - - Mostrar - - - -
//PRE:Los cartones tienen que haber sido cargados;
//POST:Se muestra la matriz de cartones cargados en pantalla;
void mostrarMatriz(Carton c, int n);

//- - - - Buscador - - - -
//PRE:El usuario elige de que forma cargar los cartones;
//POST:Comprueba que no se repitan los numeros en los cartones;
int buscarEnMatriz(Carton c, int datoBuscado);
//PRE:Generar una bolsa de 90 bolitas;
//POST:Verifica que las bolitas no salgan repetidas;
int buscarEnVector(int c[], int datoBuscado);

//- - - - Funcion - - - -
void generarBolsa(int bolsa[]);

//- - - - Procedimientos - - - -
//PRE:Se sacan bolillas y se comparan con los numeros de los cartones ya cargados;
//POST:Comprueba si ocurrio "Linea";
int linea(Carton c);
//PRE:Se sacan bolillas y se comparan con los numeros de los cartones ya cargados;
//POST:Comprueba si ocurrio "Columna";
int columna(Carton c);
//PRE:Se sacan bolillas y se comparan con los numeros de los cartones ya cargados;
//POST:Comprueba si ocurrio "Bingo";
int bingo(Carton c);


#endif
