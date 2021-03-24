

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{

    omp_set_num_threads(6);

    #pragma omp parallel 
    {

        int i;

        #pragma omp single
        {
            printf("\n Eu sou a single = %d",omp_get_thread_num());
        }


        printf("\n eu sou a thread %d",omp_get_thread_num());
        
    }
    
}

void carregar_variaveis_ambiente()
{
    return ;
}

