#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "ArrayList.h"
#include "lista.h"
#include "parser.h"
#include <ctype.h>

int menu(ArrayList* this)
{
    char opcion[20];
    int Num;

    system("cls");
    printf("\n\n1.Alta\n2.Modificacion\n3.Baja Logica\n4.Baja Fisica\n5.Listar\n6.Guardar y salir\n\ningrese: ");

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
int setvocal(eProducto* Producto, int vocal)
{
    int aux = -1;

    if(Producto != NULL)
    {
        Producto->vocal = vocal;
        aux = 0;
    }

    return aux;
}

int getvocal(eProducto* Producto)
{
    int aux;

    if(Producto != NULL)
    {
        aux = Producto->vocal;
    }
    return aux;
}

int getConsonante(eProducto* Producto)
{
    int aux;

    if(Producto != NULL)
    {
        aux = Producto->consonante;
    }
    return aux;
}

int setConsonante(eProducto* Producto, int Consonante)
{
    int aux = -1;

    if(Producto != NULL)
    {
        Producto->consonante = Consonante;
        aux = 0;
    }

    return aux;
}



int setNombre(eProducto* Producto, char* nombre)
{
    int aux = -1;

    if(Producto != NULL)
    {
        if(strlen(nombre) > 0 || strlen(nombre) < 21)
        {
            strcpy(Producto->nombre, nombre);
            aux = 0;
        }
    }

    return aux;
}

int setLetra(eProducto* Producto, char* Letra)
{
    int aux = -1;
    char validar;
    if(Producto != NULL)
    {


        strcpy(Producto->letra, Letra);
        aux = 0;
    }

    return aux;
}

char* getNombre(eProducto* Producto)
{
    char* aux = (char*) malloc(sizeof(char)*50);

    if(Producto != NULL && aux != NULL)
    {
        strcpy(aux, Producto->nombre);
    }
    return aux;
}

char* getLetra(eProducto* Producto)
{
    char* aux = (char*) malloc(sizeof(char));

    if(Producto != NULL && aux != NULL)
    {
        strcpy(aux, Producto->letra);
    }
    return aux;
}


/*
void ordenar(ArrayList* this)
{
    this->sort(this,compararProductos,1);

    printf("lista ordenada!!\n\n");
    system("pause");
}

int compararProductos(void* ProductoA,void* ProductoB)
{
    if(ProductoA != NULL && ProductoB != NULL)
    {

        eProducto* pA = (eProducto*) ProductoA;
        eProducto* pB = (eProducto*) ProductoB;
        return strcmp(pA->Descripcion, pB->Descripcion);
    }
    return 0;
}
*/







eProducto* constructor()
{
    eProducto* aux;

    aux = (eProducto*)malloc(sizeof(eProducto));

    if(aux != NULL)
    {
        aux->vocal = 0;
        strcpy(aux->nombre,"");
        aux->consonante = 0;
        strcpy(aux->letra,"");

    }

    return aux;
}
void employee_print(eProducto* this)
{
    if(this != NULL)
    {
        printf(" %c %s %d %d\n", this->letra, this->nombre, this->vocal,this->consonante);
    }
}
void mostrarNumeros (ArrayList* numeros)
{
    int i,flag = 0;
    eProducto* aux;

    if(numeros != NULL && numeros->isEmpty(numeros) == 0)
    {
        system("cls");

        for (i=0; i<numeros->len(numeros); i++)
        {
            aux = (eProducto*)numeros->get(numeros,i);
            if(flag == 0)
            {
                printf("     Letra    Nombre\t            vocal\t      Consonante     \n");
                flag = 1;
            }

            printf("%5d %-20s%-20s%-10d%d\n",i+1,aux ->letra,getNombre(aux),getvocal(aux),getConsonante(aux));
        }

        system("pause");
    }
    else if(numeros->isEmpty(numeros)==1)
    {
        printf("No hay numeros ingresados.\n");
        system("pause");
    }
}

int esVocal(ArrayList* Letras)
{
    eProducto* aux;
    int i;
    char comp[2] = "a";
    char comp1[2] = "e";
    char comp2[2] = "i";
    char comp3[2] = "o";
    char comp4[2] = "u";
    char minuscula[20];
    int retorno=-1;
    if(Letras != NULL)
    {
        for(i=0; i<Letras->len(Letras); i++)
        {
            aux = (eProducto*)Letras->get(Letras,i);

            strcpy(minuscula,aux->letra);
            minuscula = tolower(minuscula);
                if( strcmp(aux->letra,comp)==0 ||strcmp(aux->letra,comp1)==0 ||strcmp(aux->letra,comp2)==0 ||strcmp(aux->letra,comp3)==0||strcmp(aux->letra,comp4)==0 && esSoloLetras(aux->letra)==1 )
                {
                    aux->vocal=1;
                    retorno=0;

                }else{
                    aux->consonante=1;
                }
                printf("%5d %-20s%-20s%-10d% d%\n",i+1,aux ->letra,getNombre(aux),aux->vocal,aux->consonante);
        }

system("pause");

        return retorno;
}


}




int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
