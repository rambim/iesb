#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int conta_primos(int x, int y);
int main()
{
    int x, y;

    do
    {
        printf("\n Digite o valor de x: ");
        scanf("%d", &x);

    } while (x < 2);

    do
    {
        printf("\n Digite o valor de y: ");
        scanf("%d", &y);

    } while (y < 2);

    printf("\n Existem %d primos entre %d e %d", conta_primos(x, y), x, y);
    printf("\n");
    return 0;
}

int conta_primos(int x, int y)
{
    int aux, i;
    int qtd_primos = 0;
    if (x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    for (i = x; i <= y; i++)
    {
        if (primo(i))
            qtd_primos++;
    }
    return qtd_primos;
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