#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void mostrar_vetor(long long int *vet, long long int tamanho);
long long int *cria_vetor_zerado(long long int tamanho);
long long int *cria_vetor_embaralhado(long long int tamanho);
void bubble(long long int *vet, long long int tam);
void quicksort(long long int *vet, long long int inicio, long long int fim);

int main(int argc, char * argv[])
{
    int i;

    clock_t inicio, fim;
    long long *vet1, *vet2;
    double tempo;
    int tam = atoi(argv[1]);
    printf("Tamanho = %d",tam);

    vet1 = cria_vetor_embaralhado(tam);
    // printf("Mostrando vetor embaralhado: \n");
    // mostrar_vetor(vet1,tam);
    inicio = clock();
    // bubble(vet1,tam);
    quicksort(vet1,0,tam-1);
    fim = clock();
    // printf("Mostrando vetor ordenado: \n");
    // mostrar_vetor(vet1,tam);
    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de ordenacao: %lf\n",tempo);


    // vet2 = cria_vetor_zerado(tam);
    // memcpy(vet2, vet1, sizeof(long long int) * tam);

    // mostrar_vetor(vet2, tam);

    return 0;
}

long long int *cria_vetor_embaralhado(long long int tamanho)
{
    srand(time(NULL));
    long long int *vet;
    long long int i;
    int sorteio, aux;
    vet = (long long int *)calloc(tamanho, sizeof(long long int));

    for (i = 0; i < tamanho; i++)
    {
        vet[i] = i + 1;
    }

    for (i = 0; i < tamanho; i++)
    {
        sorteio = rand() % tamanho;
        aux = vet[i];
        vet[i] = vet[sorteio];
        vet[sorteio] = aux;
    }

    return vet;
}

long long int *cria_vetor_zerado(long long int tamanho)
{
    long long int *vet;
    vet = (long long int *)calloc(tamanho, sizeof(long long int));
    return vet;
}

void mostrar_vetor(long long int *vet, long long int tamanho)
{
    long long int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%lld\n", vet[i]);
    }
    printf("\n");
}

void bubble(long long int *vet, long long int tam)
{
    long long int pass, i, aux;
    int trocou = 1;

    for (pass = 0; pass < tam - 1 && trocou; pass++)
    {
        trocou=0;
        for (i = 0; i < tam - 1 - pass; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                trocou=1;
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
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