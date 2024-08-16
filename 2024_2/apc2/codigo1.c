#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x = 2, y = 3,i;
    int som = 0;

    for(i=0;i<x+y;i++)
    {
        x = x -1;
        som = som + 1;
    }

    printf("\n Resultado = %d",som);
}