#include <stdio.h>
#include <stdlib.h>

void cargarVector(int*,int);

void mostrarVector(int*,int);

void incrementarId(int*);

int main()
{
    //int* puntero;
    //int i;
    int contador=0;
    int vector[5]; //= {5,7,9,8,3};
    //int entero;

    //puntero=&entero;

    //puntero=&vector;
    //puntero=vector;
    //puntero=&vector[0];

    //cargarVector(vector,5);

    //mostrarVector(vector,5);

    incrementarId(&contador);
    printf("Siguiente id %d\n",contador);

        incrementarId(&contador);
    printf("Siguiente id %d\n",contador);

        incrementarId(&contador);
    printf("Siguiente id %d\n",contador);


    /*
    printf("%p\n",puntero);
    printf("%p\n",puntero-1);
    printf("%p\n",puntero+1);
    printf("%p\n",puntero+2);
    printf("%p\n\n\n",puntero+3);

    puntero=puntero+1;
    system("pause");
    printf("%p\n",puntero);
    */
    return 0;
}

void cargarVector(int* vector,int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");//vector[i]
        scanf("%d",vector+i);
    }
}

void mostrarVector(int* vector,int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        printf("%d\n", *(vector+i));//vector[i]
    }
}

void incrementarId(int* ultimoId)
{
    *ultimoId=*ultimoId+1;
}


