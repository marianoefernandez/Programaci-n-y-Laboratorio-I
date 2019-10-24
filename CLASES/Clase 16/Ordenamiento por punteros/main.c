#include <stdio.h>
#include <stdlib.h>

void inicializarArray(int*,int);
void ordenarNumeroDeOrden(int*,int);
void swap(int*,int*);
void mostrarNumeros(int*,int);

int main()
{
    int numeroOrden[50];
    int i=0;
    char continuar;

    inicializarArray(numeroOrden,50);

    do
    {
        if(i>=0 && i<50) //&& (numeroOrden[i]!=NULL))
    {
        printf("\n\nIngrese un numero de orden: ");
        scanf("%d", numeroOrden[i]);
        i++;
    }
    else
    {
        printf("\nNo hay mas espacio");
        system("pause");
        continuar='n';
    }

    printf("\n¿Desea continuar s/n?:");
    continuar=getche();

    }while(continuar=='s');


    ordenarNumeroDeOrden(numeroOrden,50);
    mostrarNumeros(numeroOrden,50);

    return 0;
}

void inicializarArray(int* array,int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        *(array+i)=-1;
    }
}

void ordenarNumeroDeOrden(int* array,int tam)
{
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(*(array+i)>*(array+j))
            {
                int a;
                swap(array+i,&array+j);
            }
        }
    }
}

void swap(int* a, int* b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void mostrarNumeros(int* array,int tam)
{
   int i;
    for (i=0;i<tam;i++)
    {
        if (*(array+i)!=-1)
        {
            printf("\nEl numero de orden es %d: ",*(array+i));
        }
    }
}


