#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lista.h"


#define ESC 27
int main()
{
    char opcion;
    ArrayList* repetidos = al_newArrayList();
    ArrayList* depurado = al_newArrayList();
    NumeroNatural* auxLista;
    ArrayList* lista = al_newArrayList();
    int i,parser;
    int flag =0;
    char auxCad[100],eliminar;
    if(lista == NULL && repetidos == NULL && depurado == NULL)
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
        printf("3- LISTAR Descendente\n");
        printf("4- LISTAR Ascendente\n");
        printf("5- GENERAR\n");
        printf("Presione ESC para salir\n");
        printf("\n\n/****************************************************\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            if(flag==0)
            {
                parser = parserLista(archivo, lista);
                if(parser==0)
                {
                    printf("Accion Realizada con exito\n");
                    flag=1;
                }
                mostrarNumeros(lista);
            }
            else{
                printf("Esta accion ya ha sido realizada\n");
                system("pause");
            }


            break;
        case '2':
            completarCampos(lista);
            mostrarNumeros(lista);
            repetidos = lista->clone(lista);
            depurado = lista->clone(lista);
            break;
        case '3':
            repetidos=depurarLista2(repetidos);
            ordenarDescendente(repetidos);
            mostrarNumeros(repetidos);
            break;
        case '4':
            //ordenar de manera descendente
           depurado= depurarLista(depurado);
            ordenarAscendente(depurado);
            mostrarNumeros(depurado);

            break;
        case '5':

            break;

            break;
        case 'ESC':
            break;
        }
    }
    while(opcion != ESC);

    return 0;
}
