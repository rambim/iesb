#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;

} registro;

void mostrar(lista *l);
lista *aloca_lista();
registro *aloca_registro();
void push(lista *l, int x);
int pop(lista *l);
void menu(lista *l);
int empty(lista *l);
int stack_pop(lista *l);

int main()
{

    lista *pilha;
    int qtd, i, j;
    char *texto;
    int diamantes = 0;

    texto = (char *)malloc(sizeof(char) * 1000);

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++)
    {

        //fflush(stdin);  no windows
        //__fpurge(stdin); // no linux #include <stdio_ext.h>
        //fgets(texto,1000,stdin);
        pilha = aloca_lista();
        diamantes = 0;
        scanf("%s", texto);
        for (j = 0; j < strlen(texto); j++)
        {
            if (texto[j] == '<')
            {
                push(pilha, 1);
            }
            else
            {
                if (texto[j] == '>')
                {

                    if (pop(pilha) == 1)
                    {
                        diamantes++;
                    }
                }
            }
        }
        printf("%d", diamantes);
        free(pilha);
        printf("\n");
    }

    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->qtd = 0;

    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void push(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (empty(l)) // if(l->inicio==NULL)
    {
        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }

    l->qtd++;
}

void mostrar(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n valor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}

int pop(lista *l)
{
    registro *aux = NULL;
    int retorno;

    if (empty(l))
    {
        return -1;
    }
    else
    {
        aux = l->inicio;
        retorno = aux->valor;
        l->inicio = aux->prox;
        free(aux);
        l->qtd--;
        return retorno;
    }
}

int empty(lista *l)
{
    if (l->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_pop(lista *l)
{
    if (!empty(l))
    {
        return l->inicio->valor;
    }
    else
    {
        return -1;
    }
}

void menu(lista *l)
{
    int opcao;
    int numero;
    int retorno;
    registro *aux;

    do
    {

        printf("\n");
        printf("\n 1 - push");
        printf("\n 2 - pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Sair");
        printf("\n");
        mostrar(l);
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            push(l, numero);
            break;
        case 2:

            if (!empty(l))
            {
                printf("\n Pop de  %d", pop(l));
            }
            else
            {
                printf("\n Pilha vazia");
            }
            break;
        case 3:
            if (!empty(l))
            {
                printf("\n Pop de  %d", stack_pop(l));
            }
            else
            {
                printf("\n Pilha vazia");
            }

            break;
        case 4:
            if (empty(l))
            {
                printf("\n Pilha vazia");
            }
            else
            {
                printf("\n Pilha com elementos");
            }

            break;
        case 5:
            printf("\n Saindo do programa");
            break;

        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 5);
}