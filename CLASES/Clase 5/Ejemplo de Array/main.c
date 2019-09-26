#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 6

void mostrarArray(int miArray[],int cantidad);
int dameMax(int miArray[],int cantidad);
int dameMin(int miArray[],int cantidad);
void inicializarArray(int miArray[],int cantidad);
void cargaSecuencialArray(int miArray[],int cantidad,char mensaje[]);
float darmePromedio (int miArray[],int cantidad);
void ordenarBurbujeo (int miArray[],int cantidad);


int main()
{
    int edad[6];
    inicializarArray(edad,CANTIDAD);
    cargaSecuencialArray(edad,CANTIDAD,"la edad");
    printf("Antes de ordenar:\n");
    mostrarArray(edad,CANTIDAD);
    ordenarBurbujeo (edad,CANTIDAD);
    printf("Despues de ordenar:\n");//Nunca te olvides los if (de menor a mayor i mayor a j
    mostrarArray(edad,CANTIDAD);
    printf("El max es: %d\n",dameMax(edad,CANTIDAD));
    printf("El min es: %d\n",dameMin(edad,CANTIDAD));
    printf("El promedio de edades es de %.2f\n",darmePromedio(edad,CANTIDAD));
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

float darmePromedio (int miArray[],int cantidad)
{
    int i;
    float acumulador=0;

    for (i=0;i<cantidad;i++)
    {
        acumulador = acumulador + miArray[i];
    }

    return acumulador/cantidad;
}

void ordenarBurbujeo (int miArray[],int cantidad)
{
    int i;
    int j;
    int aux;

    for (i=0;i<cantidad-1;i++)
    {
        for (j=i+1;j<cantidad;j++)
        {
            if (miArray [i]>miArray[j])
            {
            aux = miArray[i];
            miArray[i] = miArray[j];
            miArray[j] = aux;
            }
        }
    }
}

