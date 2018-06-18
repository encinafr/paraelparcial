#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 *//*Crea y retorna un nuevo ArrayList. Es el constructor, ya que en �l daremos valores iniciales a
las variables y asignaremos las funciones a sus punteros. */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 *//*
 Agrega un elemento al final de ArrayList. Verificando que tanto el puntero pList como pElement
sean distintos de NULL. Si la verificaci�n falla la funci�n retorna (-1) y si tiene �xito (0).
*/
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag = 1;

    if (this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {

            if (resizeUp(this)==-1)
            {
                printf("Nose pudo conseguir lugar\n");
                flag = 0;
            }
        }
        if(flag == 1)
        {
            *(this->pElements +this->size) = pElement;
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
/*Elimina el ArrayList . Verificando que el puntero pList sea distinto de NULL. Si la verificaci�n
falla la funci�n retorna (-1), si esta vac�o (1) y si contiene elementos (0).
*/
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        free(this);
        free(this->pElements);
        returnAux = 0;
        if(this->size==0)
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief  returns the size of the array
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 *//*
 Retorna el tama�o del ArrayList. Verificando que el puntero pList sea distinto de NULL. Si la
verificaci�n falla la funci�n retorna (-1) y si tiene �xito retorna la longitud del array.*/
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
/*
   Retorna un puntero al elemento que se encuentra en el �ndice especificado. Verificando que el
   puntero pList sea distinto de NULL y que index sea positivo e inferior al tama�o del array. Si la
   verificaci�n falla la funci�n retorna (NULL) y si tiene �xito retorna el elemento.
*/
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index >= 0 && index < this->len(this))
    {

        returnAux = *(this->pElements+index);
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
/*
Comprueba si existe el elemento que se le pasa como par�metro. Verificando que tanto el
puntero pList como pElement sean distintos de NULL. Si la verificaci�n falla la funci�n retorna
(-1) , si encuentra el elemento (1) y si no lo encuentra (0).
*/
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1,i;
    if (this != NULL && pElement != NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            if(*(this->pElements + i) == pElement)
            {
                returnAux=1;
                break;
            }
            else
            {
                returnAux=0;
            }
        }
    }

    return returnAux;
}
/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 *//*
 Inserta un elemento en el ArrayList, en el �ndice especificado. Verificando que tanto el puntero
pList como pElement sean distintos de NULL y que index sea positivo e inferior al tama�o del
array. Si la verificaci�n falla la funci�n retorna (-1) y si tiene �xito (0).

 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && pElement != NULL && index >= 0 && index < this->len(this))
    {
        *(this->pElements+index)=pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *//*
 Elimina un elemento del ArrayList, en el �ndice especificado. Verificando que el puntero pList
sea distinto de NULL y que index sea positivo e inferior al tama�o del array. Si la verificaci�n
falla la funci�n retorna (-1) y si tiene �xito (0).
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    if(this!=NULL && index >= 0 && index < this->len(this))
    {
        contract(this,index);
        returnAux=0;
    }



    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 *//*Borra todos los elementos de ArrayList. Verificando que el puntero pList sea distinto de NULL.
Si la verificaci�n falla la funci�n retorna (-1) y si tiene �xito (0).
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    void** aux;
    int i;
    if(this!=NULL)
    {
        aux = (void**) realloc (this->pElements,sizeof(void*)* AL_INITIAL_VALUE);
        if(aux!=NULL)
        {
            this->size=0;
            this->reservedSize = AL_INITIAL_VALUE;
            this->pElements = aux;

            for(i=0; i<this->len(this); i++)
            {
                free(*(this->pElements+i));
                //*(this->pElements+i)=NULL;
            }

            returnAux=0;
        }
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 *//*Retorna un nuevo ArrayList copia del ArrayList original. Verificando que el puntero pList sea
distinto de NULL. Si la verificaci�n falla la funci�n retorna (NULL) y si tiene �xito retorna el
nuevo array.
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this!=NULL)
    {
        returnAux = al_newArrayList();
        if(returnAux!=NULL)
        {
            for(i=0; i<this->len(this); i++)
            {
                returnAux->add(returnAux,*(this->pElements+i));
            }
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *//*Desplaza los elementos e inserta en la posici�n index. Verificando que tanto el puntero pList
como pElement sean distintos de NULL y que index sea positivo e inferior al tama�o del array.
Si la verificaci�n falla la funci�n retorna (-1) y si tiene �xito (0).*/
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL && index >=0 && index <=this->len(this))
    {
        if(index==this->len(this))
        {
            this->add(this,pElement);
        }
        else
        {
            if(expand(this,index)==0)
            {
                *(this->pElements+index) = pElement;
                returnAux = 0;
            }
        }

    }


    return returnAux;
}





/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 *//*Retorna el �ndice de la primera aparici�n de un elemento (element) en el ArrayList. Verificando
que tanto el puntero pList como pElement sean distintos de NULL. Si la verificaci�n falla o no
encuentra el elemento la funci�n retorna (-1) y si encuentra el elemento retorna su �ndice.
*/
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1,i;

    if(this != NULL && pElement != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            if(*(this->pElements + i) == pElement)
            {
                returnAux = i;
            }
        }

    }
    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 *//*
 Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero pList sea
distinto de NULL. Si la verificaci�n falla la funci�n retorna (-1), si esta vac�o (1) y si contiene
elementos (0).
*/
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->len(this)>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 *//*
 Retorna un puntero al elemento que se encuentra en el �ndice especificado y luego lo elimina
de la lista. Verificando que el puntero pList sea distinto de NULL y que index sea positivo e
inferior al tama�o del array. Si la verificaci�n falla la funci�n retorna (NULL) y si tiene �xito
retorna el elemento.
*/
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL )
    {

        returnAux = this->get(this,index);
        this->remove(this,index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 *//*Retorna un nuevo ArrayList con el subconjunto de elementos. Verificando que el puntero pList
sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tama�o
del array. Si la verificaci�n falla la funci�n retorna (NULL) y si tiene �xito retorna el nuevo */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    //void* returnAux = NULL;
    ArrayList* returnAux = NULL;
    int i;
    if(this != NULL &&  from>=0 && from < to && to <=this->size)
    {
        returnAux =(ArrayList*) al_newArrayList();
        if(returnAux!=NULL)
        {
            for(i=from; i<to; i++)
            {
                //returnAux->add(returnAux,*(this->pElements+i));
                returnAux->add( returnAux, this->get(this, i) );
            }
        }

    }


    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 *//*Comprueba si los elementos pasados son contenidos por el ArrayList. Verificando que tanto el
puntero pList como pList2 sean distintos de NULL. Si la verificaci�n falla o no encuentra el
elemento la funci�n retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna
(1).
*/
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i;

    if(this != NULL && this2 != NULL)
    {
        if(this->size == this2->size)
        {
            for(i=0; i<this->size; i++)
            {
                if(*(this->pElements+i)== *(this2->pElements+i))
                {
                    returnAux = 1;
                }

            }
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 *//*Ordena los elementos del array recibiendo como par�metro la funci�n que sera la encargada
de determinar que elemento es mas grande que otro y si se debe ordenar de manera
ascendente o descendente. Verificando que tanto el puntero pList como el puntero a la funcion
pFunc sean distintos de NULL. Si la verificaci�n falla (-1) caso contrario retorna (1).*/
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i,j;
    void* aux;

    if(this != NULL && pFunc !=NULL && (order==0 || order==1))
    {
        for(i=0; i<this->size-1; i++)
        {
            for(j=i+1; j<this->size; j++)
            {
                if(order==0)
                {
                    if(pFunc(*(this->pElements+i),*(this->pElements+j))== -1)
                    {
                        aux= *(this->pElements+i);
                        *(this->pElements+i)=*(this->pElements+j);
                        *(this->pElements+j)= aux;

                    }
                }
                else
                {
                    if(pFunc(*(this->pElements+i),*(this->pElements+j))== 1)
                    {
                        aux= *(this->pElements+i);
                        *(this->pElements+i)=*(this->pElements+j);
                        *(this->pElements+j)= aux;

                    }
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** auxArray;
    if (this != NULL)
    {

        auxArray = (void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize+AL_INCREMENT));

        if (auxArray != NULL)
        {
            this->pElements = auxArray;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1, i;

    if (this != NULL && index >= 0 && index <= this->size && this->size > 0)
    {
        if(this->reservedSize == this->len(this))
        {
            resizeUp(this);
        }

        for (i=this->len(this); i>index; i--)
        {
            //  free(this->pElements+j);
            *(this->pElements+(i+1)) = *(this->pElements+i);
        }
        this->size++;
        returnAux = 0;
    }


    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1,i,j;
    if(this!=NULL && index >= 0  && index < this->len(this))
    {
        for(i=index; i < this->len(this) ; i++)
        {
            j=i+1;
            // free(this->pElements+j);
            *(this->pElements+i)= *(this->pElements+j);
        }
        returnAux=0;
        this->size--;
    }
    return returnAux;
}





