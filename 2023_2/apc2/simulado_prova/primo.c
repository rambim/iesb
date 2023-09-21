#include <stdio.h>
#include <stdlib.h>

int funcao(int x , int y);
int primo(int numero);
int main()
{

    int x,y;
    int qtd_primos=0;

    printf("\n Digite o valor de X: ");
    scanf("%d",&x);

    printf("\n Digite o valor de Y: ");
    scanf("%d",&y);

    qtd_primos = funcao(x,y);
    printf("\n Existem %d primos entre %d e %d",qtd_primos,x,y);
    return 0;
}

int funcao(int x , int y)
{
    int i;
    int qtd_primos=0;
    int copo;

    if (x > y)
    {
        copo = x;
        x = y;
        y = copo;
    }

    for(i=x;i<=y;i++)
    {
        if (primo(i)==1)
        {
            printf("\n Primo: %d",i);
            qtd_primos++;
        }
    }   
    return qtd_primos;
}

int primo(int numero)
{
    int divisor;
    if (numero == 1)
        return 0;

    for(divisor=2;divisor<numero;divisor++)
    {
        if (numero % divisor ==0)
        {
            return 0;
        }
    }

    return 1;
}