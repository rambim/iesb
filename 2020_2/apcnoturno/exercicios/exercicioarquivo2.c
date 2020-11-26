#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int qtd_linhas_arq(char *nome_arquivo);
int main()
{

    char nome_arq1[50], nome_arq2[50];

    printf("\n Digite o nome do arquivo 1: ");
    // fflush(stdin); //Windows
    __fpurge(stdin);
    fgets(nome_arq1, 50, stdin);
    nome_arq1[strlen(nome_arq1) - 1] = '\0';

    printf("\n Digite o nome do arquivo 2: ");
    // fflush(stdin); //Windows
    __fpurge(stdin);
    fgets(nome_arq2, 50, stdin);
    nome_arq2[strlen(nome_arq2) - 1] = '\0';

    if (qtd_linhas_arq(nome_arq1) > qtd_linhas_arq(nome_arq2))
    {
        printf("\nArquivo %s possui mais linhas que o arquivo %s", nome_arq1, nome_arq2);
    }
    else
    {
        if (qtd_linhas_arq(nome_arq1) < qtd_linhas_arq(nome_arq2))
        {
            printf("\nArquivo %s possui mais linhas que o arquivo %s", nome_arq2, nome_arq1);
        }
        else
        {
            printf("\nQuantidade de linhas iguais nos arquivos %s e %s",nome_arq1, nome_arq2);
        }
        
    }

    printf("\n");
    return 0;
}

int qtd_linhas_arq(char *nome_arquivo)
{
    FILE *arq;
    char linha[10000];
    int count = 0;

    arq = fopen(nome_arquivo, "r");

    if (arq == NULL)
    {
        return 0;
    }
    else
    {
        while (fgets(linha, 10000, arq) != NULL)
        {
            count++;
        }
        fclose(arq);
    }

    return count;
}