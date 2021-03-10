// 7 - Faça um programa que receba do usuário dois números N e M e mostre na tela todos os números entre N e M.


#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n,m,i;

    printf("\n Digite o valor de n: ");
    scanf("%d",&n);
    printf("\n Digite o valor de m: ");
    scanf("%d",&m);

    if (n>m)
    {
        i = n;
        n = m;
        m = i;
    }

    for(i=n;i<=m;i++)
    {
        printf("\n %d",i);
    }

    printf("\n");
    return 0;
}