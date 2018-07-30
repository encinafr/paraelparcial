#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

LogEntry* new_log()
{
    LogEntry* returnAux;

    returnAux = (LogEntry*)malloc(sizeof(LogEntry));

    if(returnAux != NULL)
    {
        strcpy(returnAux->date, "");
        strcpy(returnAux->time, "");
        returnAux->gravedad = 0;
        returnAux->serviceId = 0;
        strcpy(returnAux->msg, "");

    }

    return returnAux;
}

Service* new_service(void)
{
    Service* returnAux;

    returnAux = (Service*)malloc(sizeof(Service));

    if(returnAux != NULL)
    {
        strcpy(returnAux->name, "");
        strcpy(returnAux->email, "");
        returnAux->id = 0;
    }

    return returnAux;
}

int parsearLog(FILE* pFile, ArrayList* pArrayListLog)
{
    char auxDate[11];
    char auxTime[6];
    char auxServiceId[51];
    char auxGravedad[10];
    char auxMsg[65];

    int auxGravedadInt, auxServiceIdInt;

    int returnAux = -1, bandera = 1;

    LogEntry* nuevoLog;

    if(pFile == NULL || pArrayListLog == NULL)
    {
        bandera = 0;
    }
    if (bandera)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", auxDate, auxTime, auxServiceId, auxGravedad, auxMsg);

            auxGravedadInt = atoi(auxGravedad);
            auxServiceIdInt = atoi(auxServiceId);

            nuevoLog = new_log();

            if(nuevoLog != NULL)
            {
                strcpy(nuevoLog->date, auxDate);
                strcpy(nuevoLog->time, auxTime);
                nuevoLog->gravedad = auxGravedadInt;
                nuevoLog->serviceId = auxServiceIdInt;
                strcpy(nuevoLog->msg, auxMsg);

                pArrayListLog->add(pArrayListLog, nuevoLog);
            }

        }
        returnAux = 1;
    }

    return returnAux;
}

int parsearService(FILE* pFile, ArrayList* pArrayListService)
{
    char auxName[33];
    char auxEmail[65];
    char auxId[11];

    int auxIdInt;

    int returnAux = -1, bandera = 1;

    Service* nuevoService;

    if(pFile == NULL || pArrayListService == NULL)
    {
        bandera = 0;
    }

    if (bandera)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^;];%[^;];%[^\n]\n", auxId, auxName, auxEmail);

            auxIdInt = atoi(auxId);

            nuevoService = new_service();

            if(nuevoService != NULL)
            {
                strcpy(nuevoService->name, auxName);
                strcpy(nuevoService->email, auxEmail);
                nuevoService->id = auxIdInt;

                pArrayListService->add(pArrayListService, nuevoService);
            }

        }
        returnAux = 1;
    }

    return returnAux;
}

void imprimir(LogEntry* log, char nombreDeServicio[])
{
    if (log != NULL)
    {
        printf("%s %s %s %s %d", log->date, log->time, nombreDeServicio, log->msg, log->gravedad);
    }

}

int procesarInformacion(ArrayList* log, ArrayList* service)
{
    int i, j, returnAux = 1, bandera = 1;

    //char buffer[700];

    LogEntry* auxLog;
    Service* auxService;

    FILE* archivoWarning;
    FILE* archivoErrors;

    if ((archivoWarning = fopen("warnings.txt", "r+")) == NULL || (archivoErrors = fopen("errors.txt", "r+")) == NULL)
    {
        if ((archivoWarning = fopen("warnings.txt", "w+")) == NULL || (archivoErrors = fopen("errors.txt", "w+")) == NULL)
        {
            returnAux = 0;
            bandera = 0;
        }
    }

    if (bandera)
    {
        for (i = 0; i < log->len(log); i++)
        {
            auxLog = log->get(log, i);

            for (j = 0; j < service->len(service); j++)
            {
                auxService = service->get(service, j);

                if (auxLog->serviceId == auxService->id)
                    break;
            }

            if (auxLog->gravedad == 3 && auxLog->serviceId != 45)
            {
                fprintf(archivoWarning, "%s;%s;%s;", auxLog->date, auxLog->time, auxService->name);
                fputs(auxLog->msg, archivoWarning);
                fprintf(archivoWarning ,";%s\n",auxService->email);
                printf("%s", auxLog->msg);
            }

        }
    }


    return returnAux;
}
