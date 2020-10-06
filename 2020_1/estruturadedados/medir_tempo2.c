/*

medir tempo de um programa utilizando a biblioteca omp.h

*/

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{
    double t1,t2;

    int i,j;
    int x;

    t1 = omp_get_wtime();

    for(i=0;i<10000;i++)
    {
        for(j=0;j<10000;j++)
        {
            x = x;
        }
    }

    t2 = omp_get_wtime();

    printf("\n Tempo gasto: %lf",t2-t1);

}

