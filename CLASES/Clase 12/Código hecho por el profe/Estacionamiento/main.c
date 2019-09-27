#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

//hacemos un for
//if (idDueño == idPersona)
//cuando lo encontre hago break

int main()
{
    ePersona ListadoDePersonas[4];
    cargarPersonas(ListadoDePersonas,4);
    mostrarPersonas(ListadoDePersonas,4);
    return 0;
}

