#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"



//0-MUESTRO MENUES (4 de 4)
void printFirstMenu()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a un empleado: ");
    printf("\n2-Modificar empleado: ");
    printf("\n3-Dar de baja a un empleado: ");
    printf("\n4-Informar: ");
}

void printSecondMenu()
{
    printf("\n\n1-Ordenar empleados por apellido y sector: ");
    printf("\n\n2-Calcular total de salarios, el salario promedio y cuantos empleados superan el salario promedio: ");
}

void printSortMenu()
{
    printf("-----¿Como desea ordenar?----\n\n");
    printf("\n1-Ordenar por apellido");
    printf("\n2-Ordenar por sector");

}
void printModificationMenu()
{
    printf("-----¿Qué desea modificar?-----\n\n");
    printf("1-Nombre\n");
    printf("2-Apellido\n");
    printf("3-Salario\n");
    printf("4-Sector\n");
}

//1-FUNCIONES PARA INICIALIZAR (1.5 de 2) //LA DEL ID NO SE SI FUNCIONA
int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;

    if(list!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            list[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

//2-FUNCIONES PARA AÑADIR (2 de 2)

int addEmployees(Employee* list,int len,int id)
{
    int i;
    int sector;
    int retorno= -1;
    float salary;
    char auxSalary[50];
    char auxSector[50];

    i= getFree(list, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",list[i].name);//Pido
        //VALIDACION
        while(isOnlyLetters(list[i].name) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",list[i].name);//Valido
        }
        stringToUpper(list[i].name);//Paso primer caracter a Mayuscula


        getString("\nIngrese el apellido: ",list[i].lastName);//Pido
        //VALIDACION
        while(isOnlyLetters(list[i].lastName) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el apellido nuevamente: ",list[i].lastName);//Valido
        }
        stringToUpper(list[i].lastName);//Paso primer caracter a Mayuscula


        getString("\nIngrese el salario: ",auxSalary);//Pido
        //VALIDACION
        while(isNumeric(auxSalary) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el salario nuevamente: ",auxSalary);//Valido
        }
        salary=atoi(auxSalary);//Paso cadena a numero
        list[i].salary=salary;


        getString("\nIngrese el sector: ",auxSector);//Pido
        //VALIDACION
        while(isNumeric(auxSector) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el sector nuevamente: ",auxSector);//Valido
        }
        sector=atoi(auxSector);//Paso cadena a numero
        list[i].sector=sector;

        list[i].isEmpty =1;
        list[i].id =id;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

int getFree(Employee* list,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (list[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

//3-BUSCAR EMPLEADO POR ID (1 de 1)
int findEmployeeById(Employee* list, int len, int id)
{
    int i;
    int retorno = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//4-MODIFICACION (1 de 1)
int modificationEmployee(Employee* list, int len)
{
    int id;
    int index;
    int opcion;
    int sector;
    char auxName[30];
    char auxLastName[30];
    char auxSalary[30];
    char auxSector[30];
    float salary;
    char auxId[20];
    int retorno;

    if(len >0 && list!= NULL)
    {
        retorno=0;

        printEmployees(list, len);

        getString("\nIngrese ID: ",auxId);

        while(isNumeric(auxId)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO LETRAS\nIngrese ID nuevamente: ",auxId);
        }
        id=atoi(auxId);

        index=findEmployeeById(list, len, id);

        if(index>=0)
        {

    printModificationMenu();

    opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            getString("\nIngrese un nuevo nombre: ",auxName);
            while(isOnlyLetters(auxName)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo nombre: ",auxName);
            }
            stringToUpper(auxName);
            strcpy(list[index].name, auxName);
            break;

        case 2:
	    getString("\nIngrese un nuevo apellido: ",auxLastName);
            while(isOnlyLetters(auxLastName)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo apellido: ",auxLastName);
            }
            stringToUpper(auxLastName);
            strcpy(list[index].lastName, auxLastName);
            break;

        case 3:
            getString("\nIngrese un nuevo salario: ",auxSalary);
            while(isNumeric(auxSalary)==0)
            {
		getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS\nIngrese nuevamente un nuevo salario: ",auxSalary);
            }
            salary = atoi(auxSalary);
            list[index].salary = salary;
            break;

        case 4:
	    getString("\nIngrese un nuevo sector: ",auxSector);
            while(isNumeric(auxSector)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS\nIngrese nuevamente un nuevo sector: ",auxSector);
            }
            sector = atoi(auxSector);
            list[index].sector = sector;
            break;

        default:
            printf("\nError. No se ha ingresado una opcion valida.\n");
            break;
            }
        }
        else
        {
            retorno=-1;
        }
    return retorno;
    }
}


//5-BAJA LÓGICA (1 de 1) NO SE SI ESTA BIEN

int removeEmployee(Employee* list, int len, int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (list!=NULL && len>0)
    {
        printEmployees(list,len);

        index = findEmployeeById(list,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL ALUMNO A LIBRE
        {

            if (list[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\n\nDar de baja a:");
                printEmployee(list[index]);
                printf("\n\nEsta seguro de eliminar el dato s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                list[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (list[index].isEmpty==FREE)
                {
                    retorno=2;
                }
                else
                    {
                        retorno =1;//CANCELO ACCION
                    }
            }
        }
    }
    return retorno;//SI RETORNA -1 NO FUNCIONO
}

//6-FUNCIONES DE ORDENAMIENTO (2 de 2) LISTO

int sortEmployeesByLastName(Employee* list, int len, int order)
{
    Employee auxList;
    int i;
    int j;
    int retorno =-1;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName) > order)//1 ASC y 0-DESC
            {
                auxList=list[i];
                list[i]=list[j];
                list[j]=auxList;
                retorno=0;
            }
        }
    }
    return retorno;
}

int sortEmployeesBySector(Employee* list, int len)
{
    Employee auxList;
    int i;
    int j;
    int retorno =-1;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(list[i].sector>list[j].sector)
            {
                auxList=list[i];
                list[i]=list[j];
                list[j]=auxList;
            }
        }
    }
    return retorno;
}

//7-FUNCIONES PARA MOSTRAR (2 de 2) LISTO
void printEmployee(Employee list)
{
    printf("\n%d -- %10s %15s %20.2f $ %10d\n\n", list.id, list.name, list.lastName, list.salary, list.sector);
}

int printEmployees(Employee* list, int len)
{
    int i;
    printf("ID        Nombre        Apellido          Salario            Sector\n");
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==NOTFREE)
        {
            printEmployee(list[i]);
        }
    }
    return 0;
}

//8-FUNCIONES DE HARDCODEO (1 de 1) LISTO

void hardcoded(Employee* list, int len) //TERMINADA
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char name[10][51] = {"Jorge","Mauro","Diego","Daniela","Juliana","Victoria","Carmen","Tomas","Damaris","Julian"};
    char lastName[10][51] = {"Rios","Zarate","Perez","Gonzalez","Lopez","Rodriguez","Fernandez","Fidalgo","Tevez","Riquelme"};
    float salary[10] = {2850,4425,3250,5785,6900,3450,777,2320,1400,11450};
    int sector[10] = {8,33,11,11,8,8,7,7,33,13};

    int i;
    for (i=0; i<len; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = NOTFREE;
    }
}

 //9-CALCULAR PROMEDIOS Y OTROS DATOS (4 de 4)

 float totalSalary(Employee* list,int len)
 {
     float sumaSalarios=0;
     int i;

     for(i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
             sumaSalarios = sumaSalarios + list[i].salary;
         }
     }
     return sumaSalarios;
 }

 float salaryAverage(Employee* list,int len,float allSalary)
 {
     int cantidadCargados=0;
     float average;
     int i;

     for(i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
             cantidadCargados++;
         }
     }
     average=allSalary/cantidadCargados;
     return average;
 }

 int betterThanAverage(Employee* list,int len,float averageSalary)
 {
     int betterSalaryAverage=0;
     float auxSalary;
     int i;

     for (i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
            auxSalary=list[i].salary;
            if(auxSalary>averageSalary)
            {
               betterSalaryAverage++;
            }
         }
     }

     return betterSalaryAverage;
 }

 int employeesNotFree(Employee* list,int len)
 {
     int i;
     int employeesNotFreeLen=0;

     for(i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
             employeesNotFreeLen++;
         }
     }

     return employeesNotFreeLen;
 }

