#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"

int* n=0;//ID AUTOINCRMENTAL GLOBAL PARA QUE NUNCA SE PISE EN NINGUNA FUNCION, POR ESO ES PUNTERO

//MENUES (2 de 4)
void menuPrincipal()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a un empleado: ");
    printf("\n2-Modificar empleado: ");
    printf("\n3-Dar de baja a un empleado: ");
    printf("\n4-Informar: ");
}

void menuSecundario()
{
    printf("\n1-Ordenar empleados por apellido y sector: ");
    printf("\n2-Calcular total de salarios, el salario promedio y cuantos empleados superan el salario promedio: ");
}

//SWITCH DEL PRIMER MENU (FALTA)

//SWITCH DEL SEGUNDO MENU (FALTA)


//FUNCIONES PARA INICIALIZAR (1 de 2)
int inicializarEmpleados(eEmpleado* empleados, int cantidad)
{
    int i;
    int retorno=-1;
    //GENERAR ID


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


int autoincrementar (int* n) //NO SE SI SIRVE
{
    *n=*n+1;
    return &n;
}

//int generarID (HACER)


//FUNCIONES PARA AÑADIR (2 de 4)

eEmpleado pedirEmpleado() //FALTA PROBAR BIEN
{
    eEmpleado empleados;

    //LLAMAMOS A GENERAR ID EN ID
    empleados.id = autoincrementar(*n);//NO SE SI SIRVE
    strcpy(empleados.nombre,getString("Ingrese el nombre: ", 51))
    strcpy(empleados.apellido,getString("Ingrese el apellido: ", 51))
    empleados.salario = getFloat("Ingrese el salario: ");
    empleados.sector = getInt("Ingrese el nro de sector: ")

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
