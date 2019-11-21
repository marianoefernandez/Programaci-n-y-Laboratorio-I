#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/*********************** *****************************
    1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del
    mismo.
    2) Imprimir Llamadas: Se imprimirá por pantalla la tabla con los datos de las llamadas indicando el
    problema en forma de texto (no de número)
    3) Generar archivo de llamadas: Se pedirá que se ingrese el número de problema (1 a 5), y se
    generará un archivo CSV con el mismo formato que el original, pero solo con las llamadas de dicho
    tipo de problema.
    4) Salir.
*****************************************************/

int main()
{
    LinkedList* listaLlamados = ll_newLinkedList();

    int opcion;
    int flagTexto= 0;
    int flagBinario= 0;
    int retorno;
    char* archivo;

    do
    {
        printf("MENU:\n");
        printf("1- Cargar archivo\n");
        printf("2- Imprimir Llamadas\n");
        printf("3- Generar archivo de llamadas\n");
        printf("4- Salir\n");
        printf("\nSu opcion: ");
        scanf("%d", &opcion);

        while (opcion>4)
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
                printf("Ingrese el nombre del archivo a abrir(agregue el .csv al final): ");
                fflush(stdin);
                gets(archivo);

                if(controller_loadFromText(archivo,listaLlamados) == 1)
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
            if(controller_ListEmployee(listaLlamados)==1)
            {
                printf("\nSe cargo la lista.\n\n");
            }
            else
            {
                printf("\nNo se cargo la lista.\n\n");
            }
            break;


        case 3:
            if(controller_saveAsText("DATOS.csv",listaLlamados)==1)
            {
                printf("\nSe guardo el archivo.\n\n");
            }
            else
            {
                printf("\nNo se guardo el archivo.\n\n");
            }
            break;


        case 4:
            opcion=4;
            printf("\nSaliendo...\n\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion != 4);

    return 0;
}
