#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao = 0;

    while (opcao != 3)
    {
        printf("\nDigite uma nova opcao");
        scanf("%d", &opcao);
    }

    int numero = 0;

    while (numero < 10)
    {
        printf("\n %d", numero);
        numero = numero + 1;
    }

    for (numero = 0; numero < 3; numero = numero + 1)
    {
        printf("\n %d", numero);
    }

    numero = 2;
    do
    {
        printf("%d", numero);
    } while (numero < 2);
}
