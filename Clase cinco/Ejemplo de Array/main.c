#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 3

void mostrarArray(int miArray[],int cantidad);
int dameMax(int miArray[],int cantidad);
int dameMin(int miArray[],int cantidad);
void inicializarArray(int miArray[],int cantidad);
void cargaSecuencialArray(int miArray[],int cantidad,char mensaje[]);

int main()
{
    int edad[10];
    inicializarArray(edad,CANTIDAD);
    cargaSecuencialArray(edad,CANTIDAD,"la edad");
    mostrarArray(edad,CANTIDAD);
    printf("El max es: %d\n",dameMax(edad,CANTIDAD));
    printf("El min es: %d\n",dameMin(edad,CANTIDAD));
}

void mostrarArray(int miArray[],int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("%d\n",miArray[i]);
    }
}

int dameMax(int miArray[],int cantidad)
{
    int i;
    int max;
    for (i=0;i<cantidad;i++)
    {
        if (miArray[i]>max||i==0)
        {
            max = miArray[i];
        }
    }
    return max;
}

int dameMin(int miArray[],int cantidad)
{
    int i;
    int min;
    for (i=0;i<cantidad;i++)
    {
        if (miArray[i]<min||i==0)
        {
            min = miArray[i];
        }
    }
    return min;
}

void inicializarArray(int miArray[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        miArray[i]=0;
    }
}

void cargaSecuencialArray(int miArray[],int cantidad,char mensaje[])
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("Ingrese %s: ",mensaje);
        scanf("%d",&miArray[i]);
    }
}



