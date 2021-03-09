#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, m, i;

    int *vetor;

    printf("\n Digite o valor de N: ");
    scanf("%d", &n);
    printf("\n Digite o valor de m: ");
    scanf("%d", &m);

    vetor = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("\n Digite um valor: ");
        scanf("%d", &vetor[i]);
        vetor[i] = vetor[i] - m;
    }

    printf("\n Resultado: ");
    for (i = 0; i < n; i++)
    {
        printf("\n %d",vetor[i]);
    }

    printf("\n");
    return 0;
}