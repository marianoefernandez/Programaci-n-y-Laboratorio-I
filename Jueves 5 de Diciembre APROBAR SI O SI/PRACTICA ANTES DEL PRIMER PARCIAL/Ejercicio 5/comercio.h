#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define TAM 1000


typedef struct
{
    int codigo;
    char descripcion [51];
    int importe;
    int cantidad;
    int isEmpty;
}eProducto;

void printFirstMenu();
void printModificationMenu();
void printOrdenarMenu();
void printInformarMenu();
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






