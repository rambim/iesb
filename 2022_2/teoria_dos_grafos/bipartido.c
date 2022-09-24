#include <stdio.h>
#include <stdlib.h>


typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int cor;
}vertice;


void mostrar_tudo (vertice * vertices, int qtd_vertices);
int dfs(vertice * vertices, int qtd_vertices, int raiz, int cor);


int main()
{
    int qtd_vertices, qtd_arestas;
    int i,a,b,qtd_cc=0;
    vertice * vertices;
    scanf("%d %d",&qtd_vertices, &qtd_arestas);

    // printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // printf("\n Quantidade de arestas: %d\n",qtd_arestas);

    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    for(i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }

    // mostrar_tudo(vertices,qtd_vertices);


    if (dfs(vertices,qtd_vertices,1,1))
    {
        printf("\n Grafo bipartido");
    }
    else
    {
        printf("\n grafo nao bipartido");
    }

    return 0;
}


void mostrar_tudo (vertice * vertices, int qtd_vertices)
{
    int i,j;

    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Vertice: %d",i);
        printf("\n Lista de adjacencias: ");

        for(j=0;j<vertices[i].tam_lista_adj;j++)
        {
            printf("%d ",vertices[i].lista_adj[j]);
        }
    }
}

int dfs(vertice * vertices, int qtd_vertices, int raiz, int cor)
{
    int i;

    vertices[raiz].visitado=1;
    vertices[raiz].cor = cor; 

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0)
        {
            if(!dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i],cor * -1))
            {
                return 0;
            }
        }
        else
        {
            if (vertices[raiz].cor == vertices[vertices[raiz].lista_adj[i]].cor)
                return 0;
        }
    }
    return 1;
}