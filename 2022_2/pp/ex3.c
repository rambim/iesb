#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 1000000000;
double step;

int main(int argc, char * argv[])
{
    int qtd_threads = atoi(argv[1]);
    double pi,sum_geral=0;

    printf("\n Threads solicitadas: %d",qtd_threads);
    double sum[qtd_threads][16];
    omp_set_num_threads(qtd_threads);

    double t1,t2;

    t1 = omp_get_wtime();


    step = 1.0 / (double)num_steps;
    #pragma omp parallel
    {
        double x;
        int i;
        int id;
        id = omp_get_thread_num();
        for (i = id,sum[id][0]=0.0; i < num_steps; i = i + qtd_threads)
        {
            x = (i + 0.5) * step;
            sum[id][0] = sum[id][0] + 4.0 / (1.0 + x * x);
        }

    }
    int i;
    for(i=0;i<qtd_threads;i++)
    {
        sum_geral = sum_geral + sum[i][0];
    }

    t2 = omp_get_wtime();

    printf("\n Tempo gasto: %lf",t2-t1);
    pi = step * sum_geral;



    

    printf("pi = %lf",pi);
    return 0;
}