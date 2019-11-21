#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "llamados.h"
#include "parser.h"


int parser_llamados(FILE* pArchivo, LinkedList* pLista)
{
    llamados* pLlamados;

    char idAux[20];
    char diaAux[20];
    char mesAux[20];
    char anioAux[20];
    char numeroClienteAux[20];
    char idProblemaAux[20];
    char solucionAux[20];

    int ret = 1;
    int flag = 0;

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            if(flag)
            {
                fscanf(pArchivo, "%[^,],%[^,]%[^,]%[^,],%[^,],%[^\n]\n", idAux, diaAux, mesAux,anioAux, numeroClienteAux, idProblemaAux, solucionAux);
                flag = 1;
            }

            fscanf(pArchivo, "%[^,],%[^,]%[^,]%[^,],%[^,],%[^\n]\n", idAux, diaAux, mesAux,anioAux, numeroClienteAux, idProblemaAux, solucionAux);
            printf("%s - %s/%s/%s - %s - %s - %s\n", idAux, diaAux, mesAux,anioAux, numeroClienteAux, idProblemaAux, solucionAux);
            pLlamados = new_llamadoParametros(idAux, diaAux, mesAux,anioAux, numeroClienteAux, idProblemaAux, solucionAux);
            flag = 1;

            if(pLlamados != NULL)
            {
                ll_add(pLista, pLlamados);
                ret = 0;
            }
        }
    }
    return ret;
}
