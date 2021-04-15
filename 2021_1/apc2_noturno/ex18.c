#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//strlen()
int vogais(char letra);

int main()
{
    // Diga quantas vogais há no nome digitado.
    char nome[30];
    int i,retorno;

    printf("\n Digite um nome: ");
    __fpurge(stdin);
    fgets(nome, 28, stdin);
    nome[strlen(nome) - 1] = '\0';

    for(i=0;i<strlen(nome);i++)
    {
        retorno = vogais(nome[i]);
        if (retorno==1)
        {
            printf("\n%c e uma vogal",nome[i]);
        }
    }

    return 0;
}

int vogais(char letra)
{
    if ((letra == 'a' || letra == 'A') ||
        (letra == 'e' || letra == 'E') ||
        (letra == 'i' || letra == 'I') ||
        (letra == 'o' || letra == 'O') ||
        (letra == 'u' || letra == 'U'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}