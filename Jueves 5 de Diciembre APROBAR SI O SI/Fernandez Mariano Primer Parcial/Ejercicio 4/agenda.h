#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define TAM 200


typedef struct
{
    char nombre[30];
    char apellido[30];
    int legajo;
    int isEmpty;
}eAgenda;

void printFirstMenu();
void printModificationMenu();
int initAgenda(eAgenda*,int);
int agregarAgenda(eAgenda*,int);
int buscarAgendaPorLegajo(eAgenda*,int,int);
int modificarAgenda(eAgenda*,int);
int eliminarAgenda(eAgenda*,int,int);
int ordenarAgendaPorApellido(eAgenda*,int,int);
void printAgenda(eAgenda);
int printAgendas(eAgenda*,int);
int agendaNotFree(eAgenda*,int);
int validarLegajo(eAgenda*,int,int);






