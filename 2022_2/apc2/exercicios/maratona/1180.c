#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x,n,i;
    int menor,posicao;

    scanf("%d",&x);

    for(i=0;i<x;i++)
    {
        scanf("%d",&n);

        if (i==0 || n<menor)
        {
            menor = n;
            posicao=i;
        }
    }

    printf("Menor Valor: %d\n",menor);
    printf("Posicao: %d\n",posicao);



    return 0;


}