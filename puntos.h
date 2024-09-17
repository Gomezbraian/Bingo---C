#ifndef PUNTOS_H_INCLUDED
#define PUNTOS_H_INCLUDED

struct puntosE;

typedef struct puntosE * Puntos;

//- - - - Constructor - - - -
Puntos crearPuntaje();


//- - - - Gets - - - -
int getLinea(Puntos p);
int getBingo(Puntos p);
int getColumna(Puntos p);
int getPuntajeTotal(Puntos p);
int getMultiplicador(Puntos p);


//- - - - Sets - - - -
void setLinea(Puntos p, int n);
void setBingo(Puntos p, int n);
void setColumna(Puntos p, int n);
void setPuntajeTotal(Puntos p, int n);

void tabla();
void guardarArchivo(Puntos p, Jugador j);

int multiplicador(float bingo, int bolas);

void calcularPuntaje(Puntos p, Jugador j);




#endif // PUNTOS_H_INCLUDED
