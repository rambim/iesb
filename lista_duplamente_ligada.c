#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}lista;


typedef struct registro
{
    int valor;
    struct registro * ant;
    struct registro * prox;
}registro;

int main()
{
    return 0;
}