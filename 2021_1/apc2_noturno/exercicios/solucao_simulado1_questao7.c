// Escreva uma função que recebe por parâmetro um valor inteiro e positivo N
// e retorna o valor de S.

// S = 1 + ½ + 1/3 + ¼ + 1/5 + 1/N.

#include <stdio.h>
#include <stdlib.h>

float calcula_s(int n);

int main()
{
    int n;
    printf("\n Digite o valor de N: ");
    scanf("%d", &n);

    printf("\n Somatorio = %f", calcula_s(n));

    printf("\n");
    return 0;
}

float calcula_s(int n)
{
    if (n <= 0)
    {
        printf("\n numero invalido");
        return 0;
    }
    float som = 0, i;

    for (i = 1; i <= n; i++)
    {
        som = som + (1.0 / (float)i);
    }
    return som;
}
