#include <stdio.h>
#include <stdlib.h>

int qtd_global[10001];


typedef struct vertice
{
    int visitado;
    int distancia;
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
int carrega_grafo(vertice *vertices, char *nome_do_arquivo);
void push(vertice *v, int x);
void mostrar_lista_dos_vertices(vertice *v, int tam);
void dfs(vertice * vertices , int x, int distancia);
void reseta_visitados(vertice * vertices, int qtd_vertices);

int main(int *argc, char *argv[])
{
    vertice *vertices;
    int i,qtd_vertices,qtd_arestas,a,b,qtd_consultas;
    int * vet;
    // printf(" Parametro recebido: %s", argv[1]);
    scanf("%d",&qtd_vertices);
    scanf("%d",&qtd_arestas);
    

    vertices = (vertice *)calloc(qtd_vertices+1, sizeof(vertice));

    i = 0;

    while(i<qtd_arestas)
    {
        scanf("%d %d",&a,&b);
        push(&vertices[a],b);
        push(&vertices[b],a);
        i++;
    }

    scanf("%d",&qtd_consultas);

    vet = (int*)calloc(qtd_consultas,sizeof(int));

    i = 0;

    while(i<qtd_consultas)
    {
        reseta_visitados(vertices,qtd_vertices);
        scanf("%d %d",&a,&b);


        dfs(vertices,a,0);
        vet[i] = vertices[b].distancia;
        i++;
    }

    for(i=0;i<qtd_consultas;i++)
    {
        printf("%d\n",vet[i]);
    }


  
    printf("\n");
    return 0;
}

void reseta_visitados(vertice * vertices, int qtd_vertices)
{

    int i;
    for(i=1;i<=qtd_vertices;i++)
    {
        vertices[i].visitado=0;
    }
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
    // printf(" %d",x);

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


