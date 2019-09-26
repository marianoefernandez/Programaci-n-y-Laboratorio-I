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

} eAlumno;

int buscarAlumnoPorLegajo(eAlumno*,int,int);


int buscarAlumnoLibre(eAlumno[], int);

int inicializarAlumnos(eAlumno*, int);

void mostrarAlumno(eAlumno);

eAlumno pedirAlumno(void);

int compararAlumnoPorLegajo(eAlumno,eAlumno);

int cargarAlumnos(eAlumno[], int);

void mostrarListadoDeAlumnos(eAlumno[], int);

void ordenarAlumnosPorNombre(eAlumno[], int);

void hardcoderAlumnos(eAlumno[], int);
