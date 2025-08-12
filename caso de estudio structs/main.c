#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "poker.h"

#define TOTAL_CARTAS 52

typedef struct{
  char palo[10];
  char valor[5];
} Carta;

const char *obtenerColor(const char* palo){
    if(strcmp(palo, "HEART") == 0) return RED;
    if(strcmp(palo, "DIAMOND") == 0) return YELLOW;
    if(strcmp(palo, "CLUBS") == 0) return BLUE;
    if(strcmp(palo, "SPADES") == 0) return GREEN;
    return WHITE;

}

void crearMazo(Carta mazo[], const char palos[][10], const char valores[][3]){
    int index = 0;
        for(int p = 0; p < 4; p++) {
            for(int v = 0; v < 13; v++){
                strcpy(mazo[index].palo, palos[p]);
                strcpy(mazo[index].valor, valores[v]);
                index++;
            }
        }
}

void mostrarMazo(Carta mazo[]) {
    for(int i = 0; i < TOTAL_CARTAS; i++) {
        const char *color = obtenerColor(mazo[i].palo);
        printCard(mazo[i].palo, mazo[i].valor, color);
    }
}

void barajar(Carta mazo[]){
    for(int i = 0; i < TOTAL_CARTAS; i++) {
        int r = rand() % TOTAL_CARTAS;
        Carta temp = mazo[i];
        mazo[i] = mazo[r];
        mazo[r] = temp;
    }
}

void repartir(Carta mazo[], int numJugadores){
    int CartasPorMano = TOTAL_CARTAS / numJugadores;

    for(int i = 0; i < numJugadores; i++){
        printf("\n--- MANO %d ---\n", i + 1);
        for(int j = 0; j < CartasPorMano; j++){
            int index = i * CartasPorMano + j;
            const char* color = obtenerColor(mazo[index].palo);
            printCard(mazo[index].palo, mazo[index].valor, color);
        }
    }
}

int main() {
    Carta mazo[TOTAL_CARTAS];

    system("");

    const char palos[4][10] = {"SPADES", "HEARTS", "DIAMONDS", "CLUBS"};
    const char valores[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "K", "Q"};

    srand(time(NULL));

    crearMazo(mazo, palos, valores);

    printf("-------MAZO SIN BARAJAR-------");
    mostrarMazo(mazo);

    barajar(mazo);

    printf("\n-----MAZO BARAJADO-----\n");
    mostrarMazo(mazo);

    int n;
    printf("\n en cuantas manos desea repartir? ");
    scanf("%d", &n);

    if(n > 0 && TOTAL_CARTAS % n == 0) {
        repartir(mazo, n);
    } else{
        printf("numero invalido, debe ser divisor de %d\n", TOTAL_CARTAS);
    }

    return 0;
}
