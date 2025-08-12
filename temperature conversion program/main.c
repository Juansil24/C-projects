#include <stdio.h>
#include <stdlib.h>

int main()
{
    char unit;
    double convertion;
    int temperature;

    printf("is the temperature in (F) or (C)?\n");
    scanf(" %c", &unit);

    if(unit >= 'a' && unit <= 'z'){
        unit -= 32;
    }

    if(unit != 'F' && unit != 'C'){
     printf("Please enter a valid unit\n");
    }

    while(unit != 'F' && unit != 'C'){

        printf("is the temperature in (F) or (C)?\n");
        scanf(" %c", &unit);
    }

    printf("please enter the temperature in %c\n", unit);
    scanf(" %d", &temperature);


    switch(unit){
     case 'F':
        convertion = (temperature - 32) * 0.5555555555555556;
        printf("the temperature in C is %.2lf\n", convertion);
        break;
     case 'C':
        convertion = (temperature * 1.8) + 32;
        printf("the temperature in F is %.2lf\n", convertion);
        break;
    default:
            printf("An unexpected error occurred with the unit.\n");
            break;
    }
    return 0;
}
