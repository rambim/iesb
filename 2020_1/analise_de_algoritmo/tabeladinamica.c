#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define tam 100000000
long int * aloca_vetor(long int qtd);
void mostra_vetor(long int * vet , long int qtd);
void copia (long int * vet1, long int  * vet2, long int qtd);

int main()
{
    double t1,t2;
    long int * vet1, * vet2;
    vet1 = aloca_vetor(tam);
    vet2 = aloca_vetor(tam);
    // printf("\n Vetor 1: ");
    // mostra_vetor(vet1,tam);

    // printf("\n Vetor 2: ");
  //  mostra_vetor(vet2,tam);

    t1 = omp_get_wtime();

    copia(vet1,vet2,tam);

    t2 = omp_get_wtime();

    printf("\n Tempo para copia: %lf",t2-t1);
    return 0;

}

long int * aloca_vetor(long int qtd)
{
    int i;
    long int * novo;
    novo = (long int *)malloc(sizeof(long int )* qtd);
    for(i=0;i<qtd;i++)
    {
        novo[i] = 1;
    }

    return novo;
}

void mostra_vetor(long int * vet , long int qtd)
{
    int i;
    for(i=0;i<qtd;i++)
    {
        printf(" %ld",vet[i]);
    }
}

void copia (long int * vet1, long int  * vet2, long int qtd)
{
    int i;
    for(i=0;i<qtd;i++)
    {
        vet2[i] = vet1[i];
    }
}

