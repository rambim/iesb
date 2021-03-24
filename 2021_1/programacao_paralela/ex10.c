#include <stdio.h>
#include <stdlib.h>
#include "omp.h"



void funcao(int x);
int main(int argc, char * argv[])
{
    int vet_a[10] = {1,1,1,1,1,1,1,1,1,1};
    int vet_b[10] = {1,1,1,1,1,1,1,1,1,1};
    int vet_c[10];
    long int i;
    long int tamanho=10;
    int x=1;
    omp_set_num_threads(2);
    double t1,t2;
    double t1_t,t2_t;

    t1 = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic,1)
    for(i=0;i<tamanho;i++)
    {   
        t1_t = omp_get_wtime();
        funcao(i);
        t2_t = omp_get_wtime();
        printf("\nindice %ld processaodo pela thread %d levou %lf ",i,omp_get_thread_num(),t2_t - t1_t);

    }

    t2 = omp_get_wtime();

    printf("\n Tempo gasto : %lf",t2-t1);


}

void funcao(int x)
{
    int aux;
    int i,j;
    if (x%2==0)
    {
        aux = 1;
    }
    else
    {
        for(i=0;i<100000;i++)
        {
            for(j=0;j<10000;j++)
            {
                aux = 1;
            }
        }
    }
    return ;    
}

