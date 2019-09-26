#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*
Escribir un programa que realice las siguientes acciones:

-Solicite al usuario 10 números.
-Calcule cuántos son negativos y cuantos son positivos.
-Muestre por pantalla la cantidad de negativos y la cantidad de positivos.

*/

int main()
{
    int numeros[MAX];
    return 0;
}

//1-FUNCION GET INT
int getInt (char* mensaje)
{
    int aux;//PASAMOS EL DATO AL AUX
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}
//2-FUNCION PARA PEDIR VARIOS NUMEROS
int pedirDatos(int* numeros,int cantidad)
{
   int i;

   for (i=0;i<cantidad;i++)//CARGA SECUENCIAL
   {
       printf("\nIngrese un numero: ")
       scanf("%d",&numeros[i]);
   }

}
//3-CALCULAR NEGATIVOS
//4-CALCULAR POSITIVOS
//5-MOSTRAR CANTIDAD POS Y NEG
