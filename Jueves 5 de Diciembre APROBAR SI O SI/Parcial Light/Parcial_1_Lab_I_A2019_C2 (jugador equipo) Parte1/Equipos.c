#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "inputs.h"
#include "Equipos.h"

//0-MENU
void mostrarMenuE()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Dar de baja\n");
    printf("3-Listar ordenado por nombre y localidad\n");
    printf("4-Salir\n");
}

void printModificationMenuE()
{
    printf("-----ELIJA QUE MODIFICAR-----\n\n");
    printf("1-Nombre\n");
    printf("2-Localidad\n");
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


//2-ALTAS/BAJAS/MODIFICACION

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
        equipos[i].isEmpty=NOTFREE;
        equipos[i].codigo=codigo;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

int modificarEquipo(eEquipo* equipos,int len)
{
    int id;
    int index;
    int opcion;
    int sector;
    char auxNombre[52];
    char auxLocalidad[34];
    char auxId[10];
    int retorno;

    if(len >0 && equipos!= NULL)
    {
        retorno=0;

        printEquipos(equipos, len);

        getString("\nIngrese codigo del equipo: ",auxId);

        while(isNumeric(auxId)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO NUMEROS\nIngrese codigo nuevamente: ",auxId);
        }
        id=atoi(auxId);

        index=buscarEquipoPorCodigo(equipos, len, id);

        if(index>=0)
        {

    printModificationMenuE();

    opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            getString("\nIngrese un nuevo nombre de equipo: ",auxNombre);
            while(isOnlyLetters(auxNombre)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo nombre: ",auxNombre);
            }
            stringToUpper(auxNombre);
            strcpy(equipos[index].nombre, auxNombre);
            break;

        case 2:
            getString("\nIngrese una nuava localidad: ",auxLocalidad);
            while(isOnlyLetters(auxLocalidad)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente una nueva localidad: ",auxLocalidad);
            }
            stringToUpper(auxLocalidad);
            strcpy(equipos[index].localidad, auxLocalidad);
            break;

        case 3:
            retorno=-2;//-2 PARA SALIR
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

//PUSE LA FUNCION ACA ASI ME DEJA USAR LA ESTRUCTURA EQUIPO Y PODER MOSTRARLOS ANTES DE MODIFICAR EQUIPO
int modificarJugadores(eJugadores* jugadores,eEquipo* equipos,int len)
{
    int id;
    int i;
    int index;
    int opcion;
    int sector;
    char auxNombre[32];
    char auxApellido[32];
    char auxId[10];
    char auxIdE[10];
    char auxSexo;
    char auxFecha[12];
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    char respuesta;
    int idE;
    int dia;
    int mes;
    int anio;
    int retorno;

    if(len >0 && jugadores!= NULL)
    {
        retorno=0;

        printJugadores(equipos,jugadores,len);

        getString("\nIngrese el codigo del jugador: ",auxId);

        while(isNumeric(auxId)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO NUMEROS\nIngrese codigo nuevamente: ",auxId);
        }
        id=atoi(auxId);

        index=buscarJugadorPorCodigo(jugadores, len, id);

        if(index>=0)
        {

        printModificationMenuJ();

        opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            getString("\nIngrese un nuevo nombre para el jugador: ",auxNombre);
            while(isOnlyLetters(auxNombre)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente el nuevo nombre: ",auxNombre);
            }
            stringToUpper(auxNombre);
            strcpy(jugadores[index].nombre, auxNombre);
            break;

        case 2:
            getString("\nIngrese un nuevo apellido para el jugador: ",auxApellido);
            while(isOnlyLetters(auxApellido)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente el nuevo apellido: ",auxApellido);
            }
            stringToUpper(auxApellido);
            strcpy(jugadores[index].apellido, auxApellido);
            break;

        case 3:
            printJugadores(equipos,jugadores,len);

            getString("\nIngrese un nuevo codigo de equipo para el jugador: ",auxIdE);
            while(isNumeric(auxIdE)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS \nIngrese nuevamente el id del equipo: ",auxIdE);
            }
            idE=atoi(auxIdE);
            jugadores[index].codigoE=idE;
            break;

        case 4:
            printf("\nDesea cambiar el sexo por el sexo opuesto? s/n");
            fflush(stdin);
            respuesta=getche();
            respuesta=tolower(respuesta);
            while(respuesta!='s' && respuesta!='n')
            {
                printf("\nPOR FAVOR, SOLO INGRESE s/n");
                fflush(stdin);
                respuesta=getche();
                respuesta=tolower(respuesta);
            }
            if(respuesta=='s')
            {
                if(jugadores[index].sexo == 'M')
                {
                    jugadores[index].sexo = 'F';
                }
                else
                {
                    jugadores[index].sexo = 'M';
                }
            }
            else
            {
                retorno=-3;//SE CANCELO LA ACCION
            }
            break;

        case 5:
        getString("\nIngrese la nueva fecha de nacimiento: ",auxFecha);//Pido
        //VALIDACION
        while(isADate(auxFecha) == 0)
        {
            getString("\nPOR FAVOR INGRESE UNA FECHA VALIDA \nIngrese la fecha nuevamente: ",auxFecha);//Valido
        }


        //VALIDACION YA QUE EN FUNCION DA ERROR

    for(i=0;i<3;i++)///DÍA
    {
        if(auxFecha[1]!='/')
        {
            diaAux[0]=auxFecha[0];
            diaAux[1]=auxFecha[1];
            break;
        }
        else
        {
            diaAux[0]=auxFecha[0];
        }
    }

    for(i=2;i<10;i++)///MES Y ANIO
    {
        if(auxFecha[2]!='/' && auxFecha[3]!= '/')
        {
            mesAux[0]=auxFecha[2];
            mesAux[1]=auxFecha[3];
            anioAux[0]=auxFecha[5];
            anioAux[1]=auxFecha[6];
            anioAux[2]=auxFecha[7];
            anioAux[3]=auxFecha[8];
            break;
        }

        if(auxFecha[3]!='/' && auxFecha[4]!= '/')
        {
            mesAux[0]=auxFecha[3];
            mesAux[1]=auxFecha[4];
            anioAux[0]=auxFecha[6];
            anioAux[1]=auxFecha[7];
            anioAux[2]=auxFecha[8];
            anioAux[3]=auxFecha[9];
            break;
        }

        if(auxFecha[2]!='/' && auxFecha[3]=='/')
        {
            mesAux[0]=auxFecha[2];
            anioAux[0]=auxFecha[4];
            anioAux[1]=auxFecha[5];
            anioAux[2]=auxFecha[6];
            anioAux[3]=auxFecha[7];
        }

        if(auxFecha[3]!='/' && auxFecha[4]=='/')
        {
            mesAux[0]=auxFecha[3];
            anioAux[0]=auxFecha[5];
            anioAux[1]=auxFecha[6];
            anioAux[2]=auxFecha[7];
            anioAux[3]=auxFecha[8];
        }


    }

        dia=atoi(diaAux);
        mes=atoi(mesAux);
        anio=atoi(anioAux);

        //FIN
        if(dia>31 || dia<=0 && mes>12 || mes<=0 && anio>2050 || anio<=1950)
        {
            printf("\nLA FECHA NO ES VALIDA");
            return -4;
        }
        else
        {
            jugadores[i].fechaNac.dia=dia;
            jugadores[i].fechaNac.mes=mes;
            jugadores[i].fechaNac.anio=anio;
        }
            break;

        case 6:
            retorno=-2;//-2 PARA SALIR
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

int modificarPartidos(ePartido* partidos,eReferi* referis,eEquipo* equipos,int len)
{
    int id;
    int i;
    int index;
    int opcion;
    char auxId[10];
    char auxIdLoc[10];
    char auxIdVis[10];
    char auxIdR[10];
    char auxFecha[12];
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    char respuesta;
    int idLoc;
    int idVis;
    int idR;
    int dia;
    int mes;
    int anio;
    int retorno;

    if(len >0 && partidos!= NULL)
    {
        retorno=0;

        printPartidos(equipos,referis,partidos,len);
        getString("\nIngrese el codigo del partido: ",auxId);

        while(isNumeric(auxId)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO NUMEROS\nIngrese codigo nuevamente: ",auxId);
        }
        id=atoi(auxId);

        index=buscarPartidoPorCodigo(partidos, len, id);

        if(index>=0)
        {

        printModificationMenuP();

        opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            printEquipo(equipos[index]);
            getString("\nIngrese el codigo de un nuevo equipo local: ",auxIdLoc);
            while(isNumeric(auxIdLoc)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS \nIngrese el codigo nuevamente: ",auxIdLoc);
            }
            idLoc=atoi(auxIdLoc);
            break;

        case 2:
            printEquipo(equipos[index]);
            getString("\nIngrese el codigo de un nuevo equipo visitante: ",auxIdVis);
            while(isNumeric(auxIdVis)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS \nIngrese el codigo nuevamente: ",auxIdVis);
            }
            idVis=atoi(auxIdVis);
            break;

        case 3:
            printReferi(referis,len);
            getString("\nIngrese el codigo de un nuevo referi: ",auxIdR);
            while(isNumeric(auxIdR)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO NUMEROS \nIngrese el codigo nuevamente: ",auxIdR);
            }
            idR=atoi(auxIdR);
            break;

        case 4:
        getString("\nIngrese la nueva fecha del encuentro: ",auxFecha);//Pido
        //VALIDACION
        while(isADate(auxFecha) == 0)
        {
            getString("\nPOR FAVOR INGRESE UNA FECHA VALIDA \nIngrese la fecha nuevamente: ",auxFecha);//Valido
        }


        //VALIDACION YA QUE EN FUNCION DA ERROR

    for(i=0;i<3;i++)///DÍA
    {
        if(auxFecha[1]!='/')
        {
            diaAux[0]=auxFecha[0];
            diaAux[1]=auxFecha[1];
            break;
        }
        else
        {
            diaAux[0]=auxFecha[0];
        }
    }

    for(i=2;i<10;i++)///MES Y ANIO
    {
        if(auxFecha[2]!='/' && auxFecha[3]!= '/')
        {
            mesAux[0]=auxFecha[2];
            mesAux[1]=auxFecha[3];
            anioAux[0]=auxFecha[5];
            anioAux[1]=auxFecha[6];
            anioAux[2]=auxFecha[7];
            anioAux[3]=auxFecha[8];
            break;
        }

        if(auxFecha[3]!='/' && auxFecha[4]!= '/')
        {
            mesAux[0]=auxFecha[3];
            mesAux[1]=auxFecha[4];
            anioAux[0]=auxFecha[6];
            anioAux[1]=auxFecha[7];
            anioAux[2]=auxFecha[8];
            anioAux[3]=auxFecha[9];
            break;
        }

        if(auxFecha[2]!='/' && auxFecha[3]=='/')
        {
            mesAux[0]=auxFecha[2];
            anioAux[0]=auxFecha[4];
            anioAux[1]=auxFecha[5];
            anioAux[2]=auxFecha[6];
            anioAux[3]=auxFecha[7];
        }

        if(auxFecha[3]!='/' && auxFecha[4]=='/')
        {
            mesAux[0]=auxFecha[3];
            anioAux[0]=auxFecha[5];
            anioAux[1]=auxFecha[6];
            anioAux[2]=auxFecha[7];
            anioAux[3]=auxFecha[8];
        }


    }

        dia=atoi(diaAux);
        mes=atoi(mesAux);
        anio=atoi(anioAux);

        //FIN
        if(dia>31 || dia<=0 && mes>12 || mes<=0 && anio>2050 || anio<=1950)
        {
            printf("\nLA FECHA NO ES VALIDA");
            return -4;
        }
        else
        {
            partidos[i].fechaP.dia=dia;
            partidos[i].fechaP.mes=mes;
            partidos[i].fechaP.anio=anio;
        }
            break;

        case 5:
            retorno=-2;//-2 PARA SALIR
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

int bajaEquipo(eEquipo* equipos, int len, int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (equipos!=NULL && len>0)
    {
        printEquipos(equipos,len);

        index = buscarEquipoPorCodigo(equipos,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL EQUIPO A LIBRE
        {

            if (equipos[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\n\nDar de baja a:");
                printEquipo(equipos[index]);
                printf("\n\nEsta seguro de eliminar el dato s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                equipos[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (equipos[index].isEmpty==FREE)
                {
                    retorno=2;//EL DATO YA SE ELIMINO
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

//LA HAGO EN EQUIPOS YA QUE SI NO HAY CONFLICTO ENTRE BIBLIOTECAS
int bajaJugadores(eJugadores* jugadores,eEquipo* equipos,int len,int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (jugadores!=NULL && len>0)
    {
        printJugadores(equipos,jugadores,len);

        index = buscarJugadorPorCodigo(jugadores,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL EQUIPO A LIBRE
        {

            if (jugadores[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\n\nDar de baja a:");
                printf("\n%s %s",jugadores[index].nombre,jugadores[index].apellido);
                printf("\n\nEsta seguro de eliminar el dato s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                jugadores[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (jugadores[index].isEmpty==FREE)
                {
                    retorno=2;//EL DATO YA SE ELIMINO
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

int bajaPartidos(eReferi* partido,eEquipo* equipos,eReferi* referis,int len,int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (partido!=NULL && len>0)
    {

        printPartidos(equipos,referis,partido,len);
        index = buscarPartidoPorCodigo(partido,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL EQUIPO A LIBRE
        {

            if (partido[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\nEsta seguro de eliminar el partido s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                partido[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (partido[index].isEmpty==FREE)
                {
                    retorno=2;//EL DATO YA SE ELIMINO
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
    int retorno=0;

    printf("Codigo        Nombre          Localidad\n");
    for(i=0; i<len; i++)
    {
        if(equipos[i].isEmpty==NOTFREE)
        {
            printEquipo(equipos[i]);
            retorno=1;
        }
    }
    return retorno;
}

int printJugadores(eEquipo* equipos,eJugadores* jugadores, int len)
{
    int i;
    int retorno=0;
    int index;
    int auxCodigo;
    char sexo[20];

    printf("Codigo       Nombre          Apellido        Sexo          Fecha de Nacimiento          Equipo\n");
    for(i=0; i<len; i++)
    {
        if(jugadores[i].isEmpty==NOTFREE)
        {
            if(jugadores[i].sexo=='M')
            {
                strcpy(sexo,"Masculino");
            }
            else
            {
                strcpy(sexo,"Femenino");
            }

            auxCodigo=jugadores[i].codigoE;
            index=buscarEquipoPorCodigo(equipos,len,auxCodigo);
            printf("%d-- %10s %7s %5s %7d/%d/%d %12s\n",jugadores[i].codigo,jugadores[i].nombre,jugadores[i].apellido,sexo,jugadores[i].fechaNac.dia,jugadores[i].fechaNac.mes,jugadores[i].fechaNac.anio,equipos[index].nombre);
            retorno=1;
        }
    }
    return retorno;
}

int printPartidos(eEquipo* equipo,eReferi* referi,ePartido* partidos,int len)
{
    int i;
    int retorno=0;
    int indexL;
    int indexV;
    int indexR;
    int auxCodigoL;
    int auxCodigoV;
    int auxCodigoR;

    printf("Codigo       Equipo Local          Equipo Visitante        Referi          Fecha del encuentro\n");
    for(i=0; i<len; i++)
    {
        if(partidos[i].isEmpty==NOTFREE)
        {
            auxCodigoL=partidos[i].codigoLocal;
            auxCodigoV=partidos[i].codigoVis;
            auxCodigoR=partidos[i].codigoReferi;
            indexL=buscarEquipoPorCodigo(equipo,len,auxCodigoL);
            indexV=buscarEquipoPorCodigo(equipo,len,auxCodigoV);
            indexR=buscarReferiPorCodigo(referi,len,auxCodigoR);
            printf("%d-- %10s %7s %5s  %s %7d/%d/%d\n",partidos[i].codigo,equipo[indexL].nombre,equipo[indexV].nombre,referi[indexR].nombre,referi[indexR].apellido,partidos[i].fechaP.dia,partidos[i].fechaP.mes,partidos[i].fechaP.anio);
            retorno=1;
        }
    }
    return retorno;
}


//5-EXTRAS

int cantidadEquiposOcupados(eEquipo* equipos, int len)
{
    int i;
    int cantidadEquipos=0;
    for (i=0;i<len;i++)
    {
        if (equipos[i].isEmpty == NOTFREE)
        {
            cantidadEquipos++;
            //break;//SI DEVUELVE -1 NO HAY ESPACIO
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

//6-LISTAR

int printJugadoresPorEquipo(eEquipo* equipos,eJugadores* jugadores,int len)
{
    int i;
    int j;
    int retorno=0;

    for (i=0;i<len;i++)
    {
        if(equipos[i].isEmpty==NOTFREE)
        {
            printf("%s tiene los siguientes jugadores:\n ",equipos[i].nombre);
            for(j=0;j<len;j++)
            {
                if(jugadores[j].isEmpty==NOTFREE && jugadores[j].codigoE==equipos[i].codigo)
                {
                    printf("%s      %s      \n",jugadores[j].nombre, jugadores[j].apellido);
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}

//6-VALIDACIONES

int referiMasPartidos(eReferi* referis,ePartido* partidos,int len)
{
    int i;
    int j;
    int contador;
    int auxReferi;
    int max=0;
    int retorno=0;

    for(i=0;i<len;i++)
    {
        if(referis[i].isEmpty==NOTFREE)
        {
            contador=0;
            for(j=0;j<len;j++)
            {
                if(partidos[j].codigoReferi==referis[i].codigo)
                {
                    contador++;
                }

                if (j==len-1)
                {
                    auxReferi=contador;

                    if(auxReferi>max)
                    {
                        max=auxReferi;
                    }
                }
            }
        }
    }

    printf("\nEl/Los Referis con mas partidos: \n");

        for(i=0;i<len;i++)
    {
        if(referis[i].isEmpty==NOTFREE)
        {
            contador=0;
            for(j=0;j<len;j++)
            {
                if(partidos[j].codigoReferi==referis[i].codigo)
                {
                    contador++;
                }

                if(contador==max)
                {
                    printf("%s  %s\n",referis[i].nombre,referis[i].apellido);
                    retorno=1;
                    contador=-len;
                }
            }
        }
    }

    return retorno;
}

int listarNombres(eEquipo* equipos,eJugadores* jugadores,int len)
{
    char nombreIngresado[32];
    int retorno=0;//NO ENCONTRO NOMBRE
    int i;
    int index;

    getString("Ingrese el nombre a comparar: ",nombreIngresado);
    stringToUpper(nombreIngresado);

    for(i=0;i<len;i++)
    {
        if(jugadores[i].isEmpty==NOTFREE)
        {
            if(strcmp(nombreIngresado,jugadores[i].nombre)==0)
            {
                index=buscarEquipoPorCodigo(equipos,len,jugadores[i].codigoE);
                printf("\n%s %s juega en el %s",jugadores[i].nombre,jugadores[i].apellido,equipos[index].nombre);
                retorno=1;
            }
        }
    }
    return retorno;
}

int listarEquiposNombreMasLargo(eEquipo* equipos,int len)
{
    int i;
    int maxLen=0;
    int auxlen;
    int retorno=0;

    for(i=0;i<len;i++)
    {
        if(equipos[i].isEmpty==NOTFREE)
        {
            auxlen=strlen(equipos[i].nombre);

            if(auxlen>maxLen)
            {
                maxLen = auxlen;
            }
        }
    }

    printf("El o los equipos con el nombre mas largo\n");

    for(i=0;i<len;i++)
    {
        if(equipos[i].isEmpty==NOTFREE)
        {
            if(strlen(equipos[i].nombre)==maxLen)
            {
                printf("%s\n",equipos[i].nombre);
                retorno=1;
            }
        }
    }
    return retorno;
}

int listarPorFechaPartido(eEquipo* equipos, ePartido* partidos,eReferi* referis, int len)
{
    int i;
    char fecha[12];
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    int dia;
    int mes;
    int anio;
    int indexLoc;
    int indexVis;
    int indexR;
    int flag=0;

        getString("\nIngrese la fecha del partido: ",fecha);//Pido
        //VALIDACION
        while(isADate(fecha) == 0)
        {
            getString("\nPOR FAVOR INGRESE UNA FECHA VALIDA \nIngrese la fecha nuevamente: ",fecha);//Valido
        }
        for(i=0;i<3;i++)///DÍA
    {
        if(fecha[1]!='/')
        {
            diaAux[0]=fecha[0];
            diaAux[1]=fecha[1];
            break;
        }
        else
        {
            diaAux[0]=fecha[0];
        }
    }

    for(i=2;i<10;i++)///MES Y ANIO
    {
        if(fecha[2]!='/' && fecha[3]!= '/')
        {
            mesAux[0]=fecha[2];
            mesAux[1]=fecha[3];
            anioAux[0]=fecha[5];
            anioAux[1]=fecha[6];
            anioAux[2]=fecha[7];
            anioAux[3]=fecha[8];
            break;
        }

        if(fecha[3]!='/' && fecha[4]!= '/')
        {
            mesAux[0]=fecha[3];
            mesAux[1]=fecha[4];
            anioAux[0]=fecha[6];
            anioAux[1]=fecha[7];
            anioAux[2]=fecha[8];
            anioAux[3]=fecha[9];
            break;
        }

        if(fecha[2]!='/' && fecha[3]=='/')
        {
            mesAux[0]=fecha[2];
            anioAux[0]=fecha[4];
            anioAux[1]=fecha[5];
            anioAux[2]=fecha[6];
            anioAux[3]=fecha[7];
        }

        if(fecha[3]!='/' && fecha[4]=='/')
        {
            mesAux[0]=fecha[3];
            anioAux[0]=fecha[5];
            anioAux[1]=fecha[6];
            anioAux[2]=fecha[7];
            anioAux[3]=fecha[8];
        }


    }

        dia=atoi(diaAux);
        mes=atoi(mesAux);
        anio=atoi(anioAux);

        printf("\nEse dia");

        for (i=0;i<len;i++)
        {
            if(partidos[i].isEmpty==NOTFREE)
            {
                if(partidos[i].fechaP.dia == dia && partidos[i].fechaP.mes == mes && partidos[i].fechaP.anio == anio)
                {   if(flag==0)
                    {
                        printf(" jugaron\n\n");
                    }
                    indexLoc=buscarEquipoPorCodigo(equipos,len,partidos[i].codigoLocal);
                    indexVis=buscarEquipoPorCodigo(equipos,len,partidos[i].codigoVis);
                    indexR=buscarReferiPorCodigo(referis,len,partidos[i].codigoReferi);
                    flag=1;
                    printf("%s  vs  %s  y el referi fue  %s %s\n",equipos[indexLoc].nombre,equipos[indexVis].nombre,referis[indexR].nombre,referis[indexR].apellido);
                }
            }
        }

        return flag;
}

int equipoMasJoven(eEquipo* equipos, eJugadores* jugadores,int len)
{
    int i;
    int j;
    int acumulador=0;
    int edadAux;
    int flag=0;
    float minProm=0;
    float auxProm;
    int index;
    int contador=0;

    for(i=0;i<len;i++)
    {
        if(equipos[i].isEmpty==NOTFREE)
        {
            for (j=0;j<len;j++)
            {
                if(jugadores[j].codigoE==equipos[i].codigo && jugadores[j].isEmpty==NOTFREE)
                {
                    edadAux=(2019)-(jugadores[j].fechaNac.anio);
                    acumulador=acumulador+edadAux;
                    contador++;
                }
            }
                if(acumulador!=0 || contador!=0)
                {
                    auxProm=acumulador/(float)contador;

                    if (flag==0)
                    {
                        minProm=auxProm;
                        index=i;
                    }

                    flag=1;

                    if(minProm>auxProm)
                    {
                        minProm=auxProm;
                        index=i;
                    }

                    acumulador=0;
                    contador=0;
                }
        }
    }

    printf("\nEl equipo mas joven es %s y tiene un promedio de edad de %.2f ",equipos[index].nombre,minProm);
    return flag;
}

int printPartidosPorArbitro(ePartido* partidos,eReferi* referis,eEquipo* equipos,int len)
{
    int i;
    int j;
    int indexL;
    int indexV;
    int retorno=0;

    for(i=0;i<len;i++)
    {
        if(referis[i].isEmpty==NOTFREE)
        {
            printf("\n\nLos partidos de %s %s son\n ",referis[i].nombre,referis[i].apellido);
            for(j=0;j<len;j++)
            {
                if(partidos[j].isEmpty==NOTFREE && partidos[j].codigoReferi==referis[i].codigo)
                {
                    indexL=buscarEquipoPorCodigo(equipos,len,partidos[j].codigoLocal);
                    indexV=buscarEquipoPorCodigo(equipos,len,partidos[j].codigoVis);
                    printf("\n%s vs %s que se jugo el %d/%d/%d",equipos[indexL].nombre,equipos[indexV].nombre,partidos[j].fechaP.dia,partidos[j].fechaP.mes,partidos[j].fechaP.anio);
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}

int arbitrosqueEstanMas4Partidos(eReferi* referis,ePartido* partidos,int len)
{
    int i;
    int j;
    int contador;
    int hayCinco=0;//0 para no y 1 para si

    for(i=0;i<len;i++)
    {
        if(referis[i].isEmpty==NOTFREE)
        {
            contador=0;
            for(j=0;j<len;j++)
            {
                if(partidos[j].codigoReferi==referis[i].codigo)
                {
                    contador++;
                }

                if (contador==5)
                {
                    if(hayCinco==0)
                    {
                        printf("\nLos siguientes arbitros estan en mas de 4 partidos:");
                    }
                    hayCinco=1;
                    printf("%s %s",referis[i].nombre,referis[i].apellido);
                    contador=-len;
                    break;
                }
            }
        }
    }

    return hayCinco;
}
