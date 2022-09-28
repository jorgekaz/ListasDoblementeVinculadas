#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "listadoble.h"

typedef struct{
    nodoDoble* inicio;
    nodoDoble* fin;
    int contador;
}Fila;

Fila* inicFila();
void inicFilaParam(Fila* fila);
void mostrar(Fila* fila);
void agregar(Fila* fila, int dato);
int extraer(Fila* fila);
void leer(Fila* fila);
int primero(Fila* fila);
int filaVacia(Fila* fila);


#endif // LISTA_H_INCLUDED
