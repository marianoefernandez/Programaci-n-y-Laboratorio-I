#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0

typedef struct
{
    int legajo;
    char nombre[50];
    int nota;
    int dni;
    int estado;
}eAlumno;

int autoincrementar (int*);

int pedirLegajo();

int buscarAlumnoPorLegajo(eAlumno*,int,int);

int buscarLibre(eAlumno*,int);

int bajaAlumno(eAlumno*,int);

int inicializarAlumnos(eAlumno*,int);

void mostrarAlumno (eAlumno);

eAlumno pedirAlumno();

int compararAlumnoPorLegajo(eAlumno , eAlumno );

int cargarAlumnos(eAlumno*,int);

void mostrarListadoAlumnos (eAlumno*,int);

void ordenarAlumnosPorNombres(eAlumno*,int);

void hardcodearAlumnos(eAlumno*,int);
