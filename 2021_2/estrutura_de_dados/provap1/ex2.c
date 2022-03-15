/*

Implemente uma lista ligada de caracteres em C, ou seja, cada registro da lista deve possuir 
apenas 1 caractere. Construa uma função chamada "separa_vogais_consoantes". Essa função irá receber 
3 listas (lista_a,  lista_b, lista_c) e deverá incluir na lista_b todas as vogais contidas na 
lista_a e incluir na lista_c todas as consoantes contidas na lista_a.  
Na sua função principal, solicite um texto ao usuário e mostre a lista de vogais e 
consoantes utilizando a função criada.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct lista_ligada
{
    struct registro *inicio;
} lista_ligada;

typedef struct registro
{
    char letra;
    struct registro *prox;
} registro;

void mostrar(lista_ligada *l);
void incluir_no_final(lista_ligada *l, char c);
void separa_vogais_consoantes(lista_ligada *a, lista_ligada *b, lista_ligada *c);
registro *aloca_registro();
lista_ligada *aloca_lista();

int vogal(char c);
int main()
{

    lista_ligada *l1, *l2, *l3;
    l1 = aloca_lista();
    l2 = aloca_lista();
    l3 = aloca_lista();

    char texto[500];
    int i;

    printf("\n Digite um texto: ");
    __fpurge(stdin); //windows fflush(stdin);
    fgets(texto, 500, stdin);

    for (i = 0; i < strlen(texto) - 1; i++)
    {
        incluir_no_final(l1, texto[i]);
    }

    separa_vogais_consoantes(l1, l2, l3);

    printf("\n Texto completo: \n");
    mostrar(l1);

    printf("\n Apenas vogais: ");
    mostrar(l2);

    printf("\n Apenas consoantes: ");
    mostrar(l3);

    printf("\n");
    return 0;
}

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

void separa_vogais_consoantes(lista_ligada *a, lista_ligada *b, lista_ligada *c)
{
    if (a == NULL || b == NULL || c == NULL)
    {
        printf("\n Listas nao alocadas");
        return;
    }

    if (a->inicio == NULL)
    {
        printf("\n Lista principal vazia");
        return;
    }

    registro *aux;

    aux = a->inicio;

    while (aux != NULL)
    {
        if (aux->letra != ' ')
        {
            if (vogal(aux->letra))
                incluir_no_final(b, aux->letra);
            else
                incluir_no_final(c, aux->letra);
        }
        aux = aux->prox;
    }
}

void incluir_no_final(lista_ligada *l, char c)
{
    if (l == NULL)
        return;

    registro *novo, *aux;

    novo = aloca_registro();
    novo->letra = c;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    
    return;
}

void mostrar(lista_ligada *l)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
        return;

    registro *aux;

    aux = l->inicio;

    while (aux != NULL)
    {
        printf("%c", aux->letra);
        aux = aux->prox;
    }
}

int vogal(char c)
{
    char vogais[] = {"AEIOUaeiou"};
    int i;

    for (i = 0; i < strlen(vogais); i++)
    {
        if (c == vogais[i])
            return 1;
    }
    return 0;
}