#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int distancia;
}vertice;


void mostrar_tudo (vertice * vertices, int qtd_vertices);
void dfs(vertice * vertices, int qtd_vertices, int raiz,int distancia);

int main()
{
    int qtd_vertices, qtd_arestas;
    int i,a,b,qtd_cc=0;
    vertice * vertices;
    scanf("%d",&qtd_vertices);
    int garotas[1000];
    int qtd_garotas;

    // printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // printf("\n Quantidade de arestas: %d\n",qtd_arestas);

    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    for(i=0;i<qtd_vertices-1;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }

    dfs(vertices,qtd_vertices,1,0);

    scanf("%d",&qtd_garotas);

    for(int i=0;i<qtd_garotas;i++)
    {
        scanf("%d",&garotas[i]);
    }

    int id_escolhida=garotas[0];
    for(int i=1;i<qtd_garotas;i++)
    {
        if (vertices[garotas[i]].distancia < vertices[id_escolhida].distancia)
        {
            id_escolhida = garotas[i];
        }
        else
        {
            if (vertices[garotas[i]].distancia == vertices[id_escolhida].distancia)
            {
                if (garotas[i] < id_escolhida)
                {
                    id_escolhida = garotas[i];
                }
            }
        }
    }

    printf("\n Id escolhida: %d",id_escolhida);



    // mostrar_tudo(vertices,qtd_vertices);

    // for(i=1;i<=qtd_vertices;i++)
    // {
    //     printf("\n Distancia até %d = %d",i,vertices[i].distancia);
    // }

    // printf("\n%d",qtd_cc);


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

void dfs(vertice * vertices, int qtd_vertices, int raiz,int distancia)
{
    int i;
    if (vertices[raiz].visitado!=0)
    {
        return;
    }

    // printf("\n %d",raiz);
    vertices[raiz].visitado=1;
    vertices[raiz].distancia = distancia;

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0)
        {
            dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i],distancia+1);
        }
    }
}