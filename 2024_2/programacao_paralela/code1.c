#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


void demorado();
int main(int argvc, char * argv[])
{

    double inicio, fim;
    inicio = omp_get_wtime();
    int num_threads = atoi(argv[1]);
    omp_set_num_threads(num_threads);


    int x  = 0;
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        // printf("Tread %d X = %d\n",id,x);
        x = x + 1;
        // printf("Tread %d Somando 1 \n Resultado: X = %d\n" ,id,x);

    }

    printf("\n Resultado = %d\n",x);

    fim = omp_get_wtime();

    printf("Tempo gasto = %lf\n",fim-inicio);

    return 0;
}

void demorado()
{
    int i,j;
    int x;

    for(i=0;i<100000;i++)
    {
        for(j=0;j<50000;j++)
        {
            x=0;
        }
    }
}