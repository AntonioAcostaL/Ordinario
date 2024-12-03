#include "Funciones.h"

void InicializarLista(ListaEnlazada* lista)
{
    lista->head=NULL;
    lista->tail=NULL;
    lista->curr=NULL;
    lista->size = 0;
}

void PushBack(ListaEnlazada* lista, char valor) 
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    
    if (lista->tail == NULL){  
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } 
    else
    { 
        lista->tail->siguiente = nuevoNodo;
        lista->tail = nuevoNodo;
    }
    lista->size++;
}
void ImprimirLista(ListaEnlazada* lista)
{
    Nodo* actual= lista->head;

    while (actual!=NULL)
    {
        printf("%c ->",actual->dato);
        actual=actual->siguiente;
    }
    printf("NULL\n");
}
int HayCiclo(ListaEnlazada* lista)
{
    if (lista->head ==NULL){ 
    return 0;
    }
    Nodo* tortuga = lista->head;  
    Nodo* liebre = lista->head;   

    while (liebre != NULL && liebre->siguiente != NULL) {
        tortuga = tortuga->siguiente;            
        liebre = liebre->siguiente->siguiente;    

        if (tortuga == liebre) {  //si se encuentran hay ciclo
            return 1;
        }
    }

    return 0;
}

void LiberarLista(ListaEnlazada* lista) {
    Nodo* actual = lista->head;
    Nodo* siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    lista->head = lista->tail = lista->curr = NULL;
    lista->size = 0;
}