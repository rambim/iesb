#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100000;

double step;

int main(int argc, char *argv[])
{
    double t1,t2;
    int i; double x, pi , sum =0.0;

    t1 = omp_get_wtime();

    step = 1.0/(double)num_steps;

    for(i=0;i<num_steps;i++)
    {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }

    pi = step * sum;
    t2 = omp_get_wtime();
   
    printf("\n Pi = %lf", pi);

    printf("\n Tempo gasto: %lf", t2 - t1);

    return 0;
}