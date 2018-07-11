#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "ArrayList.h"
#include "lista.h"

int menu(ArrayList* this)
{
    char opcion[20];
    int Num;

    system("cls");
    printf("\n\n1.Alta\n2.Completar\n3.Listar\n4.Generar Archiuvo\n\ningrese: ");

    fflush(stdin);
    scanf("%[^\n]", opcion);
    Num = validar_int(opcion);

    while(Num == 1)
    {
        system("cls");
        printf("\n\n1.Alta\n2.Modificacion\n3.Baja Logica\n4.Baja Fisica\n5.Listar\n6.Guardar y salir\n\ningrese: ");
        fflush(stdin);
        scanf("%[^\n]", opcion);
        Num = validar_int(opcion);
    }

    Num = atoi(opcion);

    return Num;
}

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
int setNum(NumeroNatural* Numero, int num)
{
    int aux = -1;

    if(Numero != NULL)
    {
        if(num > 0 )
        {
            Numero->numero = num;
            aux = 0;
        }
    }

    return aux;
}

int getNum(NumeroNatural* Numero)
{
    int aux;

    if(Numero != NULL)
    {
        aux = Numero->numero;
    }
    return aux;
}

int getPar(NumeroNatural* Numero)
{
    int aux;

    if(Numero != NULL)
    {
        aux = Numero->par;
    }
    return aux;
}

int getImpar(NumeroNatural* Numero)
{
    int aux;

    if(Numero != NULL)
    {
        aux = Numero->impar;
    }
    return aux;
}
int getPrimo(NumeroNatural* Numero)
{
    int aux;

    if(Numero != NULL)
    {
        aux = Numero->primo;
    }
    return aux;
}
int setPar(NumeroNatural* Numero, int Par)
{
    int aux = -1;

    if(Numero != NULL)
    {
        if(Par == 0 || Par == 1)
        {
            Numero->par = Par;
            aux = 0;
        }
    }

    return aux;
}

int setImpar(NumeroNatural* Numero, int Impar)
{
    int aux = -1;

    if(Numero != NULL)
    {
        if(Impar == 0 || Impar == 1)
        {
            Numero->impar = Impar;
            aux = 0;
        }
    }

    return aux;
}
int setPrimo(NumeroNatural* Numero, int Primo)
{
    int aux = -1;

    if(Numero != NULL)
    {
        if(Primo == 0 || Primo == 1)
        {
            Numero->primo = Primo;
            aux = 0;
        }
    }

    return aux;
}
int setNombre(NumeroNatural* Numero, char* Nombre)
{
    int aux = -1;

    if(Numero != NULL)
    {
        if(strlen(Nombre) > 0 && strlen(Nombre) < 51)
        {
            strcpy(Numero->nombre, Nombre);
            aux = 0;
        }
    }

    return aux;
}

char* getNombre(NumeroNatural* Numero)
{
    char* aux = (char*) malloc(sizeof(char)*50);

    if(Numero != NULL && aux != NULL)
    {
        strcpy(aux, Numero->numero);
    }
    return aux;
}

void Listar(NumeroNatural* Numero)
{
    printf("%-5d%-20s%-5d-%5d-%5d\n", Numero->numero, Numero->nombre, Numero->par, Numero->impar, Numero->primo);
}

int esPar(ArrayList* lista)
{
    int i;
    int aux = -1;
    NumeroNatural* auxNumero;
    if(lista!=NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            auxNumero= (NumeroNatural*) lista->get(lista,i);
            if(auxNumero->numero %2==0)
            {
                auxNumero->par=1;
                aux =1;
            }
        }
    }
    return aux;
}
int esImpar(ArrayList* lista)
{
    int i;
    int aux = -1;
    NumeroNatural* auxNumero;
    if(lista!=NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            auxNumero= (NumeroNatural*) lista->get(lista,i);
            if(!(auxNumero->numero %2==0))
            {
                auxNumero->impar=1;
                aux =1;
            }
        }
    }
    return aux;
}
int esPrimo(NumeroNatural* auxNumero)
{
    int i,j;
    int aux;
    int a=0;

    for(i=1; i<=auxNumero->numero; i++)
    {
        if(auxNumero->numero%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
            a++;
    }
    if(a==2)
    {
        auxNumero->primo=1;
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
void mostrarTodo(ArrayList* this)
{
    int i;
    NumeroNatural* Numero = NuevoNumero();

    if(this != NULL && Numero != NULL)
    {
        system("cls");
        if(this->isEmpty(this) == 1)
        {
            printf("La lista esta vacia.\n");
        }
        else
        {
            for(i=0; i<this->len(this); i++)
            {
                Numero = (NumeroNatural*)this->get(this, i);

                Listar(Numero);
                printf("i\n");
            }
        }
        printf("\n\n");
    }
}

void ordenar(ArrayList* this)
{
    this->sort(this,compararProductos(),1);

    printf("lista ordenada!!\n\n");
    system("pause");
}

int compararProductos(void* A,void* B)
{
    if(A != NULL && B != NULL)
    {

        NumeroNatural* pA = (NumeroNatural*) A;
        NumeroNatural* pB = (NumeroNatural*) B;
        if(pA->numero = pB->numero){
            return 0;
        }

    }
return 0;

}


