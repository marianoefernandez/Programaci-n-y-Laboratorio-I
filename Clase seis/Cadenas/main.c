#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
    strlen
    strcpy
    strupr
    strlwr
    strcmp
    stricmp
    strcat = concatena
    */
    char palabra[10];
    char palabra2[10];
    char todo [50];
    int comp;

    printf("Ingrese una palabra: ");

    gets(palabra);

    strcpy(palabra2,"perro");

    if (stricmp(palabra2, palabra)==0)
    {
        printf("Son iguales");
    }
    else
    {
        printf("No son iguales");
    }

    strcat(todo,palabra);
    strcat(todo,palabra2);
    strcat(todo,"Chau");

    printf("\ntodo = %s", todo);

    return 0;
}
