#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"
#include <string.h>

/** \brief Parsea los datos los datos de los Equipos de computadora desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeComputadoras LinkedList*
 * \return int
 *
 */
int parser_ComputadoraFromTex(FILE* pFile, LinkedList* pArrayListeComputadora)
{

    int p;

    eComputer* newComputer;
    char var[4][256];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", var[0],var[1],var[2],var[3]);

    do
    {

        p = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", var[0],var[1],var[2],var[3]);
      //  printf("%s %s %s %s",var[0],var[1],var[2],var[3]);
        if(p==4)
        {


            if(newComputer!=NULL)
            {

              // printf("got here2");

                newComputer=computer_newParametros(var[0],var[1],var[2],var[3]);
                ll_add(pArrayListeComputadora,newComputer);
            }
        }
        else
        {
            break;
        }

    }
    while(!feof(pFile));

    return 1;
}


