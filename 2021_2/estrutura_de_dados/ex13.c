#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

void mostrar_vetor(long int * vet, long int tam);
long int * aloca_vetor(long int tamanho);
void embaralha_vetor(long int * vet, long int tam);
void bubblesort(long int * vet, long int tam);
void mergesort(long int * vet, long int ini, long int fim);
void intercala(long int * vet, long int inicio, long int meio, long int fim);
void quicksort( long int * vet, long int inicio, long int fim);
void selection_sort(long int * vet, long int tam);

int main()
{

    double t1,t2;

    srand(time(NULL));
    long int * vet;
    long int tam=100000;
    vet = aloca_vetor(tam);

    // printf("\n Antes de embaralhar: ");
    // mostrar_vetor(vet,tam);

    embaralha_vetor(vet,tam);
    // printf("\n Depois de embaralhar: ");
    // mostrar_vetor(vet,tam);

    // printf("\n Ordenando o vet:or");

    t1 = omp_get_wtime();
    // bubblesort(vet,tam);
    // mergesort(vet,0,tam-1);
    // quicksort(vet,0,tam-1);
    selection_sort(vet,tam);
    t2 = omp_get_wtime();

    // printf("\n Mostrar o vetor apos a ordenacao: ");
    // mostrar_vetor(vet,tam);

    printf("\n Tempo para ordenar: %f",t2-t1);


    printf("\n");
    return 0;
}


long int * aloca_vetor(long int tamanho)
{
    long int * novo;
    novo = (long int *)calloc(tamanho,sizeof(long int));
    long int i;

    for(i=0;i<tamanho;i++)
    {
        novo[i] = i+1;
    }
    return novo;
}

void mostrar_vetor(long int * vet, long int tam)
{
    long int i;

    printf("\nMostrando vetor: ");
    for(i=0;i<tam;i++)
    {
        printf(" %ld",vet[i]);
    }
}

void embaralha_vetor(long int * vet, long int tam)
{
    long int i;
    long int ind_aux, aux;
    for(i=0;i<tam;i++)
    {
        ind_aux = rand() % tam;
        aux = vet[i];
        vet[i] = vet[ind_aux];
        vet[ind_aux] = aux;
    }
}

void bubblesort(long int * vet, long int tam)
{
    long int pass,i,aux;
    int trocou=1;

    for(pass=0;pass<tam-1 && trocou==1;pass++)
    {
        trocou=0;
        for(i=0;i<tam-1-pass;i++)
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


void mergesort(long int * vet, long int ini, long int fim)
{
    long int meio;
    if (ini<fim)
    {
        meio = (ini+fim) / 2;
        mergesort(vet,ini,meio);
        mergesort(vet,meio+1,fim);
        intercala(vet,ini,meio,fim);
    }
    return;
}

void intercala(long int * vet, long int inicio, long int meio, long int fim)
{
    long int * aux;
    int i,j,k=0;
    
    aux = (long int*)calloc((fim-inicio+1),sizeof(long int));

    i = inicio;
    j = meio+1;

    while(i<=meio && j<=fim)
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            i++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }

    while(i<=meio)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }

    while(j<=fim)
    {
        aux[k] = vet[j];
        j++;
        k++;
    }

    for(i=0;i<(fim-inicio+1);i++)
    {
        vet[inicio + i] = aux[i];
    }

    free(aux);

    return;
}


void quicksort( long int * vet, long int inicio, long int fim)
{
    if (inicio>fim)
        return ;


    long int pivo,aux;
    long int troca;
    pivo = inicio;
    aux  = fim;
    while(pivo!=aux)
    {
        if (pivo<aux)
        {
            if (vet[pivo] > vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }
        else
        {
            if (vet[pivo]< vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        if (pivo<aux)
        {
            aux--;
        }
        else
        {
            aux++;
        }

    }

    quicksort(vet,inicio,pivo-1);
    quicksort(vet,pivo+1,fim);
}



void selection_sort(long int * vet, long int tam)
{
    long int i, j,ind_menor;
    long int troca;

    for(i=0;i<tam-1;i++)
    {
        ind_menor = i;
        for(j=i;j<tam;j++)
        {
            if (vet[j]<vet[ind_menor])
            {
                ind_menor = j;
            }
        }

        troca = vet[i];
        vet[i] = vet[ind_menor];
        vet[ind_menor] = troca;

    }
}

