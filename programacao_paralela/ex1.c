#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    double t1, t2;
    int i,j;
    int x;

    t1 = omp_get_wtime();
    for(i=0;i<100000;i++)
    {
        for(j=0;j<10000;j++)
        {
            x = 1;
        }
    }
    t2 = omp_get_wtime();

    printf("\n tempo levado = %lf",t2-t1);

    return 0;
}
