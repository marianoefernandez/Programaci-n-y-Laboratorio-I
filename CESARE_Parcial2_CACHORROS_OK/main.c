#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "Dominio.h"
#include "validaciones.h"
#include "parser.h"


int main()
{
    int flag=0;


    ///FILE *pArchivo;
    LinkedList* listaCachorro = ll_newLinkedList();
    LinkedList* lista45Dias = NULL; ///cada nuevo linkedlist que crea MAP, se incializa en NULL
    LinkedList* listaMachos = NULL;
    LinkedList* listaCallejeros = NULL;
    LinkedList* listaReservados = NULL;
    // LinkedList* listaMapeada = NULL; ///aca hacer los filters
    //LinkedList* listaFilterA = NULL; ///aca hacer los filters
    // LinkedList* listaFilterM = NULL; ///aca hacer los filters

    char salir = 'n';
    char nombreArchivo [15];
    char nombreArchivoAux [15]="cachorros.csv";

    if(listaCachorro!=NULL)
    {
        do
        {
            switch(menu())
            {
            case 1:

                getString(nombreArchivo, "INGRESE EL NOMBRE DEL ARCHIVO QUE DESEA ABRIR: ", "ERROR ");

                if (!strcmpi(nombreArchivo,nombreArchivoAux))///(parser_CachorroFromText(pArchivo, listaCachorro))

                {
                    system("cls");
                    if (controller_loadFromText(nombreArchivo, listaCachorro))
                    {
                        system("cls");
                        printf("\nEL ARCHIVO ESTA CARGADO CORRECTAMENTE, PUEDE CONTINUAR\n");
                        flag=1;
                    }

                }
                else
                {
                    system("cls");
                    printf("\nEL ARCHIVO NO EXISTE\n");
                }

                break;

            case 2:  ///LISTAR ORIGINAL, SIN TIPO MAPEADO




                if (flag)
                {

                    showCachorros(listaCachorro);
                }
                else
                {
                    printf("DEBE CARGAR ALGUN ARCHIVO\n");
                }


                break;

            case 3: ///mapear y filtrar

                if (flag)
                {
                    lista45Dias = ll_filter(listaCachorro, filter_45dias);///filtra y genera una nueva lista
                    controller_saveAsText("cachorros45dias.csv", lista45Dias);///guarda esa nueva lista en texto, con el nombre pasado como parametro

                    listaMachos = ll_filter(listaCachorro, filter_machos);///filtra y genera una nueva lista
                    controller_saveAsText("cachorrosMachos.csv", listaMachos); ///guarda esa nueva lista en texto, con el nombre pasado como parametro

                    listaCallejeros = ll_filter(listaCachorro, filter_callejeros);
                    controller_saveAsText("cachorros Callejeros.csv", listaCallejeros);

                    listaReservados = ll_filter(listaCachorro, filter_reservado);
                    controller_saveAsText("cachorros Reservados.csv", listaReservados);

                    system("cls");
                    printf("\nSE HA MAPEADO Y FILTRADO SEGUN PARAMETROS\n\n");
                }
                /*
                 pArraySubList = ll_filter(lista, employee_filterUnder45);
                controller_saveAsText("cachorros45.csv",pArraySubList);
                employee_printListOfEmployees(pArraySubList);
                */
                /*if (flag)
                    {
                        listaMapeada = ll_map(listaDominios, seteaTipo);
                        printf("\nSE HA MAPEADO LA LISTA ORIGINAL Y AGREGADO EL TIPO\n");

                    }*/
                break;

            case 4: ///printf("4. Listar cachorros filtrados por 45 dias\n");

                if(lista45Dias != NULL)
                {
                    system("cls");
                    printf("\nCACHORROS CON MAS DE 45 DIAS: \n\n");
                    showCachorros(lista45Dias);
                }
                else
                {
                    printf("\nERROR, TAL VEZ NO HAY ARCHIVOS CARGADOS.\n");
                }

                break;


            case 5:///printf("5. Listar cachorros filtrados por machos\n");

                if(listaMachos != NULL)
                {
                    system("cls");
                    printf("\nCACHORROS MACHOS: \n\n");
                    showCachorros(listaMachos);
                }
                else
                {
                    printf("\nERROR, TAL VEZ NO HAY ARCHIVOS CARGADOS.\n");
                }
                break;

            case 6:/// Listar cachorros filtrado por callejeros\n");


                if(listaCallejeros != NULL)
                {
                    system("cls");
                    printf("\nCACHORROS CALLEJEROSS: \n\n");
                    showCachorros(listaCallejeros);
                }
                else
                {
                    printf("\nERROR, TAL VEZ NO HAY ARCHIVOS CARGADOS.\n");
                }

                break;
            case 7:

                if (listaReservados!= NULL)
                {
                    system("cls");
                    printf("\n CACHORROS RESERVADOS: \n\n");
                    showCachorros(listaReservados);
                }

                break;

            case 8: ///SALIR
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

