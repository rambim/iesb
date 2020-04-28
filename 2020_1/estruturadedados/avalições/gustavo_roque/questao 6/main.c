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

void iniciar(lista * point);

int main()
{
    int opc = 0, ret = 0, num = 0, qtd = 0;
    char nome[50];
    lista * point;


    do{
        printf("1 --> Inserir. \n");
        printf("2 --> Iniciar. \n");

        printf("9 --> Sair. \n");
            scanf("%d", &opc);
        switch(opc)
        {
        case 1:
            printf("Insira o numero: \n");
                scanf("%d", &qtd);

            // free(point);
            point = aloca_lista();
            for(int i = 1; i<=qtd; i++)
                inserir(i, point);

            break;
        case 2:
            iniciar(point);
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
                point->qtd--;
                return 1;
            }
            else if(atual == point->ini && atual->num == num)
            {
                point->ini = point->ini->prox;
                point->qtd--;
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


void iniciar(lista * point)
{
    struct registro * atual;
    printf("Removed cards: ");
    while(point->qtd>=2)
    {
        atual = point->ini->prox;
        printf("%d; ", point->ini->num);
        remover(point->ini->num, point);

        remover(point->ini->num, point);
        inserir(atual->num, point);
    }
    printf("\n\n");
    printf("remaining cards: %d. \n", point->ini->num);

}
