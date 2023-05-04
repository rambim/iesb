/*

Faça um programa que receba 10 números do usuário e mostre na tela quantos e quais são primos

*/

#include <stdio.h>
#include <stdlib.h>

int primo(int x);

int main()
{

    int numero,i;
    int cont=0;

    for(i=0;i<10;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&numero);

        if (primo(numero)==1)
        {
            printf("\n numero %d eh primo",numero);
            cont++;
        }
    }

    printf("\n Existem %d numeros primos",cont);


    printf("\n");
    return 0;
}

// 1 - primo
// 0 - não for primo

int primo(int x)
{
    int div;

    if ( x== 1)
        return 0;

    for(div=2;div<x;div = div + 1)
    {
        if (x%div==0)
            return 0;
    }

    return 1;


}