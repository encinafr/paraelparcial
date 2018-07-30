#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "ArrayList.h"
#include "lista.h"
#include "parser.h"
#include <ctype.h>


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
    char* aux = (char*) malloc(sizeof(char)*2);

    if(Producto != NULL && aux != NULL)
    {
        strcpy(aux, Producto->letra);
    }
    return aux;
}



int compararNumeros(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {

        eProducto* empA = (eProducto*) pEmployeeA;
        eProducto* empB = (eProducto*) pEmployeeB;
        return strcmp(empA->letra, empB->letra);
    }
    return 0;
}





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
    int j=0;
    int flag = 0;
    int i;
    eProducto* aux;

    if(numeros != NULL && numeros->isEmpty(numeros) == 0)
    {
        system("cls");

        for (i=0; i<numeros->len(numeros); i++)
        {
            j++;
            aux = (eProducto*)numeros->get(numeros,i);
            if(flag == 0)
            {
                printf("     Letra    Nombre\t            vocal\t      Consonante     \n");
                flag = 1;
            }

            printf("%5d %-20s%-20s%-10d%d\n",j+1,getLetra(aux),getNombre(aux),getvocal(aux),getConsonante(aux));
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
    int j=0;
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
            j++;
            aux = (eProducto*)Letras->get(Letras,i);

            strlwr(aux->letra);
            if(cuentaVocales(aux->letra)>0)
                //if( strcmp(aux->letra,comp)==0 ||strcmp(aux->letra,comp1)==0 ||strcmp(aux->letra,comp2)==0 ||strcmp(aux->letra,comp3)==0||strcmp(aux->letra,comp4)==0 && esSoloLetras(aux->letra)==1 )
            {
                aux->vocal=1;
                retorno=0;

            }
            else
            {
                aux->consonante=1;
            }
            printf("%5d %-20s%-20s%-10d% d%\n",j+1,aux ->letra,getNombre(aux),aux->vocal,aux->consonante);
            // employee_print(aux);
        }

        system("pause");

        return retorno;
    }


}

int cuentaVocales(char*s)
{
    int cont=0;

    while(*s) //mientras que no sea nulo
    {
        switch(*s)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cont++;
        }
        s++;
    }
    return cont;
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


//Fijate como mcomparar cada letra de una cadena con cada caracter

ArrayList* depurarLista (ArrayList* repetidos, char cadena[])
{
    int i,j,s;
    int x=0;
    int flag=0;
    eProducto* numeroA;
    ArrayList* ListaCopia = al_newArrayList();

    if(repetidos != NULL)
    {
        for(i=0; i<repetidos->len(repetidos); i++)
        {
            numeroA = (eProducto*)repetidos->get(repetidos,i);
            for(j=0; j<strlen(cadena); j++)
            {
                for(s=0; s<strlen(numeroA->letra); s++)
                {
                    if(cadena[j] == numeroA->letra[s])
                    {
                        ListaCopia->add(ListaCopia,numeroA);
                        //printf("%5d %-20s%-20s%-10d% d%\n",s+1,numeroA->letra,getNombre(numeroA),numeroA->vocal,numeroA->consonante);
                        // system("pause");
                    }
                }
            }
        }
    }
    return ListaCopia;
}


ArrayList* depurarLista2 (ArrayList* repetidos,ArrayList* lista)
{
    int i,j,s;
    int x=0;
    int flag=0;
    eProducto* numeroA;
    ArrayList* ListaCopia = al_newArrayList();

    if(repetidos != NULL)
    {
        for(i=0; i<repetidos->len(repetidos); i++)
        {
            numeroA = (eProducto*)repetidos->get(repetidos,i);

            if(repetidos->contains(lista,numeroA)==0)
            {
                ListaCopia->add(ListaCopia,numeroA);
                //printf("%5d %-20s%-20s%-10d% d%\n",s+1,numeroA->letra,getNombre(numeroA),numeroA->vocal,numeroA->consonante);
                // system("pause");
            }
        }
    }
    return ListaCopia;
}


ArrayList* quitarRepetidos(ArrayList* repetidos)
{
    int i,j,s;
    int x=0;
    int flag=0;
    eProducto* numeroA;
    eProducto* numeroB;

    if(repetidos != NULL)
    {
        for(i=0; i<repetidos->len(repetidos)-1; i++)
        {
            numeroA = (eProducto*)repetidos->get(repetidos,i);

            for(j=i+1; j<repetidos->len(repetidos); j++)
            {
                numeroB = (eProducto*)repetidos->get(repetidos,j);

                if(strcmpi(numeroA->nombre,numeroB->nombre)== 0)
                {
                    repetidos->remove(repetidos,j);
                }
            }
        }

         for(i=0; i<repetidos->len(repetidos)-1; i++)
        {
            numeroA = (eProducto*)repetidos->get(repetidos,i);

            for(j=i+1; j<repetidos->len(repetidos); j++)
            {
                numeroB = (eProducto*)repetidos->get(repetidos,j);

                if(strcmpi(numeroA->nombre,numeroB->nombre)== 0)
                {
                    repetidos->remove(repetidos,j);
                }
            }
        }


    }
    return repetidos;
}



int generarArchivo(char* nombre,ArrayList* lista)
{
    FILE* archivo;
    eProducto* aux;
    int retorno = -1,i,cantidad;

    if(nombre != NULL)
    {
        archivo = fopen(nombre,"w");

        if(archivo != NULL && lista != NULL)
        {
            printf("entre aca");
            getch();
            for(i=0;i<lista->len(lista);i++)
            {
                aux = (eProducto*)lista->get(lista,i);

                fprintf(archivo,"%S,%s,%d,%d,\n",getLetra(aux),getNombre(aux),getvocal(aux),getConsonante(aux));
            }

            retorno = 0;
        }
    }

    fclose(archivo);

    return retorno;

}
