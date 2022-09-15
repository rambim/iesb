


#include <stdio.h>
#include <stdlib.h>

int eh_primo(int x);

int main()
{
    int i;
    int som=0;

    for(i=1;i<=100;i++)
    {
        if (eh_primo(i))
        {
            som = som + i;
        }
    }

    printf("\n somatorios dos numeros primos entre 1 e 100 : %d",som);
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