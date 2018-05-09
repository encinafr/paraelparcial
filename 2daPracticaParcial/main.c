#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 100
#define UNI 1000

int main()
{
    int flag=0;
    char salir='s';
    int opcion;

    Usuario NewUsuario[TAM];
    Producto NewProducto[UNI];
    inicializarUsuario(NewUsuario,TAM);
    inicializarProducto(NewProducto,UNI);

    while(salir == 's')
    {
        system("cls");
        printf("----MENU PRINCIPAL---\n\n");
        printf("1- ALTA USUARIO\n");
        printf("2- MODIFICAR USUARIO\n");
        printf("3- BAJA USUARIO\n");
        printf("4- PUBLICAR PRODUCTO\n");
        printf("5- MODIFICAR PUBLICACION:\n");
        printf("6- CANCELAR PUBLICACION\n");
        printf("7- COMPRAR PRODUCTO:\n");
        printf("8- LISTAR PUBLICACIONES DE USUARIO:\n");
        printf("9- LISTAR PUBLICACIONES:\n");
        printf("10- LISTAR USUARIOS:\n");
        printf("11 SALIR\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                agregarPersona(NewUsuario,TAM);
                break;
            case 2:
                modificaUsuario(NewUsuario,TAM);
                break;
            case 3:
                borrarUsuario(NewUsuario,TAM);
                break;
            case 4:

                agregarProducto(NewProducto,UNI,NewUsuario,TAM);
                break;
            case 5 :
                modificaProducto(NewProducto,UNI);
            break;
            case 6 :
                borrarProducto(NewProducto,UNI);
            break;
            case 7 :
                compraProducto(NewProducto,UNI);
            break;
            case 8 :

                mostrarProductosPorID(NewProducto,UNI,NewUsuario,TAM);
                system("pause");
            break;
            case 9 :
                mostrarProductos(NewProducto,UNI);
                system("pause");
            break;
            case 10 :
                    mostrarPersonas(NewUsuario,TAM);
                    system("pause");
            break;
            case 11
             :
                salir='n';
            break;
             default:
                        printf("Opcion incorrecta");
                        system("pause");

        }
    }
    return 0;
}
