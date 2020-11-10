#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}

void mergesort(int *vet, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio + 1, fim);
        intercala(vet, inicio, meio, fim);
    }
    return;
}

void intercala(int *vet, int inicio, int meio, int fim)
{

    int i, j, k, *aux;

    aux = (int *)malloc(sizeof(int) * (fim - inicio + 1));

    i = inicio;
    j = meio + 1;
    k = 0;

    while (i <= meio && j <= fim)
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            i++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
        }

        k++;
    }

    while (i <= meio)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }

    while (j <= fim)
    {
        aux[k] = vet[j];
        j++;
        k++;
    }

    for(i=0;i<(fim-inicio)+1;i++)
    {
        vet[inicio+i] = aux[i];
    }
    free(aux);
    return ;
}
