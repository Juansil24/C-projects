#include <stdio.h>
#include <stdlib.h>
#define MAX 100

    void agregarProducto() {
        if(contador >= MAX) {
            printf("Inventario lleno.\n");
            return;
        }
    printf("ID: ");
    scanf("%d", &ids[contador]);
    getchar();

    printf("Nombre: ");
    fgets(nombres[contador], sizeof(nombres[contador]), stdin);
    nombres[contador][strcspn(nombres[cnotador], "\n"] = '\0';

    printf("Precio: ");
    scanf("%f", &precios[contador]);

    pritf("stock: ");
    scanf("%d", &stocks[contador]);
    getchar();

    printf("categoria (telefonia/electrodomesticos/otros): ");
    fgets(categorias[contador], sizeof(categorias[contador]), stdin);
    categorias[contador][strcspn(categorias[contador]

    }

    void mostrarMenu() {
        printf("\n--- Sistema de Gestion de Inventario --\n");
        printf("1. Agregar producto\n");
        printf("2. Listar productos\n");
        printf("3. Buscar producto por ID\n");
        printf("4. Calcular total del inventario\n");
        printf("5. Aplicar descuentos\n ");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
    }

    void buscarProducto() {


    }


int main()
{
        int ids[MAX];
        char nombres[MAX[50];
        float precios[MAX];
        int stocks[MAX];
        char categorias[MAX][30];
        int num_productos = 0;


    return 0;
}

