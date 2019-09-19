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
void pedirDatos(ePersona [],int,int);
void mostrarPersona (ePersona [], int);
void ordenarDNI (ePersona[],int);


int main()
{
    int opcion;

    ePersona persona[TAM];
    inicializarPersonas(persona,TAM);
    while (opcion !=8)
    {
        system ("cls");
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            pedirPersona(persona,TAM);
            break;
        case 2:
            mostrarPersona(persona,TAM);
            system("pause");
            break;
        case 3:
            ordenarDNI (persona,TAM);
            break;
        }
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
    printf("\n3-Ordenar por DNI: ");
    printf("\n8-Salir: ");
    printf("\nIngrese opcion: ");
}

void pedirPersona(ePersona persona [],int cantidad)
{
    int i;
    int flagEncontro=0;

    for (i=0; i<cantidad; i++)
    {
        if (persona[i].estaVacio = 1)
        {
            pedirDatos(persona,i,cantidad);
            flagEncontro=1;
            break;
        }
    }
    if (flagEncontro ==0)
    {
        printf("NO HAY ESPACIO");
    }
}

int validarDni (ePersona persona[],int auxDni,int cantidad)
{
   int i;
   int salida=0;
    for (i=0; i<cantidad; i++)
    {
        if (persona[i].estaVacio = 0 && auxDni == persona[i].dni)
        {
            salida =1;
        }
    }
    return salida;
}

void pedirDatos(ePersona persona[],int i,int cantidad)
{
        printf("\nIngrese dni: ");
        int auxDni;
        scanf("%d",&auxDni);
        while(validarDni(persona,auxDni,cantidad)==1)
        {
            printf("Ya existe el DNI ingrese otro: \n");
            scanf ("%d", &auxDni);
        }
        persona[i].dni=auxDni;
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
        if(persona[i].estaVacio==0)
        {
            printf("%d--%s--%s\n",persona[i].dni,persona[i].nombre,persona[i].apellido);
        }
    }
}

void ordenarDNI (ePersona persona [],int cantidad)
{
    int i;
    int j;
    ePersona auxPersona;

    for (i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if (persona[i].dni<persona[j].dni)
            {
                auxPersona = persona[i];
                persona[i] = persona[j];
                persona[j] = auxPersona;
            }
        }
    }
}
