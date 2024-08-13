#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    struct lista_adj * lista;
}vertice;

typedef struct lista_adj
{
    
    struct registro * inicio;
    struct registro * final;
}lista_adj;

typedef struct registro{
    int valor;
    struct registro * prox;
}registro;


lista_adj * aloca_lista();
registro * aloca_registro();
void mostrar_lista(lista_adj * l);
void incluir_final(lista_adj * l, int x);
int main()
{

    int qtd_vertices, qtd_arestas;
    
    vertice * vertices;

    scanf("%d %d",&qtd_vertices, &qtd_arestas);

    vertices  = (vertice*)calloc(sizeof(vertice),qtd_vertices+1);

    vertices[2].lista = aloca_lista();

    incluir_final(vertices[1].lista,1);
    incluir_final(vertices[1].lista,2);
    incluir_final(vertices[1].lista,3);

    mostrar_lista(vertices[2].lista);





    return 0;
}

lista_adj * aloca_lista()
{
    lista_adj * novo = (lista_adj*)calloc(sizeof(lista_adj), 1);
    return novo;
}

registro * aloca_registro()
{
    registro * novo = (registro*)calloc(sizeof(registro),1);
    return novo;
}

void incluir_final(lista_adj * l, int x)
{
    if (l==NULL)
    {
        printf("\n Lista Nula");
        return;
    }

    registro * novo;

    novo = aloca_registro();
    novo->valor = x;
    novo->prox=NULL;

    if (l->inicio==NULL)
    {
        l->inicio = novo;
        l->final = novo;
    }
    else
    {
        l->final->prox = novo;
        l->final = novo;
    }
}

void mostrar_lista(lista_adj * l)
{
    
    registro * aux;
    if (l==NULL)
    {
        printf("\n Lista NULA");
    }

    if (l->inicio==NULL)
    {
        printf("\n Lista vazia");
    }


    aux = l->inicio;

    while(aux!=NULL)
    {
        printf("%d ",aux->valor);
        aux=aux->prox;
    }


    


}




