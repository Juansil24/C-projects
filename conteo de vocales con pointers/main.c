#include <stdio.h>
#include <stdlib.h>

void duplicar(int *n){
    *n = *n * 2;
}

int main()
{
    int n;
    printf("ingrese el numero que quiere duplicar:");
    scanf("%d", &n);
    duplicar(&n);
    printf("el resultado es %d", n);

    return 0;
}
