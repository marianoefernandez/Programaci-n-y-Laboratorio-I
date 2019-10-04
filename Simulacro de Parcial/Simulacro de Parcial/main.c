#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estacionamiento.h"
#define TAM 1000
#define NOTFREE 1
#define FREE 0
#define HARDCODING 4

int main()
{
    ePropietario listaP[TAM];
    eVehiculo listaV[TAM];

    if(inicializarPropietarios(listaP,TAM)==0)
    {

    int opcion;
    int opcion2;
    int idAutoincremental=0;
    int retorno;
    int cantidadPropietariosOcupados;

    do
        {
            printFirstMenu();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                /*idAutoincremental++;
                if (agregarPropietario(listaP,TAM,idAutoincremental)== 0)
                {
                    printf("\nSe cargo el propietario\n");
                }
                else
                {
                    printf("\nNO HAY ESPACIO\n");
                }
                */

                hardcodeoPropietarios(listaP,HARDCODING);
                printf("\nSe hardcodearon propietarios");

                break;

            case 2:
                cantidadPropietariosOcupados= propietariosOcupados(listaP,TAM);
                if (cantidadPropietariosOcupados>0)
                {
                    retorno = eliminarPropietario(listaP,TAM,getInt("Ingrese el ID: "));
                    switch(retorno)
                    {
                    case 0:
                        printf("\nSe elimino el propietario\n");
                        break;
                    case 1:
                        printf("\nAccion cancelada por el usuario\n");
                        break;
                    case -1:
                        printf("\nNo se encontro el dato\n");
                        break;
                    case 2:
                        printf("\nEl propietario se elimino anteriormente o no existe el propietario\n");
                        break;
                    }
                }
                else
                {
                    printf("\nNo hay ningun propietario dado de alta, por favor primero realice una carga\n");
                }
                    break;

            case 3:
                cantidadPropietariosOcupados= propietariosOcupados(listaP,TAM);
                if (cantidadPropietariosOcupados>0)
                {
                   if(modificarPropietario(listaP,TAM)!=-1)
                   {
                       printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
                   }
                   else
                   {
                       printf("\nEl empleado no existe\n");
                   }
                }else
                {
                    printf("\nNo hay ningun propietario dado de alta, por favor primero realice una carga\n");
                }
                break;


            case 4:
                cantidadPropietariosOcupados= propietariosOcupados(listaP,TAM);
                if (cantidadPropietariosOcupados>0)
                {
                    if (agregarVehiculo(listaV,TAM)== 0)
                    {
                        printf("\nSe cargo el vehiculo\n");
                    }
                    else
                    {
                        printf("\nNO HAY ESPACIO\n");
                    }
                }
                else
                {
                    printf("\nNo hay ningun propietario dado de alta, por favor primero realice una carga\n");
                }
                break;

            case 5:
                cantidadPropietariosOcupados= propietariosOcupados(listaP,TAM);
                if (cantidadPropietariosOcupados>0)
                {
                   if (egresarVehiculo(listaV,TAM)== 0)//ARREGLAR LA FUNCION EGRESAR VEHICULO
                    {
                        printf("\nSe egreso el vehiculo\n");
                    }
                    else
                    {
                        printf("\nNO HAY ESPACIO\n");
                    }
                }
                else
                {
                    printf("\nNo hay ningun propietario dado de alta, por favor primero realice una carga\n");
                }
                break;
            case 6:
                cantidadPropietariosOcupados= propietariosOcupados(listaP,TAM);
                if (cantidadPropietariosOcupados>0)
                {
                    printf("\n\n\nPROPIETARIOS ORDENADOS POR NOMBRE\n\n\n");
                    ordenarPropietariosNombre(listaP,TAM,0);
                    printPropietarios(listaP,TAM);
                    printf("\n\n\nPROPIETARIOS ORDENADOS POR ANIO\n\n\n");
                    ordenarPropietariosAnio(listaP,TAM);
                    printPropietarios(listaP,TAM);
                }

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
