#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;

} registro;

void mostrar(lista *l);
lista *aloca_lista();
registro *aloca_registro();
void push(lista *l, int x);
int pop(lista *l);
void menu(lista *l);
int empty(lista *l);
int stack_pop(lista *l);
int principal(lista *l,int qtd);
void mostrar2(lista *l);
void mostrar3(lista *l);
void push2(lista *l, int x);
void retirados(lista*);
int main()
{

    lista *pilha;
    lista *pilha2;
    int qtd, i, x;
    char *texto;
    int retiradas = 0;


     printf("decida o numero de cartas a colocar sendo no maximo 50\n");
    scanf("%d", &qtd);
    if(qtd>50)
    {
              printf("\n Numero acima do permitido \n");
              return 0;
    }
else
{


    for (i = 0; i < qtd; i++)
    {
              printf("Numero:");
              scanf("%d",&x);
             push(pilha, x);
          }
}
mostrar(pilha);
printf("\n\n");

printf("Descartados:");
while(qtd>1)
          {

                 principal(pilha,qtd);
                 qtd--;

                 //mostrar(pilha);
          }
          printf("\n");
          mostrar2(pilha);



}
/*void retirados(lista *l)
{
      int x;
      lista *j;
      x=stack_pop(l);
      push(j,x);

}
*/
lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->qtd = 0;

    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void push(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (empty(l)) // if(l->inicio==NULL)
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

void mostrar(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n valor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}
void mostrar2(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\nCarta que sobrou = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
}
void mostrar3(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("Retirados = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

int pop(lista *l)
{
    registro *aux = NULL;
    int retorno;

    if (empty(l))
    {
        return -1;
    }
    else
    {
        aux = l->inicio;
        retorno = aux->valor;
        l->inicio = aux->prox;
        free(aux);
        l->qtd--;
        return retorno;
    }
}

int empty(lista *l)
{
    if (l->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_pop(lista *l)
{
    if (!empty(l))
    {
        return l->inicio->valor;
    }
    else
    {
        return -1;
    }
}

void push2(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (empty(l)) // if(l->inicio==NULL)
    {
        l->inicio = novo;
    }
    else
    {
              aux=l->inicio;
        while(aux->prox!=NULL)
    {
           aux=aux->prox;
    }
       aux->prox =novo;
    }

    l->qtd++;
}
int principal(lista *l,int qtd)
{
          int x;
          if (qtd<2)
          {
                    return 0;
          }
          else
{
              printf("%d, ",pop(l));
              x = stack_pop(l);
             pop(l);
              push2(l,x);
              return 1;

          }
}
