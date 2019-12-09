#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Computer.h"
int main()
{
    LinkedList* listaComputadora=ll_newLinkedList();
    LinkedList* listaLaptop=ll_newLinkedList();



    int opcion;
    char nombreArchivo[31];
    while(opcion!=7){
   menu();
   getInt(&opcion,"\nDigite la opcion deseada : ","\nOpcion No valida",1,7);
    switch(opcion){
case 1:
    if(ll_len(listaComputadora)==0){
        getString(nombreArchivo,"\nintrodusca el nombre del archivo con su devida extencion ejemplo:\' archivo.csv\' :","\nfuera de rango",5,31);
                if(controller_loadFromText(nombreArchivo,listaComputadora)==1){
                        controller_printList(listaComputadora);
                    printf("\ncarga de Archivo exitosa \n\n");
                    printf("%d",ll_len(listaComputadora));
                    }
                    else{
                        printf("\nError en carga\n\n");
                    }}else{printf("\n\nArchivo previamete cargado\n");

                        }
    break;
case 2:
     if(ll_len(listaComputadora)!=0){
            ll_sort(listaComputadora,computer_comparacionPorTipo,1);
            controller_printList(listaComputadora);

     }else{printf("\nDeve cargar el archivo antes.\n");
     printf("\n\n\n");
        system("pause");
        system("cls");}
    break;
case 3:
   if(ll_len(listaComputadora)!=0){
       controller_printListTipo(listaComputadora);

     }else{printf("\nDeve cargar el archivo antes.\n");
     printf("\n\n\n");
        system("pause");
        system("cls");

     }
    break;
case 4:
  if(ll_len(listaComputadora)!=0){
     ll_map(listaComputadora,computer_mapTipo);
     controller_printList(listaComputadora);


        printf("\n\n\n");
        system("pause");
        system("cls");
       }

     else{printf("\nDeve cargar el archivo antes.\n");
     printf("\n\n\n");
        system("pause");
        system("cls");

     }
    break;
case 5:
    if(ll_len(listaComputadora)!=0){
    listaLaptop=ll_filter(listaComputadora,computer_filtrarLaptop);
    controller_printList(listaLaptop);


        printf("\n\n\n");
        system("pause");
        system("cls");
       }

     else{printf("\nDeve cargar el archivo antes.\n");
     printf("\n\n\n");
        system("pause");
        system("cls");

    break;
case 6:
    if(ll_len(listaLaptop)!=0){

        controller_saveAsText("filtrado.csv" , listaLaptop);
        printf("guardado exitosamente");
    }
    break;
    }


   }}

    return 0;
  }
