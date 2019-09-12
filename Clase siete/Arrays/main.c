#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 8

//CARGA EL ARRAY CON DATOS
void cargarConDatosEnteros(int [],int);
//CARGA ARRAY CON NOMBRES
void cargarNombres(char [][50],int);

int main()
{
    int edades [TAM];
    char nombres [TAM] [50];
    int i;

   /* for (i=0;i<3;i++)
    {
        printf("\nIngrese su edad: ");
        scanf("%d", &edades[i]);
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        gets(nombres[i]);
    }

    */
    cargarConDatosEnteros(edades,TAM);
    cargarNombres(nombres,TAM);

    for (i=0;i<TAM;i++)
    {
        printf("\nSu edad es: %d anios y su nombre es %s ", edades[i], nombres[i]);
    }

    return 0;
}

void cargarConDatosEnteros(int miArray [],int cantidad)
{
    int aux[]={55,11,22,33,18,15,10,66};
    int i;
    for (i=0;i<cantidad;i++)
    {
        miArray[i]=aux[i];
    }
}

void cargarNombres(char miArray [][50],int cantidad)
{
    char aux[][50]={"Jorge","Ricardo","Lionel","Mauro","Manuel","Felipe","Damian","Jose"};
    int i;
    for (i=0;i<cantidad;i++)
    {
        strcpy(miArray[i],aux[i]);
    }
}
