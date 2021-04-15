#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int main()
{
    char nome[10];

    nome[0] = 'a';
    nome[1] = 'b';
    nome[2] = 'c';
    nome[3] = '\0';

    printf("\n Nome: %s",nome);
    printf("\n");
    return 0;
}