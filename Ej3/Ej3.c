/*dado un arbol binario represetnado como un arreglo. haz una funcion 
que determine si es un arbol binario valido (que cumpla con su propiedad) Ejemplo:
[5,2,7,1,3,null,null,null,null,4] es valido
[5,4,8,11,null,13,4] no es valido
[C,B,G,A,null,D,H] es valido
*/

#include "Funciones/Funciones.h"

int main() {
    // valido
    int arbol1[] = {5, 2, 7, 1, 3, 4};
    int n1 = sizeof(arbol1) / sizeof(arbol1[0]);
    imprimirResultado(verificarArbolValido(arbol1, n1));

    // no valido
    int arbol2[] = {5, 4, 8, 11, -1, 13, 4};
    int n2 = sizeof(arbol2) / sizeof(arbol2[0]);
    imprimirResultado(verificarArbolValido(arbol2, n2));

    // rbol valido 
    int arbol3[] = {'C', 'B', 'G', 'A', -1, 'D', 'H'};
    int n3 = sizeof(arbol3) / sizeof(arbol3[0]);
    imprimirResultado(verificarArbolValido(arbol3, n3));

    return 0;
}