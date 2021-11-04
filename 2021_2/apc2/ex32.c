#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arq;

    char linha[10000];

    arq = fopen("teste.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na leitura do arquivo");
    }
    else
    {
        while (fgets(linha, 100, arq) != NULL)
        {
            printf("Linha lida: %s", linha);
        }

        printf("\n Mostrando vogais da linha: ");

        fclose(arq);
    }
    printf("\n");
    return 0;
}