#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{
    int retornar;
    int i;
    if(list != NULL)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty= 0;
        }//end for
        retornar= 0;
    }//end if
    else
    {
        retornar= -1;
    }//end else
    return retornar;
}//end


/*int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    return -1;
}
*/
int addEmployeesModificado(Employee* paramEmployee,int len)
{
    int i;
    int id;
    int sector;
    int retorno= -1;
    float salary;
    char auxSalary[50];
    char auxSector[50];

    i= getSpace(paramEmployee, len);
    id= NextId(paramEmployee, len);

    if(i>=0)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(paramEmployee[i].name);
        //VALIDACION
        while(isOnlyLetters(paramEmployee[i].name) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(paramEmployee[i].name);
        }//end while
        stringToUpper(paramEmployee[i].name);


        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(paramEmployee[i].lastName);
        //VALIDACION
        while(isOnlyLetters(paramEmployee[i].lastName) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(paramEmployee[i].lastName);
        }//end while
        stringToUpper(paramEmployee[i].lastName);


        printf("Ingrese el salario: ");
        fflush(stdin);
        gets(auxSalary);
        //VALIDACION
        while(isNumeric(auxSalary) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxSalary);
        }//end while
        salary=atoi(auxSalary);
        paramEmployee[i].salary=salary;


        printf("Ingrese el sector: ");
        fflush(stdin);
        gets(auxSector);
        //VALIDACION
        while(isNumeric(auxSector)==0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxSector);
        }//end while
        sector= atoi(auxSector);
        paramEmployee[i].sector= sector;

        paramEmployee[i].isEmpty =1;
        paramEmployee[i].id =id;

        retorno =0;

        printf("\nLa carga fue un exito.\n");
    }//end if
    else
    {
        printf("\nNo hay espacio disponible.\n");
    }//end else
    return retorno;
}//end


int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1 && list[i].id==id)
        {
            return i;
        }//end if
    }//end for
    return -1;
}//end


int removeEmployee(Employee* paramEmployee, int len)
{
    int i;
    int idUser;
    int opcion;
    printEmployees(paramEmployee, len);

    printf("\nIngrese el id del empleado que quiera dar de baja.\n");
    scanf("%d",&idUser);

    for(i=0; i<len; i++)
    {
        if(idUser==paramEmployee[i].id)
        {
            printf("Desea dar de baja? Ingrese(0-s/1-n)\n");
            scanf("%d",&opcion);

            if (opcion == 0)
            {
                paramEmployee[i].isEmpty = 0;
                paramEmployee[i].id= 0;
                printf("Se ha dado de baja.\n");
                break;
            }//end if
            else if (opcion == 1)
            {
                printf("No se ha dado de baja.\n");
                break;
            }//end else-if
            else
            {
                printf("Error. Ingrese una opcion valida.\n");
                break;
            }//end else
        }//end if
    }//end for
}//end


int sortEmployees(Employee* paramEmployee, int len, int order)
{
    Employee auxEmployee;
    int i;
    int j;

    char auxOpcion[50];
    int opcion;

    printf("\nComo desea ordenar la lista?\n");
    printf("(1) Por apellido.\n");
    printf("(2) Por sector.\n");

    printf("\nElija una opcion: ");
    fflush(stdin);
    gets(auxOpcion);

    while(isNumeric(auxOpcion)==0)
    {
        printf("Ha ingresado una opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxOpcion);
    }
    opcion=atoi(auxOpcion);

    if(opcion==1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(paramEmployee[i].lastName,paramEmployee[j].lastName) > order)
                {
                    auxEmployee=paramEmployee[i];
                    paramEmployee[i]=paramEmployee[j];
                    paramEmployee[j]=auxEmployee;
                }//end if
            }//end for
        }//end for
    }//end if
    else if(opcion==2)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(paramEmployee[i].sector > paramEmployee[j].sector)
                {
                    auxEmployee=paramEmployee[i];
                    paramEmployee[i]=paramEmployee[j];
                    paramEmployee[j]=auxEmployee;
                }//end if
            }//end for
        }//end for
    }//end else-if
    else
    {
        printf("La opcion es invalida");
    }//end else
}//end


void printEmployeeOnly(Employee paramEmployee)
{
    printf("%d -- %10s %15s %20f %10d\n\n", paramEmployee.id, paramEmployee.name, paramEmployee.lastName, paramEmployee.salary, paramEmployee.sector);
}//end


int printEmployees(Employee* paramEmployee, int len)
{
    printf("\n\nID -- \t NAME \t\tLASTNAME \tSALARY \t\tSECTOR\n\n");

    int i;
    for(i=0; i<len; i++)
    {
        if (paramEmployee[i].isEmpty == 1)
        {
            printEmployeeOnly(paramEmployee[i]);
        }//end if
    }//end for
}//end


int getSpace(Employee* paramEmployee, int len)
{
    int index= -1;
    int i;
    for (i=0; i<len; i++)
    {
        if (paramEmployee[i].isEmpty == 0)
        {
            index= i;
            break;
        }//end if
    }//end for
    return index;
}//end


int NextId(Employee* paramEmployee, int len)
{
    int retorno= 0;
    int i;
    if(len > 0 && paramEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(paramEmployee[i].isEmpty == 1)
            {
                if(paramEmployee[i].id > retorno)
                {
                    retorno = paramEmployee[i].id;
                }//end if
            }//end if
        }//end for
    }//end if
    return retorno+1;
}//end


void initEmployeesWithData(Employee* paramEmployee, int len)
{
    int id[5] = {1,2,3,4,5};
    char name[5][51] = {"Alex","Max","Benjamin","Samm","Thomas"};
    char lastName[5][51] = {"Taylor","Block","Weisse","Weder","Zax"};
    float salary[5] = {1000,2000,3000,4000,5000};
    int sector[5] = {5,10,15,20,25};

    int i;
    for (i=0; i<5; i++)
    {
        paramEmployee[i].id = id[i];
        strcpy(paramEmployee[i].name, name[i]);
        strcpy(paramEmployee[i].lastName, lastName[i]);
        paramEmployee[i].salary = salary[i];
        paramEmployee[i].sector = sector[i];
        paramEmployee[i].isEmpty = 1;
    }//end for
}//end


int modificationEmployee(Employee* paramEmployee, int len)
{
    int id;
    int index;
    int rt;
    int retorno= -2;

    char auxId[20];

    if(len >0 && paramEmployee!= NULL)
    {
        retorno=-1;

        printEmployees(paramEmployee, len);

        printf("Ingrese el ID: ");
        fflush(stdin);
        gets(auxId);

        while(isNumeric(auxId)==0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxId);
        }
        id=atoi(auxId);

        index=findEmployeeById(paramEmployee, len, id);

        if(index>=0)
        {
            rt=menuModification(paramEmployee, index);
            retorno=rt;
        }//end if
        else
        {
            retorno = -2;
        }//end else
    }//end if
    return retorno;
}//end


int menuModification(Employee* paramEmployee, int index)
{
    int opcion;
    int sector;
    int retorno=-1;

    char auxOpcion[30];
    char auxName[30];
    char auxLastName[30];
    char auxSalary[30];
    char auxSector[30];

    float salary;

    printf("\n¿Que desea modificar?\n");
    printf("(1) Nombre.\n");
    printf("(2) Apellido.\n");
    printf("(3) Salario.\n");
    printf("(4) Sector.\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    gets(auxOpcion);

    while(isNumeric(auxOpcion)==0)
    {
        printf("Ha ingresado una opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxOpcion);
    }//end while
    opcion=atoi(auxOpcion);

    if(opcion>=1&&opcion<=6)
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre:");
            fflush(stdin);
            gets(auxName);
            while(isOnlyLetters(auxName)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxName);
            }//end while
            stringToUpper(auxName);
            strcpy(paramEmployee[index].name, auxName);
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 2:
            printf("Ingrese el nuevo apellido:");
            fflush(stdin);
            gets(auxLastName);
            while(isOnlyLetters(auxLastName)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxLastName);
            }//end while
            stringToUpper(auxLastName);
            strcpy(paramEmployee[index].lastName, auxLastName);
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 3:
            printf("Ingrese el nuevo salario:");
            fflush(stdin);
            gets(auxSalary);
            while(isNumeric(auxSalary)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxSalary);
            }//end while
            salary = atoi(auxSalary);
            paramEmployee[index].salary = salary;
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 4:
            printf("Ingrese el nuevo sector:");
            fflush(stdin);
            gets(auxSector);
            while(isNumeric(auxSector)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxSector);
            }//end while
            sector = atoi(auxSector);
            paramEmployee[index].sector = sector;
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        default:
            printf("\nError. No se ha ingresado una opcion valida.\n");
            return -2;
            break;
        }//end switch
    }//end if
    else
    {
        printf("\nError. Se ha ingresado una opcion invalida.\n");
        return -2;
    }//end else
    return retorno;
}//end
