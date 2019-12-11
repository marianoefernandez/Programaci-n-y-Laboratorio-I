#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Dominio.h"



//NO VALIDAR pELEMENT
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)///te devuelve uu puntero a linkedlist
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)///si es ditinto de NULL
    {
        this->size=0;///te lo crea, en tama�o 0 y puntero al primer nodo em NULL
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;///devuelve el valor del tama�o
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* thisIs, void* pElement)
{
    int returnAux = -1;
    if(thisIs!=NULL)
    {
        addNode(thisIs,ll_len(thisIs),pElement);
        return 0;
    }

    return returnAux;
}



/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) //no validar p Element
{
    int returnAux = -1;
    if(this!=NULL)
    {

        Node* nodoNew=(Node*)malloc(sizeof(Node*));
        Node* nodoAnt=(Node*)malloc(sizeof(Node*));
        Node* nodoSig=(Node*)malloc(sizeof(Node*));

        if(nodeIndex==0)
        {
            if(ll_len(this)==0) ///si len es igual a 0 o sea esta vacio
            {
                nodoNew->pElement = pElement;///el puntero a elemento se carga en elemento del NodoNew
                nodoNew->pNextNode = NULL;///el sgte esta vacio, solo tengo el primero, por eso el pNextnode es NULL
            }
            else
            {
                nodoSig=this->pFirstNode;///sino estaba vacio, nodoSig se carga como primer nodo
                nodoNew->pElement=pElement;///elemento del nodonew, se carga con el elemento pasado
                nodoNew->pNextNode=nodoSig;///
            }
            this->pFirstNode=nodoNew;
        }
        else
        {
            nodoAnt=getNode(this,nodeIndex-1);///nodoAnt se va a cargar con el valor de ultimo nodo

            if(nodeIndex == ll_len(this))
            {
                nodoNew->pElement = pElement;
                nodoNew->pNextNode = NULL;
                nodoAnt->pNextNode = nodoNew;
            }
            else
            {
                nodoSig= getNode(this, nodeIndex + 1);
                nodoNew->pElement = pElement;
                nodoNew->pNextNode = nodoSig;
                nodoAnt->pNextNode = nodoNew;
            }
        }

        this->size++;///el len se basa en este size para medir el tama�o

        returnAux=0;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)///obtener un nodo para usarlo para algo
{
    Node* pNode = NULL;

    if(this!=NULL)
    {
        if(nodeIndex>=0 && nodeIndex<ll_len(this))
        {
            pNode=this->pFirstNode;

            while(nodeIndex>0)
            {
                pNode=pNode->pNextNode;
                nodeIndex--;
            }
        }
    }
    return pNode;
}



/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}




/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* thisIs, int index)
{
    void* returnAux = NULL;
    //  Node* nodo;

    if(thisIs!=NULL)
    {
        if(index>=0 && index<ll_len(thisIs))
        {

            returnAux=getNode(thisIs,index)->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* thisIs, int index,void* pElement)//no validar p Element
{
    int returnAux = -1;
    Node* nodo=(Node*)malloc(sizeof(Node*));
    if(thisIs!=NULL)
    {
        if(index>=0 && index<ll_len(thisIs))
        {
            nodo=getNode(thisIs,index);
            nodo->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* thisis,int index)
{

    int returnAux=-1;

    Node* nodo=getNode(thisis, index);
    Node* nodoAnt=getNode(thisis, index-1);

    if(thisis!=NULL && index>=0 && index <ll_len(thisis))
    {

        if(index==0 && ll_len(thisis)==1)
        {
            thisis->pFirstNode=NULL;
            free(nodo);
            thisis->size--;
            returnAux=0;
        }
        else if(index==ll_len(thisis)-1)
        {

            nodoAnt->pElement=NULL;
            free(nodo);
            thisis->size--;
            returnAux=0;

        }
        else
        {
            nodoAnt->pNextNode=nodo->pNextNode;
            free(nodo);
            thisis->size--;
            returnAux=0;

        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* thisIs)
{

    int returnAux = -1;
    int i;
    // Node* nodo;
    if(thisIs!=NULL)
    {
        for(i=0; i<ll_len(thisIs); i++)
        {
            ll_remove(thisIs,i);
            returnAux=0;

        }

// NECESITO LL_REMOVE  para pasarlo x un for
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* thisIs)
{
    int returnAux = -1;
    if(thisIs!=NULL)
    {
        if(ll_clear(thisIs)==0)
        {
            free(thisIs);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* thisIs, void* pElement)
{
    int returnAux = -1;
    Node* nodo;
    int i;
    if(thisIs!=NULL)
    {
        for(i=0; i<ll_len(thisIs); i++)
        {
            nodo=getNode(thisIs,i);
            if(nodo->pElement==pElement)
            {
                returnAux=i;
                return returnAux;
            }
        }

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* thisIs)
{
    int returnAux = -1;
    if(thisIs==NULL)
    {
        return returnAux;
    }

    if(ll_len(thisIs)==0)
    {
        returnAux=1;
    }
    else
    {
        returnAux=0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* thisis, int index, void* pElement)
{
    int returnAux = -1;

    if(thisis!=NULL)
    {
        if(index>=0&& index<=ll_len(thisis))
        {
            addNode(thisis, index,pElement);
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* thisis,int index)
{
    Node* nodo;
    void* returnAux = NULL;
    if(thisis!=NULL)
    {
        if(index>=0 && index<ll_len(thisis))
        {

            nodo=getNode(thisis, index);
            ll_remove(thisis,index);
            returnAux=nodo->pElement;
        }

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* thisis, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;

    if(thisis!=NULL)
    {
        for(i=0; i<ll_len(thisis); i++)
        {
            nodo=getNode(thisis, i);
            if(nodo->pElement==pElement)
            {
                returnAux=1;
                return returnAux;
            }
        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this1,LinkedList* this2)
{

    int returnAux = -1;
    int i;
    void* pElement;
    if(this1 != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i < ll_len(this2); i++)
        {
            pElement = ll_get(this2,i);
            if(!ll_contains(this1,pElement))
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    void *pElement;
    int i;
    if(this != NULL && from >= 0 && to <= this->size)
    {
        cloneArray = ll_newLinkedList();
        for(i=from; i < to; i++)
        {
            pElement = ll_get(this,i);
            ll_add(cloneArray,pElement);
        }
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int i;
    Node* auxnode = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i = 0 ; i < ll_len(this); i++)
        {
            auxnode = ll_get(this,i);
            ll_add(cloneArray,auxnode);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* thisis, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i, j;
    void* aux;
    if(thisis!=NULL && pFunc!=NULL )
    {
        if(order == 0 || order == 1)
        {
            for(i=0; i<ll_len(thisis)-1; i++)
            {
                for(j=i+1; j<ll_len(thisis); j++)
                {
                    if(order == 1 && pFunc(ll_get(thisis,i),ll_get(thisis,j))>0)
                    {
                        aux = ll_get(thisis,i);
                        ll_set(thisis, i, ll_get(thisis, j));
                        ll_set(thisis, j, aux);
                    }
                    else if(order == 0 && pFunc(ll_get(thisis,i), ll_get(thisis,j)) < 0)
                    {
                        aux = ll_get(thisis,i);
                        ll_set(thisis, i, ll_get(thisis, j));
                        ll_set(thisis, j, aux);
                    }
                }
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Itera todos los elementos de la lista y les pasa la funcion enviada
 *
 * \param void*
 * \return int ll_map(LinkedList* this, int
 *
 */

LinkedList* ll_map (LinkedList* lista, void* (*pFun)(void*))
{
    LinkedList* listaSalida = ll_newLinkedList();
    int i;
    if(lista != NULL)
    {
        for(i = 0 ; i < ll_len(lista); i++)
        {
            pFun(ll_get(lista, i));
            ll_add(listaSalida,ll_get(lista, i));
        }
    }
    return listaSalida;
}


/*LinkedList* ll_filter (LinkedList* lista, int (*pFunc)(void*), char tipoVehiculo)///con el de manu le agrego el char tipo �ra separar por tipo de vehiculo
{   ///VER en el de marian que filtraba

    LinkedList* listaSalida = ll_newLinkedList();

    ///int i;

    if(lista != NULL && pFunc!=NULL)
    {
        for(int i = 0 ; i < ll_len(lista); i++)
        {
            if( tipoVehiculo == 'A' && pFunc(ll_get(lista, i)) )
                {
                    ll_add(listaSalida, ll_get(lista, i));
                }
                else
                {
                    if( tipoVehiculo == 'M' && !pFunc(ll_get(lista, i)) )
                    {
                        ll_add(listaSalida, ll_get(lista, i));
                    }
                }
        }
    }
    return listaSalida;
}
*/
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newList = NULL;

    if ( (this != NULL) && (pFunc != NULL) )
    {
        newList = ll_newLinkedList();

        void* aux = NULL;
        int i;

        for (i=0;i<ll_len(this);i++)
        {
            aux = ll_get(this,i);

            if (pFunc(aux)==1)
                ll_add(newList,aux);

            aux = NULL;
        }
    }

    return newList;
}
