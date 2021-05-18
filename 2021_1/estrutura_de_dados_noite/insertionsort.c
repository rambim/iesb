#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long int *aloca_vetor(long long int x);
void mostrar(long long int *vet, long long int tam);
void insertionsort(long long int * vet, long long int tam);

int main()
{
    
    srand(time(NULL));
    long long int tam;
    long long int *vet;

    clock_t t1, t2; // duas variáveis para guardar o registro clock

    FILE * arq;

    arq = fopen("tempos.csv","w");

    if (arq==NULL)
    {
        printf("\n Problemas com arquivo");
        return 0;
    }

    for (tam = 10000; tam <= 100000; tam = tam + 10000)
    {
        vet = aloca_vetor(tam);
        // printf("\n Desordenado: ");
        // mostrar(vet, tam);
        t1 = clock(); // pega esse instante
        insertionsort(vet,tam);
        t2 = clock(); // pega esse
        // printf("\n Ordenado: ");
        // mostrar(vet, tam);
        float diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
        printf("\n  Tamanho %lld Tempo gasto: %lf",tam, diff);
        fprintf(arq,"%lld;%f\n",tam, diff);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *aloca_vetor(long long int x)
{
    long long int *vetor;
    vetor = (long long int *)calloc(x, sizeof(long long int));
    long long int i, sorteado, aux;

    for (i = 0; i < x; i++)
    {
        vetor[i] = i + 1;
    }

    for (i = 0; i < 100; i++)
    {
        sorteado = rand() % x;
        aux = vetor[i];
        vetor[i] = vetor[sorteado];
        vetor[sorteado] = aux;
    }
    return vetor;
}

void mostrar(long long int *vet, long long int tam)
{
    int i;

    printf("\n Vetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void insertionsort(long long int * vet, long long int tam)
{
    long long int i,j,aux;

    for(i=1;i<tam;i++)
    {
        aux = vet[i];
        for(j=i-1;j>=0 && vet[j]>aux;j--)
        {
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}




