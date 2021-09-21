#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

char pilha[1000];
int topo = 0;

int empty();
char pop();
void push(char x);
/*


Escreva um algoritmo para determinar se uma string de caracteres de
entrada é da forma:
xCy
onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de
x (isto é, se x = "ABABBA", y deve equivaler a "ABBABA"). Em cada
ponto, você só poderá ler o próximo caractere da string.

*/

int main()
{
    char texto[1000];

    int i, encontrou_o_c = 0,erro=0;
    char t;
    fgets(texto, 1000, stdin);
    texto[strlen(texto) - 1] = '\0';

    printf("\n Texto lido : %s", texto);

    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == 'C')
        {
            encontrou_o_c = 1;
        }
        else
        {
            if (!encontrou_o_c)
            {
                push(texto[i]);
            }
            else
            {
                t = pop();
                if (t!=texto[i])
                {
                    erro=1;
                }
            }
        }
    }

    if (erro)
    {
        printf("\n Nao eh da forma xCy");
    }
    else
    {
        printf("\n E da forma xCy");
    }
    printf("\n");
}

void push(char x)
{
    if (topo == 1000)
    {
        printf("\n Pilha cheia");
    }
    else
    {
        pilha[topo] = x;
        topo++;
    }
}

char pop()
{

    if (empty())
    {
        printf("\n Pilha vazia");
    }
    else
    {
        topo--;
        return pilha[topo];
    }
    return '\0';
}

int empty()
{
    if (topo == 0)
        return 1;
    else
        return 0;
}

char stackpop()
{
    return pilha[topo - 1];
}
