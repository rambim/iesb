#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int verifica_igualdade(char *texto1, char *texto2);

int main()
{
    char texto1[30];
    char texto2[30];

    printf("\n Digite o primeiro texto: ");
    __fpurge(stdin);
    fgets(texto1,28,stdin);

    printf("\n Digite o segundo texto: ");
    __fpurge(stdin);
    fgets(texto2,28,stdin);

    if (verifica_igualdade(texto1,texto2))
        printf("\n Textos iguais");
    else
        printf("\n Textos diferentes");


    printf("\n");
    return 0;
}

int verifica_igualdade(char *texto1, char *texto2)
{
    int i;

    if (strlen(texto1) != strlen(texto2))
    {
        return 0;
    }

    for (i = 0; i < strlen(texto1); i++)
    {
        if (texto1[i] != texto2[i])
            return 0;
    }
    return 1;
}