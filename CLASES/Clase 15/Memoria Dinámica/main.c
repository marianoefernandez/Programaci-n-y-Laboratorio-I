#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    int edad;
    //char nombre[50];
    float altura;
}ePersona;

ePersona* new_Persona();//RETORNA PUNTERO

int main()
{
    ePersona* pPersona;
    pPersona = new_Persona();

    printf("La persona es: \n");
    printf("%d--%d--%f\n",pPersona->legajo,pPersona->edad,pPersona->altura);
    return 0;
}

ePersona* new_Persona()
{
    ePersona* miPersona;

    miPersona = malloc(sizeof(ePersona));

    miPersona->legajo = 100;
    miPersona->edad = 40;
    miPersona->altura = 1.87;

    return miPersona;
}
