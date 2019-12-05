#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10
#include "Fecha.h"


typedef struct
{
    int codigo;
    char nombre[32];
    char apellido[32];
    int codigoE;
    char sexo;
    eFecha fechaNac;
    int isEmpty;
}eJugadores;


//0-MENU
void mostrarMenuJ();

void printModificationMenuJ();

//1-INICIALIZAR
int inicializarJugadores(eJugadores*,int);

//int buscarEquipoPorCodigo(eEquipo*, int, int);

int getFreeJ(eJugadores*,int); //TERMINADA

int buscarJugadorPorCodigo(eJugadores*,int,int);


//2-ALTAS/BAJAS/MODIFICACION

int agregarJugadores(eJugadores*,int,int);


//3-ORDENAR

int ordenarJugadoresNombreYApellido(eJugadores*, int, int);

int ordenarJugadoresPorSexo(eJugadores* jugadores, int);

//4-MOSTRAR

//int printJugadores(eEquipo*,eJugadores*, int);

//5-EXTRAS

void hardcodeoJugadores(eJugadores*);

