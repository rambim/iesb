#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    int n;

    printf("\n Digite N: ");
    scanf("%d",&n);

    omp_set_num_threads(n);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        #pragma omp single
        {
            printf("\n INICIANDO MUNDO PARALELO vindo da thread %d ",id);
        }
        printf("\n EU SOU A THREAD %d",id);

        #pragma omp barrier
        #pragma omp master
        {
            printf("\n FIM thread = %d",id);
        }


    }


    printf("\n");
    return 0;
}