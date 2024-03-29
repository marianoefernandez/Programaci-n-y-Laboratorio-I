#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this=(LinkedList*)malloc(sizeof(LinkedList));///Si la lista es igual a la lista multiplicado el malloc del sizeof

    if(this!=NULL)///Si la lista es diferente de NULL
    {
        this->size=0;///Seteamos el size en 0
        this->pFirstNode=NULL;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    int len;

    Node* pNode=NULL;

    if(this!=NULL)///SI LA LISTA ES DISTINTA DE NULL, CALCULAMOS EL LEN
    {
        len = ll_len(this);///El len se saca con ll_len a la lista
        if(this!=NULL && nodeIndex>-1 && nodeIndex<len)///Si la lista es distinta de NULL y el indice del nodo es menor a 0 o mayor al tama�o que sacamos anteriormente se apunta al proxmimo nodo
        {
            pNode=this->pFirstNode;///EL NODO ES IGUAL A LA LISTA APUNTANDO AL PRIMER NODO

            for(i=0; i<nodeIndex; i++)///RECORREMOS EL INDICE CON UN FOR Y APUNTAMOS AL PROXIMO NODO
            {
                pNode= pNode->pNextNode;///Apuntamos al prox nodo
            }
        }
    }

    return pNode;///Retornamos el Nodo y si no existe retorna NULL como pusimos al principio
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    ///COMO SE AGREGA UN NODO

    int returnAux = -1;
    int len; ///TAMA�O DE LA LISTA

    Node* pNewNode=malloc(sizeof(Node));///DEFINIMOS DIN�MICAMENTE UN NUEVO NODO
    Node* pActualNode=NULL;///Nodo actual igual a NULL
    pNewNode->pElement=pElement;///Flechita del nuevo nodo a pElement = pElement

    if(this!=NULL && pNewNode!=NULL)
    {
        len=ll_len(this);///Definimos el largo del nodo con el ll_len
        if(nodeIndex>-1 && nodeIndex<=len)///Si el indice del nodo es mayor a -1 y el indice es mayor o igual al len
            if(nodeIndex==0)
        {
            pNewNode->pNextNode=this->pFirstNode;///El primer nodo agregado flechita a proximo nodo es igual a la lista flechita al primer nodo
            this->pFirstNode=pNewNode;
        }
        else
        {
            pActualNode=getNode(this,nodeIndex-1);
            pNewNode->pNextNode=pActualNode->pNextNode;
            pActualNode->pNextNode=pNewNode;
        }
        returnAux=0;
        this->size++;///AUMENTAMOS EL TAMA�O DE LA LISTA EN UNO
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;///SETEO EN -1

    if (this !=NULL)///PREGUNTO SI LA LISTA ES DISTINTA DE NULL
    {
        addNode(this,this->size,pElement);///AGREGA EL NODO
        returnAux=0;///RETORNAMOS 0
    }
    return returnAux;///RETORNAMOS 0 SI BIEN y -1 SI MAL
}

void* ll_get(LinkedList* this, int index)
{
    int len;
    void* returnAux = NULL;///SETEAMOS UN RETORNO A NULL
    Node* pNewNode;///DEFINIMOS UN PUNTERO A UN NUEVO NODO

    if (this != NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        len=ll_len(this);///CALCULAMOS EL LEN

        if(index>-1 && index<len)///SI EL INDICE ES MAYOR A -1 Y MENOR AL LEN
        {
            pNewNode=getNode(this,index);///OBTENEMOS EL NUEVO NODO EN EL INDICE QUE PUSIMOS PRINCIPALMENTE
            if(pNewNode!=NULL)///SI ESE NODO EXISTE O SEA QUE EL INDICE QUE PUSIMOS CORRESPONDE A UN NODO CARGADO
            {
                returnAux=pNewNode->pElement;///RETORNAMOS EL ELEMENTO (DIR DE MEMORIA) DEL NODO EN EL INDICE MARCADO
            }
        }
    }

    return returnAux;///RETORNAMOS ELEMENTO O NULL
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int len;
    void* returnAux = -1;///SETEAMOS UN RETORNO EN -1
    Node* pNewNode;///DEFINIMOS UN PUNTERO A UN NUEVO NODO

    if (this != NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        len=ll_len(this);///CALCULAMOS EL LEN

        if(index>-1 && index<len)///SI EL INDICE ES MAYOR O IGUAL A CERO Y MENOR AL LEN
        {
            pNewNode=getNode(this,index);///OBTENEMOS EL NUEVO NODO EN EL INDICE QUE PUSIMOS PRINCIPALMENTE
            if(pNewNode!=NULL)///SI ESE NODO EXISTE O SEA QUE EL INDICE QUE PUSIMOS CORRESPONDE A UN NODO CARGADO
            {
                pNewNode->pElement=pElement;///Le seteamos al nodo el valor que este en pElement
                returnAux=0;///RETORNAMOS 0 SI TODO OK
            }
        }
    }

    return returnAux;///RETORNAMOS ELEMENTO O NULL
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;///SETEAMOS EL RETORNO EN -1 POR SI NO HAY ESPACIO
    Node* n1;///NODO PRINCIPAL Y EL QUE VA A SER BORRADO
    Node* n2;///NODO QUE VA A CAMBIAR DE LUGAR

    if(this!=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        if (index>-1 && index<this->size)///PREGUNTAMOS SI EL INDEX ES MAYOR O IGUAL A CERO Y SI ES MENOR QUE EL SIZE
        {
            returnAux=0;

            if(this->size==1)///SI EL SIZE ES 1
            {
                this->pFirstNode=NULL;///APUNTAMOS EL PROXIMO NODO A NULL
                free(getNode(this,index));///Y LIBERAMOS EL NODO
            }
            else if (index==0)///SI EL INDICE ES CERO
            {
                n1=getNode(this,index);///OBTENEMOS EL NODO 1
                this->pFirstNode=n1->pNextNode;///EL PRIMER NODO ES IGUAL AL PROXIMO NODO
                free(n1);///Y LO LIBERAMOS
            }
            else///SI EL INDICE NO ES 0 NI EL SIZE ES 1
            {
                n1=getNode(this,index);///OBTENEMOS EL NODO 1
                if(n1 != NULL)///SI ES DISTINTO DE NULL
                {
                    n2=getNode(this,index-1);///OBTENEMOS EL NODO 2 CON EL INDICE MENOS 1
                    n2->pNextNode=n1->pNextNode;///CONVERTIMOS EL NODO DOS EN EL NODO UNO (POS MEMORIA)
                    free(n1);///LIBERAMOS EL NODO 1
                }
            }
        }
        this->size--;///REDUCIMOS EL SIZE EN UNO
    }
    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int len;
    int i;
    int returnAux = -1;///SETEAMOS RETORNO EN -1

    if(this!=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
    len=ll_len(this);///CALCULAMOS EL TAMA�O
     for(i=0;i<len;i++)///RECORREMOS LA LISTA
     {
         ll_remove(this,i);///Y BORRAMOS CADA INDICE
     }
     returnAux=0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux=-1;///SETEAMOS RETORNO EN -1
    if (this !=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        if (ll_clear(this)==0)///SI EL CLEAR ES IGUAL A CERO
        {
            free(this);///LIBERAMOS LA LISTA
        }
        returnAux=0;
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux=-1;///SETEAMOS RETORNO EN -1
    int i;
    int len;
    Node* pNodo=NULL;///HACEMOS UN PUNTERO A NODO Y LO IGUALAMOS EN NULL

    if (this!=NULL)
    {
        len=ll_len(this);///CALCULAMOS EL LEN

        for(i=0;i<len;i++)///RECORREMOS LA LISTA
        {
            pNodo = getNode(this,i);///OBTENEMOS EL NODO
            if (pNodo->pElement==pElement)///SI INDICE INGRESADO ES IGUAL AL INDICE DEL NODO
            {
                returnAux=i;///AGREGAMOS EL INDICE AL RETORNO
                break;///CORTAMOS EL PROGRAMA
            }
        }
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)///Simplemente verificamos con el tama�o
{
    int returnAux = -1;///SETEAMOS EL RETORNO EN -1
    int len;

    if (this!=NULL)///PREGUNTAMOS SI LA LISTA ES DISTINTA DE NULL
    {
        len=ll_len(this);///CALCULAMOS LEN

        if (len==0)
        {
            returnAux=1;///ESTA VACIA
        }
        else
        {
            returnAux=0;///NO ESTA VACIA
        }
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;///SETEAMOS RETORNO EN -1
    Node* pNode;///PUNTERO A NODO
    int len;

    if (this!=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        len=ll_len(this);///CALCULAMOS EL TAMA�O
        if (index>-1 && index<=len)///SI EL INDICE ES MAYOR A -1 Y MENOR/IGUAL AL LEN
        {
            pNode=addNode(this,index,pElement);///A�ADIMOS NODO EN EL QUE VAMOS A PUSHEAR
            returnAux=0;
        }
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;///SETEAMOS RETORNO EN NULL
    int len;

    if (this!=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        len=ll_len(this);///CALCULAMOS TAMA�O
        if(index>-1 && index<=len)///SI EL INDICE ES MAYOR A -1 Y MENOR/IGUAL AL LEN
        {
            returnAux=ll_get(this,index);///GUARDAMOS EN EL RETORNO EL NODO QUE VAMOS A ELIMINAR
            ll_remove(this,index);///LO BORRAMOS DE LA LISTA
        }
    }

    return returnAux;///RETORNAMOS NODO BORRADO
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;///SI DA ERROR

    if (this!=NULL)
    {
        if(ll_indexOf(this,pElement)==-1)///SI EL NODO NO EXISTE
        {
            returnAux=0;///SI NO LO ENCUENTRA
        }
        else///SI EL NODO EXISTE
        {
            returnAux=1;///SI LO ENCUENTRA
        }
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;///SETEAMOS RETORNO EN -1
    int i;
    int len1;
    int len2;
    int contador=0;///CONTADOR

    void* pElementAux;///PUNTERO A VOID AUX EN EL QUE GUARDAMOS CADA VALOR QUE PASA POR EL FOR

    if (this!=NULL && this2!=NULL)///SI LAS DOS LISTAS SON DISTINTAS DE NULL EJECUTO EL IF
    {
        len1=ll_len(this);///CALCULO LEN DE LISTA 1
        len2=ll_len(this2);///CALCULO LEN DE LISTA 2
        returnAux=0;///SETEO EL RETORNO EN 0 YA QUE NO DA ERROR PERO TODAVIA NO SE SABE SI SON IGUALES O NO

        if (len1>=len2)///SI LEN1 ES MAYOR O IGUAL O SEA, LEN2 JAM�S PODRIA SER MAYOR A LA PRIMERA PORQUE J�MAS SE PODRIAN COMPARAR
        {
            for(i=0;i<len2;i++)///HACEMOS UN FOR CON LEN2
            {
                pElementAux=ll_get(this2,i);///GUARDAMOS EN EL AUXILIAR CADA ELEMENTO DE CADA DATO
                if(ll_contains(this,pElementAux)==1)///SI ESE MISMO ELEMENTO PERTENECE A LA LISTA 1
                {
                    contador++;///SUMO AL CONTADOR
                }
            }
            if(contador==len1)///SI EL CONTADOR ES IGUAL AL LARGO DE LA LISTA 1, SIGNIFICA QUE CONTIENEN LOS MISMOS ELEMENTOS O SEA SON IGUALES
            {
                returnAux=1;///ENTONCES COMO SON IGUALES RETORNAMOS 1
            }
        }

    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int i;
    int newListIndex=0;///ACA SE GUARDA CUANTO VA A SER EL TAMA�O DE LA LISTA AL FINAL
    int len;

    LinkedList* cloneArray = NULL;///CREAMOS UN CLON DE LA LISTA SETEADO EN NULL
    Node* pNode;///HACEMOS UN PUNTERO AL NODOOO

    if (this!=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        len=ll_len(this);///CALCULAMOS EL LEN
        if (from>-1 && from<=len && to>-1 && to<=len)///EL VALOR DESDE Y HASTA DONDE QUE DAMOS EN LA FUNCION TIENEN QUE SER MAYORES A -1 Y MENOR O IGUAL AL LEN
        {
            cloneArray=ll_newLinkedList();///AL CLON LE CREAMOS UNA NUEVA LISTA
            for(i=from;i<to;i++)///FROM ES EL QUE ARRANCA EL FOR Y TO EL QUE LO TERMINA
            {
                pNode=getNode(this,i);///OBTENEMOS EL NODO
                if(pNode!=NULL)///SI EL NODO ES DISTINTO DE NULL
                {
                    pNode=addNode(cloneArray,newListIndex,pNode->pElement);///LO AGREGAMOS A LA LISTA CLONADA, EL ELEMENTO ES EL NODO->ELEMENTO
                    newListIndex++;///Y HACEMOS ++ DEL INDICE PARA QUE NO AGREGUE SIEMPRE EL MISMO VALOR
                }
            }
        }
    }

    return cloneArray;///RETORNAMOS EL ARRAY CLONADO
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;///SETEAMOS EL VALOR DE LA LISTA CLONADA EN NULL

    if (this!=NULL)///SI LA LISTA ORIGINAL ES DISTINTA DE NULL
    {
        cloneArray=ll_subList(this,0,this->size);///CLONAMOS TODA LA LISTA, PASANDO TODOS LOS DATOS DE LA LISTA ORIGINAL A LA NUEVA GRACIAS AL SUBLIST
    }
    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;///SETEAMOS EL RETORNO EN -1
    int i;
    int len;
    int flag;

    void* pElementA;///PUNTERO A PRIMER ELEMENTO
    void* pElementB;///PUNTERO A SEGUNDO ELEMENTO
    void* pElementAux;///PUNTERO AUX A ELEMENTO

    if(this!=NULL)///SI LA LISTA ES DISTINTA DE NULL
    {
        if(pFunc!=NULL)///SI EL PUNTERO A FUNCION ES DISTINTO A FUNCION
        {
            if(order==0 || order ==1)
            {
                len=ll_len(this);///CALCULAMOS EL TAMA�O
                if(len>0)///SI EN LA LISTA EXISTE AL MENOS UN ELEMENTO
                {
                    do
                    {
                        flag=0;///PONEMOS EL FLAG EN 0
                        for(i=0;i<len-1;i++)
                        {
                            pElementA=ll_get(this,i);///OBTENEMOS EL ELEMENTO 1
                            pElementB=ll_get(this,i+1);///OBTENEMOS EL ELEMENTO 2 i+1
                            if ((pFunc(pElementA,pElementB)<0 && order == 0) || (pFunc(pElementA,pElementB)>0 && order == 1))///SI EL PUNTERO A FUNCION ES ASC O DESC
                            {
                                pElementAux= pElementA;///HACEMOS EL CLASICO SWAP DEL ORDENAMIENTO Aux = A / A=B / B = aux
                                ll_set(this,i,pElementB);
                                ll_set(this,i+1,pElementAux);
                                flag= 1;///SETAMOS FLAG EN UNO CUANDO TERMINE EL SWAP
                            }
                            returnAux=0;
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
    int len;
    void* pElementAux;
    LinkedList* nuevaSubLista;

    if(lista != NULL)
    {
        if(*pFunc != NULL)
        {
            nuevaSubLista= ll_newLinkedList();
            len= ll_len(lista);

            for(i=0; i<len; i++)
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

int ll_map(LinkedList* this, void (*pFunc)(void *))
{
    int i;
    int ret=0;

    if(this != NULL && pFunc != NULL)
    {
        for(i=0; i< ll_len(this) ; i++)
        {
            pFunc(ll_get(this,i));
        }
        ret=1;
    }

    return ret;
}

int ll_count(LinkedList* this, void (*pFunc)(void *))
{
    int i;
    int contador;
    int acumulador=0;

    if(this != NULL && pFunc != NULL)
    {
        for(i=0; i< ll_len(this) ; i++)
        {
            contador=pFunc(ll_get(this,i));
            acumulador=acumulador+contador
        }
    }

    return acumulador;
}

