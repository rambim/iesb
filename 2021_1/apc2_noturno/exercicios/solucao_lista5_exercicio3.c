
// 2) Faça um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
// linhas esse arquivo possui.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int vogal(char l);

int main()
{
    FILE *arquivo;
    char letra;
    int qtd_vogais = 0;
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
                if (vogal(letra))
                    qtd_vogais++;
            }
        }
        fclose(arquivo);
    }

    printf("\n Existem %d vogais nesse arquivo",qtd_vogais);

    printf("\n");
    return 0;
}

int vogal(char l)
{
    char vogais[] = "AEIOUaeiou";
    int i;
    for (i = 0; i < strlen(vogais); i++)
    {
        if (l == vogais[i])
            return 1;
    }
    return 0;
}