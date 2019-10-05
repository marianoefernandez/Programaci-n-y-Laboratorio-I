#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#define TAM 200

int main()
{
    int opcion;
    int cantidadAgenda;
    int retorno;
    eAgenda agenda[TAM];

    if (initAgenda(agenda,TAM)==0)
    {
        do
        {
            printFirstMenu();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                if (agregarAgenda(agenda,TAM)== 0)
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
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                   if(modificarAgenda(agenda,TAM)!=-1)
                   {
                       printf("\n\nSe ha realizado la modificacion correctamente.\n\n");
                   }
                   else
                   {
                       printf("\nLa persona no existe\n");
                   }
                }else
                {
                    printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
                }
                break;

            case 3:
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                    retorno = eliminarAgenda(agenda,TAM,getInt("Ingrese el legajo: "));
                    switch(retorno)
                    {
                    case 0:
                        printf("\nSe elimino la persona\n");
                        break;
                    case 1:
                        printf("\nAccion cancelada por el usuario\n");
                        break;
                    case -1:
                        printf("\nNo se encontro el dato\n");
                        break;
                    case 2:
                        printf("\nLa persona se elimino anteriormente o no existe la persona\n");
                        break;
                    }
                }
                else
                {
                    printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
                }
            case 4:
                cantidadAgenda=agendaNotFree(agenda,TAM);
                if (cantidadAgenda>0)
                {
                    ordenarAgendaPorApellido(agenda,TAM,0);
                    printAgendas(agenda,TAM);
                }
                else
                {
                   printf("\nNo hay ninguna persona dada de alta, por favor primero realice una carga\n");
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
       printf("\n\nHubo un error al crear la lista, no hay espacio en memoria\n\n");
    }



}
