/*
Implemente uma função int ehPrimo(int n) que
recebe um número inteiro n como parâmetro e
retorna 1 se o número for primo e 0 caso contrário.
Escreva também a função main para testar diferentes
valores de n.

*/

#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int n);
void main()
{

    int n;
    int retorno;

    

    for(n=2;n<1000;n++)
    {
        retorno = ehPrimo(n);
        if (retorno == 1)
        {
            printf("O numero %d eh primo\n",n);
        }
        else
        {
            printf("o numero %d nao eh primo\n",n);
        }
    }
}

int ehPrimo(int n)
{
    int divisor;

    if (n == 1)
    {
        return 0;
    }

    for (divisor = 2; divisor < n; divisor++)
    {
        if (n % divisor == 0)
        {
            return 0;
        }
    }

    return 1;
}
