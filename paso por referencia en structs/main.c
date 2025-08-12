#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Punto;

void mover(Punto *p, int dx, int dy ){

    p->x += dx;
    p->y += dy;

}

void imprimirPunto(const Punto *p){
    printf("punto: (%d,%d)\n", p->x, p->y);

}

int main(){
    Punto a = {2, 3};
    imprimirPunto(&a);
    mover(&a, 5, -1);
    imprimirPunto(&a);
    return 0;
}




