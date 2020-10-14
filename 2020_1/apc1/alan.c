#include <stdio.h>
#include <stdlib.h>


int main()
{
    float x=2.1234;
    float decimal;
    int y;

    y = (int)x;

    printf("\n X = %f",x);
    printf("\n Y = %d",y);

    decimal = x - (float)y;
    printf("\nDecimal : %f",decimal);
    return 0;

}