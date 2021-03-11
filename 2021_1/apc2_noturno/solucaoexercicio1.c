// 1 - Faça um programa que receba do usuário um número e diga se o número é par ou impar

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    if ( n % 2==0)
    {
        printf("\n Numero par ");
    }
    else
    {
        printf("\n numero impar");
    }
    printf("\n");
    return 0;
}