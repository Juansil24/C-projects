#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESTACIONES 4
#define MESES 3

int main()
{
    char *Trimestre[] = {"Empresa", "Octubre", "Noviembre", "Diciembre"};
    char nombreEstaciones[ESTACIONES][50];
    float datosTrimestre[ESTACIONES][MESES];
    float promedioEstacion[ESTACIONES];
    float promedioMes[MESES];
    float estacionMax = 0.0;
    float estacionMin = 99999.0;
    char nombreMax[50];
    char nombreMin[50];
    int i,j;

    printf("\n--- Ingresado de Valores ---\n");

    for(i = 0; i <= ESTACIONES-1; i++){
        printf("ingrese el nombre de la estacion %d: ", i+1);
        scanf("%s", &nombreEstaciones[i]);
    }

    for(i = 0; i <= ESTACIONES-1; i++){
        for(int j = 0; j <= MESES-1; j++){
            printf("ingrese el valor %d de %s: ", j+1, nombreEstaciones[i]);
            scanf("%f", &datosTrimestre[i][j]);
    }
}

    printf("\n");

    printf("\n--- Impresion de Tabla ---\n");

    for(i = 0; i <= 3; i++){
        printf("%-15s ", Trimestre[i]);
    }
        printf("\n");


      for(i = 0; i <= ESTACIONES-1; i++){
        printf("%-15s", nombreEstaciones[i]);
        for(j = 0; j <= MESES-1; j++){
            printf("%-15f ", datosTrimestre[i][j]);
        }
        printf("\n");
    }

        //PROMEDIOS

    printf("\n--- Promedio de Contaminacion por Estacion ---\n");
    for (int i = 0; i < ESTACIONES; i++) {
        float sumaFila = 0.0;
        for (int j = 0; j < MESES; j++) {
            sumaFila += datosTrimestre[i][j];
        }
        promedioEstacion[i] = sumaFila / MESES;
        printf("Promedio de %-15s: %.2f\n", nombreEstaciones[i], promedioEstacion[i]);

         if (promedioEstacion[i] > estacionMax) {
        estacionMax = promedioEstacion[i];
        strcpy(nombreMax, nombreEstaciones[i]);
    }

    if (promedioEstacion[i] < estacionMin) {
        estacionMin = promedioEstacion[i];
        strcpy(nombreMin, nombreEstaciones[i]);
    }
}
    printf("\n--- Promedio de Contaminacion por Mes ---\n");
    for (j = 0; j < MESES; j++) {
            float sumaColumna = 0.0;
        for (i = 0; i < ESTACIONES; i++) {
            sumaColumna += datosTrimestre[i][j];
        }

        promedioMes[j] = sumaColumna / ESTACIONES;
        printf("Promedio de %-10s: %.2f\n", Trimestre[j+1], promedioMes[j]);
    }
        printf("\n--- Estaciones con Niveles Maximos y Minimos ---\n");
        printf("la estacion con mayor nivel de contaminacion fue %s con un valor de %.2f\n", nombreMax, estacionMax);
        printf("la estacion con menor nivel de contaminacion fue %s con un valor de %.2f\n", nombreMin, estacionMin);

        return 0;

}




