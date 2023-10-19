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
    omp_set_num_threads(qtd_threads);

    double t1,t2;

    t1 = omp_get_wtime();


    step = 1.0 / (double)num_steps;
    #pragma omp parallel
    {
        double x;
        int i;
        int id;
        double sum=0;
        id = omp_get_thread_num();
        for (i = id,sum=0.0; i < num_steps; i = i + qtd_threads)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }

        #pragma omp critical
        sum_geral += sum;

    }


    t2 = omp_get_wtime();

    printf("\n Tempo gasto: %lf",t2-t1);
    pi = step * sum_geral;



    

    printf("pi = %lf",pi);
    return 0;
}