#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void mostrar_vetor(int *vet, int tam);
int funcao_pesada(int x, int y);
void carrega_vetor(int *vet, int tam);
void procura_sequencial(int *vet, int tam, int procurado);
void procura_binaria(int *vet, int inicio, int fim, int procurado);

int main()
{

    double t1, t2 = 0;
    int vet[10000];
    int procurado = 100001;
    carrega_vetor(vet, 10000);
    mostrar_vetor(vet, 10000);

    t1 = omp_get_wtime();
    // procura_sequencial(vet, 60, 101);
    procura_binaria(vet,0,9999,procurado);
    t2 = omp_get_wtime();

    printf("\n Tempo para encontrar: %f", t2 - t1);

    printf("\n");
    return 0;
}

void procura_sequencial(int *vet, int tam, int procurado)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (funcao_pesada(vet[i], procurado))
        {
            printf("\n Achei o numero");
            return;
        }
    }

    printf("\n Nao encontrei o numero");
    return;
}

void procura_binaria(int *vet, int inicio, int fim, int procurado)
{

    printf("\n Entrei: Inicio: %d fim: %d",inicio,fim);
    int meio;

    if (inicio > fim)
    {
        printf("\n Nao encontrado");
        return;
    }
    else
    {
        meio = (inicio + fim) / 2;

        if (funcao_pesada(vet[meio], procurado))
        {
            printf("\n Achei o numero");
        }
        else
        {
            if (procurado > vet[meio])
            {
                procura_binaria(vet, meio+1, fim, procurado);
            }
            else{
                procura_binaria(vet, inicio, meio-1, procurado);

            }
        }
    }
}
void carrega_vetor(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        vet[i] = i + 1;
    }
}

void mostrar_vetor(int *vet, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf(" %d", vet[i]);
    }
}

int funcao_pesada(int x, int y)
{
    int i, j, z;

    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            z = 1;
        }
    }

    if (x == y)
        return 1;
    else
        return 0;
}