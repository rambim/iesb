#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omp.h"

int main(int argc, char *argv[])
{
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};
    int qtd_threads = atoi(argv[1]);
    
    printf("\n Quantidade de threads solicitadas: %d",qtd_threads);
    omp_set_num_threads(qtd_threads);

    #pragma omp parallel
    {
        int qtd_threads = omp_get_num_threads();
        #pragma omp single
        printf("\n Quantidade de threads conseguidas: %d",qtd_threads);
        int i;
        int id=0;
        id = omp_get_thread_num();
        for(i=id;i<10;i=i+qtd_threads)
        {
            printf("\nthread: %d Posicao %d = %d",id,i,vet[i]);
        }
    }

    return 0;

}