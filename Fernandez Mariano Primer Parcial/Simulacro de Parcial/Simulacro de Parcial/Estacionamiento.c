#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estacionamiento.h"
#include "inputs.h"



//0-MENUES (4 de 4)
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
    printf("\n-----QUE DESEA INFORMAR-----\n\n");
    printf("1-Todos los propietarios ordenados por nombre y anio de nacimiento.\n");
    printf("2-Todos los vehiculos ordenados por duenio y patente.\n");
    printf("3-Cada auto con el nombre del duenio.\n");
    printf("4-Por cada duenio, los autos que tiene estacionados.\n");
    printf("5-Ingresar el duenio y mostrar todos sus autos.\n");
    printf("6-Mostrar el total de la estadia de cada auto sabiendo que el valor por hora es $100.\n");
    printf("7-Mostrar cuanto tiene que pagar cada duenio por todos sus autos estacionados.\n");
    printf("8-Mostrar el o los duenios con los autos mas estacionados.\n");
}

//1-INICIALIZAR Y BUSCAR (5 de 5)
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
            listaV[i].estaEstacionado=FREE;
            listaV[i].horaSalida=-1;
        }
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}

void EstadiaCadaAuto(eVehiculo* listaV,int *estadias,int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        if (listaV[i].estaEstacionado==NOTFREE)
        {
            estadias[i]=(listaV[i].horaSalida-listaV[i].horaEntrada);
        }
    }
}

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


//2-ALTAS(3 de 3)

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

//3-MODIFICACION (1 de 1)
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


//4-BAJA LÓGICA (1 de 1)

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

//5-ORDENAMIENTO (2 de 2)

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

int ordenarPropietariosDuenioPatente(eVehiculo* listaV, ePropietario* listaP, int len, int order)
{
    int i;
    int j;
    int retorno=-1;
    eVehiculo auxV[1];
    ePropietario auxP[1];

    if(listaV!=NULL||len<0||order<0||order>1)
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
                        auxP[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=auxP[0];

                    }
                    if((stricmp(listaP[i].nombre,listaP[j].nombre)==0) && stricmp(listaV[i].patente,listaV[j].patente)>0)
                    {
                        auxV[0]=listaV[i];
                        listaV[i]=listaV[j];
                        listaV[j]=auxV[0];

                        auxP[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=auxP[0];
                    }
                    break;
                case 1:
                    if (stricmp(listaP[i].nombre,listaP[j].nombre)<0)
                    {
                        auxP[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=auxP[0];

                    }
                    if((stricmp(listaP[i].nombre,listaP[j].nombre)==0) && stricmp(listaV[i].patente,listaV[j].patente)<0)
                    {
                        auxV[0]=listaV[i];
                        listaV[i]=listaV[j];
                        listaV[j]=auxV[0];

                        auxP[0]=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=auxP[0];
                    }
                    break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
//6-MOSTRAR (5 de 5)
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
    int index;
    int auxId;
    printf("ID        Nombre          Patente       Fecha de ingreso        Hora de entrada         Hora de salida\n");
    for(i=0; i<len; i++)
    {
        if (listaV[i].estaEstacionado==NOTFREE)
        {
            auxId=listaV[i].idPropietario;
            index=buscarPropietarioPorId(listaP,len,auxId);

            printf("\n%d -- %10s %15s %10d/%d/%d %16d hs %20d hs\n\n", listaV[i].idPropietario, listaP[index].nombre, listaV[i].patente, listaV[i].fechaIngreso.dia, listaV[i].fechaIngreso.mes, listaV[i].fechaIngreso.anio, listaV[i].horaEntrada,listaV[i].horaSalida);

        }
    }
    return 0;
}

int printAutosConDuenios(ePropietario* listaP,eVehiculo* listaV ,int len)
{
    int i;
    int index;
    int auxId;
    printf("\n---CADA AUTO CON SU DUENIO---\n\n");
    for(i=0; i<len; i++)
    {
        if (listaV[i].estaEstacionado==NOTFREE)
        {
            auxId=listaV[i].idPropietario;
            index=buscarPropietarioPorId(listaP,len,auxId);

            printf("\n-El vehiculo con la patente %s pertenece a %s\n", listaV[i].patente, listaP[index].nombre);

        }
    }
    return 0;
}

int PrintEstadiaPorAuto(ePropietario* listaP,eVehiculo* listaV ,int len)
{
    int i;
    int index;
    int auxId;
    int estadias[len];
    int valor[len];

    EstadiaCadaAuto(listaV,estadias,len);


    printf("\n---CADA AUTO CON SU DUENIO---\n\n");
    for(i=0; i<len; i++)
    {
        if (listaV[i].estaEstacionado==NOTFREE)
        {
            valor[i]=estadias[i]*100;
            printf("\n-El vehiculo con la patente %s estuvo %d hora/s y por ende tiene que abonar %d $\n", listaV[i].patente,estadias[i],valor[i]);

        }
    }
    return 0;
}

int printAutoDeDuenio(ePropietario* listaP,eVehiculo* listaV ,int len,int id)
{
    int i;
    int index;

    index=buscarPropietarioPorId(listaP,len,id);
    printf("\nLos autos de %s son: ",listaP[index].nombre);

    for (i=0;i<len;i++)
    {
        if (id==listaV[i].idPropietario && listaV[i].estaEstacionado==NOTFREE)
        {
            printf("\n%s",listaV[i].patente);
        }
    }
    printf("\n");
    return 0;
}

void mostrarTarifaPorDuenio (ePropietario* listaP,eVehiculo* listaV,int len)
{
    int i;
    int j;
    int total[len];
    for(i=0;i<len;i++)
    {
        total[i]=0;
        if(listaP[i].isEmpty==NOTFREE)
        {
            for(j=0;j<len;j++)
        {
            if((listaP[i].idPropietario==listaV[j].idPropietario)&&(listaV[i].estaEstacionado==NOTFREE))
            {
                total[i]+=calcularTarifaAuto(listaV,len,j);
            }
        }
        printf("\n%s debe en total %d$ por todos sus vehiculos.\n",listaP[i].nombre,total[i]);
        total[i]=0;
        }
    }
    return 0;
}

int printAutoCadaDuenio(ePropietario* listaP,eVehiculo* listaV,int len)
{
    int i;
    int j;
    for(i=0;i<len;i++)
    {
        if(listaP[i].isEmpty==NOTFREE)
        {
           printf("Los autos de %s son: \n",listaP[i].nombre);
        }
            for(j=0;j<len;j++)
        {
            if((listaP[i].idPropietario==listaV[j].idPropietario)&&(listaV[j].estaEstacionado==NOTFREE))
            {
                printf("%s\n",listaV[j].patente);
            }
        }
    }
    return 0;
}

int printDuenioMasAutos(ePropietario* listaP,eVehiculo* listaV,int len)
{
    int i;
    int j;
    int contador[len];
    int max;
    int index;

    max = contador[0];

    for(i=0;i<len;i++)
    {
        contador[i]=0;
        for(j=0;j<len;j++)
        {
            if((listaP[i].idPropietario==listaV[j].idPropietario)&&(listaV[j].estaEstacionado==NOTFREE))
            {
                contador[i]++;
            }
        }

        if (listaP[i].isEmpty==NOTFREE)
        {
            if (contador[i]>max)
            {
                max=contador[i];
                index=i;
            }
        }
    }

    printf("\nEl propietario con mayor cantidad de autos es %s con %d autos",listaP[index].nombre,max);

    return 0;
}
//7-HARDCODEO (2 de 2)

void hardcodeoPropietarios(ePropietario* listaP, int cantidad) //TERMINADA
{
    int id[7] = {1,2,3,4,5,6,7};
    char nombre[7][31] = {"Juliana","Victoria","Gabriel","Damaris","Tomas","Luana","Julian"};
    int anio[7] = {2005,2005,2003,2001,2000,2001,2000};
    int mes[7] = {2,1,8,4,8,1,12};
    int dia[7] = {28,29,5,24,10,27,26};
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
    int id[11]={1,6,6,7,5,4,4,3,3,4,4};
    char patente[11][15]={"AAA111", "BBB222", "AAA222","WWW777","AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128","HGV093"};
    int horaIngreso[11]={10,9,8,11,10,11,9,7,7,14,19};
    int horaSalida[11]={11,11,11,12,14,15,12,10,11,17,23};
    int dia[11]={26,26,26,26,26,26,26,26,26,26,26};
    int mes[11]={9,9,9,9,9,9,9,9,9,9,9};
    int anio[11]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};
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
        listaV[i].estaEstacionado = NOTFREE;
    }
}

//8-EXTRAS

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

 int calcularTarifaAuto(eVehiculo* listaV,int len,int index)
{
    int tarifa;
    tarifa=(listaV[index].horaSalida-listaV[index].horaEntrada)*100;
    return tarifa;
}

