#include <stdio.h>
#include <stdlib.h>

int main()
{
    include <stdio.h>

include <string.h>

int main() {
    char A[][10] = {"Luis", "Juan", "Ana", "Pedro"};
    char B[][10] = {"Maria", "Ana", "Carlos", "Juan"};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    int contador = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (strcmp(A[i], B[j]) == 0) {
                printf("Cadena repetida encontrada: %s\n", A[i]);
                contador++;
                break;
            }
        }
    }

    if (contador == 0) {
        printf("No hay cadenas repetidas entre las matrices.\n");
    } else {
        printf("Cantidad de cadenas repetidas: %d\n", contador);
    }

    return 0;
}

    return 0;
}
