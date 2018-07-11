#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lista.h"


int parserLista(FILE* pFile , ArrayList* pArrayList)
{
    char auxNum[10];
    char auxNombre[51];
    char par[51];
    char impar[10];
    char primo[10];
    int i;
    NumeroNatural* nuevoNumero;

    if(pFile == NULL || pArrayList == NULL){
            return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s\n", auxNum, auxNombre, par, impar,primo);

    while(!feof(pFile)){
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s\n", auxNum, auxNombre, par, impar,primo);

         nuevoNumero = NuevoNumero();
         if(nuevoNumero !=NULL){
            nuevoNumero->numero = atoi(auxNum);
            strcpy(nuevoNumero->nombre, auxNombre);
            nuevoNumero->par = atoi(par);
            nuevoNumero->impar = atoi(impar);
            nuevoNumero->primo = atoi(primo);



                pArrayList->add(pArrayList, nuevoNumero);
                Listar(nuevoNumero);

            }

         }
         fclose(pFile);
    return 0;
}
