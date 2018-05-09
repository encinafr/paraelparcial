#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Recorre el vector e inicializa el estado en uno
 *
 * \param vec el el vector que le pasamos por parametro
 * \param tam el tamaño del vector
 */

void inicializarUsuario(Usuario vec[] , int tam)
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

int obtenerEspacioLibre(Usuario lista[],int tam){

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

void mostrarDato(Usuario vec)
{
    printf("Nombre:\tIDusuario:\tEdad:\tSexo:\tPassword\tFecha De Nacimiento DIA: MES: ANIO:\n");
    printf("%s\t%d\t\t%d\t%c\t%s\t\t \t%d %d %d\n" , vec.nombre ,vec.IDusuario, vec.edad,vec.sexo,vec.password,vec.nacimiento.dia,vec.nacimiento.mes,vec.nacimiento.anio);

}
/** \brief Recorre el vector y pregunta por el estado para imprimir solo los datos que esten cargados sin basura
 * \param vec Vector a recorrer
 * \param tam tamaño del vactor
 */


void mostrarPersonas(Usuario vec[] , int tam)
{
    ordenarPorNombre(vec, tam);
    int i;

    //printf("Nombre:\tIDusuario:\tEdad:\tCalificacion\tPassword\tFecha De Nacimiento DIA: MES: ANIO:\n");

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado == 0)
        {
            mostrarDato(vec[i]);
        }
    }
}
/**
 * Obtiene el indice que coincide con el usuario pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param Usuario el usuario a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro usuario
 */
int buscarPorID(Usuario vec[],int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(vec[i].estado ==0 && id == vec[i].IDusuario)
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

void ordenarPorNombre(Usuario vec[] , int tam)
{
    int i;
    int j;
    Usuario aux;

    //printf("Dni:\tNombre:\tEdad:\n");
    for(i=0 ; i < tam-1 ; i++)
    {
        for(j=i+1 ; j < tam ; j++)
        {
            if((strcmp(vec[i].nombre , vec[j].nombre) > 0))
            {
                aux= vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
            if((strcmp(vec[i].nombre , vec[j].nombre) == 0)){
                if(vec[i].IDusuario > vec[j].IDusuario){// > mayor es ascendente < descendente;
                    aux.IDusuario=vec[i].IDusuario;
                    vec[i].IDusuario = vec[j].IDusuario;
                    vec[j].IDusuario= aux.IDusuario;

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

void agregarPersona(Usuario vec[], int tam)
{
    int indice;
    int id,i;
    int existe;
    char nombreUsuario[50];
    Usuario nuevoUsuario;
    Usuario incrementarID;
    int idUsU=1;


    system("cls");
    printf("---REGISTRAR USUARIO---\n\n");

    indice = obtenerEspacioLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a usuarios nuevos.\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese id de usuario: ");//aca seria ingrese nombre para ver si ya esta en el sistema por que el id o legajo seria incremental
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


                   //idUsU=idUsU+1;//En caso de que sea incremental tendrias que preguntar si el nombre ya se encuentra registrado
                   //nuevoUsuario.IDusuario = id;
                   //nuevoUsuario.IDusuario = idUsU;
                   nuevoUsuario.estado = 0;

                   printf("Ingrese Nombre: ");
                   fflush(stdin);
                   scanf("%s",nuevoUsuario.nombre);

                   printf("Ingrese password: ");
                   fflush(stdin);
                   scanf("%s",nuevoUsuario.password);

                   printf("Ingrese SEXO ''F o M''");
                   fflush(stdin);
                   scanf("%c",&nuevoUsuario.sexo);
                   nuevoUsuario.sexo=tolower(nuevoUsuario.sexo);


                   printf("Ingrese su fecha de nacimieto: dia/mes/anio: ");
                   fflush(stdin);
                   scanf("%d%d%d",&nuevoUsuario.nacimiento.dia,&nuevoUsuario.nacimiento.mes,&nuevoUsuario.nacimiento.anio);

                   printf("Ingrese edad: ");
                   fflush(stdin);
                   scanf("%d", &nuevoUsuario.edad);
                   while(nuevoUsuario.edad <=0){
                    printf("ERROr,Reingrese edad: ");
                   fflush(stdin);
                   scanf("%d", &nuevoUsuario.edad);
                   }





                 printf("\n Se registro correctamente!!!\n\n");
                    system("\npause\n");
           }

           for(i=0;i<tam;i++){
             if(vec[i].estado==0){

                            idUsU=idUsU+1;
                            printf("a ver %d",idUsU);

                    }
           }
             incrementarID.IDusuario=idUsU;
             nuevoUsuario.IDusuario=incrementarID.IDusuario;
        vec[indice]=nuevoUsuario;
  }
   // printf("%s %s %s %d",nuevoUsuario.nombre,nuevoUsuario.apellido,nuevoUsuario.password,nuevoUsuario.edad);
   // system("pause");
}

/** \brief Busca el id del usuario y cambia el estado para pisar sus datos
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vector
 *
 */

void borrarUsuario(Usuario vec[], int tam){
int id;
int existe;
char confirma;
Usuario nuevoUsuario;

system("cls");
printf("---Borrar Usuario---\n\n");

   printf("Ingrese el ID Usuario: ");
        scanf("%d",&id);

        existe = buscarPorID(vec, tam, id);

        if(existe == -1)
        {
            printf("\nEl id %d no se encuentra en el sistema\n\n", id);
        }
        else{

                mostrarDato(vec[existe]);

        do{
            printf("\nConfirma borrar? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){

            vec[existe].estado = 1;
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
void modificaUsuario(Usuario vec[], int tam){
    Usuario nuevoDatoUsuario;
    int id;
    int esta;
    char confirma;
    int salir = 0;

    system("cls");
    printf("---Modifica Usuario---\n\n");

   printf("Ingrese ID de usuario: ");
        scanf("%d", &id);

        esta = buscarPorID(vec, tam, id);

        if(esta == -1)
        {
            printf("\nEl ID %d no se encuentra en el sistema\n\n", id);

        }
        else{

                mostrarDato(vec[esta]);

        do{
            printf("\nConfirma modificacion? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            do{
                switch(menuModifica()){
                    case 1:
                        printf("Ingrese el nuevo Id: ");
                        scanf("%d" , &nuevoDatoUsuario.IDusuario);
                        vec[esta].IDusuario = nuevoDatoUsuario.IDusuario;
                        break;
                    case 2:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevoDatoUsuario.nombre);
                        strcpy(vec[esta].nombre , nuevoDatoUsuario.nombre);
                        break;
                    case 3:
                        printf("Ingrese el nuevo sexo: ");
                        fflush(stdin);
                        scanf("%c" , &nuevoDatoUsuario.sexo);
                        nuevoDatoUsuario.sexo=tolower(nuevoDatoUsuario.sexo);
                        vec[esta].sexo = nuevoDatoUsuario.sexo;
                        break;
                    case 4:
                        printf("Ingrese la nueva fecha: ");
                        scanf("%d %d %d", &nuevoDatoUsuario.nacimiento.dia, &nuevoDatoUsuario.nacimiento.mes, &nuevoDatoUsuario.nacimiento.anio);                        break;
                        vec[esta].nacimiento = nuevoDatoUsuario.nacimiento;
                    case 5:
                        printf("Ingrese password");
                        fflush(stdin);
                        gets(nuevoDatoUsuario.password);
                        strcpy(vec[esta].password , nuevoDatoUsuario.password);
                        break;
                        case 6:
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


int menuModifica()
{
    int opcion;

    system("cls");
    printf("---Modificar Usuario---\n\n");
    printf("1-ID de usuario\n");
    printf("2-Nombre\n");
    printf("3-Sexo\n");
    printf("4-Fecha de Nacimiento\n");
    printf("5-Password\n");
    printf("6-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
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
            if((strcmp(vec[i].nombreProducto , vec[j].nombreProducto) > 0))
            {
                aux= vec[i];
                vec[i] = vec[j];
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

void agregarProducto(Producto vec[], int tam,Usuario arrays[], int tamanio)
{
    int indice;
    int id;
    int existe;
    //char nombreProducto[50];
    Producto nuevoProducto;
    int idcargar;
    int encuentra;
    char usuarioNombre[50];
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
        printf("ingrese su nombre de usuario");
         fflush(stdin);
         scanf("%s",usuarioNombre);
         estaNombre = buscaPorNombre(arrays,tamanio,usuarioNombre);
         if(estaNombre!=-1){
            printf("Los nombres son igules\n");//si te pide ingreso por nombre de usuario o contraseña esta es la forma pero falta copiar el nombre abaajo como haces con el id
         }

        printf("Ingrese su Id de usuario");
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
                   nuevoProducto.idusuario =idcargar;
                   nuevoProducto.estado2 = 0;

                   printf("Ingrese Nombre del Producto: ");
                   fflush(stdin);
                   scanf("%s",nuevoProducto.nombreProducto);

                   printf("Ingrese Descripcion('No mas de 100 caracteres'): ");
                   fflush(stdin);
                   gets(nuevoProducto.descripcion);

                   printf("Ingrese Precio: ");
                   fflush(stdin);
                   scanf("%f", &nuevoProducto.precio);
                   while(nuevoProducto.precio <=0){
                    printf("ERROr,Reingrese el precio: ");
                   fflush(stdin);
                   scanf("%f", &nuevoProducto.precio);
                   }
                    printf("Ingrese stock del producto");
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
    printf("Nombre:\tID:\tDescripcion:\tPrecio\tstock\n");
    printf("%s\t%d\t%s\t%.2f\t%d",vec.nombreProducto,vec.idProducto,vec.descripcion,vec.precio,vec.stock);
}
/** \brief Recorre el vector y pregunta por el estado para imprimir solo los datos que esten cargados sin basura
 * \param vec Vector a recorrer
 * \param tam tamaño del vactor
 */


void mostrarProductos(Producto vec[] , int tam)
{
    ordenarPorNombreP(vec, tam);
    int i;

    //printf("Nombre:\tIDusuario:\tEdad:\tCalificacion\tPassword\tFecha De Nacimiento DIA: MES: ANIO:\n");

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado2 == 0)
        {
            mostrarProducto(vec[i]);
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
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevoDatoProducto.nombreProducto);
                        strcpy(vec[esta].nombreProducto , nuevoDatoProducto.nombreProducto);
                        break;
                    case 3:
                        printf("Ingrese la Descripcion: ");
                        fflush(stdin);
                        gets(nuevoDatoProducto.descripcion);
                        strcpy(vec[esta].descripcion , nuevoDatoProducto.descripcion);
                        break;
                    case 4:
                        printf("Ingrese nuevo precio: ");
                        scanf("%f",nuevoDatoProducto.precio);
                        vec[esta].precio = nuevoDatoProducto.precio;

                     case 5:
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
    printf("2-Nombre\n");
    printf("3-Descripcion\n");
    printf("4-Precio\n");
    printf("5-Salir\n");
    printf("\nIndique opcion a modificar: ");
    scanf("%d", &opcion);

    return opcion;
}


void mostrarProductosPorID(Producto vec[] , int tam,Usuario arrays[], int larg)
{

    ordenarPorNombreP(vec, tam);
    int idMostrar;
    int i;
    int j;
    int esta;
    int estaProducto;
    printf("Ingrese el id de usuario: ");
                scanf("%d",&idMostrar);
    esta=buscarPorID(arrays,larg,idMostrar);
    if(esta==-1){
        printf("El usuario no esta registtrado");
        system("pause");
    }

 for(i=0 ; i < tam ; i++)
    {
        if( idMostrar==vec[i].idusuario)
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
 void compraProducto(Producto vec[],int tam){
 int idProduct;
 Producto nuevostock;
 int i;
 int busca;
 int compra=0;

   printf("Ingrese el id de Prodcuto: ");
   scanf("%d",&idProduct);
    busca=buscarPorIDproducto(vec,tam,idProduct);
   if(busca==-1)
       {
        printf("El producto que desea comprar no existe\n");
        system("pause");
       }
    else{
            if(vec[busca].estado2==0){
                compra = vec[busca].stock;
               // printf("se paso el valor %d",compra);
                system("pause");
            }
           // printf("entro");
                if(vec[busca].estado2==0 && vec[busca].stock<0){
                    printf("El producto no tiene stock disponible");
                    system("pause");
                } if(vec[busca].estado2==0 && vec[busca].stock>0){
                     compra=compra-1;
                    // printf("stock %d",compra);
                     nuevostock.stock=compra;
                    vec[busca].stock=nuevostock.stock;
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
 int buscaPorNombre(Usuario vec[],int tam,char nombre[]){
  int i;
  int indice=-1;
      for(i=0;i<tam;i++){
         if(strcmp(vec[i].nombre,nombre)==0){
            indice=i;
         }
        return indice;
      }
 }
