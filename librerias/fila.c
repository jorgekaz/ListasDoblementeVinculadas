#include "Fila.h"

Fila* inicFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
    fila->contador = NULL;
    return fila;
}

void inicFilaParam(Fila* fila){
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
    int contador = NULL;
}

void mostrar(Fila* fila){
    printf("\n INICIO | ");
    recorrerNodoDobleMostrar(fila->inicio);
    printf(" FIN\n");
}

void agregar(Fila* fila, int dato){
    nodoDoble* nuevo = crearNodoDoble(dato);

    fila->fin = agregarAlFinal(fila->fin, nuevo);

    if(fila->inicio == NULL){
        fila->inicio = fila->fin;
    }
    fila->fin=nuevo;
    fila->contador++;
}

int extraer(Fila* fila){
    int dato;
    if(fila->inicio != NULL){
        dato = verPrimerNodoDoble(fila->inicio);
        fila->inicio = borrarPrimerNodo(fila->inicio);
        if(fila->inicio == NULL){
            fila->fin = NULL;
        }
    }
    return dato;
}

void leer(Fila* fila){
    int dato;
    printf(" INGRESE UN VALOR: ");
    fflush(stdin);
    scanf("&d", &dato);
    agregar(fila,dato);
}

int primero(Fila* fila){
    int dato;
    if(fila->inicio != NULL){
        dato = verPrimerNodoDoble(fila->inicio);
    }
    return dato;
}

int filaVacia(Fila* fila){
    int respuesta = 0;
    if(fila->inicio == NULL){
        respuesta = 1;
    }
    return respuesta;
}
