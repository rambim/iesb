#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd);
int *intersecao(int *x1, int *x2, int n1, int n2, int *qtd);

int main()
{
    int vet1[] = {1, 3, 5, 8, 9, 22, 25, 27};
    int vet2[] = {2, 3, 5, 7, 13, 15, 20, 32, 49};

    int *vet3;
    int tam;

    vet3 = intersecao(vet1, vet2, 8, 9, &tam);

    int i;

    printf("\n Vetor da uniao: ");

    for (i = 0; i < tam; i++)
    {
        printf("\n%d", vet3[i]);
    }

    printf("\n");
    return 0;
}

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{
    int i, j, k;
    int *vet3;

    vet3 = (int *)malloc(sizeof(int) * (n1 + n2));

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2)
    {
        if (x1[i] == x2[j])
        {
            vet3[k] = x1[i];
            i++;
            j++;
        }
        else
        {
            if (x1[i] < x2[j])
            {
                vet3[k] = x1[i];
                i++;
            }
            else
            {
                vet3[k] = x2[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1)
    {
        vet3[k] = x1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vet3[k] = x2[j];
        j++;
        k++;
    }

    *qtd = k;
    return vet3;
}
int *intersecao(int *x1, int *x2, int n1, int n2, int *qtd)
{
    int i, j, k;
    int *vet3;

    vet3 = (int *)malloc(sizeof(int) * (n1 + n2));

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2)
    {
        if (x1[i] == x2[j])
        {
            vet3[k] = x1[i];
            i++;
            j++;
            k++;
        }
        else
        {
            if (x1[i] < x2[j])
            {

                i++;
            }
            else
            {

                j++;
            }
        }
    }

    *qtd = k;
    return vet3;
}