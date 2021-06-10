

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

// 3- Faça um programa que receba do usuário o nome de um arquivo e uma string. Diga quantas vezes essa string
// aparece no arquivo.

int busca_string(char *texto, char *padrao);
int compara_texto(char *texto1, int tam_1, char *texto2, int tam_2);

int main()
{
    char nome_arquivo[50];
    char texto_procurado[50];
    char linha[500];
    FILE *arq;
    int qtd=0;

    printf("\nDigite o nome do arquivo :");
    __fpurge(stdin);
    fgets(nome_arquivo, 48, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    printf("\nDigite a palavra a ser buscada:");
    __fpurge(stdin);
    fgets(texto_procurado, 48, stdin);
    texto_procurado[strlen(texto_procurado) - 1] = '\0';

    arq = fopen(nome_arquivo, "r");

    if (arq == NULL)
    {
        printf("\nProblemas na abertura do arquivo");
    }
    else
    {
        while(fgets(linha,450,arq)!=NULL)
        {
            // printf("\nlinha: %s",linha);
            qtd = qtd + busca_string(linha,texto_procurado);
        }
        fclose(arq);
    }

    printf("\n Existem %d ocorrencias da palavra %s no arquivo %s",qtd,texto_procurado,nome_arquivo);

    printf("\n");
    return 0;
}

int busca_string(char *texto, char *padrao)
{
    int i;
    int tamanho_texto = strlen(texto);
    int tamanho_padrao = strlen(padrao);
    int flag = 0;
    for (i = 0; i < strlen(texto) - (strlen(padrao) - 1); i++)
    {
        if (compara_texto(&texto[i], tamanho_padrao, padrao, tamanho_padrao))
        {
            flag++;
        }
    }

    return flag;
}

int compara_texto(char *texto1, int tam_1, char *texto2, int tam_2)
{
    int i;
    if (tam_1 != tam_2)
        return 0;

    for (i = 0; i < tam_1; i++)
    {
        if (texto1[i] != texto2[i])
            return 0;
    }
    return 1;
}