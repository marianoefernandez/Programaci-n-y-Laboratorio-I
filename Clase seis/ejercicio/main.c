#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre [15];
    char apellido [15];
    char apellidoNombre [32];

    printf("\nIngrese nombre: ");
    gets(nombre);
    printf("\nIngrese apellido: ");
    gets(apellido);
    nombre[0]=toupper(nombre[0]);
    apellido[0]=toupper(apellido[0]);

    strcpy (apellidoNombre,nombre);
    strcat(apellidoNombre," , ");
    strcat(apellidoNombre, apellido);

    printf("%s",apellidoNombre);
}
