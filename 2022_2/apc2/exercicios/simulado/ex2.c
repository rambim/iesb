/*

Construa uma função que receba 2 números x e y
inteiros positivos maiores que 2 e retorne quantos números primos
existem dentro do intervalo fechado de X e Y.

Na sua função principal , solicite ao usuário os valores de X
e Y e diga quantos primos há entre eles
*/

#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int qtd_primos(int x, int y);

int main()
{
    int a,b,qtd;
    scanf("%d %d",&a,&b);
    qtd = qtd_primos(a,b);
    printf("\n Existem %d primos entre %d e %d",qtd,a,b);
    printf("\n");
    return 0;
}

int qtd_primos(int x, int y)
{
    int qtd=0,i,aux;

    if (x>y)
    {
        aux = x;
        x = y;
        y = aux;
    }

    for(i=x;i<=y;i++)
    {
        if (primo(i))
        {
            qtd++;
        }
    }
    return qtd;
}

int primo(int x)
{
    if ((x == 1) || (x == 0))
        return 0;

    int div;

    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
            return 0;
    }
    return 1;
}
