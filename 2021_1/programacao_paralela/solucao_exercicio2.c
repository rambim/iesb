#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100000000;

double step;

int main(int argc, char *argv[])
{
    double t1, t2;
    int qtd_threads, qtd_real_threads;
    int i;
    double x, pi = 0.0, sum_total = 0.0;

    qtd_threads = atoi(argv[1]);

    printf("\n Quantidade de threads: %d", qtd_threads);

    t1 = omp_get_wtime();

    step = 1.0 / (double)num_steps;
    omp_set_num_threads(qtd_threads);

    #pragma omp parallel
    {
        int i, id, n_threads;
        double sum = 0.0;
        double x;
        id = omp_get_thread_num();
        n_threads = omp_get_num_threads();
        if (id == 0)
        {
            qtd_real_threads = n_threads;
        }

        for (i = id, sum = 0.0; i < num_steps; i = i + n_threads)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }

        #pragma omp critical
        {
            pi = pi + sum * step;
        }
    }

    t2 = omp_get_wtime();

    printf("\n Pi = %lf", pi);

    printf("\n Tempo gasto: %lf", t2 - t1);

    return 0;
}