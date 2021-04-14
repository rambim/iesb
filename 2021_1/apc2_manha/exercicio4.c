/*

1 - Construa uma função que recebe por parâmetro 1 caracter e retorne se é uma vogal ou não.
Na sua função principal, leia o nome do usuário com até 50 caracteres e mostre na tela
quantas e quais vogais há nesse nome:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int vogal(char x);
int main()
{
    char nome[50];
    int qtd = 0, i;

    printf("\n Digite seu nome: ");
    __fpurge(stdin);
    fgets(nome,50,stdin);
    nome[strlen(nome) - 1] = '\0';

    for (i = 0; i < strlen(nome); i++)
    {
        if (vogal(nome[i]))
        {
            qtd++;
            printf("\n vogal: %c", nome[i]);
        }
    }

    printf("\n Quantidade de vogais: %d",qtd);
    printf("\n");
    return 0;
}

int vogal(char x)
{
    if ((x == 'A') || (x == 'a') ||
        (x == 'E') || (x == 'e') ||
        (x == 'I') || (x == 'i') ||
        (x == 'O') || (x == 'o') ||
        (x == 'U') || (x == 'u'))
        return 1;
    else
        return 0;
}