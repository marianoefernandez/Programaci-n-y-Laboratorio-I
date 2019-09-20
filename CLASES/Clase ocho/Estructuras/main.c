#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#define TAM 2

int main()
{
    eAlumno listaAlumnos [TAM];
    int i;
    int opcion;
    int index;

    if(inicializarAlumnos(listaAlumnos,TAM)==0)
    {
        do
        {
            printf("1-Cargar alumnos\n");
            printf("2-Mostrar alumnos\n");
            printf("3-Ordenar alumnos por nombres\n");
            printf("4-Buscar por legajo\n");
            printf("5-Dar de baja a alumno\n")
            printf("6-Salir\n");
            printf("Su opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                if (cargarAlumnos(listaAlumnos,TAM)== 1)
                {
                    printf("\nSe cargo el alumno\n");
                }
                else
                {
                    printf("\nNO HAY ESPACIO\n");
                }
                break;

            case 2:
                mostrarListadoAlumnos(listaAlumnos,TAM);
                break;

            case 3:
                ordenarAlumnosPorNombres(listaAlumnos,TAM);
                break;

            case 4:
                index = buscarAlumnoPorLegajo(listaAlumnos,TAM,pedirLegajo());
                break;

            case 5:
            }
            system("pause");
            system("cls");
        }while(opcion!=6);

    }else
    {
        printf("Hubo error al crear lista");
    }



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
