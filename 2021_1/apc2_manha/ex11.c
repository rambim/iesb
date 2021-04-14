#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int main()
{
    char nome1[30];
    char nome2[30];
    int tamanho1;
    int tamanho2;

    printf("\n Digite seu nome: ");
    __fpurge(stdin);
    gets(nome1);

    tamanho1 = strlen(nome1);

    printf("\n Digite seu nome: ");
    __fpurge(stdin);
    fgets(nome2,30,stdin);
    nome2[strlen(nome2)-1] = '\0';

    tamanho2 = strlen(nome2);

    printf("\n Tamanho 1 = %d tamanho 2 = %d",tamanho1,tamanho2);
    return 0;
}