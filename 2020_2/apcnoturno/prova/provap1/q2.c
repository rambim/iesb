/*
Existe uma conjectura que diz o seguinte: Todo número par maior que 4 pode ser composto pela soma de 2 números primos.

Ex: 14 = 3 + 11



Faça um programa em C ansi que receba do usuário um número natural N até que esse número digitado seja maior que 4. Após o usuário ter digitado um número N superior a 4 
mostre na tela 2 números primos que somados são iguais a N.

*/

#include <stdio.h>
#include <stdlib.h>

int primo(int x);

int main()
{
    int numero;
    int b;
    int i;

    do
    {
        printf("\nDigite um numero: ");
        scanf("%d",&numero);

        for(i=2;i<numero;i++)
        {
            if (primo(i))
            {
                b = numero - i;
                if (primo(b))
                {
                    printf("\nA soma de %d com %d (numeros primos) = %d",i,b,numero);
                }
            }
        }

    } while (numero<=4);
    return 0;
}

int primo(int x)
{
    if (x < 0)
    {
        x = x * (-1);
    }

    if (x == 1 || x == 0)
    {
        return 0;
    }

    int div = 2;

    for (div = 2; div <= x / 2; div++)
    {
        if (x % div == 0)
        {
            return 0;
        }
    }

    return 1;
}