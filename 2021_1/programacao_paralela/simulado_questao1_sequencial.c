#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
int primo(int x);

int main()
{

    int count = 0;
    int limite = 50;
    int i = 1;
    int som = 0;
    double t1, t2;

    t1 = omp_get_wtime();

    while (count < limite)
    {
        if (primo(i))
        {
            som = som + i;
            count++;
        }
        i++;
    }
    t2 = omp_get_wtime();

    printf("Somatorio: %d Tempo: %lf", som, t2 - t1);
}

int primo(int x)
{
    int i, j, z;

    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            z = 1;
        }
    }

    if ((x == 0) || (x == 1))
        return 0;
    int div;
    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
        {
            return 0;
        }
    }
    return 1;
}