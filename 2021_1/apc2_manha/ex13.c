#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//gets() : recebe por parâmetro o endereço da primeira posicao onde será armazenado o texto.

int main()
{
    char nome[30];

    printf("\n Digite seu nome:");
    gets(nome);

    printf("\n Nome lido : %s",nome);
    // gets(&nome[0]);
    printf("\n");
    return 0;
}