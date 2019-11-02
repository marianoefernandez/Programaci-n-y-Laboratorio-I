#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int opcion;
    int flagTexto= 0;
    int flagBinario= 0;

    do
    {
        printf("MENU:\n");
        printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("3- Alta de empleado.\n");
        printf("4- Modificar datos de empleado.\n");
        printf("5- Baja de empleado.\n");
        printf("6- Listar empleados.\n");
        printf("7- Ordenar empleados.\n");
        printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9- Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("10- Salir.\n");

        printf("\nSu opcion: ");
        scanf("%d", &opcion);

        while (opcion>10)
        {
            printf("Opcion invalida\n");
            printf("\nSu opcion: ");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:
            if(flagTexto == 0)
            {
                if(controller_loadFromText("data.csv",listaEmpleados) == 1)
                {
                    printf("\nSe cargo el archivo.\n\n");
                }
                else
                {
                    printf("\nNo se cargo el archivo.\n\n");
                }
            flagTexto=1;
            }
            else if(flagTexto == 1)
            {
                printf("El archivo ya se cargo.\n");
            }
            break;

        case 2:
            if(flagBinario == 0)
            {
                if(controller_loadFromBinary("data.bin",listaEmpleados) == 1)
                {
                    printf("\nSe cargo el archivo.\n\n");
                }
                else
                {
                    printf("\nNo se cargo el archivo.\n\n");
                }
            flagBinario=1;
            }
            else if(flagBinario == 1)
            {
                printf("El archivo ya se cargo.\n");
            }
            break;

        case 3:
            if(controller_addEmployee(listaEmpleados) == 1)
            {
                printf("\nSe cargo el empleado.\n\n");
            }
            else
            {
                printf("\nNo se cargo el empleado.\n\n");
            }
            break;

        case 4:
            if(controller_editEmployee(listaEmpleados) == 1)
            {
                printf("\nSe modifico el empleado.\n\n");
            }
            else
            {
                printf("\nNo se modifico el empleado.\n\n");
            }
            break;

        case 5:
            if(controller_removeEmployee(listaEmpleados) == -1)
            {
                printf("\nNo se encontro el ID.\n\n");
            }
            else if(validarRemove == -2)
            {
                printf("\nNo se elimino el empleado.\n\n");
            }
            else
            {
                printf("\nSe elimino el empleado.\n\n");
            }
            break;

        case 6:
            if(controller_ListEmployee(listaEmpleados) == 1)
            {
                printf("\nSe cargo la lista.\n\n");
            }
            else
            {
                printf("\nNo se cargo la lista.\n\n");
            }
            break;

        case 7:
            if(controller_sortEmployee(listaEmpleados) == 1)
            {
                printf("\nSe ordeno.\n\n");
            }
            else
            {
                printf("\nNo se pudo ordenar.\n\n");
            }
            break;

        case 8:
            if(controller_saveAsText("data.csv",listaEmpleados) == 1)
            {
                printf("\nSe ha guardo el archivo.\n\n");
            }
            else
            {
                printf("\nNo se guardo el archivo.\n\n");
            }
            break;

        case 9:
            if(controller_saveAsBinary("data.bin",listaEmpleados) == 1)
            {
                printf("\nSe ha guardo el archivo.\n\n");
            }
            else
            {
                printf("\nNo se guardo el archivo.\n\n");
            }
            break;

        case 10:
            opcion=10;
            printf("\nSaliendo...\n\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion != 10);

    return 0;
}
