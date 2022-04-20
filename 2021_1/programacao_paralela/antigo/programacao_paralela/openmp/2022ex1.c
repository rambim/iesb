#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


static long num_steps = 100;
double step;

int main(int argc, char * argv[])
{
    int i,qtd_threads_global,threads_desejadas;
    double pi;
    double t1,t2;
    
    step = 1.0 / (double)num_steps;

    threads_desejadas = atoi(argv[1]);


    t1 = omp_get_wtime();

    double sum=0;

    omp_set_num_threads(threads_desejadas);

    #pragma omp parallel
    {
        double x,i;
        double sum_thread=0;
        int qtd_threads = omp_get_num_threads();
        
        int id = omp_get_thread_num();

        if (id==0)
        {
            qtd_threads_global = qtd_threads;
        }
        
        for (i = id; i < num_steps; i = i + qtd_threads)
        {
            x = (i + 0.5) * step;
            
            sum_thread = sum_thread + 4.0 / (1.0 + x * x);
        }

        #pragma omp critical
        sum = sum + sum_thread;
    }

    pi = pi + step * sum;

    t2 = omp_get_wtime();
    

    printf("\n pi = %lf tempo : %lf", pi,t2-t1);
    printf("\n");
    return 0;
}