// Escreva uma função que receba dois números 
// inteiros retorne o menor número

#include <stdio.h>
#include <stdlib.h>

int menor_numero(int a, int b);

int main()
{
    int x, y,menor;
    printf("Digite o valor de X: ");
    scanf("%d",&x);
    printf("Digite o valor de Y: ");
    scanf("%d",&y);

    menor = menor_numero(x,y);

    printf("O menor valor entre %d e %d  e %d",x,y,menor);

    return 0;
}

int menor_numero(int a, int b)
{
    if (a<b)
    {
        return a;
    }
    else{
        return b;
    }
}