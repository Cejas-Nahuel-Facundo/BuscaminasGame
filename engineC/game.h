#ifndef GAME_H
#define GAME_H

/*  -------- ESTADOS LOGICOS --------------------*/
#define OUT 0
#define ERROR -1
#define IN 1
/* --------- ESTADOS DE JUEGO -------------------*/
#define GAME_OVER 2
#define GAME_WIN 1
#define GAME_RUNNING 0

/* --------- ESTRUCTURAS NECESARIAS -------------*/
typedef struct{

    unsigned char Mina; /* MINA DE UN CASILLERO */
    unsigned char Bandera; /* BANDERA DE UN CASILLERO */
    unsigned char Descubierta; /* ESTADO: DESCUBIERTO O NO */
    unsigned char Adyacentes; /* VECINOS DE UN CASILLERO */

}Casilla;

typedef struct
{
    Casilla **tablero; /* STRUCT QUE GUARDA ESTADOS DE LA CASILLA */
    int dimension; /* DIMENSION ELEJIDA POR EL USUARIO: DESDE 8X8 A 32X32*/
    int total_minas; /* CALCULABLE CON EL PORCENTAJE QUE ELIGA EL USUARIO Y SU DIMENSION */
    int descubiertas; /* CAMBIANDO MIENTRAS SE CORRE */
    int estado; /* VICTORIA, DERROTA, JUGANDO*/

}Juego;
/* ----------- FUNCIONES PUBLICAS  -------------*/
/* ----------- APIS DEL VIDEOJUEGO -------------*/
/* ESTAS FUNCIONES SERAN USADAS Y LLAMADAS DESDE EL LENGUAJE PYTHON MAS SU INTERFAZ GRAFICA */

Juego *CrearJuego(int dimension, int total_minas); /* CREAR VIDEOJUEGO */
void DestruirJuego(Juego *juego); /* FINALIZAR VIDEOJUEGO */
int JUEGO_REVELAR(Juego *juego, int i, int j); /* CLICK IZQUIERDO */
int JUEGO_FLAGS(Juego *juego, int i, int j); /* CLICK DERECHO*/

#endif


