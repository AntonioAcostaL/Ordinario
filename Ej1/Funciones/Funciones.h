#include <stdio.h>
#include <stdlib.h>

//Haz una lista enlazada que pueda ingresar datos y haz una funcion que diga si la lista enlazada contiene un ciclo
//(donde el nodo regresa a otro nodo)

typedef struct _Nodo
{
    char dato;
    struct _Nodo *siguiente;
}Nodo;

typedef struct _ListaEnlazada
{
    Nodo* head;
    Nodo* tail;
    Nodo* curr;
    int size;
}ListaEnlazada;

void InicializarLista(ListaEnlazada* lista);
void PushBack(ListaEnlazada* lista, char valor);

int HayCiclo(ListaEnlazada* lista);

void ImprimirLista(ListaEnlazada* lista);
void LiberarLista(ListaEnlazada* lista);
