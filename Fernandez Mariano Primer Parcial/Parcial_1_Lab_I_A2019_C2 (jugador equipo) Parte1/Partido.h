#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigo;
    int codigoVisitante;
    int codigoLocal;
    int codigoReferi;
    eFecha fechaNac;
    int isEmpty;
}ePartido;
