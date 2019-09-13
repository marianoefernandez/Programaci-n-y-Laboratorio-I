#include "alumno.h"

void mostrarAlumno (eAlumno miAlumno)
{
    printf("%d--%s--%d",miAlumno.legajo,miAlumno.nombre,miAlumno.nota);
}

eAlumno pedirAlumno()
{
    eAlumno miAlumno;
    printf("\nIngrese legajo: ");
    scanf("%d",&miAlumno.legajo);
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("\nIngrese nota: ",&miAlumno.nota);
    scanf("%d",&miAlumno.nota);

    return miAlumno;
}

int compararAlumnoPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    int comp = 0;
    if (unAlumno.legajo==otroAlumno.legajo)
    {
        comp = 1;
    }
    return 0;
}
