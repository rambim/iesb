#include <stdio.h>
#include <stdlib.h>

int perfeito(int x);
int primo(int x);
int main()
{
    int perfeitos[100], qtd_perfeitos = 0, i;
    int som = 0;

    for (i = 1; i < 10000; i++)
    {
        if (perfeito(i))
        {
            perfeitos[qtd_perfeitos] = i;
            qtd_perfeitos++;
        }
    }

    printf("Numeros perfeitos encontrados: \n");
    for (i = 0; i < qtd_perfeitos; i++)
    {
        printf("%d\n", perfeitos[i]);
    }

    int x, y;

    do
    {
        printf("Digite o valor de X: ");
        scanf("%d", &x);
        printf("Digite o valor de Y: ");
        scanf("%d", &y);

        if (x > qtd_perfeitos || y > qtd_perfeitos)
        {
            printf("Valores de X ou Y não podem ultrapassar %d (qtd_perfeitos)\n", qtd_perfeitos);
        }

    } while (x > qtd_perfeitos || y > qtd_perfeitos);

    for (i = perfeitos[x - 1]; i <= perfeitos[y - 1]; i++)
    {
        if (primo(i))
        {
            printf("Numero primo encontrado: %d\n", i);
            printf("Somatorio antes da soma = %d\n", som);
            som = som + i;
            printf("Somatorio depois da soma = %d\n", som);
        }
    }

    printf("O Somatorio dos numeros primos entre o %d e o %d = %d", perfeitos[x-1],perfeitos[y-1],som);

    printf("\n");

    return 0;
}

int perfeito(int x)
{
    int som = 0, i;

    for (i = 1; i < x; i++)
        if (x % i == 0)
            som += i;

    return som == x ? 1 : 0;
    // if (som==x)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
}

int primo(int x)
{
    if (x == 0 || x == 1)
        return 0;

    int divisor;

    for (divisor = 2; divisor < x; divisor++)
        if (x % divisor == 0)
            return 0;
    return 1;
}

// perfeito

// ler 2 numeros

// fazer um for intervalo dos 2 numeros.

// primo

// somatorio