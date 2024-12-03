#include "Funciones.h"

// Funcion cumple con la propiedad del BST
bool esValido(int arr[], int n, int i, char min, char max) {

    if (i >= n || arr[i] == -1) //-1 como un valor nulo
        return true;

    char valorNodo = arr[i];

    //dentro del rango
    if (valorNodo < min || valorNodo > max)
        return false;


    return esValido(arr, n, 2 * i + 1, min, valorNodo) && esValido(arr, n, 2 * i + 2, valorNodo, max);
}


bool verificarArbolValido(int arr[], int n) {
    return esValido(arr, n, 0, '\0', 'Z'); 
}


void imprimirResultado(bool valido) {
    if (valido)
        printf("El arboo es valido.\n");
    else
        printf("El arbol no es valido.\n");
}
