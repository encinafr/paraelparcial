#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "ArrayList.h"
#include "lista.h"


int main()
{
     ArrayList* lista = al_newArrayList();
    int opcion;
    cargarArchivoTXT(lista);
    cargarArchivo(lista);
    do
    {
        system("cls");

        switch(opcion = menu(lista))
        {
        case 1:
            alta(lista);
            break;
        case 2:
            Modificacion(lista);
            break;
        case 3:
            bajaLogica(lista);
            break;
        case 4:
            bajaFisica(lista);
            break;
        case 5:
             ordenar(lista);
             mostrarProductos(lista);
             system("pause");
            break;
        case 6:
            guardarArchivoTXT(lista);
           guardarArchivo(lista);
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            //Sleep(1000);
            system("pause");
            break;
        }
    }
    while(opcion != 6);
    return 0;
}
