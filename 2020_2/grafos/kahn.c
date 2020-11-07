#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;

typedef struct registro_vertice
{
    int visitou;
    int distancia;
    char vertice[10];
    int qtd_ligados;
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
void incluir_ordenado_lista(lista_ligada *l, char *texto, char *vertice);
void mostrar_lista(lista_ligada *l);
int busca_indice(char *texto);
void dfs(registro_vertice *r);
void kahns();
int todos_visitados();

registro_vertice lista_adj[100001];
int qtd_registros = 0;

int todos_visitados()
{
    int i;
    for(i=0;i<qtd_registros;i++)
    {
        if (lista_adj[i].visitou==0)
        {
            return 0;
        }
    }
    return 1;
}

void kahns()
{
    
    int i,ind_aux,erro=0;
    registro * aux;
    while(!todos_visitados() && !erro)
    {
        erro=1;
        for(i=0;i<qtd_registros;i++)
        {
            if (lista_adj[i].visitou==0 && lista_adj[i].qtd_ligados==0)
            {
                erro=0;
                printf("%s ",lista_adj[i].vertice);
                lista_adj[i].visitou=1;

                aux = lista_adj[i].lista->inicio;

                while(aux!=NULL)
                {
                    ind_aux = busca_indice(aux->valor);
                    lista_adj[ind_aux].qtd_ligados--;
                    aux = aux->prox;
                }

            }
        }
    }
}

int main()
{
    
    arq = fopen("grafo1.txt", "r");
    int tamanho_dominio;
    char a[50], b[50];
    char linha[100];
    int i, ind_a, ind_b;

    for (i = 0; i < 100001; i++)
    {
        lista_adj[i].lista = NULL;
    }

    if (arq == NULL)
    {
        printf("\n Problema para ler arquivo");
        return 0;
    }

    while (!feof(arq))
    {
        if (fgets(linha, 100, arq))
        {
            if (linha[strlen(linha) - 1] == '\n')
            {
                linha[strlen(linha) - 1] = '\0';
            }

            printf("%s\n", linha);

            for (i = 0; i < strlen(linha); i++)
            {
                if (linha[i] == ';')
                {
                    break;
                }
                a[i] = linha[i];
            }

            a[i] = '\0';
            strcpy(b, &linha[i + 1]);

            ind_a = constroi_dominio(a, lista_adj, &qtd_registros);
            ind_b = constroi_dominio(b, lista_adj, &qtd_registros);
            incluir_ordenado_lista(lista_adj[ind_a].lista, b, lista_adj[ind_a].vertice);
            lista_adj[ind_b].qtd_ligados = lista_adj[ind_b].qtd_ligados + 1;

        }
    }

    // mostrar_lista_gera(lista_adj, qtd_registros);
    kahns();
    // dfs(&lista_adj[0]);
    printf("\n");

    return 0;
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
    lista_adj[*qtd].distancia = 0;
    lista_adj[*qtd].lista = aloca_lista();
    lista_adj[*qtd].qtd_ligados = 0;

    (*qtd)++;
    return (*qtd) - 1;
}

void mostrar_lista_gera(registro_vertice *lista_adj, int tam)
{
    int i;
    printf("\n Quantidade de Vertices: %d", tam);
    for (i = 0; i < tam; i++)
    {
        printf("\n\n Vertice = %s Qtd Contectados = %d", lista_adj[i].vertice,lista_adj[i].qtd_ligados);
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

void incluir_ordenado_lista(lista_ligada *l, char *texto, char *vertice)
{
    registro *novo;
    novo = aloca_registro();
    strcpy(novo->valor, texto);
    registro *aux = NULL, *ant = NULL;

    if (strcmp(texto, vertice) == 0)
    {
        return;
    }

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
