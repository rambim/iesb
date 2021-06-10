#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int l, int c);
void mostrar_matriz(int **m, int l, int c);
int *bp(int *valores, int *pesos, int qtd_elementos, int capacidade);
int max(int a, int b);
int knapSack(int W, int wt[], int val[], int n);


int main()
{

    int capacidade = 5;
    int qtd_objetos = 4;
    int valores[] = {50, 70, 30, 60};
    int pesos[] = {3, 4, 2, 5};
    int *vet;


    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Resultado: %d", knapSack(capacidade, pesos, valores, qtd_objetos));
  

    // printf("\nValor %d",bp_recursiva(valores,pesos,qtd_objetos,capacidade));

    // int i;
    // int vlr_maximo=0;
    // int peso_ocupado=0;
    // for (i = 0; i < qtd_objetos; i++)
    // {
    //     if (vet[i])
    //     {
    //         printf("\nValor: %d  Peso: %d", valores[i], pesos[i]);
    //         vlr_maximo = vlr_maximo + valores[i];
    //         peso_ocupado = peso_ocupado + pesos[i];
    //     }
    // }

    // printf("\nValor maximo: %d",vlr_maximo);
    // printf("\nPeso Ocupada: %d",peso_ocupado);

    printf("\n");
    return 0;
}

int **aloca_matriz(int l, int c)
{
    int **m, i;
    m = (int **)calloc(l, sizeof(int *));
    for (i = 0; i < l; i++)
        m[i] = (int *)calloc(c, sizeof(int));

    return m;
}

void mostrar_matriz(int **m, int l, int c)
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", m[i][j]);

        printf("\n");
    }
}

int *bp(int *valores, int *pesos, int qtd_elementos, int capacidade)
{
    int **m, l, c, i, j;

    l = qtd_elementos;
    c = capacidade + 1;

    m = aloca_matriz(l, c);

    int a;
    int b;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == 0)
            {
                if (j < pesos[i])
                    m[i][j] = 0;
                else
                    m[i][j] = valores[i];
            }
            else
            {
                if (j < pesos[i])
                    m[i][j] = m[i - 1][j];
                else
                {
                    a = m[i - 1][j];
                    b = valores[i] + m[i - 1][j - pesos[i]];

                    if (a > b)
                        m[i][j] = a;
                    else
                        m[i][j] = b;
                }
            }
        }
    }

    int *retorno, k;

    retorno = (int *)calloc(qtd_elementos, sizeof(int));

    i = l - 1;
    j = c - 1;

    for (k = l - 1; k >= 0; k--)
    {
        if (i > 0)
        {
            if (m[i][j] == m[i - 1][j])
            {
                retorno[k] = 0;
                i--;
            }
            else
            {
                retorno[k] = 1;
                j = j - pesos[i];
                i--;
            }
        }
        else
        {
            if (m[i][j] == 0)
                retorno[k] = 0;
            else
                retorno[k] = 1;
        }
    }
    return retorno;
}

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1],
                                  wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
    
int max(int a, int b) { return (a > b) ? a : b; }



