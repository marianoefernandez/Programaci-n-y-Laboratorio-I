#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "Dominio.h"
#include "validaciones.h"


int main()
{
    int flag=0;


    FILE *pArchivo;
    LinkedList* listaDominios = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    LinkedList* listaFilterA = NULL;
    LinkedList* listaFilterM = NULL;
    LinkedList* listaFilter2004 = NULL;
    /* LinkedList* listaDominio=ll_newLinkedList();
     LinkedList* listaAutos;
     LinkedList* listaMotos;
     */
    char salir = 'n';

    if(listaDominios!=NULL)
    {
        do
        {
            switch(menu())
            {
            case 1:
                if((pArchivo=fopen( "datos.csv","r"))==NULL)
                {
                    printf("\nNO SE PUDO ABRIR EL ARCHIVO\n");

                }
                else if (controller_loadFromText("datos.csv", listaDominios))
                {
                    system("cls");
                    printf("\nEL ARCHIVO ESTA CARGADO CORRECTAMENTE\n");
                    flag=1;
                }

                fclose(pArchivo);
                break;

            case 2:  ///LISTAR ORIGINAL, SIN TIPO MAPEADO

                if (flag)
                {
                    showDominios(listaDominios);
                }
                else
                {
                    printf("\nERROR, TAL VEZ AUN NO SE CARGARON ARCHIVOS.\n");
                }
                break;

            case 3: ///MAPEAR Y CARGAR, CON TIPO DE VEHICULO

                if (flag)
                {
                    listaMapeada = ll_map(listaDominios, seteaTipo);
                    printf("\nSE HA MAPEADO LA LISTA ORIGINAL Y AGREGADO EL TIPO\n");

                }
                break;

            case 4: ///Listar vehiculos con tipo

                if(listaMapeada != NULL)
                {
                    showDominios(listaMapeada);
                }
                else
                {
                    printf("\nERROR, TAL VEZ NO HAY ARCHIVOS CARGADOS.\n");
                }

                break;

            case 5:///Listar vehiculos separados por tipo

                listaFilterA = ll_filter(listaMapeada, filterTipo_autos);
                listaFilterM = ll_filter(listaMapeada, filterTipo_motos);


                if(listaFilterA != NULL && listaFilterM != NULL)
                {
                    showDominios(listaFilterA);
                    printf("\n");
                    showDominios(listaFilterM);
                }


                break;

            case 6:///dominios filtrados por anio

                listaFilter2004=ll_filter(listaMapeada,filter_anio_2004);

                if(listaMapeada=!NULL)
                {

                    showDominios(listaFilter2004);

                }
                else
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }

                break;

            case 7: ///generar archivo de salida Motos

                if (flag)
                {

                    /// controller_saveAsText("auto.csv", listaFilterA);
                    controller_saveAsText("moto.csv", listaFilterM);

                }
                else

                {
                    printf("Error debe generar un archivo\n");
                }

                break;

            case 8:

                if (flag)
                {

                    controller_saveAsText("auto.csv", listaFilterA);
                    ///controller_saveAsText("moto.csv", listaFilterM);
                }
                else

                {
                    printf("Error debe generar un archivo\n");
                }


                break;

            case 9: ///SALIR
                printf("\nConfirma la salida del sistema? (s/n): ");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("\nOPCION INVALIDA\n");

            }
            system("\n\npause\n");
        }
        while(salir == 'n');
    }
    {
        printf("\nERROR. No se consiguio espacio en memoria para el LinkedList");
    }

    system("\n\npause");
    return 0;
}

