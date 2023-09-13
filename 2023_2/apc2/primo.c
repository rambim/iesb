#include <stdio.h>

int main()
{
    int numero;
    int divisor;
    int qtd_divisores;

    printf("Digite um numero inteiro: \n");
    scanf("%d",&numero);

    for(divisor=2;divisor<numero;divisor++)
    {
        if (numero % divisor == 0)
        {
            qtd_divisores++;
        }
    }

    if (qtd_divisores ==0)
    {
        printf("Numero primo\n");
    }
    else{
        printf("Numero nao e primo\n");
    }
}
