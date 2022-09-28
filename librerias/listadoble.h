#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dato;
    struct nodoDoble* siguiente;
    struct nodoDoble* anterior;
} nodoDoble;

nodoDoble* inicListaDoble();
nodoDoble* crearNodoDoble(int dato);
nodoDoble* insertarNodoDoble(nodoDoble* listaDoble, nodoDoble* nuevoNodo);
nodoDoble* cargarListaDoble(nodoDoble* listaDoble);
nodoDoble* agregarAlPrincipio(nodoDoble* listaDoble, nodoDoble* nuevoNodo);
nodoDoble* buscarUltimoNodo(nodoDoble* listaDoble);
nodoDoble* agregarAlFinal(nodoDoble* listaDoble, nodoDoble* nuevoNodo);
nodoDoble* buscarNodo(nodoDoble* listaDoble, int dato);
void eliminarNodo(nodoDoble* nodoBorrar);
nodoDoble* buscarYborrarNodo(nodoDoble* listaDoble, int dato);
int verPrimerNodoDoble(nodoDoble* listaDoble);
nodoDoble* borrarPrimerNodo(nodoDoble* listaDoble);
void mostrarNodoDoble(nodoDoble* nodo);
void recorrerNodoDobleMostrar(nodoDoble* listaDoble);


#endif // LISTADOBLE_H_INCLUDED
