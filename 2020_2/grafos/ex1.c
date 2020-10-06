#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    struct no * raiz;
    int qtd;
}arvore;

typedef struct no
{
    int valor;
    struct no * esq;
    struct no * dir;
}no;


int main()
{
    arvore a;

    mostrar_pre_ordem(a.raiz);
    mostrar_em_ordem(a.raiz);
    mostrar_pos_ordem(a.raiz);

    return 0;
}

void mostrar_pre_ordem(struct no * x)
{
    if (x==NULL)
    {
        return ;
    }

    printf("\n Valor = %d",x->valor);
    mostrar_pre_ordem(x->esq);
    mostrar_pre_ordem(x->dir);


}
void mostrar_em_ordem(struct no * x)
{
    if (x==NULL)
    {
        return ;
    }

    mostrar_em_ordem(x->esq);
    printf("\n Valor = %d",x->valor);
    mostrar_em_ordem(x->dir);

}
void mostrar_pos_ordem(struct no * x)
{
    if (x==NULL)
    {
        return ;
    }

    mostrar_pos_ordem(x->esq);
    mostrar_pos_ordem(x->dir);
    printf("\n Valor = %d",x->valor);

}



