// Faça uma função que verifique se um valor é perfeito ou não. Um valor é dito
// perfeito quando ele é igual a soma dos seus divisores excetuando ele próprio.
// (Ex: 6 é perfeito, 6 = 1 + 2 + 3, que são seus divisores). A função deve retornar
// um valor booleano.

#include <stdio.h>
#include <stdlib.h>

int valida_perfeito(int x);

int main()
{
    int numero,retorno;

    //para limbar o cache windows: fflush(stdin), linux: __fpurge(stdin)

    printf("\n Digite um numero: ");
    scanf("%d",&numero);

    retorno = valida_perfeito(numero);

    if (retorno == 1)
    {
        printf("\n numero perfeito");
    }
    else
    {
        printf("\n numero nao e perfeito");
    }
    printf("\n");
    return 0;
}

int valida_perfeito(int x)
{
    int som = 0, i;

    for (i = 1; i < x; i++)
    {
        if (x % i == 0)
            som = som + i;
    }

    if (som == x)
        return 1;
    else
        return 0;
}
