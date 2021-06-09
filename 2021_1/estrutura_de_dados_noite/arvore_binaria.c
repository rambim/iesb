#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int qtd_elementos;
    struct no *raiz;
} arvore;

typedef struct no
{
    int valor;
    int qtd;
    struct no *esquerda;
    struct no *direita;
} no;

arvore *aloca_arvore();
no *aloca_no();
void incluir(arvore *a, int x);
void mostrar_pre_ordem(no * a);
void mostrar_em_ordem(no * a);
void mostrar_pos_ordem(no * a);
int buscar(no * a, int x);

int main()
{
    arvore *a1;
    a1 = aloca_arvore();
    incluir(a1,50);
    incluir(a1,25);
    incluir(a1,75);
    incluir(a1,10);
    incluir(a1,30);
    incluir(a1,60);
    incluir(a1,90);
    incluir(a1,5);
    incluir(a1,15);
    incluir(a1,27);
    incluir(a1,32);
    incluir(a1,55);
    incluir(a1,66);
    incluir(a1,80);
    incluir(a1,100);

    int procurado = 32;

    printf("\n Pre ordem: ");
    mostrar_pre_ordem(a1->raiz);
    printf("\n em ordem: ");
    mostrar_em_ordem(a1->raiz);
    printf("\n Pos ordem: ");
    mostrar_pos_ordem(a1->raiz);

    if (buscar(a1->raiz,procurado))
        printf("\n Numero %d esta na arvore",procurado);
    else
        printf("\n Numero %d nao esta na arvore",procurado);


    printf("\n");
    return 0;
}

arvore *aloca_arvore()
{
    arvore *nova;
    nova = (arvore *)calloc(1, sizeof(arvore));
    return nova;
}

no *aloca_no()
{
    no *novo;
    novo = (no *)calloc(1, sizeof(no));
    return novo;
}

void incluir(arvore *a, int x)
{
    no *novo, *aux;
    novo = aloca_no();
    novo->valor = x;
    novo->qtd = 1;

    int inseriu = 0;

    if (a->raiz == NULL)
    {
        a->raiz = novo;
        a->qtd_elementos++;
    }
    else
    {
        aux = a->raiz;
        while (!inseriu)
        {
            if (aux->valor == x)
            {
                aux->qtd++;
                return;
            }
            else
            {
                if (x < aux->valor)
                {
                    if (aux->esquerda == NULL)
                    {
                        aux->esquerda = novo;
                        inseriu = 1;
                        a->qtd_elementos++;
                    }
                    else
                    {
                        aux = aux->esquerda;
                    }
                }
                else
                {
                    if (aux->direita==NULL)
                    {
                        aux->direita = novo;
                        inseriu=1;
                        a->qtd_elementos++;
                    }
                    else
                    {
                        aux = aux->direita;
                    }
                }
            }
        }
    }
}

void mostrar_pre_ordem(no * a)
{
    if (a==NULL)
        return;
    
    printf(" %d",a->valor);
    mostrar_pre_ordem(a->esquerda);
    mostrar_pre_ordem(a->direita);
}
void mostrar_em_ordem(no * a)
{
    if (a==NULL)
        return;
    
    mostrar_em_ordem(a->esquerda);
    printf(" %d",a->valor);
    mostrar_em_ordem(a->direita);
}
void mostrar_pos_ordem(no * a)
{
    if (a==NULL)
        return;
    
    mostrar_pos_ordem(a->esquerda);
    mostrar_pos_ordem(a->direita);
    printf(" %d",a->valor);
}


int buscar(no * a, int x)
{
    if (a==NULL)
        return 0;

    if (a->valor == x)
        return 1;
    else
    {
        if (x<a->valor)
            return buscar(a->esquerda,x);
        else
            return buscar(a->direita,x);
    }
}