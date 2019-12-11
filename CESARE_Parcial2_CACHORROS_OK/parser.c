#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include "LinkedList.h"
#include "Dominio.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_CachorroFromText(FILE* pFile, LinkedList* pArrayLinkedCachorros)
{
    int result = 0;
    char buffer[6][30];
    int cant;

    eCachorro* cacho= NULL;

    if(pFile != NULL && pArrayLinkedCachorros != NULL)
    {

        cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

            if(cant == 6)
            {
                cacho = newCachorro_Parametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

                if(cacho != NULL)
                {

                    ll_add(pArrayLinkedCachorros,cacho);
                    result = 1;
                }
            }
            else
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int parser_DominioFromBinary(FILE* pFile, LinkedList* pArrayLinkedDominio)
{
    int result = 0;
    int cant;
    eDominio* dom = NULL;

    if(pFile != NULL && pArrayLinkedDominio != NULL)
    {
        while(!feof(pFile))
        {
            dom = newDominio();
            if(dom != NULL)
            {
                cant = fread(dom,sizeof(eDominio),1,pFile);

                if(cant == 1)
                {

                    ll_add(pArrayLinkedDominio,dom);
                    result = 1;
                }
                else
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    else
                    {
                        result = 0;
                        break;
                    }
                }
            }

        }
    }

    return result;
}*/
