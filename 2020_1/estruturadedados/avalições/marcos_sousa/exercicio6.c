#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;

} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

//Todas as funções
lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void incluir_comeco(lista *l, int x);
registro *buscar(lista *l, int x);
int remover(lista *l, int x);
void mostrar(lista *l, int opcao);
int primos(int x);
int remover_primo(lista *l);
void menu(lista *l);



int main()
{
    lista * l1;
    l1 = aloca_lista();
    menu(l1);
    printf("\n");
    return 0;
}


lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *aux;
    registro *novo;

    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->fim;
        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;
    }

    l->qtd++;
}

void incluir_comeco(lista *l, int x)
{
    registro *aux, *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->inicio;
        aux->ant = novo;
        novo->prox = aux;
        l->inicio = novo;
    }

    l->qtd++;
}

registro *buscar(lista *l, int x)
{
    registro *aux;

    if (l->qtd == 0)
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

int remover(lista *l, int x)
{
    registro *aux, *tras, *frente;

    aux = buscar(l, x);

    if (aux == NULL)
    {
        return 0;
    }

    tras = aux->ant;
    frente = aux->prox;

    if (tras == NULL)
    {
        l->inicio = frente;
    }
    else
    {
        tras->prox = frente;
    }

    if (frente == NULL)
    {
        l->fim = tras;
    }
    else
    {
        frente->ant = tras;
    }
    free(aux);
    l->qtd--;
    return 1;
}

// 1 - indo
// 2 - vindo

void mostrar(lista *l, int opcao)
{
    registro *aux;

    if (l == NULL)
    {
        printf("\n primeiro parametro invalido");
        return;
    }
    if (opcao != 1 && opcao != 2)
    {
        printf("\n segundo parametro invalido");
        return;
    }

    if (l->qtd == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {

        if (opcao == 1)
        {
            aux = l->inicio;
        }
        else
        {
            aux = l->fim;
        }

        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            if (opcao == 1)
            {
                aux = aux->prox;
            }
            else
            {
                aux = aux->ant;
            }
        }
    }
}


int primos(int x) //funçao primo
{
	int i;
	if (x==1)
	{
	return 0;
}
for(i=2;i<x;i++)
{
if(x%i==0)
return 0;
}
return 1;
}

int remover_primo(lista *l)
{
   registro *aux;
   int removido;
   int apaga=0;

        if (l->inicio == NULL) //nao ha nenhum elemento na lista
    {
        return 0;  //logo nao retorna nada
    }
    else //ha elementos
    {
        aux = l->inicio;
        while (aux != NULL)
        {
        	apaga=0;//sempre reinicia o apaga para descobrir se o proximo valor deve ser apagado
            if (primos(aux->valor)) //for primo
            {
            	removido=aux->valor; //uma variavel receber o valor primo pra logo apos ser removido
            	apaga=1; //variavel para dizer que o numero deve ser apagado
             }
                aux = aux->prox;

         if(apaga)//se o numero deve ser apagado ...
             {
                remover(l,removido);//chama a fução remover,recebe da variavel o valor primo que deve ser removido
             }

}

}
return 1;
}


void menu(lista *l)
{
    int opcao;
    int numero, retorno;
    int j;
    registro *aux;

    do
    {
        printf("\n 1 - Incluir no comeco");
        printf("\n 2 - Incluir no final");
        printf("\n 3 - Buscar ");
        printf("\n 4 - Remover");
        printf("\n 5 - Mostrar");
        printf("\n 6 - Excluir todos os numeros primo");
        printf("\n 7 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir ?");
            scanf("%d", &numero);
            incluir_comeco(l, numero);

            break;
        case 2:
            printf("\n Qual numero deseja inserir ?");
            scanf("%d", &numero);
            incluir_no_final(l, numero);

            break;
        case 3:
            printf("\n Qual numero deseja buscar?");
            scanf("%d", &numero);
            aux = buscar(l, numero);
            if (aux == NULL)
            {
                printf("\n numero nao encontrado");
            }
            else
            {
                printf("\n numero %d encontrado", aux->valor);
            }

            break;
        case 4:
            printf("\n Qual numero deseja remover?");
            scanf("%d", &numero);
            retorno = remover(l, numero);
            if (retorno == 0)
            {
                printf("\n numero nao foi removido");
            }
            else
            {
                printf("\n numero removido com sucesso");
            }

            break;
        case 5:
            printf("\n Deseja mostrar indo (1) ou vindo (2)");
            scanf("%d", &numero);
            mostrar(l, numero);
            break;
            case 6:
            j= remover_primo(l);
            if (j)
            {
                printf("\n Os numeros foram removidos com sucesso ");
            }
            else
            {
                printf("\n Nao ha nenhum elemento na lista ou não ha nenhum numero primo");
            }

            break;
        case 7:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 7);
}
