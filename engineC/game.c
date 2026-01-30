
/*  -------- BIBLIOTECAS REQUERIDAS -------------*/
#include "game.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* ------ FUNCIONES PRIVADAS ---------*/
static void Colocar_Minas(Juego *juego); /* COLOCAR MINAS*/
static void calcular_adyacencias(Juego *juego); /* CALCULO DE VECINOS */
static void Descubrir_Recursivo(Juego *juego, int i, int j); /* DESCUBRIR VECINOS */

Juego *CrearJuego(int dimension, int total_minas) /* CREAR VIDEOJUEGO */
{
   Juego *juego = malloc(sizeof(Juego));
   if(!juego)
    {
       return NULL;
    }

   juego->dimension = dimension;
   juego->total_minas = total_minas;
   juego->descubiertas = 0;
   juego->estado = GAME_RUNNING;

   juego->tablero = malloc(sizeof(Casilla*) * dimension);
   if(!juego->tablero)
   {
       free(juego);
       return NULL;
   }

   for(int i=0; i<dimension; i++)
   {
       juego->tablero[i] = calloc(dimension, sizeof(Casilla));
       if(!juego->tablero[i])
       {
           for(int j=0; j<i; j++)
           {
               free(juego->tablero[j]);
           }
           free(juego->tablero);
           free(juego);
           return NULL;
       }
   }

   /* COLOCO LAS MINAS Y CALCULO LAS ADYACENCIAS */
   Colocar_Minas(juego);
   calcular_adyacencias(juego);

   return juego;

}
void DestruirJuego(Juego *juego) /* FINALIZAR VIDEOJUEGO */
{
    if(!juego)
        return;

    for(int i=0; i<juego->dimension; i++)
    {
        free(juego->tablero[i]);
    }
    free(juego->tablero);
    free(juego);
}

static void Colocar_Minas(Juego *juego) /* LLENAR CASILLAS */
{
    int minas_colocadas = 0;

    while(minas_colocadas < juego->total_minas)
    {   // Elegir de forma Aleatoria las posiciones
        int fila = rand () % juego->dimension;
        int col = rand () % juego->dimension;

        if(!juego->tablero[fila][col].Mina)
        {
            juego->tablero[fila][col].Mina = 1;
            minas_colocadas ++;
        }
    }
}
static void calcular_adyacencias(Juego *juego)
{   /* Para lograr calcular las adyacencias en un elemento debemos visitar sus 8 vecinos que estaran representados por coordenadas
    (Arriba, abajo, diagonales) y sumarles +1 cuando se requiera acceder a ellas y verificar su contenido... */
    int dx[8] = {-1,-1,-1, 0,0, 1,1,1}; /*Plano Cartesiano*/
    int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    for(int i=0;i<juego->dimension;i++) /* Recorrer matriz*/
        {
            for(int j=0;j<juego->dimension;j++)
            {
                if(juego->tablero[i][j].Mina) /* Si es MINA que pase al siguiente casillero usando Continue */
                    continue;

                int cont = 0;
                /* Recorrer sus 8 vecinos */
                for(int k=0; k<8; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    /* Verifico Limites */
                    if(ni >= 0 && ni<juego->dimension && nj >= 0 && nj < juego->dimension)
                    {
                        if(juego->tablero[ni][nj].Mina)
                            cont++;
                    }
                }

                juego->tablero[i][j].Adyacentes = cont;
            }
        }
}
int JUEGO_FLAGS(Juego *juego, int i, int j)
{

    Casilla *c = &juego->tablero[i][j];

    if(c->Descubierta)
        return ERROR;

    c->Bandera = !c->Bandera;
    return c->Bandera ? IN : OUT;
}
int JUEGO_REVELAR(Juego *juego, int i, int j)
{

    Casilla *c = &juego->tablero[i][j];
    if(c->Descubierta) /* Si hay estaba descubierta sale o se bloquea*/
        return ERROR; /* CASILLERO YA DESCUBIERTO */

    if(c->Bandera)
        {
            c->Bandera = 0;
        }

    if(c->Mina)
        {
            juego->estado = GAME_OVER;
            return GAME_OVER;
        }

    Descubrir_Recursivo(juego, i, j);

    int total_celdas = juego->dimension * juego->dimension;
    if (juego->descubiertas == total_celdas - juego->total_minas)
        juego->estado = GAME_WIN;

    return IN;
}

static void Descubrir_Recursivo(Juego *juego, int i, int j)
{
    Casilla *c = &juego->tablero[i][j];

    if(c->Bandera || c->Descubierta )
        return;

    c->Descubierta = 1;
    juego->descubiertas ++;

    if(c->Adyacentes != 0) /*Si no tiene adyacentes, expandimos */
        return;

    int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
    int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    for(int k = 0; k<8; k++)
    {
        Descubrir_Recursivo(juego, i + dx[k], j + dy[k]);
    }

}
