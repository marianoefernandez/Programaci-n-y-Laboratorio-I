#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "inputs.h"
#include "Jugadores.h"
//#include "Equipos.h"

//0-MENU
void mostrarMenuJ()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Dar de baja\n");
    printf("3-Modificar\n");
    printf("4-Listar ordenado por apellido y nombre\n");
    printf("5-Salir\n");
}

void printModificationMenuJ()
{
    printf("-----ELIJA QUE MODIFICAR-----\n\n");
    printf("1-Nombre\n");
    printf("2-Apellido\n");
    printf("3-Equipo\n");
    printf("4-Sexo\n");
    printf("5-Fecha\n");
    printf("6-Salir\n");
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

int buscarJugadorPorCodigo(eJugadores* jugadores, int len, int codigo)
{
    int i;
    int retorno = -1;
    if(jugadores!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(jugadores[i].codigo==codigo && jugadores[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


//2-ALTAS/BAJAS/MODIFICACION

int agregarJugadores(eJugadores* jugadores,int len,int codigo)
{
    int i;
    char fechaAux[12];
    char codigoEAux[10];
    char auxSexo;
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    char nombreAux[32];
    char apellidoAux[32];
    int dia;
    int mes;
    int anio;
    int codigoE;
    int retorno= -1;

    i=getFreeJ(jugadores, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",nombreAux);//Pido
        //VALIDACION
        while(isOnlyLetters(nombreAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",nombreAux);//Valido
        }
        stringToUpper(nombreAux);//Paso primer caracter a Mayuscula

        getString("\nIngrese el apellido: ",apellidoAux);//Pido
        //VALIDACION
        while(isOnlyLetters(apellidoAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el apellido nuevamente: ",apellidoAux);//Valido
        }
        stringToUpper(apellidoAux);//Paso primer caracter a Mayuscula

        fflush(stdin);
        auxSexo=getChar("\nIngrese el sexo: ");//Pido
        auxSexo=toupper(auxSexo);
        //VALIDACION
        while(auxSexo!= 'M' && auxSexo!= 'F')
        {
            auxSexo=getChar("\nERROR, SOLO INGRESE f/m Ingrese el sexo: ");//Valido
            auxSexo=toupper(auxSexo);
        }

        getString("\nIngrese el codigo del equipo: ",codigoEAux);//Pido
        //VALIDACION
        while(isNumeric(codigoEAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el codigo nuevamente: ",codigoEAux);//Valido
        }

        getString("\nIngrese la fecha de nacimiento: ",fechaAux);//Pido
        //VALIDACION
        while(isADate(fechaAux) == 0)
        {
            getString("\nPOR FAVOR INGRESE UNA FECHA VALIDA \nIngrese la fecha nuevamente: ",fechaAux);//Valido
        }


        //VALIDACION YA QUE EN FUNCION DA ERROR

    for(i=0;i<3;i++)///DÍA
    {
        if(fechaAux[1]!='/')
        {
            diaAux[0]=fechaAux[0];
            diaAux[1]=fechaAux[1];
            break;
        }
        else
        {
            diaAux[0]=fechaAux[0];
        }
    }

    for(i=2;i<10;i++)///MES Y ANIO
    {
        if(fechaAux[2]!='/' && fechaAux[3]!= '/')
        {
            mesAux[0]=fechaAux[2];
            mesAux[1]=fechaAux[3];
            anioAux[0]=fechaAux[5];
            anioAux[1]=fechaAux[6];
            anioAux[2]=fechaAux[7];
            anioAux[3]=fechaAux[8];
            break;
        }

        if(fechaAux[3]!='/' && fechaAux[4]!= '/')
        {
            mesAux[0]=fechaAux[3];
            mesAux[1]=fechaAux[4];
            anioAux[0]=fechaAux[6];
            anioAux[1]=fechaAux[7];
            anioAux[2]=fechaAux[8];
            anioAux[3]=fechaAux[9];
            break;
        }

        if(fechaAux[2]!='/' && fechaAux[3]=='/')
        {
            mesAux[0]=fechaAux[2];
            anioAux[0]=fechaAux[4];
            anioAux[1]=fechaAux[5];
            anioAux[2]=fechaAux[6];
            anioAux[3]=fechaAux[7];
        }

        if(fechaAux[3]!='/' && fechaAux[4]=='/')
        {
            mesAux[0]=fechaAux[3];
            anioAux[0]=fechaAux[5];
            anioAux[1]=fechaAux[6];
            anioAux[2]=fechaAux[7];
            anioAux[3]=fechaAux[8];
        }


    }

        dia=atoi(diaAux);
        mes=atoi(mesAux);
        anio=atoi(anioAux);

        //FIN
        if(dia>31 || dia<=0 && mes>12 || mes<=0 && anio>2050 || anio<=1950)
        {
            printf("\nLA FECHA NO ES VALIDA");
            return -1;
        }
        else
        {
            jugadores[i].fechaNac.dia=dia;
            jugadores[i].fechaNac.mes=mes;
            jugadores[i].fechaNac.anio=anio;
        }

        codigoE=atoi(codigoEAux);
        strcpy(jugadores[i].nombre,nombreAux);
        strcpy(jugadores[i].apellido,apellidoAux);
        jugadores[i].sexo=auxSexo;
        jugadores[i].isEmpty=NOTFREE;
        jugadores[i].codigo=codigo;
        jugadores[i].codigoE=codigoE;

        retorno=0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

//3-ORDENAR

int ordenarJugadoresNombreYApellido(eJugadores* jugadores, int len, int order)
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

int ordenarJugadoresPorSexo(eJugadores* jugadores, int len)
{
    eJugadores auxJugadores;
    int i;
    int j;
    int retorno =0;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(jugadores[i].sexo>jugadores[j].sexo)
            {
                auxJugadores=jugadores[i];
                jugadores[i]=jugadores[j];
                jugadores[j]=auxJugadores;
                retorno=1;
            }
        }
    }
    return retorno;
}

//4-MOSTRAR


//5-EXTRAS

int cantidadJugadoresOcupados(eJugadores* jugadores, int len)
{
    int i;
    int cantidadJugadores=0;
    for (i=0;i<len;i++)
    {
        if (jugadores[i].isEmpty == NOTFREE)
        {
            cantidadJugadores++;
            //break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return cantidadJugadores;
}

void hardcodeoJugadores(eJugadores* jugadores)
{
    int i;
    char nombre[15][32]={"Carlos","Wanchope","Emmanuel","Lionel","Lucas","Martin","Luka","Lionel","Neymar","Lisandro","Alex","Juliana","Liz","Marion","Carla"};
    char apellido[15][32]={"Tevez","Abila","Mas","Galeano","Pratto","Benitez","Modric","Messi","JR","Lopez","Morgan","Martinez","Solari","Gonzalez","Suarez"};
    int codigoEquipo[15]={3,3,3,4,4,1,6,5,9,2,6,5,7,2,1};
    int dia[15]={5,14,15,18,4,17,9,24,5,2,2,6,9,8,7};
    int mes[15]={2,10,1,1,6,6,9,6,2,3,7,11,12,1,2};
    int anio[15]={1984,1989,1989,1993,1988,1994,1985,1987,1992,1983,1989,1992,1997,1995,1999};


    for(i=0;i<15;i++)
    {
        jugadores[i].codigo=i+1;
        strcpy(jugadores[i].nombre,nombre[i]);
        strcpy(jugadores[i].apellido,apellido[i]);

        if(i<10)
        {
            jugadores[i].sexo='M';
        }
        else
        {
            jugadores[i].sexo='F';
        }

        jugadores[i].codigoE=codigoEquipo[i];
        jugadores[i].fechaNac.dia=dia[i];
        jugadores[i].fechaNac.mes=mes[i];
        jugadores[i].fechaNac.anio=anio[i];
        jugadores[i].isEmpty=NOTFREE;
    }
}


