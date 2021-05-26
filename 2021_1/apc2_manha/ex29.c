#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq = NULL;
    int x = 2;
    int y;

    arq = fopen("arquivo_teste.txt", "w");

    if (arq == NULL)
    {
        printf("\n Problema na abertura do arquivo");
    }
    else
    {
        for (x = 0; x < 10; x++)
        {
            fprintf(arq, "Teste teste %d\n", x);
        }

        fclose(arq);
    }

    char linha[100];

    arq = fopen("arquivo_teste.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problema na abertura do arquivo");
    }
    else
    {
        while (fgets(linha, 98, arq) != NULL)
        {
            printf("Linha lida: %s", linha);
        }

        fclose(arq);
    }

    return 0;
}