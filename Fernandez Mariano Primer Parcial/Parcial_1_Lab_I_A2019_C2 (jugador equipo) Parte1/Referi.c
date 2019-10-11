#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"


//0-MENU
void mostrarMenuR()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Listar\n");
}

//1-INICIALIZAR
int inicializarReferis(eReferi* referis, int len)
{
    int i;
    int retorno=-1;

    if(referis!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            referis[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

int getFreeR(eReferi* referis,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (referis[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}


//2-ALTAS

int agregarReferis(eReferi* referis,int len,int codigo)
{
    int i;
    char diaAux[10];
    char mesAux[10];
    char anioAux[10];
    char auxSexo;
    int dia;
    int mes;
    int anio;
    int retorno= -1;

    i=getFreeR(referis, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",referis[i].nombre);//Pido
        //VALIDACION
        while(isOnlyLetters(referis[i].nombre) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",referis[i].nombre);//Valido
        }
        stringToUpper(referis[i].nombre);//Paso primer caracter a Mayuscula

        getString("\nIngrese el apellido: ",referis[i].apellido);//Pido
        //VALIDACION
        while(isOnlyLetters(referis[i].apellido) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el apellido nuevamente: ",referis[i].apellido);//Valido
        }
        stringToUpper(referis[i].apellido);//Paso primer caracter a Mayuscula

        auxSexo=getChar("\nIngrese el sexo: ");//Pido
        //VALIDACION
        while(auxSexo!= 'M' || auxSexo!= 'm' || auxSexo!= 'F' || auxSexo!= 'f')
        {
            auxSexo=getChar("\nERROR, SOLO INGRESE f/m Ingrese el sexo: ");//Valido
        }
        referis[i].sexo=auxSexo;

        getString("\nIngrese el eMail: ",referis[i].eMail);//Pido
        //VALIDACION
        /*while(//Funcion que valide mail (referis[i].nombre) == 0)
        {
            getString("\nPOR FAVOR INGRESE UN EMAIL VALIDO\nIngrese el eMail nuevamente: ",referis[i].eMail);//Valido
        }
        */

        getString("\nIngrese el anio de nacimiento: ",anioAux);//Pido
        //VALIDACION
        while(isNumeric(anioAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el anio nuevamente: ",anioAux);//Valido
        }

        while(validarAnio(anioAux) == 0)
        {
                //Valido
        }


        anio=atoi(anioAux);//Paso cadena a numero
        referis[i].fechaNac.anio=anio;


                getString("\nIngrese el mes de nacimiento: ",mesAux);//Pido
        //VALIDACION
        while(isNumeric(mesAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el mes nuevamente: ",mesAux);//Valido
        }

        while(validarMes(mesAux) == 0)
        {
                //Valido
        }


        mes=atoi(mesAux);//Paso cadena a numero
        referis[i].fechaNac.mes=mes;

                getString("\nIngrese el dia de nacimiento: ",diaAux);//Pido
        //VALIDACION
        while(isNumeric(diaAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el dia nuevamente: ",diaAux);//Valido
        }

        while(validarDia(diaAux) == 0)
        {
                //Valido
        }


        dia=atoi(diaAux);//Paso cadena a numero
        referis[i].fechaNac.dia=dia;

        referis[i].isEmpty =NOTFREE;
        referis[i].codigo =codigo;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

//3-MOSTRAR

int printReferi(eReferi* referis)
{
    int i;
    int index;
    printf("Codigo       Nombre          Apellido        Sexo          Fecha de Nacimiento          Email\n");
    for(i=0; i<len; i++)
    {
        if(jugadores[i].isEmpty==NOTFREE)
        {
            printf("%d-- %10s %7s %5c %7d/%d/%d %12s\n",referis[i].codigo,referis[i].nombre,referis[i].apellido,referis[i].sexo,referis[i].fechaNac.dia,referis[i].fechaNac.mes,referis[i].fechaNac.anio,referis[i].eMail);
        }
    }
    return 0;
}



