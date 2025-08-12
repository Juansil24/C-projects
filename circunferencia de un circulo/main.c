#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const float PI = 3.1416;
    float radius;
    float circunference;
    float diameter;
    float area;

    printf("\nwhat is the radius of the circle?: \n");
    scanf("%f", &radius);

        printf("\nthe RADIUS of the circle is: %.2f, now i'll proceed to calculate the diameter.\n", radius);

        diameter = radius * 2;
        printf("\nthe DIAMETER of the circle is: %.2f\n", diameter);

        area = PI * pow(radius, 2);
        printf("\nthe AREA of the circle is: %.2f\n", area);

        circunference = PI * diameter;
        printf("\nthe CIRCUNFERENCE of the circle is: %.2f\n", circunference);


    return 0;
}
