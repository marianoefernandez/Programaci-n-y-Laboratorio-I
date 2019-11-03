#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "inputs.h"
#define TAM 1000
#define OCUPADO 1
#define LIBRE 0

//Equipos:
//Altas,Bajas,Modificación,Listar

//ESTRUCTURAS
typedef struct
{
    int codigo;
    int isEmpty;
    char nombre[52];
    char localidad[34];
}eEquipo;

//PROTOTIPOS
void printMenuPrincipal();
void printMenuE();
void printMenuJ();
void printMenuR();
void printMenuP();
void printMenuModificacion();

int inicializarEquipos(eEquipo*,int);
//inicializar jugadores/referis/partidos
int buscarLibreE(eEquipo*,int);
//buscarLibre de las otras entidades
int buscarEquipoPorId (eEquipo*,int,int);

int altaEquipo(eEquipo*,int,int);

int modificarEquipo(eEquipo*,int,int);

int ordenarEquiposNombreYLocalidad(eEquipo*,int,int);

void printEquipo(eEquipo);
int printEquipos(eEquipo*,int);

void hardcodeoEquipos(eEquipo*,int);


int main()
{
    int codigoE=0;
    int opcion;
    int opcionE;
    eEquipo equipos [TAM];

    do
    {
        printMenuPrincipal();
        opcion=getInt("\nSu opcion:");

        switch(opcion)
        {
        case 1:
            if(inicializarEquipos(equipos,TAM)==0)
            {
                do
                {
                    printMenuE();
                    opcionE=getInt("\nSu opcion:");
                    switch(opcionE)
                    {
                        case 1:
                            /*
                            codigoE++;
                            if(altaEquipo(equipos,TAM,codigoE)==0)
                            {
                                printf("\nSe cargo correctamente.");
                            }
                            else
                            {
                                printf("\nHubo un error en el alta.");
                            }
                            */

                            hardcodeoEquipos(equipos,TAM);
                            opcionE=5;
                            break;

                        case 2:
                            if(modificarEquipo(equipos,TAM,getInt("Ingrese el codigo: "))==0)
                            {
                                printf("\nSe modifico correctamente.");
                            }
                            else
                            {
                                printf("\nHubo un error en la modificacion.");
                            }
                            opcionE=5;
                            break;

                        case 3:
                            printEquipos(equipos,TAM);
                            if(bajaEquipo(equipos,TAM,getInt("Ingrese el codigo: "))==0)
                            {
                                printf("\nSe dio de baja correctamente.");
                            }
                            else
                            {
                                printf("\nHubo un error en la baja.");
                            }
                            opcionE=5;
                            break;

                        case 4:
                            ordenarEquiposNombreYLocalidad(equipos,TAM,1);
                            printEquipos(equipos,TAM);
                            break;
                        default:
                            printf("\nIngrese una opcion valida.");
                            break;
                    }
                    system("pause");
                    system("cls");
                }while (opcionE!=5);
            }
            else
            {
              printf("Hubo un error.");
            }
            break;

        default:
            printf("\nIngrese una opcion valida.");
            break;
        }
        system("pause");
        system("cls");
    }while(opcion!=5);

    return 0;
}

//FUNCIONES

//0-MENUES

void printMenuPrincipal()
{
    printf("-----BIENVENIDO SELECCIONE UNA OPCION POR FAVOR-----");
    printf("\n1-Equipos");
    printf("\n2-Jugadores");
    printf("\n3-Referis");
    printf("\n4-Partido");
    printf("\n5-Salir");
}

void printMenuE()
{
    printf("---EQUIPOS---");
    printf("\n1-Dar de alta");
    printf("\n2-Modificar");
    printf("\n3-Dar de Baja");
    printf("\n4-Listar");
    printf("\n5-Salir");
}

void printMenuJ()
{
    printf("---JUGADORES---");
    printf("\n1-Dar de alta");
    printf("\n2-Dar de Baja");
    printf("\n3-Listar");
    printf("\n4-Salir");
}

void printMenuR()
{
    printf("---REFERI---");
    printf("\n1-Dar de alta");
    printf("\n2-Salir");
}

void printMenuP()
{
    printf("---JUGADORES---");
    printf("\n1-Dar de alta");
    printf("\n2-Listar");
    printf("\n3-Salir");
}

void printMenuModificacion()
{
    printf("---¿Que desea modificar?---");
    printf("\n1-Nombre");
    printf("\n2-Localidad");
    printf("\n3-Salir");
}

//1-INICIALIZACION Y BUSQUEDA

int inicializarEquipos(eEquipo* equipos,int len)
{
    int i;
    int retorno=-1;

    for (i=0;i<len;i++)
    {
        if (i>=0 && equipos[i] != NULL)
        {
            equipos[i].isEmpty=LIBRE;
            retorno=0;
        }
    }

    return retorno;
}

//inicializar jugadores/referis/partidos

int buscarLibreE(eEquipo* equipos,int len)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(equipos[i].isEmpty==LIBRE)
        {
            retorno=i;
        }
        break;
    }

    return retorno;
}

//buscarLibre de las otras entidades

int buscarEquipoPorId (eEquipo* equipos,int len,int codigo)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(equipos[i].codigo==codigo)
        {
            retorno=i;
        }
        break;
    }

    return retorno;
}

//2-ALTAS

int altaEquipo(eEquipo* equipos, int len,int codigo)
{
    int i;
    int retorno=-1;
    char auxNombre[52];
    char auxLocalidad[34];

    i=buscarLibreE(equipos,len);

    if (i>=0)
    {
        auxNombre=getString("\nIngrese el nombre del equipo: ");

        while(isOnlyLetters(auxNombre)==0)
        {
            auxNombre=getString("\nERROR, POR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre del equipo nuevamente: ");
        }

        strcpy(equipos[i].nombre,auxNombre);

        auxLocalidad=getString("\nIngrese la localidad del equipo: ");

        while(isOnlyLetters(auxLocalidad)==0)
        {
            auxLocalidad=getString("\nERROR, POR FAVOR SOLO INGRESE LETRAS\nIngrese la localidad del equipo nuevamente: ");
        }

        strcpy(equipos[i].localidad,auxLocalidad);

        equipos[i].isEmpty=OCUPADO;
        retorno=0;
    }
    return retorno;
}

//3-BAJAS

int bajaEquipo(eEquipo* equipos, int len,int codigo)
{
    int i;
    char respuesta;
    int retorno=-2;

    //-2 ERROR -1 USER CANCELO 0 TODO OK

    //printEquipos

    i=buscarEquipoPorId(equipos,len,codigo);

    printEquipo(equipos[i]);
    printf("\n¿Desea eliminar el usuario? s/n");
    respuesta=getche();

    while(respuesta!='s' || respuesta!='S' || respuesta!='n' || respuesta!='N')
    {
        printf("\nPOR FAVOR ELIJA SOLO S/N\n ¿Desea eliminar el usuario s/n?");
        respuesta=getche();
    }

    if (respuesta=='s' || respuesta=='S')
    {
        equipos[i].isEmpty==LIBRE;
        retorno=0;
    }
    else if (respuesta=='n' || respuesta=='N')
    {
        retorno=-1;
    }

    return retorno;
}

//4-MODIFICAR

int modificarEquipo(eEquipo* equipos,int tam,int codigo)
{
    int i;
    int opcion;
    char auxNombre [52];
    char auxLocalidad [34];

    if(i>=0 && equipos!=NULL)
    {
        do
        {

            printMenuModificacion()

            opcion=getInt("Ingrese su opcion: ");
            switch(opcion)
            {
            case 1:

                auxNombre=getString("\nIngrese el nombre del equipo: ");

                while(isOnlyLetters(auxNombre)==0)
                {
                    auxNombre=getString("\nERROR, POR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre del equipo nuevamente: ");
                }

                strcpy(equipos[i].nombre,auxNombre);
                opcion=0;
                break;

            case 2:

                auxLocalidad=getString("\nIngrese la localidad del equipo: ");

                while(isOnlyLetters(auxLocalidad)==0)
                {
                    auxLocalidad=getString("\nERROR, POR FAVOR SOLO INGRESE LETRAS\nIngrese la localidad del equipo nuevamente: ");
                }

                strcpy(equipos[i].localidad,auxLocalidad);
                opcion=0;
                break;

            default:
                printf("Ingrese una opcion valida\n");
                break;

                system("pause");
                system("cls");
            }
        }while(opcion!=0);
    }
}

//5-ORDENAR

int ordenarEquiposNombreYLocalidad(eEquipo* equipos, int len, int order)                                                            ///2.5 Función sortEmployees:
{
    int i;
    int j;
    int retorno=-1;
    eEquipo aux[1];

    if(equipos!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(equipos[i].nombre,equipos[j].nombre)>0)
                    {
                        aux[0]=equipos[i];
                        equipos[i]=equipos[j];
                        equipos[j]=aux[0];
                    }
                    if((stricmp(equipos[i].nombre,equipos[j].nombre)==0) && (stricmp(equipos[i].localidad,equipos[j].localidad)>0))
                    {
                        aux[0]=equipos[i];
                        equipos[i]=equipos[j];
                        equipos[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(equipos[i].nombre,equipos[j].nombre)<0)
                    {
                        aux[0]=equipos[i];
                        equipos[i]=equipos[j];
                        equipos[j]=aux[0];
                    }
                    if((stricmp(equipos[i].nombre,equipos[j].nombre)==0) && (stricmp(equipos[i].localidad,equipos[j].localidad)<0))
                    {
                        aux[0]=equipos[i];
                        equipos[i]=equipos[j];
                        equipos[j]=aux[0];
                    }
                    break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

//6-MOSTRAR
void printEquipo(eEquipo equipos)
{
    printf("\n%d -- %10s %15s\n\n", equipos.codigo, equipos.nombre, equipos.localidad);
}

int printEquipos(eEquipo* equipos, int len)
{
    int i;
    printf("Codigo        Nombre          Localidad\n");
    for(i=0; i<len; i++)
    {
        if(equipos[i].isEmpty==NOTFREE)
        {
            printEquipo(equipos[i]);
        }
    }
    return 0;
}


//7-HARDCODEO

void hardcodeoEquipos(eEquipo* equipos, int len) //TERMINADA
{
    int codigo[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[10][52] = {"Boca","Racing","Independiente","River","Racing","Independiente","Independiente","Gimnasia","Gimnasia","San Lorenzo"};
    char localidad[10][34] = {"La Boca","Avellaneda","Avellaneda","Nuniez","Cordoba","Neuquen","Chivilcoy","La Plata","Jujuy","Ni idea?"};

    int i;
    for (i=0; i<len; i++)
    {
        equipos[i].codigo = codigo[i];
        strcpy(equipos[i].nombre, nombre[i]);
        strcpy(equipos[i].localidad, localidad[i]);
        equipos[i].isEmpty = OCUPADO;
    }
}

