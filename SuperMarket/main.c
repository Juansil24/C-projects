#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CANTIDAD 5
#define MAXSTRING 50

int main()
{
    float precio[CANTIDAD];
    char NombreProducto[CANTIDAD][MAXSTRING];
    int i, j;
    float suma = 0;
    float promedio;
    int c;


    printf("\n\n---------------INGRESO DE DATOS------------------\n\n");

    for(i = 0; i < CANTIDAD ; i++){

        printf("ingrese el nombre del producto numero %d: ", i + 1);
        fgets(NombreProducto[i], MAXSTRING, stdin);
        NombreProducto[i][strcspn(NombreProducto[i], "\n")] = 0;


    do{
        printf("ingrese el precio de %s: ", NombreProducto[i]);
        scanf("%f", &precio[i]);
        if(precio[i] < 0) {
            printf("PRECIO INVALIDO\n");
        }
        while ((c = getchar()) != '\n' && c != EOF);
    } while(precio[i] < 0);

}printf("\n");

    printf("\n%-30s | %-10s\n", "PRODUCTO", "PRECIO");
    printf("----------------------------------------------\n");

    for(i = 0; i < CANTIDAD; i++) {
        for(j = 0; NombreProducto[i][j] != '\0'; j++) {
            putchar(toupper(NombreProducto[i][j]));
        }
        printf(" | %.2f\n", precio[i]);
        suma += precio[i];
    }

    promedio = suma / CANTIDAD;
    printf("\nEL PRECIO PROMEDIO ES: %.2f\n", promedio);

    return 0;
}
