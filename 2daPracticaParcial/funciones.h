
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT 100
typedef struct {
    int dia;
    int mes;
    int anio;
}FN;
typedef struct {

    char nombre[CANT];
    char password[CANT];
    int estado;
    int edad;
    char sexo;
    int IDusuario;
    FN nacimiento;
    int calificacion;
}Usuario;
typedef struct {
    float precio;
    char descripcion[CANT];
    char nombreProducto[CANT];
    int idProducto;
    int idusuario;
    int estado2;
    int stock;
}Producto;

void inicializarLibre(Usuario vec[] , int tam);
int obtenerEspacioLibre(Usuario lista[],int tam);
int buscarPorID(Usuario vec[],int tam, int id);
void agregarPersona(Usuario vec[], int tam);
void mostrarDato(Usuario vec);
void mostrarPersonas(Usuario vec[] , int tam);
void modificaUsuario(Usuario vec[], int tam);
void borrarUsuario(Usuario vec[], int tam);
void inicializarProducto(Producto vec[] , int tam);
int obtenerEspacioP(Producto lista[],int tam);
void ordenarPorNombreP(Producto vec[] , int tam);
void mostrarProducto(Producto vec);
void mostrarProductos(Producto vec[] , int tam);
void modificaProducto(Producto vec[], int tam);
void borrarProducto(Producto vec[], int tam);
void agregarProducto(Producto vec[], int tam,Usuario arrays[], int tamanio);
void mostrarProductosPorID(Producto vec[] , int tam,Usuario arrays[], int larg);
void compraProducto(Producto vec[],int tam);
int buscaPorNombre(Usuario vec[],int tam,char nombre[]);


#endif // FUNCIONES_H_INCLUDED
