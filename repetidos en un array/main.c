#include <stdio.h>

#include <stdlib.h>

#include <time.h>

define TAM 10
int main() {
    int A[TAM], B[TAM];
    int contador = 0;


    srand(time(NULL));


    for (int i = 0; i < TAM; i++) {
        A[i] = rand() % 20 + 1;
        B[i] = rand() % 20 + 1;
    }


    printf("Matriz A: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", A[i]);
    }

    printf("\nMatriz B: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", B[i]);
    }

    printf("\n");


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (A[i] == B[j]) {
                int yaContado = 0;

                for (int k = 0; k < i; k++) {
                    if (A[k] == A[i]) {
                        yaContado = 1;
                        break;
                    }
                }
                if (!yaContado) {
                    printf("Número repetido encontrado: %d\n", A[i]);
                    contador++;
                }
                break;
            }
        }
    }

    if (contador == 0) {
        printf("No hay números repetidos entre las matrices.\n");
    } else {
        printf("Cantidad de números repetidos únicos: %d\n", contador);
    }

    return 0;
}
