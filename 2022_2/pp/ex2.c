#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 1000000000;
double step;

int main()
{
    int i;
    double t1,t2;
    double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    t1 = omp_get_wtime();
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    t2 = omp_get_wtime();

    printf("pi = %lf",pi);
    printf("\n Tempo gasto: %lf",t2-t1);
    return 0;
}