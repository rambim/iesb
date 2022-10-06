// https://www.spoj.com/problems/BUGLIFE/
// Exercício A Bug’s Life

#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[3000];
    int tam_lista_adj;
    int cor;
} vertice;

void mostrar_tudo(vertice *vertices, int qtd_vertices);
int dfs(vertice *vertices, int qtd_vertices, int raiz, int cor);

int main()
{
    int qtd_vertices, qtd_arestas;
    int i, a, b, qtd_cc = 0;
    int qtd_casos = 0, d;
    vertice *vertices;

    // printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // printf("\n Quantidade de arestas: %d\n",qtd_arestas);

    scanf("%d", &qtd_casos);
    d = qtd_casos;

    while (d--)
    {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertices = (vertice *)calloc(3000 + 1, sizeof(vertice));

        for (i = 0; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);
            vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
            vertices[a].tam_lista_adj++;
            vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
            vertices[b].tam_lista_adj++;
        }

        // mostrar_tudo(vertices,qtd_vertices);
        int flag=0;

        printf("Scenario #%d:\n", qtd_casos - d);

        for (int i = 1; i <= qtd_vertices; i++)
        {
            if (vertices[i].visitado == 0)
            {
                if (!dfs(vertices, qtd_vertices, i, 1))
                {
                    flag = 1;
                }
            }
        }

        if (flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");

            

        free(vertices);
    }
    return 0;
}

int dfs(vertice *vertices, int qtd_vertices, int raiz, int cor)
{
    int i;

    vertices[raiz].visitado = 1;
    vertices[raiz].cor = cor;

    for (i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado == 0)
        {
            if (!dfs(vertices, qtd_vertices, vertices[raiz].lista_adj[i], cor * -1))
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