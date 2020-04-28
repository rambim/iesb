#include <stdio.h>
#include <stdlib.h>

void show(int *x, int tam);
int push1(int num, int *x, int tam);
int push2(int num, int *x, int tam);
int pop1(int *x, int final1);
int pop2(int *x, int final2);


int main()
{
    int tam, opc = 0, *pilha, i, tamanho, num, final1 = 0, final2 = 12;

    printf("Insira o tamanho dos vetores (1 tamanho max para os 2 vetores): \n");
        scanf("%d", &tamanho);

    tam = tamanho*2+2;

    pilha = (int*)malloc(sizeof(int)*tam);

    for(i = 0; i< tam; i++)
        pilha[i] = -1;

    do{
        printf("1 -- push 1. \n");
        printf("2 -- Push 2.\n");
        printf("3 -- Pop 1. \n");
        printf("4 -- Pop 2. \n");
        printf("5 -- Show pilhas. \n");
        printf("9 -- exit. \n \n");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            printf("Insira o numero:\n");
                scanf("%d", &num);

            if(final1 <= tamanho-1)
                final1 = push1(num, pilha, tamanho);
            else
                printf("Esta pilha esta cheia.\n\n");
            break;
        case 2:
            printf("Insira o numero:\n");
                scanf("%d", &num);
            if(final2 >= tamanho+2)
                final2 = push2(num, pilha, tamanho);
            else
                printf("Esta pilha esta cheia.\n\n");
            break;
        case 3:
            if(pilha[1] != -1)
                final1 = pop1(pilha, final1);
            else
                printf("Pilha vazia. \n");
            break;
        case 4:
            if(pilha[tam*2+1] != -1)
                final2 = pop2(pilha, final2);
            else
                printf("Pilha vazia. \n");
            break;
        case 5:
            show(pilha,tamanho);
            break;
        default:
            break;
        }
    }while(opc != 9);
    return 0;
}

int push1(int num, int *x, int tam)
{
    int i;
    for (i = 1; i<=tam; i++)
    {
        if(x[i] == -1)
        {
            x[i] = num;
            return i;
        }
    }
}
int push2(int num, int *x, int tam)
{
    int i, j;
    j = tam*2+1;
    for (i = j; i>=tam+2; i--)
    {
        if(x[i] == -1)
        {
            x[i] = num;
            return i;
        }
    }
}

int pop1(int *x, int final1)
{
    x[final1] = -1;

    return (final1-1);
}
int pop2(int *x, int final2)
{
    x[final2] = -1;

    return (final2+1);
}

void show(int *x, int tam)
{
    int i = tam;

    printf("Pilha 1. \n \n");

    for (; i>=1; i--)
        printf("Num: %d. \n", x[i]);

    printf("\n\n");
    printf("Pilha 2. \n \n");

    for (i = tam+2; i<=tam*2+1; i++)
        printf("Num: %d. \n", x[i]);
}
