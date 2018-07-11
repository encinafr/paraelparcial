#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lista.h"


#define ESC 27
int main()
{
    char opcion;
    ArrayList* subLista;
    NumeroNatural* auxLista;
    ArrayList* lista = al_newArrayList();
    int id,desde,hasta,indice,i,parser;
    char auxCad[100],eliminar;
    if(lista == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
    FILE* archivo = fopen("datos.csv", "r");
    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    do
    {
        system("cls");
        printf("/****************************************************\n\n");
        printf("MENU:\n\n");
        printf("1- ALTA\n");
        printf("2- COMPLETAR\n");
        printf("3- LISTAR\n");
        printf("4- GENERAR\n");
        printf("Presione ESC para salir\n");
        printf("\n\n/****************************************************\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            parser = parserLista(archivo, lista);
            if(parser==0)
            {
                printf("Accion Realizada con exito\n");
                /* for( i=0; i < lista->len(lista); i++)
                 {
                     auxLista = (NumeroNatural*)lista->get(lista, i);
                     Listar(auxLista);
                 }*/
            }


            //system("pause");
            system("pause");
            break;
        case '2':
            esPar(lista);
            esImpar(lista);


             for( i=0; i < lista->len(lista); i++)
                 {

                     auxLista = (NumeroNatural*)lista->get(lista, i);
                     esPrimo(auxLista);
                     Listar(auxLista);

                 }

            system("pause");


            system("pause");
            break;
        case '3':
            ordenar(lista);
            esPar(lista);
            esImpar(lista);


             for( i=0; i < lista->len(lista); i++)
                 {

                     auxLista = (NumeroNatural*)lista->get(lista, i);
                     esPrimo(auxLista);
                     Listar(auxLista);

                 }

            system("pause");
            break;
        case '4':
            //ordenar de manera descendente

            break;

            break;
        case 'ESC':
            break;
        }
    }
    while(opcion != ESC);

    return 0;
}
