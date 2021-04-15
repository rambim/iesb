#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


int main()
{
    char nome1[30];
    char nome2[30];

    printf("\n Digite o primeiro nome: ");
    __fpurge(stdin);
    fgets(nome1,28,stdin);
    nome1[strlen(nome1)-1] = '\0';

    printf("\n Digite o segundo nome: ");
    __fpurge(stdin);
    fgets(nome2,28,stdin);
    nome2[strlen(nome2)-1] = '\0';

    strcat(nome1," ");
    strcat(nome1,nome2);
    
    printf("\n Nome 1: %s Nome 2: %s",nome1,nome2);

    return 0;
}