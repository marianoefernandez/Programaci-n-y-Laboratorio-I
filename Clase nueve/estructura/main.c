#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct
{
    int dni;
    char nombre [21];
    char apellido [21];
    int estaVacio;
}ePersona;

void inicializarPersonas(ePersona [],int);
void menu ();
void pedirPersona(ePersona [],int);
void pedirDatos(ePersona [],int);
void mostrarPersona (ePersona [], int);

int main()
{
    int opcion;

    ePersona persona[TAM];
    //inicializarPersonas(persona,TAM);
    menu();
    scanf("%d",opcion);
    switch(opcion)
    {
    case 1:
        pedirPersona(persona,TAM);
        break;
    case 2:
        mostrarPersona(persona,TAM);
        break;
    }
    //pedirPersona(persona,TAM);
    //mostrarPersona(persona,TAM);
    return 0;
}

void inicializarPersonas(ePersona persona [],int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        persona[i].estaVacio = 1;
    }
}

void menu ()
{
    printf("-------Ingrese una opcion-------");
    printf("\n1-Pedir persona: ");
    printf("\n2-Mostrar persona: ");
    printf("\nIngrese opcion: ");
}

void pedirPersona(ePersona persona [],int cantidad)
{
    int i;

    for (i=0; i<cantidad; i++)
    {
        if (persona[i].estaVacio = 0)
        {
            printf("INO HAY MAS ESPACIO");
        }
    }
}

void pedirDatos(ePersona persona[],int indice)
{
        printf("\nIngrese dni: ");
        scanf("%d",&persona[i].dni);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(persona[i].nombre);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(persona[i].apellido);
        persona[i].estaVacio = 0;
}

void mostrarPersona (ePersona persona [], int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("\n%d--%s--%s",persona[i].dni,persona[i].nombre,persona[i].apellido);
    }
}
