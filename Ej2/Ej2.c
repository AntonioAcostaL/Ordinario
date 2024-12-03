/*Dado que una raiz de un arbol y un entero (k),(primero genera el arbol) haz una funcion que regrese el camino de la raiz
a la hoja donde la suma de todos los nodos sean el numero entero (k), la funcion debera regresar un lista enlazada
de nodos donde la suma sea igual a k.*/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones/Funciones.h"




int main() {

    NodoArbol* raiz = CrearNodoArbol(5);
    raiz->izquierdo = CrearNodoArbol(4);
    raiz->derecho = CrearNodoArbol(8);
    raiz->izquierdo->izquierdo = CrearNodoArbol(11);
    raiz->izquierdo->izquierdo->izquierdo = CrearNodoArbol(7);
    raiz->izquierdo->izquierdo->derecho = CrearNodoArbol(2);
    raiz->derecho->izquierdo = CrearNodoArbol(13);
    raiz->derecho->derecho = CrearNodoArbol(4);
    raiz->derecho->derecho->izquierdo = CrearNodoArbol(5);
    raiz->derecho->derecho->derecho = CrearNodoArbol(1);
    
 
    int k = 18;
    
 
    NodoLista* caminosValidos = NULL;
    
   
    EncontrarCaminos(raiz, k, 0, NULL, &caminosValidos);
    
  
    printf("Caminos cuya suma es igual a %d:\n", k);
    NodoLista* temp = caminosValidos;
    while (temp != NULL) {
        ImprimirCamino(temp);
        temp = temp->siguiente;
    }


    LiberarLista(caminosValidos);
    LiberarArbol(raiz);
    
    return 0;
}

