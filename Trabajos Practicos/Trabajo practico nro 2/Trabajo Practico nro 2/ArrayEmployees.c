#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"



//0-MUESTRO MENUES (3 de 3)
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

//MENU DE MODIFICACION
void printModificationMenu()
{
    printf("¿Qué desea modificar?\n");
    printf("1.Nombre\n");
    printf("2.Apellido\n");
    printf("3.Salario\n");
    printf("4.Sector\n");
}

//SWITCH DEL PRIMER MENU (FALTA) QUE MUESTRE MENU Y LUEGO SWITCH CON DO/WHILE (FUNCION PRINCIPAL POR ESTA PASA TODO)
void opcionesMenuPrincipal(eEmpleado* empleados ,int seCargo)
{
    int opcion;
    int retorno;

    do
        {
            menuPrincipal();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                if (agregarEmpleados(empleados,TAM)== 0)
                {
                    printf("\nSe cargo el empleado\n");
                }
                else
                {
                    printf("\nNO HAY ESPACIO\n");
                }
                /*hardcodeoEmpleados(empleados,1);
                printf("\nSe hardcodearon empleados");
                */
                seCargo=1;

                break;

            case 2:
                if (seCargo==1)
                {
                    //MODIFICAREMPLEADO
                }else
                {
                    printf("\nSe elimino el empleado\n");
                }
                break;

            case 3:
                if (seCargo==1)
                {
                    retorno = bajaEmpleado(empleados,TAM);
                    switch(retorno)
                    {
                    case 0:
                        printf("\nSe elimino el empleado\n");
                        break;
                    case 1:
                        printf("\nAccion cancelada por el usuario\n");
                        break;
                    case -1:
                        printf("\nNo se encontro el dato\n");
                        break;
                    }
                }
                else
                {
                    printf("Por favor primero realice una carga");
                }
                    break;

            case 4:
                if (seCargo==1)
                {
                    opcionesMenuSecundario(empleados);
                }
                else
                {
                    printf("Por favor primero realice una carga");
                }
                break;
            default:
                printf("Seleccione una opcion valida ");

            }
            system("pause");
            system("cls");
        }while(opcion!=0);
}

//SWITCH DEL SEGUNDO MENU (FALTA)
void opcionesMenuSecundario(eEmpleado* empleados)
{
    int opcion;
    int retorno;

    do
        {
            menuSecundario();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                ordenarEmpleadosApellido(empleados,TAM,1);
                ordenarEmpleadosSector(empleados,TAM);
                mostrarListadoDeEmpleados(empleados,TAM);
                system("pause");
                opcionesMenuPrincipal(empleados,1);
                break;

            case 2:
                //SACAR PROMEDIO Y LO OTRO (FALTA)
                break;

            default:
                printf("Seleccione una opcion valida ");

            }
            system("pause");
            system("cls");
        }while(opcion!=0);
}

//SWITCH DEL MENU DE MODIFICACION (FALTA)

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

/*
int getId (int* n)
{
    *n=*n+1;
    return &n;
}
*/

int getId(Employee* list, int len)
{
    int retorno=0;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == NOTFREE)
            {
                if(list[i].id > retorno)
                {
                    retorno = list[i].id;
                }
            }
        }
    }
    return retorno+1;
}

//2-FUNCIONES PARA AÑADIR (2 de 2)

int addEmployees(Employee* list,int len)
{
    int i;
    int id;
    int sector;
    int retorno= -1;
    float salary;
    char auxSalary[50];
    char auxSector[50];

    i= getFree(list, len);
    id= getId(list, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",list.name);//Pido
        //VALIDACION
        while(isOnlyLetters(list[i].name) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",list.name);//Valido
        }
        stringToUpper(list[i].name);//Paso primer caracter a Mayuscula


        getString("\nIngrese el apellido: ",list.lastName);//Pido
        //VALIDACION
        while(isOnlyLetters(list[i].lastName) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el apellido nuevamente: ",list.lastName);//Valido
        }
        stringToUpper(list[i].lastName);//Paso primer caracter a Mayuscula


        getString("\nIngrese el salario: ",auxSalary);//Pido
        //VALIDACION
        while(isNumeric(auxSalary) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el salario nuevamente: ",auxSalary);//Valido
        }//end while
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

int getFree(eEmpleado* list,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<cantidad;i++)
    {
        if (list[i].estado == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

/*int agregarEmpleados (eEmpleado* empleados,int cantidad) //TERMINADA
{
    int i;
    //int id;
    int retorno=-1;
    //id=generarId(empleados,TAM);
    i = buscarLibre(empleados,cantidad);
    printf("%d",i);
    if (i!=-1)//Hay lugar
    {
        empleados[i] = pedirEmpleado();
        //empleados[i].id = id;
        empleados[i].estado==OCUPADO;
        printf("%d\n%s\n%s\n%.1f\n%d\n",empleados[i].id,empleados[i].nombre,empleados[i].apellido,empleados[i].salario,empleados[i].sector);
        retorno = 0;
    }
    return retorno;
}
*/
//3-BUSCAR EMPLEADO POR ID (1 de 1)
int findEmployeeById(Employee* list, int len, int id)
{
    int i;
    int retorno = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//4-MODIFICACION (0.5/1) NO ENTIENDO TANTO EL CODIGO, Y NO QUIERO COPIAR CÓDIGO

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

    if(len >0 && paramEmployee!= NULL)
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

    void printModificationMenu ();

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
            printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
            break;

        case 2:
	    getString("\nIngrese un nuevo apellido: ",auxLastName);
            while(isOnlyLetters(auxLastName)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo apellido: ",auxLastName);
            }
            stringToUpper(auxLastName);
            strcpy(list[index].lastName, auxLastName);
            printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
            break;

        case 3:
            getString("\nIngrese un nuevo salario: ",auxSalary);
            while(isNumeric(auxSalary)==0)
            {
		getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS\nIngrese nuevamente un nuevo salario: ",auxSalary);
            }
            salary = atoi(auxSalary);
            list[index].salary = salary;
            printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
            break;

        case 4:
	    getString("\nIngrese un nuevo sector: ",auxSector);
            while(isNumeric(auxSector)==0)
            {
		getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS\nIngrese nuevamente un nuevo sector: ",auxSector);
            }
            sector = atoi(auxSector);
            list[index].sector = sector;
            printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
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

//5-BAJA LÓGICA (0.5/1) NO SE SI ESTA BIEN

int removeEmployee(Employee* list, int len, int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (list!=NULL && len>0)
    {
        mostrarListadoDeEmpleados(list,len);

        index = findEmployeeById(list,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL ALUMNO A LIBRE
        {
            printEmployee(list[index]);
            printf("Esta seguro de eliminar el dato s/n: ");
            respuesta = getche ();
            if (respuesta=='s')
            {
                list[index].estado = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                retorno =1;//CANCELO ACCION
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
    printf("\n%d -- %10s %15s %20f %10d\n\n", list.id, list.nombre, list.apellido, list.salario, list.sector);
}

void printEmployees(Employee* list, int len)
{
    int i;
    printf("ID        Nombre        Apellido          Salario            Sector\n");
    for(i=0; i<len; i++)
    {
        if(list[i].estado==NOTFREE)
        {
            printEmployee(list[i]);
        }
    }
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
        empleados[i].sector = sector[i];
        empleados[i].estado = NOTFREE;
    }

}

 //9-CALCULAR PROMEDIOS Y OTROS DATOS
