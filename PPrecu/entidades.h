#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int idPersona;
    char nombre[31];
    int telefono;

}ePersona;

typedef struct
{
    int idPersona;
    int idDestino;
    char tipo[31];
    char estado[31];

}eLlamada;


int inicializarAutor(ePersona arrayAutores[], int len);
int buscarLibreAutor(ePersona arrayAutor[],int len);
void autor_hardcore(ePersona y[]);
char menuAutores();
void getInformationAutor(char auxName[],int* auxTelefono);
void printAutores(ePersona lista[], int cant);
void printAutor(ePersona unAutor);
int buscarPosAutor(ePersona arrayAutores[],int len,int codAutor);

int altaAutor(ePersona arrayAutores[],int len);
int bajaAutor(ePersona arrayAutores[],int len);
int modificarAutor(ePersona arrayAutores[],int len);




int inicializarLlamada(eLlamada arrayAutores[], int len);
int buscarLibreLlamada(eLlamada arrayAutor[],int len);
//void getInformationLlamada(int*auxIdDestino, char auxtipo[],char estado[],eLlamada[]);
void getInformationLlamada(int*auxLlamador,int*auxIdDestino, char auxtipo[],char auxEstado[]);
//int altaLlamada(eLlamada arrayAutores[],int len);
int altaLlamada(eLlamada arrayAutores[],int len,ePersona arrayPersona[]);
