 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

// Complexidade:

// Bubblesort:
// Melhor caso O(n)
// Pior   caso n²

// Mergesort:
// Melhor caso O(n.logn)
// Pior caso O(n.logn)

// Quicksort:
// Melhor caso O(n.logn)
// Pior caso O(n²)

void mostrar_vetor(long int *vet, long int tam);
void bubblesort(long int *vet, long int tam);
long int *gera_vetor(long int tam);
void embaralha_vetor(long int *vet, long int tam);
void intercala(long int *vet, long int inicio, long int meio, long int fim);
void mergesort(long int *vet, long int inicio, long int fim);
void quicksort(long int *vet, long int inicio, long int fim);
void quicksort2(long int *vet, long int inicio, long int fim);
void insertionsort(long int *vet,long int tam);
void teste(long int * vet , long int tam);


int main()
{
    float t1, t2;
    long int tam;
    long int *vet;
    srand(time(NULL));
    FILE *arq;

    tam= 10;
    vet=gera_vetor(tam);
    embaralha_vetor(vet,tam);

    printf("\n Mostrando antes de ordenar: ");
    mostrar_vetor(vet,tam);
    printf("\n Mostrando depois de ordenar:");
    teste(vet,tam);
    mostrar_vetor(vet,tam);
    return 0;

    arq = fopen("temposinsertionsort.txt", "w");

    if (arq == NULL)
    {
        printf("treta no arquivo");
        return 0;
    }

    for (tam = 10000; tam <= 150000; tam = tam + 10000)
    {
        fprintf(arq, "%ld;", tam);
        t1 = omp_get_wtime();
        vet = gera_vetor(tam);
        embaralha_vetor(vet, tam);
        t2 = omp_get_wtime();
        mostrar_vetor(vet, 10);
        printf("\nTempo total para criacao do vetor: %lf", t2 - t1);

        t1 = omp_get_wtime();
        insertionsort(vet,tam );
        t2 = omp_get_wtime();

        // printf("\n Mostrando conteudo do vetor depois de ordenar: \n");
        mostrar_vetor(vet, 10);
        fprintf(arq, "%lf\n", t2 - t1);
    }

    fclose(arq);

    return 0;
}

void mostrar_vetor(long int *vet, long int tam)
{
    long int i;
    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("%ld ", vet[i]);
    }
}

void bubblesort(long int *vet, long int tam)
{
    long int vezes, i;
    long int aux;
    int trocou = 1;

    for (vezes = 0; (vezes < (tam - 1)) && trocou == 1; vezes++)
    {
        trocou = 0;
        for (i = 0; i < tam - 1 - vezes; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou = 1;
            }
        }
    }
}

void mergesort(long int *vet, long int inicio, long int fim)
{
    long int meio;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio + 1, fim);
        intercala(vet, inicio, meio, fim);
    }
    return;
}

void quicksort1(long int *vet, long int inicio, long int fim)
{

    if (inicio >= fim)
    {
        return;
    }

    long int pivo, aux, troca;
    pivo = inicio;
    aux = fim;

    while (pivo != aux)
    {
        if (pivo < aux)
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
            if (vet[pivo] < vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        if (aux > pivo)
        {
            aux--;
        }
        else
        {
            aux++;
        }
    }

    quicksort1(vet, inicio, pivo - 1);
    quicksort1(vet, pivo + 1, fim);
}


void quicksort2(long int *vet, long int inicio, long int fim)
{
    // printf("\nInicio: %ld Fim %ld",inicio,fim);
    long int i,j,pivo,aux;

    i = inicio;
    j = fim;

    pivo = vet[(inicio+fim)/2];

    do
    {
        while(vet[i]<pivo &&i<fim)
        {
            i++;
        }

        while(vet[j]>pivo && j>inicio)
        {
            j--;
        }
        if (i<=j)
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    } while (i<=j);

    if (inicio<j)
    {
        quicksort2(vet,inicio,j);
    }

    if (i<fim)
    {
        quicksort2(vet,i,fim);
    }
    // return ;
}


void intercala(long int *vet, long int inicio, long int meio, long int fim)
{

    long int i, j, k, *aux;

    aux = (long int *)malloc(sizeof(long int) * (fim - inicio + 1));

    i = inicio;
    j = meio + 1;
    k = 0;

    while (i <= meio && j <= fim)
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

    while (i <= meio)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }

    while (j <= fim)
    {
        aux[k] = vet[j];
        j++;
        k++;
    }

    for (i = 0; i < (fim - inicio) + 1; i++)
    {
        vet[inicio + i] = aux[i];
    }
    free(aux);
    return;
}


void insertionsort(long int *vet, long int tam)
{
    int i, j, ind_menor, aux;
    
    for(i=0;i<tam-1;i++)
    {
        ind_menor = i;
        for(j=i+1;j<tam;j++)
        {
            if (vet[j] < vet[ind_menor])
            {
                ind_menor = j;
            }
        }

        aux = vet[i];
        vet[i] = vet[ind_menor];
        vet[ind_menor] = aux;
    }

    return;
}


long int *gera_vetor(long int tam)
{
    long int *vet;
    long int i;
    vet = (long int *)malloc(sizeof(long int) * tam);
    for (i = 0; i < tam; i++)
    {
        vet[i] = i + 1;
    }

    return vet;
}

void embaralha_vetor(long int *vet, long int tam)
{
    long int ind_aux, aux;
    long int i;
    for (i = 0; i < tam; i++)
    {
        ind_aux = rand() % tam;

        aux = vet[i];
        vet[i] = vet[ind_aux];
        vet[ind_aux] = aux;
    }
}

void teste(long int * vet ,long  int tam)
{
    int i,j,aux;

    for(i=1;i<tam;i++)
    {
        aux = vet[i];
        for(j=i-1;j>=0 && vet[j] > aux;j--)
        {
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}














