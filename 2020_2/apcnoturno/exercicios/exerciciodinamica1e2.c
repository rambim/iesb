#include <stdio.h>
#include <stdlib.h>

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd);
int *intersecao(int *x1, int *x2, int n1, int n2, int *qtd);

int main()
{
    int x1[] = {1, 2, 5, 6, 9, 15, 17, 20};
    int x2[] = {1, 3, 4, 5, 8,17};

    int *x3;
    int qtd, i;

    x3 = intersecao(x1, x2, 8, 6, &qtd);

    for (i = 0; i < qtd; i++)
    {
        printf("\n%d ", x3[i]);
    }

    printf("\n");
    return 0;
}

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{
    int *x3;
    int i, j, k;

    x3 = (int *)malloc(sizeof(int) * (n1 + n2));

    i = 0;
    j = 0;
    k = 0;
    *qtd = 0;

    while (i < n1 && j < n2)
    {
        if (x1[i] == x2[j])
        {
            x3[k] = x1[i];
            i++;
            j++;
        }
        else
        {
            if (x1[i] < x2[j])
            {
                x3[k] = x1[i];
                i++;
            }
            else
            {
                x3[k] = x2[j];
                j++;
            }
        }
        k++;
        (*qtd)++;
    }

    while (i < n1)
    {
        x3[k] = x1[i];
        i++;
        k++;
        (*qtd)++;
    }

    while (j < n2)
    {
        x3[k] = x2[j];
        j++;
        k++;
        (*qtd)++;
    }

    return x3;
}

int *intersecao(int *x1, int *x2, int n1, int n2, int *qtd)
{
    int *x3;
    int tam,i,j,k;

    if (n1 < n2)
        tam = n1;
    else
        tam = n2;

    x3 = (int*)malloc(sizeof(int)*tam);

    i=0;
    j=0;
    k=0;
    *qtd=0;

    while(i<n1 && j<n2)
    {
        if (x1[i] == x2[j])
        {
            x3[k] = x1[i];
            i++;
            j++;
            k++;
            (*qtd)++;
        }
        else
        {
            if (x1[i]<x2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
            
        }
        
    }
    return x3;
}