
#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include <string.h>

/** \brief Valida que el entero ingresado este en un rango valido
 *
 * \param num int el numero a verificar
 * \return 1 si es valido 0 sino lo es
 *
 */
int validaint(int num){
int valido=0;
if(num>0 &&num < 100)
    {
        valido=1;
    }
return valido;
}
/** \brief Valida 1ue la cadena de caracteres contengas al menos 4 caracteres
 *
 * \param cadena Cadena a ser verificada
 * \return 1 si es valido 0 sino lo es
 *
 */

int validastring(char cadena[]){
int valido=0;
    if(strlen(cadena)>3){
        valido=1;
    }

return valido;
}
/** \brief Recorre el vector e inicializa el estado en uno
 *
 * \param vec el el vector que le pasamos por parametro
 * \param tam el tamaño del vector
 */

void inicializarProveedor( Proveedor vec[] , int tam)
{
    int i;
    for(i=0 ; i < tam ; i++)
    {
        vec[i].estado = 1;
    }
}

/** \brief Recoore el array y corrobora que tenga lugar disponible
 *
 * \param lista el array que pasamos por parametro
 * \param tam el tamaño del array
 * \return retorna si hay espacio y -1 si no la hay
 *
 */

int obtenerEspacioLibre(Proveedor lista[],int tam){

  int i;
    int espacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(lista[i].estado == 1)
        {
            espacio = i;
            break;
        }
    }
    return espacio;
}

/** \brief Recorre el vector e imprime los datos cargados
 *
 * \param vec Vector a recorrer
 */

void mostrarDato(Proveedor vec)
{
    printf("Descripcion:\t CodigoProveedor:\t\n");
    printf("%s\t\t%d\n" , vec.Descripcion ,vec.IDProveedor);

}
/** \brief Recorre el vector y pregunta por el estado para imprimir solo los datos que esten cargados sin basura
 * \param vec Vector a recorrer
 * \param tam tamaño del vactor
 */


void mostrarProveedor(Proveedor vec[] , int tam)
{
    ordenarPorNombre(vec, tam);
    int i;

    //printf("Nombre:\tIDusuario:\tEdad:\tCalificacion\tPassword\tFecha De Nacimiento DIA: MES: ANIO:\n");

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado == 0)
        {
            mostrarDato(vec[i]);
           // printf("entro");
        }
    }
}
/**
 * Obtiene el indice que coincide con el usuario pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param Usuario el usuario a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro usuario
 */
int buscarPorID(Proveedor vec[],int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(vec[i].estado ==0 && id == vec[i].IDProveedor)
        {
            indice = i;
            break;
        }
    }
    return indice;


}

/** \brief  compara los nombres y los ordena en orden alfabetico
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vactor
 *
 */

void ordenarPorNombre(Proveedor vec[] , int tam)
{
    int i;
    int j;
    Proveedor aux;

    //printf("Dni:\tNombre:\tEdad:\n");
    for(i=0 ; i < tam-1 ; i++)
    {
        for(j=i+1 ; j < tam ; j++)
        {
            if((strcmp(vec[i].Descripcion, vec[j].Descripcion) > 0))
            {
                aux= vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
            if((strcmp(vec[i].Descripcion , vec[j].Descripcion) == 0)){
                if(vec[i].IDProveedor > vec[j].IDProveedor){// > mayor es ascendente < descendente;
                    aux.IDProveedor=vec[i].IDProveedor;
                    vec[i].IDProveedor = vec[j].IDProveedor;
                    vec[j].IDProveedor= aux.IDProveedor;

                }

            }
        }
    }
}
/** \brief Pide los datos a ser cargados
 *
 * \param Vector donde guardo los datos
 * \param Tamaño del vactor
 */

void agregarProveedor(Proveedor vec[], int tam)
{
    int indice;
    int id,auxid;
    int existe;
    char nombreProveedor[50];
    Proveedor nuevoProveedor;

    system("cls");
    printf("---REGISTRAR PROVEEDOR---\n\n");

    indice = obtenerEspacioLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a proveedores nuevos.\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese id de Proveedor: ");
         fflush(stdin);
        scanf("%d", &auxid);
        while(!validaint(auxid))
            {
                printf("Ingrese un id valido\n");
                printf("Ingrese id de Proveedor: \n");
                 fflush(stdin);
                scanf("%d", &auxid);

            }
        id = auxid;
        existe = buscarPorID(vec,tam,id);

        if(existe != -1)
        {
            printf("\nEl id %d ya esta dado de alta en el sistema\n", id);
                   mostrarDato(vec[existe]);
                   system("pause");
        }
       else{
                   nuevoProveedor.IDProveedor=id;
                   nuevoProveedor.estado = 0;

                   printf("Ingrese la descripcion del proveedor: ");
                   fflush(stdin);
                   scanf("%s",nombreProveedor);
                   while(!validastring(nombreProveedor)){
                        printf("Nombre muy corto\n");
                        printf("Ingrese la descripcion del proveedor: ");
                       fflush(stdin);
                       scanf("%s",nombreProveedor);

                   }
                    strcpy(nuevoProveedor.Descripcion,nombreProveedor);
                     vec[indice]=nuevoProveedor;
                 printf("\n Se registro correctamente!!!\n\n");
                    system("\npause\n");
           }

  }

}


/** \brief Recorre el vector e inicializa el estado en uno
 *
 * \param vec el el vector que le pasamos por parametro
 * \param tam el tamaño del vector
 */

void inicializarProducto(Producto vec[] , int tam)
{
    int i;
    for(i=0 ; i < tam ; i++)
    {
        vec[i].estado2 = 1;
    }
}

/** \brief Recoore el array y corrobora que tenga lugar disponible
 *
 * \param lista el array que pasamos por parametro
 * \param tam el tamaño del array
 * \return retorna si hay espacio y -1 si no la hay
 *
 */

int obtenerEspacioP(Producto lista[],int tam){

  int i;
    int espacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(lista[i].estado2 == 1)
        {
            espacio = i;
            break;
        }
    }
    return espacio;
}

/** \brief  compara los nombres y los ordena en orden alfabetico
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vactor
 *
 */

void ordenarPorNombreP(Producto vec[] , int tam)
{
    int i;
    int j;
    Producto aux;

    //printf("Dni:\tNombre:\tEdad:\n");
    for(i=0 ; i < tam-1 ; i++)
    {
        for(j=i+1 ; j < tam ; j++)
        {

            if(strcmp(vec[i].nombreProducto , vec[j].nombreProducto) > 0)
            {
                aux= vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
             if(strcmp(vec[i].nombreProducto , vec[j].nombreProducto) > 0){
                    if(vec[i].precio < vec[j].precio){
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
             }
            }
        }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 void ordenarPorImporteP(Producto vec[] , int tam)
{
    int i;
    int j;
    Producto aux;

    //printf("Dni:\tNombre:\tEdad:\n");
    for(i=0 ; i < tam-1 ; i++)
    {
        for(j=i+1 ; j < tam ; j++)
        {
            if(vec[i].precio < vec[j].precio){
                        aux= vec[i];
                        vec[i]= vec[j];
                        vec[j] = aux;
                    }

            }
        }
}


/** \brief Pide los datos a ser cargados
 *
 * \param Vector donde guardo los datos
 * \param Tamaño del vactor
 */

void agregarProducto(Producto vec[], int tam,Proveedor arrays[], int tamanio)
{
    int indice,id,existe,auxstock;
    //char nombreProducto[50];
    Producto nuevoProducto;
    int idcargar,auxid;
    int encuentra;
    int estaNombre;
    char nombreProducto[50];
    char descripcionProducto[100];
    system("cls");
    printf("---REGISTRAR PRODUCTO---\n\n");

    indice = obtenerEspacioP(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta productos nuevos.\n\n");
        system("pause");
    }
    else
    {

        printf("Ingrese su Id de Proveedor");
                scanf("%d",&auxid);
                while(!validaint(auxid))
            {
                printf("Ingrese un id valido\n");
                printf("Ingrese id de Proveedor: \n");
                 fflush(stdin);
                scanf("%d", &auxid);

            }
            idcargar=auxid;
                encuentra = buscarPorID(arrays,tamanio,idcargar);
                if(encuentra == -1)
                        {
                            printf("\nEl id %d no esta dado de alta en el sistema\n", idcargar);
                            system("pause");
                        }else{

        printf("Ingrese id de Producto: ");
        fflush(stdin);
        scanf("%d",&auxid);
        while(!validaint(auxid))
            {
                printf("Ingrese un id valido\n");
                printf("Ingrese id de Producto: \n");
                 fflush(stdin);
                scanf("%d", &auxid);

            }
           id = auxid;
        existe = buscarPorIDproducto(vec,tam,id);

        if(existe != -1)
        {
            printf("\nEl id %d ya esta dado de alta en el sistema\n", id);
                   mostrarProducto(vec[existe]);
                   system("pause");
        }
       else{
                   nuevoProducto.idProducto = id;
                   nuevoProducto.idProveedor =idcargar;
                   nuevoProducto.estado2 = 0;

                   printf("Ingrese Nombre del Producto: ");
                   fflush(stdin);
                   gets(nombreProducto);
                    while(!validastring(nombreProducto)){
                        printf("Nombre muy corto\n");
                        printf("Ingrese Nombre del Producto: ");
                       fflush(stdin);
                       scanf("%s",nombreProducto);

                   }
                    strcpy(nuevoProducto.nombreProducto,nombreProducto);
                   printf("Ingrese Descripcion('No mas de 100 caracteres'): ");
                   fflush(stdin);
                   gets(descripcionProducto);
                   while(!validastring(descripcionProducto)){
                        printf("Ampliar Descripcion \n");
                       fflush(stdin);
                       gets(descripcionProducto);

                   }
                    strcpy(nuevoProducto.descripcion,descripcionProducto);

                   printf("Ingrese Importe: ");
                   fflush(stdin);
                   scanf("%f", &nuevoProducto.precio);
                   while(nuevoProducto.precio <=0){
                    printf("ERROr,Reingrese el Importe: ");
                   fflush(stdin);
                   scanf("%f", &nuevoProducto.precio);
                   }
                    printf("Ingrese Cantidad del producto");
                    scanf("%d",&auxstock);
                     while(!validaint(auxstock))
                        {
                            printf("Ingrese una cantidad valida\n");
                             fflush(stdin);
                            scanf("%d", &auxstock);
                        }
                        nuevoProducto.stock=auxstock;
                    vec[indice]=nuevoProducto;
                   printf("\n Se registro correctamente!!!\n\n");
                    system("\npause\n");

           }
    }
  }

   // printf("%s %s %s %d",nuevoUsuario.nombre,nuevoUsuario.apellido,nuevoUsuario.password,nuevoUsuario.edad);
   // system("pause");
}
/** \brief Recorre el vector e imprime los datos cargados
 *
 * \param vec Vector a recorrer
 */

void mostrarProducto(Producto vec)
{
    printf("\n| NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
    printf("\n%10s| %-35s | %9d | %5.2f | %5d |\n",vec.nombreProducto,vec.descripcion,vec.idProducto,vec.precio,vec.stock);
}
/** \brief Recorre el vector y pregunta por el estado para imprimir solo los datos que esten cargados sin basura
 * \param vec Vector a recorrer
 * \param tam tamaño del vactor
 */


void mostrarProductosOrdenNombre(Producto vec[],int tam)
{
    int i;
    ordenarPorNombreP(vec,tam);
    printf("\n| NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |ID|");
    for(i=0;i < tam; i++)
    {
        if(vec[i].estado2 == 0)
        {
          printf("\n%10s| %-35s | %9d | %5.2f | %5d | %3d|\n\n",vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock,vec[i].idProducto);
        }
    }

}
/** \brief Lista los productos ordenados por importe
 *
 * \param vec EL vetor de productos
 * \param tam EL tamaño del array
 */
 void mostrarProductosOrdenImporte(Producto vec[],int tam)
{
    int i;
    ordenarPorImporteP(vec,tam);
    printf("\n| NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
    for(i=0;i < tam; i++)
    {
        if(vec[i].estado2 == 0)
        {
          printf("\n%10s| %-35s | %9d | %5.2f | %5d |\n\n",vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock);
        }
    }

}

/**
 * Obtiene el indice que coincide con el usuario pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param Usuario el usuario a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro usuario
 */
int buscarPorIDproducto(Producto vec[],int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(vec[i].estado2 ==0 && id == vec[i].idProducto)
        {
            indice = i;
            break;
        }
    }
    return indice;


}
/** \brief Busca el id del usuario y cambia el estado para pisar sus datos
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vector
 *
 */

void borrarProducto(Producto vec[], int tam){
int id;
int existe;
char confirma;
Producto nuevoProducto;

system("cls");
printf("---Borrar Producto---\n\n");


    printf("Los productos registrados son:\n");
    mostrarProductosOrdenNombre(vec,tam);
   printf("Ingrese el ID Producto que desea eliminar: ");
        scanf("%d",&id);

        existe = buscarPorIDproducto(vec, tam, id);

        if(existe == -1)
        {
            printf("\nEl id %d no se encuentra en el sistema\n\n", id);
            system("pause");
        }
        else{

                mostrarProducto(vec[existe]);

        do{
            printf("\nConfirma borrar? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){

            vec[existe].estado2 = 1;
            printf("\nSe ha realizado la baja\n\n");
            system("pause");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
            system("pause");
        }

        }
}



/** \brief Busca el legajo del usuario,muestra los datos ser modificados guarda los nuevos datos
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vector
 *
 */
void modificaProducto(Producto vec[], int tam){
    Producto nuevoDatoProducto;
    int id;
    int esta;
    char confirma;
    int salir = 0;
    int fijate;


    system("cls");
    printf("---Modifica Producto---\n\n");
    printf("Los productos registrados son:\n");
    mostrarProductosOrdenNombre(vec,tam);
   printf("Ingrese ID de Producto: ");
        scanf("%d", &id);

        esta = buscarPorIDproducto(vec, tam, id);

        if(esta == -1)
        {
            printf("\nEl ID %d no se encuentra en el sistema\n\n", id);
            system("pause");

        }
        else{

            mostrarProducto(vec[esta]);

        do{
            printf("\nConfirma modificacion? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            do{
                switch(menuModificaproducto()){
                    case 1:
                        printf("Ingrese el nuevo Id de producto: ");
                        scanf("%d" , &nuevoDatoProducto.idProducto);
                        vec[esta].idProducto = nuevoDatoProducto.idProducto;
                        break;

                    case 2:
                        printf("Ingrese la Descripcion: ");
                        fflush(stdin);
                        gets(nuevoDatoProducto.descripcion);
                        strcpy(vec[esta].descripcion , nuevoDatoProducto.descripcion);
                        break;
                    case 3:
                        printf("Ingrese nuevo Importe: ");
                        scanf("%f",&nuevoDatoProducto.precio);
                        vec[esta].precio = nuevoDatoProducto.precio;

                     case 4:
                        salir = 1;
                        break;
                    default:
                        printf("Opcion incorrecta");
                        system("pause");

                }

            }while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
        }
        else{
            printf("\nSe ha cancelado la modificacion\n\n");
        }

        }
}

/** \brief imprime un menu con opciones para moificar
 *
 * \return Retorna la opcion ingresada
 *
 */


int menuModificaproducto()
{
    int opcion;

    system("cls");
    printf("---Modificar Producto---\n\n");
    printf("1-ID de Producto\n");
    printf("2-Descripcion\n");
    printf("3-Precio\n");
    printf("4-Salir\n");
    printf("\nIndique opcion a modificar: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Muestra los productos de un proveedor ingresando su id
 * \param vec Array de productos
 * \param tam Tamaño del array de productos
 * \param arrays Array de Proveedores
 * \param tam1 tamaño del array de proveedores
 */

void mostrarProductosPorID(Producto vec[] , int tam,Proveedor arrays[], int tam1)
{
    ordenarPorNombreP(vec, tam);
    int idMostrar;
    char auxProveedor[50];
    int i;
    int j;
    int esta;
    int estaProveedor;
    mostrarProveedor(arrays,tam1);
    printf("Ingrese el id de Proveedor que desea mostrar: ");
                scanf("%d",&idMostrar);

    printf("\n| NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK | PROVEEDOR");
 for(i=0 ; i < tam ; i++)
    {
        for(j=0 ; j < tam1 ;j++)
        {
            if(arrays[j].estado == 0 && idMostrar == arrays[j].IDProveedor )
            {
                strcpy(auxProveedor,arrays[j].Descripcion);
            }
            if(vec[i].estado2 == 0 && idMostrar==vec[i].idProveedor )
            {



    printf("\n%10s| %-35s | %9d | %5.2f | %5d | %10s|",vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock,auxProveedor);
                printf("\n");

                break;

            }
        }
    }
}
/** \brief Muestra todos los productos de todos los provedores
 * \param vec Array de productos
 * \param tam Tamaño del array de productos
 * \param arrays Array de Proveedores
 * \param tam1 tamaño del array de proveedores
 */

void mostrarProductosProveedor(Producto vec[] , int tam,Proveedor arrays[], int tam1)
{

    ordenarPorNombreP(vec, tam);
    int idMostrar;
    char auxProveedor[50];
    int i;
    int j;
    int esta;
    int estaProveedor;
    printf("\n| PROVEEDOR | PRODUCTOS ");
    printf("\n            | NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
 for(i=0 ; i < tam ; i++)
    {
        for(j=0;j<tam1;j++)
        {
            if(arrays[j].estado == 0 && vec[i].idProveedor == arrays[j].IDProveedor )
            {
                strcpy(auxProveedor,arrays[j].Descripcion);
            }
            if(vec[i].estado2 == 0 && arrays[j].IDProveedor == vec[i].idProveedor )
            {
                printf("\n|%10s|%10s| %-35s | %9d | %5.2f | %5d |",auxProveedor,vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock);
                printf("\n");
                break;
            }
        }
    }
}
/** \brief Muestra el proveedores y los productos con cantidad <= 10
 * \param vec Array de productos
 * \param tam1 Tamaño del array de productos
 * \param array Array de Proveedores
 * \param tam tamaño del array de proveedores
 */

void mostrarProveedorstock(Proveedor array[],int tam,Producto vec[],int tam1)
{
    int flag=0;
    int i,j;
    char auxProveedor[50];
    int stockMenor;

 for(i=0 ; i < tam1 ; i++)
    {
        for(j=0;j<tam;j++)
        {

            if(vec[i].estado2 == 0 && array[j].IDProveedor == vec[i].idProveedor && vec[i].stock <= 10 )
            {
                strcpy(auxProveedor,array[j].Descripcion);
                printf("\n| PROVEEDOR  | PRODUCTO  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
                printf("\n|%10s| %10s| %-37s | %9d | %5.2f | %5d |\n",auxProveedor,vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock);
                printf("\n");
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        printf("No existe un provedor con un producto cuyo stock sea <= 10\n");
    }
}
/** \brief Muestra los productos con cantidad mayor a 10
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 *
 */

void CantidadMayoDiez(Producto vec[],int tam)
{
    ordenarPorNombreP(vec, tam);
    int i;

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado2 == 0 && vec[i].stock>10)
        {
            mostrarProducto(vec[i]);
        }
    }
}
  /** \brief Muestra los productos con cantidad <= 10
   *
   * \param vec Array de productos
   * \param tam Tamaño del array
   *
   */

  void ProductoMenorDiez(Producto vec[],int tam)
{
    ordenarPorNombreP(vec, tam);
    int i;

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado2 == 0 && vec[i].stock<=10)
        {
            mostrarProducto(vec[i]);
        }
    }
}


/** \brief Muestra la cantidad de productos con cantidad <= 10
 *
 * \param vec Array de produtos
 * \param tam Tamaño del array
 */

void MostrarMenorDiez(Producto vec[],int tam)
{
    ordenarPorNombreP(vec, tam);
    int i;
    int cont=0;

    //printf("Nombre:\tIDusuario:\tEdad:\tCalificacion\tPassword\tFecha De Nacimiento DIA: MES: ANIO:\n");

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado2 == 0 && vec[i].stock<=10)
        {
            cont=cont+1;
        }
    }
    printf("La cantidad de productos con importe <= a 10 son: %d",cont);
}


/** \brief Muestra la cantidad de productos con cantidad > 10
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 */

void MostrarCantMayorDiez(Producto vec[],int tam)
{
    ordenarPorNombreP(vec, tam);
    int i;
    int cont=0;
    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado2 == 0 && vec[i].stock>=10)
        {
            cont=cont+1;
        }
    }
    printf("La cantidad de productos con importe >= a 10 son: %d",cont);
}
/** \brief Suma el total de importes de los productos
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 * \return acumulador La suma de los importes
 *
 */
float sumadorImportes(Producto vec [] , int tam)
{
    float acumulador = 0;
    int i;

    for(i=0 ;i < tam ; i++)
    {
        if(vec[i].estado2 == 0)
        {
            acumulador=acumulador+vec[i].precio;
        }
    }

    return acumulador;
}
/** \brief Cuenta la cantidad de productos activos
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 * \return cont La cantidad de productos activos
 *
 */

int contadorImportes(Producto vec[] , int tam)
{
    int cont=0;
    int i;

    for(i=0 ;i < tam ; i++)
    {
        if(vec[i].estado2 == 0)
        {
            cont++;
        }
    }

    return cont;
}
/** \brief Muestra Los productos que superan el promedio de precios
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 */

 void MostrarSuperaPromedio(Producto vec[],int tam){

 float promedio;
 int i;
 promedio=sumadorImportes(vec,tam)/contadorImportes(vec,tam);
 printf("EL PROMEDIO ES %.2f:\n",promedio);
 printf("LOS PRODUCTOS QUE SUPERAN EL PROMEDIO DEL PRECIO SON:");
 for(i=0;i<tam;i++){
    if(vec[i].estado2==0&&vec[i].precio > promedio)
        {
            mostrarProducto(vec[i]);
        }
    }
 }
 /** \brief Muestra Los productos que no superan el promedio de precios
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 */

  void MostrarNoSuperaPromedio(Producto vec[],int tam){

 float promedio;
 int i;
 promedio=sumadorImportes(vec,tam)/contadorImportes(vec,tam);
 printf("EL PROMEDIO ES %.2f:\n",promedio);
 printf("LOS PRODUCTOS QUE NO SUPERAN EL PROMEDIO DEL PRECIO SON:");
 for(i=0;i<tam;i++){
    if(vec[i].estado2==0&&vec[i].precio < promedio)
        {
            mostrarProducto(vec[i]);
        }
    }
 }
/** \brief Contabiliza los productos que superan el promedio de precio
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 * \return cont La cantidad de productos que superan el promedio de precio
 */

int contSuperaPromedio(Producto vec[],int tam){

 float promedio;
 int cont=0;
 int i;
 promedio=sumadorImportes(vec,tam)/contadorImportes(vec,tam);

 for(i=0;i<tam;i++){
    if(vec[i].estado2==0&&vec[i].precio>promedio)
        {
            cont ++;
        }
     }
 return cont;
 }
/** \brief Contabiliza los productos que no superan el promedio de precio
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 * \return cont La cantidad de productos que no superan el promedio de precio
 */

  int contNoSuperaPromedio(Producto vec[],int tam){

 float promedio;
 int cont=0;
 int i;
 promedio=sumadorImportes(vec,tam)/contadorImportes(vec,tam);

 for(i=0;i<tam;i++){
    if(vec[i].estado2==0&&vec[i].precio<promedio)
    {
        cont ++;

    }
 }
 return cont;
 }
/** \brief Busca el producto con el menor importe
 *
 * \param vec Array de productos
 * \param tam Tamaño del vector
 * \return precioMenor EL precio del producto
 */
float menorPrecio(Producto vec[],int tam)
{
    int i;
    float precioMenor = -1;

    for(i=0;i < tam; i++)
    {
        if(vec[i].estado2 == 0)
        {
            precioMenor = vec[i].precio;
            break;
        }
    }

    if(precioMenor == -1) /**< Si se cumple indica que no existen productos activos en el array */
        return -1;

    for(i=0;i < tam; i++)
    {
        if(precioMenor > vec[i].precio && vec[i].estado2 == 0)
        {
            precioMenor = vec[i].precio;
        }
    }

    return precioMenor;
}
/** \brief Muestra el Proveedor del producto mas barato junto con el producto
 *
 * \param vec Array de productos
 * \param tam Tamaño del array de productos
 * \param arrays Array de proveedores
 * \param tam1 Tamaño del array de proveedores
 */

void mostrarProductaMasBarato(Producto vec[] , int tam,Proveedor arrays[], int tam1)
{
    ordenarPorNombreP(vec, tam);
    char auxProveedor[50];
    int i,j;
    float menorprecio;

   menorprecio = menorPrecio(vec,tam);

    printf("\n| PROVEEDOR | PRODUCTOS ");
    printf("\n            | NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
 for(i=0 ; i < tam ; i++)
    {
        for(j=0;j<tam1;j++)
        {
            if(vec[i].estado2 == 0 && arrays[j].IDProveedor == vec[i].idProveedor && menorprecio == vec[i].precio )
            {
                strcpy(auxProveedor,arrays[j].Descripcion);
                printf("\n %20s| %-37s | %9d | %5.2f | %5d |\n",vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock);
                printf("\n");
                break;
            }
        }
    }
    printf("|%10s|\n",auxProveedor);
}
/** \brief Busca el producto con el mayor importe
 *
 * \param vec Array de productos
 * \param tam Tamaño del vector
 * \return precioMayor EL precio del producto
 */

float mayorPrecio(Producto vec[],int tam)
{
    int i;
    float precioMayor = -1;

    for(i=0;i < tam; i++)
    {
        if(vec[i].estado2 == 0)
        {
            precioMayor = vec[i].precio;
            break;
        }
    }

    if(precioMayor == -1) /**< Si se cumple indica que no existen productos activos en el array */
        return -1;

    for(i=0;i < tam; i++)
    {
        if(precioMayor  < vec[i].precio && vec[i].estado2 == 0)
        {
            precioMayor = vec[i].precio;
        }
    }

    return precioMayor;
}
/** \brief Muestra el Proveedor del producto mas caro junto con el producto
 *
 * \param vec Array de productos
 * \param tam Tamaño del array de productos
 * \param arrays Array de proveedores
 * \param tam1 Tamaño del array de proveedores
 */
void mostrarProductaMasCaro(Producto vec[] , int tam,Proveedor arrays[], int tam1)
{
         ordenarPorNombreP(vec, tam);
    int idMostrar;
    char auxProveedor[50];
    int i,j;

    float mayorprecio;
   mayorprecio = mayorPrecio(vec,tam);

    printf("\n| PROVEEDOR | PRODUCTOS ");
    printf("\n            | NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
 for(i=0 ; i < tam ; i++)
    {
        for(j=0;j<tam1;j++)
        {
            if(vec[i].estado2 == 0 && arrays[j].IDProveedor == vec[i].idProveedor && mayorprecio == vec[i].precio )
            {
                strcpy(auxProveedor,arrays[j].Descripcion);
                printf("\n%20s| %-37s | %9d | %5.2f | %5d |",vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock);
                printf("\n");
                break;
            }
        }
    }
printf("|%10s|\n",auxProveedor);

}

/** \brief Contabiliza los productos activos
 *
 * \param proveedor El id del proveedor
 * \param lista El vector de producto
 * \param tam, Tamalo del array
 * \return cont la cantidad de productos activos
 *
 */

int cantidadProductos(int proveedor, Producto lista[], int tam)
{
    int i, cont=0;

    for(i=0; i<tam; i++)
    {
        if(proveedor == lista[i].idProveedor && lista[i].estado2 == 0)
        {
            cont++;
        }
    }

    return cont;
}
/** \brief Contabiliza la cantidad maxima de productos activos
 *
 * \param lista El array de proveedores
 * \param tam El tamaño del array de proveedores
 * \param lista2 El array de producto
 * \param tam2 El tamaño del array de productos
 * \return maxino La mayor cantidad  de productos activos
 *
 */

int maximoProductos(Proveedor lista[], int tam, Producto lista2[], int tam2)
{
    int flag = 0, maximo, cantidad, i;

    for(i=0; i<tam; i++)
    {
        cantidad = cantidadProductos(lista[i].IDProveedor, lista2, tam);
        if(cantidad>maximo || flag==0)
        {
            maximo = cantidad;
            flag = 1;
        }
    }
    return maximo;
}
/** \brief Contabiliza la cantidad minima de productos activos
 *
 * \param lista El array de proveedores
 * \param tam El tamaño del array de proveedores
 * \param lista2 El array de producto
 * \param tam2 El tamaño del array de productos
 * \return minimo La menor cantidad  de productos activos
 *
 */

int minimoProductos(Proveedor lista[], int tam, Producto lista2[], int tam2)
{
    int flag = 0, minimo, cantidad, i;

    for(i=0; i<tam; i++)
    {
        cantidad = cantidadProductos(lista[i].IDProveedor, lista2, tam);
        if(cantidad<minimo || flag==0)
        {
            minimo = cantidad;
            flag = 1;
        }
    }
    if(minimo<=0){
        minimo=1;
        return minimo;
    }else{
        return minimo;
    }

}
/** \brief Muetsra el proveedor mas productos incluyendo dichos productos
 *
 * \param proveedor El array de proveedores
 * \param tamPROV El tamaño del array de proveedores
 * \param productos El array de producto
 * \param tamPROD El tamaño del array de productos
 *
 */
void proveedorConMasProductos(Proveedor proveedor[], int tamPROV, Producto productos[], int tamPROD)
{
    int i, j, cant,idprov;

    system("cls");
    cant = maximoProductos(proveedor, tamPROV, productos, tamPROD);

            printf("\n    PROVEEDOR        | NOMBRE PRODUCTO |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");

    for(i=0; i<tamPROV; i++)
    {
        if(cant==cantidadProductos(proveedor[i].IDProveedor, productos, tamPROD))
        {
            printf("\n\n%s:\n", proveedor[i].Descripcion);
            idprov = proveedor[i].IDProveedor;
            for(j=0; j<tamPROD; j++)
            {
                if( productos[j].idProveedor == idprov && productos[j].estado2==0)
                {
                    printf("\n%30s| %-37s | %9d | %5.2f | %5d |",productos[j].nombreProducto,productos[j].descripcion,productos[j].idProducto,productos[j].precio,productos[j].stock);
                }
            }
        }
    }
    printf("\n\n");

}
/** \brief Muetsra el proveedor mas productos incluyendo dichos productos
 *
 * \param proveedor El array de proveedores
 * \param tamPROV El tamaño del array de proveedores
 * \param productos El array de producto
 * \param tamPROD El tamaño del array de productos
 *
 */
void proveedorConMenosProductos(Proveedor proveedor[], int tamPROV, Producto productos[], int tamPROD)
{
    int i, j, cant,idprov;

    system("cls");
    cant = minimoProductos(proveedor, tamPROV, productos, tamPROD);
    printf("%d",cant);
    system("pause");
            printf("\n PROVEEDOR | NOMBRE PRODUCTO |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");

    for(i=0; i<tamPROV; i++)
    {
        if(cant==cantidadProductos(proveedor[i].IDProveedor, productos, tamPROD))
        {
            printf("\n\n%s:\n", proveedor[i].Descripcion);
            idprov = proveedor[i].IDProveedor;
            for(j=0; j<tamPROD; j++)
            {
                if( productos[j].idProveedor == idprov && productos[j].estado2==0)
                {
                    printf("\n%30s| %-37s | %9d | %5.2f | %5d |",productos[j].nombreProducto,productos[j].descripcion,productos[j].idProducto,productos[j].precio,productos[j].stock);
                }
            }
        }
    }
    printf("\n\n");

}


/**
 * \brief Carga los valores del Proveedor
 * \param ProveedorArray Es el array de Proveedores
 * \param POS Indica la posicion a setear
 * \param codeAux Codigo del Proveedor
 * \param nombreAux Titulo del PRoveedor
 * \return -
 *
 */
void hardCodeProveedores(Proveedor ProveedorArray[],int POS,char nombreAux[],int codeAux)
{

    strcpy(ProveedorArray[POS].Descripcion,nombreAux);
    ProveedorArray[POS].IDProveedor = codeAux;
    ProveedorArray[POS].estado= 0;
}
/**
 * \brief Carga los valores del Producto
 * \param ProductoArray Es el array de Producto
 * \param POS Indica la posicion a setear
 * \param codeAux Codigo del Producto
 * \param codeAux2 Codigo del Proveedor al que corresponde el producto
 * \param nombreAux Titulo del Producto
 * \param Descripcion Descripcion del Producto
 * \param Stock Stock del Producto
 * \param Importe Importe del Producto
 * \return -
 *
 */
void hardCodeProducto(Producto ProductoArray[],int POS,char nombreAux[],char Descripcion[],int codeAux,int codeAux2,int Stock,int Importe)
{

    strcpy(ProductoArray[POS].nombreProducto,nombreAux);
    strcpy(ProductoArray[POS].descripcion,Descripcion);
    ProductoArray[POS].idProducto = codeAux;
    ProductoArray[POS].idProveedor = codeAux2;
    ProductoArray[POS].stock = Stock;
     ProductoArray[POS].precio = Importe;
    ProductoArray[POS].estado2= 0;
}
/** \brief Lista las distintas opciones del usuario
 *
 * \param vec Array de producto
 * \param vec2 Array de Proveedores
 * \param tam Tamaño del array de productos
 * \param tam2 Tamaño del array de proveedores
 */

void Listados(Producto vec[],int tam,Proveedor vec2[],int tam2){
    int opcion=0;
    do{
        switch(menuListar()){
            case 1:
                printf("Productos Ordenados por Importe:\n");
                mostrarProductosOrdenImporte(vec,tam);
                printf("Productos Ordenados por Descripcion:\n");
                mostrarProductosOrdenNombre(vec,tam);
                system("pause");
                break;
            case 2:
                CantidadMayoDiez(vec,tam);
                system("pause");
                break;
            case 3:
                ProductoMenorDiez(vec,tam);
                system("pause");
                break;
            case 4:
               MostrarSuperaPromedio(vec,tam);
                system("pause");
                break;
            case 5:
                MostrarNoSuperaPromedio(vec,tam);
                system("pause");
                break;
            case 6:
                mostrarProveedorstock(vec2,tam2,vec,tam);
                 system("pause");
                break;
            case 7:
                mostrarProductosProveedor(vec,tam,vec2,tam2);
                 system("Pause");
                break;
             case 8:
                 mostrarProductosPorID(vec,tam,vec2,tam2);
                 system("Pause");
                break;
             case 9:
                 proveedorConMenosProductos(vec2,tam2,vec,tam);
                  system("Pause");
                break;
             case 10:
                 proveedorConMasProductos(vec2,tam2,vec,tam);
                 system("pause");
                break;
             case 11:
                    mostrarProductaMasCaro(vec,tam,vec2,tam2);
                  system("Pause");
                break;
             case 12:
                 //getCheaperPrice(vec,tam);
                 mostrarProductaMasBarato(vec,tam,vec2,tam2);
                 system("Pause");
                break;
             case 13:
                 opcion=1;
                break;

        }
    }while(opcion!=1);
}

/** \brief Imprime las distintas opciones a listar
 * \return opcion La opcion elegida
 */

int menuListar()
{
    int opcion;

    system("cls");
    printf("1- LISTAR PRODUCTOS ORDENADOS POR IMPORTE('DESCENDENTE') Y POR DESCRIPCION('ASCENDENTE')\n");
    printf("2- LISTAR PRODUCTOS CON CANTIDAD > 10:\n");
    printf("3- LISTAR PRODUCTOD CON CANTIDAD <= 10:\n");
    printf("4- LISTAR PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES\n");
    printf("5- LISTAR PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE LOS IMPORTES\n");
    printf("6- LISTAR PROVEEDORES CUYA CANTIDAD DE PRODUCTOS ES <= 10\n");
    printf("7- LISTAR TODOS LOS PRODUCTOS DE CADA PROVEEDOR:\n");
    printf("8- LISTAR TODOS LOS PRODUCTOS DE UN PROVEEDOR DETERMINADO:\n");
    printf("9- EL PROVEEDOR QUE PROVEE MENOS PRODUCTOS,CON LOS PRODUCTOS\n");
    printf("10- EL PROVEEDOR QUE PROVEE MAS PRODUCTOS,CON LOS PRODUCTOS\n");
    printf("11- EL PROVEEDOR QUE PROVEE EL PRODUCTO MAS CARO('muestra el proveedor con el producto'):\n");
    printf("12- EL PROVEEDOR QUE PROVEE EL PRODUCTO MAS BARATO('muestra el proveedor con el producto'):\n");
    printf("13-PARA REGRESAR\n");

    printf("\nIndique opcion a listar: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief Imprime los informes que el usuario elige
 * \return opcion La opcion elegida
 */

int menuInformar()
{
    int opcion;

    system("cls");
    printf("1- TOTAL Y RPOMEDIO DE LOS IMPORTES, Y CUANTOS NO SUPERAN ESE PROMEDIO:\n");
    printf("2- TOTAL Y RPOMEDIO DE LOS IMPORTES, Y CUANTOS SUPERAN ESE PROMEDIO:\n");
    printf("3- CANTIDAD DE PRODUCTOS CON STOCK > 10:\n");
    printf("4- CNATIDAD DE PRODUCTOS CON STOCK <= 10:\n");
    printf("5- PARA REGRESAR");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief Imrime los informes elegidos por el usuarios
 *
 * \param vec Array de productos
 * \param tam Tamaño del array
 */

void Informes(Producto vec[],int tam){
    int opcion=0;
    float sumaImportes;
    int cantimporte;
    do{switch(menuInformar()){
        case 1:
           sumaImportes = sumadorImportes(vec,tam);
           cantimporte = contadorImportes(vec,tam);
           printf("El total de la suma de los precios es : %2.f \n",sumaImportes);
           printf("El promedio de los precios es:%.2f\n",sumaImportes/cantimporte);
           printf("Y los productos que no superan ese promedio son: %d\n",contNoSuperaPromedio(vec,tam));
           system("pause");
            break;
        case 2:
           sumaImportes = sumadorImportes(vec,tam);
           cantimporte = contadorImportes(vec,tam);
           printf("El total de la suma de los precios es : %2.f \n",sumaImportes);
           printf("El promedio de los precios es:%.2f\n",sumaImportes/cantimporte);
           printf("Y los productos que superan ese promedio son: %d\n",contSuperaPromedio(vec,tam));
           system("pause");
            break;
        case 3:
            MostrarCantMayorDiez(vec,tam);
            system("pause");
            break;
        case 4:
            MostrarMenorDiez(vec,tam);
            system("pause");
            break;
        case 5:
            opcion=1;
            break;
      }

    }while(opcion!=1);
}
