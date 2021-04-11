// 2 - Faça um programa que receba do usuário um número N  par positivo, aloque um vetor dinâmicamente de tamanho N e preencha as 
// N posições com números aleatórios.

// Calcule o somatório dos produtos de cada par de elementos desse vetor de forma sequencial e paralela.
// Evidêncie a melhora de performance na utilização da solução paralela.

// Ex:

// Vetor: 1,2,3,4,5,6,7,8,9,10
// (1*2) + (3*4) + (5*6) + (7*8) + (9*10)


#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

long long int funcao_pesada(long long int x, long long int y);

int main()
{
    int n,i;
    int * vet;
    long long int som=0;
    double t1,t2;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    vet = (int*)calloc(n,sizeof(int));

    // //SEQUENCIAL
    t1 = omp_get_wtime();
    for(i=0;i<n;i++)
    {
        vet[i] = i+1;
    }

    for(i=0;i<n;i=i+2)
    {
        som = som + funcao_pesada(vet[i],vet[i+1]);
    }

    t2 = omp_get_wtime();

    printf("\n Tempo: %lf Somatorio %lld",t2-t1,som);

    som =0;

    // PARALELO

    int qtd_threads = 6;
    omp_set_num_threads(qtd_threads);
    t1 = omp_get_wtime();
    for(i=0;i<n;i++)
    {
        vet[i] = i+1;
    }

    long long int  som_total=0;
    #pragma omp parallel
    {
        int  i;
        long long int som=0;
        int id;
        id = omp_get_thread_num();
        for(i=id*2;i<n;i=i+(qtd_threads*2))
        {
            // printf("\nThread %d indice %d e %d",omp_get_thread_num(),i,i+1);
            som = som + funcao_pesada(vet[i],vet[i+1]);
        }
        printf("\n Somatorio da threada %d = %lld",omp_get_thread_num(),som);

        #pragma omp critical
            som_total = som_total + som;
    }


    t2 = omp_get_wtime();

    printf("\n Tempo: %lf Somatorio %lld",t2-t1,som_total);




    printf("\n");
    return 0;
}

long long int funcao_pesada(long long int x, long long int y)
{
    long long int produto;
    int i,j,z;
    for(i=0;i<10000;i++)
    {
        for(j=0;j<100000;j++)
        {
            z  =1 ;
        }
    }
    produto = x *y;


    return produto;
}