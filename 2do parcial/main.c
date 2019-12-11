#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "inputs.h"
#include "LinkedList.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    eFecha fecha;
    char destino[33];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelos;

///CONSTRUCTOR

eVuelos* new_vuelo();
eVuelos* new_vuelo_parametros(char* idVuelo,char* idAvion,char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);
void delate_vuelo (eVuelos*);
int get_idVuelo(eVuelos*,int*);
int set_idVuelo(eVuelos*,int);
int get_idAvion(eVuelos*,int*);
int set_idAvion(eVuelos*,int);
int get_idPiloto(eVuelos*,int*);
int set_idPiloto(eVuelos*,int);
int get_fecha(eVuelos*,int*,int*,int*);
int set_fecha(eVuelos*,int,int,int);
int get_destino(eVuelos*,char*);
int set_destino(eVuelos*,char*);
int get_cantPasajeros(eVuelos*,int*);
int set_cantPasajeros(eVuelos*,int);
int get_horaDespegue(eVuelos*,int*);
int set_horaDespegue(eVuelos*,int);
int get_horaLlegada(eVuelos*,int*);
int set_horaLlegada(eVuelos*,int);

///PARSEO

int parserTexto(FILE*,LinkedList*);

///CARGAR Y GUARDAR ARCHIVO

int cargarArchivo(char*,LinkedList*);
int guardarArchivoVuelosCortos(char*,LinkedList*);
int guardarArchivoPortugal(char*,LinkedList*);
int guardarArchivoSinAlex(char*, LinkedList*);

///PRINT

void printVuelos(LinkedList*);
void printCantidadPasajeros(LinkedList*);
void printCantidadPasajerosChina(LinkedList*);

int main()
{
    eVuelos* vuelos;
    LinkedList* lista;

    lista=ll_newLinkedList();

    int opcion;
    char archivo[30];
    int flagTexto=0;
    int retorno;

    do
    {
        printf("MENU:\n");
        printf("1- Cargar archivo.\n");
        printf("2- Imprimir vuelos.\n");
        printf("3- Cantidad de pasajeros.\n");
        printf("4- Cantidad de pasajeros a China.\n");
        printf("5- Filtrar vuelos cortos.\n");
        printf("6- Listar vuelos a Portugal.\n");
        printf("7- Filtrar a Alex Lifeson.\n");
        printf("8- Salir!.\n");
        printf("\nSu opcion: ");
        scanf("%d", &opcion);

        while (opcion>8)
        {
            printf("Opcion invalida\n");
            printf("\nSu opcion: ");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:
            if(flagTexto == 0)
            {
                getString("Ingrese el nombre del archivo (.csv): ",archivo);
                if(cargarArchivo(archivo,lista) == 1)
                {
                    printf("\nSe cargo el archivo.\n\n");
                }
                else
                {
                    printf("\nNo se cargo el archivo.\n\n");
                }
            flagTexto=1;
            }
            else if(flagTexto == 1)
            {
                printf("El archivo ya se cargo.\n");
            }

            system("pause");
            system("cls");

            break;

        case 2:
            printVuelos(lista);
            system("pause");
            system("cls");
            break;

        case 3:
            printCantidadPasajeros(lista);
            break;

        case 4:
            printCantidadPasajerosChina(lista);
            break;

        case 5:
            getString("Ingrese el nombre del archivo (.csv): ",archivo);
            guardarArchivoVuelosCortos(archivo,lista);
            break;

        case 6:
            getString("Ingrese el nombre del archivo (.csv): ",archivo);
            guardarArchivoPortugal(archivo,lista);
            break;

        case 7:
            getString("Ingrese el nombre del archivo (.csv): ",archivo);
            guardarArchivoSinAlex(archivo,lista);
            break;

        case 8:
            printf("\nSaliendoooo...");
            break;

        default:
            printf("Opcion invalida.\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion != 8);

    return 0;
}

eVuelos* new_vuelo()
{
    eVuelos* vuelos;
    vuelos = (eVuelos*)malloc(sizeof(eVuelos));

    if (vuelos!=NULL)
    {
        set_idVuelo(vuelos,0);
        set_idAvion(vuelos,0);
        set_idPiloto(vuelos,0);
        set_fecha(vuelos,0,0,0);
        set_destino(vuelos,"");
        set_cantPasajeros(vuelos,0);
        set_horaDespegue(vuelos,0);
        set_horaLlegada(vuelos,0);
    }

    return vuelos;
}

eVuelos* new_vuelo_parametros(char* idVuelo,char* idAvion,char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
    char dia[10];
    char mes[10];
    char anio[10];

    int i;

    int idVueloAux;
    int idAvionAux;
    int idPilotoAux;
    int diaAux;
    int mesAux;
    int anioAux;
    int cantPasajerosAux;
    int horaDespegueAux;
    int horaLlegadaAux;

    eVuelos* vuelos;
    vuelos=new_vuelo();

    idVueloAux=atoi(idVuelo);
    idAvionAux=atoi(idAvion);
    idPilotoAux=atoi(idPiloto);

    for(i=0;i<3;i++)///DÍA
    {
        if(fecha[1]!='/')
        {
            dia[0]=fecha[0];
            dia[1]=fecha[1];
            break;
        }
        else
        {
            dia[0]=fecha[0];
        }
    }

    for(i=2;i<10;i++)///MES Y ANIO
    {
        if(fecha[2]!='/' && fecha[3]!= '/')
        {
            mes[0]=fecha[2];
            mes[1]=fecha[3];
            anio[0]=fecha[5];
            anio[1]=fecha[6];
            anio[2]=fecha[7];
            anio[3]=fecha[8];
            break;
        }

        if(fecha[3]!='/' && fecha[4]!= '/')
        {
            mes[0]=fecha[3];
            mes[1]=fecha[4];
            anio[0]=fecha[6];
            anio[1]=fecha[7];
            anio[2]=fecha[8];
            anio[3]=fecha[9];
            break;
        }

        if(fecha[2]!='/' && fecha[3]=='/')
        {
            mes[0]=fecha[2];
            anio[0]=fecha[4];
            anio[1]=fecha[5];
            anio[2]=fecha[6];
            anio[3]=fecha[7];
        }

        if(fecha[3]!='/' && fecha[4]=='/')
        {
            mes[0]=fecha[3];
            anio[0]=fecha[5];
            anio[1]=fecha[6];
            anio[2]=fecha[7];
            anio[3]=fecha[8];
        }


    }

    diaAux=atoi(dia);
    mesAux=atoi(mes);
    anioAux=atoi(anio);

    cantPasajerosAux=atoi(cantPasajeros);
    horaDespegueAux=atoi(horaDespegue);
    horaLlegadaAux=atoi(horaLlegada);

    if(vuelos!=NULL && idVuelo!=NULL && idAvion!=NULL && idPiloto!=NULL && fecha!=NULL && destino!=NULL && cantPasajeros!=NULL && horaDespegue!=NULL && horaLlegada!=NULL)
    {
        set_idVuelo(vuelos,idVueloAux);
        set_idAvion(vuelos,idAvionAux);
        set_idPiloto(vuelos,idPilotoAux);
        set_fecha(vuelos,diaAux,mesAux,anioAux);
        set_destino(vuelos,destino);
        set_cantPasajeros(vuelos,cantPasajerosAux);
        set_horaDespegue(vuelos,horaDespegueAux);
        set_horaLlegada(vuelos,horaLlegadaAux);
    }
    return vuelos;
}

void delate_vuelo (eVuelos* vuelos)
{
    if (vuelos!=NULL)
    {
        free(vuelos);
    }
}

int get_idVuelo(eVuelos* vuelos,int* idVuelo)
{
    int ret=0;
    if(vuelos!=NULL && *idVuelo!=NULL)
    {
        *idVuelo=vuelos->idVuelo;
        ret=1;
    }
    return ret;
}

int set_idVuelo(eVuelos* vuelos,int idVuelo)
{
    int ret=0;
    if (vuelos!=NULL)
    {
        if(idVuelo>-1)
        {
            vuelos->idVuelo=idVuelo;
            ret=1;
        }
    }
    return ret;
}

int get_idPiloto(eVuelos* vuelos,int* idPiloto)
{
    int ret=0;
    if(vuelos!=NULL && *idPiloto!=NULL)
    {
        *idPiloto=vuelos->idPiloto;
        ret=1;
    }
    return ret;
}

int set_idPiloto(eVuelos* vuelos,int idPiloto)
{
    int ret=0;
    if (vuelos!=NULL)
    {
        if(idPiloto>-1)
        {
            vuelos->idPiloto=idPiloto;
            ret=1;
        }
    }
    return ret;
}

int get_idAvion(eVuelos* vuelos,int* idAvion)
{
    int ret=0;
    if(vuelos!=NULL && *idAvion!=NULL)
    {
        *idAvion=vuelos->idAvion;
        ret=1;
    }
    return ret;
}

int set_idAvion(eVuelos* vuelos,int idAvion)
{
    int ret=0;
    if (vuelos!=NULL)
    {
        if(idAvion>-1)
        {
            vuelos->idAvion=idAvion;
            ret=1;
        }
    }
    return ret;
}

int get_fecha(eVuelos* vuelos,int* dia,int* mes,int* anio)
{
    int ret=0;
    if(vuelos!=NULL && *dia!=NULL && *mes!=NULL && *anio!=NULL)
    {
        *dia=vuelos->fecha.dia;
        *mes=vuelos->fecha.mes;
        *anio=vuelos->fecha.anio;
        ret=1;
    }
    return ret;
}

int set_fecha(eVuelos* vuelos,int dia,int mes,int anio)
{
    int ret=0;
    if (vuelos!=NULL)
    {
            vuelos->fecha.dia=dia;
            vuelos->fecha.mes=mes;
            vuelos->fecha.anio=anio;
            ret=1;
    }
    return ret;
}

int set_destino(eVuelos* vuelos,char* destino)
{
    int ret=0;

    if(vuelos!=NULL && destino!=NULL)
    {
        strcpy(vuelos->destino,destino);
        ret=1;
    }
    return ret;
}

int get_destino(eVuelos* vuelos,char* destino)
{
    int ret=0;

    if(vuelos!=NULL && destino!=NULL)
    {
        strcpy(destino,vuelos->destino);
        ret=1;
    }
    return ret;
}

int get_cantPasajeros(eVuelos* vuelos,int* cantPasajeros)
{
    int ret=0;
    if(vuelos!=NULL && *cantPasajeros!=NULL)
    {
        *cantPasajeros=vuelos->cantPasajeros;
        ret=1;
    }
    return ret;
}

int set_cantPasajeros(eVuelos* vuelos,int cantPasajeros)
{
    int ret=0;
    if (vuelos!=NULL)
    {
        if(cantPasajeros>-1)
        {
            vuelos->cantPasajeros=cantPasajeros;
            ret=1;
        }
    }
    return ret;
}

int get_horaDespegue(eVuelos* vuelos,int* horaDespegue)
{
    int ret=0;
    if(vuelos!=NULL && *horaDespegue!=NULL)
    {
        *horaDespegue=vuelos->horaDespegue;
        ret=1;
    }
    return ret;
}

int set_horaDespegue(eVuelos* vuelos,int horaDespegue)
{
    int ret=0;
    if (vuelos!=NULL)
    {
        if(horaDespegue>-1)
        {
            vuelos->horaDespegue=horaDespegue;
            ret=1;
        }
    }
    return ret;
}

int get_horaLlegada(eVuelos* vuelos,int* horaLlegada)
{
    int ret=0;
    if(vuelos!=NULL && *horaLlegada!=NULL)
    {
        *horaLlegada=vuelos->horaLlegada;
        ret=1;
    }
    return ret;
}

int set_horaLlegada(eVuelos* vuelos,int horaLlegada)
{
    int ret=0;
    if (vuelos!=NULL)
    {
        if(horaLlegada>-1)
        {
            vuelos->horaLlegada=horaLlegada;
            ret=1;
        }
    }
    return ret;
}


int parserTexto(FILE* pArchivo,LinkedList* lista)
{
    int ret = 0;
    char buffer[8][30];
    int cant;

    eVuelos* vuelos=NULL;

    if(pArchivo != NULL && lista != NULL)
    {

        cant = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7]);
        printf("%s,%s,%s,%s,%s,%s,%s,%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4], buffer[5], buffer[6], buffer[7]);

        while(!feof(pArchivo))
        {
            cant = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7]);
            printf("%s,%s,%s,%s,%s,%s,%s,%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4], buffer[5], buffer[6], buffer[7]);


            if(cant == 8)
            {
                vuelos = new_vuelo_parametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4], buffer[5], buffer[6], buffer[7]);

                if(vuelos != NULL)
                {

                    ll_add(lista,vuelos);
                    ret = 1;
                }
            }
            else
            {
                if(feof(pArchivo))
                {
                    break;
                }
                else
                {
                    ret = 0;
                    break;
                }
            }
        }
    }
    return ret;
}

int guardarArchivoVuelosCortos(char* path, LinkedList* lista)
{
    FILE* pArchivo;
    eVuelos* vuelos;
    int horasAux;

    int ret = 0;
    int i;

    if(lista != NULL && path != NULL)
    {
        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada\n");

        for(i=0; i< ll_len(lista); i++)
        {
            vuelos = ll_get(lista,i);
            horasAux=(vuelos->horaLlegada) - (vuelos->horaDespegue);
            if(horasAux<3)
            {
                fprintf(pArchivo,"%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n",vuelos->idVuelo,vuelos->idAvion,vuelos->idPiloto,vuelos->fecha.dia,vuelos->fecha.mes,vuelos->fecha.anio,vuelos->destino,vuelos->cantPasajeros,vuelos->horaDespegue,vuelos->horaLlegada);
            }
        }
        fclose(pArchivo);
        ret = 1;
    }
    return ret;
}

int guardarArchivoPortugal(char* path, LinkedList* lista)
{
    FILE* pArchivo;
    eVuelos* vuelos;
    char portugal[9]={"Portugal"};

    int ret = 0;
    int i;

    if(lista != NULL && path != NULL)
    {
        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada\n");

        for(i=0; i< ll_len(lista); i++)
        {
            vuelos = ll_get(lista,i);

            if(strcmp(portugal,vuelos->destino)==0)
            {
                fprintf(pArchivo,"%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n",vuelos->idVuelo,vuelos->idAvion,vuelos->idPiloto,vuelos->fecha.dia,vuelos->fecha.mes,vuelos->fecha.anio,vuelos->destino,vuelos->cantPasajeros,vuelos->horaDespegue,vuelos->horaLlegada);
            }
        }
        fclose(pArchivo);
        ret = 1;
    }
    return ret;
}

int guardarArchivoSinAlex(char* path, LinkedList* lista)
{
    FILE* pArchivo;
    eVuelos* vuelos;
    int idAlex=1;

    int ret = 0;
    int i;

    if(lista != NULL && path != NULL)
    {
        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada\n");

        for(i=0; i< ll_len(lista); i++)
        {
            vuelos = ll_get(lista,i);
            if(idAlex!=vuelos->idPiloto)
            {
                fprintf(pArchivo,"%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n",vuelos->idVuelo,vuelos->idAvion,vuelos->idPiloto,vuelos->fecha.dia,vuelos->fecha.mes,vuelos->fecha.anio,vuelos->destino,vuelos->cantPasajeros,vuelos->horaDespegue,vuelos->horaLlegada);
            }
        }
        fclose(pArchivo);
        ret = 1;
    }
    return ret;
}

int cargarArchivo(char* path , LinkedList* lista)
{
    FILE* pArchivo = NULL;
    int ret=0;

    if(path != NULL && lista != NULL){
        pArchivo=fopen(path,"r");
        if(pArchivo==NULL)
        {
            ret=0;
        }
        else
        {
          ret = parserTexto(pArchivo, lista);
        }
    }
    fclose(pArchivo);

    return ret;
}

void printVuelos(LinkedList* lista)
{
    int i;
    int numPilotoAux;
    char nombre[31];

    printf("idVuelo, idAvion, Piloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada\n ");

        for(i=0;i<ll_len(lista);i++)
        {
            eVuelos* vuelos=new_vuelo();

            vuelos=ll_get(lista,i);

            numPilotoAux=vuelos->idPiloto;
            switch(numPilotoAux)
            {
                case 1:
                    strcpy(nombre,"Alex Lifeson");
                    break;

                case 2:
                    strcpy(nombre,"Richard Bach");
                    break;

                case 3:
                    strcpy(nombre,"John Kerry");
                    break;

                case 4:
                    strcpy(nombre,"Erwin Rommel");
                    break;

                case 5:
                    strcpy(nombre,"Stephen Coonts");
                    break;

                default:
                    strcpy(nombre,"Error... id de piloto invalido");
                    break;
            }
                printf("%d,%d,%s,%d/%d/%d,%s,%d,%d,%d\n",vuelos->idVuelo,vuelos->idAvion,nombre,vuelos->fecha.dia,vuelos->fecha.mes,vuelos->fecha.anio,vuelos->destino,vuelos->cantPasajeros,vuelos->horaDespegue,vuelos->horaLlegada);
        }
}

void printCantidadPasajeros(LinkedList* lista)
{
    int i;
    int acumulador=0;
    int cantidad;

        for(i=0;i<ll_len(lista);i++)
        {
            eVuelos* vuelos=new_vuelo();

            vuelos=ll_get(lista,i);
            cantidad=vuelos->cantPasajeros;
            acumulador=acumulador+cantidad;
        }

        printf("Hay en total %d de pasajeros",acumulador);
}

void printCantidadPasajerosChina(LinkedList* lista)
{
    int i;
    int acumulador=0;
    int cantidad;
    char china[6]={"China"};

        for(i=0;i<ll_len(lista);i++)
        {
            eVuelos* vuelos=new_vuelo();

            vuelos=ll_get(lista,i);
            if(strcmp(china,vuelos->destino)==0)
            {
                cantidad=vuelos->cantPasajeros;
                acumulador=acumulador+cantidad;
            }
        }

        printf("Hay en total %d de pasajeros que viajaron a China",acumulador);
}
