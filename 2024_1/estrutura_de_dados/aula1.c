#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct registro * inicio;
    int qtd;
}lista;

typedef struct registro{
    int valor;
    struct registro * prox;
}registro;

int main(char argc, char * argv[])
{

    lista * a, *b, *c;

    a = cria_lista();
    b = cria_lista();
    c = cria_lista();


    printf("\n Elementos da lista a: %d",a->qtd);
    printf("\n Elementos da lista b: %d",b->qtd);
    printf("\n Elementos da lista c: %d",c->qtd);
    return 0;
}


lista * cria_lista()
{
    lista * nova_lista;
    nova_lista = (lista*)malloc(sizeof(lista));

    
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;

    return nova_lista;

}
