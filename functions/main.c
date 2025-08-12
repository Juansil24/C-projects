#include <stdio.h>

int mostrarMenu();
int sumar();
int restar();
int multiplicar();

int main() {
    int opcion;
    do {
        opcion = mostrarMenu();

        switch(opcion) {
            case 1:
                printf("\n-------SUMA-------\n");
                sumar();
                break;
            case 2:
                printf("\n------RESTA------\n");
                restar();
                break;
            case 3:
                printf("\n------MULTIPLICACION-----\n");
                multiplicar();
                break;
            case 4:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nPor favor ingrese una opción válida\n");
        }
    } while(opcion != 4);

    return 0;
}

int mostrarMenu() {
    int opcion;
    printf("\n-------MENU------\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Salir\n");
    printf("\nElige una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

int sumar() {
    int a, b;
    printf("\nIngrese el primer número: ");
    scanf("%d", &a);
    printf("Ingrese el segundo número: ");
    scanf("%d", &b);
    int resultado = a + b;
    printf("El resultado de la suma es: %d\n", resultado);
    return resultado;
}

int restar() {
    int a, b;
    printf("\nIngrese el primer número: ");
    scanf("%d", &a);
    printf("Ingrese el segundo número: ");
    scanf("%d", &b);
    int resultado = a - b;
    printf("El resultado de la resta es: %d\n", resultado);
    return resultado;
}

int multiplicar() {
    int a, b;
    printf("\nIngrese el primer número: ");
    scanf("%d", &a);
    printf("Ingrese el segundo número: ");
    scanf("%d", &b);
    int resultado = a * b;
    printf("El resultado de la multiplicación es: %d\n", resultado);
    return resultado;
}
