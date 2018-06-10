#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

#define ESC 27
int main()
{
    char opcion;
    ArrayList* subLista;
     Employee* auxCliente;
    ArrayList* lista = al_newArrayList();
    int id,desde,hasta,indice,i,parser;
    char auxCad[100],eliminar;
    if(lista == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
    FILE* archivo = fopen("data.csv", "r");
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
        printf("2- Listar Empleados\n");
        printf("3- Ordenar por nombre\n");
        printf("4- Agregar un elemento\n");
        printf("5- Elimina un elemento\n");
        printf("6- Listar Empleados (Desde/Hasta)\n\n");
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
                    system("pause");
                break;
            case '2':
                    printf("Lista de Clientes\n\n");
                    printf("id  Nombre   Apellido\n\n");
                    for(int i=0; i < lista->len(lista); i++)
                    {
                        auxCliente = (Employee*)lista->get(lista, i);
                        employee_print(auxCliente);
                    }
                    system("pause");
                break;
            case '3':
                    if(lista->sort(lista, employee_compare, 1)==0){
                        printf("\nLista Ordenada\n\n");
                    }
                    else{
                            printf("\nProblema al ordenar la lista\n\n");
                        }
                    system("pause");
                break;
            case '4':
                    auxCliente = employee_new();
                    if(auxCliente != NULL){
                    printf("**Alta Cliente**\n\n");
                    printf("Ingrese id: ");
                    scanf("%d", &id);
                    // valido id
                    employee_setId(auxCliente, id);

                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                    //validar cadena
                    strcpy(auxCliente->name, auxCad);
                    printf("Ingrese Apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                    //validar cadena
                    strcpy(auxCliente->lastName, auxCad);
                    auxCliente->isEmpty = 0;

                    lista->add(lista, auxCliente);

                break;
            case '5':
                    indice = -1;
                    system("cls");
                    printf("Ingrese id: ");
                    scanf("%d", &id);
                    for(int i=0; i < lista->len(lista); i++)
                    {
                        auxCliente = (Employee*)lista->get(lista, i);
                        if(auxCliente->id == id){
                            indice = i;
                            break;
                        }
                    }
                    if(indice == -1){
                        printf("No existe un Cliente con ese id\n\n");
                    }
                    else{
                        auxCliente = (Employee*)lista->get(lista, indice);
                        employee_print(auxCliente);

                        printf("\nEliminar Cliente? s/n: ");
                        fflush(stdin);
                        scanf("%c", &eliminar);

                        if(eliminar == 's'){
                            lista->remove(lista, indice);
                            printf("\nCliente eliminado\n\n");
                        }
                        else{
                            printf("\nEliminacion cancelada\n\n");
                        }
                    }
                    system("pause");

                break;
            case '6':
                parserEmployee(archivo, lista);
                system("cls");
                printf("Indique desde que indice quiere listar: ");
                scanf("%d", &desde);
                 printf("Indique hasta que indice quiere listar: ");
                scanf("%d", &hasta);

                subLista = lista->subList(lista,desde, hasta);

                printf("Lista de Clientes\n\n");
                printf("id  Nombre   Apellido\n\n");
                for(i=0; i < subLista->len(subLista); i++)
                {
                    auxCliente = (Employee*)subLista->get(subLista, i);
                    employee_print(auxCliente);
                }
                system("pause");

                break;
            case 'ESC':
                break;
        }
      }
    }while(opcion != ESC);
    return 0;
}
