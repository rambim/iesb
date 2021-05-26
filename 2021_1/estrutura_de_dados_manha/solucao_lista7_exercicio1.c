#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *aloca_vetor(long long int n);
void mostrar(long long int *vet, long long int tam);
long long int busca_sequencial(long long int *vet, long long int tam, long long int x);
long long int busca_binaria(long long int *vet, long long int inicio, long long int fim, long long int x);
void delay();
int main()
{
    srand(time(NULL));
    long long int *vet, buscado;
    long long int tam = 100000;
    clock_t t1, t2; // duas variáveis para guardar o registro clock
    long long int retorno;

    FILE * sequencial,*binario;

    sequencial = fopen("sequencial.txt","w");
    binario = fopen("binario.txt","w");

    if (sequencial == NULL || binario == NULL)
    {
        printf("\n Erro na abertura de arquivo");
        return 0;
    }
        
    vet = aloca_vetor(100000);
    // mostrar(vet, tam);

    for (tam = 10000; tam <= 100000; tam = tam + 10000)
    {
        buscado = 10;
        printf("\nTamanho: %lld", tam);
        // Busca sequencial
        t1 = clock(); // pega esse instante
        retorno = busca_sequencial(vet, tam, buscado);
        t2 = clock(); // pega esse

        if (retorno < 0)
            printf("\n Numero nao encontrado");
        else
            printf("\n O numero esta na %lld posicao", retorno);

        float diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
        printf("\nTempo gasto sequencial: %f", diff);
        fprintf(sequencial,"%lld;%f\n",tam,diff);

        // Busca binaria
        t1 = clock(); // pega esse instante
        retorno = busca_binaria(vet, 0, tam - 1, buscado);
        t2 = clock(); // pega esse

        if (retorno < 0)
            printf("\n Numero nao encontrado");
        else
            printf("\n O numero esta na %lld posicao", retorno);

        diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
        printf("\nTempo gasto binario: %f", diff);
        fprintf(binario,"%lld;%f\n",tam,diff);
    }
    free(vet);
    fclose(sequencial);
    fclose(binario);

    printf("\n");
    return 0;
}

long long int *aloca_vetor(long long int n)
{
    long long int *novo, i;
    novo = (long long int *)calloc(n, sizeof(long long int));

    for (i = 0; i < n; i++)
        novo[i] = i * 10 + rand() % 10;

    return novo;
}

void mostrar(long long int *vet, long long int tam)
{
    long long int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
        printf(" %lld", vet[i]);
}

void delay()
{
    int i, j, x;

    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++)
            x = 1;
}

long long int busca_sequencial(long long int *vet, long long int tam, long long int x)
{
    long long int i;
    for (i = 0; i < tam; i++)
    {
        delay();
        if (vet[i] == x)
            return i;
    }

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