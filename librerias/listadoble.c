#include "listadoble.h"

nodoDoble* inicListaDoble(){
    return NULL;
}

nodoDoble* crearNodoDoble(int dato){
    nodoDoble* nuevoNodo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevoNodo->dato = dato;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoDoble* insertarNodoDoble(nodoDoble* listaDoble, nodoDoble* nuevoNodo){
    if(listaDoble == NULL){
        listaDoble = nuevoNodo;
    }else if(nuevoNodo->dato < listaDoble->dato){
        listaDoble = agregarAlPrincipio(listaDoble, nuevoNodo);
    }else{
        nodoDoble* nodoAnterior = listaDoble;
        nodoDoble* iterador = listaDoble->siguiente;

        while(iterador != NULL && iterador->dato < nuevoNodo->dato){
            nodoAnterior = iterador;
            iterador = iterador->siguiente;
        }
        nodoAnterior->siguiente = nuevoNodo;
        nuevoNodo->anterior = nodoAnterior;
        nuevoNodo->siguiente = iterador;

        if(iterador!=NULL){
            iterador->anterior = nuevoNodo;
        }
    }
    return listaDoble;
}

nodoDoble* cargarListaDoble(nodoDoble* listaDoble){
    char respuesta = 's';
    int dato;
    nodoDoble* aux;
    while(respuesta == 's'){
        printf("\nIngrese un valor entero: ");
        scanf("%d", &dato);
        aux = crearNodoDoble(dato);
        listaDoble = agregarAlFinal(listaDoble, aux);
        printf("\nDesea insertar otro valor (s/n)? ");
        fflush(stdin);
        scanf("%c", &respuesta);
    }
    return listaDoble;
}

nodoDoble* agregarAlPrincipio(nodoDoble* listaDoble, nodoDoble* nuevoNodo){
    nuevoNodo->siguiente = listaDoble;
    if(listaDoble != NULL){
        listaDoble->anterior = nuevoNodo;
    }
    return nuevoNodo;
}

nodoDoble* buscarUltimoNodo(nodoDoble* listaDoble){
    nodoDoble* ultimoNodo = NULL;
    if( listaDoble != NULL){
        if(listaDoble->siguiente == NULL){
            ultimoNodo = listaDoble;
        }else {
            ultimoNodo = buscarUltimoNodo(listaDoble->siguiente);
        }
    }
    return ultimoNodo;
}

nodoDoble* agregarAlFinal(nodoDoble* listaDoble, nodoDoble* nuevoNodo){
    if(listaDoble == NULL){
        listaDoble = nuevoNodo;
    }else {
        nodoDoble* ultimo = buscarUltimoNodo(listaDoble);
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }
    return listaDoble;
}

nodoDoble* buscarNodo(nodoDoble* listaDoble, int dato){
    nodoDoble* nodoBuscado = listaDoble;
    if (listaDoble != NULL && dato != listaDoble->dato){
        nodoBuscado = buscarNodo(listaDoble->siguiente, dato);
    }
    return nodoBuscado;
}

void eliminarNodo(nodoDoble* nodoBorrar){
    if (nodoBorrar != NULL){
        nodoDoble* nodoAnterior = nodoBorrar->anterior;
        nodoDoble* nodoSiguiente = nodoBorrar->siguiente;
        nodoAnterior->siguiente = nodoSiguiente;
        nodoSiguiente->anterior = nodoAnterior;
        free(nodoBorrar);
    }
}

nodoDoble* buscarYborrarNodo(nodoDoble* listaDoble, int dato){
    nodoDoble* nodoBuscado = buscarNodo(listaDoble, dato);
    if (nodoBuscado != NULL){
        eliminarNodo(nodoBuscado);
    }
    return listaDoble;
}

int verPrimerNodoDoble(nodoDoble* listaDoble){
    int dato = 0;
    if(listaDoble != NULL){
        dato = listaDoble->dato;
    }

    return dato;
}

nodoDoble* borrarPrimerNodo(nodoDoble* listaDoble){
    nodoDoble* aux = listaDoble;
    if (listaDoble != NULL){
        listaDoble = listaDoble->siguiente;
        if(listaDoble != NULL){
            listaDoble->anterior = NULL;
        }
        free(aux);
    }
    return listaDoble;
}


void mostrarNodoDoble(nodoDoble* nodo){
    printf("%d | ", nodo->dato);
}

void recorrerNodoDobleMostrar(nodoDoble* listaDoble){
    nodoDoble* iterador = listaDoble;
    while (iterador != NULL){
        mostrarNodoDoble(iterador);
        iterador = iterador->siguiente;
    }
}
