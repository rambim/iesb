#include <stdio.h>
#include <stdlib.h>

void escreve_arquivo(FILE *arq, int tam);
void grava_arquivo(char *nome, int j, int tam);

int main()
{
    grava_arquivo("arquivo1.txt", 1, 1);
    grava_arquivo("arquivo2.txt", 10, 1);
    grava_arquivo("arquivo3.txt", 100, 1);
    grava_arquivo("arquivo4.txt", 1, 2);
    grava_arquivo("arquivo5.txt", 10, 2);
 //   grava_arquivo("arquivo6.txt", 100, 2);

    return 0;
}

void grava_arquivo(char *nome, int j, int tam)
{
    FILE *arq;
    int i;
    arq = fopen(nome, "w");

    if (arq == NULL)
    {
        printf("arquivo nao aberto");
        return;
    }

    for (i = 0; i < j; i++)
    {
        escreve_arquivo(arq, tam);
    }
    fclose(arq);
}
void escreve_arquivo(FILE *arq, int tam)
{
    int i;
    int j;

    switch (tam)
    {
    case 1:
        j = 100;
        break;
    case 2:
        j = 1000000;
        break;
    case 3:
        j = 100000000;
        break;
    default:
        printf("tamanho invalido:");
        return;
        break;
    }

    for (i = 0; i < j; i++)
    {
        if (i == 56)
        {
            fprintf(arq, "abcdefghijklmnopqabcdefghijklmnotem que acharjklmnopqrtuvxzabcdefghijklmnopqrtuvxzhijklmnopqrtuvxz");
        }
        else
        {
            fprintf(arq, "abcdefghijklmnopqabcdefghijklmnosdrigijpcjklmnopqrtuvxzabcdefghijklmnopqrtuvxzhijklmnopqrtuvxz");
        }
    }
}