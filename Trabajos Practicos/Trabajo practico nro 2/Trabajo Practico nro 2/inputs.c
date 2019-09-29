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
    scanf("%s", &aux);
    return aux;
}

void getString (char* mensaje,char* cadena)
{
    printf("\n%s", mensaje);
    fflush(stdin);
    gets(cadena);
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
    while (cadena[i] != '\0')
    {
        if((cadena[i] <  'a' || cadena [i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] == ' '))
            return 0;//RETORNA 0 SI TODO MAL
        i++;
    }
    return 1;//RETORNA 1 SI TODO OK
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
