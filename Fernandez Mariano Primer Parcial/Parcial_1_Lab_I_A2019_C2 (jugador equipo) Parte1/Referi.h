#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10


//ESTRUCTURA

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigo;
    char apellido[32];
    char nombre[32];
    char sexo;
    char email[32];
    char localidad[34];
    eFecha fechaNac;
    int isEmpty;
}eReferi;
