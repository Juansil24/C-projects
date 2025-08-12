#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int i = 0;
    int j = 0;
    int swapped;
    int aux = 0;
    int sumaPrincipal = 0;
    int sumaSecundaria = 0;
    int matriz[4][4];
    int traspuesta[4][4];
    int temp[16];
    int fila, col;
    int total = 16;
    int paresRepetidos = 0;
    int imparesRepetidos = 0;
    int comprobacion;

    for(i = 0; i <= 3; i++){
        for(j = 0; j <= 3; j++){
           matriz[i][j] = (rand() % 11) + 20;
          comprobacion = matriz[i][j] % 2;
          if(comprobacion == 0){
            paresRepetidos++;
          }else{
            imparesRepetidos++;
            }
        }
    }

    printf("\n-----------Matriz original-------------\n");

    for(i = 0; i <= 3; i++){
        for(j = 0; j <= 3; j++){
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }


  for(i = 0; i < total; i++){
    fila = i/4; //para las filas
    col = i % 4; //para las columnas
    temp[i]= matriz[fila][col];
  }

  printf("\n--------------Matriz en 1D--------------\n");

  for(i = 0; i < total; i++){
    printf(" %d", temp[i]);
  } printf("\n");

    // ordenar los varoles

    for(i = 0; i < total - 1; i++){
            swapped = 0;
        for(j = 0; j< total - i - 1; j++){
            if(temp[j] < temp[j + 1]){
                aux = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = aux;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }

    //copiar el array ordenao

     for(i = 0; i < total; i++){
    fila = i/4;
    col = i % 4;
    matriz[fila][col] = temp[i];
     }

    //escribiendo el ordenado

    printf("\n--------------Matriz Ordenada-------------\n");

    for(i = 0; i <=3; i++){
        for(j = 0; j<=3; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    //haciendo la traspuesta

    printf("\n--------------Matriz traspuesta-------------\n");
    for(i = 0; i <=3; i++){
        for(j = 0; j <= 3; j++){
            traspuesta[i][j] = matriz[j][i];
        }
    }

    for(i = 0; i <= 3; i++){
        for(j = 0; j <= 3; j++){
            printf(" %d ", traspuesta[i][j]);
        }
        printf("\n");
    }


    //haciendo las sumas

for(i = 0; i <= 3; i++){
    for(j = 0; j <= 3; j++){
        if(i == j){
            sumaPrincipal += matriz[i][j];
        }
        if(i + j == 3){
            sumaSecundaria += matriz[i][j];
        }
    }
}
    printf("\n----------Sumas de las columnas-------------\n");

    printf("la suma de la diagonal principal de la matriz es igual a %d\n", sumaPrincipal);
    printf("la suma de la diagonal secundaria de la matriz es igual a %d\n", sumaSecundaria);

    printf("\n----------Conteo Pares e Impares-------------\n");

    printf("la cantidad total de numeros Pares fue de: %d\n", paresRepetidos);
    printf("la cantidad total de numeros Impares fue de: %d\n", imparesRepetidos);

    return 0;
}
