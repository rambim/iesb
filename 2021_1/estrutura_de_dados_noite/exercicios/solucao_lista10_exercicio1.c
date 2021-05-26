#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *aloca_vetor(long long int x);
void mostrar_vetor(long long int *vet, long long int tam);
long long int busca_sequencial(long long int *vet, long long int tam, long long int x);
long long int busca_binaria(long long int *vet, long long int inicio, long long int fim, long long int x);
void delay();

int main()
{
    srand(time(NULL));
    long long int *vet;
    long long tam = 100;
    long long int buscado = 47, retorno;
    float diff;

    FILE *sequencial,*binaria;

    sequencial = fopen("sequencial.txt","w");
    binaria = fopen("binaria.txt","w");

    if (sequencial == NULL || binaria == NULL)
    {
        printf("\nProblemas na abertura de arquivo");
        return 0;
    }

    clock_t t1, t2; // duas variáveis para guardar o registro clock

    for (tam = 100; tam <= 1000; tam = tam + 100)
    {
        printf("\nTamanho: %lld",tam);
        vet = aloca_vetor(tam);
        // mostrar_vetor(vet, tam);

        t1 = clock(); // pega esse instante
        retorno = busca_sequencial(vet, tam, buscado);
        t2 = clock(); // pega esse
        if (retorno < 0)
            printf("\nNumero nao encontrado");
        else
            printf("\nNumero esta na posicao %lld", retorno);

        diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
        printf("\nTempo gasto de forma sequencial: %f", diff);
        fprintf(sequencial,"%lld;%f\n",tam,diff);

        t1 = clock(); // pega esse instante
        retorno = busca_binaria(vet, 0, tam - 1, buscado);
        t2 = clock(); // pega esse
        if (retorno < 0)
            printf("\nNumero nao encontrado");
        else
            printf("\nNumero esta na posicao %lld", retorno);
        diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
        printf("\nTempo gasto de forma binaria: %f", diff);
        fprintf(binaria,"%lld;%f\n",tam,diff);
        free(vet);
    }

    fclose(sequencial);
    fclose(binaria);
    printf("\n");
    return 0;
}

long long int *aloca_vetor(long long int x)
{
    long long int *novo, i;
    novo = (long long int *)calloc(x, sizeof(long long int));

    for (i = 0; i < x; i++)
        novo[i] = i * 10 + rand() % 10;

    return novo;
}

void mostrar_vetor(long long int *vet, long long int tam)
{
    long long int i;

    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

// -1 se não encontrar
// indice do vetor se encontrar
long long int busca_sequencial(long long int *vet, long long int tam, long long int x)
{
    long long int i;

    for (i = 0; i < tam; i++)
        delay();
    if (vet[i] == x)
        return i;

    return -1;
}

long long int busca_binaria(long long int *vet, long long int inicio, long long int fim, long long int x)
{
    if (inicio > fim)
        return -1;

    long long int meio;

    meio = (inicio + fim) / 2;

    delay();
    if (vet[meio] == x)
        return meio;
    else
    {
        if (x < vet[meio])
            return busca_binaria(vet, inicio, meio - 1, x);
        else
            return busca_binaria(vet, meio + 1, fim, x);
    }
}

void delay()
{
    int i, j, x;

    for (i = 0; i < 10000; i++)
        for (j = 0; j < 1000; j++)
            x = 1;
}
