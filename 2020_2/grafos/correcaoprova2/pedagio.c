

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;

typedef struct registro_vertice
{
    int visitou;
    char vertice[10];
    struct lista_ligada *lista;

} registro_vertice;

typedef struct lista_ligada
{
    struct registro *inicio;
    int qtd;
} lista_ligada;

typedef struct registro
{
    char valor[10];
    struct registro *prox;
    int distancia;
} registro;

typedef struct fila
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} fila;

int constroi_dominio(char *c, registro_vertice *lista_adj, int *qtd);
void mostrar_lista_gera(registro_vertice *lista_adj, int tam);
lista_ligada *aloca_lista();
registro *aloca_registro();
void incluir_ordenado_lista(lista_ligada *l, char *texto);
void mostrar_lista(lista_ligada *l);
int busca_indice(char *texto);
void dfs(registro_vertice *r);
fila *aloca_fila();
void incluir_na_fila(char *vertice, int distancia);
registro remover_da_fila();
int empty();
char *my_itoa(int n);
void bfs(registro_vertice *r, int p);

registro_vertice lista_adj[100001];
int qtd_registros = 0;

fila *fila_execucao;

int main()
{
    fila_execucao = aloca_fila();

    int tamanho_dominio;
    char *a, *b;
    char linha[100];
    int i, ind_a, ind_b;

    for (i = 0; i < 100001; i++)
    {
        lista_adj[i].lista = NULL;
    }

    int c, e, l, p;
    int vet_a[100], vet_b[100];
    scanf("%d %d %d %d", &c, &e, &l, &p);
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &vet_a[i], &vet_b[i]);
    }

    for (i = 1; i <= c; i++)
    {
        a = my_itoa(i);
        constroi_dominio(a, lista_adj, &qtd_registros);
    }

    for (i = 0; i < e; i++)
    {
        a = my_itoa(vet_a[i]);
        b = my_itoa(vet_b[i]);

        incluir_ordenado_lista(lista_adj[vet_a[i] - 1].lista, b);
        incluir_ordenado_lista(lista_adj[vet_b[i] - 1].lista, a);
    }

    // mostrar_lista_gera(lista_adj,qtd_registros);
    bfs(&lista_adj[l - 1], p);

    printf("\n");

    return 0;
}

char *my_itoa(int n)
{
    char *s;
    s = (char *)malloc(sizeof(char) * 20);
    if (s == NULL)
    {
        return NULL;
    }

    sprintf(s, "%d", n);
    return s;
}

fila *aloca_fila()
{
    fila *novo;
    novo = (fila *)malloc(sizeof(fila));
    novo->inicio = NULL;
    novo->fim = NULL;
    novo->qtd = 0;
    return novo;
}

void incluir_na_fila(char *vertice, int distancia)
{
    registro *novo;
    novo = aloca_registro();
    strcpy(novo->valor, vertice);
    novo->distancia = distancia;

    if (fila_execucao->inicio == NULL && fila_execucao->fim == NULL)
    {
        fila_execucao->inicio = novo;
        fila_execucao->fim = novo;
    }
    else
    {
        fila_execucao->fim->prox = novo;
        fila_execucao->fim = novo;
    }
    fila_execucao->qtd++;
}

registro remover_da_fila()
{
    registro aux;
    aux = *(fila_execucao->inicio);
    free(fila_execucao->inicio);

    fila_execucao->inicio = aux.prox;
    if (fila_execucao->inicio == NULL)
    {
        fila_execucao->fim = NULL;
    }
    fila_execucao->qtd--;

    return aux;
}

int empty()
{
    if (fila_execucao->inicio == NULL && fila_execucao->fim == NULL)
        return 1;
    else
        return 0;
}

void bfs(registro_vertice *r, int p)
{
    int indice;
    registro atual, *aux;
    indice = busca_indice(r->vertice);
    lista_adj[indice].visitou = 1;
    incluir_na_fila(lista_adj[indice].vertice, 0);

    while (!empty())
    {
        atual = remover_da_fila();
        if (atual.distancia <= p)
        {
            if (atual.distancia > 0)
            {
                printf("\nVertice %s Distancia: %d", atual.valor, atual.distancia);
            }
        }
        else
        {
            return;
        }
        
        indice = busca_indice(atual.valor);

        aux = lista_adj[indice].lista->inicio;

        while (aux != NULL)
        {
            indice = busca_indice(aux->valor);

            if (lista_adj[indice].visitou == 0)
            {
                lista_adj[indice].visitou = 1;
                incluir_na_fila(lista_adj[indice].vertice, atual.distancia + 1);
            }
            aux = aux->prox;
        }
    }
}

//retornar o indice do procurado no vetor;
int constroi_dominio(char *c, registro_vertice *lista_adj, int *qtd)
{
    int i;

    for (i = 0; i < *qtd; i++)
    {
        if (strcmp(lista_adj[i].vertice, c) == 0)
        {
            return i;
        }
    }

    strcpy(lista_adj[*qtd].vertice, c);
    lista_adj[*qtd].visitou = 0;
    lista_adj[*qtd].lista = aloca_lista();
    (*qtd)++;
    return (*qtd) - 1;
}

void mostrar_lista_gera(registro_vertice *lista_adj, int tam)
{
    int i;
    printf("\n Quantidade de Vertices: %d", tam);
    for (i = 0; i < tam; i++)
    {
        printf("\n\n Vertice = %s ", lista_adj[i].vertice);
        printf("\n Mostrando adjacencias de %s: ", lista_adj[i].vertice);
        mostrar_lista(lista_adj[i].lista);
    }
}

lista_ligada *aloca_lista()
{
    lista_ligada *novo;
    novo = (lista_ligada *)malloc(sizeof(lista_ligada));
    novo->inicio = NULL;
    novo->qtd = 0;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->prox = NULL;
    strcpy(novo->valor, "\0");
    return novo;
}

void incluir_ordenado_lista(lista_ligada *l, char *texto)
{
    registro *novo;
    novo = aloca_registro();
    strcpy(novo->valor, texto);
    registro *aux = NULL, *ant = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL && (strcmp(aux->valor, texto) < 0))
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux != NULL)
        {
            if (strcmp(aux->valor, texto) == 0)
            {
                return;
            }
        }
        if (ant == NULL)
        {
            l->inicio = novo;
        }
        else
        {
            ant->prox = novo;
        }

        novo->prox = aux;
    }

    l->qtd++;
}

void mostrar_lista(lista_ligada *l)
{
    registro *aux;
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }
    aux = l->inicio;
    while (aux != NULL)
    {
        printf("\n %s", aux->valor);
        aux = aux->prox;
    }
}

int busca_indice(char *texto)
{

    int i;
    for (i = 0; i < qtd_registros; i++)
    {
        if (strcmp(lista_adj[i].vertice, texto) == 0)
        {
            return i;
        }
    }
    return -1;
}

void dfs(registro_vertice *r)
{
    registro *aux;
    int indice, indice_prox;
    indice = busca_indice(r->vertice);
    lista_adj[indice].visitou = 1;
    printf(" -> %s\n", lista_adj[indice].vertice);

    if (lista_adj[indice].lista == NULL)
    {
        return;
    }

    aux = lista_adj[indice].lista->inicio;

    while (aux != NULL)
    {
        indice_prox = busca_indice(aux->valor);

        if (lista_adj[indice_prox].visitou == 0)
        {
            dfs(&lista_adj[indice_prox]);
        }
        aux = aux->prox;
    }
}
