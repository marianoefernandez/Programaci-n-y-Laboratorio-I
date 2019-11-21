#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "llamados.h"

//ESTRUCTURA EMPLEADO

llamado* new_llamado()
//CONSTRUYE UN NUEVO EMPLEADO MEDIANTE UN MALLOC, LUEGO SI ESE PUNTERO A EMPLEADO EXISTE EN MEMORIA LO SETEA EN 0 TODO
{
    llamado* nuevoLLamado;///Siempre Puntero
    eFecha* fecha;
    nuevoLLamado=(llamado*)malloc(sizeof(llamado));///Siempre va un (Employee*) antes del malloc


    if (nuevoLLamado != NULL)
    {
        nuevoLLamado->id=0;
        nuevoLLamado->fecha->dia=0;
        nuevoLLamado->fecha->mes=0;
        nuevoLLamado->fecha->anio=0;
        nuevoLLamado->numCliente=0;
        nuevoLLamado->idProblema=0;
        strcpy(nuevoLLamado->solucion, " ");
        //(NO) nuevoEmpleado=malloc(sizeof(Employee));
    }

    return nuevoLLamado;
}

llamado* new_llamadoParametros(char* id,char*dia,char*mes,char*anio,char*numCliente,char*idProblema,char*solucion)
//A UN PUNTERO NUEVO EMPLEADO LO CONSTRUYE Y SE LE SETEAN VALORES QUE UNO QUIERA, LES HACE UN ATOI A LOS ENTEROS Y HACE EL SET A CADA DATO
{
    Employee* nuevoEmpleado;
    new_Employee(nuevoEmpleado);

    int idAux;
    int sueldoAux;
    int horasTrabajadasAux;

    idAux=atoi(id);
    sueldoAux=atoi(sueldo);
    horasTrabajadasAux=atoi(horasTrabajadas);

    if(nuevoEmpleado!=NULL && id!=NULL && nombre!=NULL && sueldo!=NULL && horasTrabajadas!=NULL)
    {
        ///SETEAMOS CADA DATO CON LOS SETERS
        employee_setId(nuevoEmpleado,idAux);
        employee_setNombre(nuevoEmpleado,nombre);
        employee_setSueldo(nuevoEmpleado,sueldoAux);
        employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadasAux);
    }

    return nuevoEmpleado;
}

llamada* delate_llamada(llamada* nuevaLlamada)
//SI HAY MEMORIA Y EXISTE EL EMPLEADO LO LIBERA
{
    if (nuevaLlamada!=NULL)
    {
        free(nuevaLlamada);
    }
}

int llamada_setId(llamada* nuevaLlamada,int id)
//SETEA EL ID, SI ES DISTINTO DE NULL Y EL ID ES MAYOR A -1 SIGNIFICA QUE EXISTE,POR ENDE LO SETEA CON FLECHITA IGUAL A ID
{
    int ret = 0;

    if(nuevaLlamada != NULL)
    {
        if(id >= 0)
        {
            nuevaLlamada->id = id;
            ret = 1;
        }
    }
    return ret;
}

//SI EL ID Y EL EMPLEADO SON DISTINTOS DE NULL,EL PUNTERO A ID ES IGUAL A EMPLEADO FLECHITA ID ESO ES UN GET

int llamada_getId(llamada* nuevaLlamada,int* id)
{
    int ret = 0;

    if(nuevaLlamada!=NULL && id !=NULL)
    {
        *id = nuevaLlamada->id;
        ret = 1;
    }
    return ret;
}

///SET  lista->dato = dato
///GET  *dato = lista->dato


int llamada_setFecha(llamada* nuevaLlamada,int dia,int mes,int anio)
//SETEA EL ID, SI ES DISTINTO DE NULL Y EL ID ES MAYOR A -1 SIGNIFICA QUE EXISTE,POR ENDE LO SETEA CON FLECHITA IGUAL A ID
{
    int ret = 0;

    if(nuevaLlamada != NULL)
    {
        if(dia >= 1 && dia<=31)
        {
            nuevaLlamada->dia = dia;
            ret = 1;
        }

        if(mes >= 1 && mes<=12)
        {
            nuevaLlamada->mes = mes;
            ret = 1;
        }

        if(anio >= 1900 && anio<=2050)
        {
            nuevaLlamada->anio = anio;
            ret = 1;
        }
    }
    return ret;
}

int llamada_getFecha(llamada* nuevaLlamada,int* dia,int* mes,int* anio)
{
    int ret = 0;

    if(nuevaLlamada!=NULL && dia !=NULL && mes !=NULL && anio !=NULL)
    {
        *dia = nuevaLlamada->dia;
        *mes = nuevaLlamada->mes;
        *anio = nuevaLlamada->anio;
        ret = 1;
    }
    return ret;
}

int llamada_setNumeroCliente(llamada* nuevaLlamada,int numeroCliente)
//SETEA EL ID, SI ES DISTINTO DE NULL Y EL ID ES MAYOR A -1 SIGNIFICA QUE EXISTE,POR ENDE LO SETEA CON FLECHITA IGUAL A ID
{
    int ret = 0;

    if(nuevaLlamada != NULL)
    {
        if(numeroCliente >= 0)
        {
            nuevaLlamada->numCliente = numeroCliente;
            ret = 1;
        }
    }
    return ret;
}

//SI EL ID Y EL EMPLEADO SON DISTINTOS DE NULL,EL PUNTERO A ID ES IGUAL A EMPLEADO FLECHITA ID ESO ES UN GET

int llamada_getNumeroCliente(llamada* nuevaLlamada,int* numeroCliente)
{
    int ret = 0;

    if(nuevaLlamada!=NULL && numeroCliente !=NULL)
    {
        *numeroCliente = nuevaLlamada->numCliente;
        ret = 1;
    }
    return ret;
}

int llamada_setIdProblema(llamada* nuevaLlamada,int idProblema)
//SETEA EL ID, SI ES DISTINTO DE NULL Y EL ID ES MAYOR A -1 SIGNIFICA QUE EXISTE,POR ENDE LO SETEA CON FLECHITA IGUAL A ID
{
    int ret = 0;

    if(nuevaLlamada != NULL)
    {
        if(idProblema >= 0)
        {
            nuevaLlamada->idProblema = idProblema;
            ret = 1;
        }
    }
    return ret;
}

//SI EL ID Y EL EMPLEADO SON DISTINTOS DE NULL,EL PUNTERO A ID ES IGUAL A EMPLEADO FLECHITA ID ESO ES UN GET

int llamada_getIdProblema(llamada* nuevaLlamada,int* idProblema)
{
    int ret = 0;

    if(nuevaLlamada!=NULL && id !=NULL)
    {
        *idProblema = nuevaLlamada->idProblema;
        ret = 1;
    }
    return ret;
}

int llamada_setSolucion(llamados* nuevoEmpleado,char* solucion)
{
    int ret=0;

    if(nuevoEmpleado!=NULL && solucion!=NULL)
    {
        strcpy(nuevoEmpleado->solucion,solucion);
        ret=1;
    }
    return ret;
}



int llamada_getSolucion(llamados* nuevoEmpleado,char* solucion)
{
    int ret=0;

    if(nuevoEmpleado!=NULL && solucion!=NULL)
    {
        strcpy(solucion,nuevoEmpleado->solucion);
        ret=1;
    }
    return ret;
}
