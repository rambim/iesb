#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50

void mostrar_vetor(long long int *vet, long long int tam);
long long int *cria_vetor(long long int tam, int ordenado);
void bubblesort(long long int *vet, long long int tam);
void quicksort(long long int *vet, long long int inicio, long long int fim);

int main()
{
    srand(time(NULL));

    clock_t start, end;
    long long int i, j, z;

    long long int *vet;

    for (i = 10000000; i <= 10000001; i = i + 10000)
    {

        vet = cria_vetor(i, 0);

        // printf("\n Mostrando vetor desordenado: ");
        // mostrar_vetor(vet,i);

        start = clock(); // tempo inicial
        // bubblesort(vet, i);
        quicksort(vet,0,i-1);
        end = clock(); // tempo final;

        // printf("\n Mostrando vetor ordenado: ");
        // mostrar_vetor(vet,i);
        printf("\n Tamanho do vetor: %lld", i);
        printf("\ntempo gasto %f segundos\n", ((double)(end - start) /
                                               ((double)CLOCKS_PER_SEC))); // impressão do tempo gasto
        free(vet);
    }
}

long long int *cria_vetor(long long int tam, int ordenado)
{
    long long int *vet;
    long long int i;
    long long int sorteio = 0;
    long long int aux;

    vet = (long long int *)malloc(sizeof(long long int) * tam);

    for (i = 0; i < tam; i++)
    {
        vet[i] = i + 1;
    }

    if (ordenado != 1)
    {
        for (i = 0; i < tam; i++)
        {
            sorteio = rand() % tam;
            aux = vet[i];
            vet[i] = vet[sorteio];
            vet[sorteio] = aux;
        }
    }

    return vet;
}

void mostrar_vetor(long long int *vet, long long int tam)
{
    long long int i;
    printf("\n mostrando vetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void bubblesort(long long int *vet, long long int tam)
{
    long long int pass, i, aux;
    int trocou = 1;

    for (pass = 0; pass < tam - 1 && trocou == 1; pass++)
    {
        trocou = 0;
        for (i = 0; i < tam - pass - 1; i++)
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

void quicksort(long long int *vet, long long int inicio, long long int fim)
{
    if (inicio > fim)
        return;

    long long int pivo, aux, troca;

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

