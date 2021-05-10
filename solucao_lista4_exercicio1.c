/*
1) Faça um programa que receba um número N inteiro positivo do usuário,
aloque um vetor de tamanho N, preencha os N números do vetor e diga quantos primos
há nesse vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int main()
{
    int n, *vet, i, qtd_primos = 0;
    do
    {
        printf("\n Digite um N inteiro positivo: ");
        scanf("%d", &n);
        if (n < 0)
            printf("\n N invalido, digite novamente");
    } while (n < 0);

    vet = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf("\n Digite um valor: ");
        scanf("%d", &vet[i]);

        if (primo(vet[i]))
        {
            qtd_primos++;
        }
    }

    printf("\n Existem %d numeros primos ",qtd_primos);

    printf("\n");
    return 0;
}

int primo(int x)
{
    if (x == 1 || x == 0)
        return 0;
    int div;
    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
            return 0;
    }
    return 1;
}