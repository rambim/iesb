#include <stdio.h>
#include <stdlib.h>

int qtd_global[10001];

typedef struct vertice
{
    int visitado;
    int distancia;
    struct lista *lista_adj;
} vertice;

typedef struct lista_duplamente_ligada
{
    struct registro * inicio;
    struct registro * fim;
}lista_duplamente_ligada;

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
int carrega_grafo(vertice *vertices, char *nome_do_arquivo);
void push(vertice *v, int x);
void mostrar_lista_dos_vertices(vertice *v, int tam);
void dfs(vertice * vertices , int x, int distancia);
int pop_fila(lista_duplamente_ligada * fila);
void push_fila(lista_duplamente_ligada * fila, int x);
lista_duplamente_ligada * aloca_lista_duplamente_ligada();
void bfs(vertice * vertices, int root);
int empty(lista_duplamente_ligada * fila);

int main(int *argc, char *argv[])
{
    vertice *vertices;
    int qtd_vertices,i;
    printf(" Parametro recebido: %s", argv[1]);
    vertices = (vertice *)calloc(10000, sizeof(vertice));
    qtd_vertices = carrega_grafo(vertices, argv[1]);
    if (qtd_vertices)
    {
        printf("\n Grafo carregado com sucesso qtd vertices: %d",qtd_vertices);
        // mostrar_lista_dos_vertices(vertices, 10001);
    }
    else
        printf("\n Problema no carregamento do grafo");

    
    bfs(vertices,5);


    printf("\n");
    return 0;
}

void bfs(vertice * vertices, int root)
{
    lista_duplamente_ligada * fila;
    registro * aux;
    fila = aloca_lista_duplamente_ligada();
    int retorno;

    push_fila(fila,root);

    while(!empty(fila))
    {
        retorno = pop_fila(fila);

        if (vertices[retorno].visitado==0)
        {
            printf("\n -> %d",retorno);
            vertices[retorno].visitado=1;

            aux = vertices[retorno].lista_adj->inicio;
            while(aux!=NULL)
            {
                push_fila(fila,aux->valor);
                aux = aux->prox;
            }

        }
    }

}

int empty(lista_duplamente_ligada * fila)
{
    if (fila==NULL)
        return 1;
    if (fila->inicio==NULL)
        return 1;
    return 0;
}


int carrega_grafo(vertice *vertices, char *nome_do_arquivo)
{
    FILE *arq;
    arq = fopen(nome_do_arquivo, "r");
    int a, b;
    int qtd_vertices=0;

    int i;

    for(i=0;i<10001;i++)
    {
        qtd_global[i] =0;
    }

    if (arq == NULL)
    {
        printf("\n Arquivo nao localizado");
        return 0;
    }

    while (fscanf(arq, "%d;%d\n", &a, &b) != EOF)
    {
        printf("\n A: %d B: %d", a, b);

        if (qtd_global[a]==0)
            qtd_vertices++;
            qtd_global[a] = 1;

        if (qtd_global[b]==0)
            qtd_vertices++;
            qtd_global[b] = 1;

        push(&vertices[a], b);
        push(&vertices[b], a);
    }

    return qtd_vertices;
}

void push(vertice *v, int x)
{
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_lista();
    incluir_ordenado_lista(v->lista_adj, x);
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

lista_duplamente_ligada * aloca_lista_duplamente_ligada()
{
    lista_duplamente_ligada * novo;
    novo = (lista_duplamente_ligada*)calloc(1,sizeof(lista_duplamente_ligada));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void push_fila(lista_duplamente_ligada * fila, int x)
{   
    if (fila==NULL)
        return;
    
    registro * novo;
    novo = aloca_registro();
    novo->valor = x;

    if (fila->inicio==NULL)
    {
        fila->inicio = novo;
        fila->fim=novo;
    }
    else
    {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int pop_fila(lista_duplamente_ligada * fila)
{
    int retorno;
    registro * aux;
    if (fila==NULL)
        return 0;
    
    if (fila->inicio==NULL)
        return 0;

    aux = fila->inicio;
    retorno = aux->valor;
    fila->inicio = aux->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(aux);
    return retorno;
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

void mostrar_lista_dos_vertices(vertice *v, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (v[i].lista_adj != NULL)
        {
            printf("\n Lista de Adjacencias do no : %d", i);
            mostrar_lista(v[i].lista_adj);
        }
    }
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


void dfs(vertice * vertices , int x, int distancia)
{
    
    registro * aux;
    vertices[x].visitado=1;
    vertices[x].distancia = distancia;
    printf(" %d",x);

    if (vertices[x].lista_adj==NULL)
        return;
        
    aux = vertices[x].lista_adj->inicio;

    while(aux!=NULL)
    {
        if (vertices[aux->valor].visitado==0)
        {
            dfs(vertices,aux->valor,distancia+1); 
        }
        aux = aux->prox;
    }

}