#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define PAD 8


static long num_steps = 100000000;
double step;

int main(int argc, char * argv[])
{
    int i,qtd_threads_global,threads_desejadas;
    double pi;
    
    double t1,t2;
    
    step = 1.0 / (double)num_steps;

    threads_desejadas = atoi(argv[1]);


    t1 = omp_get_wtime();

    

        double sum=0.0;
    omp_set_num_threads(threads_desejadas);

    #pragma omp parallel
    {
        double x;
        int i;
        

        #pragma omp for reduction (+:sum)
        for (i = 0; i < num_steps; i = i + 1)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
        

    }
    pi =(step * sum);
    t2 = omp_get_wtime();
    

    printf("\n pi = %lf tempo : %lf", pi,t2-t1);
    printf("\n");
    return 0;
}