//1 - Faça um programa que receba do usuário um número e diga se o número é par ou impar

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;

    printf("\n Digite um numero: ");
    scanf("%d",&x);

    if (x%2==0)
    {
        printf("\n Numero par");
    }
    else
    {
        printf("\n Numero impar");
    }
    return 0;
}