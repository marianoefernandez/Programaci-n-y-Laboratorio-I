#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"

#include "Computer.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeComputadora)
{

FILE *pFile;
int r=0;

pFile = fopen(path,"r");
    if(pFile != NULL)
    {
   parser_ComputadoraFromTex(pFile ,pArrayListeComputadora);
    fclose(pFile);
    r=1;
    }
    else{
            printf("El archivo no existe");

    r=-1;
    }

return r;
}
/** \brief impreme elementos en de una linkedlist
 *
 * \param recive puntero a linkedlist pArrayListeComputadora
 * \param
 * \return
 *
 */

void controller_printList(LinkedList* pArrayListeComputadora){
int i;
 for(i=0;i<ll_len(pArrayListeComputadora);i++){
    eComputer* newlistado=computer_new();

    newlistado=ll_get(pArrayListeComputadora,i);
        printf("\n%5d %10s %10d %5d",newlistado->id,newlistado->descripcion,newlistado->precio,newlistado->idtipo);

}
printf("\n\n\n");
system("pause");
        system("cls");

}
/** \brief Guarda modo Texto los elementos de la linked
 *
 * \param path que es el nombre y lugar donde se guada un archivo
 * \param pArraylisteComputdpa
 * \return 0 si el puntero archivo, 1 si guado ok -1 si el archivo no existe
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListeComputadora)
{
    int i,r=0;
    int Id,precio,tipo;
    char descripcion[256];

    eComputer* listComputer=computer_new();
    FILE* pFile;
    pFile = fopen(path,"w");
      if(pFile != NULL)
    {
        for(i=0;i<ll_len(pArrayListeComputadora);i++){

        listComputer=ll_get(pArrayListeComputadora,i);
        Id=listComputer->id;
        strcpy(descripcion,listComputer->descripcion);
        precio=listComputer->precio;
        tipo=listComputer->idtipo;

        fprintf(pFile,"\n%d,%s,%d,%d",Id,descripcion,precio,tipo);

    } fclose(pFile);
    r=1;
    }else{
            printf("El archivo no existe");

    r=-1;

    }
    return r;
}
/** \brief imprime una lista con el tipo que cambia el tipo de dato de numero a Descriocion laptop o desktop
 *
 * \param pArrayLiseComputadora
 * \param
 * \return void
 *
 */

void controller_printListTipo(LinkedList* pArrayListeComputadora){
int i;
 for(i=0;i<ll_len(pArrayListeComputadora);i++){
    eComputer* newlistado=computer_new();

    newlistado=ll_get(pArrayListeComputadora,i);
        printf("\n%5d %10s %10d",newlistado->id,newlistado->descripcion,newlistado->precio);
        if(newlistado->idtipo==1){
            printf("=>DESKTOP");
        }else{printf("=>LAPTOP");}
}
printf("\n\n\n");
system("pause");
        system("cls");

}
