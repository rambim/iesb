#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int qtd;
    struct elemento *inicio;
    struct elemento *fim;
} lista;

typedef struct elemento {
    int valor;
    struct elemento *prox;
    struct elemento *ant;
} elemento;

void mostrar_lista(lista *l);
lista *aloca_lista();
elemento *aloca_elemento();
void incluir_inicio(lista *l, int x);
void incluir_final(lista *l, int x);
void incluir_ordenado(lista *l, int x);
int remover_elemento(lista *l, int valor);

int main() {
    lista *l1;
    l1 = aloca_lista();

    incluir_inicio(l1, 3);
    incluir_final(l1, 5);
    incluir_ordenado(l1, 4);
    incluir_ordenado(l1, 2);
    incluir_ordenado(l1, 1);

    mostrar_lista(l1);

    printf("\nRemovendo elemento 4 da lista l1.\n");
    remover_elemento(l1, 4);
    mostrar_lista(l1);

    return 0;
}

lista *aloca_lista() {
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

elemento *aloca_elemento() {
    elemento *novo;
    novo = (elemento *)calloc(1, sizeof(elemento));
    return novo;
}

void incluir_inicio(lista *l, int x) {
    elemento *novo = aloca_elemento();
    novo->valor = x;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_final(lista *l, int x) {
    elemento *novo = aloca_elemento();
    novo->valor = x;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        novo->ant = l->fim;
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void incluir_ordenado(lista *l, int valor) {
    elemento *novo = aloca_elemento();
    novo->valor = valor;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        elemento *aux = l->inicio;
        elemento *anterior = NULL;

        while (aux != NULL && aux->valor < valor) {
            anterior = aux;
            aux = aux->prox;
        }

        if (anterior == NULL) {
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
        } else {
            novo->prox = aux;
            novo->ant = anterior;
            anterior->prox = novo;
            if (aux != NULL) {
                aux->ant = novo;
            } else {
                l->fim = novo;
            }
        }
    }
    l->qtd++;
}

int remover_elemento(lista *l, int valor) {
    if (l->inicio == NULL) {
        return 0; // Lista vazia, não há o que remover
    }

    elemento *aux = l->inicio;

    while (aux != NULL) {
        if (aux->valor == valor) {
            if (aux->ant == NULL) {
                // Removendo o primeiro elemento da lista
                l->inicio = aux->prox;
                if (l->inicio != NULL) {
                    l->inicio->ant = NULL;
                } else {
                    l->fim = NULL;
                }
            } else if (aux->prox == NULL) {
                // Removendo o último elemento da lista
                l->fim = aux->ant;
                l->fim->prox = NULL;
            } else {
                // Removendo um elemento do meio da lista
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            l->qtd--;
            free(aux);
            return 1; // Remoção bem-sucedida
        }
        aux = aux->prox;
    }

    return 0; // Elemento não encontrado na lista
}

void mostrar_lista(lista *l) {
    elemento *aux;

    printf("\nLista do início ao fim:\n");
    aux = l->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\nLista do fim ao início:\n");
    aux = l->fim;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->ant;
    }
}


