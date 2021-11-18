#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arq;

    char letra;
    int qtd_linhas=0;

    arq = fopen("teste.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
        return 0;
    }
    else
    {

        letra = fgetc(arq);
        while (letra != EOF)
        {
            // printf("\nLetra lida: %c",letra);
            if (letra == '\n')
            {
                qtd_linhas++;
            }
            letra = fgetc(arq);
        }

        fclose(arq);
    }

    printf("\n Existem %d linhas no arquivo",qtd_linhas);

    printf("\n");
    return 0;
}
