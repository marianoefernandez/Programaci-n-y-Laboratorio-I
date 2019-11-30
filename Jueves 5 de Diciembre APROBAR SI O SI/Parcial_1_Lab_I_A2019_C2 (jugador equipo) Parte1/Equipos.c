#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "Equipos.h"

//0-MENU
void mostrarMenuE()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Listar\n");
    printf("3-Salir\n");
}

//1-INICIALIZAR
int inicializarEquipos(eEquipo* equipos, int len)
{
    int i;
    int retorno=-1;

    if(equipos!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            equipos[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

int getFreeE(eEquipo* equipos,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (equipos[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

int buscarEquipoPorCodigo(eEquipo* equipos, int len, int codigo)
{
    int i;
    int retorno = -1;
    if(equipos!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(equipos[i].codigo==codigo && equipos[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


//2-ALTAS

int agregarEquipo(eEquipo* equipos,int len,int codigo)
{
    int i;
    int retorno= -1;

    i=getFreeE(equipos, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",equipos[i].nombre);//Pido
        //VALIDACION
        while(isOnlyLetters(equipos[i].nombre) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",equipos[i].nombre);//Valido
        }
        stringToUpper(equipos[i].nombre);//Paso primer caracter a Mayuscula

                getString("\nIngrese la localidad: ",equipos[i].localidad);//Pido
        //VALIDACION
        while(isOnlyLetters(equipos[i].localidad) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese la localidad nuevamente: ",equipos[i].localidad);//Valido
        }
        stringToUpper(equipos[i].localidad);//Paso primer caracter a Mayuscula
        equipos[i].isEmpty =NOTFREE;
        equipos[i].codigo =codigo;

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

//4-MOSTRAR

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

int printJugadoresPorEquipo(eEquipo* equipos,eJugadores* jugadores, int len)
{
    int i;
    int index;
    int auxCodigo;

    printf("Codigo       Nombre          Apellido        Sexo          Fecha de Nacimiento          Equipo\n");
    for(i=0; i<len; i++)
    {
        if(jugadores[i].isEmpty==NOTFREE)
        {
            auxCodigo=equipos[i].codigo;
            index=buscarEquipoPorCodigo(jugadores,len,auxCodigo);
            printf("%d-- %10s %7s %5c %7d/%d/%d %12s\n",jugadores[i].codigo,jugadores[i].nombre,jugadores[i].apellido,jugadores[i].sexo,jugadores[i].fechaNac.dia,jugadores[i].fechaNac.mes,jugadores[i].fechaNac.anio,equipos[i].nombre);
        }
    }
    return 0;
}

//5-EXTRAS

int cantidadEquiposOcupados(eEquipo* equipos, int len)
{
    int i;
    int cantidadEquipos;
    for (i=0;i<len;i++)
    {
        if (equipos[i].isEmpty == NOTFREE)
        {
            cantidadEquipos++;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return cantidadEquipos;
}

void hardcodeoEquipos(eEquipo* equipos)
{
    int i;
    char nombre[10][52]={"Independiente","Racing","Boca","River","Barcelona","Real Madrid","Liverpool","Manchester City","PSG","Flamengo"};
    char localidad[10][34]={"Avellaneda","Avellaneda","La Boca","Nuniez","Barcelona","Madrid","Liverpool","Manchester","Paris","Rio de Janeiro"};


    for(i=0;i<10;i++)
    {
        equipos[i].codigo=i+1;
        strcpy(equipos[i].nombre,nombre[i]);
        strcpy(equipos[i].localidad,localidad[i]);
        equipos[i].isEmpty=NOTFREE;
    }
}



