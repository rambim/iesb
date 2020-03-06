#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao = 0;

    while (opcao != 5)
    {
        printf("\n 1 - opcao 1");
        printf("\n 2 - opcao 2");
        printf("\n 3 - opcao 3");
        printf("\n 4 - opcao 4");
        printf("\n 5 - Sair");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("executa funcao 1");
            break;
        case 2:
            printf("executa funcao 2");
            break;
        case 3:
            printf("executa funcao 3");
            break;
        case 4:
            printf("executa funcao 4");
            break;
        case 5:
            printf("Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }
    return 0;
}