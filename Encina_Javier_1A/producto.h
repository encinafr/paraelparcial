
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT 100

typedef struct {

    char Descripcion[CANT];
    int estado;
    int IDProveedor;
}Proveedor;
typedef struct {
    float precio;
    char descripcion[CANT];
    char nombreProducto[CANT];
    int idProducto;
    int idProveedor;
    int estado2;
    int stock;
}Producto;

int validastring(char cadena[]);
int validaint(int num);

void inicializarLibre(Proveedor vec[] , int tam);
int obtenerEspacioLibre(Proveedor lista[],int tam);
int buscarPorID(Proveedor vec[],int tam, int id);
void agregarProveedor(Proveedor vec[], int tam);
void mostrarDato(Proveedor vec);
void mostrarProveedor(Proveedor vec[] , int tam);

void inicializarProducto(Producto vec[] , int tam);
int obtenerEspacioP(Producto lista[],int tam);
void ordenarPorNombreP(Producto vec[] , int tam);
void ordenarPorImporteP(Producto vec[] , int tam);
void modificaProducto(Producto vec[], int tam);
void borrarProducto(Producto vec[], int tam);
void agregarProducto(Producto vec[], int tam,Proveedor arrays[], int tamanio);

int menuInformar();
int menuListar();
void Informes(Producto vec[],int tam);
void Listados(Producto vec[],int tam,Proveedor vec2[],int tam2);
float sumadorImportes(Producto vec [] , int tam);
float menorPrecio(Producto vec[],int arrayLenght);
float mayorPrecio(Producto vec[],int tam);
int contSuperaPromedio(Producto vec[],int tam);
int contNoSuperaPromedio(Producto vec[],int tam);

void mostrarProductosPorID(Producto vec[] , int tam,Proveedor arrays[], int tam1);
void mostrarProducto(Producto vec);
void mostrarProveedorstock(Proveedor array[],int tam,Producto vec[],int tam1);
void MostrarSuperaPromedio(Producto vec[],int tam);
void MostrarNoSuperaPromedio(Producto vec[],int tam);
void mostrarProductosOrdenNombre(Producto vec[],int tam);
void mostrarProductosOrdenImporte(Producto vec[],int tam);
void CantidadMayoDiez(Producto vec[],int tam);
void ProductoMenorDiez(Producto vec[],int tam);
void MostrarMenorDiez(Producto vec[],int tam);
void MostrarCantMayorDiez(Producto vec[],int tam);
void mostrarProductaMasBarato(Producto vec[] , int tam,Proveedor arrays[], int tam1);
void mostrarProductosProveedor(Producto vec[] , int tam,Proveedor arrays[], int tam1);
void mostrarProductaMasCaro(Producto vec[] , int tam,Proveedor arrays[], int tam1);
void proveedorConMenosProductos(Proveedor proveedor[], int tamPROV, Producto productos[], int tamPROD);
void proveedorConMasProductos(Proveedor proveedor[], int tamPROV, Producto productos[], int tamPROD);

void hardCodeProveedores(Proveedor ProveedorArray[],int POS,char nombreAux[],int codeAux);
void hardCodeProducto(Producto ProductoArray[],int POS,char nombreAux[],char Descripcion[],int codeAux,int codeAux2,int Stock,int Importe);

#endif // FUNCIONES_H_INCLUDED
