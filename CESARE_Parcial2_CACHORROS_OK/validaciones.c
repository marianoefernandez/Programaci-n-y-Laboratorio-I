#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Dominio.h"
#include "validaciones.h"




int esNumeroEntero (char* vStr)
{
    int i=0;
    int todoOk=1;
    while(vStr[i]!='\0')
    {
        if(vStr[i]<'0' || vStr[i]>'9')
        {
            todoOk= 0;
        }
        i++;
    }
    return todoOk;
}

int getNumber(char* pStr, char* msg, char* msgE)
{
    int todoOk=0;

    printf("\n%s",msg);
    fflush(stdin);
    gets(pStr);

    while(!esNumeroEntero(pStr) || atoi(pStr) <= 0)
    {
        printf("\n%s",msgE);
        fflush(stdin);
        gets(pStr);
    }
    todoOk=1;

    return todoOk;
}

int getString(char* pStr, char* msg, char* msgE)
{
    int todoOk=0;

    printf("\n%s",msg);
    fflush(stdin);
    gets(pStr);

    while(strlen(pStr)>127 || strlen(pStr) <=0)
    {
        printf("\n%s",msgE);
        fflush(stdin);
        gets(pStr);
    }
    todoOk=1;

    return todoOk;
}

int menu()
{
    int option;

    system("cls");
    printf("****PRACTICA PARCIAL****\n\n");
    printf("1. Cargar los datos .\n");
    printf("2. Listar CACHORROS\n");
    printf("3. mapear y filtrar\n");
    printf("4. Listar cachorros filtrados por 45 dias\n");
    printf("5. Listar cachorros filtrados por machos\n");
    printf("6. Listar cachorros filtrado por callejeros\n");
    printf("7. Listar cachorros filtrado por reservado\n");
    printf("8. Salir.\n");
    printf("\nIngrese una opcion del menu: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

/*Employee* menuModificar(LinkedList* pArrayListEmployee, int option)
{
    char encontro ='n';
    char id[20];
    Employee* auxEmployee;

    if(option == 1 || option == 2 || option == 3){
        getNumber(id,"Ingrese Id: ", "ERROR. Numero invalido, reingrese Id: ");
        auxEmployee = (Employee*)employee_FindById(pArrayListEmployee, atoi(id));

        while(encontro!='s')
        {
            if(auxEmployee==NULL)
            {
                printf("\nNo se encontro el empleado.");
                getNumber(id,"Ingrese Id: ", "ERROR. Numero invalido, reingrese Id: ");
                auxEmployee =(Employee*) employee_FindById(pArrayListEmployee, atoi(id));
            }
            else
            {
                printf("\nEl empleado a modificar es correcto?(s-n): ");
                fflush(stdin);
                scanf("%c",&encontro);
                if(encontro!='s')
                auxEmployee=NULL;
            }

        }
    }

    return auxEmployee;
}
*/
