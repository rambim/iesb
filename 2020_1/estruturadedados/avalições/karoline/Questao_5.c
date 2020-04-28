#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

registro *aloca_registro();
lista *aloca_lista();
int push(int x);
int pop();

int main()
{

    lista *pilha;
    int qtd, i, j;
    char *entrada;
    int parenteses_abre = 0;
	int parentese_fecha = 0;
    entrada = (char *)malloc(sizeof(char) * 1000);
	

    for (i = 0; i < qtd; i++)
    {

        fflush(stdin);
    
        pilha = aloca_lista();
     	parentese_abre = 0;
     	parentese_fecha = 0;
        scanf("%s", entrada);
        for (j = 0; j < strlen(entrada); j++)
        {
            if (entrada[j] == '(')
            {
                push(pilha, 1);
                parentese_abre++;
            }
            else
            {
                if (entrada[j] == ')')
                {

                    if (pop(pilha) == 1)
                    {
                        parentese_fecha++;
                    }
                }
            }
        }
        if(parentese_abre == parentese_fecha)
        {
        	printf("Correto");
		}else
		{
			printf("Incorreto");
		}
        free(pilha);
        printf("\n");
    }

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
int push(int x)
{
        vet[qtd] = x;
        qtd++;
        
		return 1;
}

int pop()
{
    int x;
	qtd--;
    
	x = vet[qtd];
    
	vet[qtd] = -1;
    
	return x;
}
