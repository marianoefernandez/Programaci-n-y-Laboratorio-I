#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Personas.h"

///EL CONSTRUCTOR ESTA BIEN
///GUARDA EL ARCHIVO PERO NO PUEDO CREAR UN SEGUNDO DATO YA QUE POR MAS QUE PONGA persona+1 NO CARGA
///EL LOAD BINARY NO FUNCIONA

int main()
{
    ePersona* persona;
    persona=newPersonaParametros("1","hola37@gmail.com");
    ///CARGUE SOLO UNO PORQUE NO ME SALEN CARGAR LOS DOS DATOS
    //realloc((ePersona*)persona,sizeof(ePersona*)*2);
    //(*persona+1)=newPersonaParametros("2","hola68@gmail.com"); //NO ME SALE CON DOS DATOS
    saveBinary(persona,"personas.bin");
    loadBinary(persona,"personas.bin");
    return 0;
}

