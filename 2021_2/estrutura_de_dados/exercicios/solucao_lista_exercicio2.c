/*

1 - Utilizando como base os exemplos 1,2,3 e 4, construa uma 
função que receba por parâmetro uma lista e um número
e insira valores nessa lista de forma que ela permaneça sempre ordenada.

Na sua função principal solicite N valores
ao usuário até que seja digitado o valor 0.
Insira todos os valores digitados em uma lista utilizando a 
função criada e ao final mostre todos valores da lista.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_ligada
{
    int qtd;
    struct registro *inicio;
} lista_ligada;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

void mostrar(lista_ligada *l);
registro *aloca_registro();
lista_ligada *aloca_lista();
int valida_lista(lista_ligada *l);
void incluir_ordenado(lista_ligada *l, int x);

lista_ligada *aloca_lista()
{
    lista_ligada *novo;
    novo = (lista_ligada *)calloc(1, sizeof(lista_ligada));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void mostrar(lista_ligada *l)
{
    if (valida_lista(l))
    {
        registro *aux;

        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->prox;
        }
    }
}

int valida_lista(lista_ligada *l)
{
    if (l == NULL)
    {
        printf("\n Lista nao alocada");
        return 0;
    }
    return 1;
}

void incluir_ordenado(lista_ligada *l, int x)
{

    if (l == NULL)
        return;

    registro *aux, *ant = NULL, *novo;
    aux = l->inicio;

    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        int inseriu = 0;
        while (aux != NULL && !inseriu)
        {
            if (x < aux->valor)
            {
                if (ant == NULL)
                    l->inicio = novo;
                else
                    ant->prox = novo;

                novo->prox = aux;
                inseriu = 1;
            }
            else
            {
                ant = aux;
                aux = aux->prox;
            }
        }
        // se não inseriu ainda, significa que chegou no final da lista e não encontrou um numero maior.
        // Nesse caso, só incluir no final da lista.
        if (!inseriu)
        {
            if (ant == NULL)
                l->inicio = novo;
            else
                ant->prox = novo;
        }
    }
}

int main()
{
    int numero;
    lista_ligada * l;
    l = aloca_lista();

    do
    {
        printf("\n Digite um numero: ");
        scanf("%d",&numero);
        incluir_ordenado(l,numero);

    } while (numero != 0);

    mostrar(l);
    printf("\n");
    return 0;
}
