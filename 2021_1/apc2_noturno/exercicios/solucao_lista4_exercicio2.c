// 2) Construa uma função que receba por parâmetro um vetor e seu tamanho, e retorne
// um vetor de tamanho dobrado com os mesmos valores do vetor original. Não esqueça de
// desalocara o vetor original. Na sua função principa, Aloque um vetor de tamanho N,
// preencha seus N valores, e utilizando a função criada, dobre seu tamanho e solicite
// ao usuário para preencher as posições restantes do vetor. Mostre o conteúdo final do vetor
// dobrado.

#include <stdio.h>
#include <stdlib.h>

void mostrar_vetor(int *vet, int tam);
int *aloca_vetor(int tamanho);
void preenche_vetor(int *vet, int tam);
int *dobrar_tamanho_vetor(int *vet, int * tam);

int main()
{
    int tamanho_vetor;
    int *vet,i;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    vet = aloca_vetor(tamanho_vetor);
    preenche_vetor(vet, tamanho_vetor);
    mostrar_vetor(vet, tamanho_vetor);

    vet = dobrar_tamanho_vetor(vet, &tamanho_vetor);

    for (i = tamanho_vetor/2; i < tamanho_vetor; i++)
    {
        printf("\nDigite o %d numero: ", i + 1);
        scanf("%d", &vet[i]);
    }
    mostrar_vetor(vet, tamanho_vetor);

    printf("\n");
    return 0;
}

int *aloca_vetor(int tamanho)
{
    int *novo;
    novo = (int *)malloc(sizeof(int) * tamanho);
    return novo;
}

int *dobrar_tamanho_vetor(int *vet, int * tam)
{
    int *novo, i;
    *tam = *tam * 2;
    novo = (int *)malloc(sizeof(int) * *tam);

    for (i = 0; i < *tam; i++)
    {
        novo[i] = vet[i];
    }
    free(vet);
    return novo;
}

void preenche_vetor(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\nDigite o %d numero: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

void mostrar_vetor(int *vet, int tam)
{
    int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
        printf(" %d", vet[i]);
}