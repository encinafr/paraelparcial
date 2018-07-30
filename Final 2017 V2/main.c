#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int menu();

int main()
{
    char seguir = 's';

    //int verificar;

    FILE* logArchivo;
    FILE* servicesArchivo;

    logArchivo = fopen("log.txt", "r");
    servicesArchivo = fopen("services.txt", "r");

    if(logArchivo == NULL || servicesArchivo == NULL)
    {
        printf("No se pudo abrir los archivos");
        exit(1);
    }

    ArrayList* LogEntryArray = al_newArrayList();
    ArrayList* ServiceArray = al_newArrayList();

    if(LogEntryArray == NULL || ServiceArray == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    do
    {
        switch(menu())
        {

        case 1: //Leer log

            if (parsearService(servicesArchivo, ServiceArray) && parsearLog(logArchivo, LogEntryArray))
            {
                printf("\nArchivos cargados con exito\n\n");
            }
            else
            {
                printf("\nError al parsear archivos\n\n");
            }

            system("pause");
            break;

        case 2: //Procesar informacion

            procesarInformacion(LogEntryArray, ServiceArray);

            system("pause");
            break;

        case 3: //Mostrar estadisticas

            system("pause");
            break;

        case 4:

            seguir = 'n';
            break;

        }
    }

    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. Leer log\n");
    printf("2. Procesar informacion\n");
    printf("3. Mostrar estadisticas\n");
    printf("4. Salir\n\n");
    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
