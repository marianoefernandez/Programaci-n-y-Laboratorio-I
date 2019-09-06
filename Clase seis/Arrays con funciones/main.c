#include <stdio.h>
#include <stdlib.h>
#define T 5

//int const T = 10;


void cargarVector(int[], int);
void mostrarVector(int[], int);
void mostrarNegativos(int[],int);
void mostrarPromedio(int[],int);
int contarPositivos(int [],int );
int sumarPositivos(int[],int);
float calcularPromedio(int,int);

int main()
{
    int vectorDeNumeros[T]={10,-5,5,-6,-1,-4,10,5,4,-1};
    int i;
    int contadorDePositivos = 0;
    int sumaDePositivos = 0;
    float promedioPositivos;
    int maximo;
    int minimo;

    cargarVector(vectorDeNumeros, T);
    mostrarVector(vectorDeNumeros,T);
    mostrarNegativos(vectorDeNumeros,T);
    mostrarPromedio(vectorDeNumeros,T);

   /*printf("MAXIMO: %d -- MINIMO: %d", maximo, minimo);*/


    return 0;
}


void cargarVector(int miVector[], int tam)
{
    int i;
      printf("\tCARGA DE DATOS\n");
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &miVector[i]);
    }
}

void mostrarVector(int miVector[], int tam)
{
    int i;
    printf("\tMUESTRO EL VECTOR\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\n", miVector[i]);
    }
}

void mostrarNegativos(int miVector[],int tam)
{
    int i;
    printf("\n\n\tMUESTRO SOLO LOS NEGATIVOS\n");
    for(i=0; i<tam; i++)
    {
        if(miVector[i]<0)
        {
           printf("%d\n", miVector[i]);
        }

    }
}

void mostrarPromedio(int miVector[],int tam)
{
    int i;
    int contadorDePositivos = 0;
    int sumaDePositivos;
    float promedioPositivos;

   sumaDePositivos = sumarPositivos(miVector, tam);
   contadorDePositivos = contarPositivos(miVector,tam);

   promedioPositivos =calcularPromedio(sumaDePositivos,contadorDePositivos);

   //printf("Suma: %d -- Cantidad %d\n\n", sumaDePositivos, contadorDePositivos);


     printf("\n\n\PROMEDIO DE POSITIVOS: %f\n\n", promedioPositivos);

}

int sumarPositivos(int miVector[],int tam)
{
    int suma = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(miVector[i]>0)
        {
            suma += miVector[i];
        }
    }

    return suma;
}

int contarPositivos(int miVector[],int tam)
{
    int contador = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(miVector[i]>0)
        {
            contador++;
        }
    }

    return contador;
}
float calcularPromedio(int suma,int contador)
{
    float retorno;
    retorno = (float)suma/contador;
    return retorno;
}
