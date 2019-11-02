#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


Employee* employee_new()
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}



Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = employee_new();

    int auxId;
    int auxHoras;
    int auxSueldo;

    auxId= atoi(idStr);
    auxHoras= atoi(horasTrabajadasStr);
    auxSueldo= atoi(sueldoStr);

    if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setNombre(nuevoEmpleado, nombreStr);
        employee_setId(nuevoEmpleado, auxId);
        employee_setHorasTrabajadas(nuevoEmpleado, auxHoras);
        employee_setSueldo(nuevoEmpleado, auxSueldo);
    }

    return nuevoEmpleado;
}



void employee_delete(Employee* nuevoEmpleado)
{
    if(nuevoEmpleado!=NULL)
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



int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int ret = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n COMO DESEA ORDENAR:");
        printf("\n 1-Ordernar empleados por nombre.");
        printf("\n 2-Ordenar empleados por sueldo.");
        printf("\n 3-Ordenar empleados por horas trabajadas.");
        printf("\n 4-Cancelar.");
        printf("\n\n Su Opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nSe esta ordenando...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
            break;

        case 2:
            printf("\nSe esta ordenando...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
            break;

        case 3:
            printf("\nSe esta ordenando...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
            break;

        case 4:
            opcion=4;
            printf("\nCancelando...\n\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

        ret=1;
    }
    return ret;
}



int employee_ordenarPorSueldo(void* uno, void* dos)
{
    int sueldoUno;
    int sueldoDos;
    int ret = 0;

    employee_getSueldo(uno, &sueldoUno);
    employee_getSueldo(dos, &sueldoDos);

    if(sueldoUno > sueldoDos)
    {
        ret = 1;
    }
    else if(sueldoUno < sueldoDos)
    {
        ret = -1;
    }

    return ret;
}



int employee_ordenarPorNombre(void* uno, void* dos)
{
    char nombreUno[50];
    char nombreDos[50];
    int ret = 0;

    employee_getNombre(uno, nombreUno);
    employee_getNombre(dos, nombreDos);

    if(strcmp(nombreUno, nombreDos) > 0)
    {
        ret = 1;
    }
    else if(strcmp(nombreUno, nombreDos) < 0)
    {
        ret = -1;
    }

    return ret;



int employee_ordenarPorHoras(void* uno, void* dos)
{
    int horasUno;
    int horasDos;
    int ret = 0;

    employee_getHorasTrabajadas(uno, &horasUno);
    employee_getHorasTrabajadas(dos, &horasDos);

    if(horasUno > horasDos)
    {
        ret = 1;
    }
    else if(horasUno < horasDos)
    {
        ret = -1;
    }

    return ret;
}


