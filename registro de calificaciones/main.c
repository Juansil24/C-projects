#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROJO "\x1b[31m"
#define RESET "\033[0m"
#define VERDE "\x1b[32m"

#define ESTUDIANTES 4
#define MATERIAS 3

int main()
{
system("");

    char nombre[ESTUDIANTES][50];
    float nota[ESTUDIANTES][MATERIAS];
    float acumNotas;
    float promedio;
    float arraypromedios[ESTUDIANTES];
    int i,j,c;

    for(i = 0; i < ESTUDIANTES; i++){
        printf("ingrese el nombre del estudiante numero %d: ", i + 1);
        fgets(nombre[i], 50, stdin);
        nombre[i][strcspn(nombre[i], "\n")] = '\0';
    }
    for(i = 0; i < ESTUDIANTES; i++){
        for(j = 0; j < MATERIAS; j++){
    do{
        printf("ingrese la clasificacion numero %d: ", i + 1);
            scanf("%f", &nota[i][j]);
        if(nota[i][j] < 0 || nota[i][j] >20){
            printf("error, ingrese una nota valida");
        }
            }while(nota[i][j] < 0 || nota[i][j] > 20);
        while((c = getchar()) != '\n' && c != EOF);
        }
    }

    for (i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        for (j = 0; j < MATERIAS; j++) {
            suma += nota[i][j];
        }
        promedio = suma / MATERIAS;
        arraypromedios[i] = promedio;

        printf("\n Promedio de %s: %.2f\n", nombre[i], promedio);
    }

printf("\n%-20s | %-10s\n", "ESTUDIANTE", "PUNTAJE");
printf("----------------------+------------\n");

for (i = 0; i < ESTUDIANTES; i++) {
    float puntaje = arraypromedios[i] > 10 ? 10 : arraypromedios[i];
    printf("%-20s | ", nombre[i]);
    if (puntaje < 6) {
        printf(ROJO "%-10.2f" RESET "\n", puntaje);
    } else {
        printf(VERDE "%-10.2f" RESET "\n", puntaje);
    }
}

    return 0;
}
