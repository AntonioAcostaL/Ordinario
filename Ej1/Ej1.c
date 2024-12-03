#include <stdio.h>
#include <stdlib.h>
#include "Funciones/Funciones.h"

int main() {
    ListaEnlazada lista;
    InicializarLista(&lista);
    
    PushBack(&lista, 'A');
    PushBack(&lista, '2');
    PushBack(&lista, 'B');
    PushBack(&lista, 'z');
    PushBack(&lista, '5');
    PushBack(&lista, '1');
    PushBack(&lista, '2');
    
    
    printf("Lista: ");
    ImprimirLista(&lista);
    
    // Verifica si la lista tiene ciclo
    printf("Hay ciclo? %s\n", HayCiclo(&lista) ? "Si" : "No");
    

    LiberarLista(&lista);
    
    return 0;
}
