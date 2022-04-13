#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 1000;

double step;

int main(int argc, char *argv[])
{
    int i, qtd_threads;
    qtd_threads = atoi(argv[1]);
    double x, pi, sum = 0.0, t1, t2;

    omp_set_num_threads(qtd_threads);

    t1 = omp_get_wtime();

    step = 1.0 / (double)num_steps;

    printf("\n Quantidade de threads: %d", qtd_threads);

        for (i = 0; i < num_steps; i++)
        {
            printf("\nI = %d",i);
            x = (i + 0.5) * step;

            sum = sum + 4.0 / (1.0 + x * x);
            printf("\n Sum: %lf",sum);
        }
        printf("\n Step: %lf Sum: %lf",step,sum);
    pi = step * sum;

    printf("\n Pi = %lf", pi);
    t2 = omp_get_wtime();

    printf("\n Tempo gasto: %lf", t2 - t1);

    return 0;
}