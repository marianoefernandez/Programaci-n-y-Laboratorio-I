#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Computer.h"
/** \brief Crea un puntero a un nuevo elemento
 *
 * \param
 * \param
 * \return puntero al nuevo elemento
 *
 */

eComputer* computer_new()
{
    eComputer* newComputer = (eComputer*)malloc(sizeof(eComputer));
    if(newComputer!=NULL)
    {
        newComputer->id=0;
        strcpy(newComputer->descripcion," ");
        newComputer->precio=0;
        newComputer->idtipo=0;
        return newComputer;
    }
    return 0;
}
/** \brief Setea los parametros que sean cargado de un archivo.
 *
 * \param char idStr
 * \param char descripcionStr
 * \param char precioStr
 * \param char tipoStr
 * \return puntero al elemento
 *
 */

eComputer* computer_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* tipoStr)
{
    eComputer* newComputer=computer_new();
    int r=0;

    if(newComputer!=NULL)
    {
        if(computer_setId(newComputer,atoi(idStr)))
        {


            if(computer_setDescripcion(newComputer,descripcionStr))
            {


                if(computer_setPrecio(newComputer,atoi(precioStr)))
                {
                    if(computer_setTipo(newComputer,atoi(tipoStr)))
                    {

                        r=1;
                    }
                }
            }
        }
        if(r == 0)
        {
            //free(newComputer);
            //newComputer = NULL;
        }


    }
    return newComputer;
}
/** \brief setea el id de computadoa
 *
 * \param this
 * \param id
 * \return int 0
 *
 */

int computer_setId(eComputer* this,int id)
{

    int r=0;
    if(this!=NULL)
    {
        this->id=id;
        r=1;

    }
    return r;
}

int computer_setDescripcion(eComputer* this,char* descripcion)
{
    int r=0;
    if(this!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        r=1;
    }
    return r;
}

int computer_setPrecio(eComputer* this,int precio)
{

    int r=0;
    if(this!=NULL)
    {
        this->precio=precio;
        r=1;
    }
    return r;
}

int computer_setTipo(eComputer* this,int tipo)
{

    int r=0;
    if(this!=NULL)
    {

        this->idtipo=tipo;
        r=1;
    }
    return r;
}

int computer_comparacionPorTipo(void* ComputerA, void* ComputerB)
{
    int aux=0;
    eComputer* auxA=(eComputer*)ComputerA;
    eComputer* auxB=(eComputer*)ComputerB;

    if(auxA->idtipo>auxB->idtipo)
    {
        aux=1;
    }
    else if(auxA->idtipo<auxB->idtipo)
    {

        aux=-1;
    }
    else
    {
        aux=0;
    }

    return aux;
}

void computer_mapTipo(void* pElement)
{

    eComputer* aux;
    int auxtipo;


    if(pElement != NULL)
    {
        aux = (eComputer*) pElement;

        computer_getComputer(aux,auxtipo);

        if(aux->idtipo==1)
        {

            computer_setPrecio(aux,aux->precio*1.1);

        }
        else
        {
            computer_setPrecio(aux,aux->precio*1.2);

        }

    }
   // return retorno;
}

int computer_getComputer(eComputer* this,int* precio)
{
    int retorno =0;

    if(this != NULL && precio!=NULL)
    {

        precio=this->precio;


        retorno=1;
    }

    return retorno;
}

int computer_filtrarLaptop(void* p){

    int ok = 0;
    eComputer* tipoC;
    if(p != NULL){

        tipoC = (eComputer*) p;

        if(tipoC->idtipo == 2 ){
            ok = 1;
        }
    }

    return ok;

}
