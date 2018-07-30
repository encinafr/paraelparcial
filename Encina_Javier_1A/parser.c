#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lista.h"

int parserLista (FILE* archivo,ArrayList *Numero)
{
    NumeroNatural* lista;
    char nombre[50];
    char numero[50];
    char  par[50];
    char impar[50];
    char primo[50];
    int cant;



    if(archivo != NULL && numero != NULL)
    {
        cant = fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,par,impar,primo);

        while(!feof(archivo))
        {
            cant = fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,par,impar,primo);
            lista= NuevoNumero();
            if(lista!=NULL)
            {
                setNombre(lista,nombre);
                setNumero(lista,numero);
                setPar(lista,par);
                setImpar(lista,impar);
                setPrimo(lista,primo);
            }

            Numero->add(Numero,lista);
        }
    }

    fclose(archivo);
}
