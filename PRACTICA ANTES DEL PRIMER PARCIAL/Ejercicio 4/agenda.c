#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void printFirstMenu()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a una persona: ");
    printf("\n2-Modificar persona: ");
    printf("\n3-Dar de baja a una persona: ");
    printf("\n4-Mostrar ordenado por apellido: ");
}

void printModificationMenu()
{
    printf("-----¿Qué desea modificar?-----\n\n");
    printf("1-Nombre\n");
    printf("2-Apellido\n");
}

int initAgenda(eAgenda* agenda, int len)
{
    int i;
    int retorno=-1;

    if(agenda!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            agenda[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

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
        agenda[i].legajo=legajo;

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

int getFree(eAgenda* agenda,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (agenda[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

int buscarAgendaPorLegajo(eAgenda* agenda, int len, int legajo)
{
    int i;
    int retorno = -1;
    if(agenda!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(agenda[i].legajo==legajo && agenda[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

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

void printAgenda(eAgenda agenda)
{

    printf("\n%d -- %10s -- %15s\n\n", agenda.legajo, agenda.nombre, agenda.apellido);
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


