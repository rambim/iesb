#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;
void mostrar_lista(lista * l);
lista * aloca_lista();
elemento * aloca_elemento();
void incluir_inicio(lista * l, int x);
int remover_elemento(lista *l, int valor) ;

int main()
{
    lista * l1,*l2;

    l1 = aloca_lista();
    l2 = aloca_lista();

    incluir_inicio(l1,3);
    incluir_inicio(l1,2);
    incluir_inicio(l1,1);

    mostrar_lista(l1);

    incluir_inicio(l2,10);
    incluir_inicio(l2,20);
    incluir_inicio(l2,30);

    mostrar_lista(l2);

    printf("\nRemovendo elemento 2 da lista l1.\n");
    remover_elemento(l1, 2);
    mostrar_lista(l1);

    printf("\nRemovendo elemento 30 da lista l2.\n");
    remover_elemento(l2, 30);
    mostrar_lista(l2);


    printf("\n");

    return 0;
}

lista * aloca_lista()
{
    lista * novo;
    novo =(lista*)calloc(1,sizeof(lista));
    return novo;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1,sizeof(elemento));
    return novo;
}

void incluir_inicio(lista * l, int x)
{

    elemento * novo;
    novo = aloca_elemento();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista * l)
{
    elemento * aux;
    aux = l->inicio;

    while(aux!=NULL){
        printf("\n %d ",aux->valor);
        aux=aux->prox;
    }
}

int remover_elemento(lista *l, int valor) {
    if (l->inicio == NULL) {
        return 0; // Lista vazia, não há o que remover
    }

    elemento *aux, *anterior;
    aux = l->inicio;
    anterior = NULL;

    while (aux != NULL) {
        if (aux->valor == valor) {
            if (anterior == NULL) {
                // Removendo o primeiro elemento da lista
                l->inicio = aux->prox;
            } else {
                // Removendo um elemento do meio ou do final da lista
                anterior->prox = aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1; // Remoção bem-sucedida
        }
        anterior = aux;
        aux = aux->prox;
    }

    return 0; // Elemento não encontrado na lista
}
