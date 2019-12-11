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
    int idLlamada;
    eFecha fecha;
    int numCliente;
    int idProblema;
    char solucionado[3];
}eLlamada;

///CONSTRUCTOR

eLlamada* new_llamada();
eLlamada* new_llamada_parametros(char* id,char* fecha,char* numCliente, char* idProblema, char* solucion);
void delate_llamada (eLlamada*);
int get_id(eLlamada*,int*);
int set_id(eLlamada*,int);
int get_fecha(eLlamada*,int*,int*,int*);
int set_fecha(eLlamada*,int,int,int);
int get_numCliente(eLlamada*,int*);
int set_numCliente(eLlamada*,int);
int get_idProblema(eLlamada*,int*);
int set_idProblema(eLlamada*,int);
int setSolucion(eLlamada*,char*);
int getSolucion(eLlamada*,char*);

///PARSEO

int parserTexto(FILE*,LinkedList*);

///CARGAR Y GUARDAR ARCHIVO

int cargarArchivo(char*,LinkedList*);
int guardarArchivo(char*,LinkedList*,int);

///PRINT

void printLlamadas(LinkedList*);

int main()
{
    eLlamada* llamada;
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
        printf("2- Imprimir Llamadas.\n");
        printf("3- Generar archivo de llamadas.\n");
        printf("4- Salir!.\n");
        printf("\nSu opcion: ");
        scanf("%d", &opcion);

        while (opcion>4)
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
            printLlamadas(lista);
            system("pause");
            system("cls");
            break;

        case 3:
            getString("Ingrese el nombre del archivo (.csv) al que vas a guardar el archivo: ",archivo);
            retorno=guardarArchivo(archivo,lista,getInt("Ingrese el num del problema: "));

            switch(retorno)
            {
                case -1:
                    printf("\nIngreso un numero incorrecto, solo ingrese del 1 al 5");
                    break;

                case 0:
                    printf("\nError al guardar el archivo");
                    break;

                case 1:
                    printf("\nSe guardo con exito");
                    break;
            }

            system("pause");
            system("cls");

            break;

        case 4:
            printf("\nSaliendoooo...");
            break;

        default:
            printf("Opcion invalida.\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion != 4);

    return 0;
}

eLlamada* new_llamada()
{
    eLlamada* llamada;
    llamada = (eLlamada*)malloc(sizeof(eLlamada));

    if (llamada!=NULL)
    {
        set_id(llamada,0);
        set_fecha(llamada,0,0,0);
        set_numCliente(llamada,0);
        set_idProblema(llamada,0);
        setSolucion(llamada,"");
    }

    return llamada;
}

eLlamada* new_llamada_parametros(char* id,char* fecha,char* numCliente, char* idProblema, char* solucion)
{
    char dia[10];
    char mes[10];
    char anio[10];

    int i;

    int idAux;
    int diaAux;
    int mesAux;
    int anioAux;
    int idProblemaAux;
    int numClienteAux;

    eLlamada* llamada;
    llamada=new_llamada();

    idAux=atoi(id);

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

    idProblemaAux=atoi(idProblema);
    numClienteAux=atoi(numCliente);

    if(llamada!=NULL && id!=NULL && fecha!=NULL && numCliente!=NULL && idProblema!=NULL && solucion!=NULL)
    {
        set_id(llamada,idAux);
        set_fecha(llamada,diaAux,mesAux,anioAux);
        set_idProblema(llamada,idProblemaAux);
        set_numCliente(llamada,numClienteAux);
        setSolucion(llamada,solucion);
    }
    return llamada;
}

void delate_llamada (eLlamada* llamada)
{
    if (llamada!=NULL)
    {
        free(llamada);
    }
}

int get_id(eLlamada* llamada,int* id)
{
    int ret=0;
    if(llamada!=NULL && *id!=NULL)
    {
        *id=llamada->idLlamada;
        ret=1;
    }
    return ret;
}

int set_id(eLlamada* llamada,int id)
{
    int ret=0;
    if (llamada!=NULL)
    {
        if(id>-1)
        {
            llamada->idLlamada=id;
            ret=1;
        }
    }
    return ret;
}

int get_fecha(eLlamada* llamada,int* dia,int* mes,int* anio)
{
    int ret=0;
    if(llamada!=NULL && *dia!=NULL && *mes!=NULL && *anio!=NULL)
    {
        *dia=llamada->fecha.dia;
        *mes=llamada->fecha.mes;
        *anio=llamada->fecha.anio;
        ret=1;
    }
    return ret;
}

int set_fecha(eLlamada* llamada,int dia,int mes,int anio)
{
    int ret=0;
    if (llamada!=NULL)
    {
            llamada->fecha.dia=dia;
            llamada->fecha.mes=mes;
            llamada->fecha.anio=anio;
            ret=1;
    }
    return ret;
}

int get_numCliente(eLlamada* llamada,int* numCliente)
{
    int ret=0;
    if(llamada!=NULL && *numCliente!=NULL)
    {
        *numCliente=llamada->numCliente;
        ret=1;
    }
    return ret;
}

int set_numCliente(eLlamada* llamada,int numCliente)
{
    int ret=0;
    if (llamada!=NULL)
    {
        if(numCliente>-1)
        {
            llamada->numCliente=numCliente;
            ret=1;
        }
    }
    return ret;
}

int get_idProblema(eLlamada* llamada,int* idProblema)
{
    int ret=0;
    if(llamada!=NULL && *idProblema!=NULL)
    {
        *idProblema=llamada->idProblema;
        ret=1;
    }
    return ret;
}

int set_idProblema(eLlamada* llamada,int idProblema)
{
    int ret=0;
    if (llamada!=NULL)
    {
        if(idProblema>-1)
        {
            llamada->idProblema=idProblema;
            ret=1;
        }
    }
    return ret;
}

int setSolucion(eLlamada* llamada,char* solucion)
{
    int ret=0;

    if(llamada!=NULL && solucion!=NULL)
    {
        strcpy(llamada->solucionado,solucion);
        ret=1;
    }
    return ret;
}

int getSolucion(eLlamada* llamada,char* solucion)
{
    int ret=0;

    if(llamada!=NULL && solucion!=NULL)
    {
        strcpy(solucion,llamada->solucionado);
        ret=1;
    }
    return ret;
}

int parserTexto(FILE* pArchivo,LinkedList* lista)
{
    int ret = 0;
    char buffer[5][30];
    int cant;

    eLlamada* llamadas=NULL;

    if(pArchivo != NULL && lista != NULL)
    {

        cant = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        printf("%s,%s,%s,%s,%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

        while(!feof(pArchivo))
        {
            cant = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            printf("%s,%s,%s,%s,%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(cant == 5)
            {
                llamadas = new_llamada_parametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

                if(llamadas != NULL)
                {

                    ll_add(lista,llamadas);
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

int guardarArchivo(char* path, LinkedList* lista,int numProblema)
{
    FILE* pArchivo;
    eLlamada* llamada;

    if(numProblema<=0 && numProblema>=6)
    {
        return -1;//POR FAVOR INGRESE UN PROBLEMA VALIDO DEL 1 AL 5
    }

    int ret = 0;
    int i;

    if(lista != NULL && path != NULL)
    {
        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"ID_Llamada,Fecha,Numero_Cliente,ID_Problema,Solucionado\n");

        for(i=0; i< ll_len(lista); i++)
        {
            llamada = ll_get(lista,i);
            if(numProblema==llamada->idProblema)
            {
                fprintf(pArchivo,"%d,%d/%d/%d,%d,%d,%s\n",llamada->idLlamada,llamada->fecha.dia,llamada->fecha.mes,llamada->fecha.anio,llamada->numCliente,llamada->idProblema,llamada->solucionado);
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

void printLlamadas(LinkedList* lista)
{
    int i;
    int numProblemaAux;
    char problema[31];

    printf("ID_Llamada, Fecha, Numero_Cliente, Problema, Solucionado\n ");

        for(i=0;i<ll_len(lista);i++)
        {
            eLlamada* llamada=new_llamada();

            llamada=ll_get(lista,i);

            numProblemaAux=llamada->idProblema;
            switch(numProblemaAux)
            {
                case 1:
                    strcpy(problema,"No enciende PC");
                    break;

                case 2:
                    strcpy(problema,"No funciona mouse");
                    break;

                case 3:
                    strcpy(problema,"No funciona teclado");
                    break;

                case 4:
                    strcpy(problema,"No hay internet");
                    break;

                case 5:
                    strcpy(problema,"No funciona telefono");
                    break;

                default:
                    strcpy(problema,"Error... num de problema invalido");
                    break;
            }
            printf("%d,%d/%d/%d,%d,%s,%s\n",llamada->idLlamada,llamada->fecha.dia,llamada->fecha.mes,llamada->fecha.anio,llamada->numCliente,problema,llamada->solucionado);
        }
}
