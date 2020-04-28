#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct lista
{
    int qtd;
    struct registro *ini;
} lista;

typedef struct registro
{
    char texto;
    struct registro *prox;
} registro;

void push(char txt, lista *point);
registro *aloca_reg();
lista *aloca_lista();
void pop(lista *point);
void show(lista *point);
void equa(lista *point);

int main()
{
    int opc = 0;
    char txt[1000];
    lista *point;
    point = aloca_lista();

    do
    {
        printf("1 --> show\n");
        printf("2 --> Equacoes. \n");
        printf("9 --> Sair. \n");
        scanf("%d", &opc);
        switch (opc)
        {

        case 1:
            show(point);
            break;
        case 2:
            equa(point);
            break;
        default:
            break;
        }

    } while (opc != 9);

    return 0;
}
lista *aloca_lista()
{
    struct lista *p1;
    p1 = (lista *)malloc(sizeof(lista));
    p1->ini = NULL;
    p1->qtd = 0;

    return p1;
}
registro *aloca_reg()
{
    struct registro *l1;
    l1 = (registro *)malloc(sizeof(registro));
    l1->prox = NULL;

    return l1;
}

void push(char txt, lista *point)
{
    struct registro *atual;

    if (point->ini == NULL)
    {
        point->ini = aloca_reg();
        point->qtd = 1;
        point->ini = aloca_reg();
        point->ini->texto = txt;
    }
    else
    {
        point->qtd += 1;
        atual = point->ini;
        point->ini = aloca_reg();
        point->ini->texto = txt;
        point->ini->prox = atual;
    }
}
void pop(lista *point)
{
    if (point->ini != NULL)
    {
        point->ini = point->ini->prox;
        point->qtd--;
    }
    else
        printf("pilha vazia \n");
}
void show(lista *point)
{
    struct registro *atual;
    if (point->ini != NULL)
    {
        atual = point->ini;
        while (atual != NULL)
        {
            printf("char %c \n", atual->texto);
            atual = atual->prox;
        }
    }
    else
    {
        printf("Lista vazia \n");
    }
}
void equa(lista *point)
{
    int j;
    char txt[1000];
    printf("Insira o texto: \n");
    __fpurge(stdin);
    fgets(txt, 1000, stdin);
    txt[strlen(txt) - 1] = '\0';

    for (j = 0; j < strlen(txt); j++)
    {
        if (txt[j] == '(')
            push(txt[j], point);
        else if (txt[j] == ')')
            pop(point);
    }
    if (point->ini == NULL)
        printf("Equacao correta. \n");
    else
    {
        printf("Algo esta errado ai... \n \n");
        while (point->ini != NULL)
            pop(point);
    }
}
