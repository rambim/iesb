#include <stdio.h>
#include <stdlib.h>



void somar()
{
    int x, y;

    printf("\n Digite o valor de x:");
    scanf("%d",&x);
    printf("\n Digite o valor de y:");
    scanf("%d",&y);
    printf("\n Resultado da soma = %d",x+y);

}

void somar2(int x, int y)
{
    printf("\n Resultado = %d",x+y);
}

int somar3(int x, int y)
{
    int resultado;
    resultado = x+ y;
    return resultado;
}

int main()
{
    int x, y,resultado;

    printf("\n Digite o valor de X:");
    scanf("%d",&x);
    printf("\n Digite o valor de y:");
    scanf("%d",&y);
    resultado = somar3(x,y);

    printf("\n Resultado = %d",resultado);
    printf("\n");
    return 0;
}