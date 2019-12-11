#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor,re=-1;
    printf(message);
    fflush(stdin);
    scanf("%d",&valor);
    while(valor<lowLimit||valor>hiLimit){
        printf(eMessage);
        fflush(stdin);
        scanf("%d",&valor);

    }
    re=0;

    *input = valor;
    return re;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
        int re=-1;
        float valor;
    printf(message);
    fflush(stdin);
    scanf("%f",&valor);
    while(valor<lowLimit||valor>hiLimit){
        printf(eMessage);
        fflush(stdin);
        scanf("%f",&valor);

    }
    re=0;
    *input = valor;


    return re;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
        char valor;
        int re=-1;
    printf(message);
    fflush(stdin);
    scanf("%c",&valor);
    while(valor<lowLimit||valor>hiLimit){
        printf(eMessage);
        fflush(stdin);
        scanf("%c",&valor);
    }
    re=0;
    *input = valor;
    return re;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char cadena[hiLimit];
    int re=-1;
    printf(message);
    fflush(stdin);
    fgets(cadena, hiLimit-2, stdin);
    strcpy(cadena,strtok(cadena,"\n"));
    cadena[hiLimit-1] = '\0';
    while(strlen(cadena)<2){
        printf(eMessage);
        printf(message);
    fflush(stdin);
    fgets(cadena, hiLimit-2, stdin);
    strcpy(cadena,strtok(cadena,"\n"));
    cadena[hiLimit-1] = '\0';
    }
   re=0;

    strcpy(input,cadena);
    return re;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */

 int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/** \brief Menu de opciones solo imprime, las opciones.
 *
 *
 */

void menu(){
printf("\n1)Realizar un programa que lea un archivo\n2)Ordenar la lista generada\n3)Imprimir por pantalla ide tipo DESKTOP o LAPTOP\n4)map y aumenta precios en 10 desktop 20 laptops:\n5)filtrar solo Laptop \n6)Guardar lista laptops\n7)Salir");

}
