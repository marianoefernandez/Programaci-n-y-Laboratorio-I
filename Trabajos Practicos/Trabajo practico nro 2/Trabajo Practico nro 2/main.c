#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000
#define NOTFREE 1
#define FREE 0


/*Una empresa requiere un sistema para administrar su n�mina de empleados.
Se sabe que dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.

1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero de Id.
El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema. //FUNCIONA
4. INFORMAR:
1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector. //FUNCIONA
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
*/
int main()
{
    //2.init=0
    //3.menumostrar
    //
    Employee list[TAM];

    if(inicializarEmpleados(empleados,TAM)==0)
    {
        opcionesMenuPrincipal(empleados,0);//SWITCH DEL MENU
    }
    else
    {
        printf("\nHubo un error al crear la lista, No hay espacio en memoria");
    }

    return 0;
}
