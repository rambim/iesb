#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct registro * ini;
}lista;

typedef struct registro{
    int pos, num;
    struct registro * prox;
}registro;


void inserir_ini(int num, lista * point);
registro * aloca_reg();
lista * aloca_lista();
void achar(int num, lista * point);
void mostrar(lista * point);


int main()
{
    int opc = 0, ret = 0, num = 0, qtd = 0, i;
    lista * point;
    point = aloca_lista();

    do{
        printf("1 --> Inserir. \n");
        printf("2 --> Achar. \n");
        printf("3 --> Mostrar. \n");

        printf("9 --> Sair. \n");
            scanf("%d", &opc);
        switch(opc)
        {
        case 1:

            printf("Insira a quantidade de registros:\n");
                scanf("%d", &qtd);

            printf("Insira os valores:\n");
            for( i = 0; i<qtd; i++)
            {
                num = 0;
                scanf("%d", &num);
                inserir_ini(num, point);
            }
            break;
        case 2:
            printf("Insira o numero que deseja achar:\n");
                scanf("%d", &num);
            achar(num, point);
            break;
        case 3:
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
    p1->ini = NULL;
    p1->qtd = 0;

    return p1;
}
registro * aloca_reg()
{
    struct registro * l1;
    l1 = (registro*)malloc(sizeof(registro));
    l1->num = 0;
    l1->pos = 0;
    l1->prox = NULL;

    return l1;
}


void inserir_ini(int num, lista * point)
{
    struct registro * atual;

    if (point->ini == NULL)
    {
        point->ini = aloca_reg();
        point->qtd = 1;
        atual = point->ini;
        atual->num = num;
        atual->pos = 0;
    }
    else
    {
        atual = point->ini;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = aloca_reg();
        atual->prox->num= num;
        atual->prox->pos =point->qtd;
        point->qtd +=1;
    }
}

void achar(int num, lista * point)
{
    int achado = 0;
    struct registro *ant, *atual;
    if(point->ini != NULL)
    {
        atual = point->ini;
        ant  = point->ini;
        while(atual!=NULL)
        {
            if(atual->num == num && atual != point->ini)
            {
                achado = 1;
                printf("%d Numero achado.\n%d anterior de tal. \n", atual->num, ant->num);
                if(atual->prox != NULL)
                    printf("%d Proximo de tal. \n \n", atual->prox->num);

                break;
            }
            else if (atual == point->ini && atual->num == num)
            {
                achado = 1;
                printf("%d Numero achado no inicio. \n", atual->num);
                printf("%d Proximo de tal. \n \n", atual->prox->num);
                break;
            }
            else
            {
                ant = atual;
                atual = atual->prox;
            }
        }
        if(achado == 0)
            printf("Numero nao achado \n");
    }
    else
        printf("Lista vazia. \n \n");
}

void mostrar(lista * point)
{
    struct registro * atual;
    if (point->ini != NULL)
    {
        atual = point->ini;
        while (atual != NULL)
        {
            printf("Numero %d ; posicao %d \n", atual->num, atual->pos);
            atual = atual->prox;
        }
    }
    else
    {
        printf("Lista vazia \n");
    }
}


