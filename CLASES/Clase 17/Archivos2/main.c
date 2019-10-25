#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[100];
    char apellido[100];
    char sexo[100];
    char sueldo[100];
}eEmpleado;

int main()
{
    FILE* pArchivo;
    //char lector [1000];
    int id[100];
    char nombre[100];
    char apellido[100];
    char sexo[100];
    char sueldo[100];

    eEmpleado lista[100];
    eEmpleado unEmpleado;

    pArchivo=fopen("Empleados.csv", "r");

    while(!feof(pArchivo))
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,apellido,sexo,sueldo);
        printf("%s--%s--%s--%s--%s\n", id,nombre,apellido,sexo,sueldo);
    }

    fclose(pArchivo);

    return 0;
}
