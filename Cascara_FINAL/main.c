#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lista.h"
#include "parser.h"
#include <ctype.h>



#define ESC 27
int main()
{
    char opcion;
    int flag=0;
    char cadena[100];
    char cadena1[10];
    ArrayList* subLista = al_newArrayList();
    ArrayList* subLista2 = al_newArrayList();
    ArrayList* lista = al_newArrayList();
    int i,parser,validar;
    char auxCad[100];
    if(lista == NULL && subLista== NULL && subLista2== NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    do
    {
        system("cls");
        printf("/****************************************************\n\n");
        printf("MENU:\n\n");
        printf("1- Parse del archivo data.csv\n");
        printf("2- Completar\n");
        printf("3- Listar Ordenado Ascendente\n");
        printf("4- Listar Ordenado Descendente\n");
        printf("5- Generar\n");
        printf("Presione ESC para salir\n");
        printf("\n\n/****************************************************\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
              printf("Ingrese el nombre del archivo\n");
            gets(cadena);

            while(strcmp(cadena,"caracter.csv")!=0)
            {


                    printf("Nombre incorrecto\n");
                    printf("Ingrese el nombre del archivo\n");
            gets(cadena);

            }
            if(strcmp(cadena,"caracter.csv")==0)
            {
                FILE* archivo = fopen(cadena, "r");
                if(archivo == NULL)
                {
                    printf("No se pudo abrir el archivo");
                    exit(1);
                }
                parser = parserEmployee(archivo, lista);
                if(parser==0)
                {
                    printf("Accion Realizada con exito\n");
                    flag=1;
                }

                mostrarNumeros(lista);

            }



            //subLista2 = subLista->clone(lista);

            break;
        case '2':
            lista=esVocal(lista);

            //subLista = subLista->clone(lista);
            break;
        case '3':



            subLista2= esVocal2(lista);
            if(subLista2->sort(subLista2,compararNumeros,1)==0)
            {
                printf("lista ordenada\n");
                mostrarNumeros(subLista2);

            }


            break;
        case '4':
                 printf("Ingrese caracter \n");
            gets(cadena1);
            strlwr(cadena1);

            subLista= depurarLista(lista,cadena1);
            if(subLista->sort(subLista,compararNumeros,0)==0)
            {
                printf("lista ordenada\n");
                mostrarNumeros(subLista);
            }

            break;
        case '5':
            if(generarArchivo("depurados.csv",subLista2)== 0 && generarArchivo("repetidos.csv",subLista)== 0 )
            {
                system("cls");
                printf("Archivos Generados con exito.\n");
                system("pause");
            }


            break;
        case 'ESC':
            break;
        }
    }
    while(opcion != ESC);
    return 0;
}
