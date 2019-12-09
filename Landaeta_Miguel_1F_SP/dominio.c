#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "dominio.h"

eDominio* dominio_new()
{
    eDominio* newDominio = (eDominio*)malloc(sizeof(eDominio));
    if(newDominio!=NULL)
    {
        newDominio->id=0;
        strcpy(newDominio->dominio," ");
        newDominio->anio=0;
        newDominio->tipo=' ';
        return newDominio;
    }
    return 0;
}

eDominio* dominio_newParametros(char* idStr,char* dominioStr,char* anioStr)
{
    eDominio* newDominio=dominio_new();
    int r=0;

    if(newDominio!=NULL)
    {
        if(dominio_setId(newDominio,atoi(idStr)))
        {


            if(dominio_setDominio(newDominio,dominioStr))
            {


                if(dominio_setAnio(newDominio,atoi(anioStr)))
                {

                        r=1;

                }
            }
        }
        if(r == 0)
        {
            free(newDominio);
            newDominio = NULL;
        }


    }
    return newDominio;
}

int dominio_setId(eDominio* this,int id)
{
    int r=0;
    if(this!=NULL)
    {
        this->id=id;
        r=1;
    }
    return r;
}

int dominio_setDominio(eDominio* this,char* dominio)
{

    int r=0;
    if(this!=NULL)
    {
        strcpy(this->dominio,dominio);
        r=1;
    }
    return r;
}
int dominio_setAnio(eDominio* this,int anio)
{
    int r=0;
    if(this!=NULL)
    {

        this->anio=anio;
        r=1;
    }
    return r;
}

int dominio_setTipo(eDominio* this,char tipo)
{
    int retorno =0;

    if(this != NULL )
    {
        this->tipo = tipo;
        retorno=1;
    }

    return retorno;
}
void dominio_mapTipo(void* pElement)
{
    //int retorno = -1;
    eDominio* aux;
    char auxDominio[20];


    if(pElement != NULL)
    {
        aux = (eDominio*) pElement;

        dominio_getDominio(aux,auxDominio);

        if(aux->dominio[0]<'0' || aux->dominio[0]>'9')
        {

            dominio_setTipo(aux,'A');
           // retorno=1;
        }
        else
        {
            dominio_setTipo(aux,'M');
           // retorno=1;
        }

    }
   // return retorno;
}
int dominio_getDominio(eDominio* this,char* dominio)
{
    int retorno =0;

    if(this != NULL && dominio!=NULL)
    {
        strcpy(dominio,this->dominio);

        retorno=1;
    }

    return retorno;
}

int dominio_filtrarMotos(void* p){

    int ok = 0;
    eDominio* dominio;
    if(p != NULL){

        dominio = (eDominio*) p;

        if(dominio->tipo != 'A'){
            ok = 1;
        }
    }

    return ok;

}

int dominio_filtrarAutos(void* p){

    int ok = 0;
    eDominio* dominio;
    if(p != NULL){

        dominio = (eDominio*) p;

        if(dominio->tipo != 'M'){
            ok = 1;
        }
    }

    return ok;

}
