#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

ePersona* new_Persona()
{
    ePersona* miPersona;

    miPersona = calloc(sizeof(ePersona),1);

/*
    miPersona->legajo = 100;
    miPersona->edad = 40;
    miPersona->altura = 1.87;
*/

    return miPersona;
}

int mostrarPersona(ePersona* unaPersona)
{
    int retorno=-1;

    if (unaPersona!=NULL)
    {
        printf("%d--%d--%f\n",unaPersona->legajo,unaPersona->edad,unaPersona->altura);
        retorno=1;
    }
    return retorno;
}

int delate_Persona(ePersona* unaPersona)
{
    int retorno=-1;

    if (unaPersona!=NULL)
    {
        free(unaPersona);
        retorno=1;
    }
    return retorno;
}

ePersona* new_Persona_Parametros(int legajo,int edad, float altura)
{
    ePersona* miPersona = new_Persona();

    if (miPersona!=NULL)
    {
        miPersona->legajo = legajo;
        miPersona->edad = edad;
        miPersona->altura = altura;
    }


    return miPersona;
}


