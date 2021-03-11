
// 4 - Faça um programa que receba do usuário um número inteiro N e mostre todos os números entre 0 e N.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    for(i=0;i<=n;i++)
    {
        printf("\n %d",i);
    }

    printf("\n");
    return 0;
}