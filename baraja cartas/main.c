#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *x, int *y){
    int temp = *x;
     *x = *y;
     *y = temp;
}

int main(){
  int x = 5;
  int y = 10;
  intercambiar(&x, &y);
  printf("x=%d, y=%d", x, y);

    return 0;
}
