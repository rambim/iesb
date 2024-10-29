#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

char pilha[TAM];
int topo = 0;

void push(char x);
char pop();
int empty();

int main()
{
    char texto[1000];
    int i;
    int encontrou_c = 0;
    int erro=0;

    scanf("%s", texto);

    printf("Texto lido: %s\n", texto);

    for (i = 0; i < strlen(texto) && !erro; i++)
    {
        if (texto[i] == 'C' || texto[i] == 'c')
        {
            encontrou_c = 1;
        }
        else
        {
            if (!encontrou_c)
            {
                push(texto[i]);
            }
            else{
                if (texto[i] != pop())
                {
                    erro = 1;
                }
            }
        }
    }

    if (!empty())
        erro = 1;

    if (erro)
    {
        printf("nao e do xCy");
    }
    else
    {
        printf("e xCy");
    }

    printf("\n");

    return 0;
}

void push(char x)
{
    if (topo >= TAM)
    {
        printf("\n Pilha cheia");
    }
    else
    {
        pilha[topo++] = x;
    }
}

char pop()
{
    if (topo == 0)
    {
        printf("\n Pilha vazia");
    }
    else
    {
        return pilha[--topo];
    }
}

char stackpop()
{
    if (topo == 0)
    {
        printf("\n Pilha vazia");
    }
    else
    {
        return pilha[topo - 1];
    }
}

int empty()
{
    return topo >= 1 ? 0 : 1;
}