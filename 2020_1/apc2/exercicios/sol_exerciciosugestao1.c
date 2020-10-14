#include <stdio.h>
#include <stdlib.h>

int * cria_vetor ( int n);
void mostra_vetor(int * vet, int n);
void libera_memoria(int * vet);

int main()
{
    int n;
    int * vet;

    printf("\n Digite N: ");
    scanf("%d",&n);
    vet = cria_vetor(n);
    mostra_vetor(vet,n);
    libera_memoria(vet);
    return 0;
}

int * cria_vetor ( int n)
{
    int i;
    int * novo;

    novo = (int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        novo[i] = i + 1;
    }
    return novo;

}

void mostra_vetor(int * vet, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\n",vet[i]);
    }

}

void libera_memoria(int * vet)
{
    free(vet);
}