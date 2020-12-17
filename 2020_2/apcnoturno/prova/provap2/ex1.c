#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
    char arquivo1[50];
    char arquivo2[50];
    char a, b;

    FILE *arq1, *arq2;

    printf("\nDigite o nome do arquivo 1: ");
    __fpurge(stdin);
    fgets(arquivo1, 50, stdin);
    arquivo1[strlen(arquivo1) - 1] = '\0';

    printf("\nDigite o nome do arquivo 2: ");
    __fpurge(stdin);
    fgets(arquivo2, 50, stdin);
    arquivo2[strlen(arquivo2) - 1] = '\0';

    printf("\n Arquivo 1: %s Arquivo 2 : %s", arquivo1, arquivo2);

    arq1 = fopen(arquivo1, "r");
    arq2 = fopen(arquivo2, "r");

    if (arq1 == NULL || arq2 == NULL)
    {
        printf("\n Problema em algum dos arquivos");
        return 0;
    }

    int iguais = 1;
    while (iguais)
    {
        a = fgetc(arq1);
        b = fgetc(arq2);
        if (a != b)
        {
            iguais = 0;
        }

        if (a==EOF || b==EOF)
        {
            break;
        }
    }

    if (iguais)
    {
        printf("\n Arquivos iguais");
    }
    else
    {
        printf("\nDiferentes");
    }

    printf("\n");
    return 0;
}