// 1 - Faça um programa que solicite ao usuário o nome de 2 arquivos e diga se os arquivos sãa iguais ou diferentes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
    char nome_arquivo1[50], nome_arquivo2[50];

    FILE *arq1, *arq2;
    char linha1[500], linha2[500];

    printf("\nDigite o nome do primeiro arquivo :");
    __fpurge(stdin);
    fgets(nome_arquivo1, 48, stdin);
    nome_arquivo1[strlen(nome_arquivo1) - 1] = '\0';

    printf("\nDigite o nome do segundo arquivo :");
    __fpurge(stdin);
    fgets(nome_arquivo2, 48, stdin);
    nome_arquivo2[strlen(nome_arquivo2) - 1] = '\0';

    arq1 = fopen(nome_arquivo1, "r");
    arq2 = fopen(nome_arquivo2, "r");

    int iguais=1;

    if (arq1 == NULL || arq2 == NULL)
    {
        printf("\nProblema na abertura dos arquivos");
    }
    else
    {
        char * a,*b;
        do
        {
            linha1[0] = '\0';
            linha2[0] = '\0';
            a = fgets(linha1, 498, arq1);
            b = fgets(linha2, 498, arq2);
            printf("\nLinha1: %s", linha1);
            printf("\nLinha2: %s", linha2);
            if (strcmp(linha1,linha2)!=0)
                iguais=0;
        } while ((a != NULL || b != NULL) && iguais);

        fclose(arq1);
        fclose(arq2);
    }

    if (iguais)
        printf("\n Arquivos iguais");
    else
        printf("\n Arquivos diferentes");

    printf("\n");
    return 0;
}