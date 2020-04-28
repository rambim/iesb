#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} fila;

typedef struct registro
{
    int valor;
    struct registro *prox;

} registro;

void mostrar(fila *f);
fila *aloca_fila();
registro *aloca_registro();
void push(fila *f, int x);
int pop(fila *f);
void menu(fila *f);
int empty(fila *f);
int stack_pop(fila *f);

    int main()
{

    fila *f1;
    f1 = aloca_fila();


    menu(f1);

    return;

}

fila *aloca_fila()
{
    fila *novo;
    novo = (fila *)malloc(sizeof(fila));
    novo->inicio = NULL;
    novo->fim = NULL;
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

void push(fila *f, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (f->qtd == 0) // if(l->inicio==NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
              aux=f->fim;
               aux->prox= novo;
               f->fim = novo;

    }

    f->qtd++;
}

void mostrar(fila *f)
{
    registro *aux;

    if (f->inicio == NULL)
    {
              printf("***********************************");
        printf("\n Nao existem elementos no momento\n");
        printf("***********************************");
    }
    else
    {
                    printf("\n***********************************\n");
        aux = f->inicio;
        while (aux != NULL)
        {
            printf(" %d  ", aux->valor);
            aux = aux->prox;
        }
                                        printf("\n***********************************\n");


    }
}

int pop(fila *f)
{
    registro *aux = NULL, *ant = NULL;
    int excluido;

    if (empty(f))
    {
        return 0;
    }
    else
    {
        aux = f->inicio;

        while (aux->prox != NULL)
        {
                ant = aux;
                aux = aux->prox;

        }
        //aux->prox ==NULL
                if (ant == NULL)
                {
                    f->inicio = NULL;
                    f->fim = NULL;
                }
                else
                {
                    ant->prox=NULL;
                    f->fim = ant;
                }

                excluido=aux->valor;
                free(aux);
                f->qtd--;
                return excluido;



        }


    }




int empty(fila *f)
{
    if (f->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_pop(fila *f)
{
    if (!empty(f))
    {
        return f->fim->valor;
    }
    else
    {
        return -1;
    }
}

void menu(fila *f)
{
    int opcao;
    int numero;
    int retorno;
    registro *aux;

    do
    {
        printf("\n");
        printf("\n 1 - push");
        printf("\n 2 - pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Sair\n");
        printf("\n");
       mostrar(f);
        printf("\n\n");
        scanf("%d", &opcao);

            switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            push(f, numero);
            break;
        case 2:

            if (!empty(f))
            {
                      printf("***********************************");
                printf("\n        Pop de  %d       \n", pop(f));
                printf("***********************************");
            }
            else
            {
              printf("\n***********************************");
                printf("\n Fila esta vazia");
            printf("\n***********************************\n");

            }
            break;
        case 3:
            if (!empty(f))
            {
                printf("\n***********************************");
                printf("\n  Pop de  %d", stack_pop(f));
                printf("\n***********************************\n");

            }
            else
            {
                printf("\n***********************************");
                printf("\n Fila esta vazia");
                printf("\n***********************************\n");

            }

            break;
        case 4:
            if (empty(f))
            {
                printf("\n***********************************");
                printf("\n Fila esta vazia");
                printf("\n***********************************\n");

            }
            else
            {
                printf("\n***********************************");
                printf("\n Fila possui elementos");
                printf("\n***********************************\n");

            }

            break;
        case 5:
            printf("\n***********************************");
            printf("\n Saindo do programa");
            printf("\n***********************************\n");

            break;

        default:
            printf("\n***********************************");
            printf("\n opcao invalida");
            printf("\n***********************************\n");

            break;
        }

    } while (opcao != 5);
}
