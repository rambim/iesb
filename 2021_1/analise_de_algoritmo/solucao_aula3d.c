#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include "omp.h"

int **aloca_matriz(int l, int c);
void mostrar_matriz(int **m, int l, int c);
void desaloca_matriz(int **m, int l, int c);
void inicializa_matriz(int **m, int l, int c, int *vet);
int subset(int **m, int l, int c);
int *aloca_vetor(int tamanho);
int main()
{
    srand(time(NULL));
    int **m;
    int l, c;
    int *vet;
    int sum;
    int tamanho_vetor;
    double t1, t2;

    // for (sum = 5; sum <= 100; sum = sum + 5)
    // {
    //     for (tamanho_vetor = 5; tamanho_vetor <= 500; tamanho_vetor++)
    //     {
    //     }
    // }

    tamanho_vetor = 10000;
    sum = 10000;
    vet = aloca_vetor(tamanho_vetor);
    m = aloca_matriz(tamanho_vetor + 1, sum + 2);

    t1 = omp_get_wtime();
    inicializa_matriz(m, tamanho_vetor + 1, sum + 2, vet);
    if (subset(m, tamanho_vetor + 1, sum + 2))
        printf("\n Existe subset = %d", sum);
    else
        printf("\nnao existe sub set = %d", sum);
    t2 = omp_get_wtime();
    printf("\n Tempo gasto: %f", t2 - t1);

    // mostrar_matriz(m, tamanho_vetor + 1, sum + 2);
    desaloca_matriz(m, tamanho_vetor + 1, sum + 2);

    printf("\n");
    return 0;
}

int **aloca_matriz(int l, int c)
{
    int **m;
    int i;
    printf("\n Alocando matriz de %d por %d", l, c);

    m = (int **)calloc(l, sizeof(int *));

    for (i = 0; i < l; i++)
    {
        m[i] = (int *)calloc(c, sizeof(int));
    }
    return m;
}

void mostrar_matriz(int **m, int l, int c)
{
    int i, j;

    for (i = 0; i < l; i++)
    {
        printf("\n");
        for (j = 0; j < c; j++)
        {
            printf("\t%d", m[i][j]);
        }
    }
}

void desaloca_matriz(int **m, int l, int c)
{
    int i, j;

    for (i = 0; i < l; i++)
    {
        free(m[i]);
    }
    free(m);
}

void inicializa_matriz(int **m, int l, int c, int *vet)
{
    int i, j;
    m[0][0] = 0;

    for (i = 1; i < l; i++)
    {
        m[i][0] = vet[i - 1];
        m[i][1] = 1;
    }
    for (i = 1; i < c; i++)
    {
        m[0][i] = i - 1;

        if (m[0][i] == vet[0])
            m[1][i] = 1;
    }
}

int subset(int **m, int l, int c)
{
    int i, j;

    for (i = 2; i < l; i++)
    {
        for (j = 2; j < c; j++)
        {

            if (m[i][0] > m[0][j])
            {
                m[i][j] = m[i - 1][j];
            }
            else
            {
                if (m[i - 1][j] == 1)
                    m[i][j] = 1;

                if (m[i - 1][j - m[i][0]] == 1)
                    m[i][j] = 1;
            }
        }
    }

    if (m[l - 1][c - 1] == 1)
        return 1;
    else
        return 0;
}

int *aloca_vetor(int tamanho)
{
    int *vet;
    int i;
    vet = (int *)calloc(tamanho, sizeof(int));

    vet[0] = 3;
    for (i = 1; i < tamanho; i++)
    {
        vet[i] = vet[i - 1] + 1 + rand() % 3;
    }

    return vet;
}