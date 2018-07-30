#include "ArrayList.h"

struct S_LogEntry
{
char date[11];
char time[6];
int serviceId;
int gravedad;
char msg[65];
};
typedef struct S_LogEntry LogEntry;

struct S_Service
{
int id;
char name[33];
char email[65];
};
typedef struct S_Service Service;

LogEntry* new_log(void);
Service* new_service(void);

int parsearLog(FILE* pFile , ArrayList* pArrayListLog);
int parsearService(FILE* pFile , ArrayList* pArrayListService);
void imprimir(LogEntry*, char nombreDeServicio[]);
int procesarInformacion(ArrayList* log, ArrayList* service);
