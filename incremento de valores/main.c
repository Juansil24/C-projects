#include <stdio.h>
#include <stdlib.h>

void incrementarTres(int *x, int *y, int *z){
   (*x)++;
   (*y)++;
   (*z)++;

}

int main()
{
    int x,y,z;
    printf("ingrese el valor de x: ");
    scanf("%d", &x);
    printf("ingrese el valor de y: ");
    scanf("%d", &y);
    printf("ingrese el valor de z: ");
    scanf("%d", &z);

    incrementarTres(&x, &y, &z);
    printf("x = %d, y = %d, z = %d", x, y, z);

    return 0;
}
