#include <stdio.h>
#include <stdlib.h>

int main()
{

    int opcao = 0;

    while (opcao != 3)
    {

        printf("\n 1 - somar");
        printf("\n 2 - subtrair");
        printf("\n 3 - sair: ");
        scanf("%d",&opcao);
    }

    printf("\n");
    return 0;
}