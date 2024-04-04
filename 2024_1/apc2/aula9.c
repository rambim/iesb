#include <stdio.h>
#include <stdlib.h>


int primo(int x);


int main()
{
    int retorno=0;

    int qtd_primos=0;

    int x,y;
    int i;

    printf("Digite o valor de x: \n");
    scanf("%d",&x);
    printf("Digite o valor de y: \n");
    scanf("%d",&y);

    for(i = x; i<=y;i++)
    {
        retorno = primo(i);
        if (retorno == 1)
        {
            printf("%d\n",i);
            qtd_primos++;
        }
    }

    printf("Quantidade de primos: %d",qtd_primos);

    
    return 0;
}

int primo(int x)
{
    int divisor;
    int contador=0;

    for(divisor=2;divisor<x;divisor++)
    {
        if (x%divisor==0)
        {
            contador++;
        }
    }

    if (contador > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}