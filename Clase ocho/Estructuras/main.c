#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

int main()
{
    eAlumno miAlumno;//{1000,"Pepe",7};
    eAlumno otroAlumno;
    miAlumno = pedirAlumno();
    otroAlumno = pedirAlumno();
    mostrarAlumno(miAlumno);

    if (compararAlumnoPorLegajo(miAlumno,otroAlumno))
    {
        printf("\nLos alumnos son iguales.");
    }
    else
    {
        printf("\n Los alumnos no son iguales.");
    }
    return 0;
}
