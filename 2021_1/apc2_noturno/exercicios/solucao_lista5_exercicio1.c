/*
1) Faça um programa que leia o nome do usuário, guarde as vogais do nome em um arquivo vogais.txt e as consoantes em um arquivo consoantes.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int vogal(char l);

int main()
{
    FILE *vogais, *consoantes;
    char nome[50];
    int i;

    vogais = fopen("vogais.txt", "w");
    consoantes = fopen("consoantes.txt", "w");

    if (vogais == NULL || consoantes == NULL)
    {
        printf("\n Problemas na abertura dos arquivos");
        return 0;
    }

    printf("\nDigite seu nome: ");
    __fpurge(stdin);
    fgets(nome, 40, stdin);
    nome[strlen(nome) - 1] = '\0';

    for (i = 0; i < strlen(nome); i++)
    {
        if (nome[i] != ' ')
        {
            if (vogal(nome[i]) == 1)
                fprintf(vogais, "%c", nome[i]);
            else
                fprintf(consoantes, "%c", nome[i]);
        }
    }

    fclose(vogais);
    fclose(consoantes);

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