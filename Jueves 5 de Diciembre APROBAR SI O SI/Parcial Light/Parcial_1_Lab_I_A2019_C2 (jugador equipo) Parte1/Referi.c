#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "inputs.h"
#include "Referi.h"


//0-MENU
void mostrarMenuR()
{
    printf("-----Elija una opcion-----\n\n");
    printf("1-Dar de alta\n");
    printf("2-Listar\n");
    printf("3-Salir\n");
}

void printModificationMenuR()
{
    printf("-----ELIJA QUE MODIFICAR-----\n\n");
    printf("1-Nombre\n");
    printf("2-Apellido\n");
    printf("3-Sexo\n");
    printf("4-eMail\n");
    printf("5-Fecha\n");
    printf("6-Salir\n");
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

int buscarReferiPorCodigo(eReferi* referi, int len, int codigo)
{
    int i;
    int retorno = -1;
    if(referi!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(referi[i].codigo==codigo && referi[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


//2-ALTAS/BAJAS/MODIFICACION

int agregarReferis(eReferi* referis,int len,int codigo)
{
    int i;
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    char fechaAux[12];
    char codigoRAux[10];
    char nombreAux[32];
    char apellidoAux[32];
    char emailAux[32];
    char auxSexo;
    int dia;
    int mes;
    int anio;
    int codigoAux;
    int codigoE;
    int retorno= -1;

    i=getFreeR(referis, len);

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

        getString("\nIngrese el eMail: ",emailAux);//Pido
        //VALIDACION
        /*while(//Funcion que valide mail (email) == 0)
        {
            getString("\nPOR FAVOR INGRESE UN EMAIL VALIDO\nIngrese el eMail nuevamente: ",email);//Valido
        }
        */

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
        if(dia>31 || dia<=0 && mes>12 || mes<=0 && anio>2050 || anio<=1900)
        {
            printf("\nLA FECHA NO ES VALIDA");
            return -1;
        }
        else
        {
            referis[i].fechaNac.dia=dia;
            referis[i].fechaNac.mes=mes;
            referis[i].fechaNac.anio=anio;
        }

        strcpy(referis[i].nombre,nombreAux);
        strcpy(referis[i].apellido,apellidoAux);
        referis[i].sexo=auxSexo;
        strcpy(referis[i].eMail,emailAux);
        referis[i].isEmpty=NOTFREE;
        referis[i].codigo=codigo;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}


int modificarReferis(eReferi* referis,int len)
{
    int id;
    int i;
    int index;
    int opcion;
    int sector;
    char auxNombre[32];
    char auxApellido[32];
    char auxEmail[32];
    char auxId[10];
    char auxSexo;
    char auxFecha[12];
    char diaAux[3];
    char mesAux[3];
    char anioAux[5];
    char respuesta;
    int dia;
    int mes;
    int anio;
    int retorno;

    if(len >0 && referis!= NULL)
    {
        retorno=0;

        printReferi(referis,len);

        getString("\nIngrese el codigo del referi: ",auxId);

        while(isNumeric(auxId)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO NUMEROS\nIngrese codigo nuevamente: ",auxId);
        }
        id=atoi(auxId);

        index=buscarReferiPorCodigo(referis, len, id);

        if(index>=0)
        {

        printModificationMenuR();

        opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            getString("\nIngrese un nuevo nombre para el referi: ",auxNombre);
            while(isOnlyLetters(auxNombre)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente el nuevo referi: ",auxNombre);
            }
            stringToUpper(auxNombre);
            strcpy(referis[index].nombre, auxNombre);
            break;

        case 2:
            getString("\nIngrese un nuevo apellido para el referi: ",auxApellido);
            while(isOnlyLetters(auxApellido)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente el nuevo apellido: ",auxApellido);
            }
            stringToUpper(auxApellido);
            strcpy(referis[index].apellido, auxApellido);
            break;

        case 3:
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
                if(referis[index].sexo == 'M')
                {
                    referis[index].sexo = 'F';
                }
                else
                {
                    referis[index].sexo = 'M';
                }
            }
            else
            {
                retorno=-3;//SE CANCELO LA ACCION
            }
            break;

        case 4:
            getString("\nIngrese un nuevo eMail para el referi: ",auxEmail);
            while(isOnlyLetters(auxEmail)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente el nuevo eMail: ",auxEmail);
            }
            strcpy(referis[index].eMail, auxEmail);
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
        if(dia>31 || dia<=0 && mes>12 || mes<=0 && anio>2050 || anio<=1900)
        {
            printf("\nLA FECHA NO ES VALIDA");
            return -4;
        }
        else
        {
            referis[i].fechaNac.dia=dia;
            referis[i].fechaNac.mes=mes;
            referis[i].fechaNac.anio=anio;
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


int bajaReferis(eReferi* referis,int len,int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (referis!=NULL && len>0)
    {
        printReferi(referis,len);

        index = buscarReferiPorCodigo(referis,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL EQUIPO A LIBRE
        {

            if (referis[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\n\nDar de baja a:");
                printf("\n%s %s",referis[index].nombre,referis[index].apellido);
                printf("\n\nEsta seguro de eliminar el dato s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                referis[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (referis[index].isEmpty==FREE)
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

int ordenarReferisNombreyApellido(eReferi* referis, int len, int order)
{
    int i;
    int j;
    int retorno=-1;
    eReferi aux[1];

    if(referis!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(referis[i].apellido,referis[j].apellido)>0)
                    {
                        aux[0]=referis[i];
                        referis[i]=referis[j];
                        referis[j]=aux[0];
                    }
                    if((stricmp(referis[i].apellido,referis[j].apellido)==0) && (stricmp(referis[i].nombre,referis[j].nombre)>0))
                    {
                        aux[0]=referis[i];
                        referis[i]=referis[j];
                        referis[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(referis[i].apellido,referis[j].apellido)<0)
                    {
                        aux[0]=referis[i];
                        referis[i]=referis[j];
                        referis[j]=aux[0];
                    }
                    if((stricmp(referis[i].apellido,referis[j].apellido)==0) && (stricmp(referis[i].nombre,referis[j].nombre)<0))
                    {
                        aux[0]=referis[i];
                        referis[i]=referis[j];
                        referis[j]=aux[0];
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

int printReferi(eReferi* referis,int len)
{
    int i;
    int index;
    char sexo[20];

    printf("Codigo       Nombre          Apellido        Sexo          Fecha de Nacimiento          Email\n");
    for(i=0; i<len; i++)
    {
            if(referis[i].sexo=='M')
            {
                strcpy(sexo,"Masculino");
            }
            else
            {
                strcpy(sexo,"Femenino");
            }

        if(referis[i].isEmpty==NOTFREE)
        {
            printf("%d-- %10s %7s %5s %7d/%d/%d %12s\n",referis[i].codigo,referis[i].nombre,referis[i].apellido,sexo,referis[i].fechaNac.dia,referis[i].fechaNac.mes,referis[i].fechaNac.anio,referis[i].eMail);
        }
    }
    return 0;
}

//5-EXTRAS
void hardcodeoReferis(eReferi* referis)
{
    int i;
    char nombre[4][32]={"Pablo","Nestor","German","Patricia"};
    char apellido[4][32]={"Lunati","Pitana","Delfino","Vazquez"};
    char eMail[4][32]={"pablolunati@gmail.com","pitanaelpirata69@hotmail.com","germandelfino@yahoo.com.ar","patriVazquez69@hotmail.com"};
    int dia[4]={5,17,8,9};
    int mes[4]={6,6,5,11};
    int anio[4]={1967,1975,1989,1969};


    for(i=0;i<4;i++)
    {
        referis[i].codigo=i+1;
        strcpy(referis[i].nombre,nombre[i]);
        strcpy(referis[i].apellido,apellido[i]);
        strcpy(referis[i].eMail,eMail[i]);
        if(i<3)
        {
            referis[i].sexo='M';
        }
        else
        {
            referis[i].sexo='F';
        }
        referis[i].fechaNac.dia=dia[i];
        referis[i].fechaNac.mes=mes[i];
        referis[i].fechaNac.anio=anio[i];
        referis[i].isEmpty=NOTFREE;
    }
}

int cantidadReferisOcupados(eReferi* referis, int len)
{
    int i;
    int cantidadReferis=0;
    for (i=0;i<len;i++)
    {
        if (referis[i].isEmpty == NOTFREE)
        {
            cantidadReferis++;
            //break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return cantidadReferis;
}



