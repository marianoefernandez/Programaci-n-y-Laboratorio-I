#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

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
