#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


Employee* employee_new()//CONSTRUCTOR
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        //INICIALIZAMOS EN CERO
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



void employee_delete(Employee* this)//LIBERAMOS EL EMPLEADO
{
    if(this!=NULL)
    {
        free(this);
    }
}



int employee_setId(Employee* this,int id)
{
    int ret = 0;

    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            ret = 1;
        }
    }
    return ret;
}



int employee_getId(Employee* this,int* id)
{
    int ret = 0;

    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        ret = 1;
    }
    return ret;
}



int employee_setNombre(Employee* this,char* nombre)
{
    int ret=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        ret=1;
    }
    return ret;
}



int employee_getNombre(Employee* this,char* nombre)
{
    int ret=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        ret=1;
    }
    return ret;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = 0;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            ret = 1;
        }
    }
    return ret;
}



int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret = 1;
    }
    return ret;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int ret=0;

    if(this!=NULL)
    {
        this->sueldo = sueldo;
        ret=1;
    }
    return ret;
}



int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
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
        printf("\n\n ¿COMO DESEA ORDENAR?");
        printf("\n 1-Ordernar por nombre.");
        printf("\n 2-Ordenar por sueldo.");
        printf("\n 3-Ordenar por horas trabajadas.");
        printf("\n 4-Salir.");
        printf("\n\n Su Opcion: ");
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



int employee_ordenarPorSueldo(void* thisA, void* thisB)
{
    int sueldoA;
    int sueldoB;
    int ret = 0;

    employee_getSueldo(thisA, &sueldoA);
    employee_getSueldo(thisB, &sueldoB);

    if(sueldoA > sueldoB)
    {
        ret = 1;
    }
    else if(sueldoA < sueldoB)
    {
        ret = -1;
    }

    return ret;
}



int employee_ordenarPorNombre(void* thisA, void* thisB)
{
    char nombreA[50];
    char nombreB[50];
    int ret = 0;

    employee_getNombre(thisA, nombreA);
    employee_getNombre(thisB, nombreB);

    if(strcmp(nombreA, nombreB) > 0)
    {
        ret = 1;
    }
    else if(strcmp(nombreA, nombreB) < 0)
    {
        ret = -1;
    }

    return ret;
}



int employee_ordenarPorHoras(void* thisA, void* thisB)
{
    int horasA;
    int horasB;
    int ret = 0;

    employee_getHorasTrabajadas(thisA, &horasA);
    employee_getHorasTrabajadas(thisB, &horasB);

    if(horasA > horasB)
    {
        ret = 1;
    }
    else if(horasA < horasB)
    {
        ret = -1;
    }

    return ret;
}
