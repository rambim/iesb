#include <stdio.h>
#include <stdlib.h>


// Faça um programa receba do usuário um número e diga se esse número é primo.

int main()
{
    //entrada
    int n;

    //saida  1 = primo 
    //       0 = não é primo.
    int e_primo;

    //auxiliares
    int div;

    printf("\n Digite um numero inteiro positivo: ");
    scanf("%d",&n);

    e_primo=1;

    for(div=2;div<n;div++)
    {
        if (n%div==0)
        {
            e_primo=0;
        }
    }

    if (e_primo)
    {
        printf("\n numero primo");
    }
    else
    {
        printf("\n Numero nao e primo");
    }

    return 0;

}