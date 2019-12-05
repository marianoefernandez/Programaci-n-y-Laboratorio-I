#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10
#include "Fecha.h"

typedef struct
{
    int codigo;
    int codigoVis;
    int codigoLocal;
    int codigoReferi;
    int isEmpty;
    eFecha fechaP;
}ePartido;

//0-MENU
void mostrarMenuP();

void printModificationMenuP();

//1-INICIALIZAR
int inicializarPartidos(ePartido*, int);

int getFreeP(ePartido*,int); //TERMINADA

int buscarPartidoPorCodigo(ePartido*,int,int);

//2-ALTAS
int agregarPartidos(ePartido*,int,int);


//3-ORDERNAR
int ordenarPartidosPorFecha(ePartido*, int, int);

//4-MOSTRAR


//5-EXTRAS
void hardcodeoPartidos(ePartido*);
