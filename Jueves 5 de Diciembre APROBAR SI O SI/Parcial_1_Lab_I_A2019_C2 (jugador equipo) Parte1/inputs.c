#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int getInt (char* mensaje)
{
    int aux;//PASAMOS EL DATO AL AUX
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}

float getFloat(char* mensaje)
{
    float aux;
    printf("%s", mensaje);
    scanf("%f", &aux);
    return aux;
}

char getChar (char* mensaje)
{
    char aux;//PASAMOS EL DATO AL AUX
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    printf("%c",aux);
    return aux;
}

void getString (char* mensaje,char* cadena)
{
    printf("\n%s", mensaje);
    fflush(stdin);
    gets(cadena);
}

int validarDia (char* mes)
{
    int retorno=1;
    int auxDia;
    auxDia=atoi(mes);
    if (auxDia>31 || auxDia<1)
    {
        printf("\nERROR POR FAVOR SELECCIONE UN DIA VALIDO\n");
        retorno=0;
    }
    return retorno;
}

int validarMes (char* mes)
{
    int retorno=1;
    int auxMes;
    auxMes=atoi(mes);
    if (auxMes>12 || auxMes<1)
    {
        printf("\nERROR POR FAVOR SELECCIONE UN MES VALIDO\n");
        retorno=0;
    }
    return retorno;
}


int validarAnio (char* anio)
{
    int retorno=1;
    int auxAnio;
    auxAnio=atoi(anio);
    if (auxAnio<1900 || auxAnio>2019)
    {
        printf("\nERROR POR FAVOR SELECCIONE UN ANIO VALIDO\n");
        retorno=0;
    }
    return retorno;
}


void stringToUpper(char* caracter)
{
    int i;
    int large;
    caracter[0]=toupper(caracter[0]);
    large=strlen(caracter);
    for(i=0; i<large; i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}

int isCellphone(char* celular)
{
    int i=0;
    int contadorDeGuion = 0;
    while (celular[i] != '\0')
    {
        if ((celular[i] < '0' || celular[i] > '9') && (celular[i] != ' ') && (celular[i] != '-'))
            return 0;//RETORNA 0 SI TODO MAL
        if (celular[i] == '-')
            contadorDeGuion++;
        i++;
    }
    if (contadorDeGuion==2)
        return 1;//RETORNA 1 SI TODO BIEN
}

int isPhone(char* telefono)
{
    int i=0;
    int contadorDeGuion = 0;
    while (telefono[i] != '\0')
    {
        if ((telefono[i] < '0' || telefono[i] > '9') && (telefono[i] != ' ') && (telefono[i] != '-'))
            return 0;//RETORNA 0 SI TODO MAL
        if (telefono[i] == '-')
            contadorDeGuion++;
        i++;
    }
    if (contadorDeGuion==1)
        return 1;//RETORNA 1 SI TODO BIEN
}


int isOnlyLetters(char* cadena)
{
    int i=0;
    int ret;
    int cantidad;
    cantidad=strlen(cadena);
    while (cadena[i] != '\0')
    {
        if(((cadena[i] <  'a' || cadena [i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')) && (cadena[i] != ' '))
            ret=0;//RETORNA 0 SI TODO MAL
        i++;
    }

    ret=1;

    if(cantidad==0)
    {
        ret=0;
    }

    return ret;//RETORNA 1 SI TODO OK
}

int isNumeric(char* numero)
{
    int i=0;
    while(numero[i] != '\0')
    {
        if(numero[i] < '0' || numero[i] > '9')
            return 0;//RETORNA 0 SI TODO MAL
        i++;
    }
    return 1;//RETORNA 1 SI TODO BIEN
}

int isAlphaNumeric(char* alfanumero)
{
    int i=0;
    while (alfanumero[i] != '\0')
    {
        if((alfanumero[i] != ' ') && (alfanumero[i] <  'a' || alfanumero [i] > 'z') && (alfanumero[i] < 'A' || alfanumero[i] > 'Z') && (alfanumero[i] < '0' || alfanumero[i] > '9'))
            return 0;//RETORNA 0 SI TODO MAL
        i++;
    }
    return 1;//RETORNA 1 SI TODO BIEN
}

void mostrarArray(int* miArray,int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("%d\n",miArray[i]);
    }
}

int dameMax(int* miArray,int cantidad)
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

int dameMin(int* miArray,int cantidad)
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

void cargaSecuencialArray(int* miArray,int cantidad,char* mensaje)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("Ingrese %s: ",mensaje);
        scanf("%d",&miArray[i]);
    }
}

float darmePromedio (int* miArray,int cantidad)
{
    int i;
    float acumulador=0;

    for (i=0;i<cantidad;i++)
    {
        acumulador = acumulador + miArray[i];
    }

    return acumulador/cantidad;
}

void burbujeoMejorado (int* miArray,int cantidad)
{
    int j;
    int aux;
    int flag = 1;
    while (flag==1)
    {
        flag = 0;
        for (j = 1; j < cantidad; j++)
        {
            if (miArray[j] < miArray[j - 1])
            {
                aux = miArray[j];
                miArray[j] = miArray[j - 1];
                miArray[j - 1] = aux;
                flag = 1;
            }
        }
    }
}

void cargarVector(int* miVector, int tam)
{
    int i;
      printf("\tCARGA DE DATOS\n");
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &miVector[i]);
    }
}

void mostrarVector(int* miVector, int tam)
{
    int i;
    printf("\tMUESTRO EL VECTOR\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\n", miVector[i]);
    }
}

void mostrarNegativos(int* miVector,int tam)
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

void mostrarPromedio(int* miVector,int tam)
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

int sumarPositivos(int* miVector,int tam)
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

int contarPositivos(int* miVector,int tam)
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
