#include <stdio.h>
#include <stdlib.h>


void mostra_vetor(int *vet, int tam);
int *uniao(int *x1, int *x2, int n1, int n2, int *qtd);
void preenche_vetor(int *vet, int tam);
int valida_ordenacao(int *vet, int tam);

int main()
{
    int *x1, *x2, *x3;
    int n1, n2, n3;

    printf("\n Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n1);

    printf("\n Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);

    x1 = (int *)malloc(sizeof(int) * n1);
    x2 = (int *)malloc(sizeof(int) * n2);

    preenche_vetor(x1, n1);
    preenche_vetor(x2, n2);

    printf("\n Mostrando vetor x1: \n");
    mostra_vetor(x1, n1);
    printf("\n Mostrando vetor x2: \n");
    mostra_vetor(x2, n2);

    x3 = uniao(x1, x2, n1, n2, &n3);

    printf("\n Mostrando vetor da uniao de x1 e x2: \n");
    mostra_vetor(x3, n3);

    printf("\n");

    return 0;
}

void preenche_vetor(int *vet, int tam)
{
    int i;

    do
    {
        for (i = 0; i < tam; i++)
        {
            printf("\n Digite um numero: ");
            scanf("%d", &vet[i]);
        }

        if (valida_ordenacao(vet,tam)==0)
        {
            printf("\n Vetor nao esta ordenado, digite novamente: ");
        }

    } while (!valida_ordenacao(vet, tam));
}

void mostra_vetor(int *vet, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
}

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{
    int *novo;
    int i, j, k;

    novo = (int *)malloc(sizeof(int) * (n1 + n2));

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2)
    {
        if (x1[i] == x2[j])
        {
            novo[k] = x1[i];
            i++;
            j++;
        }
        else
        {
            if (x1[i] < x2[j])
            {
                novo[k] = x1[i];
                i++;
            }
            else
            {
                novo[k] = x2[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1)
    {
        novo[k] = x1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        novo[k] = x2[j];
        j++;
        k++;
    }

    *qtd = k;
    return novo;
}

// 1 = esta ordenado
// 0 = nao esta ordenado

int valida_ordenacao(int *vet, int tam)
{
    int i;

    for (i = 0; i < tam - 1; i++)
    {
        if (vet[i] > vet[i + 1])
        {
            return 0;
        }
    }
    return 1;
}