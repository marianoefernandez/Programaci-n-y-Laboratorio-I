#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#define A 2

int main()
{
    eAlumno listaAlumnos [A];
    int i;

    //HACER MENU USANDO SYSTEM CLS Y PAUSE

    cargarAlumnos(listaAlumnos,A);
    mostrarListadoAlumnos (listaAlumnos,A);


   /* eAlumno miAlumno;//{1000,"Pepe",7};
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
    */
    return 0;
}
