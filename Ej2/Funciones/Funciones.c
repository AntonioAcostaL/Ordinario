#include "Funciones.h"


NodoArbol* CrearNodoArbol(int valor) {
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->dato = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}


NodoLista* CrearNodoLista(int valor) {
    NodoLista* nuevoNodo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void EncontrarCaminos(NodoArbol* raiz, int k, int sumaActual, NodoLista* caminoActual, NodoLista** caminosValidos) {
    if (raiz == NULL) {
        return;
    }
    
    NodoLista* nuevoNodo = CrearNodoLista(raiz->dato);
    nuevoNodo->siguiente = caminoActual;
    caminoActual = nuevoNodo;
        
    sumaActual += raiz->dato;
    
    // Si llegamos a una hoja y la suma es igual a k, guardamos el camino
    if (raiz->izquierdo == NULL && raiz->derecho == NULL && sumaActual == k) {
        NodoLista* caminoValido = caminoActual;
       
        NodoLista* caminoInvertido = NULL;
        while (caminoValido != NULL) {
            NodoLista* nuevoNodo = CrearNodoLista(caminoValido->valor);
            nuevoNodo->siguiente = caminoInvertido;
            caminoInvertido = nuevoNodo;
            caminoValido = caminoValido->siguiente;
        }
       
        NodoLista* temp = caminoInvertido;
        while (temp != NULL) {
            NodoLista* nuevoNodo = CrearNodoLista(temp->valor);
            nuevoNodo->siguiente = *caminosValidos;
            *caminosValidos = nuevoNodo;
            temp = temp->siguiente;
        }
    }
    
    
    EncontrarCaminos(raiz->izquierdo, k, sumaActual, caminoActual, caminosValidos);
    EncontrarCaminos(raiz->derecho, k, sumaActual, caminoActual, caminosValidos);
    

    NodoLista* temp = caminoActual;
    caminoActual = caminoActual->siguiente;
    free(temp);
}


void ImprimirCamino(NodoLista* camino) {
    NodoLista* temp = camino;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->siguiente;
    }
    printf("\n");
}


void LiberarLista(NodoLista* lista) {
    NodoLista* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}


void LiberarArbol(NodoArbol* raiz) {
    if (raiz != NULL) {
        LiberarArbol(raiz->izquierdo);
        LiberarArbol(raiz->derecho);
        free(raiz);
    }
}


