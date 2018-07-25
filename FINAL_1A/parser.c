#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lista.h"

int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char auxInt[10];
    char auxNombre[51];
    char auxApellido[51];
    char auxEmpty[51];
    eProducto* nuevoEmpleado;
    int i=0;

    if(pFile == NULL || pArrayListEmployee == NULL){
            return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

    while(!feof(pFile)){
         fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);
        i++;
         nuevoEmpleado = constructor();
         if(nuevoEmpleado !=NULL){
            nuevoEmpleado->vocal = atoi(auxEmpty);
            strcpy(nuevoEmpleado->nombre, auxNombre);
            strcpy(nuevoEmpleado->letra, auxInt);
            nuevoEmpleado->consonante = atoi(auxEmpty);

            }


                pArrayListEmployee->add(pArrayListEmployee, nuevoEmpleado);
                        printf("%5d %-20s%-20s%-10d%d\n",i+1,nuevoEmpleado->letra,getNombre(nuevoEmpleado),getvocal(nuevoEmpleado),getConsonante(nuevoEmpleado));

            }

         fclose(pFile);
    return 0;
}



