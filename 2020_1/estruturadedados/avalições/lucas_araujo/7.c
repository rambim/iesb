#include <stdlib.h>
#include <stdio.h>

typedef struct Fila
{
    int qtd;
    struct Registro * comeco;
    struct Registro * fim;
}Fila;

typedef struct Registro
{
    int valor;
    struct Registro * prox;
}Registro;

Fila * cria_fila();
Registro * cria_registro(int x);
void push(Fila * f1, int x);
void mostra(Fila * f1);
void pop(Fila * f1);
void menu(Fila * f1);

int main() {
    Fila * fila = cria_fila();

    menu(fila);
    return 0;
}

Fila * cria_fila()
{
    Fila * retorna = (Fila *)malloc(sizeof(Fila));

    retorna->comeco = NULL;
    retorna->fim = NULL;
}

Registro * cria_registro(int x)
{
    Registro * retorna = (Registro *)malloc(sizeof(Registro));

    retorna->prox = NULL;
    retorna->valor = x;

    return retorna;
}

void push(Fila * f1, int x)
{
    Registro * adc = cria_registro(x);

    if (f1->comeco ==NULL)
    {
        f1->comeco = adc;
        f1->fim = adc;
        adc->prox = f1->comeco;
        f1->qtd++;
    }else
    {
        Registro * aux = f1->fim;
        f1->fim = adc;
        aux->prox = adc;
        adc->prox = f1->comeco;
        f1->qtd++;
    }
}

void mostra(Fila * f1)
{
    if(f1->comeco == NULL)
    {
        printf("Fila vazia\n");
    }
    else
    {
        Registro * aux = f1->comeco;
        int i;
        for(i = 0; i<f1->qtd;i++)
        {
            printf(" %d <-", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void pop(Fila * f1)
{
    if(f1->comeco == NULL)
    {
        printf("Fila vazia\n");
    }
    else
    {
        Registro * aux = f1->comeco;
        if(f1->comeco == f1->fim)
        {
            f1->comeco = NULL;
            f1->fim = NULL;
            free(aux);
            f1->qtd--;
        }
        else
        {
            f1->comeco = aux->prox;
            f1->fim->prox = f1->comeco;
            f1->qtd--;
            free(aux);
        }
    }  
}

void menu(Fila * f1){

    int valor_adicionar = 0, opcoes = 0, valor_escolhido = 0;

    do
    {
        printf("0 - sair\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - mostrar\n");


        printf("Digite a sua Opção: ");
        scanf("%d", &opcoes);
        printf("\n");

        switch (opcoes)
        {

        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            printf("Digite o Valor: ");
            scanf("%d", &valor_adicionar);
            push(f1, valor_adicionar);
            break;
        case 2:
            pop(f1);
            break;
        case 3:
            mostra(f1);
            break;
        default:
            printf("Opção Não Existente");
        }

    } while (opcoes != 0);
}