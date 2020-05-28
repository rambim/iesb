#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int m[3][3];
    int i_menor, j_menor;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    i_menor = 0;
    j_menor = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (m[i][j] < m[i_menor][j_menor])
            {
                i_menor = i;
                j_menor = j;
            }
        }
    }

    printf("\n O elemento %d que esta na posicao [%d][%d] (linha %d) e o menor elemento da matriz\n", m[i_menor][j_menor], i_menor, j_menor, i_menor);

    return 0;
}