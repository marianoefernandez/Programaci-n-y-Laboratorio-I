#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    float b;
    char c;
}eDato;

void cargarDatos(eDato*,int);
void mostrarDatos(eDato*,int);

int main()
{
/*
    eDato unDato = {1,5.3,'B'};
    eDato* pDato;

    pDato = &unDato;
    //pDato = unDato;


    //printf("%d-- %f -- %c\n",unDato.a,unDato.b,unDato.c);
    printf("%d-- %f -- %c\n",pDato->a,pDato->b,pDato->c);
 */

    eDato unDato[2]; //= {{2,3.26,'C'},{1,5.3,'B'}};

    cargarDatos(unDato,2);
    mostrarDatos(unDato,2);

    //pDato = unDato;


    //printf("%d-- %f -- %c\n",unDato.a,unDato.b,unDato.c);
}

void cargarDatos(eDato* listaDatos,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("\nIngrese entero: ");
        scanf("%d", &(listaDatos+i)->a);
        printf("\nIngrese flotante: ");
        scanf("%f", &(listaDatos+i)->b);
        printf("\nIngrese caracter: ");
        fflush(stdin);
        (listaDatos+i)->c = getche();
    }
}

void mostrarDatos(eDato* listaDatos,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("\n%d-- %f -- %c\n",(listaDatos+i)->a,(listaDatos+i)->b,(listaDatos+i)->c);
    }

    return 0;
}

