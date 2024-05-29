#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int main()
{
    int par=0,i;
    int encontrei=0;

    do
    {
        printf("Digite um numero par: ");
        scanf("%d",&par);

    } while (par%2!=0);

    for(i=2;i<par && !encontrei;i++)
    {
        if (primo(i) && primo(par-i))
        {
            printf("Os 2 numeros primos %d e %d = %d",i,par-i,par);            
            encontrei=1;
        }
    }

    if (!encontrei)
    {
        printf("Nao existem 2 numeros primos = %d",par);
    }
    return 0;
}

int primo(int x)
{
    if (x == 1 || x == 0)
        return 0;
    int divisor;
    for (divisor = 2; divisor < x; divisor++)
    {
        if (x % divisor == 0)
        {
            return 0;
        }
    }
    return 1;
}