#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void inicializar(int[], int);
void mostrar(int[], int);
void ordenar(int[], int);
void swap(int*, int*);

int main()
{
    int pos;
    int numeroOrden[50];
    inicializar(numeroOrden,50);

    mostrar(numeroOrden,50);
    pos = 0;
    char opcion;
    do{
        printf("Ingrese Numero de orden: ");
        scanf("%d",&numeroOrden[pos]);

        pos++;
        //printf("\nIngresa Otro?");
        //fflush(stdin);
        //gets(&opcion);

    }while(pos<10);

    mostrar(numeroOrden,50);
    ordenar(numeroOrden,50);
    mostrar(numeroOrden,50);

    return 0;
}

void inicializar(int array[], int tam){

        int i;
        for(i=0;i<tam;i++){
            array[i]=-1;
        }
}

void mostrar(int array[], int tam){

        int i=0;
        for(i=0;i<tam;i++){
                if(array[i]!=-1){
                    printf("%d-%d \n ",i, array[i]);
                }

        }
}

void ordenar(int array[], int tam){
    int i=0;
    int j=0;
    for(i= 0; i< tam -1;i++){
        for(j=i+1;j<tam;j++){
            if(array[i]> array[j])
            {
                int a;
                swap(&array[i], &array[j]);
            }
        }
    }

}
void swap(int* a, int* b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
