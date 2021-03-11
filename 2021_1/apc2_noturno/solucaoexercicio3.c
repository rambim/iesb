// 3 - Faça um programa que receba do usuário 2 números e diga qual o maior deles

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;

    printf("\n Digite o valor de A: ");
    scanf("%d",&a);
    printf("\n Digite o valor de B: ");
    scanf("%d",&b);

    if (a>b)
    {
        printf("\n Maior numero = %d",a);
    }
    else
    {
        if(b>a)
        {
            printf("\n Maior numero = %d",b);
        }
        else
        {
            printf("\n Os numeros são iguais");
        }
    }

    printf("\n");
    return 0;
}
