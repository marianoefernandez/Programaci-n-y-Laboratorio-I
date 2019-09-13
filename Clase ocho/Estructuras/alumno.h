#include <stdio.h>

typedef struct
{
    int legajo;
    char nombre[50];
    int nota;
}eAlumno;

void mostrarAlumno (eAlumno miAlumno);
eAlumno pedirAlumno();
int compararAlumnoPorLegajo(eAlumno unAlumno, eAlumno otroAlumno);
