#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;
}vertice;

int count;


void mostrar_tudo (vertice * vertices, int qtd_vertices);

int menor(int a, int b) ;
void dfs2(vertice * vertices, int qtd_vertices, int raiz, int pai);

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

    mostrar_tudo(vertices,qtd_vertices);

    dfs2(vertices,qtd_vertices,1,1);

    // for(i=1;i<=qtd_vertices;i++)
    // {
    //     if (vertices[i].visitado==0)
    //     {
    //         dfs(vertices,qtd_vertices,i);
    //         qtd_cc++;
    //     }
    // }

    // printf("\n%d",qtd_cc);

    // dfs(vertices,qtd_vertices,1);

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


void dfs2(vertice * vertices, int qtd_vertices, int raiz, int pai)
{
    int i,filho;

    vertices[raiz].visitado = 1;
    vertices[raiz].in = count;
    vertices[raiz].lower = count;
    count++;

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        filho = vertices[raiz].lista_adj[i];
        if (filho == pai)
        {
            continue;
        }
        else
        {
            if (vertices[filho].visitado == 1)
            {
                //back edge
                vertices[raiz].lower = menor(vertices[raiz].lower,vertices[filho].in);
            }
            else
            {
                //forward edge
                dfs2(vertices,qtd_vertices,filho,raiz);

                if (vertices[filho].lower > vertices[raiz].in)
                {
                    printf("\n Ponte entre %d e %d ", raiz, filho);
                }

                vertices[raiz].lower = menor(vertices[raiz].lower, vertices[filho].lower);
            }
        }
    }

}


int menor(int a, int b) { return a<b ? a : b;}


