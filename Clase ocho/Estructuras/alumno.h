#include <stdio.h>

typedef struct
{
    int legajo;
    char nombre[50];
    int nota;
}eAlumno;

void mostrarAlumno (eAlumno);
eAlumno pedirAlumno();
int compararAlumnoPorLegajo(eAlumno , eAlumno );
void cargarAlumnos(eAlumno[],int);
void mostrarListadoAlumnos (eAlumno[],int);
void ordenarAlumnosPorNombres(eAlumno[],int);
void hardcodearAlumnos(eAlumno[],int);
