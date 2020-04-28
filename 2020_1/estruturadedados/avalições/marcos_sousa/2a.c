#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    int qtd,x;
    struct registro *inicio;
} pilha;

typedef struct registro
{
    char texto;
    struct registro *prox;

} registro;

pilha *aloca_pilha();
registro *aloca_registro();
void push(pilha *p, char x);
int pop(pilha *p);
int empty(pilha *p);
void mostrar(pilha *p);

int main()
{

    pilha *pi;
    int  j;
    int x;
    char *texto;

    texto = (char *)malloc(sizeof(char)) ;

        fflush(stdin);
        printf("Digite o seu nome\n");
        gets(texto);  //recebe o nome
        pi = aloca_pilha();
        x=strlen(texto);
        for (j = 0; j <x; j++)//laço para ver cada texto digitado
        {
                push(pi, texto[j]); //coloca na pilha
        }
printf("\n");
                for (j = 0; j <x; j++)//laço para ver cada texto digitado
        {

                printf("%c", pop(pi)); //o que era o ultimo virou o 1 fazendo ficar ao contrario
        }
        printf("\n");






    return 0;
}

pilha *aloca_pilha()
{
    pilha *novo;
    novo = (pilha *)malloc(sizeof(pilha));
    novo->inicio = NULL;
    novo->qtd = 0;

    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->texto = NULL;
    novo->prox = NULL;
    return novo;
}

void push(pilha *p, char x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->texto = x;

    if (empty(p)) // if(l->inicio==NULL)
    {
        p->inicio = novo;
    }
    else
    {
        novo->prox = p->inicio;
        p->inicio = novo;
    }

    p->qtd++;
}


int pop(pilha *p)
{
    registro *aux = NULL;
    int retorno;

    if (empty(p))
    {
        return -1;
    }
    else
    {
        aux = p->inicio;
        retorno = aux->texto;
        p->inicio = aux->prox;
        free(aux);
        p->qtd--;
        return retorno;
    }
}

int empty(pilha *p)
{
    if (p->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}





