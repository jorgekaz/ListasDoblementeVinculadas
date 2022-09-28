#include <stdio.h>
#include <stdlib.h>
#include "librerias/fila.h"
#include "librerias/listadoble.h"

//typedef struct{
//    int dato;
//    struct nodoDoble* siguiente;
//    struct nodoDoble* anterior;
//}nodoDoble;

nodoDoble* inicListaDoble();
nodoDoble* crearNodoDoble(int dato);
nodoDoble* agregarNodoPrincipio(nodoDoble* listaDoble, nodoDoble* nuevoNodo);
nodoDoble* buscarUltimoNodo(nodoDoble* listaDoble);
nodoDoble* buscarNodoDoble(nodoDoble* listaDoble, int dato);
nodoDoble* agregarNodoFinal(nodoDoble* listaDoble, nodoDoble* nuevoNodo);
nodoDoble* agregarNodoOrdenado(nodoDoble* listaDoble, nodoDoble* nuevoNodo);
nodoDoble* borrarPrimerNodo(nodoDoble* listaDoble);
void mostrarListaDoble(nodoDoble* listaDoble);
void mostrarListaDobleHaciaAtras(nodoDoble* listaDoble);
nodoDoble* devolverUltimoNodo(nodoDoble* listaDoble);
int esCapicua(nodoDoble* listaDoble, nodoDoble* ultimoNodo);
int cantidadNodos(nodoDoble* listaDoble);
nodoDoble* buscarNodo(nodoDoble* listaDoble, int cantidad);
void eliminarNodo(nodoDoble* nodoBorrar);
void eliminarNodoCentral(nodoDoble* listaDoble, int cantidad);

int main()
{
    /// EJERCICIO 1 ///
    printf("=============\n");
    printf(" EJERCICIO 1 \n");
    printf("=============\n");
    nodoDoble* listaDoble = inicListaDoble();
    nodoDoble* nuevoNodo = crearNodoDoble(10);
    listaDoble = agregarNodoPrincipio(listaDoble, nuevoNodo);
    nuevoNodo = crearNodoDoble(20);
    listaDoble = agregarNodoPrincipio(listaDoble, nuevoNodo);
    nuevoNodo = crearNodoDoble(30);
    listaDoble = agregarNodoPrincipio(listaDoble, nuevoNodo);
    nuevoNodo = crearNodoDoble(40);
    listaDoble = agregarNodoPrincipio(listaDoble, nuevoNodo);
    nuevoNodo = crearNodoDoble(50);
    listaDoble = agregarNodoPrincipio(listaDoble, nuevoNodo);
    mostrarListaDoble(listaDoble);

    nodoDoble* ultimoNodo = buscarUltimoNodo(listaDoble);
    printf("\n EL ULTIMO NODO TIENE EL DATO DE %i\n", ultimoNodo->dato);

    nodoDoble* nodoEncontrado = buscarNodoDoble(listaDoble, 30);
    if(nodoEncontrado != NULL){
        printf("\n SE ENCONTRO EL NODO CON EL VALOR %i \n", nodoEncontrado->dato);
    }else{
        printf("\n ESE DATO NO SE ENCUENTRA EN LA LISTA\n");
    }

    listaDoble = inicListaDoble();
    nuevoNodo = crearNodoDoble(2);
    listaDoble = agregarNodoFinal(listaDoble,nuevoNodo);
    nuevoNodo = crearNodoDoble(4);
    listaDoble = agregarNodoFinal(listaDoble,nuevoNodo);
    nuevoNodo = crearNodoDoble(6);
    listaDoble = agregarNodoFinal(listaDoble,nuevoNodo);
    nuevoNodo = crearNodoDoble(8);
    listaDoble = agregarNodoFinal(listaDoble,nuevoNodo);
    nuevoNodo = crearNodoDoble(10);
    listaDoble = agregarNodoFinal(listaDoble,nuevoNodo);
    printf("\n LISTA DOBLE AGREGADO NODO AL FINAL: \n\n");
    mostrarListaDoble(listaDoble);

    printf("\n LA LISTA DOBLE ANTERIOR PERO DESDE EL FINAL AL INICIO:\n\n");
    mostrarListaDobleHaciaAtras(listaDoble);

    printf("\n\n ELIMINO EL PRIMER ELEMENTO DE LA LISTA\n\n");
    listaDoble = borrarPrimerNodo(listaDoble);
    mostrarListaDoble(listaDoble);

    printf("\n\n LISTA DOBLE ANTERIOR PERO DESDE EL FINAL AL INICIO\n\n");
    mostrarListaDobleHaciaAtras(listaDoble);
    printf("\n");

    /// EJERCICIO 2 ///
    printf("=============\n");
    printf(" EJERCICIO 2 \n");
    printf("=============\n");
    nodoDoble* listaDobleDos = inicListaDoble();
    listaDobleDos = agregarNodoPrincipio(listaDobleDos,crearNodoDoble(1));
    listaDobleDos = agregarNodoPrincipio(listaDobleDos,crearNodoDoble(5));
    listaDobleDos = agregarNodoPrincipio(listaDobleDos,crearNodoDoble(3));
    listaDobleDos = agregarNodoPrincipio(listaDobleDos,crearNodoDoble(5));
    listaDobleDos = agregarNodoPrincipio(listaDobleDos,crearNodoDoble(1));


    mostrarListaDoble(listaDobleDos);

    nodoDoble* ultimo = devolverUltimoNodo(listaDobleDos);
    printf("\n EL ULTIMO NODO ES %i\n", ultimo->dato);

    if(esCapicua(listaDobleDos, devolverUltimoNodo(listaDobleDos))){
        printf("\n LA LISTA DOBLE ES CAPICUA\n");
    }else{
        printf("\n LA LISTA DOBLE NO ES CAPICUA\n");
    }
    printf("\n");

    /// EJERCICIO 3 ///
    printf("=============\n");
    printf(" EJERCICIO 3 \n");
    printf("=============\n");
    printf(" CANTIDAD DE NODOS: %i\n\n", cantidadNodos(listaDobleDos));
    eliminarNodoCentral(listaDobleDos,cantidadNodos(listaDobleDos));
    mostrarListaDoble(listaDobleDos);
    printf("\n");

    /// EJERCICIO 4 ///
    printf("=============\n");
    printf(" EJERCICIO 4 \n");
    printf("=============\n");
    printf(" LIBRERIAS LISTA DOBLE Y FILA\n\n");
    Fila* filaNueva = inicFila();
    printf("\n CONTADOR FILA CREADA EN FUNCION %i\n\n", filaNueva->contador);

    Fila* fila = inicFila();
    inicFilaParam(fila);
    printf("\n CONTADOR FILA PASADA POR PARAMETRO %i\n\n", fila->contador);

    agregar(fila,10);
    agregar(fila,11);
    mostrar(fila);
    printf("\n CANTIDAD DE ELEMENTOS: %i\n\n", fila->contador);

    return 0;
}

//nodoDoble* inicListaDoble(){
//    return NULL;
//}

//nodoDoble* crearNodoDoble(int dato){
//    nodoDoble* nuevoNodoDoble = (nodoDoble*)malloc(sizeof(nodoDoble));
//    nuevoNodoDoble->dato = dato;
//    nuevoNodoDoble->anterior = NULL;
//    nuevoNodoDoble->siguiente = NULL;
//    return nuevoNodoDoble;
//}

nodoDoble* agregarNodoPrincipio(nodoDoble* listaDoble, nodoDoble* nuevoNodo){
    nuevoNodo->siguiente = listaDoble;
    if(listaDoble!=NULL){
        listaDoble->anterior = nuevoNodo;
        return nuevoNodo;
    }
    if(listaDoble==NULL){
        listaDoble = nuevoNodo;
    }else{
        nuevoNodo->siguiente = listaDoble;
        listaDoble->anterior = nuevoNodo;
    }
    return nuevoNodo;
}

//nodoDoble* buscarUltimoNodo(nodoDoble* listaDoble){
//    nodoDoble* ultimoNodo = listaDoble;
//    while(listaDoble != NULL){
//        ultimoNodo = listaDoble;
//        listaDoble = listaDoble->siguiente;
//    }
//    return ultimoNodo;
//}

nodoDoble* buscarNodoDoble(nodoDoble* listaDoble, int dato){
    nodoDoble* nodoEncontrado = listaDoble;
    while(nodoEncontrado != NULL && nodoEncontrado->dato != dato){
        nodoEncontrado = nodoEncontrado->siguiente;
    }
    return nodoEncontrado;
}

nodoDoble* agregarNodoFinal(nodoDoble* listaDoble, nodoDoble* nuevoNodo){
    if(listaDoble == NULL){
        listaDoble = nuevoNodo;
    }else{
        nodoDoble* ultimoNodo = buscarUltimoNodo(listaDoble);
        ultimoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimoNodo;
    }
    return listaDoble;
}

nodoDoble* agregarNodoOrdenado(nodoDoble* listaDoble, nodoDoble* nuevoNodo){
    if(listaDoble == NULL){
        listaDoble = nuevoNodo;
    }else{
        if(nuevoNodo->dato < listaDoble->dato){
            listaDoble = agregarNodoPrincipio(listaDoble, nuevoNodo);
        }else{
            nodoDoble* anterior = listaDoble;
            nodoDoble* iterador = listaDoble;
            while(iterador != NULL && nuevoNodo->dato > iterador->dato){
                anterior = iterador;
                iterador = iterador->siguiente;
            }
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = iterador;
            nuevoNodo->anterior = anterior;
            if(iterador != NULL){
                iterador->anterior = nuevoNodo;
            }
        }
    }
    return listaDoble;
}

//nodoDoble* borrarPrimerNodo(nodoDoble* listaDoble){
//    nodoDoble* auxiliar = listaDoble;
//    listaDoble = listaDoble->siguiente;
//    listaDoble->anterior = NULL;
//    free(auxiliar);
//    return listaDoble;
//}

void mostrarListaDoble(nodoDoble* listaDoble){
    while(listaDoble != NULL){
        printf(" DATO: %i \n", listaDoble->dato);
        listaDoble = listaDoble->siguiente;
    }
}

void mostrarListaDobleHaciaAtras(nodoDoble* listaDoble){
    nodoDoble* nodoAnterior;
    while(listaDoble!=NULL){
        nodoAnterior = listaDoble;
        listaDoble = listaDoble->siguiente;
    }
    while(nodoAnterior!=NULL){
        printf(" DATO: %i \n", nodoAnterior->dato);
        nodoAnterior = nodoAnterior->anterior;
    }
}

nodoDoble* devolverUltimoNodo(nodoDoble* listaDoble){
    if(listaDoble->siguiente != NULL){
        listaDoble = devolverUltimoNodo(listaDoble->siguiente);
    }
    return listaDoble;
}

int esCapicua(nodoDoble* listaDoble, nodoDoble* ultimoNodo){
    int aux = 1;
    nodoDoble* iterador = listaDoble;
    if(iterador != NULL && ultimoNodo != NULL){
        if(iterador->dato == ultimoNodo->dato){
            aux = esCapicua(iterador->siguiente, ultimoNodo->anterior);
        }else{
            aux = 0;
        }
    }
    return aux;
}

int cantidadNodos(nodoDoble* listaDoble){
    int cantidad = 0;
    if(listaDoble != NULL){
        cantidad = cantidadNodos(listaDoble->siguiente);
        cantidad++;
    }
    return cantidad;
}

//nodoDoble* buscarNodo(nodoDoble* listaDoble, int cantidad){
//    nodoDoble* nodoBuscado = listaDoble;
//    if(listaDoble != NULL && cantidad > 1){
//        nodoBuscado = buscarNodo(listaDoble->siguiente,cantidad-1);
//    }
//    return nodoBuscado;
//}

//void eliminarNodo(nodoDoble* nodoBorrar){
//    if(nodoBorrar != NULL){
//        nodoDoble* nodoAnterior = nodoBorrar->anterior;
//        nodoDoble* nodoSiguiente = nodoBorrar->siguiente;
//        nodoAnterior->siguiente = nodoSiguiente;
//        nodoSiguiente->anterior=nodoAnterior;
//        free(nodoBorrar);
//    }
//}

void eliminarNodoCentral(nodoDoble* listaDoble, int cantidad){
    printf(" ELIMINAR CENTRO\n");
    int mitad = cantidad / 2 + 1;
    nodoDoble* nodoEliminar = buscarNodo(listaDoble, mitad);
    eliminarNodo(nodoEliminar);
}
