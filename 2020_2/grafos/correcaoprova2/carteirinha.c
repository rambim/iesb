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
} registro;

int constroi_dominio(char *c, registro_vertice *lista_adj, int *qtd);
void mostrar_lista_gera(registro_vertice *lista_adj, int tam);
lista_ligada *aloca_lista();
registro *aloca_registro();
void incluir_ordenado_lista(lista_ligada *l, char *texto);
void mostrar_lista(lista_ligada *l);
int busca_indice(char *texto);
void dfs(registro_vertice *r);
char *my_itoa(int n);
void inicializa_visitados(registro_vertice * l, int qtd);

registro_vertice lista_adj[100001];
int qtd_registros = 0;

int main()
{
    int tamanho_dominio;
    char *a, *b;
    char linha[100];
    int i, ind_a, ind_b;
    int n;
    int vet[1000];

    for (i = 0; i < 100001; i++)
    {
        lista_adj[i].lista = NULL;
    }

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < n; i++)
    {
        a = my_itoa(i + 1);
        b = my_itoa(vet[i]);
        constroi_dominio(a, lista_adj, &qtd_registros);
        incluir_ordenado_lista(lista_adj[i].lista, b);
    }

    
    for (i = 0; i < n; i++)
    {
        inicializa_visitados(lista_adj,qtd_registros);
        dfs(&lista_adj[i]);
    }

 

    return 0;
}

void inicializa_visitados(registro_vertice * l, int qtd)
{
    int i;
    for(i=0;i<qtd;i++)
    {
        l[i].visitou=0;
    }
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

    // if (strcmp(texto, vertice) == 0)
    // {
    //     return;
    // }

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
    lista_adj[indice].visitou = lista_adj[indice].visitou + 1;

    if (lista_adj[indice].visitou == 2)
    {
        printf("%s ", lista_adj[indice].vertice);
        return;
    }

    if (lista_adj[indice].lista == NULL)
    {
        return;
    }

    aux = lista_adj[indice].lista->inicio;

    while (aux != NULL)
    {
        indice_prox = busca_indice(aux->valor);

        if (lista_adj[indice_prox].visitou < 2)
        {
            dfs(&lista_adj[indice_prox]);
        }
        aux = aux->prox;
    }
}
