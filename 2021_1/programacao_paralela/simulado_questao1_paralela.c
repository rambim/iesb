// 1 - Faça um programa que receba do usuário um número N inteiro positivo e mostre o somatório dos N primeiros números primos maiores
// que 0 de forma sequencial e paralela. Evidêncie a melhora de performance na utilização da solução paralela.

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int primo(int x);
int main()
{
    int limite=100;
    int count_total =0;
    int chamadas=0;
    int i;
    int vet_final[100];
    int indice_final=0;
    int som_final=0;
    double t1,t2;

    int inicio;
    int fim;
    omp_set_num_threads(6);

    t1 = omp_get_wtime();

    while(count_total < limite)
    {
        inicio = (chamadas * 10);
        fim    = (chamadas * 10)+10;

        #pragma omp parallel
        {
            int count=0;
            int vet[10];
            #pragma omp for schedule(dynamic,1)
            for(i=inicio;i<fim;i++)
            {
                if (primo(i))
                {
                    vet[count] = i;
                    count++;
                }
            }    
            #pragma omp critical
            {
                count_total = count_total + count;     
                for(i=0;i<count;i++)
                {
                   vet_final[indice_final] = vet[i];
                   indice_final++;
                }
            }
        }
        chamadas++;
    }

    for(i=0;i<limite;i++)
    {
        som_final = som_final + vet_final[i];
    }

    t2 = omp_get_wtime();
    omp_get_max_threads
    printf("\nCount total: %d Som final = %d Tempo gasto %lf",count_total,som_final,t2-t1);

    return 0;
}

int primo(int x)
{
    int i,j,z;

    for(i=0;i<10000;i++)
    {
        for(j=0;j<10000;j++)
        {
            z = 1;
        }
    }

    if ((x==0) || (x==1))
        return 0;        
    int div;
    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
        {
            return 0;
        }
    }
    return 1;
}