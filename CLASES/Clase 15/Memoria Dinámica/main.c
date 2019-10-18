#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"


int main()
{
    ePersona* pPersona;
    pPersona = new_Persona_Parametros(100,40,1.87);

    if (mostrarPersona(pPersona)!=1)
    {
        printf("Error al mostrar.");
    }

    delate_Persona(pPersona);

    return 0;
}
