#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"

#define E 50

int main()
{
    int estadoInicializacionDeEmpleados;
    int acumuladorSalario;
    int contadorSalario;
    int contadorSalariosMayorAlPromedio;
    int validarNewEmployee;
    int i;

    float promedioSalario;

    char opcion;

    Employee misEmpleados[E];

    estadoInicializacionDeEmpleados = initEmployees(misEmpleados, E);

    if(estadoInicializacionDeEmpleados == 0)
    {
        printf("Empleados inicializados.\n");
    }//end if
    else
    {
        printf("Error de inicializacion.");
    }//end else

    initEmployeesWithData(misEmpleados, E);

    system("pause");
    system("cls");

    do
    {
        printf("(1) ANIADIR EMPLEADO. \n");
        printf("(2) MODIFICAR EMPLEADO. \n");
        printf("(3) BAJA DE EMPLEADO. \n");
        printf("(4) MOSTRAR LISTADO. \n");
        printf("(5) INFORMAR PROMEDIOS. \n");
        printf("(6) Salir. \n");

        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6')
        {
            printf("Error. Elija una opcion valida.\n\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }//end while

        switch(opcion)
        {
        case '1':
            validarNewEmployee = addEmployeesModificado(misEmpleados, E);
            break;

        case '2':
            modificationEmployee(misEmpleados, E);
            break;

        case '3':
            removeEmployee(misEmpleados, E);
            break;

        case '4':
            sortEmployees(misEmpleados, E, 0);
            printEmployees(misEmpleados, E);
            break;

        case '5':
            contadorSalario = 0;
            acumuladorSalario = 0;
            contadorSalariosMayorAlPromedio = 0;
            promedioSalario = 0;

            for (i=0; i<E; i++)
            {
                if (misEmpleados[i].isEmpty == 1)
                {
                    acumuladorSalario = misEmpleados[i].salary + acumuladorSalario;
                    contadorSalario++;
                }//end if
            }//end for
            promedioSalario = (acumuladorSalario / contadorSalario);

            for (i=0; i<E; i++)
            {
                if (misEmpleados[i].isEmpty == 1 && misEmpleados[i].salary > promedioSalario)
                {
                    contadorSalariosMayorAlPromedio++;
                }//end if
            }//end for
            printEmployees(misEmpleados, E);

            printf("El promedio es: %f\n", promedioSalario);
            printf("Los empleados que superan el sueldo promedio son: %d\n", contadorSalariosMayorAlPromedio);
            break;

        case '6':
            opcion='6';
            printf("Saliendo... \n");
            break;

        default:
            printf("Error. Elija una opcion valida.\n");
            break;
        }//end switch
        system("pause");
        system("cls");
    }//end do
    while(opcion!='6');

    return 0;
}//end main
