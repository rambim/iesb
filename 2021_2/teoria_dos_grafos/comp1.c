#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int dist;
    int vis;
    
    struct lista *lista_adjacentes;
} vertice;

typedef struct registro{
    int val;
    struct reg *proximo;
} registro;

typedef struct lista{
    int qtd;
    struct registro *inc;
} lista;

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    
    return novo;  
}

registro *alocar_reg(){
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));

    return novo;
}

void limpaVert(vertice *vertice){
    int i = 0;
    for(i=0; i < 1001; i++){
        vertice[i].vis = 0;
    }
}

void push(vertice *ver, int val){
    if(ver->lista_adjacentes == NULL){
        ver->lista_adjacentes = alocar_list();
    }

    inc_list(ver->lista_adjacentes, val);
}

void inclui_list(lista *lista, int val){
    if(lista == NULL){
        return;
    }

    registro *novo, *aux = NULL, *ant = NULL;
    novo = alocar_reg();
    novo->val = val;

    if(lista->inc == NULL){
        lista->inc = novo;
    }else {
        aux = lista->inc;

        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }
    
    lista->qtd++;
}

void dfs(vertice *vertice, int x, int dist){
    registro *aux;
    vertice[x].vis = 1;
    vertice[x].dist = dist;

    if(vertice[x].lista_adjacentes == NULL){
        return;
    }

    aux = vertice[x].lista_adjacentes->inc;
    while(aux != NULL){
        if(vertice[aux->val].vis == 0){
            dfs(vertice, aux->val, dist+1);
        }

        aux = aux->proximo;
    }
}
int main(){

    vertice *vert;
    int qtdVert = 0, qtdares = 0, l = 0, qtdCon = 0, dist = 0, i = 0, j = 0, a = 0, b = 0, c = 0, d = 0;

    scanf("%d", &qtdVert);
    scanf("%d", &qtdares);

    vert = (vertice*)calloc(1001, sizeof(vert));

    for(i = 0; i < qtdares; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        
        push(&vert[a], b);
        push(&vert[b], a);
    }

    scanf("%d", &qtdCon);
    int contador[qtdCon];
    for(j = 0; j < qtdCon; j++){
        scanf("%d", &c);
        scanf("%d", &d);
        dfs(vert, c, 0);     
        contador[j] = vert[d].dist;
        limpaVert(vert);
    }
	for(l=0; l<qtdCon;l++)
		{
			printf("%d\n", contador[l]);
		}

    return 0;
}
