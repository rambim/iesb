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
void incluir(lista *l, int x);
int remover_registro(lista *l, int x);
registro *buscar(lista *l, int x);
void menu(lista *l);
int contar(lista *l);
int primo(int x);
int remove_primos(lista *l);
int remover_primos2(lista *l);

int main()
{

    lista *l1;
    lista *l2;
    l1 = aloca_lista();
    l2 = aloca_lista();

    menu(l1);

    return 0;
}

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

void incluir(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0) // if(l->inicio==NULL)
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

int remover_registro(lista *l, int x)
{
    registro *aux = NULL, *ant = NULL;

    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aux->valor == x)
            {
                if (ant == NULL)
                {
                    l->inicio = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                free(aux);
                l->qtd--;
                return 1;
            }
            else
            {
                ant = aux;
                aux = aux->prox;
            }
        }
        return 0;
    }
}

registro *buscar(lista *l, int x)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        return NULL;
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->valor == x)
            {
                return aux;
            }
            else
            {
                aux = aux->prox;
            }
        }

        return NULL;
    }
}

void menu(lista *l)
{
    int opcao;
    int numero;
    int retorno;
    registro *aux;

    do
    {
        printf("\n 1 - Incluir");
        printf("\n 2 - Buscar");
        printf("\n 3 - Remover");
        printf("\n 4 - Mostrar");
        printf("\n 6 - contar");
        printf("\n 7 - remove primos");
        printf("\n 5 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            incluir(l, numero);
            break;
        case 2:
            printf("\n Qual numero deseja buscar: ");
            scanf("%d", &numero);
            aux = buscar(l, numero);
            if (aux == NULL)
            {
                printf("\n numero nao encontrado");
            }
            else
            {
                printf("\n Numero %d encontrado", aux->valor);
            }

            break;

        case 3:
            printf("\n QUal numero deseja remover: ");
            scanf("%d", &numero);
            retorno = remover_registro(l, numero);
            if (retorno == 0)
            {
                printf("\n numero nao esta na lista\n");
            }
            else
            {
                printf("\n numero removido com sucesso");
            }

            break;
        case 4:
            mostrar(l);
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        case 6:
            printf("\n Quantidade de elementos na lista ");
            printf("%d", contar(l));
            break;
        case 7:
            printf("removendo primos");
            retorno = remover_primos2(l);
            if (retorno)
            {
                printf("\n Os primos foram apagados");
            }
            else
            {
                printf("\n Nao haviam primos ");
            }
            break;

        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 5);
}

int contar(lista *l)
{
    registro *aux;
    int count = 0;

    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            count++;
            aux = aux->prox;
        }
        return count;
    }
}

int primo(int x)
{
    int div;
    if (x == 1)
    {
        return 0;
    }
    else
    {
        if (x < 0)
        {
            x = x * (-1);
        }
        for (div = 2; div < x; div++)
        {
            if (x % div == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int remove_primos(lista *l)
{
    registro *aux, *ant, *removido;
    int apaga = 0;
    int apagou = 0;

    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        aux = l->inicio;
        ant = NULL;

        while (aux != NULL)
        {

            apaga = 0;
            if (primo(aux->valor))
            {
                printf("\n %d eh primo ", aux->valor);
                if (ant == NULL)
                {
                    l->inicio = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                removido = aux;

                apaga = 1;

                l->qtd--;
            }
            else
            {
                ant = aux;
            }
            aux = aux->prox;
            if (apaga)
            {
                free(removido);
                apagou = 1;
            }
        }
    }

    return apagou;
}

int remover_primos2(lista *l)
{
    registro *aux;
    int removido;
    int apaga = 0;

    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            apaga = 0;
            if (primo(aux->valor))
            {
                removido = aux->valor;
                apaga = 1;
            }
            aux = aux->prox;
            if (apaga)
            {
                remover_registro(l, removido);
            }
        }
    }
    return 1;
}