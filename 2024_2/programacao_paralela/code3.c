#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define QTD_THREADS 4

static long num_steps = 2000000000;
double step;
int main()
{


    double inicio, fim;
    inicio = omp_get_wtime();

    omp_set_num_threads(QTD_THREADS);


    double pi;
    double step = 1.0 / (double)num_steps;
    double  sum_global[QTD_THREADS];
    

    #pragma omp parallel
    {

        int i,id=omp_get_thread_num();
        double x;
        double sum=0;
        for (i = id ; i < num_steps; i = i + QTD_THREADS)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }

        sum_global[id] = sum;
    }

    int j;
    double som_total=0;

    for (j=0;j<QTD_THREADS;j++)
    {
        som_total = som_total + sum_global[j];
    }
    pi = step * som_total;

    fim = omp_get_wtime();

    printf("\nTempo gasto: %lf",fim-inicio);
    printf("\n%f",pi);
    return 0;
}