/*

Gabriel Salmai Camargo Farias - 1922130017

*/
/*
Entrada
6
5
1;2
1;3
1;4
3;5
3;6
3
1;5
5;2
4;2

Saida 
2
3
2
*/

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

int incluir_ordenado_lista(lista *l, int x);
registro *aloca_registro();
lista *aloca_lista();
void push(vertice *v, int x);
void dfs(vertice * vertices , int x, int distancia);
void reset_dfs(vertice * vertices , int x);


int main(int *argc, char *argv[])
{
    vertice *vertices;
    int qtd_vertices, qtd_arestas,i, i2, a, b, c;
    vertices = (vertice *)calloc(10000, sizeof(vertice));


    printf("\nDigite a quantidade de vertices: ");
    scanf("%i", &qtd_vertices);

    printf("\nDigite a quantidade de arestas: ");
    scanf("%i", &qtd_arestas);

    for(i=0;i<qtd_arestas;i++){
        printf("\nDigite a %i aresta: ", i+1);
        scanf("%i %i", &a, &b);
        push(&vertices[a], b);
        push(&vertices[b], a);
    }


    printf("\nDigite a quantidade de consultas: ");
    scanf("%i", &c);
    int saida[c], i3 = 0;

    for(i2=0;i2<c;i2++){
        printf("\nDigite a %i consulta: (Exemplo: Va Vb) \n- ", i2+1);
        scanf("%i %i", &a, &b);
        dfs(vertices, a, 0);

        for(i=1;i<=qtd_vertices;i++)
        {
            if (i == b)
            {
                saida[i3]= vertices[i].distancia;
                i3++;
            }        
        }
        reset_dfs(vertices, a);
    }

    printf("\nSaida:");
    for(i2=0;i2<c;i2++){
        printf("\n%i", saida[i2]);
    }

    printf("\n");
    return 0;
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

void dfs(vertice * vertices , int x, int distancia)
{
    registro * aux;
    vertices[x].visitado=1;
    vertices[x].distancia = distancia;

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

void reset_dfs(vertice * vertices , int x)
{
    registro * aux;
    vertices[x].visitado=0;

    if (vertices[x].lista_adj==NULL)
        return;
        
    aux = vertices[x].lista_adj->inicio;

    while(aux!=NULL)
    {
        if (vertices[aux->valor].visitado==1)
        {
            reset_dfs(vertices,aux->valor); 
        }
        aux = aux->prox;
    }
}