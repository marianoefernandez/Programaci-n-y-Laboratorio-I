#include <stdio.h>
#include <stdlib.h>
#include TAM 1000
#include LIBRE 0
#include OCUPADO 1


/*Una empresa requiere un sistema para administrar su nómina de empleados.
Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id.
El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*/

typedef struct
{
    int id;
    char nombre [51];
    char apellido [51];
    float salario;
    int sector;
    int estado;
}eEmpleado;

void menu ();
/** \brief Muestra menu de opciones
 *
 *
 */

int inicializarEmpleados(eEmpleado* empleados, int cantidad);
/** \brief Verifica si todas las posiciones del array estan vacias, pone una flag si esta en true para verificarlo.
 *
 * \param 1 Recibe un puntero de la estructura eEmpleados
 * \param 2 Recibe la cantidad de elementos del array
 * \return Retorna (-1) si hay error y 0 si todo está bien
 *
 */


int main()
{
    int opcion;
    menu();
    eEmpleado empleados[1000];
    return 0;
}

void menu ()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a un empleado: ");
    printf("\n2-Modificar empleado: ");
    printf("\n3-Dar de baja a un empleado: ");
    printf("\n4-Informar: ");
}

int inicializarEmpleados(eEmpleado* empleados, int cantidad)
{
    int i;
    int retorno=-1;

    if(lista!=NULL && cantidad>0)
    {
        for (i=0; i<cantidad; i++)
        {
            empleados[i].estado = LIBRE;
        }
        retorno=0;
    }

    return retorno;
}
