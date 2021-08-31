#include <stdio.h>
#include <stdlib.h>

/*

1 - Utilizando como base o código da lista ligada ex1.c, construa um programa que receba 10 números do usuário. Esses 10 números
devem ser incluídos em uma lista de nome lista_do_felippe e após incluído todos os números, solicite ao usuário um número X e diga
se o número X está na lista ou não.

*/


typedef struct lista_ligada
{
    int qtd;
    struct registro * inicio;
}lista_ligada;

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;

lista_ligada * aloca_lista();
registro * aloca_registro();
void incluir_no_fim_da_lista(lista_ligada * l, int x);
void mostrar_lista(lista_ligada * l);
int remover_registro_da_lista(int valor_para_apagar, lista_ligada * l );
registro * buscar_registro ( lista_ligada * l, int x);

int main()
{
    lista_ligada * lista_do_felippe;
    lista_do_felippe = aloca_lista();

    int i,numero,x;

    printf("\n Digite 10 numeros: ");
    for(i=0;i<10;i++)
    {
        scanf("%d",&numero);
        incluir_no_fim_da_lista(lista_do_felippe,numero);
    }

    mostrar_lista(lista_do_felippe);

    printf("\n Digite o valor a ser buscado (x): ");
    scanf("%d",&x);

    if (buscar_registro(lista_do_felippe,x)==NULL)
        printf("\n Elemento não está na lista com os 10 valores digitados");
    else
        printf("\n Elemento encontrado na lista com os 10 valores digitados");

    printf("\n");
    return 0;
}

lista_ligada * aloca_lista()
{
    lista_ligada * novo;
    novo = (lista_ligada*)calloc(1,sizeof(lista_ligada));
    novo->inicio=NULL;

    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}

void incluir_no_fim_da_lista(lista_ligada * l, int x)
{
    registro * novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio = novo;   
    }
    else
    {
        aux = l->inicio;

        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista_ligada * l)
{
    if (l==NULL){
        printf("\n Lista nao alocada");
        return;
    }

    if (l->inicio==NULL)
    {
        printf("\n Lista sem elementos");
        return;
    }

    registro * aux;

    aux = l->inicio;

    while(aux!=NULL)
    {
        printf("\n -> %d",aux->valor);
        aux=aux->prox;   
    }
}


//0 - não conseguir apagar um elemento.
//1 - conseguir apagar um elemento.

int remover_registro_da_lista(int valor_para_apagar, lista_ligada * l )
{
    if (l==NULL)
    {
        printf("\nLista inexistente");
        return 0;
    }   

    if (l->inicio==NULL)
    {
        printf("\nLista vazia");
        return 0;
    }

    registro * aux=l->inicio,*ant=NULL;
    int encontrou=0;
    while(aux!=NULL && encontrou==0)
    {
        if (aux->valor == valor_para_apagar){
            ant->prox = aux->prox;
            free(aux);
            l->qtd--;
            encontrou=1;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    if (encontrou)
        return 1;
    else
        return 0;

}


registro * buscar_registro ( lista_ligada * l, int x)
{
    if (l==NULL)
        return NULL;
    if (l->inicio==NULL)
        return NULL;

    registro * aux;

    aux = l->inicio;

    while(aux!=NULL)
    {
        if (aux->valor == x)
            return aux;
        else
            aux = aux->prox;
    }

    return NULL;
}



