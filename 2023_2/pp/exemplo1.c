#include <stdio.h>
#include "omp.h"


void print_do_felippe(int x);
int main()
{

    double t1,t2;

    t1 = omp_get_wtime();

    int vet[]={1,2,3,4,5,6,7,8,9,10};
    int tam = sizeof(vet)/sizeof(int);

    // print_do_felippe(5);

    omp_set_num_threads(8);
    #pragma omp parallel
    {
        int qtd_threads = omp_get_num_threads();
        int ID = omp_get_thread_num();
        int i;

        for(i=ID;i<tam;i=i+qtd_threads)
        {
            print_do_felippe(i);
        }
        
    }
    printf("Finalizando\n");

    t2 = omp_get_wtime();

    printf("Tempo de execocao: %lf\n",t2-t1);
    return 0;
}

void print_do_felippe(int x)
{
    int i,y,z=0;

    for(i=0;i<100000;i++)
    {
        for(y=0;y<10000;y++)
        {
            z=0;
        }
    }

    printf("Valor %d\n",x);
}