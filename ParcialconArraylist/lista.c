#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "ArrayList.h"
#include "lista.h"

int menu(ArrayList* this)
{
    char opcion[20];
    int esNum;

    system("cls");
    printf("\n\n1.Alta\n2.Modificacion\n3.Baja Logica\n4.Baja Fisica\n5.Listar\n6.Guardar y salir\n\ningrese: ");

    fflush(stdin);
    scanf("%[^\n]", opcion);
    esNum = validar_num(opcion);

    while(esNum == 1)
    {
        system("cls");
        printf("\n\n1.Alta\n2.Modificacion\n3.Baja Logica\n4.Baja Fisica\n5.Listar\n6.Guardar y salir\n\ningrese: ");
        fflush(stdin);
        scanf("%[^\n]", opcion);
        esNum = validar_num(opcion);
    }

    esNum = atoi(opcion);

    return esNum;
}

int validar_num(char* opcion)
{
    int i, flag = 0, size;

    size = strlen(opcion);

    for(i=0; i<size; i++)
    {
        if(*(opcion+i) < 48  || *(opcion+i) > 57)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}
int setid(eProducto* Producto, int id)
{
    int aux = -1;

    if(Producto != NULL)
    {
        if(id > 0 && id <= 1000)
        {
            Producto->id = id;
            aux = 0;
        }
    }

    return aux;
}

int getid(eProducto* Producto)
{
    int aux;

    if(Producto != NULL)
    {
        aux = Producto->id;
    }
    return aux;
}

int getEsatdo(eProducto* Producto)
{
    int aux;

    if(Producto != NULL)
    {
        aux = Producto->estado;
    }
    return aux;
}
int getBajaFisica(eProducto* Producto)
{
    int aux;

    if(Producto != NULL)
    {
        aux = Producto->bajaFisica;
    }
    return aux;
}
int setCantidad(eProducto* Producto, int Cantidad)
{
    int aux = -1;

    if(Producto != NULL)
    {
        if(Cantidad > 0)
        {
            Producto->cantidad = Cantidad;
            aux = 0;
        }
    }

    return aux;
}

int setEstado(eProducto* Producto, int Estado)
{
    int aux = -1;

    if(Producto != NULL)
    {
            Producto->estado = Estado;
            aux = 0;
    }

    return aux;
}
int getCantidad(eProducto* Producto)
{
    int aux;

    if(Producto != NULL)
    {
        aux = Producto->cantidad;
    }
    return aux;
}
int setDescripcion(eProducto* Producto, char* Descripcion)
{
    int aux = -1;

    if(Producto != NULL)
    {
        if(strlen(Descripcion) > 0 && strlen(Descripcion) < 51)
        {
            strcpy(Producto->Descripcion, Descripcion);
            aux = 0;
        }
    }

    return aux;
}

char* getDescripcion(eProducto* Producto)
{
    char* aux = (char*) malloc(sizeof(char)*50);

    if(Producto != NULL && aux != NULL)
    {
        strcpy(aux, Producto->Descripcion);
    }
    return aux;
}


int setPrecio(eProducto* Producto, float Precio)
{
    int aux = -1;

    if(Producto != NULL)
    {
        if(Precio > 0)
        {
            Producto->precio = Precio;
            aux = 0;
        }
    }

    return aux;
}

float getPrecio(eProducto* Producto)
{
    float aux;

    if(Producto != NULL)
    {
        aux = Producto->precio;
    }
    return aux;
}

void alta(ArrayList* this)
{
    eProducto* Producto;
    int id,existe;
    float precio;
    int cantidad;
    char Descripcion[51];

    if(this != NULL)
    {
        Producto = newProducto();

        if(Producto != NULL)
        {
            do
            {
                printf("Ingrese id: ");
                scanf("%d", &id);
                existe = buscarID(this, id);
                if(existe != -1)
                {
                    printf("El id ya existe.\n\n");
                    system("pause");
                }
            }while(setid(Producto, id) == -1);
            if(existe==-1){
            do
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                scanf("%[^\n]", Descripcion);
            }while(setDescripcion(Producto, Descripcion) == -1);
            do
            {
                printf("Ingrese Cantidad: ");
                scanf("%d",&cantidad);

            }while(setCantidad(Producto, cantidad) == -1 );
            do
            {
                printf("Ingrese Precio: ");
                scanf("%f", &precio);
            }
            while(setPrecio(Producto, precio) == -1);
            setEstado(Producto,1);
            this->add(this, Producto);
            printf("\nAlta exitosa.\n\n");
            system("pause");
        }
      }
    }
}

int buscarID(ArrayList* this, int id)
{
    int aux = -1, i;
    eProducto* Producto = newProducto();

    if(this != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            Producto = (eProducto*)this->get(this, i);
            if(Producto->id == id)
            {
                aux = i;
                break;
            }
        }
    }

    return aux;
}

void bajaFisica(ArrayList* this)
{
    eProducto* Producto = newProducto();
    int buscar;
    int id;
    char opcion;

    if(this != NULL && Producto != NULL && this->isEmpty(this) != 1)
    {
        mostrarProductos(this);
        printf("\nIngrese id a buscar: ");

        scanf("%d",&id);
        buscar = buscarID(this, id);
        if(buscar == -1)
        {
            printf("No se encontro el id.\n\n");
            system("pause");
        }
        else
        {
            Producto = (eProducto*)this->get(this, buscar);
            system("cls");
            printf("\ndesea eliminar este Producto? s/n\n\n");
            mostrarProducto(Producto);
            fflush(stdin);
            opcion = getch();
            opcion=tolower(opcion);
            if(opcion == 's')
            {
                this->remove(this, buscar);
            }
            printf("\nBaja exitosa.\n\n");
            system("pause");
        }
    }
    else if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}

void bajaLogica(ArrayList* this)
{
    eProducto* Producto = newProducto();
    int buscar;
    int id;
    char opcion;

    if(this != NULL && Producto != NULL && this->isEmpty(this) != 1)
    {
        mostrarProductos(this);
        printf("\nIngrese id a buscar: ");

        scanf("%d",&id);
        buscar = buscarID(this, id);
        if(buscar == -1)
        {
            printf("No se encontro el id.\n\n");
            system("pause");
        }
        else
        {
            Producto = (eProducto*)this->get(this, buscar);
            system("cls");
            printf("\ndesea eliminar esta Producto? s/n\n\n");
            mostrarProducto(Producto);
            fflush(stdin);
            opcion = getch();
            opcion=tolower(opcion);
            if(opcion == 's')
            {
                //this->remove(this, buscar);
                Producto->bajaFisica=1;
                Producto->estado=0;
            }
            printf("\nBaja exitosa.\n\n");
            system("pause");
        }
    }
    else if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}
void Modificacion(ArrayList* this)
{
    eProducto* Producto = newProducto();
    int buscar, eleccion,id,edad,cantidad;
    char opcion, Descripcion[51];
    float precio;

    if(this != NULL && Producto != NULL && this->isEmpty(this) != 1)
    {
        mostrarProductos(this);
        printf("\ningrese id a buscar: ");

        scanf("%d", &id);
        buscar = buscarID(this, id);
        if(buscar == -1)
        {
            printf("No se encontro el id.\n\n");
            system("pause");
        }
        else
        {
            Producto = this->get(this, buscar);
            system("cls");
            printf("\ndesea modificar esta Producto? s/n\n\n");
            mostrarProducto(Producto);
            fflush(stdin);
            opcion = getch();
            opcion = tolower(opcion);
            if(opcion == 's' )
            {
                do
                {
                    system("cls");
                    printf("1-Descripcion\n2-id\n3-Precio\n4-Cantidad\n5-Volver\n\nIngrese opcion: ");
                    scanf("%d", &eleccion);
                    switch(eleccion)
                    {
                    case 1:
                        do
                        {
                            printf("Ingrese Descripcion: ");
                            fflush(stdin);
                            scanf("%[^\n]", Descripcion);
                        }
                        while(setDescripcion(Producto, Descripcion) == -1);
                        break;
                    case 2:
                        do
                        {
                            printf("Ingrese id: ");
                            scanf("%d", &id);
                        }
                        while(setid(Producto, id) == -1);
                        break;
                    case 3:
                        do
                        {
                            printf("Ingrese Precio: ");
                            scanf("%f", &precio);
                        }
                        while(setPrecio(Producto, precio) == -1);
                        break;
                    case 4:
                        do
                        {
                            printf("Ingrese Cantidad: ");
                            scanf("%d", &cantidad );
                        }
                        while(setCantidad(Producto, cantidad) == -1);
                        break;
                    case 5:
                        opcion=5;
                        break;
                    }

                }
                while(opcion != 5);
                printf("\nModificacion exitosa.\n\n");
                system("pause");
            }

        }
    }
    if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}


void ordenar(ArrayList* this)
{
    this->sort(this,compararProductos,1);

    printf("lista ordenada!!\n\n");
    system("pause");
}

int compararProductos(void* ProductoA,void* ProductoB)
{
    if(ProductoA != NULL && ProductoB != NULL)
    {

        eProducto* pA = (eProducto*) ProductoA;
        eProducto* pB = (eProducto*) ProductoB;
        return strcmp(pA->Descripcion, pB->Descripcion);
    }
    return 0;
}

void mostrarProducto(eProducto* Producto)
{
    printf("%-5d%-20s%-5.2f %5d\n", getid(Producto), getDescripcion(Producto), getPrecio(Producto), getCantidad(Producto));
}
/*
void pintarLineas(ArrayList* this)
{
    int i, size;
    size = this->len(this) +2;

    for(i=0; i<size; i++)
    {
        gotoxy(4, i);
        printf("%c", 186);
        gotoxy(24, i);
        printf("%c", 186);
        gotoxy(31, i);
        printf("%c", 186);
        gotoxy(42, i);
        printf("%c", 186);
    }
    for(i=0; i<43; i++)
    {
        gotoxy(i, size);
        printf("%c", 205);
    }
    gotoxy(4, size);
    printf("%c", 202);
    gotoxy(24, size);
    printf("%c", 202);
    gotoxy(31, size);
    printf("%c", 202);
    gotoxy(42, size);
    printf("%c", 188);
}
*/
void mostrarProductos(ArrayList* this)
{
    int i;
    eProducto* Producto = newProducto();

    if(this != NULL && Producto != NULL)
    {
        system("cls");
        if(this->isEmpty(this) == 1)
        {
            printf("La lista esta vacia.\n");
        }
        else
        {
            printf("Id Descripcion              Precio Cantidad    \n\n");
            for(i=0; i<this->len(this); i++)
            {
                Producto = (eProducto*)this->get(this, i);
                if(Producto->estado==1)
                mostrarProducto(Producto);
            }
          //  pintarLineas(this);
        }
        printf("\n\n");

    }
}

eProducto* newProducto()
{
    eProducto* aux = (eProducto*) malloc(sizeof(eProducto));

    if(aux != NULL)
    {
        strcpy(aux->Descripcion, "");
        aux->id = 0;
        aux->estado = 0;
        aux->bajaFisica=0;
        aux->cantidad = 0;
        aux->precio = 0;
    }

    return aux;
}

FILE* leerArchivoTXT(char* name)
{
    FILE* archivo;

    if((archivo = fopen(name, "r")) == NULL)
    {
        if((archivo = fopen(name, "w")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
        }
    }

    return archivo;
}

FILE* crearArchivoTXT(char* name)
{
    FILE* archivo;

    if((archivo = fopen(name, "w")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

FILE* leerArchivo(char* name)
{
    FILE* archivo;

    if((archivo = fopen(name, "rb")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

FILE* crearArchivo(char* name)
{
    FILE* archivo;

    if((archivo = fopen(name, "wb")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

void cargarArchivoTXT(ArrayList* this)
{
    FILE* f = leerArchivoTXT("datosB.txt");

    if(this != NULL)
    {
        if(f != NULL)
        {
            printf("archivo de texto generado.\n");
        }
    }
}



void guardarArchivoTXT(ArrayList* this)
{
    eProducto* Producto = newProducto();
    FILE* f = crearArchivoTXT("datosB.txt");

    if(this != NULL && Producto != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            fprintf(f, "ID,Descripcion,Cantidad,Precio\n");
            for(int i=0; i<this->len(this); i++)
            {
                Producto = this->get(this, i);
                if(getBajaFisica(Producto)==1)
                fprintf(f, "%d,%s,%d,%.2f,%d,%d\n", Producto->id, Producto->Descripcion, Producto->cantidad, Producto->precio, Producto->estado, Producto->bajaFisica);
            }
        }
    }
}

void guardarArchivo(ArrayList* this)
{
    int i;
    eProducto* producto;
    FILE* f = crearArchivo("datos.bin");

    if(this != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            for (i=0; i < this->len(this); i++)
            {
                producto = (eProducto*)this->get(this, i);

                fwrite(producto, sizeof(eProducto), 1, f);
            }
            fclose(f);
        }
    }
}

void cargarArchivo(ArrayList* this)
{
    FILE* archivo = leerArchivo("datos.bin");
    eProducto aux;
    int validar;
    eProducto* Producto;
    rewind(archivo);
    if(archivo != NULL)
    {
        while (!feof(archivo))
        {
            validar = fread(&aux, sizeof(eProducto), 1, archivo);
            Producto = newProducto();
            if(validar == 1 && Producto != NULL)
            {
                Producto->id = aux.id;
                strcpy(Producto->Descripcion, aux.Descripcion);
                 Producto->cantidad = aux.cantidad;
                Producto->precio = aux.precio;
                Producto->estado=1;
                Producto->bajaFisica=0;
                this->add(this, Producto);
            }

            if(validar!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro\n");
                    system("pause");
                    break;
                }
            }

        }
        printf("\nArchivo cargado.\n\n");
        system("pause");

        fclose(archivo);
    }
}

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

