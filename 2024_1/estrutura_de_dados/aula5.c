#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

registro *cria_registro();
lista *cria_lista();
void inserir_no_inicio(lista *l, int valor);
void inserir_no_final(lista *l, int valor);
void mostrar_lista(lista *l, int opcao);
void remover(lista * l, int valor);

lista *cria_lista()
{
    return (lista *)calloc(1, sizeof(lista));
}

registro *cria_registro()
{
    return (registro *)calloc(1, sizeof(registro));
}

int main()
{
    lista * l;
    l = cria_lista();

    inserir_no_inicio(l,3);
    inserir_no_inicio(l,2);
    inserir_no_inicio(l,1);

    mostrar_lista(l,1);

    printf("\n");
    inserir_no_final(l,4);
    inserir_no_final(l,5);
    inserir_no_final(l,6);

    mostrar_lista(l,2);

    printf("\n");
    remover(l,10);
    printf("\n");
    remover(l,3);
    mostrar_lista(l,1);
    printf("\n");
    remover(l,1);
    mostrar_lista(l,1);
    printf("\n");
    remover(l,6);
    mostrar_lista(l,1);

    printf("\n");
    remover(l,2);
    remover(l,4);
    remover(l,5);
    mostrar_lista(l,1);

    return 0;
}

void inserir_no_final(lista *l, int valor)
{
    registro *novo;
    novo = cria_registro();
    novo->valor = valor;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->qtd++;
}

void inserir_no_inicio(lista *l, int valor)
{
    registro *novo;
    novo = cria_registro();
    novo->valor = valor;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->inicio->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }

    l->qtd++;
}

void mostrar_lista(lista *l, int opcao)
{
    if (l->inicio == NULL && l->fim == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        registro *aux;

        if (opcao != 1 && opcao != 2)
        {
            printf("opcao invalida\n");
        }
        else
        {
            if (opcao == 1)
            {
                aux = l->inicio;

                while (aux != NULL)
                {
                    printf(" %d", aux->valor);
                    aux = aux->prox;
                }
            }
            else
            {
                aux = l->fim;

                while (aux != NULL)
                {
                    printf(" %d", aux->valor);
                    aux = aux->ant;
                }
            }
        }
    }
}


void remover(lista * l, int valor)
{
    if (l->inicio==NULL && l->fim == NULL)
    {
        printf("Elemento nao encontrado na lista");
        return ;
    }
    else
    {
        registro * aux;

        aux = l->inicio;

        while(aux!=NULL)
        {
            if (aux->valor == valor)
            {
                if ( aux->ant == NULL)
                {
                    l->inicio = aux->prox;
                }
                else
                {
                    aux->ant->prox = aux->prox;
                }


                if (aux->prox == NULL)
                {
                    l->fim = aux->ant;
                }
                else
                {
                    aux->prox->ant = aux->ant;
                }
                l->qtd--;
                printf("%d removido\n",aux->valor);
                free(aux);
                return;
            }           
            aux = aux->prox;
        }

        printf("Elemento nao encontrado\n");

    }

}