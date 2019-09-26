#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main()
{
    ePersona ListadoDePersonas[4];
    cargarPersonas(ListadoDePersonas,4);
    mostrarPersonas(ListadoDePersonas,4);
    printf("\n Estacionamiento!\n");
    return 0;
}

