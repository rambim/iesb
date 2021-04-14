#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int main()
{
    char nome[30];
    int i;

    printf("\n Digite seu nome: ");
    __fpurge(stdin);
    fgets(nome,30,stdin);
    nome[strlen(nome)-1] = '\0';

    printf("\n Nome lido : %s",nome);

    for(i=0;i<strlen(nome);i++)
    {
        if (nome[i] == 'f')
            printf("\n Letra f na posicao %d",i);
    }
    return 0;
}