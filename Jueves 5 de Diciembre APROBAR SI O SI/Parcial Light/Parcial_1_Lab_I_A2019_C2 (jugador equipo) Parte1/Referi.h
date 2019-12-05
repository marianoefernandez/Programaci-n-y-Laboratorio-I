#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10
#include "Fecha.h"

//ESTRUCTURAS

typedef struct
{
    int codigo;
    char nombre[32];
    char apellido[32];
    char eMail[32];
    char sexo;
    eFecha fechaNac;
    int isEmpty;
}eReferi;

//0-MENU

void mostrarMenuR();

void printModificationMenuR();

//1-INICIALIZAR
int inicializarReferis(eReferi*,int);

int getFreeR(eReferi*,int); //TERMINADA

int buscarReferiPorCodigo(eReferi*,int,int);

//2-ALTAS/BAJAS/MODIFICACION

int agregarReferis(eReferi*,int,int);

int modificarReferis(eReferi*,int);

int bajaReferis(eReferi*,int,int);

//3-ORDENAR

int ordenarReferisNombreyApellido(eReferi*, int, int);

//4-MOSTRAR

int printReferi(eReferi*,int);

//5-EXTRAS
void hardcodeoReferis(eReferi*);

int cantidadReferisOcupados(eReferi*,int);


