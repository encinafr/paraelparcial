#include "ArrayList.h"

typedef struct
{
    int id;
    char Descripcion[30];
    float precio;
    int cantidad;
    int estado;
    int bajaFisica;
} eProducto;

eProducto* newProducto();
int setid(eProducto*, int);
int getid(eProducto*);
int setPrecio(eProducto*, float);
float getPrecio(eProducto*);
int setDescripcion(eProducto*, char*);
char* getDescripcion(eProducto*);
void altaProducto(ArrayList*);
void mostrarProductos(ArrayList*);
void mostrarLogica(eProducto*);
int buscarID(ArrayList*, int);
void bajaProducto(ArrayList*);
void ModificaProducto(ArrayList*);
void guardarArchivo(ArrayList*);
void cargarArchivo(ArrayList*);
FILE* crearArchivo(char*);
FILE* leerArchivo(char*);

int menu(ArrayList*);
int validar_num(char*);
void gotoxy(int x, int y);
void pintarLineas(ArrayList*);
int compararProductos(void*,void*);
void ordenar(ArrayList*);
void guardarArchivoTXT(ArrayList*);
void cargarArchivoTXT(ArrayList*);
FILE* crearArchivoTXT(char*);
FILE* leerArchivoTXT(char*);
