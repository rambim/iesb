#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct registro * ini, *fim;
}lista;

typedef struct registro{
    int pos, num;
    struct registro * prox, *anter;
}registro;

void inserir(int num, lista * point);
registro * aloca_reg();
lista * aloca_lista();
int remover(int num, lista * point);
void mostrar(lista * point);
int primo(int num);
void remove_primo(lista * point);

int main()
{
    int opc = 0, ret = 0, num = 0, qtd = 0;
    char nome[50];
    lista * point;
    point = aloca_lista();

    do{
        printf("1 --> Inserir. \n");
        printf("2 --> Remover. \n");
        printf("3 --> Mostrar. \n");
        printf("4 --> Remove primo. \n");
        printf("9 --> Sair. \n");
            scanf("%d", &opc);
        switch(opc)
        {
        case 1:
            printf("Insira a quantidade de registros: \n");
                scanf("%d", &qtd);

            printf("Insira os registros: \n");
            for(int i = 0; i<qtd; i++)
            {
                num = 0;
                printf("Numero-> ");
                    scanf("%d", &num);
                inserir(num, point);
            }
            break;
        case 2:
            printf("Insira o numero que deseja excluir: \n");
                scanf("%d", &num);

            ret = remover(num, point);

            if(ret != 0)
                printf("%d Numero encontrado e excluido. \n", num);
            else
                printf("Num nao encontrado \n");

            break;
        case 3:
            mostrar(point);
            break;
        case 4:
            remove_primo(point);
            mostrar(point);
            break;
        default:
            break;

        }

    }while(opc != 9);

    return 0;
}
lista * aloca_lista()
{
    struct lista * p1;
    p1 = (lista*)malloc(sizeof(lista));
    p1->fim = NULL;
    p1->ini = NULL;
    p1->qtd = 0;

    return p1;
}
registro * aloca_reg()
{
    struct registro * l1;
    l1 = (registro*)malloc(sizeof(registro));
    l1->anter = NULL;
    l1->num = 0;
    l1->pos = 0;
    l1->prox = NULL;
    return l1;
}

void inserir(int num, lista * point)
{
    struct registro * atual, *ant;

    if (point->ini == NULL)
    {
        point->ini = aloca_reg();
        point->qtd = 1;
        atual = point->ini;
        atual->num = num;
        atual->pos = point->qtd;


    }
    else
    {
        atual = point->ini;
        while (atual->prox != NULL)
            atual = atual->prox;

        point->qtd +=1;
        atual->prox = aloca_reg();
        ant = atual;
        atual = atual->prox;
        atual->anter = ant;
        atual->num = num;
        atual->pos = point->qtd;
        point->fim = atual;
    }
}
int remover(int num, lista * point)
{
    int count = 0;
    struct registro * atual, *ant;
    if (point->ini != NULL)
    {
        atual = point->ini;
        ant = point->ini;
        while(atual != NULL)
        {
            if(atual->num == num && atual != point->ini)
            {
                if(atual == point->fim)
                    point->fim = ant;
                ant->prox = atual->prox;
                free(atual);

                return 1;
            }
            else if(atual == point->ini && atual->num == num)
            {
                point->ini = point->ini->prox;
                return 1;
            }

            else
            {
                ant = atual;
                atual = atual->prox;
            }
        }
        return 0;
    }
    else
    {
        printf("Lista vazia \n");
        return 0;
    }
    return 0;
}

void mostrar(lista * point)
{
    struct registro * atual;
    if (point->ini != NULL)
    {
        atual = point->ini;
        while (atual != NULL)
        {
            printf("Numero %d\n", atual->num);
            atual = atual->prox;
        }
    }
    else
        printf("Lista vazia \n");

}

void remove_primo(lista * point)
{
    int trash;
    struct registro * atual, * aux;

    if (point->ini != NULL)
    {
        atual = point->ini;
        while (atual != NULL)
        {
            if(primo(atual->num) == 1)
            {
                aux = atual->prox;
                printf("%d Removido. \n", atual->num);
                trash = remover(atual->num, point);
                atual = aux;
            }
            else
                atual = atual->prox;
        }

    }
    else
        printf("Lista vazia \n");
}

int primo(int num)
{
    int x;
    if (num == 2 )
        return 1;
    else if ( num == 0 ||  num == 1)
    {
         return 0;
    }
    else
    {
        for (x = 2; x<num; x++)
        {
            if (num % x == 0)
                return 0;
        }
        return 1;
    }

    return 0;
}
