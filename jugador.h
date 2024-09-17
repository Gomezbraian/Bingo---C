#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct jugadorE;

typedef struct jugadorE * Jugador;

//- - - - Constructor - - - -
//PRE:Se tiene que haber elegido la opcion de iniciar una partida;
//POST:Se obtienen los datos del usuario:
Jugador cargarJugador();
//PRE:Tienen que estar cargados todos los datos del usuario;
//POST:Se crean los datos de la PC y sus respectivos cartones;
Jugador cargarMaquina();

//- - - - Destructor - - - -
//PRE:Jugador tiene que estar cargado;
//POST:Se reinician los datos del jugador;
void destroy(Jugador j);

//- - - - Checks - - - -
//PRE:El usuario tiene que ingresar sus datos;
//POST:Se verifica que el dni ingresado sea valido;
int checkDNI(Jugador x);


//- - - - Mostrar - - - -
//PRE:Ya tienen que estar cargados los datos del jugador y la pc;
//POST:Se muestran los datos cargados del jugador;
void mostrarDatos(Jugador j);

//- - - - Funciones - - - -
//PRE:Ya tiene que estar registrado el jugador;
//POST:El jugador determina la cantidad de cartones a utilizar;
int eleccionCartones();

//- - - - Set - - - -
void setFlagBingo(Jugador j, int n);
void setBolita(Jugador j, int n);


//- - - - Procedimientos - - - -
//PRE:Deben estar cargados los datos y cartones del jugador y la pc;
//POST:Se comienza el juego hasta que alguien consiga hacer Bingo;
void jugar(Jugador j, Jugador pc);
//PRE:
//POST:Se inician los valores en cero;
void inicializar(Jugador j, Jugador pc);



//- - - - Gets - - - -
int getFlagBingo(Jugador j);
int getCantiCartones(Jugador j);
int getCont(Jugador j);
char *getApellido(Jugador j);
char *getNombre(Jugador j);


#endif
