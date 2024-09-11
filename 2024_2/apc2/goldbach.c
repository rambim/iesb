#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int main()
{
    int x,i,achou_primos=0;

    printf("Digite um numero par: ");
    scanf("%d",&x);

    for(i=1;i<=x && !achou_primos;i++)
    {
        if (primo(i) && primo(x-i))
        {
            printf("%d + %d = %d\n",i,x-i,x);
            achou_primos = 1;
        }
    }


    return 0;
}


// 1 - primo
// 0 - não primo
int primo(int x)
{
    if (x<2)
        return 0;
    int divisor;
    for(divisor=2;divisor<x;divisor++)
    {
        if (x%divisor==0)
            return 0;
    }
    return 1;
}