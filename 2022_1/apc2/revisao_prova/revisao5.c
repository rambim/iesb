/*

Faça um programa que receba do usuário 10 números e mostre na tela o somatório dos números 
pares


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, i;
    int som =0;

    for(i=0;i<10;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&numero);

        if (numero % 2 ==0 )
        {
            som = som + numero;
        }
    }

    printf("\n Somatorio dos pares: %d",som);
    return 0;
}