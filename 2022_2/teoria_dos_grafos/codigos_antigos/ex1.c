#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int valor;
    struct lista *lista_adj;
} vertice;

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

void mostrar_lista(lista *l);
int incluir_ordenado_lista(lista *l, int x);
registro *aloca_registro();
lista *aloca_lista();

int main()
{
    vertice *vertices;
    int qtd_vertices;
    int opcao;
    int a,b;
    int i;

    printf("\nDigite a quantidade de vertices: ");
    scanf("%d", &qtd_vertices);

    vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

    do
    {
        printf("\n 1 - incluir aresta");
        printf("\n 2 - mostrar grafo");
        printf("\n 5 - Sair");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            a=0;
            b=0;
            printf("\nDigite o primeiro vertice: ");
            scanf("%d",&a);
            printf("\nDigite o segundo vertice: ");
            scanf("%d",&b);

            if (vertices[a].lista_adj == NULL)
                vertices[a].lista_adj = aloca_lista();
            incluir_ordenado_lista(vertices[a].lista_adj,b);

            if (vertices[b].lista_adj == NULL)
                vertices[b].lista_adj = aloca_lista();
            incluir_ordenado_lista(vertices[b].lista_adj,a);
            break;
        case 2:
            for(i=1;i<=qtd_vertices;i++)
            {
                printf("\n\nVertice %d ",i);
                mostrar_lista(vertices[i].lista_adj);

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

    printf("\n");
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

int incluir_ordenado_lista(lista *l, int x)
{
    if (l == NULL)
        return 0;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        int inserido = 0;
        aux = l->inicio;
        while (aux != NULL && !inserido)
        {

            if (aux->valor == novo->valor)
            {
                return 0;
            }

            if (aux->valor < novo->valor)
            {
                ant = aux;
                aux = aux->prox;
            }
            else
            {
                if (ant == NULL)
                    l->inicio = novo;
                else
                    ant->prox = novo;

                novo->prox = aux;
                inserido = 1;
            }
        }
        if (!inserido)
        {
            ant->prox = novo;
            inserido = 1;
        }
    }
    l->qtd++;
    return 1;
}

void mostrar_lista(lista *l)
{
    registro *aux;

    if (l == NULL)
    {
        printf("\n Lista nula");
        return;
    }

    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    aux = l->inicio;
    while (aux != NULL)
    {
        printf("\n -> %d", aux->valor);
        aux = aux->prox;
    }
}
