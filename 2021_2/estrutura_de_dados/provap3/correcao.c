#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i,numero2,vetor[2],cont=0,j;

    for(i=0;i<2;i++)
    {
        scanf("%d",&numero2);
        if(numero2 >= 1 || numero2 <= 1000)
        {
            vetor[i] = numero2;
        }
    }
    int M = vetor[0];
    int N = vetor[1];

    char matriz[M][N];

    for(i=0;i <= M; i++)
    {

        fgets(matriz[i],100,stdin);

    }

    for(i=0;i<=M;i++)
    {
        for(j=0;j<=N;j++)
        {

            if(matriz[i][j] == '#')
            {
                if(matriz[i][j+1] == '.' || matriz[i][j-1] == '.')

                {
                    cont++;
                }
            }
        }

    }

  printf("\n %d",cont);

}