#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int left, int right);

int main()
{
    int qtd_caixa;
    int i, ini, fim, j, cont;
    int vetor[10000];
    int ind1, ind2;
    int procurado;
    int flag;
        qtd_caixa = 0;

    while (scanf("%d", &qtd_caixa) == 1)
    {
        
        ini = 0;
        fim = 0;
        ind1 = -1;
        ind2 = -1;

    */

        cont = 0;
        for (i = 0; i < qtd_caixa; i++)
        {
            scanf("%d", &ini);
            scanf("%d", &fim);

            for (j = ini; j <= fim; j++)
            {
                vetor[cont] = j;
                cont++;
            }
        }
        scanf("%d", &procurado);

        quick_sort(vetor, 0, cont - 1);

        /*
    for(i=0;i<cont;i++)
    {
        printf("%d ",vetor[i]);
    }
*/

        for (i = 0; i < cont; i++)
        {
            if (vetor[i] == procurado)
            {
                ind1 = i;
                ind2 = i;
                for (j = i + 1; vetor[i] == vetor[j]; j++)
                {
                    ind2 = j;
                }
                break;
            }
        }

        if (ind1 != -1)
        {
            printf("%d found from %d to %d\n", procurado, ind1, ind2);
        }
        else
        {
            printf("%d not found\n", procurado);
        }
    }

    return 0;
}

void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
    }
}