//OpenMP

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    double t1, t2;

    int i, j, x;

    t1 = omp_get_wtime();

    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 100000; j++)
        { 
            x = 1;
        }
    }
    t2 = omp_get_wtime();

    printf("\n Tempo de execução : %lf", t2 - t1);

    printf("\n");
    return 0;
}
