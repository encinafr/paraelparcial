#include "ArrayList.h"

typedef struct
{
    int numero;
    char nombre[30];
    int par;
    int impar;
    int primo;

} NumeroNatural;

int compararNumeros(void* numeroA,void* numeroB);
char* getNombre (NumeroNatural* num);
void ordenarDescendente (ArrayList* num);
void ordenarAscendente (ArrayList* num);

