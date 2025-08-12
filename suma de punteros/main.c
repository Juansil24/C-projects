#include <stdio.h>
#include <stdlib.h>

void sumar(int a, int b, int *resultado){
    *resultado = a + b;
}

int main(){
    int a;
    int b;
    int resultado;

    printf("ingrese el primer numero: ");
    scanf("%d", &a);
    printf("ingrese el segundo numero: ");
    scanf("%d", &b);
    sumar(a, b, &resultado);
    printf("el resultado de la suma es: %d", resultado);

    return 0;
}
