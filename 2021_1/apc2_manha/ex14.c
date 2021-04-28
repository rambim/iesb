#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//gets() : recebe por parâmetro o endereço da primeira posicao onde será armazenado o texto.
// Após a leitura de uma variável inteira, caso seja utilizado a função gets ou fgets, é necessário
// limpar o buffer de leitura

int main()
{
    int idade;
    char nome[30];

    printf("\n Digite sua idade: ");
    scanf("%d",&idade);

    printf("\n Digite seu nome:");
    // fflush(stdin); windows
    __fpurge(stdin);
    gets(nome);

    printf("\n Nome lido : %s",nome);
    // gets(&nome[0]);
    printf("\n");
    return 0;
}