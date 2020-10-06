#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"





void mostrar_vetor(long int * vet , long int qtd);
void bubblesort(long int * vet, long int qtd);
long int * aloca_vetor_randomico(long int qtd);
long int * aloca_vetor_ordenado(long int qtd);


int main(int argc, char *argv[])
{
    long int tam;
    long int  * vetor;
    double t1,t2;

    printf("\n Qual tamanho do vetor: ");
    scanf("%ld",&tam);

    t1 = omp_get_wtime();
    // vetor = aloca_vetor_randomico(tam);
    vetor = aloca_vetor_ordenado(tam);
    t2 = omp_get_wtime();

    printf("\n Tempo para gerar vetor: %lf",t2-t1);

    printf("\n Mostrando vetor desordenado:");
    mostrar_vetor(vetor,tam);

    t1 = omp_get_wtime();
    bubblesort(vetor,tam);
    t2 = omp_get_wtime();
    printf("\n Tempo bubblesort vetor: %lf",t2-t1);

    // printf("\n Mostrando o vetor ordenado: ");  
    // mostrar_vetor(vetor,tam);
    printf("\n");
    
    return 0;
}

void bubblesort(long int * vet, long int qtd)
{
    long int aux,pass,i;
    int trocou=1;
    for(pass=0;pass<qtd-1 && trocou==1;pass++)
    {
        trocou=0;
        for(i=0;i<qtd-1-pass;i++)
        {
            if (vet[i] > vet[i+1])
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocou=1;
            }
        }
    }
}


void mostrar_vetor(long int * vet , long int qtd)
{
    long int i;
    for(i=0;i<qtd;i++)
    {
        printf(" %ld",vet[i]);
    }
}


long int * aloca_vetor_randomico(long int qtd)
{
    long int * vetor;
    long int i;
    long int i_aux, aux;
    vetor = (long int*)malloc(sizeof(long int)*qtd);

    for(i=0;i<qtd;i++)
    {
        vetor[i] = i+1;
    }
    srand(time(NULL));

    for(i=0;i<qtd;i++)
    {
        i_aux = rand() % qtd;
        aux = vetor[i];
        vetor[i] = vetor[i_aux];
        vetor[i_aux] = aux;

    }

    return vetor;
}


long int * aloca_vetor_ordenado(long int qtd)
{
    long int * vetor;
    long int i;
    long int i_aux, aux;
    vetor = (long int*)malloc(sizeof(long int)*qtd);

    for(i=0;i<qtd;i++)
    {
        vetor[i] = i+1;
    }
   

    return vetor;
}