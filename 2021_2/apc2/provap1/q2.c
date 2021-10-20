#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int qtd_primos(int x, int y);
int main()
{
    int x, y;
    int q_primos;
    
    printf("\n Digite X: ");
    scanf("%d",&x);
    printf("\n Digite Y: ");
    scanf("%d",&y);

    q_primos = qtd_primos(x,y);

    printf("\n Quantidade de primos: %d",q_primos);
    printf("\n Quantidade de primos: %d",qtd_primos(x,y));

    return 0;
}


int qtd_primos(int x, int y)
{
    int aux,i,qtd_primos=0;
    if (x>y)
    {
        aux = x;
        x = y;
        y = aux;
    }


    int retorno;
    for(i=x;i<=y;i++)
    {
        retorno = primo(i);

        if (retorno==1)
            qtd_primos++;
    }
    
    return qtd_primos;
    
}




int primo(int x)
{
    int div;
    if (x < 2)
        return 0;

    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
            return 0;
    }
    return 1;
}