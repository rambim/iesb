/*
Gabriel Salmai Camargo Farias - 1922130017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int vertice;
    int distancia;
}elemento;

typedef struct vertice
{
    int visitado;
    int distancia;
    int lower;
    int in;
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
    int peso;
    struct registro *prox;
} registro;


int qtd_global[10001];
int count = 1;

elemento heap[1000];
int count_min_heap = 0;


void inicializar_distancias(vertice * vertices);
void djisktra(vertice * vertices, int raiz);

void mostrar_lista(lista *l);
int incluir_ordenado_lista(lista *l, int x, int peso);
registro *aloca_registro();
lista *aloca_lista();
int carrega_grafo(vertice *vertices, char *nome_do_arquivo);
void push(vertice *v, int x, int peso);
void mostrar_lista_dos_vertices(vertice *v, int tam);
int min(int x, int y);

int define_filho_direita(int indice);
int define_filho_esquerda(int indice);
int define_pai(int indice);
void subir_minimo(int indice);
void descer_minimo(int indice);
int push_fila(elemento x);
elemento pop();
int empty();


int main(int *argc, char *argv[])
{
    vertice *vertices;
    int qtd_vertices,i;
    printf(" Parametro recebido: %s", argv[1]);
    vertices = (vertice *)calloc(10001, sizeof(vertice));
    qtd_vertices = carrega_grafo(vertices, argv[1]);
    if (qtd_vertices)
    {
        printf("\n Grafo carregado com sucesso qtd vertices: %d",qtd_vertices);
        mostrar_lista_dos_vertices(vertices, 10001);
    }
    else
        printf("\n Problema no carregamento do grafo");


    djisktra(vertices, 6);

    for(i=1;i<=qtd_vertices;i++){
        printf("\n Distancia do no raiz (F) ate %d = %d", i, vertices[i].distancia);
    }

    printf("\n");
    return 0;
}

void inicializar_distancias(vertice * vertices){
    int i;

    for(i=0;i<10000;i++){
        vertices[i].distancia = 9999;
    }
}

void djisktra(vertice * vertices, int raiz){

    int current, distancia_atual;
    elemento elemento_aux;
    registro * aux;

    inicializar_distancias(vertices);

    vertices[raiz].distancia = 0;
    elemento_aux.distancia = 0;
    elemento_aux.vertice = raiz;
    push_fila(elemento_aux);

    while (!empty())
    {
        elemento_aux = pop();
        current = elemento_aux.vertice;
        distancia_atual = elemento_aux.distancia;

        if(vertices[current].lista_adj==NULL){
            printf("\n Vertice em componente desconectado");
            return;
        }

        aux = vertices[current].lista_adj->inicio;
        while (aux!=NULL)
        {
            if(distancia_atual + aux->peso < vertices[aux->valor].distancia){
                vertices[aux->valor].distancia = distancia_atual + aux->peso;
                elemento_aux.distancia = vertices[aux->valor].distancia;
                elemento_aux.vertice = aux->valor;
                push_fila(elemento_aux);
            }
            aux = aux -> prox;
        }
    }
}

int carrega_grafo(vertice *vertices, char *nome_do_arquivo)
{
    FILE *arq;
    arq = fopen(nome_do_arquivo, "r");
    int a, b, c;
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

    while (fscanf(arq, "%d;%d;%d\n", &a, &b, &c) != EOF)
    {
        printf("\n %d -> %d Peso: %d", a, b, c);

        if (qtd_global[a]==0)
            qtd_vertices++;
            qtd_global[a] = 1;

        if (qtd_global[b]==0)
            qtd_vertices++;
            qtd_global[b] = 1;

        push(&vertices[a], b, c);
        push(&vertices[b], a, c);
    }

    return qtd_vertices;
}

void push(vertice *v, int x, int peso)
{
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_lista();
    incluir_ordenado_lista(v->lista_adj, x, peso);
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

int incluir_ordenado_lista(lista *l, int x, int peso)
{
    if (l == NULL)
        return 0;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;
    novo->peso=peso;

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

int min(int x, int y){
    return x < y ? x : y;
}

int define_filho_esquerda(int indice){
    return indice * 2;
}

int define_filho_direita(int indice){
    return (indice * 2) + 1;
}

int define_pai(int indice){
    return indice/2;
}

void subir_minimo(int indice){
    elemento aux;

    if(indice<=1){
        return;
    }

    int pai = define_pai(indice);

    if(heap[indice].distancia < heap[pai].distancia){
        aux = heap[indice];
        heap[indice] = heap[pai];
        heap[pai] = aux;
        subir_minimo(pai);
    }
}

void desce_minimo(int indice){
    if(indice * 2 > count_min_heap){
        return;
    }
    int esquerda = define_filho_esquerda(indice);
    int direita = define_filho_direita(indice);

    int menor = indice;

    if(esquerda <= count_min_heap && heap[esquerda].distancia < heap[menor].distancia){
        menor = esquerda;
    }

    if(direita <= count_min_heap && heap[direita].distancia < heap[esquerda].distancia){
        menor = direita;
    }

    if(menor == indice){
        return;
    }

    elemento aux;

    aux = heap[indice];
    heap[indice] = heap[menor];
    heap[menor] = aux;
    desce_minimo(menor);
}

int push_fila(elemento x){
    count_min_heap++;
    heap[count_min_heap] = x;
    subir_minimo(count_min_heap);
}

elemento pop(){
    elemento retorno;

    if(count_min_heap == 0){
        retorno.distancia = -1;
        retorno.vertice = -1;
        return retorno;
    }

    retorno = heap[1];

    heap[1] = heap[count_min_heap];
    count_min_heap--;
    desce_minimo(1);
    return retorno;
}

int empty(){
    if(count_min_heap==0){
        return 1;
    }
    else{
        return 0;
    }
}