#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

//0-MENUES
void printFirstMenu()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a una persona: ");
    printf("\n2-Modificar persona: ");
    printf("\n3-Dar de baja a una persona: ");
    printf("\n4-Listar contenido: ");
    printf("\n5-Ordenar contenido: ");
    printf("\n6-Salir: ");
}

void printModificationMenu()
{
    printf("-----¿Qué desea modificar?-----\n\n");
    printf("1-Nombre\n");
    printf("2-Apellido\n");
}

void printOrdenarMenu()
{
    printf("-----¿Como desea listar los productos?-----\n\n");
    printf("1-Por descripcion descendente.\n");
    printf("2-Por cantidad ascendente.\n");
}

void printInformarMenu()
{
    printf("-----¿Qué desea informar?-----\n\n");
    printf("1-Los datos del/os producto/s de menor Importe.\n");
    printf("2-Los datos del/os producto/s que superan el valor de precio promedio.\n");
}

int main()
{
    int opcion;
    int cantidadAgenda;
    int retorno;
    eProducto productos[TAM];

    if (initAgenda(agenda,TAM)==0)
    {
        do
        {
            printFirstMenu();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                retorno=agregarAgenda(agenda,TAM);

                switch(retorno)
                {
                    case 0:
                        printf("\nSe cargo el empleado\n");
                        break;

                    case -1:
                        printf("\nNO HAY ESPACIO\n");
                        break;

                    case -2:
                        printf("\nERROR, EL LEGAJO YA EXISTE\n");
                        break;
                }
                /*hardcoded(list,HARDCODING);
                printf("\nSe hardcodearon empleados");
                */
                break;

            case 2:
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                   if(modificarAgenda(agenda,TAM)!=-1)
                   {
                       printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
                   }
                   else
                   {
                       printf("\nLa persona no existe\n");
                   }
                }else
                {
                    printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
                }
                break;

            case 3:
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                    retorno = eliminarAgenda(agenda,TAM,getInt("Ingrese el legajo: "));
                    switch(retorno)
                    {
                    case 0:
                        printf("\nSe elimino la persona\n");
                        break;
                    case 1:
                        printf("\nAccion cancelada por el usuario\n");
                        break;
                    case -1:
                        printf("\nNo se encontro el dato\n");
                        break;
                    case 2:
                        printf("\nLa persona se elimino anteriormente o no existe la persona\n");
                        break;
                    }
                }
                else
                {
                    printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
                }
            case 4:
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                    printAgendas(agenda,TAM);
                }
                else
                {
                   printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
                }
                break;

            case 5:
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                    ordenarAgendaPorApellido(agenda,TAM,0);
                }
                else
                {
                   printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
                }
                break;

            case 6:
                printf("\nSALIENDO...");

            default:
                printf("\nSeleccione una opcion valida \n");

            }
            system("pause");
            system("cls");
        }while(opcion!=6);
    }
    else
    {
       printf("\n\nHubo un error al crear la lista, no hay espacio en memoria\n\n");
    }
}

//1-INICIALIZACION Y BUSQUEDAS

int initProductos(eProducto* productos, int len)
{
    int i;
    int retorno=-1;

    if(productos!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            productos[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

int getFree(eProducto* productos,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (productos[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

int buscarProductoPorCodigo(eProducto* productos, int len, int codigo)
{
    int i;
    int retorno = -1;
    if(productos!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(productos[i].codigo==codigo && productos[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//2-ALTAS

int agregarAgenda(eAgenda* agenda,int len)
{
    int i;
    int retorno= -1;
    int legajo;
    char auxLegajo[20];

    i= getFree(agenda, len);

    if(i>=0)
    {
        getString("\nIngrese el legajo: ",auxLegajo);//Pido

        //VALIDACION
        while(isNumeric(auxLegajo) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el legajo nuevamente: ",auxLegajo);//Valido
        }

        legajo=atoi(auxLegajo);//Paso cadena a numero

        if (validarLegajo(agenda,TAM,legajo)!=-1)
        {
            return -2;
        }
        else
        {
            agenda[i].legajo=legajo;
        }
        getString("\nIngrese el nombre: ",agenda[i].nombre);//Pido
        //VALIDACION
        while(isOnlyLetters(agenda[i].nombre) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",agenda[i].nombre);//Valido
        }
        stringToUpper(agenda[i].nombre);//Paso primer caracter a Mayuscula


        getString("\nIngrese el apellido: ",agenda[i].apellido);//Pido
        //VALIDACION
        while(isOnlyLetters(agenda[i].apellido) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el apellido nuevamente: ",agenda[i].apellido);//Valido
        }
        stringToUpper(agenda[i].apellido);//Paso primer caracter a Mayuscula

        agenda[i].isEmpty =1;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

//3-BAJAS

int eliminarAgenda(eAgenda* agenda, int len, int legajo)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (agenda!=NULL && len>0)
    {
        printAgendas(agenda,len);

        index = buscarAgendaPorLegajo(agenda,len,legajo);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL ALUMNO A LIBRE
        {

            if (agenda[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\n\nDar de baja a:");
                printAgenda(agenda[index]);
                printf("\n\nEsta seguro de eliminar el dato s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                agenda[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (agenda[index].isEmpty==FREE)
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

//4-MODIFICAR
int modificarAgenda(eAgenda* agenda, int len)
{
    int index;
    int legajo;
    int opcion;
    char auxNombre[30];
    char auxApellido[30];
    char auxLegajo[20];
    int retorno;

    if(len >0 && agenda!= NULL)
    {
        retorno=0;

        printAgendas(agenda, len);

        getString("\nIngrese legajo: ",auxLegajo);

        while(isNumeric(auxLegajo)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO LETRAS\nIngrese legajo nuevamente: ",auxLegajo);
        }
        legajo=atoi(auxLegajo);

        index=buscarAgendaPorLegajo(agenda, len, legajo);

        if(index>=0)
        {

    printModificationMenu();

    opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            getString("\nIngrese un nuevo nombre: ",auxNombre);
            while(isOnlyLetters(auxNombre)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo nombre: ",auxNombre);
            }
            stringToUpper(auxNombre);
            strcpy(agenda[index].nombre, auxNombre);
            break;

        case 2:
	    getString("\nIngrese un nuevo apellido: ",auxApellido);
            while(isOnlyLetters(auxApellido)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo apellido: ",auxApellido);
            }
            stringToUpper(auxApellido);
            strcpy(agenda[index].apellido, auxApellido);
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

//5-ORDENAR

int ordenarAgendaPorApellido(eAgenda* agenda, int len, int order)
{
    eAgenda auxAgenda;
    int i;
    int j;
    int retorno =-1;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(agenda[i].apellido,agenda[j].apellido) > order)//1 ASC y 0-DESC
            {
                auxAgenda=agenda[i];
                agenda[i]=agenda[j];
                agenda[j]=auxAgenda;
                retorno=0;
            }
        }
    }
    return retorno;
}

//6-MOSTRAR

void printAgenda(eAgenda agenda)
{

    printf("\n%d -- %10s %15s\n\n", agenda.legajo, agenda.nombre, agenda.apellido);
}

int printAgendas(eAgenda* agenda, int len)
{
    int i;
    printf("LEGAJO        NOMBRE        APELLIDO\n");
    for(i=0; i<len; i++)
    {
        if(agenda[i].isEmpty==NOTFREE)
        {
            printAgenda(agenda[i]);
        }
    }
    return 0;
}

//7-HARDCODEO

//8-EXTRAS

int agendaNotFree(eAgenda* agenda,int len)
 {
     int i;
     int agendaNotFreeLen=0;

     for(i=0;i<len;i++)
     {
         if(agenda[i].isEmpty==NOTFREE)
         {
             agendaNotFreeLen++;
         }
     }

     return agendaNotFreeLen;
 }
