#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double hipotenuse;
    int cathetus_a;
    int cathetus_b;

    printf("enter the first cathetus: ");
    scanf("%d", &cathetus_a);

    printf("enter the second cathetus: ");
    scanf("%d", &cathetus_b);

    hipotenuse = sqrt((pow(cathetus_a, 2) + pow(cathetus_b, 2)));

    printf("the hipotenuse of your triangle is: %.2lf", hipotenuse);
    return 0;
}
