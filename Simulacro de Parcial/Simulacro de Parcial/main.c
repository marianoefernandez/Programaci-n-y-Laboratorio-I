#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estacionamiento.h"
#define TAM 1000
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10

int main()
{
    ePropietario listaP[TAM];
    eVehiculo listaV[TAM];

    if(inicializarPropietarios(listaP,TAM)==0 && inicializarVehiculos(listaV,TAM)==0)
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
                idAutoincremental++;
                /*
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
                    /*
                    if (agregarVehiculo(listaV,TAM)== 0)
                    {
                        printf("\nSe cargo el vehiculo\n");
                    }
                    else
                    {
                        printf("\nNO HAY ESPACIO\n");
                    }
                    */
                    hardcodeoVehiculos(listaV,HARDCODING);
                    printf("\nSe hardcodearon vehiculos");

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
                    do
                    {
                    printInformar();
                    opcion2=getInt("\nSu opcion: ");
                    switch (opcion2)
                    {
                        case 1:
                            ordenarPropietariosNombreAnio(listaP,TAM,1);
                            printf("/nSe ordeno correctamente/n");
                            system("pause");
                            printPropietarios(listaP,TAM);
                            opcion2=0;
                            break;

                        case 2:
                            ordenarPropietariosDuenioPatente(listaV,TAM,1);
                            printf("/nSe ordeno correctamente/n");
                            system("pause");
                            printVehiculos(listaP,listaV,TAM);
                            opcion2=0;
                            break;

                        case 3:
                            printAutosConDuenios(listaP,listaV,TAM);
                            opcion2=0;
                            break;

                        case 4:
                            break;

                        case 5:
                            break;

                        case 6:
                            break;

                        case 7:
                            break;

                        case 8:
                            break;

                        default:
                            if(opcion2!=0)
                            {
                                printf("Seleccione una opcion valida ");
                                system("pause");
                            }
                            break;
                    }
                    system("pause");
                    system("cls");
                    }while (opcion2 !=0);
                    opcion2=0;
                    break;
                    ordenarPropietariosNombreAnio(listaP,TAM,1);//DE A-Z
                    printPropietarios(listaP,TAM);
                    printf("\n\n\n");
                    ordenarPropietariosDuenioPatente(listaV,TAM,1);
                    printVehiculos(listaP,listaV,TAM);
                }
                break;

            default:
                printf("\nSeleccione una opcion valida \n");
                break;
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
