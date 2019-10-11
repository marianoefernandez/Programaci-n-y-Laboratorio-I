#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10

//ESTRUCTURAS
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigo;
    char nombre[32];
    char apellido[32];
    int codigoE;
    char eMail[32];
    char sexo;
    eFecha fechaNac;
    int isEmpty;
}eReferi;

//0-MENU
void mostrarMenuR();

//1-INICIALIZAR
int inicializarReferis(eReferi*,int);

int getFreeR(eReferi*,int); //TERMINADA

//2-ALTAS

int agregarReferis(eReferi*,int,int);

//3-MOSTRAR

int printReferi(eReferi*, int);
