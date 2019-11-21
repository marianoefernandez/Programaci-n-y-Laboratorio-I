#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Employee.h"

//ESTRUCTURA EMPLEADO

Employee* new_Employee()
//CONSTRUYE UN NUEVO EMPLEADO MEDIANTE UN MALLOC, LUEGO SI ESE PUNTERO A EMPLEADO EXISTE EN MEMORIA LO SETEA EN 0 TODO
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

Employee* delate_employee(Employee* nuevoEmpleado)
//SI HAY MEMORIA Y EXISTE EL EMPLEADO LO LIBERA
{
    if (nuevoEmpleado!=NULL)
    {
        free(nuevoEmpleado);
    }
}

int employee_setId(Employee* nuevoEmpleado,int id)
//SETEA EL ID, SI ES DISTINTO DE NULL Y EL ID ES MAYOR A -1 SIGNIFICA QUE EXISTE,POR ENDE LO SETEA CON FLECHITA IGUAL A ID
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

//SI EL ID Y EL EMPLEADO SON DISTINTOS DE NULL,EL PUNTERO A ID ES IGUAL A EMPLEADO FLECHITA ID ESO ES UN GET

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

///SET  lista->dato = dato
///GET  *dato = lista->dato


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


int employee_getSueldo(Employee* nuevoEmpleado, int* sueldo)
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

int sortEmployee(LinkedList* listaEmpleados)
{
    int opcion;
    int retorno = 0;

    if(listaEmpleados != NULL)
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
            ll_sort(listaEmpleados, employee_ordenarPorNombre, 1);
            break;

        case 2:
            printf("\nSe esta ordenando...\n\n");
            ll_sort(listaEmpleados, employee_ordenarPorSueldo, 1);
            break;

        case 3:
            printf("\nSe esta ordenando...\n\n");
            ll_sort(listaEmpleados, employee_ordenarPorHoras, 1);
            break;

        case 4:
            opcion=4;
            printf("\nCancelando...\n\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

        retorno=1;
    }
    return retorno;

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

}

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
