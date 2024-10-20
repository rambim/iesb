#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 1000000000;
double step;
int main()
{
    double inicio, fim;

    inicio = omp_get_wtime();
    int i;
    double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = step * sum;

    fim = omp_get_wtime();

    printf("\nTempo gasto: %lf",fim-inicio);
    printf("\n%f",pi);
    return 0;
}