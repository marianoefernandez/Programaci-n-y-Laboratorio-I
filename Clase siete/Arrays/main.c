#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 8
#define TAMALUMNOS 4

//CARGA EL ARRAY CON DATOS
void cargarConDatosEnteros(int [],int);
//CARGA ARRAY CON NOMBRES
void cargarNombres(char [][50],int);



int main()
{
    int edades [TAM];
    int notas [TAMALUMNOS];
    char nombres [TAM] [50];
    int i;
    int max,iMax;

   /* for (i=0;i<3;i++)
    {
        printf("\nIngrese su edad: ");
        scanf("%d", &edades[i]);
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        gets(nombres[i]);
    }

    */
    /*cargarConDatosEnteros(edades,TAM);
    cargarNombres(nombres,TAM);
    */

    cargarConDatosEnteros(notas,TAMALUMNOS);
    cargarNombres(nombres,TAMALUMNOS);

    max=notas[0];

    for (i=0;i<TAMALUMNOS;i++)
    {
        if (max<notas[i])
        {
            iMax=i;
        }
    }
    printf("\nLa nota mas alta es la de: %s", nombres[iMax]);

    /*
    for (i=0;i<TAM;i++)
    {
        printf("\nSu edad es: %d anios y su nombre es %s ", edades[i], nombres[i]);
    }
    */

    return 0;
}

void cargarConDatosEnteros(int miArray [],int cantidad)
{
    int aux[]={4,10,8,2};
    int i;
    for (i=0;i<cantidad;i++)
    {
        miArray[i]=aux[i];
    }
}

void cargarNombres(char miArray [][50],int cantidad)
{
    char aux[][50]={"Alfredo","Rogelio","Julieta","Pablo"};
    int i;
    for (i=0;i<cantidad;i++)
    {
        strcpy(miArray[i],aux[i]);
    }
}
