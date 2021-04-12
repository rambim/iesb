// Implemente uma lista ligada de caracteres em C, ou seja, cada registro da lista deve possui
// apenas 1 caractere. Construa uma função chamada "separa_vogais_consoantes". Essa função irá
// receber 3 listas (lista_a,  lista_b, lista_c) e deverá incluir na lista_b todas as vogais
// contidas na lista_a e incluir na lista_c todas as consoantes contidas na lista_a.  Na sua
// função principal, solicite um texto ao usuário e mostre a lista de vogais e consoantes utilizando a função criada.

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    char valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, char a);
void mostrar(lista *l);
int vogal(char c);
void separa_vogais_consoantes(lista *la, lista *lb, lista *lc);

int main()
{
    lista *l, *vogais, *consoantes;
    char texto[100];
    l = aloca_lista();
    vogais = aloca_lista();
    consoantes = aloca_lista();
    l = aloca_lista();
    int i;

    printf("\n Digite um texto: ");
    __fpurge(stdin);
    fgets(texto, 100, stdin);
    texto[strlen(texto) - 1] = '\0';

    for (i = 0; i < strlen(texto); i++)
    {
        incluir_no_final(l, texto[i]);
    }

    separa_vogais_consoantes(l,vogais,consoantes);

    printf("\n Mostrando texto completo: ");
    mostrar(l);
    printf("\n Mostrando vogais: ");
    mostrar(vogais);
    printf("\n Mostrando consoantes: ");
    mostrar(consoantes);
    printf("\n");
    return 0;
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

void incluir_no_final(lista *l, char a)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor = a;
    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        registro *aux;
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux;

    aux = l->inicio;
    while (aux != NULL)
    {
        printf("%c", aux->valor);
        aux = aux->prox;
    }
}

void separa_vogais_consoantes(lista *la, lista *lb, lista *lc)
{
    if (la->inicio == NULL)
    {
        printf("\n Lista origem vazia");
        return;
    }

    registro *aux;
    aux = la->inicio;

    while (aux != NULL)
    {
        if (vogal(aux->valor))
            incluir_no_final(lb,aux->valor);
        else
            incluir_no_final(lc,aux->valor);

        aux = aux->prox;
    }
}

int vogal(char c)
{
    if ((c == 'A') || (c == 'a') ||
        (c == 'E') || (c == 'e') ||
        (c == 'I') || (c == 'i') ||
        (c == 'O') || (c == 'o') ||
        (c == 'U') || (c == 'u'))
    {
        return 1;
    }
    else
        return 0;
}