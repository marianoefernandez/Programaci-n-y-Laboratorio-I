#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio
}eFecha;

typedef struct
{
    int id;
    eFecha fecha;
    int numCliente;
    int idProblema;
    char* solucion;
}llamada;

llamada* new_llamado();
llamada* new_llamadoParametros(char*,char*,char*,char*,char*,char*,char*);
llamada* delate_llamada(llamada*);
int llamada_setId(llamada*,int);
int llamada_getId(llamada*,int*);
int llamada_setFecha(llamada*,int,int,int);
int llamada_getFecha(llamada*,int*,int*,int*);
int llamada_setNumeroCliente(llamada*,int);
int llamada_getNumeroCliente(llamada*,int*);
int llamada_setIdProblema(llamada*,int);
int llamada_getIdProblema(llamada*,int*);
int llamada_setSolucion(llamada*,char*);
int llamada_getSolucion(llamada*,char*);











#endif // employee_H_INCLUDED



