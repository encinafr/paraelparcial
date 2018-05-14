
#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include <string.h>

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
    int id;
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
        scanf("%d", &id);

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
                   scanf("%s",nuevoProveedor.Descripcion);

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
    int indice;
    int id;
    int existe;
    //char nombreProducto[50];
    Producto nuevoProducto;
    int idcargar;
    int encuentra;
    int estaNombre;
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
                scanf("%d",&idcargar);
                encuentra = buscarPorID(arrays,tamanio,idcargar);
                if(encuentra == -1)
                        {
                            printf("\nEl id %d no esta dado de alta en el sistema\n", idcargar);
                            system("pause");
                        }else{

        printf("Ingrese id de Producto: ");
        fflush(stdin);
        scanf("%d",&id);

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
                   scanf("%s",nuevoProducto.nombreProducto);

                   printf("Ingrese Descripcion('No mas de 100 caracteres'): ");
                   fflush(stdin);
                   gets(nuevoProducto.descripcion);

                   printf("Ingrese Importe: ");
                   fflush(stdin);
                   scanf("%f", &nuevoProducto.precio);
                   while(nuevoProducto.precio <=0){
                    printf("ERROr,Reingrese el Importe: ");
                   fflush(stdin);
                   scanf("%f", &nuevoProducto.precio);
                   }
                    printf("Ingrese Cantidad del producto");
                    scanf("%d",&nuevoProducto.stock);

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
    printf("\n%10s| %-35s | %9d | %5.2f | %5d |",vec.nombreProducto,vec.descripcion,vec.idProducto,vec.precio,vec.stock);
}
/** \brief Recorre el vector y pregunta por el estado para imprimir solo los datos que esten cargados sin basura
 * \param vec Vector a recorrer
 * \param tam tamaño del vactor
 */


void mostrarProductosOrdenNombre(Producto vec[],int tam)
{
    int i;
    ordenarPorNombreP(vec,tam);
    printf("\n| NOMBRE  |                  DESCRIPCION        |IDPRODUCTO | PRECIO | STOCK |");
    for(i=0;i < tam; i++)
    {
        if(vec[i].estado2 == 0)
        {
          printf("\n%10s| %-35s | %9d | %5.2f | %5d |\n\n",vec[i].nombreProducto,vec[i].descripcion,vec[i].idProducto,vec[i].precio,vec[i].stock);
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

   printf("Ingrese el ID Producto: ");
        scanf("%d",&id);

        existe = buscarPorIDproducto(vec, tam, id);

        if(existe == -1)
        {
            printf("\nEl id %d no se encuentra en el sistema\n\n", id);
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
   printf("Ingrese ID de Producto: ");
        scanf("%d", &id);

        esta = buscarPorIDproducto(vec, tam, id);

        if(esta == -1)
        {
            printf("\nEl ID %d no se encuentra en el sistema\n\n", id);

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


void mostrarProductosPorID(Producto vec[] , int tam,Proveedor arrays[], int larg)
{

    ordenarPorNombreP(vec, tam);
    int idMostrar;
    int i;
    int j;
    int esta;
    int estaProveedor;
    printf("Ingrese el id de Proveedor: ");
                scanf("%d",&idMostrar);
    esta=buscarPorID(arrays,larg,idMostrar);
    if(esta==-1){
        printf("El Proveedor no esta registtrado");
        system("pause");
    }

 for(i=0 ; i < tam ; i++)
    {
        if( idMostrar==vec[i].idProveedor)
        {
            mostrarProducto(vec[i]);
            printf("\n");

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
  /** \brief
   *
   * \param
   * \param
   * \return
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


/** \brief
 *
 * \param
 * \param
 * \return
 *
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


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void MostrarCantMayorDiez(Producto vec[],int tam)
{
    ordenarPorNombreP(vec, tam);
    int i;
    int cont=0;

    //printf("Nombre:\tIDusuario:\tEdad:\tCalificacion\tPassword\tFecha De Nacimiento DIA: MES: ANIO:\n");

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado2 == 0 && vec[i].stock>=10)
        {
            cont=cont+1;
        }
    }
    printf("La cantidad de productos con importe >= a 10 son: %d",cont);
}
/** \brief
 *
 * \param
 * \param
 * \return
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
 void MostrarSuperaPromedio(Producto vec[],int tam){

 float promedio;
 int i;
 promedio=sumadorImportes(vec,tam)/contadorImportes(vec,tam);
 for(i=0;i<tam;i++){
    if(vec[i].estado2==0&&vec[i].precio>promedio)
    {
        mostrarProducto(vec[i]);
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

void mostrarProductaMasBarato(Producto vec[] , int tam,Proveedor arrays[], int larg)
{

    ordenarPorNombreP(vec, tam);
    int idMostrar;
    int i;

     for(i=0 ; i < tam ; i++)
        {

        }
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

void Listados(Producto vec[],int tam,Proveedor vec2[],int tam2){
    int opcion=0;
    do{
        switch(menuListar()){
            case 1:
                mostrarProductosOrdenImporte(vec,tam);
                mostrarProductosOrdenNombre(vec,tam);
                system("pause");
                break;
            case 2:
                MostrarCantMayorDiez(vec,tam);
                system("pause");
                break;
            case 3:
                MostrarMenorDiez(vec,tam);
                system("pause");
                break;
            case 4:
               MostrarSuperaPromedio(vec,tam);
                system("pause");
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
             case 8:
                break;
             case 9:
                break;
             case 10:
                break;
             case 11:
                break;
             case 12:
                break;
             case 13:
                 opcion=1;
                break;

        }
    }while(opcion!=1);




}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int menuListar()
{
    int opcion;

    system("cls");
    printf("1- LISTAR PRODUCTOS ORDENADOS POR IMPORTE('DESCENDENTE') Y POR DESCRIPCION('ASCENDENTE')\n");
    printf("2- LISTAR PRODUCTOS CON CANTIDAD > 10:\n");
    printf("3- LISTAR PRODUCTOD CON CANTIDAD < 10:\n");
    printf("4- LISTAR PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES\n");
    printf("5- LISTAR PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE LOS IMPORTES\n");
    printf("6- LISTAR PROVEEDORES CUYA CANTIDAD DE PRODUCTOS ES <= 10\n");
    printf("7- LISTAR TODOS LOS PRODUCTOS DE CADA PROVEEDOR:\n");
    printf("8- LISTAR TODOS LOS PRODUCTOS DE PROVEEDOR DETERMINADO:\n");
    printf("9- EL PROVEEDOR QUE PROVEE MENOS PRODUCTOS,CON LOS PRODUCTOS\n");
    printf("10- EL PROVEEDOR QUE PROVEE MAS PRODUCTOS,CON LOS PRODUCTOS\n");
    printf("11- EL PROVEEDOR QUE PROVEE EL PRODUCTO MAS CARO('muestra el producto'):\n");
    printf("12- EL PROVEEDOR QUE PROVEE EL PRODUCTO MAS BARATO('muestra el producto'):\n");
    printf("13-SALIR\n");

    printf("\nIndique opcion a listar: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int menuInformar()
{
    int opcion;

    system("cls");
    printf("1- TOTAL Y RPOMEDIO DE LOS IMPORTES, Y CUANTOS NO SUPERAN ESE PROMEDIO:\n");
    printf("2- TOTAL Y RPOMEDIO DE LOS IMPORTES, Y CUANTOS SUPERAN ESE PROMEDIO:\n");
    printf("3- CANTIDAD DE PRODUCTOS CON STOCK > 10:\n");
    printf("4- CNATIDAD DE PRODUCTOS CON STOCK <= 10:\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void Informes(Producto vec[],int tam){
    int opcion=0;
    do{switch(menuInformar()){
        case 1:
            break;
        case 2:
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
