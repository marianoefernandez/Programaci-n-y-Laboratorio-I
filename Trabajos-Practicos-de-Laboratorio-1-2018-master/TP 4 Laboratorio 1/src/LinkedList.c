#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


/********************* DOCUMENTACION EN EL .H **********************/

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this= (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size= 0;
        this->pFirstNode= NULL;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux= -1;
    if(this != NULL)
    {
        returnAux= this->size;
    }
    return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    int tam;
    Node* pNode = NULL;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(this!= NULL && nodeIndex>=0 && nodeIndex<tam)
        {
            pNode= this->pFirstNode;
            for(i=0; i<nodeIndex; i++)
            {
                pNode= pNode->pNextNode;
            }
        }
    }
    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux= -1;
    int tam;

    Node* pNewNode= malloc(sizeof(Node));
    Node* pActualNode= NULL;
    pNewNode->pElement=pElement;

    if(this!= NULL && pNewNode!= NULL)
    {
        tam= ll_len(this);
        if(nodeIndex>=0 && nodeIndex<= tam)
        {
            if(nodeIndex==0)
            {
                pNewNode->pNextNode= this->pFirstNode;
                this->pFirstNode= pNewNode;
            }
            else
            {
                pActualNode= getNode(this,nodeIndex-1);
                pNewNode->pNextNode= pActualNode->pNextNode;
                pActualNode->pNextNode= pNewNode;
            }
            returnAux= 0;
            this->size++;
        }
    }
    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux= -1;
    if(this != NULL)
    {
        returnAux= addNode(this, this->size, pElement);
    }
    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{
    int tam;
    void* returnAux = NULL;
    Node* pNewNode;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<tam)
        {
            pNewNode= getNode(this, index);
            if(pNewNode != NULL)
            {
                returnAux= pNewNode->pElement;
            }
        }
    }
    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
    int tam;
    int returnAux= -1;
    Node* pNewNode;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<tam)
        {
            pNewNode= getNode(this, index);
            if(pNewNode != NULL)
            {
                pNewNode->pElement= pElement;
                returnAux= 0;
            }
        }
    }
    return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux= -1;

    Node *pNodeUno;
    Node *pNodeDos;

    if(this!= NULL)
    {
        if(index>=0 && index<this->size)
        {
            returnAux= 0;
            if(this->size == 1)
            {
                this->pFirstNode= NULL;
                free(getNode(this,index));
            }
            else if(index == 0)
            {
                pNodeUno= getNode(this,index);
                this->pFirstNode= pNodeUno->pNextNode;
                free(pNodeUno);
            }
            else
            {
                pNodeUno= getNode(this,index);
                if(pNodeUno != NULL)
                {
                    pNodeDos= getNode(this,index-1);
                    pNodeDos->pNextNode= pNodeUno->pNextNode;
                    free(pNodeUno);
                }
            }
        }
        this->size--;
    }
    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int i;
    int tam;
    int returnAux= -1;

    if(this != NULL)
    {
        tam= ll_len(this);
        for(i=0; i<tam; i++)
        {
            ll_remove(this,i);
        }
        returnAux= 0;
    }
    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux= -1;
    if(this != NULL)
    {
        if(ll_clear(this) == 0)
        {
            free(this);
            returnAux= 0;
        }
    }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int i;
    int tam;
    int returnAux= -1;

    Node* pNode= NULL;

    if(this != NULL)
    {
        tam= ll_len(this);
        for(i=0; i<tam; i++)
        {
            pNode= getNode(this,i);
            if(pNode->pElement == pElement)
            {
                returnAux= i;
                break;
            }
        }
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int tam;
    int returnAux= -1;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(tam == 0)
        {
            returnAux= 1;
        }
        else
        {
            returnAux= 0;
        }
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux= -1;
    int tam;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<=tam)
        {
            returnAux= addNode(this, index, pElement);
        }
    }
    return returnAux;
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux= NULL;
    int tam;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<=tam)
        {
            returnAux= ll_get(this, index);
            ll_remove(this, index);
        }
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux= -1;
    if(this != NULL)
    {
        if (ll_indexOf(this, pElement) == -1)
        {
            returnAux= 0;
        }
        else
        {
            returnAux= 1;
        }
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int i;
    int lenUno;
    int lenDos;
    int returnAux= -1;
    int contador= 0;

    void* pElementAux;

    if(this!=NULL && this2!=NULL)
    {
        lenUno= ll_len(this);
        lenDos= ll_len(this2);

        returnAux=0;

        if(lenUno >= lenDos)
        {
            for(i=0 ; i<lenDos; i++)
            {
                pElementAux= ll_get(this2, i);
                if(ll_contains(this, pElementAux) == 1)
                {
                    contador++;
                }
            }
            if(contador==lenUno)
            {
                returnAux= 1;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int i;
    int tam;
    int nuevaLista= 0;

    Node* pNode;
    LinkedList* cloneArray= NULL;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(from>=0 && from<=tam && to>=0 && to<=tam)
        {
            cloneArray= ll_newLinkedList();
            for(i=from; i<to; i++)
            {
                pNode= getNode(this, i);
                if(pNode != NULL)
                {
                    addNode(cloneArray, nuevaLista, pNode->pElement);
                    nuevaLista++;
                }
            }
        }
    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray= NULL;
    if(this != NULL)
    {
        cloneArray= ll_subList(this, 0, this->size);
    }
    return cloneArray;
}


int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int i;
    int tam;
    int flag;
    int returnAux= -1;

    void* pElementA;
    void* pElementB;
    void* pElementAux;

    if(this != NULL)
    {
        if(pFunc != NULL)
        {
            if(order==0 || order==1)
            {
                tam= ll_len(this);
                if(tam > 0)
                {
                    do
                    {
                        flag= 0;
                        for(i=0; i<tam-1; i++)
                        {
                            pElementA= ll_get(this,i);
                            pElementB= ll_get(this,i+1);
                            if((pFunc(pElementA, pElementB) <0 && order==0) || (pFunc(pElementA, pElementB) >0 && order==1))
                            {
                                pElementAux= pElementA;
                                ll_set(this,i,pElementB);
                                ll_set(this,i+1,pElementAux);
                                flag= 1;
                            }
                            returnAux= 0;
                        }
                    }while(flag);
                }
            }
        }
    }
    return returnAux;
}



LinkedList* ll_filter(LinkedList* lista, int(*pFunc)(void*))
{
    int i;
    int tam;
    void* pElementAux;
    LinkedList* nuevaSubLista;

    if(lista != NULL)
    {
        if(*pFunc != NULL)
        {
            nuevaSubLista= ll_newLinkedList();
            tam= ll_len(lista);

            for(i=0; i<tam; i++)
            {
                pElementAux= ll_get(lista,i);
                if(pFunc(pElementAux) == 1);
                {
                    ll_add(nuevaSubLista,pElementAux);
                }
            }
        }
    }
    return nuevaSubLista;
}
