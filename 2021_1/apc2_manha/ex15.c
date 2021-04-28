#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//fgets()

int main()
{
    char nome[30];

    printf("\n Digite seu nome:");
    __fpurge(stdin);
    fgets(nome,28,stdin);

    printf("\n Nome lido : %s",nome);
    // gets(&nome[0]);
    printf("\n");
    return 0;
}