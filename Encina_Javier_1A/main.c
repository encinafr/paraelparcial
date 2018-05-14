#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#define TAM 100
#define UNI 1000

int main()
{
    int flag=0;
    char salir='s';
    int opcion;

    Proveedor NewProveedor[TAM];
    Producto NewProducto[UNI];
    inicializarProveedor(NewProveedor,TAM);
    inicializarProducto(NewProducto,UNI);
    hardCodeProveedores(NewProveedor,1,"Marolio",1);
    hardCodeProveedores(NewProveedor,2,"Knort",2);
    hardCodeProveedores(NewProveedor,3,"Mayorista el Sol",3);
    hardCodeProveedores(NewProveedor,4,"Walmart",4);
    hardCodeProveedores(NewProveedor,5,"Easy",5);

    //hardCodeProducto(Producto ProductoArray[],int POS,char nombreAux[],char Descripcion[],int codeAux,int codeAux2,int Stock,int Importe)
    hardCodeProducto(NewProducto,1,"Harina","Altas tortas fritas",1,1,10,10);
    hardCodeProducto(NewProducto,2,"Caldos","Para el guizo",2,2,20,1000);
    hardCodeProducto(NewProducto,3,"Papel","Para todo",3,3,50,10);
    hardCodeProducto(NewProducto,4,"Cerveza","Para el refrescar el gallote",4,4,2,10);
     hardCodeProducto(NewProducto,5,"Amoladora","Para laburar",5,5,100,10);
    while(salir == 's')
    {
        system("cls");
        printf("----MENU PRINCIPAL---\n\n");
        printf("1- ALTA PROVEEDOR\n");
        printf("2- AGREGAR PRODUCTO\n");
        printf("3- MODIFICAR PRODUCTO:\n");
        printf("4- CANCELAR PRODUCTO:\n");
        printf("5- INFORMES:\n");
        printf("6- LISTADOS:\n");
        printf("7- SALIR\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                agregarProveedor(NewProveedor,TAM);
                break;
            case 2:

                agregarProducto(NewProducto,UNI,NewProveedor,TAM);
                break;
            case 3 :
                modificaProducto(NewProducto,UNI);
            break;
            case 4 :
                borrarProducto(NewProducto,UNI);
            break;
            case 5:
              Informes(NewProducto,UNI);
                    break;
            case 6:
                Listados(NewProducto,UNI,NewProveedor,TAM);
                break;
                  //  system("pause");
            case 7:
                salir='n';
            break;
             default:
                        printf("Opcion incorrecta");
                        system("pause");

        }
    }
    return 0;
}
