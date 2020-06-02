#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

#define tamanho 90

void mostra_vetor(long int * vet, long int tam);
void funcA(long int * vet, long int tam);
long int fibo_iterativo(long int n);
int primo(long int x);


int main(int argc, char * argv[])
{
    // declarações
    int qtd_threads_global,threads_desejadas;
    long int * vet, i;
    double t1,t2;

    

    //inicializa qtd de threads.
    threads_desejadas = atoi(argv[1]);
    omp_set_num_threads(threads_desejadas);


    //procedure

    //começa a contar tempo
    t1 = omp_get_wtime();    

    vet = (long int*)malloc(sizeof(long int)*tamanho);
    funcA(vet,tamanho);
    //mostra_vetor(vet,tamanho);

    #pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<tamanho;i++)
        {
            if (primo(vet[i]))
            {
                printf("\n Thread:%d -> %ld e primo",omp_get_thread_num(),vet[i]);
            }
            
        }

    }



    //para de contar tempo
    t2 = omp_get_wtime();

    //Tempo gasto: 
    printf("\nTempo : %lf\n",t2-t1);

/*
    #pragma omp parallel
    {
        double x;
        int i;
        int qtd_threads = omp_get_num_threads();
        double temp;
        
        int id = omp_get_thread_num();

        if (id==0)
        {
            qtd_threads_global = qtd_threads;
        }

        #pragma omp for
        for (i = 0; i < num_steps; i = i + 1)
        {
            x = (i + 0.5) * step;
            temp = 4.0 / (1.0 + x * x);
            #pragma omp atomic
            sum = sum + temp;
        }
    }

    pi = pi + step * sum;
    printf("\n");
    


    

*/
    return 0;
}


void mostra_vetor(long int * vet, long int tam)
{
    long int i;

    for(i=0;i<tam;i++)
    {
        printf("%ld\n",vet[i]);        
    }
}


void funcA(long int * vet, long int tam)
{
    long int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = fibo_iterativo(i);
    }
}

long int fibo_iterativo(long int n)
{
    long int ultimo = 1;
    long int penultimo = 1;
    long int atual;
    long int i;

    if (n==0)
    {
        return 0;
    }

    if (n == 1)
    {
        return penultimo;
    }
    else
    {
        if (n == 2)
        {
            return ultimo;
        }
        else
        {
            for (i = 2; i < n; i++)
            {
                atual = ultimo + penultimo;
                penultimo = ultimo;
                ultimo = atual;
            }
        }
    }

    return atual;
}

int primo(long int x)
{
    long int div;
    if (x == 1)
    {
        return 0;
    }
    else
    {
        if (x < 0)
        {
            x = x * (-1);
        }

        #pragma omp parallel
        {
            #pragma omp for
            for (div = 2; div < x; div++)
            {
                if (x % div == 0)
                {
                    return 0;
                }
            }

        }
        return 1;
    }
}

