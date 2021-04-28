#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//strlen()

int main()
{
    char nome1[30];
    char nome2[30];
    int tamanho1, tamanho2;

    printf("\n Digite o primeiro nome: ");
    __fpurge(stdin);
    gets(nome1);

    printf("\n Digite o segundo nome: ");
    __fpurge(stdin);
    fgets(nome2,28,stdin);

    tamanho1 = strlen(nome1);
    tamanho2 = strlen(nome2);

    printf("\n Tamanho 1 = %d",tamanho1);
    printf("\n Tamanho 2 = %d",tamanho2);
    return 0;
}