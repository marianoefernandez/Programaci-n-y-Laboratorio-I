#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000
#define NOTFREE 1
#define FREE 0


/*Una empresa requiere un sistema para administrar su nómina de empleados.
Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id.
El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema. //FUNCIONA
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector. //FUNCIONA
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*/
int main()
{
    Employee list[TAM];

    if(initEmployees(list,TAM)==0)
    {

    int opcion;
    int opcion2;
    int opcion3;
    int idAutoincremental=0;
    int retorno;
    int cantidadEmpleadosOcupados;
    float salarioTotal;
    float promedioSalario;
    int cantidadEmpleadosSalarioSuperior;

    do
        {
            printFirstMenu();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                idAutoincremental++;
                if (addEmployees(list,TAM,idAutoincremental)== 0)
                {
                    printf("\nSe cargo el empleado\n");
                }
                else
                {
                    printf("\nNO HAY ESPACIO\n");
                }

                /*hardcoded(list,HARDCODING);
                printf("\nSe hardcodearon empleados");
                */
                break;

            case 2:
                cantidadEmpleadosOcupados= employeesNotFree(list,TAM);
                if (cantidadEmpleadosOcupados>0)
                {
                   if(modificationEmployee(list,TAM)!=-1)
                   {
                       printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
                   }
                   else
                   {
                       printf("\nEl empleado no existe\n");
                   }
                }else
                {
                    printf("\nNo hay ningun empleado dado de alta, por favor primero realice una carga\n");
                }
                break;

            case 3:
                cantidadEmpleadosOcupados= employeesNotFree(list,TAM);
                if (cantidadEmpleadosOcupados>0)
                {
                    retorno = removeEmployee(list,TAM,getInt("Ingrese el ID: "));
                    switch(retorno)
                    {
                    case 0:
                        printf("\nSe elimino el empleado\n");
                        break;
                    case 1:
                        printf("\nAccion cancelada por el usuario\n");
                        break;
                    case -1:
                        printf("\nNo se encontro el dato\n");
                        break;
                    case 2:
                        printf("\nEl empleado se elimino anteriormente o no existe el empleado\n");
                        break;
                    }
                }
                else
                {
                    printf("\nNo hay ningun empleado dado de alta, por favor primero realice una carga\n");
                }
                    break;

            case 4:
                cantidadEmpleadosOcupados= employeesNotFree(list,TAM);
                if (cantidadEmpleadosOcupados>0)
                {
                    do
                    {
                        printSecondMenu();
                        opcion2=getInt("\nSu opcion: ");

                        switch(opcion2)
                        {
                        case 1:
                            do
                            {
                                printSortMenu();
                                opcion3=getInt("\nSu opcion: ");
                                switch(opcion3)
                                {
                                    case 1:
                                        sortEmployeesByLastName(list,TAM,0);
                                        printf("/nSe ordeno correctamente       /n");
                                        system("pause");
                                        printEmployees(list,TAM);
                                        system("pause");
                                        opcion3=0;
                                        break;
                                    case 2:
                                        sortEmployeesBySector(list,TAM);
                                        printf("/nSe ordeno correctamente       /n");
                                        system("pause");
                                        printEmployees(list,TAM);
                                        system("pause");
                                        opcion3=0;
                                        break;
                                    default:
                                            if(opcion3!=0)
                                            {
                                                printf("Seleccione una opcion valida ");
                                            }
                                            break;
                                }
                                system("cls");
                            }while (opcion3 !=0);
                            opcion2=0;
                            break;

                        case 2:
                            salarioTotal=totalSalary(list,TAM);
                            promedioSalario=salaryAverage(list,TAM,salarioTotal);
                            cantidadEmpleadosSalarioSuperior=betterThanAverage(list,TAM,promedioSalario);
                            printf("\nEl salario total es: %.2f $",salarioTotal);
                            printf("\nEl promedio es: %.2f $",promedioSalario);
                            printf("\n%d empleados superan el salario promedio",cantidadEmpleadosSalarioSuperior);
                            opcion2=0;
                            break;

                        default:
                            if(opcion2!=0)
                            {
                                printf("Seleccione una opcion valida ");
                            }
                        }
                        system("pause");
                        system("cls");
                    }
                    while(opcion2!=0);
                }
                else
                {
                    printf("\nPor favor primero realice una carga\n");
                }
                break;
            default:
                printf("\nSeleccione una opcion valida \n");

            }
            system("pause");
            system("cls");
        }while(opcion!=0);
    }
    else
    {
        printf("\nHubo un error al crear la lista, No hay espacio en memoria\n");
    }

    return 0;
}
