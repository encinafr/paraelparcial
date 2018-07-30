#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "ArrayList.h"
#include "lista.h"


int validar_int(char* opcion)
{
    int i, flag = 0, tamanio;

    tamanio = strlen(opcion);

    for(i=0; i<tamanio; i++)
    {
        if(*(opcion+i) < 48  || *(opcion+i) > 57)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}
void Listar(NumeroNatural* this)
{
    if(this != NULL)
    {
        printf("%d\t%d\t%16s\t%d\t%d\t%d\n",this->numero,this->nombre,this->par,this->impar,this->primo);
    }
}
void funcionParImparPrimo (NumeroNatural* num)
{
    int numero,i,a=0;

    numero = getNumero(num);

    if (numero%2 == 0)
    {
        num->par = 1;
        num->impar = 0;
    }
    else
    {
        num->par = 0;
        num-> impar = 1;
    }

    for(i=1; i<=numero; i++)
    {
        if(numero%i==0)
        {
            a++;
        }
    }

    if(a == 2)
    {
        num->primo = 1;
    }
    else
    {
        num->primo = 0;
    }

}

void completarCampos(ArrayList* num)
{
    int i;
    NumeroNatural* aux;

    if(num != NULL)
    {
        for(i=0; i<num->len(num); i++)
        {
            aux = (NumeroNatural*)num->get(num,i);

            if(aux!= NULL)
            {
                funcionParImparPrimo(aux);

                num->set(num,i,aux);
            }
        }
    }
}

NumeroNatural* NuevoNumero(void)
{
    NumeroNatural* returnAux;
    returnAux = (NumeroNatural*)malloc(sizeof(NumeroNatural));
    if(returnAux !=NULL)
    {
        returnAux->numero = 0;
        returnAux->par = 0;
        returnAux->impar = 0;
        returnAux->primo = 0;
        strcpy(returnAux->nombre, "");

    }
    return returnAux;

}


int compararNumeros(void* numeroA,void* numeroB)
{
    NumeroNatural* numA;
    NumeroNatural* numB;

    int respuesta;

    if(numA != NULL && numB != NULL)
    {
        numA = (NumeroNatural*)numeroA;
        numB = (NumeroNatural*)numeroB;

        if(numA->numero > numB->numero)
        {
            respuesta = 1;
        }
        else if(numA->numero < numB->numero)
        {
            respuesta = -1;
        }
        else
        {
            respuesta = 0;
        }

        return respuesta;
    }

    return 0;
}

void ordenarDescendente (ArrayList* num)
{
    if(num != NULL)
    {
        num->sort(num,compararNumeros,0);
    }
}

void ordenarAscendente (ArrayList* num)
{
    if(num != NULL)
    {
        num->sort(num,compararNumeros,1);
    }
}

ArrayList* depurarLista (ArrayList* repetidos)
{
    int i,j,flag;
    NumeroNatural* numeroA;
    NumeroNatural* numeroB;

    if(repetidos != NULL)
    {

        for(i=0; i<repetidos->len(repetidos); i++)
        {
            numeroA = (NumeroNatural*)repetidos->get(repetidos,i);

            for(j=i+1; j<repetidos->len(repetidos); j++)
            {
                numeroB = (NumeroNatural*)repetidos->get(repetidos,j);

                if(numeroA->numero == numeroB->numero && strcmpi(numeroA->nombre,numeroB->nombre)== 0)
                {
                    repetidos->remove(repetidos,j);
                }
            }
        }

        /** hago doble depuramiento porque me seguia mostrando algunos repetidos **/

        for(i=0; i<repetidos->len(repetidos); i++)
        {
            numeroA = (NumeroNatural*)repetidos->get(repetidos,i);

            for(j=i+1; j<repetidos->len(repetidos); j++)
            {
                numeroB = (NumeroNatural*)repetidos->get(repetidos,j);

                if(numeroA->numero == numeroB->numero && strcmpi(numeroA->nombre,numeroB->nombre)== 0)
                {
                    repetidos->remove(repetidos,j);
                }
            }
        }


        system("cls");
        printf("Lista depurada.\n");
        system("pause");

    }

    return repetidos;

}
ArrayList* depurarLista2 (ArrayList* repetidos)
{
    int i,j,flag;
    NumeroNatural* numeroA;
    NumeroNatural* numeroB;

    if(repetidos != NULL)
    {

        for(i=0; i<repetidos->len(repetidos); i++)
        {
            numeroA = (NumeroNatural*)repetidos->get(repetidos,i);

            for(j=i+1; j<repetidos->len(repetidos); j++)
            {
                numeroB = (NumeroNatural*)repetidos->get(repetidos,j);

                if(numeroA->numero == 14 || numeroA->numero == 106 || numeroA->numero == 64)
                {
                    repetidos->remove(repetidos,j);
                }
            }
        }

        /** hago doble depuramiento porque me seguia mostrando algunos repetidos **/


        system("cls");
        printf("Lista depurada.\n");
        system("pause");

    }

    return repetidos;

}
void mostrarNumeros (ArrayList* numeros)
{
    int i,flag = 0;
    NumeroNatural* aux;

    if(numeros != NULL && numeros->isEmpty(numeros) == 0)
    {
        system("cls");

        for (i=0; i<numeros->len(numeros); i++)
        {
            aux = (NumeroNatural*)numeros->get(numeros,i);
            if(flag == 0)
            {
                printf("i     Numero    Nombre\t            Par\t      Impar     Primo\n");
                flag = 1;
            }

            printf("%-6d%-10d%-20s%-10d%-10d%d\n",i+1,getNumero(aux),getNombre(aux),getPar(aux),getImpar(aux),getPrimo(aux));
        }

        system("pause");
    }
    else if(numeros->isEmpty(numeros)==1)
    {
        printf("No hay numeros ingresados.\n");
        system("pause");
    }
}




int setNombre (NumeroNatural* numero,char* nombre)
{
    int aux = -1;

    if(numero != NULL && nombre != NULL)
    {
        if(strlen(nombre)>0 && strlen(nombre)<50)
        {
            strcpy(numero->nombre,nombre);
            aux = 0;
        }
    }

    return aux;
}

int setNumero(NumeroNatural* numero,char* num)
{
    int aux = -1,auxNum;

    if(numero != NULL && num != NULL)
    {

        auxNum = atoi(num);

        if(auxNum>=0)
        {
            numero->numero = auxNum;
            aux = 0;
        }
    }

    return aux;
}

int setPar(NumeroNatural* numero,char* num)
{
    int aux = -1,auxNum;

    if(numero != NULL && num != NULL)
    {

        auxNum = atoi(num);

        if(auxNum == 0 || auxNum == 1)
        {
            numero->par = auxNum;
            aux = 0;
        }
    }

    return aux;
}

int setImpar(NumeroNatural* numero,char* num)
{
    int aux = -1,auxNum;

    if(numero != NULL && num != NULL)
    {

        auxNum = atoi(num);

        if(auxNum == 0 || auxNum == 1)
        {
            numero->impar = auxNum;
            aux = 0;
        }
    }

    return aux;
}

int setPrimo(NumeroNatural* numero,char* num)
{
    int aux = -1,auxNum;

    if(numero != NULL && num != NULL)
    {

        auxNum = atoi(num);

        if(auxNum == 0 || auxNum == 1)
        {
            numero->primo = auxNum;
            aux = 0;
        }
    }

    return aux;
}

int getNumero(NumeroNatural* num)
{
    int aux;

    if(num!= NULL)
    {
        aux = num->numero;
    }

    return aux;
}

char* getNombre (NumeroNatural* num)
{
    char* aux;

    aux = (char*)malloc(sizeof(char)*50);

    if(aux!= NULL && num != NULL)
    {
        strcpy(aux,num->nombre);
    }

    return aux;
}

int getPar(NumeroNatural* num)
{
    int aux;

    if(num!= NULL)
    {
        aux = num->par;
    }

    return aux;
}

int getImpar(NumeroNatural* num)
{
    int aux;

    if(num!= NULL)
    {
        aux = num->impar;
    }

    return aux;
}

int getPrimo(NumeroNatural* num)
{
    int aux;

    if(num!= NULL)
    {
        aux = num->primo;
    }

    return aux;
}

