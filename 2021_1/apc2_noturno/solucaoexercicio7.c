// 7 - Faça um programa que receba do usuário dois números A e B e mostre na tela todos os números entre A e B.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i;

    printf("\n Digite o valor de A: ");
    scanf("%d",&a);
    printf("\n Digite o valor de B: ");
    scanf("%d",&b);

    if (a>b)
    {
        i = a;
        a = b;
        b = i;
    }

    for(i=a;i<=b;i++)
    {
        printf("\n %d",i);
    }
    printf("\n");
    return 0;
}