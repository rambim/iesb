#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void inicializa_vetor(long int * x,long int tam);


int main(int argc, char * argv[])
{
    int qtd_threads;
    qtd_threads = atoi(argv[1]);

    omp_set_num_threads(qtd_threads);
    long int * vet1, *vet2, *vet3;
    long int tam=90000000,i;

    double t1,t2;

    vet1  = (long int *)malloc(sizeof(long int) * tam);
    vet2  = (long int *)malloc(sizeof(long int) * tam);
    vet3  = (long int *)malloc(sizeof(long int) * tam);
    inicializa_vetor(vet1,tam);
    inicializa_vetor(vet2,tam);
    

    t1 = omp_get_wtime();

    for(i=0;i<tam;i++)
    {
        //vet3[i] = vet1[i] + vet2[i];
        continue;
    }

    t2 = omp_get_wtime();

    printf("\n Execucao sequencial: ");
    printf("\n vet3[0] = %ld",vet3[0]);
    printf("\n vet3[1] = %ld",vet3[1]);
    printf("\n vet3[2] = %ld",vet3[2]);
    printf("\n Tempo = %lf",t2-t1);

    t1 = omp_get_wtime();

    #pragma omp parallel
    {

        int nthreads = omp_get_num_threads();
        int id = omp_get_thread_num();
        long int i;
        
        for(i=id;i<tam;i = i + nthreads)
        {
            continue;
            vet3[i] = vet1[i] + vet2[i];
        }

    }
    t2 = omp_get_wtime();

    printf("\n Execucao paralelo: ");
    printf("\n vet3[0] = %ld",vet3[0]);
    printf("\n vet3[1] = %ld",vet3[1]);
    printf("\n vet3[2] = %ld",vet3[2]);
    printf("\n Tempo = %lf",t2-t1);


   




    return 0;
}

void inicializa_vetor(long int * x,long int tam)
{
    long int i;

    for(i=0;i<tam;i++)
    {
        x[i] = 1;
    }

}