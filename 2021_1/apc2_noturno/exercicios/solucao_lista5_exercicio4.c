// Faça um programa que receba do usuario um arquivo texto. Crie outro arquivo texto
// contendo o texto do arquivo de entrada, mas com as vogais substituídas por ‘*’.

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int vogal(char l);

int main()
{
    char nome_arquivo[50];

    FILE *arquivo,*arquivo_saida;
    char letra;

    printf("\nDigite o nome do arquivo: ");
    __fpurge(stdin);
    fgets(nome_arquivo, 40, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL)
        printf("\n Arquivo nao localizado");
    else
    {
        arquivo_saida = fopen("saida.txt","w");

        if ( arquivo_saida==NULL)
        {
            printf("\n Nao foi possivel criar um novo arquivo");
        }
        else
        {
            while(!feof(arquivo))
            {
                letra = fgetc(arquivo);
                if (letra != EOF)
                {
                    if (vogal(letra))
                        fprintf(arquivo_saida,"*");
                    else
                        fprintf(arquivo_saida,"%c",letra);

                }
            }
            fclose(arquivo_saida);
        }
        fclose(arquivo);
    }

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