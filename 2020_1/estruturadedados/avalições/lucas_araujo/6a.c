#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pilha
{
    struct Registro * topo;
}Pilha;

typedef struct Registro
{
    char dado;
    struct Registro * prox;
}Registro;

Pilha * cria_pilha();
Registro * cria_registro(char c);
void push(Pilha * p1, char c);
char pop(Pilha * p1);

int main() {
    char * string;
    int i;
    int virada = 0;
    scanf("%m[^\n]s", &string);
    Pilha * novas = cria_pilha();

    for(i = 0; i < strlen(string); i++)
    {
        if(string[i] == 'C')
        {
            virada = 1;
            continue;
        }

        if(!virada)
        {
            push(novas, string[i]);
        }else
        {
            if(pop(novas) != string[i])
            {
                printf("x não é o inverso de y\n");
                return 0;
            }
            
        }
    }
    printf("x é o inverso de y (palindromo)\n");
    return 0;
}

Pilha * cria_pilha()
{
    Pilha * retorno = (Pilha *)malloc(sizeof(Pilha));

    retorno->topo = NULL;

    return retorno;
}

Registro * cria_registro(char c)
{
    Registro * retorno = (Registro *)malloc(sizeof(Registro));

    retorno->dado = c;
    retorno->prox = NULL;

    return retorno;
}

void push(Pilha * p1, char c)
{
    Registro * adicionavel = cria_registro(c);
    if(p1->topo == NULL)
    {
        p1->topo = adicionavel;
    }
    else
    {
        Registro * aux = p1->topo;
        p1->topo = adicionavel;
        adicionavel->prox = aux;
    }
}

char pop(Pilha * p1)
{
    char retorno;
    if(p1->topo == NULL)
    {
        return 'x';
    }
    else
    {
        Registro * aux = p1->topo;
        p1->topo = aux->prox;
        retorno = aux->dado;
        free(aux);
        return retorno;
    }
    
}