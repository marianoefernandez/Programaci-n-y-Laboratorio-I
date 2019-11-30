#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "Jugadores.h"
//#include "Equipos.h"

//0-MENU
void mostrarMenuJ()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Listar\n");
}

//1-INICIALIZAR
int inicializarJugadores(eJugadores* jugadores, int len)
{
    int i;
    int retorno=-1;

    if(jugadores!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            jugadores[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

int getFreeJ(eJugadores* jugadores,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (jugadores[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}


//2-ALTAS

int agregarJugadores(eJugadores* jugadores,int len,int codigo)
{
    int i;
    char diaAux[10];
    char mesAux[10];
    char anioAux[10];
    char auxSexo;
    int dia;
    int codigoAux;
    int mes;
    int anio;
    int retorno= -1;

    i=getFreeJ(jugadores, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",jugadores[i].nombre);//Pido
        //VALIDACION
        while(isOnlyLetters(jugadores[i].nombre) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",jugadores[i].nombre);//Valido
        }
        stringToUpper(jugadores[i].nombre);//Paso primer caracter a Mayuscula

        getString("\nIngrese el apellido: ",jugadores[i].apellido);//Pido
        //VALIDACION
        while(isOnlyLetters(jugadores[i].apellido) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el apellido nuevamente: ",jugadores[i].apellido);//Valido
        }
        stringToUpper(jugadores[i].apellido);//Paso primer caracter a Mayuscula

        auxSexo=getChar("\nIngrese el sexo: ");//Pido
        //VALIDACION
        while(auxSexo!= 'M' || auxSexo!= 'm' || auxSexo!= 'F' || auxSexo!= 'f')
        {
            auxSexo=getChar("\nERROR, SOLO INGRESE f/m Ingrese el sexo: ");//Valido
        }
        jugadores[i].sexo=auxSexo;

        getString("\nIngrese el codigo del equipo: ",codigoAux);//Pido
        //VALIDACION
        while(isNumeric(codigoAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el codigo nuevamente: ",codigoAux);//Valido
        }
        codigo=atoi(codigoAux);//Paso cadena a numero
        jugadores[i].codigo=codigo;


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
        jugadores[i].fechaNac.anio=anio;


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
        jugadores[i].fechaNac.mes=mes;

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
        jugadores[i].fechaNac.dia=dia;

        jugadores[i].isEmpty =NOTFREE;
        jugadores[i].codigo =codigo;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

//3-ORDENAR

int ordenarJugadoresNombreYApellido(eJugadores* jugadores, int len, int order)                                                            ///2.5 Función sortEmployees:
{
    int i;
    int j;
    int retorno=-1;
    eJugadores aux[1];

    if(jugadores!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(jugadores[i].apellido,jugadores[j].apellido)>0)
                    {
                        aux[0]=jugadores[i];
                        jugadores[i]=jugadores[j];
                        jugadores[j]=aux[0];
                    }
                    if((stricmp(jugadores[i].apellido,jugadores[j].apellido)==0) && (stricmp(jugadores[i].nombre,jugadores[j].nombre)>0))
                    {
                        aux[0]=jugadores[i];
                        jugadores[i]=jugadores[j];
                        jugadores[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(jugadores[i].apellido,jugadores[j].apellido)<0)
                    {
                        aux[0]=jugadores[i];
                        jugadores[i]=jugadores[j];
                        jugadores[j]=aux[0];
                    }
                    if((stricmp(jugadores[i].apellido,jugadores[j].apellido)==0) && (stricmp(jugadores[i].nombre,jugadores[j].nombre)<0))
                    {
                        aux[0]=jugadores[i];
                        jugadores[i]=jugadores[j];
                        jugadores[j]=aux[0];
                    }
                    break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

//4-MOSTRAR

