#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Employee.h"

//ESTRUCTURA EMPLEADO

Employee* new_Employee()
{
    Employee* nuevoEmpleado;///Siempre Puntero
    nuevoEmpleado=(Employee*)malloc(sizeof(Employee));///Siempre va un (Employee*) antes del malloc


    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->sueldo=0;
        nuevoEmpleado->horasTrabajadas=0;
        //(NO) nuevoEmpleado=malloc(sizeof(Employee));
    }

    return nuevoEmpleado;
}

Employee* new_Employee_Parametros(char* id,char*nombre,char*sueldo,char*horasTrabajadas)
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

    }

    return nuevoEmpleado;
}

Employee* delate_employee(Employee* nuevoEmpleado);
{
    if (nuevoEmpleado!=NULL)
    {
        free(nuevoEmpleado);
    }
}

int employee_setId(Employee* nuevoEmpleado,int id)
{
    int ret = 0;

    if(nuevoEmpleado != NULL)
    {
        if(id >= 0)
        {
            nuevoEmpleado->id = id;
            ret = 1;
        }
    }
    return ret;
}



int employee_getId(Employee* nuevoEmpleado,int* id)
{
    int ret = 0;

    if(nuevoEmpleado!=NULL && id !=NULL)
    {
        *id = nuevoEmpleado->id;
        ret = 1;
    }
    return ret;
}



int employee_setNombre(Employee* nuevoEmpleado,char* nombre)
{
    int ret=0;

    if(nuevoEmpleado!=NULL && nombre!=NULL)
    {
        strcpy(nuevoEmpleado->nombre,nombre);
        ret=1;
    }
    return ret;
}



int employee_getNombre(Employee* nuevoEmpleado,char* nombre)
{
    int ret=0;

    if(nuevoEmpleado!=NULL && nombre!=NULL)
    {
        strcpy(nombre,nuevoEmpleado->nombre);
        ret=1;
    }
    return ret;
}



int employee_setHorasTrabajadas(Employee* nuevoEmpleado,int horasTrabajadas)
{
    int ret = 0;

    if(nuevoEmpleado != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            nuevoEmpleado->horasTrabajadas = horasTrabajadas;
            ret = 1;
        }
    }
    return ret;
}



int employee_getHorasTrabajadas(Employee* nuevoEmpleado,int* horasTrabajadas)
{
    int ret = 0;

    if(nuevoEmpleado != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = nuevoEmpleado->horasTrabajadas;
        ret = 1;
    }
    return ret;
}



int employee_setSueldo(Employee* nuevoEmpleado,int sueldo)
{
    int ret=0;

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->sueldo = sueldo;
        ret=1;
    }
    return ret;
}


int employee_getSueldo(Employee* nuevoEmpleado,int* sueldo)
{
    int ret = 0;

    if(nuevoEmpleado != NULL && sueldo != NULL)
    {
        *sueldo = nuevoEmpleado->sueldo;
        ret = 1;
    }
    return ret;
}

///FALTAN FUNCIONES DE ORDENAMIENTO SABER REALIZARLAS Y ENTENDERLAS
