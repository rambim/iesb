#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char nome[30];
    char nome2[30];

    strcpy(nome,"Felippe");

    printf("Nome copiado: %s",nome);

    strcpy(nome2,nome);

    printf("\nNome 2 = %s",nome2);

    return 0;
}