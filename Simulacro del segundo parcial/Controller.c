#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "llamados.h"
#include "Controller.h"
#include "inputs.h"

//Carga el texto abriendo el archivo en modo lectura, path se usa para el nombre del archivo a usar, se parsea y lee
int controller_loadFromText(char* path , LinkedList* lista)
{
    FILE* pArchivo;

    int ret = 0;

    if(pArchivo!=NULL)
    {
        pArchivo=fopen(path, "r");
        parser_EmployeeFromText(pArchivo,lista);
        ret = 1;
    }
    fclose(pArchivo);

    return ret;
}

int controller_ListEmployee(LinkedList* pLista)
{
    llamada* pLlamado;

    int ret = 0;
    int i;
    int id;
    eFecha fecha;
    int numCliente;
    int idProblema;
    char* problema;
    char* solucion;

    if(pLista != NULL)
    {
        printf("\n\nID Llamada-- \t\t   Fecha \t\t Numero Cliente \t\Id Problema \t\Solucionado \n\n");
        ret =1;

        for(i=0; i < ll_len(pLista); i++)
        {
            pLlamado = ll_get(pLista,i);
            llamada_getId(pLista,&id);
            llamada_getFecha(pEmpleado, fecha->dia,fecha->mes,fecha->anio);
            llamada_getNumeroCliente(pEmpleado,&numCliente);
            llamada_getIdProblema(pLista,&idProblema);
            llamada_getSolucion(pLista, solucion);

            switch (idProblema)
            {
                case 1:
                    strcpy(problema,"No enciende PC");
                    break;

                case 2:
                    strcpy(problema,"No funciona mouse");
                    break;

                case 3:
                    strcpy(problema,"No funciona teclado");
                    break;

                case 4:
                    strcpy(problema,"No hay internet");
                    break;

                case 5:
                    strcpy(problema,"No funciona telefono");
                    break;

            }
            printf("%d -- %d/%d/%d %20d %20s, %s \n\n", id,fecha->dia,fecha->mes,fecha->anio, numCliente, probl, solucion);
        }
    }
    return ret;
}

int controller_saveAsText(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    llamados* llamadoAux;

    int ret = 0;
    int* idAux;
    eFecha* fechaAux;
    int* numClienteAux;
    int* idProblemaAux;
    int idProblema;
    char* solucionAux;
    int i;


    idProblema=getInt("\nIngrese un numero de problema: ");

    while(idProblema>5 && idProblema<1)
    {
        idProblema=getInt("\nERROR SOLO NUM DEL 1 AL 5 \n Ingrese el numero de problema: ");
    }

    if(lista != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        fechaAux->dia = malloc(sizeof(int));
        fechaAux->mes = malloc(sizeof(int));
        fechaAux->anio = malloc(sizeof(int));
        solucion = malloc(sizeof(char)*20);
        idProblemaAux = malloc(sizeof(int));
        numClienteAux = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i< ll_len(lista); i++)
        {
            pLlamado = ll_get(pLista,i);
            llamada_getId(pLista,&idAux);
            llamada_getFecha(pEmpleado, fechaAux->dia,fechaAux->mes,fechaAux->anio);
            llamada_getNumeroCliente(pEmpleado,&numClienteAux);
            llamada_getIdProblema(pLista,&idProblemaAux);
            llamada_getSolucion(pLista, solucionAux);

            if (idProblema=idProblemaAux)
            {
                fprintf(pArchivo,"%d,%d/%d/%d,%d,%d,%s\n",*idAux,fechaAux->dia,fechaAux->mes,fechaAux->anio,*numClienteAux,idProblemaAux,solucionAux);
            }
        }

        free(idAux);
        free(fechaAux);
        free(numClienteAux);
        free(idProblemaAux);
        free(solucionAux);
        fclose(pArchivo);
        ret = 1;
    }
    return ret;
}

