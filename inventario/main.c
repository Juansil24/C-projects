#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxproductos 100
#define maxstring 50


int main()
{
   float precio[maxproductos];
   char nombreProducto[maxproductos][maxstring];
   int cantidad, i, j;
   float tempPrecio;
   char tempNombre[maxstring];
   int c;
   int swapped;


   printf("ingrese la cantidad de productos: ");
   scanf("%d", &cantidad);
   while((c = getchar()) != '\n' && c !=  EOF);

  if(cantidad > maxproductos) {
    printf("Error: El maximo de poductos permitidos es: %d", maxproductos);
  return 1;
  }

   for(i = 0; i < cantidad; i++){

    printf("\nProducto %d:\n", i+1);
    printf("Nombre: ");
    fgets(nombreProducto[i], maxstring, stdin);

    nombreProducto[i][strcspn(nombreProducto[i], "\n")] = '\0';
    printf("Precio: ");
    scanf("%f", &precio[i]);
    while((c = getchar()) != '\n' && c != EOF);
    }

    for(i = 0; i < cantidad-1; i++){
        swapped = 0;
        for(j = 0; j < cantidad-i-1; j++){
            if(precio[j] > precio[j + 1]){
                tempPrecio = precio[j];
                precio[j] = precio[j + 1];
                precio[j + 1] = tempPrecio;

                strcpy(tempNombre, nombreProducto[j]);
                strcpy(nombreProducto[j], nombreProducto[j + 1]);
                strcpy(nombreProducto[j + 1], tempNombre);
                swapped = 1;
            }
        }
        if(swapped = 0){
            break;
        }
    }
     printf("\n%-30s | %-10s\n", "PRODUCTO", "PRECIO");
      printf("----------------------------------------------\n");
    for(i = 0; i < cantidad; i++){
        printf("%-30s | %.2f\n", nombreProducto[i], precio[i]);
    }

    return 0;
}
