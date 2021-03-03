#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int e_primo;
    int div;

    printf("\n Digite um numero inteiro positivo: ");
    scanf("%d",&n);

    e_primo=2;

    for(div=2;div<n;div++)
    {
        if (n%div==0)
        {
            e_primo=0;
        }
    }

    if (e_primo==1)
        printf("\n numero primo");
    else
        printf("\n Numero nao e primo");

    return 0;

}