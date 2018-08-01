#include "ArrayList.h"

typedef struct
{
    char letra[2];
    char nombre[22];
    int vocal;
    int consonante;
    int numero;
} eProducto;


int compararNumeros(void* pEmployeeA,void* pEmployeeB);
ArrayList* depurarLista (ArrayList* repetidos,char cadena[]);
int esSoloLetras(char str[]);
int cuentaVocales(char*s);
ArrayList* esVocal(ArrayList* Letras);
void mostrarNumeros (ArrayList* numeros);
eProducto* constructor();
ArrayList* depurarLista2 (ArrayList* repetidos,ArrayList* lista);
ArrayList* quitarRepetidos(ArrayList* repetidos);
