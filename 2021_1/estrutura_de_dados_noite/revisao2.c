#include <stdio.h>
#include <stdlib.h>


int main()
{
    int * x;

    x = malloc(4);

    *x = 2;

    *x = *x + 10;

    printf("\n Valor de X: %d",*x);

    printf("\n");

    return 0;
}