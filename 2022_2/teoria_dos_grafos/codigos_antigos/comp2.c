#include <stdlib.h>
#include <stdio.h>

typedef struct vertice{
    int visitado;
    int minimaDistancia;
    struct lista *lista_adj;
} vertice;

typedef struct registro{
    int valor;
    struct registro *prox;
} registro;

typedef struct lista{
    int qtd;
    struct registro *inicio;
} lista;

lista *aloca_lista();
registro *aloca_registro();
void push(vertice *vertice, int valor);
void incluir_na_lista(lista *lista, int valor);
void excluirDistanciaVertices(vertice *vertices);
void dfs(vertice *vertices, int x, int distancia);

int main(){

    vertice *vertices;
    int Q = 0, V = 0, C = 0, minimaDistancia = 0, i = 0, j = 0, a = 0, b = 0, c = 0, d = 0;
    
    scanf("%d", &Q);
    scanf("%d", &V);

    vertices = (vertice *)calloc(1001, sizeof(vertice));

    for(i = 0; i < V; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        
        push(&vertices[a], b);
        push(&vertices[b], a);
    }

    scanf("%d", &C);
    for(j=0; j < C; j++){
        scanf("%d", &c);
        scanf("%d", &d);
        
        dfs(vertices, c, 0);
        printf("%d\n", vertices[d].minimaDistancia);
        
        excluirDistanciaVertices(vertices);
    }

    return 0;
}

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    
    return novo;  
}

registro *aloca_registro(){
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));

    return novo;
}


void excluirDistanciaVertices(vertice *vertices){
	int i = 0;
	for(i = 0; i < 1001; i++){
		vertices[i].visitado = 0;
	}
}

void push(vertice *vertice, int valor){
    if(vertice->lista_adj == NULL){
        vertice->lista_adj = aloca_lista();
    }

    incluir_na_lista(vertice->lista_adj, valor);
}

void incluir_na_lista(lista *lista, int valor){
    if(lista == NULL){
        return;
    }

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else {
        aux = lista->inicio;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = novo;
    }
    
    lista->qtd++;
}

void dfs(vertice *vertices, int x, int minimaDistancia){
    registro *aux;
    vertices[x].visitado = 1;
    vertices[x].minimaDistancia = minimaDistancia;

    if(vertices[x].lista_adj == NULL){
        return;
    }

    aux = vertices[x].lista_adj->inicio;
    while(aux != NULL){
        if(vertices[aux->valor].visitado == 0){
            dfs(vertices, aux->valor, minimaDistancia+1);
        }

        aux = aux->prox;
    }
}