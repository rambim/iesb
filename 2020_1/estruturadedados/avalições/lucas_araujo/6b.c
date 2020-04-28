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
int pop(Pilha * p1);

int main() {
    char * string;
    int i;
    int virada = 0;
    int tamx = 0;
    int tamy = 0;
    scanf("%m[^\n]s", &string);
    Pilha * novas = cria_pilha();
    
    for(i = 0; i < strlen(string); i++)
    {
        if(string[i]==' ')
        {
            if(tamy != tamx)
            {
                printf("String invalida\n");
                return 0;
            }
            continue;
        }

        if(string[i]=='D')
        {
            virada = 0;
            tamx = 0;
            tamy = 0;
            continue; 
        }

        if(string[i] == 'C')
        {
            virada = 1;
            continue;
        }

        if(!virada)
        {
            push(novas, string[i]);
            tamx++;
        }
        else
        {
            if(pop(novas))
            {
                tamy++;
            }
            else
            {
                printf("String invalida\n");
                return 0;
            }
        }
    }
    printf("String valida\n");
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

int pop(Pilha * p1)
{
    char retorno;
    if(p1->topo == NULL)
    {
        return 0;
    }
    else
    {
        Registro * aux = p1->topo;
        p1->topo = aux->prox;
        retorno = aux->dado;
        free(aux);
        return 1;
    }
    
}