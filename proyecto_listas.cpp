#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//MENU
void menu_principal();
//LIFO
void menu_lifo();
void submenu_imprimir_lifo(Nodo *);
//FIFO
void menu_fifo();
void submenu_imprimir_fifo(Nodo *,Nodo *);
//LISTA CIRCULAR SIMPLEMENTE ENLAZADA
void menu_lista_cirsimple();
void submenu_imprimir_cirsimple(Nodo *, Nodo *);
void submenu_insertar_cirsimple(Nodo *, Nodo *);
//LISTA CIRCULAR DOBLEMENTE ENLAZADAS
void menu_lista_cirdoble();
void submenu_imprimir_cirdoble(Nodo *, Nodo *);
void submenu_insertar_cirdoble(Nodo *, Nodo *);
//LISTA SIMPLEMENTE ENLAZADA
void menu_lista_simple();
void submenu_imprimir_simple(Nodo *, Nodo *);
void submenu_insertar_simple(Nodo *, Nodo *);
//LISTA DOBLEMENTE ENLAZADA
void menu_lista_doble();
void submenu_imprimir_doble(Nodo *, Nodo *);
void submenu_insertar_doble(Nodo *, Nodo *);
//OPERACIONES ANEXAS
void menu_operaciones_anexas();
//FUNCIONES
void Eliminar_dato(Nodo *&, int);
bool vacia_LIFO(Nodo *&);
void ini_pila(Nodo *&);
void ini_lista(Nodo *&, Nodo *&);
void insertar(Nodo *&, int);
void insertar_listas(Nodo *&cabeza, Nodo *&cola, int n);
void quitar(Nodo *&, int &);
void imprimir_pila(Nodo *pila);
void buscar_dato(Nodo *pila, int);
void ultimo_elemento(Nodo *);
void editar_dato(Nodo * ,int , int);
bool vacia_listas(Nodo *&);
bool colaVacia(Nodo *&cabeza);
void eliminar_fifo(Nodo *&cabeza, Nodo *&cola, int &numero);
void imprimir_listas(Nodo * cabeza);
void buscar_eliminar(Nodo * cabeza,Nodo *cola, int);
void buscar_listas(Nodo * cabeza, int);
void imprimir_listas_completa(Nodo * cabeza);
void editar_listas(Nodo *, int , int);
void insertar_lista_inicio(Nodo *&,Nodo *&,int);
void insertar_lista_final(Nodo *&,Nodo *& ,int );


//VARIABLES
void ini_lifo();
int s, e,f,n;

//FUNCION PRINCIPAL
int main()
{
    menu_principal();
    return 0;
}

void menu_principal(){
    int opcion;
    do{
        printf("\n***** MENU PRINCIPAL *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Listas LIFO\n");
        printf("\n2 Listas FIFO\n");
        printf("\n3 Listas Circulares simplemente enlazadas\n");
        printf("\n4 Listas Circulares doblemente enlazadas\n");
        printf("\n5 Listas simplemente enlazadas\n");
        printf("\n6 Listas doblemente enlazadas\n");
        printf("\n7 Operaciones Anexas\n");
        printf("\n0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: exit(0);
                break;
            case 1: menu_lifo();
                break;
            case 2: menu_fifo();
                break;
            case 3: menu_lista_cirsimple();
                break;
            case 4: menu_lista_cirdoble();
                break;
            case 5: menu_lista_simple();
                break;
            case 6: menu_lista_doble();
                break;
            case 7: menu_operaciones_anexas();
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

/*
* LIFO
*/

void menu_lifo(){
    Nodo *pila = reservar_memoria;
    int opcion, dato_buscar,eliminar,editar,numero_editar;
    do{
        printf("\n***** MENU LISTA LIFO *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Crear lista\n");
        printf("2 Insertar elementos\n");
        printf("3 Imprimir elementos\n");
        printf("4 Buscar elementos\n");
        printf("5 Eliminar elementos\n");
        printf("6 Editar elemento\n");
        printf("7 vaciar elementos\n");
        printf("8 Lista vacia\n");
        printf("9 Eliminar lista\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);
        switch(opcion){
             case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nCREAR LISTA LIFO\n");
                ini_pila(pila);
                printf("\nlifo creada exitosamente!\n");
                break;
            case 2:
                printf("Presiones (0) cuando termine el ingreso de numeros");
                do{
                    printf("\nIngrese un numero: ");
                    scanf("%d",&n);
                    if(n!=0)insertar(pila, n);
                }while(n!=0);
                break;
            case 3:
                submenu_imprimir_lifo(pila);
                break;
            case 4:
                printf("ingrese dato a buscar\n");
                scanf("%d",&dato_buscar);
                buscar_dato(pila, dato_buscar);
                break;
            case 5:
                printf("que elemento desea eliminar\n");
                scanf("%d",&eliminar);
                Eliminar_dato(pila,eliminar);

                break;
            case 6:
                printf("Que elemento desea editar\n");
                scanf("%d",&numero_editar);

                printf("Por cual elemento desea editarlo\n");
                scanf("%d",&editar);

                editar_dato(pila,numero_editar,editar);
                break;
            case 7:
                printf("\nELIMINAR ELEMENTOS\n\n");
                    while(pila!=NULL){
                    quitar(pila,n);
                    }
                    if(vacia_LIFO(pila)){
                        printf("\nElementos eliminados correctamente!\n\n");
                    }
                break;
            case 8:
                printf("\nLIFO VACIA\n");
                    if(vacia_LIFO(pila)){
                        printf("\nLa lista LIFO esta vacia!\n\n");
                    }else{
                        printf("\nLa lista LIFO  no esta vacia!\n");
                    }
                break;
            case 9:
                    free(pila);
                    printf("\nLista eliminada correctamente!\n\n");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void submenu_imprimir_lifo(Nodo *pila){
    int opcion;
    do{
        printf("\n***ELIJA CUAL ELEMENTO DESEA MOSTRAR***\n");
        printf("1 Mostrar el primer elemento\n");
        printf("2 Mostrar el ultimo elemento\n");
        printf("3 Mostrar todos los elementos\n");
        printf("0 Voler al Menu principal\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\n EL PRIMER ELEMENTO ES: %d\n",pila ->dato);
                break;
            case 2:

                printf("\nEL ULTIMO ELEMENTO ES: \n");
                ultimo_elemento(pila);
                break;
            case 3:
                printf("\nMOSTRAR TODOS LOS ELEMENTOS \n\n");
                printf("\nLa lista LIFO contiene los siguientes elementos: \n\n");
                imprimir_pila(pila);

                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void ini_pila(Nodo *&pila){
    pila = NULL;
}

bool vacia_LIFO(Nodo *&pila)
{
    return (pila==NULL)?true: false;
}

void insertar(Nodo *&pila, int n){
    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    printf("dato %c, insertado con exito", n);
}

void quitar(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    free(aux);
}

void imprimir_pila(Nodo *pila)
{
    Nodo *primero=reservar_memoria;

    primero=pila;
    if(pila!=NULL)
    {
        while(primero != NULL){
            printf("%d ",primero -> dato);
            primero=primero ->siguiente;
            printf("\n");
        }
    }else{
        printf("\n pila vacia\n");
    }
}

void buscar_dato(Nodo *pila, int dato_buscar)
{
    int i=1;
    Nodo *primero=reservar_memoria;
    primero=pila;

    if(pila!=NULL)
    {
        while(primero != NULL)
        {
            if(primero ->dato==dato_buscar)
            {
                printf("\nDato %d encontrado en la posicion %d\n", dato_buscar, i);
            }
                primero=primero -> siguiente;
                i++;
        }
    }else{printf("\npila vacia");}
}

void editar_dato(Nodo *pila, int numero_editar, int editar)
{
    Nodo *primero=reservar_memoria;
    primero=pila;

    if(pila!=NULL)
    {
        while(primero != NULL)
        {
            if(primero ->dato==numero_editar)
            {
                primero ->dato=editar;
                printf("\nDato editado exitosamente\n");
            }
                primero=primero -> siguiente;
        }
    }else{printf("\npila vacia");}
}

void Eliminar_dato(Nodo *&pila,int eliminar)
{
    Nodo *primero=reservar_memoria;
    Nodo *anterior=reservar_memoria;
    Nodo *aux=reservar_memoria;
    primero = pila;
    anterior = primero;

    if(pila!=NULL)
    {
        while(primero != NULL)
        {
            if(primero->dato==eliminar)
            {
                if(pila==primero)
                {
                    pila=primero->siguiente;
                    printf("\nel dato fue eliminado exitosamente\n");
                }
                else
                {
                    anterior->siguiente=primero->siguiente;
                    printf("\nel dato fue eliminado exitosamente\n");
                }

            }
            anterior=primero;
            primero=primero->siguiente;

        }
    }else
    {
        printf("\npila vacia");
    }
    free(primero);
    free(anterior);
}

void ultimo_elemento(Nodo * pila)
{
    Nodo *primero=reservar_memoria;

    primero=pila;
    if(pila!=NULL)
    {
        while(primero != NULL)
        {
            if(primero ->siguiente==NULL)
            {
                printf("%d\n",primero ->dato);
            }
            primero=primero ->siguiente;
        }
    }else{
        printf("\n pila vacia");
    }

}


/*
* FIFO
*/

void menu_fifo(){
    Nodo *cabeza = reservar_memoria;
    Nodo *cola = reservar_memoria;
    int opcion, dato_buscar,dato_eliminar,numero_editar,editar;
    do{
        printf("\n***** MENU LISTA FIFO *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Crear lista\n");
        printf("2 Insertar elementos\n");
        printf("3 Imprimir elementos\n");
        printf("4 Buscar elementos\n");
        printf("5 Eliminar elementos\n");
        printf("6 Editar elemento\n");
        printf("7 vaciar elementos\n");
        printf("8 Lista vacia\n");
        printf("9 Eliminar lista\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);
        switch(opcion){
             case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nCREAR LISTA FIFO\n");
                ini_lista(cabeza, cola);
                printf("\nfifo creada exitosamente!\n");
                break;
            case 2:
                printf("Presiones (0) cuando termine el ingreso de numeros");
                do{
                    printf("\nIngrese un numero: ");
                    scanf("%d",&n);
                    if(n!=0)
                    insertar_listas(cabeza, cola, n);
                }while(n!=0);
                break;
            case 3:
                submenu_imprimir_fifo(cabeza,cola);
                break;
            case 4:
                printf("\ningrese el dato a buscar\n");
                scanf("%d",&dato_buscar);
                buscar_listas(cabeza, dato_buscar);
                break;
            case 5:
                printf("ingrese dato a eliminar");
                scanf("%d",&dato_eliminar);
                buscar_eliminar(cabeza,cola, dato_eliminar);
                break;
            case 6:
                printf("Que elemento desea editar\n");
                scanf("%d",&numero_editar);

                printf("Por cual elemento desea editarlo\n");
                scanf("%d",&editar);

                editar_listas(cabeza,numero_editar,editar);
                break;
            case 7:
                printf("\nVACIAR ELEMENTOS\n");
                while(vacia_listas(cabeza)!=true){
                    eliminar_fifo(cabeza,cola,n);
                }
                printf("\nElementos eliminados correctamente\n");
                break;
            case 8:
                if(vacia_listas(cabeza)==true)
                {
                    printf("\nla lista esta vacia\n");
                }
                else{
                    printf("\nla lista tiene elementos\n");
                }
                break;
            case 9:
                free(cabeza);
                free(cola);
                printf("\nlista eliminada correctamente\n");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void submenu_imprimir_fifo(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA CUAL ELEMENTO DESEA MOSTRAR***\n");
        printf("1 Mostrar el primer elemento\n");
        printf("2 Mostrar el ultimo elemento\n");
        printf("3 Mostrar todos los elementos\n");
        printf("0 Voler al Menu principal\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                if(cabeza!=NULL)
                {
                    printf("\nel primer elemento es: %d\n",cabeza->dato);
                }
                else{
                    printf("\nlista vacia\n");
                }
                break;
            case 2:
                printf("\nel ultimo elemento es:\n");
                imprimir_listas(cabeza);
                break;
            case 3:
                imprimir_listas_completa(cabeza);
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void ini_lista(Nodo *&cabeza, Nodo *&cola){
    cabeza = NULL;
    cola = NULL;
}

void insertar_listas(Nodo *&cabeza, Nodo *&cola, int num)
{
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo -> dato = num;
    nuevo_nodo -> siguiente = NULL;
    if(vacia_listas(cabeza)){
        cabeza = nuevo_nodo;
    }else{
        cola -> siguiente = nuevo_nodo;
    }
    cola = nuevo_nodo;
    printf("\n Dato insertado correctamente \n");
}

bool vacia_listas(Nodo *&cabeza)
{
    return (cabeza==NULL)?true: false;
}

void eliminar_fifo(Nodo *&cabeza, Nodo *&cola, int &numero){
    numero = cabeza -> dato;
    Nodo *aux = reservar_memoria;
    aux = cabeza;
    if(cabeza == cola){
        cabeza = NULL;
        cola = NULL;
    }else{
        cabeza = aux -> siguiente;
    }
    free(aux);
}

void imprimir_listas(Nodo * cabeza)
{
    Nodo *primero=reservar_memoria;

    primero=cabeza;
    if(cabeza!=NULL)
    {
        while(primero != NULL)
        {
            if(primero ->siguiente==NULL)
            {
                printf("%d\n",primero ->dato);
            }
            primero=primero ->siguiente;
        }
    }else{
        printf("\n cola vacia");
    }

}

void buscar_eliminar(Nodo *cabeza,Nodo *cola, int dato_eliminar)
{
    int encontrado=0;
    Nodo *primero=reservar_memoria;
    primero=cabeza;
    Nodo *anterior=reservar_memoria;
    anterior=NULL;

    if(cabeza!=NULL)
    {
        while(primero != NULL && encontrado !=1)
        {
            if(primero ->dato==dato_eliminar)
            {
                if(primero==cabeza)
                {
                    cabeza=cabeza->siguiente;
                }
                else
                    if(primero==cola)
                    {
                        anterior->siguiente=NULL;
                        cola=anterior;
                    }
                    else
                    {
                        anterior->siguiente=primero->siguiente;
                    }
                    encontrado=1;
            }
            anterior=primero;
            primero=primero->siguiente;
        }
        if(encontrado==0)
        {
            printf("\ndato encontrado\n");
        }
        else{
            free(anterior);
        }
    }
    else{
        printf("\nel dato no existe\n");
    }
}

void buscar_listas(Nodo *cabeza, int dato_buscar)
{
    int i=1,encontrado=0;
    Nodo *primero=reservar_memoria;
    primero=cabeza;
    if(cabeza!=NULL)
    {
        while(primero != NULL && encontrado !=1)
        {
            if(primero ->dato==dato_buscar)
            {
                printf("\nDato %d encontrado en la posicion %d\n", dato_buscar, i);
                encontrado=1;
            }
            primero=primero->siguiente;
            i++;
        }
        if(encontrado==0)
        {
            printf("\ndato encontrado\n");
        }
    }
    else{
        printf("\nel dato no existe\n");
    }
}

void imprimir_listas_completa(Nodo * cabeza)
{
    Nodo *primero=reservar_memoria;
    primero=cabeza;
    if(cabeza!=NULL)
    {
        while(primero != NULL)
        {
            if(primero !=NULL)
            {
                printf("%d\n",primero ->dato);
                primero=primero ->siguiente;
            }
        }
    }else{
        printf("\n cola vacia");
    }

}

void editar_listas(Nodo *cabeza, int numero_editar, int editar)
{
    Nodo *primero=reservar_memoria;
    primero=cabeza;

    if(cabeza!=NULL)
    {
        while(primero != NULL)
        {
            if(primero ->dato==numero_editar)
            {
                primero ->dato=editar;
                printf("\nDato editado exitosamente\n");
            }
                primero=primero -> siguiente;
        }
    }else{printf("\npila vacia");}
}

void lista_vacia()
{
    Nodo * cabeza = NULL;
    Nodo * cola = NULL;
}


/*
*  LISTAS CIRCULARES SIMPLES
*/
void menu_lista_cirsimple()
{
    Nodo *cabeza = reservar_memoria;
    Nodo *cola = reservar_memoria;
    int opcion, dato_buscar,dato_eliminar,numero_editar,editar;
    do{
        printf("\n***** MENU LISTAS CIRCULARES SIMPLEMENTE ENLAZADAS *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Crear lista\n");
        printf("2 Insertar elementos\n");
        printf("3 Imprimir elementos\n");
        printf("4 Buscar elementos\n");
        printf("5 Eliminar elementos\n");
        printf("6 Editar elemento\n");
        printf("7 vaciar elementos\n");
        printf("8 Lista vacia\n");
        printf("9 Eliminar lista\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);

        switch(opcion){
             case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nCREAR LISTA\n");
                ini_lista(cabeza, cola);
                printf("\nlista creada exitosamente!\n");
                break;
            case 2:
                submenu_insertar_cirsimple(cabeza,cola);
                break;
            case 3:
                submenu_imprimir_cirsimple(cabeza,cola);
                break;
            case 4:
                printf("\ningrese el dato a buscar\n");
                scanf("%d",dato_buscar);
                buscar_listas(cabeza, dato_buscar);
                break;
            case 5:
                printf("ingrese dato a eliminar");
                scanf("%d",&dato_eliminar);
                buscar_eliminar(cabeza,cola, dato_eliminar);
                break;
            case 6:
                printf("Que elemento desea editar\n");
                scanf("%d",&numero_editar);

                printf("Por cual elemento desea editarlo\n");
                scanf("%d",&editar);

                editar_listas(cabeza,numero_editar,editar);
                break;
            case 7:
                printf("\n case 7 \n");
                break;
            case 8:
                printf("\n case 8 \n");
                break;
            case 9:
                printf("\n case 9 \n");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void submenu_imprimir_cirsimple(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA IMPRIMIR***\n");
        printf("1 Mostrar el primer elemento\n");
        printf("2 Mostrar el ultimo elemento\n");
        printf("3 Mostrar todos los elementos\n");
        printf("4 Mostrar el anterior elemento aun nodo dado\n");
        printf("5 Mostrar el siguiente elemento aun nodo dado\n");
        printf("0 Volver al menu\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nel primer elemento es: %d ",&cabeza->dato);
                break;
            case 2:
                imprimir_listas(cabeza);
                break;
            case 3:
                imprimir_listas_completa(cabeza);
                break;
            case 4:
                printf("Mostrar el anterior elemento aun nodo dado");
                break;
            case 5:
                printf("Mostrar el siguiente elemento aun nodo dado");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}


void submenu_insertar_cirsimple(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA INSERTAR***\n");
        printf("1 Al inicio\n");
        printf("2 Al final\n");
        printf("3 Despues de un nodo\n");
        printf("4 Antes de un nodo\n");
        printf("5 En medio de dos nodos\n");
        printf("6 En forma ascendente\n");
        printf("7 En forma descendente\n");
        printf("0 volver al menu\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("al inicio");
                break;
            case 2:
                printf("al final");
                break;
            case 3:
                printf("despues de un nodo");
                break;
            case 4:
                printf("antes de un nodo");
                break;
            case 5:
                printf("en medio de dos nodos");
                break;
            case 6:
                printf("en forma ascendente");
                break;
            case 7:
                printf("en forma descendente");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}


/*
*  LISTAS CIRCULARES DOBLES
*/
void menu_lista_cirdoble()
{
    Nodo *cabeza = reservar_memoria;
    Nodo *cola = reservar_memoria;
    int opcion, dato_buscar,dato_eliminar,numero_editar,editar;
    do{
        printf("\n***** MENU LISTAS CIRCULARES SIMPLEMENTE ENLAZADAS *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Crear lista\n");
        printf("2 Insertar elementos\n");
        printf("3 Imprimir elementos\n");
        printf("4 Buscar elementos\n");
        printf("5 Eliminar elementos\n");
        printf("6 Editar elemento\n");
        printf("7 vaciar elementos\n");
        printf("8 Lista vacia\n");
        printf("9 Eliminar lista\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);

        switch(opcion){
             case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nCREAR LISTA\n");
                ini_lista(cabeza, cola);
                printf("\nlista creada exitosamente!\n");
                break;
            case 2:
                submenu_insertar_cirdoble(cabeza,cola);
                break;
            case 3:
                submenu_imprimir_cirdoble(cabeza,cola);
                break;
            case 4:
                printf("\ningrese el dato a buscar\n");
                scanf("%d",dato_buscar);
                buscar_listas(cabeza, dato_buscar);
                break;
            case 5:
                printf("ingrese dato a eliminar");
                scanf("%d",&dato_eliminar);
                buscar_eliminar(cabeza,cola, dato_eliminar);
                break;
            case 6:
                printf("Que elemento desea editar\n");
                scanf("%d",&numero_editar);

                printf("Por cual elemento desea editarlo\n");
                scanf("%d",&editar);

                editar_listas(cabeza,numero_editar,editar);
                break;
            case 7:
                printf("\n case 7 \n");
                break;
            case 8:
                printf("\n case 8 \n");
                break;
            case 9:
                printf("\n case 9 \n");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void submenu_imprimir_cirdoble(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA IMPRIMIR***\n");
        printf("1 Mostrar el primer elemento\n");
        printf("2 Mostrar el ultimo elemento\n");
        printf("3 Mostrar todos los elementos\n");
        printf("4 Mostrar el anterior elemento aun nodo dado\n");
        printf("5 Mostrar el siguiente elemento aun nodo dado\n");
        printf("6 Mostrar elementos de izquierda a derecha\n");
        printf("7 Mostrar elementos de derecha a izquierda\n");
        printf("0 Volver al menu\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nel primer elemento es: %d ",&cabeza->dato);
                break;
            case 2:
                imprimir_listas(cabeza);
                break;
            case 3:
                imprimir_listas_completa(cabeza);
                break;
            case 4:
                printf("Mostrar el anterior elemento aun nodo dado");
                break;
            case 5:
                printf("Mostrar el siguiente elemento aun nodo dado");
                break;
            case 6:
                printf("Mostrar elementos de izquierda a derecha");
                break;
            case 7:
                printf("Mostrar elementos de derecha a izquierda");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}


void submenu_insertar_cirdoble(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA INSERTAR***\n");
        printf("1 Al inicio\n");
        printf("2 Al final\n");
        printf("3 Despues de un nodo\n");
        printf("4 Antes de un nodo\n");
        printf("5 En medio de dos nodos\n");
        printf("6 En forma ascendente\n");
        printf("7 En forma descendente\n");
        printf("0 volver al menu\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("al inicio");
                break;
            case 2:
                printf("al final");
                break;
            case 3:
                printf("despues de un nodo");
                break;
            case 4:
                printf("antes de un nodo");
                break;
            case 5:
                printf("en medio de dos nodos");
                break;
            case 6:
                printf("en forma ascendente");
                break;
            case 7:
                printf("en forma descendente");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

/*
*  LISTAS SIMPLES
*/
void menu_lista_simple()
{
    Nodo *cabeza = reservar_memoria;
    Nodo *cola = reservar_memoria;
    int opcion, dato_buscar,dato_eliminar,numero_editar,editar;
    do{
        printf("\n***** MENU LISTAS CIRCULARES SIMPLEMENTE ENLAZADAS *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Crear lista\n");
        printf("2 Insertar elementos\n");
        printf("3 Imprimir elementos\n");
        printf("4 Buscar elementos\n");
        printf("5 Eliminar elementos\n");
        printf("6 Editar elemento\n");
        printf("7 vaciar elementos\n");
        printf("8 Lista vacia\n");
        printf("9 Eliminar lista\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);

        switch(opcion){
             case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nCREAR LISTA\n");
                ini_lista(cabeza, cola);
                printf("\nlista creada exitosamente!\n");
                break;
            case 2:
                submenu_insertar_simple(cabeza,cola);
                break;
            case 3:
                submenu_imprimir_simple(cabeza,cola);
                break;
            case 4:
                printf("\ningrese el dato a buscar\n");
                scanf("%d",dato_buscar);
                buscar_listas(cabeza, dato_buscar);
                break;
            case 5:
                printf("ingrese dato a eliminar");
                scanf("%d",&dato_eliminar);
                buscar_eliminar(cabeza,cola, dato_eliminar);
                break;
            case 6:
                printf("Que elemento desea editar\n");
                scanf("%d",&numero_editar);

                printf("Por cual elemento desea editarlo\n");
                scanf("%d",&editar);

                editar_listas(cabeza,numero_editar,editar);
                break;
            case 7:
                printf("\n case 7 \n");
                break;
            case 8:
                printf("\n case 8 \n");
                break;
            case 9:
                printf("\n case 9 \n");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void submenu_imprimir_simple(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA IMPRIMIR***\n");
        printf("1 Mostrar el primer elemento\n");
        printf("2 Mostrar el ultimo elemento\n");
        printf("3 Mostrar todos los elementos\n");
        printf("4 Mostrar el anterior elemento aun nodo dado\n");
        printf("5 Mostrar el siguiente elemento aun nodo dado\n");
        printf("0 Volver al menu\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nel primer elemento es: %d ",&cabeza->dato);
                break;
            case 2:
                imprimir_listas(cabeza);
                break;
            case 3:
                imprimir_listas_completa(cabeza);
                break;
            case 4:
                printf("Mostrar el anterior elemento aun nodo dado");
                break;
            case 5:
                printf("Mostrar el siguiente elemento aun nodo dado");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}


void submenu_insertar_simple(Nodo *cabeza, Nodo *cola){
    int opcion,dato_ingresado;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA INSERTAR***\n");
        printf("1 Al inicio\n");
        printf("2 Al final\n");
        printf("3 Despues de un nodo\n");
        printf("4 Antes de un nodo\n");
        printf("5 En medio de dos nodos\n");
        printf("6 En forma ascendente\n");
        printf("7 En forma descendente\n");
        printf("0 volver al menu\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nDATO INGRESADO AL INICIO\n");
                printf("\ningrese el dato\n");
                scanf("%d",&dato_ingresado);
                insertar_lista_inicio(cabeza,cola,dato_ingresado);
                break;
            case 2:
                printf("\nDATO INGRESADO AL INICIO\n");
                scanf("%d",&dato_ingresado);
                insertar_lista_final(cabeza,cola,dato_ingresado);
                break;
            case 3:
                printf("despues de un nodo");
                break;
            case 4:
                printf("antes de un nodo");
                break;
            case 5:
                printf("en medio de dos nodos");
                break;
            case 6:
                printf("en forma ascendente");
                break;
            case 7:
                printf("en forma descendente");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void insertar_lista_inicio(Nodo *& cabeza,Nodo *& cola,int num)
{
    Nodo *nuevo_nodo = reservar_memoria;
    Nodo *anterior = reservar_memoria;
    nuevo_nodo -> dato = num;

    if(vacia_listas(cabeza)){
        cabeza = nuevo_nodo;
        nuevo_nodo -> siguiente = NULL;
        cola=nuevo_nodo;
    }else{


        cabeza = nuevo_nodo;
        cabeza->siguiente=anterior;
        nuevo_nodo ->siguiente=anterior->siguiente;

    }
    printf("\n Dato insertado correctamente \n");
}

void insertar_lista_final(Nodo *& cabeza,Nodo *& cola,int num)
{
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo -> dato = num;

    if(vacia_listas(cabeza)){
        cabeza = nuevo_nodo;
        nuevo_nodo -> siguiente = NULL;
        cola=nuevo_nodo;
    }else{
        cola -> siguiente = nuevo_nodo;
        nuevo_nodo ->siguiente=NULL;
        cola=nuevo_nodo;
    }
    printf("\n Dato insertado correctamente \n");
}



/*
*  LISTAS DOBLES
*/
void menu_lista_doble()
{
    Nodo *cabeza = reservar_memoria;
    Nodo *cola = reservar_memoria;
    int opcion, dato_buscar,dato_eliminar,numero_editar,editar;
    do{
        printf("\n***** MENU LISTAS CIRCULARES SIMPLEMENTE ENLAZADAS *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("\n1 Crear lista\n");
        printf("2 Insertar elementos\n");
        printf("3 Imprimir elementos\n");
        printf("4 Buscar elementos\n");
        printf("5 Eliminar elementos\n");
        printf("6 Editar elemento\n");
        printf("7 vaciar elementos\n");
        printf("8 Lista vacia\n");
        printf("9 Eliminar lista\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);

        switch(opcion){
             case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nCREAR LISTA\n");
                ini_lista(cabeza, cola);
                printf("\nlista creada exitosamente!\n");
                break;
            case 2:
                submenu_insertar_doble(cabeza,cola);
                break;
            case 3:
                submenu_imprimir_doble(cabeza,cola);
                break;
            case 4:
                printf("\ningrese el dato a buscar\n");
                scanf("%d",dato_buscar);
                buscar_listas(cabeza, dato_buscar);
                break;
            case 5:
                printf("ingrese dato a eliminar");
                scanf("%d",&dato_eliminar);
                buscar_eliminar(cabeza,cola, dato_eliminar);
                break;
            case 6:
                printf("Que elemento desea editar\n");
                scanf("%d",&numero_editar);

                printf("Por cual elemento desea editarlo\n");
                scanf("%d",&editar);

                editar_listas(cabeza,numero_editar,editar);
                break;
            case 7:
                printf("\n case 7 \n");
                break;
            case 8:
                printf("\n case 8 \n");
                break;
            case 9:
                printf("\n case 9 \n");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void submenu_imprimir_doble(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA IMPRIMIR***\n");
        printf("1 Mostrar el primer elemento\n");
        printf("2 Mostrar el ultimo elemento\n");
        printf("3 Mostrar todos los elementos\n");
        printf("4 Mostrar el anterior elemento aun nodo dado\n");
        printf("5 Mostrar el siguiente elemento aun nodo dado\n");
        printf("6 Mostrar elementos de izquierda a derecha\n");
        printf("7 Mostrar elementos de derecha a izquierda\n");
        printf("0 Volver al menu\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("\nel primer elemento es: %d ",&cabeza->dato);
                break;
            case 2:
                imprimir_listas(cabeza);
                break;
            case 3:
                imprimir_listas_completa(cabeza);
                break;
            case 4:
                printf("Mostrar el anterior elemento aun nodo dado");
                break;
            case 5:
                printf("Mostrar el siguiente elemento aun nodo dado");
                break;
            case 6:
                printf("Mostrar elementos de izquierda a derecha");
                break;
            case 7:
                printf("Mostrar elementos de derecha a izquierda");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}


void submenu_insertar_doble(Nodo *cabeza, Nodo *cola){
    int opcion;
    do{
        printf("\n***ELIJA EN QUE POSICION DESEA INSERTAR***\n");
        printf("1 Al inicio\n");
        printf("2 Al final\n");
        printf("3 Despues de un nodo\n");
        printf("4 Antes de un nodo\n");
        printf("5 En medio de dos nodos\n");
        printf("6 En forma ascendente\n");
        printf("7 En forma descendente\n");
        printf("0 volver al menu\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("al inicio");
                break;
            case 2:
                printf("al final");
                break;
            case 3:
                printf("despues de un nodo");
                break;
            case 4:
                printf("antes de un nodo");
                break;
            case 5:
                printf("en medio de dos nodos");
                break;
            case 6:
                printf("en forma ascendente");
                break;
            case 7:
                printf("en forma descendente");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}


void menu_operaciones_anexas(){
    Nodo *cabeza = reservar_memoria;
    Nodo *cola = reservar_memoria;
    int opcion, dato_buscar,dato_eliminar,numero_editar,editar;
    do{
        printf("\n***** MENU OPERACIONES ANEXAS *****\n");
        printf("\nELIJA EL NUMERO DE LA OPCION QUE DESEA REALIZAR\n");
        printf("1 Concatenar dos listas\n");
        printf("2 Sumar dos listas\n");
        printf("3 Dividir dos listas\n");
        printf("4 Elevar una lista a la potencia de otra\n");
        printf("5 Copiar una lista en otra\n");
        printf("6 problema de josephus\n");
        printf("0 Para salir\n\n");
        printf("\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0: printf("\nvuelve pronto\n");
                break;
            case 1:
                printf("CASE 1");
                break;
            case 2:
                printf("CASE 2");
                break;
            case 3:
                printf("CASE 3");
                break;
            case 4:
                printf("CASE 4");
                break;
            case 5:
                printf("CASE 5");
                break;
            default: printf("\nOpcion invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}













