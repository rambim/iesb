/*
Faça um programa em C ansi que receba do usuário 2 números naturais N1 e N2 e mostre todos os 
números primos entre o intervalo fechado entre N1 e N2. Obs.: N2 pode ser menor, igual ou maior que N1.

*/

#include <stdio.h>
#include <stdlib.h>
int primo(int x);

int main()
{

    int i;
    int n1,n2,aux;

    printf("\nDigite n1: ");
    scanf("%d",&n1);
    printf("\nDigite n2: ");
    scanf("%d",&n2);

    if (n2<n1)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }

    for(i=n1;i<=n2;i++)
    {
        if (primo(i))
        {
            printf("\n %d eh primo",i);
        }
    }

    printf("\n");
    return 0;
}

int primo(int x)
{
    if (x < 0)
    {
        x = x * (-1);
    }

    if (x == 1 || x == 0)
    {
        return 0;
    }

    int div = 2;

    for (div = 2; div <= x / 2; div++)
    {
        if (x % div == 0)
        {
            return 0;
        }
    }

    return 1;
}