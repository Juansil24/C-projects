#include <stdio.h>
#include <stdlib.h>

int main()
{
    int desorden[] = {7,9,2,3,5,6,1,4,8,0};
    int longitud = 10;
    int swapped;
    int i,j;

    for(i = 0; i < longitud - 1; i++) {  //> por <
        swapped = 0;
        for(j = 0; j < longitud - i - 1; j++) {  // > por <
            if(desorden[j] > desorden[j+1]) {
                int temp = desorden[j];
                desorden[j] = desorden[j+1];
                desorden[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0) {
            break;
        }
    }

    for(i = 0; i < longitud; i++) {
        printf("%d\t", desorden[i]);
    }
    return 0;
}
