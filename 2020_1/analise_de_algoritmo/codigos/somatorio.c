#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "omp.h"


void somatorio (long long int n);

int main()
{
    int i,j;
     
    somatorio(10);
    somatorio(100);
    somatorio(1000);
    somatorio(10000);
    somatorio(100000);
    somatorio(1000000);
    somatorio(10000000);
    somatorio(100000000);
    
    
    

    
    
    return 0;
    
}


void somatorio (long long int n)
{
    long long int * vet;
    long long int i;

    long long int sum=0;

    double t1,t2,total;

    vet = (long long int*)malloc(sizeof(long long int)*n);

    for(i=0;i<n;i++)
    {
        vet[i] = 1;
    }

    t1 = omp_get_wtime();

    for(i=0;i<n;i++)
    {
        sum = sum + vet[i];
    }

    t2 = omp_get_wtime();
    total = t2 - t1;

    printf("\n Sum: %lli Tempo gasto: %lf",sum,total);  
    

    
}

void somatorio_recursivo(long long n)
