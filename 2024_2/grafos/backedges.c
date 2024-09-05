#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    struct lista *adj;
    int visitado;
} vertice;

typedef struct lista
{
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

typedef struct aresta
{
    int a, b;
} aresta;

lista *aloca_lista();
registro *aloca_registro();
void mostrar_lista(lista *l);
void incluir_vertice_lista_adjacencia(vertice *v, int valor);
void dfs(int raiz, vertice *vertices, int par);
int compara_arestas(aresta a, aresta b);
void adicionar_aresta(int a, int b);

aresta *arestas;
int qtd_back_edges = 0;
int main()
{

    int qtd_vertices, qtd_arestas, i, a, b;

    vertice *vertices;

    aresta nova_aresta;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    arestas = (aresta *)calloc(sizeof(aresta), 10000);

    vertices = (vertice *)calloc(sizeof(vertice), qtd_vertices + 1);

    for (i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);
        incluir_vertice_lista_adjacencia(&vertices[a], b);
        incluir_vertice_lista_adjacencia(&vertices[b], a);
    }

    // printf("Lista da Adjacencia: \n");
    // for (i = 1; i <= qtd_vertices; i++)
    // {
    //     printf("Vertice: %d -> ", i);
    //     mostrar_lista(vertices[i].adj);
    //     printf("\n");
    // }

    dfs(1, vertices, 1);

    printf("BackEdges: \n");
    for (i = 0; i < qtd_back_edges; i++)
    {
        printf("%d - %d\n",arestas[i].a,arestas[i].b);
    }

    return 0;
}

void adicionar_aresta(int a, int b)
{
    int i;
    aresta nova_aresta;

    nova_aresta.a = a;
    nova_aresta.b = b;

    for (i = 0; i < qtd_back_edges; i++)
    {
        if (compara_arestas(arestas[i], nova_aresta))
            return;
    }

    arestas[qtd_back_edges] = nova_aresta;
    qtd_back_edges = qtd_back_edges + 1;
}

int compara_arestas(aresta a, aresta b)
{
    if ((a.a == b.a && a.b == b.b) || (a.a == b.b && a.b == b.a))
    {
        return 1;
    }
    return 0;
}

void dfs(int raiz, vertice *vertices, int par)
{
    vertices[raiz].visitado = 1;
    aresta nova_aresta;

    registro *aux;
    if (vertices[raiz].adj != NULL)
    {
        aux = vertices[raiz].adj->inicio;

        while (aux != NULL)
        {
            if (vertices[aux->valor].visitado == 0)
            {
                dfs(aux->valor, vertices, raiz);
            }
            else
            {
                if (aux->valor != par)
                {
                    adicionar_aresta(aux->valor , raiz);
                }
            }
            aux = aux->prox;
        }
    }
}

void incluir_vertice_lista_adjacencia(vertice *v, int valor)
{
    if (v->adj == NULL)
    {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL)
    {
        v->adj->inicio = novo;
        v->adj->final = novo;
    }
    else
    {
        v->adj->final->prox = novo;
        v->adj->final = novo;
    }
}

lista *aloca_lista()
{
    lista *novo = (lista *)calloc(sizeof(lista), 1);
    return novo;
}

registro *aloca_registro()
{
    registro *novo = (registro *)calloc(sizeof(registro), 1);
    return novo;
}

void mostrar_lista(lista *l)
{

    registro *aux;
    if (l == NULL)
    {
        return;
    }

    if (l->inicio == NULL)
    {
        return;
    }

    aux = l->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}
