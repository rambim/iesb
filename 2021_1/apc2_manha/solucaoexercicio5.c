//5 - Faça um programa que receba do usuário um número N e mostre os N primeiros números primos.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int numero;
    i = 0;
    int div;
    int primo=0;

    printf("\n Digite o valor de N: ");
    scanf("%d", &n);

    for (numero = 2; i < n; numero++)
    {
        primo=1;

        for(div=2;div<numero;div++)
        {
            if (numero%div==0)
            {
                primo=0;
            }
        }
        if (primo)
        {
            printf("%d",numero);
            i++;
        }
    }

    printf("\n");
    return 0;
}


