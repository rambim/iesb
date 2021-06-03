
// 2) Faça um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
// linhas esse arquivo possui.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
    FILE *arquivo;
    char letra;
    int qtd_linhas = 1;
    char nome_do_arquivo[50];
    printf("\nDigite o nome do arquivo: ");
    __fpurge(stdin);
    fgets(nome_do_arquivo, 40, stdin);
    nome_do_arquivo[strlen(nome_do_arquivo) - 1] = '\0';

    arquivo = fopen(nome_do_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("\n Arquivo nao encontrado");
    }
    else
    {
        while (!feof(arquivo))
        {
            letra = fgetc(arquivo);
            if (letra != EOF)
            {
                if (letra == '\n')
                    qtd_linhas++;
            }
        }
        fclose(arquivo);
    }

    printf("\n Existem %d linhas nesse arquivo",qtd_linhas);

    printf("\n");
    return 0;
}