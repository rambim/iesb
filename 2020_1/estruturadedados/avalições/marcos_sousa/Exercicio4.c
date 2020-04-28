#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct pilha
{
    int qtd;
    struct registro *inicio;
} pilha;

typedef struct registro
{
    int valor;
    struct registro *prox;

} registro;

pilha *aloca_pilha();
registro *aloca_registro();
void push(pilha *p, int x);
int pop(pilha *p);
int empty(pilha *p);

int main()
{

    pilha *pi;
    int qtd, i, j;
    int qtN,qtJ;
    char *texto;

    texto = (char *)malloc(sizeof(char) * 1000);

printf("Numero de expressoes\n");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++)
    {

        __fpurge(stdin);
        printf("Digite a expressao\n");
        gets(texto);  //recebe a expressao
        pi = aloca_pilha();
        for (j = 0; j < strlen(texto); j++)//la�o para ver cada texto digitado
        {
            if (texto[j] == '(') //se aparecer o (
            {
                push(pi, 1); //coloca ( na pilha ou no caso um numero para expressar o (

            }
            else
            {
                if (texto[j] == ')')//se aparecer o )
                {
                    pop(pi); //retira o ( ou no caso o numero 1 que foi expressado como um (

                }

            }
        }
                        if (empty(pi)) //se a pilha estiver vazia e pq nao ha nenhum parentese aberto sem se fechar
                {
                	printf("\nExpressao correta");
				}
				else //caso contrario a expressao esta errada
				{
					printf("\nExpressao incorreta");
				}
        free(pi); //limpa a pilha pra proxima expressao
        printf("\n");
    }

    return 0;
}

pilha *aloca_pilha()
{
    pilha *novo;
    novo = (pilha *)malloc(sizeof(pilha));
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

void push(pilha *p, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (empty(p)) // if(l->inicio==NULL)
    {
        p->inicio = novo;
    }
    else
    {
        novo->prox = p->inicio;
        p->inicio = novo;
    }

    p->qtd++;
}


int pop(pilha *p)
{
    registro *aux = NULL;
    int retorno;

    if (empty(p))
    {
        return -1;
    }
    else
    {
        aux = p->inicio;
        retorno = aux->valor;
        p->inicio = aux->prox;
        free(aux);
        p->qtd--;
        return retorno;
    }
}

int empty(pilha *p)
{
    if (p->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




