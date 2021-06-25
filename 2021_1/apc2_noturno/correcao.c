#include <stdio.h>
#include <stdlib.h>

int numero_perfeito(int x);
int main()
{
    int numero, verdadeiro, n, i;
    printf("Digite  n:");
    scanf("%d", &n);
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        printf("\nDigite um numero:");
        scanf("%d", &numero);
        fflush(stdin);

        verdadeiro = numero_perfeito(numero);
        if (verdadeiro == 1)
        {
            printf("\nNumero perfeito");
        }
        else
        {
            printf("\nNumero nao perfeito");
        }
    }
    return 0;
}
int numero_perfeito(int x)
{
    int i, cont = 0;
    for (i = 0; i < x; i++)
    {
        if (x % i == 0)
        {
            cont = cont + i;
        }
    }

    if (cont == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}