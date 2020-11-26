#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int vogal(char l);

int main()
{
    char nome[50];
    char nome_do_arquivo[55];
    int i;

    FILE * arq;

    printf("\n Digite seu nome: ");
    // fflush(stdin); //Windows
    __fpurge(stdin);
    fgets(nome,50,stdin);
    nome[strlen(nome)-1] = '\0';

    printf("\n Nome lido: %s",nome);
    strcpy(nome_do_arquivo,nome);
    strcat(nome_do_arquivo,".txt");

    arq = fopen(nome_do_arquivo,"w");

    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        for(i=0;i<strlen(nome);i++)
        {
            if (vogal(nome[i]))
            {
                fprintf(arq,"%c",nome[i]);
            }
        }
        fclose(arq);
    }
    
    printf("\n");
    return 0;
}

int vogal(char l)
{
    int i;
    char * vogais = "aeiouAEIOU";
    for(i=0;i<strlen(vogais);i++)
    {
        if (l == vogais[i])
        {
            return 1;
        }
    }
    return 0;
}