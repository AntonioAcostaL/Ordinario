#include <stdio.h>
#include <stdlib.h>

typedef struct _NodoArbol
{
    int dato;
    struct _NodoArbol* izquierdo;
    struct _NodoArbol* derecho;
}NodoArbol;


typedef struct _NodoLista 
{
    int valor;
    struct _NodoLista* siguiente;
} NodoLista;

NodoArbol* CrearNodoArbol(int valor);
NodoLista* CrearNodoLista(int valor);
void EncontrarCaminos(NodoArbol* raiz, int k, int sumaActual, NodoLista* caminoActual, NodoLista** caminosValidos);
void ImprimirCamino(NodoLista* camino);
void LiberarLista(NodoLista* lista);
void LiberarArbol(NodoArbol* raiz);