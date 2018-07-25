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
    int vocal;
    int validar;
    char cadena[100];
    ArrayList* subLista;
     eProducto* auxCliente;
    ArrayList* lista = al_newArrayList();
    int i,parser;
    char auxCad[100];
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

  do{
        system("cls");
        printf("/****************************************************\n\n");
        printf("MENU:\n\n");
        printf("1- Parse del archivo data.csv\n");
        printf("2- Completar\n");
        printf("3- Listar\n");
        printf("4- Generar\n");
        printf("Presione ESC para salir\n");
        printf("\n\n/****************************************************\n");

        opcion = getch();

        switch(opcion)
        {
            case '1':
                    parser = parserEmployee(archivo, lista);
                    if(parser==0){
                        printf("Accion Realizada con exito\n");
                    }
                   // mostrarNumeros(lista);
                    system("pause");
                break;
            case '2':
                    esVocal(lista);

                break;
            case '3':

                printf("Ingrese cadena\n");
                        scanf("%s",cadena);
                validar=esSoloLetras(cadena);
                while(validar!=1){
                        printf("Ingrese cadena\n");
                        scanf("%s",cadena);
                }
                depurarLista(lista,cadena);




                break;
            case '4':

                break;
            case 'ESC':
                break;
        }
      }while(opcion != ESC);
    return 0;
}
