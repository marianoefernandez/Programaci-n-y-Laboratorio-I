#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "Partido.h"

//0-MENU
void mostrarMenuP()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Listar ordenado por fecha\n");
    printf("3-Salir\n");
}

void printModificationMenuP()
{
    printf("-----ELIJA QUE MODIFICAR-----\n\n");
    printf("1-Equipo Local\n");
    printf("2-Equipo Visitante\n");
    printf("3-Referi\n");
    printf("4-Fecha\n");
    printf("5-Salir\n");
}


//1-INICIALIZAR
int inicializarPartidos(ePartido* partidos, int len)
{
    int i;
    int retorno=-1;

    if(partidos!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            partidos[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

int getFreeP(ePartido* partidos,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (partidos[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

int buscarPartidoPorCodigo(ePartido* partido,int len,int codigo)
{
    int i;
    int retorno = -1;
    if(partido!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(partido[i].codigo==codigo && partido[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


//2-ALTAS

int agregarPartidos(ePartido* partidos,int len,int codigo)
{
    int i;
    char fechaAux[12];
    char codigoEVisAux[10];
    char codigoELocAux[10];
    char codigoRAux[10];
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    int dia;
    int mes;
    int anio;
    int codigoEVis;
    int codigoELoc;
    int codigoR;
    int retorno= -1;

    i=getFreeP(partidos, len);

    if(i>=0)
    {
        getString("\nIngrese el codigo del equipo local: ",codigoELocAux);//Pido
        //VALIDACION
        while(isNumeric(codigoELocAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el codigo nuevamente: ",codigoELocAux);//Valido
        }
        getString("\nIngrese el codigo del equipo visitante: ",codigoEVisAux);//Pido
        //VALIDACION
        while(isNumeric(codigoEVisAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el codigo nuevamente: ",codigoEVisAux);//Valido
        }

        getString("\nIngrese el codigo del referi: ",codigoRAux);//Pido
        //VALIDACION
        while(isNumeric(codigoRAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el codigo nuevamente: ",codigoRAux);//Valido
        }

        getString("\nIngrese la fecha del encuentro: ",fechaAux);//Pido
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
            partidos[i].fechaP.dia=dia;
            partidos[i].fechaP.mes=mes;
            partidos[i].fechaP.anio=anio;
        }

        codigoELoc=atoi(codigoELocAux);
        codigoEVis=atoi(codigoEVisAux);
        codigoR=atoi(codigoRAux);

        partidos[i].isEmpty=NOTFREE;
        partidos[i].codigo=codigo;
        partidos[i].codigoLocal=codigoELoc;
        partidos[i].codigoVis=codigoEVis;
        partidos[i].codigoReferi=codigoR;


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

int ordenarPartidosPorFecha(ePartido* partidos, int len, int order)
{
    int i;
    int j;
    int retorno=-1;
    ePartido aux[1];

    if(partidos!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (partidos[i].fechaP.anio>partidos[j].fechaP.anio)
                    {
                        aux[0]=partidos[i];
                        partidos[i]=partidos[j];
                        partidos[j]=aux[0];
                    }
                    if((partidos[i].fechaP.anio==partidos[j].fechaP.anio) && (partidos[i].fechaP.mes>partidos[j].fechaP.mes))
                    {
                        aux[0]=partidos[i];
                        partidos[i]=partidos[j];
                        partidos[j]=aux[0];
                    }
                    break;
                case 1:
                    if (partidos[i].fechaP.anio<partidos[j].fechaP.anio)
                    {
                        aux[0]=partidos[i];
                        partidos[i]=partidos[j];
                        partidos[j]=aux[0];
                    }
                    if((partidos[i].fechaP.anio==partidos[j].fechaP.anio) && (partidos[i].fechaP.mes<partidos[j].fechaP.mes))
                    {
                        aux[0]=partidos[i];
                        partidos[i]=partidos[j];
                        partidos[j]=aux[0];
                    }
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

//4-MOSTRAR


//5-EXTRAS

void hardcodeoPartidos(ePartido* partido)
{
    int i;
    int dia[6]={5,6,7,7,7,23};
    int mes[6]={12,12,12,12,12,11};
    int anio[6]={2019,2019,2019,2019,2019,2019};
    int codigoL[6]={1,5,4,1,2,10};
    int codigoV[6]={2,6,3,3,4,4};
    int codigoR[6]={1,3,3,2,1,4};

    for(i=0;i<6;i++)
    {
        partido[i].codigo=i+1;
        partido[i].codigoLocal=codigoL[i];
        partido[i].codigoVis=codigoV[i];
        partido[i].fechaP.dia=dia[i];
        partido[i].fechaP.mes=mes[i];
        partido[i].fechaP.anio=anio[i];
        partido[i].codigoReferi=codigoR[i];
        partido[i].isEmpty=NOTFREE;
    }
}


