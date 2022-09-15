#include <stdio.h>
#include <stdlib.h>

int eh_primo(int x);

int main()
{

    int x,divisor;
    int retorno;

    printf("\n Digite um numero: ");
    scanf("%d",&x);

    if (eh_primo(x))
    {
        printf("\n eh primo");
    }
    else
    {
        printf("\n nao eh primo");
    }



    printf("\n");
    return 0;
}

int eh_primo(int x)
{
    int div;

    if ( x== 1)
        return 0;

    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }
    return 1;

}