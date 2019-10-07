#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estacionamiento.h"
#include "inputs.h"



//0-MUESTRO MENUES (3 de 3)
void printFirstMenu()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Cargar un propietario: ");
    printf("\n2-Eliminar propietario: ");
    printf("\n3-Modificar datos de propietario: ");
    printf("\n4-Ingresar vehiculo: ");
    printf("\n5-Egresar vehiculo: ");
    printf("\n6-Informar: ");
}

void printSecondMenu()
{
    printf("\n\na)Todas las personas ordenadas por nombre y año de nacimiento: ");
    printf("\n\nb)Todos los vehículos ordenados por dueño y patente: ");
    printf("\n\nc)Cada auto con el nombre de su dueño: ");
    printf("\n\nd)Por cada dueño los autos que tiene estacionados: ");
    printf("\n\ne)Ingresar un dueño y mostrar todos sus autos: ");
    printf("\n\ng)Mostrar cuanto deberá pagar cada dueño por todos sus autos estacionados: ");
    printf("\n\nh)Mostrar el/los dueños con más autos estacionados: ");
}

void printModificationMenu()
{
    printf("-----¿Qué desea modificar?-----\n\n");
    printf("1-Nombre\n");
    printf("2-Fecha de Nacimiento\n");
}

void printInformar()
{
    printf("1-Todos los propietarios ordenados por nombre y anio de nacimiento.\n");
    printf("2-Todos los vehiculos ordenados por duenio y patente.\n");
    printf("3-Cada auto con el nombre del duenio.\n");
    printf("4-Por cada duenio, los autos que tiene estacionados.\n");
    printf("5-Ingresar el duenio y mostrar todos sus autos.\n");
    printf("6-Mostrar el total de la estadia de cada auto sabiendo que el valor por hora es $100.\n");
    printf("7-Mostrar cuanto tiene que pagar cada duenio por todos sus autos estacionados.\n");
    printf("8-Mostrar el o los duenios con los autos mas estacionados.\n");
}

//1-FUNCIONES PARA INICIALIZAR (1 de 1) //LA DEL ID NO SE SI FUNCIONA
int inicializarPropietarios(ePropietario* listaP, int len)
{
    int i;
    int retorno=-1;

    if(listaP!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            listaP[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

int inicializarVehiculos(eVehiculo* listaV, int len)                                                                                             ///2.1 Función initEmployees:
{
    int i;
    int retorno;
    if(listaV!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            vehiculo[i].estaEstacionado=FREE;
            vehiculo[i].horaSalida=-1;
        }
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}

//2-FUNCIONES PARA AÑADIR (2 de 2)

int agregarPropietario(ePropietario* listaP,int len,int id)
{
    int i;
    char diaAux[10];
    char mesAux[10];
    char anioAux[10];
    int dia;
    int mes;
    int anio;
    int retorno= -1;

    i= getFree(listaP, len);

    if(i>=0)
    {
        getString("\nIngrese el nombre: ",listaP[i].nombre);//Pido
        //VALIDACION
        while(isOnlyLetters(listaP[i].nombre) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS\nIngrese el nombre nuevamente: ",listaP[i].nombre);//Valido
        }
        stringToUpper(listaP[i].nombre);//Paso primer caracter a Mayuscula

        getString("\nIngrese el anio de nacimiento: ",anioAux);//Pido
        //VALIDACION
        while(isNumeric(anioAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el anio nuevamente: ",anioAux);//Valido
        }
        anio=atoi(anioAux);//Paso cadena a numero
        listaP[i].fechaNac.anio=anio;


        getString("\nIngrese el mes de nacimiento: ",mesAux);//Pido
        //VALIDACION
        while(isNumeric(mesAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el mes nuevamente: ",mesAux);//Valido
        }
        mes=atoi(mesAux);//Paso cadena a numero
        listaP[i].fechaNac.mes=mes;

        getString("\nIngrese el dia de nacimiento: ",diaAux);//Pido
        //VALIDACION
        while(isNumeric(diaAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el dia nuevamente: ",diaAux);//Valido
        }
        dia=atoi(diaAux);//Paso cadena a numero
        listaP[i].fechaNac.dia=dia;

        listaP[i].isEmpty =NOTFREE;
        listaP[i].idPropietario =id;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

/*
int validarFecha (ePropietario* listaP,eVehiculo* listaV,int orden)//1-año,2-dia,3-mes(Propietario),4-5-6(Vehículo)
{
    int retorno=1;
    int biciesto[30];
    int i;

    for (i=0;i<30;i++)
    {
        if (i=0)
        {
            biciesto [i]=1900;
        }

        if (i>0)
        {
           biciesto[i]=biciesto[i-1] + 4;
        }

        printf("%d\n",biciesto[i]);
    }

    switch(orden)
    {
        case 1:
            if (listaP.fechaNac.anio > 2019 && listaP.fechaNac.anio<1900)
            {
                retorno=0;
            }
            break;

        case 2:
            if (listaP.fechaNac.mes > 12 && listaP.fechaNac.mes<1)
            {
                retorno=0;
            }
            break;

        case 3:
            if (listaP.fechaNac.dia > 2019 && listaP.fechaNac.anio<1900)
            {
                retorno=0;
            }

            if (listaP.fechaNac.dia>30 && listaP.fechaNac.mes == 4 || listaP.fechaNac.mes == 6 || listaP.fechaNac.mes == 9 || listaP.fechaNac.mes == 11)
            {
                retorno=-1;
            }

                if (listaP.fechaNac.dia>28 && listaP.fechaNac.mes == 2)
            {
                retorno=-1;
            }

            for (i=0;i<30;i++)
            {
                if (listaP.fechaNac.anio==biciesto[i] && (listaP.fechaNac.dia>29 && listaP.fechaNac.mes == 2))
                {
                    retorno=-1;
                }
            }
            break;

        case 4:
            if (listaV.fechaIngreso.anio > 2019 && listaV.fechaIngreso.anio<1900)
            {
                retorno=0;
            }
            break;

        case 5:
            if (listaV.fechaIngreso.mes > 12 && listaV.fechaIngreso.mes<1)
            {
                retorno=0;
            }
            break;

        case 6:
            if (listaV.fechaIngreso.dia > 2019 && listaV.fechaIngreso.anio<1900)
            {
                retorno=0;
            }

            if (listaV.fechaIngreso.dia>30 && listaV.fechaIngreso.mes == 4 || listaV.fechaIngreso.mes == 6 || listaV.fechaIngreso.mes == 9 || listaV.fechaIngreso.mes == 11)
            {
                retorno=-1;
            }

            if (listaV.fechaIngreso.dia>28 && listaV.fechaIngreso.mes == 2)
            {
                retorno=-1;
            }

            for (i=0;i<30;i++)
            {
                if (listaV.fechaIngreso.anio==biciesto[i] && (listaV.fechaIngreso.dia>29 && listaV.fechaIngreso.mes == 2))
                {
                    retorno=-1;
                }
            }
            break;

    }

    return retorno;
}
*/

int agregarVehiculo(eVehiculo* listaV,int len)
{
    int i=0;
    char diaAux[11];
    char mesAux[11];
    char anioAux[11];
    char horaAux[11];
    int dia;
    int mes;
    int anio;
    int horaIngreso;
    int id;
    char idAux[31];
    int retorno= -1;

    if(i>=0)
    {
        getString("\nIngrese el id del propietario: ",idAux);//Pido
        //VALIDACION
        while(isNumeric(idAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el id nuevamente: ",idAux);//Valido
        }
        id=atoi(idAux);//Paso cadena a numero
        listaV[i].idPropietario=id;

        getString("\nIngrese la patente: ",listaV[i].patente);//Pido
        //VALIDACION
        while(isAlphaNumeric(listaV[i].patente) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE LETRAS Y NUMEROS\nIngrese el nombre nuevamente: ",listaV[i].patente);//Valido
        }
        stringToUpper(listaV[i].patente);//Paso primer caracter a Mayuscula

        getString("\nIngrese el anio de entrada: ",anioAux);//Pido
        //VALIDACION
        while(isNumeric(anioAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el anio nuevamente: ",anioAux);//Valido
        }
        anio=atoi(anioAux);//Paso cadena a numero
        listaV[i].fechaIngreso.anio=anio;


        getString("\nIngrese el mes de entrada: ",mesAux);//Pido
        //VALIDACION
        while(isNumeric(mesAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el mes nuevamente: ",mesAux);//Valido
        }
        mes=atoi(mesAux);//Paso cadena a numero
        listaV[i].fechaIngreso.mes=mes;

        getString("\nIngrese el dia de entrada: ",diaAux);//Pido
        //VALIDACION
        while(isNumeric(diaAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el dia nuevamente: ",diaAux);//Valido
        }
        dia=atoi(diaAux);//Paso cadena a numero
        listaV[i].fechaIngreso.dia=dia;

        getString("\nIngrese el hora de entrada: ",horaAux);//Pido
        //VALIDACION
        while(isNumeric(horaAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese la hora nuevamente: ",horaAux);//Valido
        }
        horaIngreso=atoi(horaAux);//Paso cadena a numero
        listaV[i].horaEntrada=horaIngreso;

        listaV[i].idPropietario=id;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

int egresarVehiculo(eVehiculo* listaV,int len)
{
    int i=0;
    char auxHora[11];
    int horaSalida;
    int retorno=-1;

    if(i>=0)
    {
        getString("\nIngrese el hora de salida: ",auxHora);//Pido
        //VALIDACION
        while(isNumeric(auxHora) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese la hora nuevamente: ",auxHora);//Valido
        }
        horaSalida=atoi(auxHora);//Paso cadena a numero
        listaV[i].horaSalida=horaSalida;

        retorno =0;

        printf("\nCarga exitosa.\n");//Se pudo cargar el usuario
    }
    else
    {
        printf("\nNo hay espacio disponible.\n");//No hay mas espacio
    }
    return retorno;
}

int getFree(ePropietario* listaP,int len) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<len;i++)
    {
        if (listaP[i].isEmpty == FREE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}


//3-BUSCAR EMPLEADO POR ID (1 de 1)
int buscarPropietarioPorId(ePropietario* listaP, int len, int id)
{
    int i;
    int retorno = -1;
    if(listaP!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(listaP[i].idPropietario==id && listaP[i].isEmpty==NOTFREE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//4-MODIFICACION (1 de 1)
int modificarPropietario(ePropietario* listaP, int len)
{
    int id;
    int index;
    int opcion;
    char auxName[30];
    char diaAux[10];
    char mesAux[10];
    char anioAux[10];
    int dia;
    int mes;
    int anio;
    char auxId[20];
    int retorno;

    if(len >0 && listaP!= NULL)
    {
        retorno=0;

        printPropietarios(listaP, len);

        getString("\nIngrese ID: ",auxId);

        while(isNumeric(auxId)==0)
        {
            getString("\nPOR FAVOR INGRESE SOLO LETRAS\nIngrese ID nuevamente: ",auxId);
        }
        id=atoi(auxId);

        index=buscarPropietarioPorId(listaP, len, id);

        if(index>=0)
        {

    printModificationMenu();

    opcion=getInt("Su opcion: ");

        switch(opcion)
        {
        case 1:
            getString("\nIngrese un nuevo nombre: ",auxName);
            while(isOnlyLetters(auxName)==0)
            {
                getString("\nPOR FAVOR SOLO INGRESE SOLO LETRAS \nIngrese nuevamente un nuevo nombre: ",auxName);
            }
            stringToUpper(auxName);
            strcpy(listaP[index].nombre, auxName);
            break;

        case 2:
	    getString("\nIngrese un nuevo anio de nacimiento: ",anioAux);//Pido
        //VALIDACION
        while(isNumeric(anioAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el anio nuevamente: ",anioAux);//Valido
        }
        anio=atoi(anioAux);//Paso cadena a numero
        listaP[index].fechaNac.anio=anio;


        getString("\nIngrese un nuevo mes de nacimiento: ",mesAux);//Pido
        //VALIDACION
        while(isNumeric(mesAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el mes nuevamente: ",mesAux);//Valido
        }
        mes=atoi(mesAux);//Paso cadena a numero
        listaP[index].fechaNac.mes=mes;

        getString("\nIngrese un nuevo dia de nacimiento: ",diaAux);//Pido
        //VALIDACION
        while(isNumeric(diaAux) == 0)
        {
            getString("\nPOR FAVOR SOLO INGRESE NUMEROS\nIngrese el dia nuevamente: ",diaAux);//Valido
        }
        dia=atoi(diaAux);//Paso cadena a numero
        listaP[index].fechaNac.dia=dia;

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


//5-BAJA LÓGICA (1 de 1) NO SE SI ESTA BIEN

int eliminarPropietario(ePropietario* listaP, int len, int id)
{
    //Hacer baja Lógica
    int retorno =-1;
    int index;
    char respuesta;
    if (listaP!=NULL && len>0)
    {
        printPropietarios(listaP,len);

        index = buscarPropietarioPorId(listaP,len,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL ALUMNO A LIBRE
        {

            if (listaP[index].isEmpty==FREE)
                {

                }
            else
            {
                printf("\n\n\nDar de baja a:");
                printPropietario(listaP[index]);
                printf("\n\nEsta seguro de eliminar el dato s/n: ");
                respuesta = getche();
            }

            if (respuesta=='s')
            {
                listaP[index].isEmpty = FREE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                if (listaP[index].isEmpty==FREE)
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

//6-FUNCIONES DE ORDENAMIENTO (2 de 2) LISTO

int ordenarPropietariosNombreAnio(ePropietario* listaP, int len, int order)                                                            ///2.5 Función sortEmployees:
{
    int i;
    int j;
    int retorno=-1;
    ePropietario aux[1];

    if(listaP!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(listaP[i].nombre,listaP[j].nombre)>0)
                    {
                        aux[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=aux[0];
                    }
                    if((stricmp(listaP[i].nombre,listaP[j].nombre)==0) && (listaP[i].fechaNac.anio>listaP[j].fechaNac.anio))
                    {
                        aux[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(listaP[i].nombre,listaP[j].nombre)<0)
                    {
                        aux[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=aux[0];
                    }
                    if((stricmp(listaP[i].nombre,listaP[j].nombre)==0) && (listaP[i].fechaNac.anio<listaP[j].fechaNac.anio))
                    {
                        aux[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=aux[0];
                    }
                    break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int ordenarPropietariosDuenioPatente(eVehiculo* listaV, int len, int order)
{
    int i;
    int j;
    int retorno=-1;
    eVehiculo aux[1];

    if(listaV!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (listaV[i].idPropietario>listaV[j].idPropietario)
                    {
                        aux[0]=listaV[i];
                        listaV[i]=listaV[j];
                        listaV[j]=aux[0];
                    }
                    if(listaV[i].idPropietario==listaV[j].idPropietario && (stricmp(listaV[i].patente,listaV[j].patente)>0))
                    {
                        aux[0]=listaV[i];
                        listaV[i]=listaV[j];
                        listaV[j]=aux[0];
                    }
                    break;
                case 1:
                    if (listaV[i].idPropietario<listaV[j].idPropietario)
                    {
                        aux[0]=listaV[i];
                        listaV[i]=listaV[j];
                        listaV[j]=aux[0];
                    }
                    if(listaV[i].idPropietario==listaV[j].idPropietario && (stricmp(listaV[i].patente,listaV[j].patente)<0))
                    {
                        aux[0]=listaV[i];
                        listaV[i]=listaV[j];
                        listaV[j]=aux[0];
                    }
                    break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
//7-FUNCIONES PARA MOSTRAR (2 de 2) LISTO
void printPropietario(ePropietario listaP)
{
    printf("\n%d -- %10s %10d/%d/%d\n\n", listaP.idPropietario, listaP.nombre, listaP.fechaNac.dia, listaP.fechaNac.mes, listaP.fechaNac.anio);
}

int printPropietarios(ePropietario* listaP, int len)
{
    int i;
    printf("ID        Nombre          Fecha de nacimiento\n");
    for(i=0; i<len; i++)
    {
        if(listaP[i].isEmpty==NOTFREE)
        {
            printPropietario(listaP[i]);
        }
    }
    return 0;
}

int printVehiculos(ePropietario* listaP,eVehiculo* listaV ,int len)
{
    int i;
    printf("ID        Nombre          Patente       Fecha de ingreso        Hora de entrada         Hora de salida\n");
    for(i=0; i<len; i++)
    {
        if (listaP[i].idPropietario==listaV[i].idPropietario)
        {

            printf("\n%d -- %10s %10s %10d/%d/%d %10d hs %10d hs\n\n", listaV[i].idPropietario, listaP[i].nombre, listaV[i].patente, listaV[i].fechaIngreso.dia, listaV[i].fechaIngreso.mes, listaV[i].fechaIngreso.anio, listaV[i].horaEntrada,listaV[i].horaSalida);

        }
    }
    return 0;
}




//8-FUNCIONES DE HARDCODEO (2 de 2) LISTO

void hardcodeoPropietarios(ePropietario* listaP, int cantidad) //TERMINADA
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[10][31] = {"Juliana","Victoria","Gabriel","Damaris","Tomas","Juliana","Juliana","Juliana","Damaris","Julian"};
    int anio[10] = {2005,2005,2003,2001,2000,1999,2008,1977,2002,2000};
    int mes[10] = {2,1,8,4,8,3,4,5,6,12};
    int dia[10] = {28,29,5,24,10,11,17,18,27,26};
    int i;

    for (i=0; i<cantidad; i++)
    {
        listaP[i].idPropietario = id[i];
        strcpy(listaP[i].nombre, nombre[i]);
        listaP[i].fechaNac.anio = anio[i];
        listaP[i].fechaNac.mes = mes[i];
        listaP[i].fechaNac.dia = dia[i];
        listaP[i].isEmpty = NOTFREE;
    }
}

void hardcodeoVehiculos(eVehiculo* listaV, int cantidad) //TERMINADA
{
    int id[10]={1,6,6,7,5,4,4,3,3,4};
    char patente[10][15]={"AAA111", "BBB222", "AAA222","WWW777","AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int horaIngreso[10]={10,9,8,11,10,11,9,7,7,14};
    int horaSalida[10]={11,11,11,12,14,15,12,10,11,17};
    int dia[10]={26,26,26,26,26,26,26,26,26,26};
    int mes[10]={9,9,9,9,9,9,9,9,9,9};
    int anio[10]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};
    int i;

    for (i=0; i<cantidad; i++)
    {
        listaV[i].idPropietario = id[i];
        strcpy(listaV[i].patente, patente[i]);
        listaV[i].fechaIngreso.anio = anio[i];
        listaV[i].fechaIngreso.mes = mes[i];
        listaV[i].fechaIngreso.dia = dia[i];
        listaV[i].horaEntrada = horaIngreso[i];
        listaV[i].horaSalida = horaSalida[i];
    }
}

/*void hardcodeoPersonas(ePersona* persona, int cantidad) //TERMINADA
{
    int id[4] = {1,2,3,4};
    char nombre[4][31] = {"Maria","Ezequiel","German","Yanina"};
    int anio[4] = {1990,1980,2000,1995};
    int mes[4] = {3,4,12,11};
    int dia[4] = {33,22,25,11};
    int i;

    for (i=0; i<cantidad; i++)
    {
        persona[i].id = id[i];
        strcpy(persona[i].nombre, nombre[i]);
        persona[i].fechaNac.anio = anio[i];
        persona[i].fechaNac.mes = mes[i];
        persona[i].fechaNac.dia = dia[i];
    }
}

void hardcodeoVehiculos(eVehiculo* vehiculo, int cantidad) //TERMINADA
{
    int id[4] = {1,2,2,4};
    char patente[4][31] = {"AAA111","BBB222","AA111BB","DJ222BB"};
    int anio[4] = {2019,2019,2019,2019};
    int mes[4] = {9,9,9,9};
    int dia[4] = {26,26,26,26};
    int horaIngreso[4] = {10,9,8,11};
    int horaSalida[4] = {11,11,11,12};
    int i;

    for (i=0; i<cantidad; i++)
    {
        vehiculo[i].idDuenio = id[i];
        strcpy(vehiculo[i].patente, patente[i]);
        vehiculo[i].fechaIngreso.anio = anio[i];
        vehiculo[i].fechaIngreso.mes = mes[i];
        vehiculo[i].fechaIngreso.dia = dia[i];
        vehiculo[i].horaIngreso = horaIngreso[i];
        vehiculo[i].horaSalida = horaSalida[i];
    }
}
void hardcoded(Employee* list, int len) //TERMINADA
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char name[10][51] = {"Jorge","Mauro","Diego","Daniela","Juliana","Victoria","Carmen","Tomas","Damaris","Julian"};
    char lastName[10][51] = {"Rios","Zarate","Perez","Gonzalez","Lopez","Rodriguez","Fernandez","Fidalgo","Tevez","Riquelme"};
    float salary[10] = {2850,4425,3250,5785,6900,3450,777,2320,1400,11450};
    int sector[10] = {8,33,11,11,8,8,7,7,33,13};

    int i;
    for (i=0; i<len; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = NOTFREE;
    }
}

 //9-CALCULAR PROMEDIOS Y OTROS DATOS (4 de 4)

 float totalSalary(Employee* list,int len)
 {
     float sumaSalarios=0;
     int i;

     for(i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
             sumaSalarios = sumaSalarios + list[i].salary;
         }
     }
     return sumaSalarios;
 }

 float salaryAverage(Employee* list,int len,float allSalary)
 {
     int cantidadCargados=0;
     float average;
     int i;

     for(i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
             cantidadCargados++;
         }
     }
     average=allSalary/cantidadCargados;
     return average;
 }

 int betterThanAverage(Employee* list,int len,float averageSalary)
 {
     int betterSalaryAverage=0;
     float auxSalary;
     int i;

     for (i=0;i<len;i++)
     {
         if(list[i].isEmpty==NOTFREE)
         {
            auxSalary=list[i].salary;
            if(auxSalary>averageSalary)
            {
               betterSalaryAverage++;
            }
         }
     }

     return betterSalaryAverage;
 }
 */

 int propietariosOcupados(ePropietario* listaP,int len)
 {
     int i;
     int propietariosOcupados=0;

     for(i=0;i<len;i++)
     {
         if(listaP[i].isEmpty==NOTFREE)
         {
             propietariosOcupados++;
         }
     }

     return propietariosOcupados;
 }

