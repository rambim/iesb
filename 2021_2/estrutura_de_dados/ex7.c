#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

char pilha[50];
int topo = 0;

void push(char x);
char pop();
char stackpop();
int empty();
int size();

int main()
{
    char palavra[100];
    int i;

    printf("\n Digite uma palavra:");
    __fpurge(stdin); //fflush(stdin) no windows e não precisa da stdlib_ext.h
    fgets(palavra, 100, stdin);
    palavra[strlen(palavra) - 1] = '\0';

    printf("\n Palavra lida: %s", palavra);

    for (i = 0; i < strlen(palavra); i++)
    {
        push(palavra[i]);
    }

    int palindromo = 1;

    for (i = 0; i < strlen(palavra) && palindromo; i++)
    {
        if (pop() != palavra[i])
        {
            palindromo = 0;
        }
    }

    if (palindromo)
        printf("\n Palavra é palindromo");
    else
        printf("\n Não e palindromo");
        
    printf("\n");
    return 0;
}

void push(char x)
{
    if (topo == 50)
    {
        printf("\n Pilha cheia, nao e possivel inserir elementos");
    }
    else
    {
        pilha[topo] = x;
        topo++;
    }
}

char pop()
{
    char retorno;
    if (topo == 0)
    {
        printf("\n Pilha vazia, nao e possivel remover elementos");
    }
    else
    {
        topo--;
        retorno = pilha[topo];
        pilha[topo] = 0;
        return retorno;
    }
    return ' ';
}

char stackpop()
{
    return pilha[topo - 1];
}

int empty()
{
    if (topo == 0)
        return 1;
    else
        return 0;
}

int size()
{
    return topo;
}