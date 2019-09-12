#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 8
#define TAMALUMNOS 4

//CARGA EL ARRAY CON DATOS
void cargarConDatosEnteros(int [],int);
//CARGA ARRAY CON NOMBRES
void cargarNombres(char [][50],int);
//MAX Y MIN
int maxArray (int [],int);
int minArray (int [],int);
int indiceMax (int [],int);
int indiceMin (int [],int);
void nombreMax (char [][],int iMax,char[])
void nombreMax (char [][],int iMax,char[])

//CARGAR SOLO LETRAS




int main()
{
    int edades [TAM];
    int notas [TAMALUMNOS];
    char nombres [TAM] [50];
    int i;
    int iMax;

   /* for (i=0;i<3;i++)
    {
        printf("\nIngrese su edad: ");
        scanf("%d", &edades[i]);
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        gets(nombres[i]);
    }

    */
    /*cargarConDatosEnteros(edades,TAM);
    cargarNombres(nombres,TAM);
    */

    cargarConDatosEnteros(notas,TAMALUMNOS);
    cargarNombres(nombres,TAMALUMNOS);
    iMax=indiceMax(notas[i],TAMALUMNOS);

    /*max=notas[0];

    for (i=0;i<TAMALUMNOS;i++)
    {
        if (max<notas[i])
        {
            iMax=i;
        }
    }
    printf("\nLa nota mas alta es la de: %s", nombres[iMax]);
    */

    /*
    for (i=0;i<TAM;i++)
    {
        printf("\nSu edad es: %d anios y su nombre es %s ", edades[i], nombres[i]);
    }
    */

    return 0;
}

void cargarConDatosEnteros(int miArray [],int cantidad)
{
    int aux[]={4,10,8,2};
    int i;
    for (i=0;i<cantidad;i++)
    {
        miArray[i]=aux[i];
    }
}

void cargarNombres(char miArray [][50],int cantidad)
{
    char aux[][50]={"Alfredo","Rogelio","Julieta","Pablo"};
    int i;
    for (i=0;i<cantidad;i++)
    {
        strcpy(miArray[i],aux[i]);
    }
}

int maxArray (int mIArray[],int cantidad)
{
    int i;
    int max;
    for (i=0;i<cantidad;i++)
    {
        if (i==0||mIArray>max)
        {
            max=mIArray[i];
        }
    }
    return max;
}

int minArray (int mIArray[],int cantidad)
{
    int i;
    int min;
    for (i=0;i<cantidad;i++)
    {
        if (i==0||mIArray<min)
        {
            min=mIArray[i];
        }
    }
    return min;
}

int indiceMax (int miArray[],int cantidad) //SOLO GUARDA UN SOLO MAXIMO
{
    int i;
    int iMax;
    int max;
    max = maxArray(miArray,cantidad);

    for (i=0;i<cantidad;i++)
    {
       if(miArray[i]==max)
        iMax =i;
    }
    return iMax;
}

int indiceMin (int miArray[],int cantidad) //SOLO GUARDA UN SOLO MINIMO
{
    int i;
    int iMin;
    int min;
    min = minArray(miArray,cantidad);

    for (i=0;i<cantidad;i++)
    {
       if(miArray[i]==min)
        iMin =i;
    }
    return iMin;
}

void nombreMax (char miArray [][],int iMax,char mensaje[])
{
    printf("%s %s",mensaje[],miArray[iMax]);
}

void nombreMax (char miArray [][],int iMin,char mensaje[])
{
    printf("%s %s",mensaje[],miArray[iMin]);
}
