#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
// #define tempo_sleep 40000
#define tempo_sleep 1

int divisor(int a, int b);
int primo(int x);


int main(int argc, char * argv[])
{
    int qtd_threads_desejadas=0;
    qtd_threads_desejadas = atoi(argv[1]);
    int qtd_primos=0;
    int sum=0;

    // printf("\n Quantidade de threads: %d",qtd_threads_desejadas);
    // printf("\n");

    double t1,t2;

    int i,n, *vet;

    printf("\n Digite N: ");
    scanf("%d",&n);

    vet = (int*)calloc(n,sizeof(int));

    printf("\n Digite N valores: \n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&vet[i]);
    }


    omp_set_num_threads(qtd_threads_desejadas);
    t1 = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum) reduction(+:qtd_primos)
    for(i=0;i<n;i++)
    {
        if (primo(vet[i]))
        {
            printf("\n %d eh primo",vet[i]);
            qtd_primos++;
            sum = sum + vet[i];
        }
        else
        {
            printf("\n %d nao eh primo",vet[i]);
        }
    }
    
    t2 = omp_get_wtime();

    printf("\n Tempo gasto: %f",t2-t1);
    printf("\n Quantidade de primos: %d",qtd_primos);
    printf("\n Somatorio : %d",sum);

    return 0;
}


int primo(int x)
{
        
    if (x<2)
        return 0;

    int div;

    for(div=2;div<x;div++)
    {
        if (divisor(x,div))
            return 0;
    }

    return 1;    

}

int divisor(int a, int b)
{
    int i,j,k;


    for(i=0;i<tempo_sleep;i++)
    {
        for(j=0;j<10000;j++)
        {
            k = 1;
        }
    }

    if (a%b==0)
        return 1;
    else
        return 0;

}