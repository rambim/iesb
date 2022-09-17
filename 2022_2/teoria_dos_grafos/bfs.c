#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int tam;
    struct elemento *primeiro;
    struct elemento *ultimo;
} fila;

typedef struct elemento
{
    int valor;
    struct elemento *prox;
} elemento;

typedef struct vertice
{
    int visitado;
    int distancia;
    int lista_adj[1000];
    int tam_lista_adj;
} vertice;

int is_empty(fila *f);
void insert_queue(fila *f, int x);
int pop_queue(fila *f);
void bfs(vertice *vertices, int raiz);

int main()
{
    int qtd_vertices, qtd_arestas;
    int i, a, b, qtd_cc = 0;
    int raiz;
    vertice *vertices;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    // printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // printf("\n Quantidade de arestas: %d\n",qtd_arestas);

    vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

    for (i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }

    printf("\n Digite a raiz desejada: ");
    scanf("%d", &raiz);

    bfs(vertices, raiz);

    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Distancia do vertice %d para a raiz %d = %d",i,raiz,vertices[i].distancia);
    }

    return 0;
}

void insert_queue(fila *f, int x)
{
    elemento *novo;
    novo = (elemento *)calloc(1, sizeof(elemento));
    novo->valor = x;

    if (f->tam == 0)
    {
        f->primeiro = novo;
        f->ultimo = novo;
    }
    else
    {
        f->ultimo->prox = novo;
        f->ultimo = novo;
    }
    f->tam++;
}

int pop_queue(fila *f)
{
    if (is_empty(f))
    {
        return -1;
    }
    else
    {
        int retorno;
        retorno = f->primeiro->valor;
        f->primeiro = f->primeiro->prox;
        f->tam--;
        return retorno;
    }
}

int is_empty(fila *f)
{
    if (f->tam == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mostrar_tudo(vertice *vertices, int qtd_vertices)
{
    int i, j;

    for (i = 1; i <= qtd_vertices; i++)
    {
        printf("\n Vertice: %d", i);
        printf("\n Lista de adjacencias: ");

        for (j = 0; j < vertices[i].tam_lista_adj; j++)
        {
            printf("%d ", vertices[i].lista_adj[j]);
        }
    }
}

void bfs(vertice *vertices, int raiz)
{
    fila *f;
    f = calloc(1, sizeof(fila));
    int current;
    int i, filho;

    insert_queue(f, raiz);

    while (!is_empty(f))
    {
        current = pop_queue(f);
        vertices[current].visitado = 1;
        for (i = 0; i < vertices[current].tam_lista_adj; i++)
        {
            filho = vertices[current].lista_adj[i];
            if (vertices[filho].visitado == 0)
            {
                vertices[filho].distancia = vertices[current].distancia + 1;
                insert_queue(f, filho);
            }
        }
    }
}
