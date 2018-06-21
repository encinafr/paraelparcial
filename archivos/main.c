#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    //char cadena[50]="hola ";
    char cadena[200];
    printf("Ingrese texto a guardar\n");
    //gets(cadena);
    scanf("%[^\n]", cadena);
    pArchivo = fopen("archivo.txt","w");

    if(pArchivo!=NULL)
    {
       // fprintf(pArchivo,"%s %d %d %s",cadena,1,4,"gato");Puedo escribir todo lo que quiera
        fprintf(pArchivo,"%s",cadena);
        fclose(pArchivo);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }

    printf("El texto guardado es:\n");
    pArchivo = fopen("archivo.txt","r");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {

         fgets(cadena,200,pArchivo);
         puts(cadena);
        }
        fclose(pArchivo);
    }
    return 0;
}
