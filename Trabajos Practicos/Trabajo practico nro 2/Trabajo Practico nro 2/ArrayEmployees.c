#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"

//MENUES (1 de 4)
void menuPrincipal()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a un empleado: ");
    printf("\n2-Modificar empleado: ");
    printf("\n3-Dar de baja a un empleado: ");
    printf("\n4-Informar: ");
}

//SEGUNDO MENU (FALTA)

//SWITCH DEL PRIMER MENU (FALTA)

//SWITCH DEL SEGUNDO MENU (FALTA)


//FUNCIONES PARA INICIALIZAR (1 de 2)
int inicializarEmpleados(eEmpleado* empleados, int cantidad)
{
    int i;
    int retorno=-1;

    if(empleados!=NULL && cantidad>0)
    {
        for (i=0; i<cantidad; i++)
        {
            empleados[i].estado = LIBRE;
        }
        retorno=0;
    }

    return retorno;
}

//int generarID (HACER)


//FUNCIONES PARA AÑADIR (2 de 4)

eEmpleado pedirEmpleado() //FALTA TERMINAR
{
    eEmpleado empleados;
    //HAY QUE USAR INPUTS
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(empleado.nombre);
    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(empleado.apellido);
    printf("\nIngrese salario: ");
    scanf("%f",&empleado.salario);
    printf("\nIngrese num de sector: ");
    scanf("%d",&empleado.sector);

    empleado.estado = LIBRE;

    return empleado;
}

//int validarEmpleado (HACER)

int buscarLibre(eEmpleado* empleado,int cantidad) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<cantidad;i++)
    {
        if (empleado[i].estado == LIBRE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

int agregarEmpleados (eEmpleado* empleados,int cantidad) //TERMINADA
{
    int i;
    int retorno=-1;
    i = buscarLibre(empleados,cantidad);
    if (i != -1)
    {
        empleados[i] = pedirEmpleado();
        empleados[i].estado==OCUPADO;
        retorno = 0;
    }
}

//3-BUSCAR EMPLEADO POR ID

//4-BAJA LÓGICA

//5-FUNCIONES DE ORDENAMIENTO

//6-FUNCIONES PARA MOSTRAR

//7-FUNCIONES DE HARDCODEO (1 de 1) LISTO

void hardcodeoEmpleados(Employee* empleado, int cantidad) //TERMINADA
{
    int id[5] = {1,2,3,4,5};
    char nombre[5][51] = {"Jorge","Mauro","Diego","Daniela","Juliana"};
    char apellido[5][51] = {"Rios","Zarate","Perez","Gonzalez","Lopez"};
    float salario[5] = {2850,4425,3250,5785,6900};
    int sector[5] = {8,33,11,11,8};

    int i;
    for (i=0; i<5; i++)
    {
        empleado[i].id = id[i];
        strcpy(empleado[i].nombre, nombre[i]);
        strcpy(empleado[i].apellido, apellido[i]);
        empleado[i].salary = salario[i];
        empleado[i].sector = sector[i];
        empleado[i].estado = OCUPADO;
    }
}
