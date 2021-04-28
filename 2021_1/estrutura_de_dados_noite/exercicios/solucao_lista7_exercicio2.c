
/* 2)
O aeroporto de Congonhas recebe todos os dias uma média de 600 pousos e decolagens, ou cerca de 36 por hora. 
No último ano, foram exatamente 223.989 movimentos aéreos. Para organizar todo o fluxo de aviões que chegam a 
Congonhas e saem de lá, a torre de controle funciona o tempo inteiro com nível máximo de atenção. Para descartar 
qualquer possibilidade de erro humano o chefe do controle de tráfego aéreo de Congonhas contratou você para desenvolver 
um programa que organize automaticamente o fluxo de aviões no campo de pouso. Para isso, basta seguir o seguinte protocolo, 
os aviões que veem do lado Oeste da pista têm maior prioridade de serem colocados na fila, pois são aqueles que estão mais 
próximo do localizador (início da pista).  Já os aviões que estão se aproximando pelo lado Norte e Sul, devem ser inseridos 
na fila 1 por vez, ou seja, insere-se 1 avião do lado Norte e em seguida 1 avião do lado Sul. Por último, insere-se o próximo 
avião que esteja se aproximando ao lado leste da pista.

Entrada
A entrada é composta por um número inteiro P, representando o ponto cardeal do avião que entrou no campo da pista (-4 <= P <= -1), 
onde (-4 representa o lado leste, -3 o lado norte, -2 lado sul e -1 lado oeste) . Em seguida é realizada a entrada dos respectivos 
aviões, compostos de um identificador começando com a letra “A” seguida de um número inteiro I (1 <= I <= 1000). A qualquer momento 
é permitido trocar o ponto cardeal, e inserir novas aeronaves, repetidamente até que o controlador finalize a sessão com o dígito 0. 

Saída
A saída é composta de uma linha contendo as aeronaves enfileiradas pela ordem do protocolo estabelecido pelo aeroporto.

EXEMPLO DE ENTRADA:
-4 leste
A1 X
A26 X
A38
A23
-1 oeste
A80 X
A40
-2 sul
A2 X
A16 X
A108
-3 norte
A20 X
A44 X
0

EXEMPLO DE SAÍDA
A80 (OESTE) A20 (NORTE) A2(SUL) A1(LESTE) A40(OESTE) A44(NORTE) A16(SUL) A26 (LESTE) A108(SUL) A38 (LESTE) A23 (LESTE)

-4 leste
A12
A33 X
-3 norte
A8
A33
-2 sul
A77
A102
A866
-3 norte
A21
A15
A9
-1 oeste
A2
0

A2(oeste) A8(norte) A77(sul) A12(leste) A33(norte) A102(sul) A33(leste) A21(norte) A866(sul) A15 A9


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct fila
{
    int tamanho;
    struct elemento *inicio;
    struct elemento *fim;
} fila;

typedef struct elemento
{
    int valor;
    struct elemento *prox;
} elemento;

fila *aloca_fila();
elemento *aloca_elemento();
void insert(fila *f, int x);
int dequeue(fila *f);
int empty(fila *f);
int size(fila *f);
int front(fila *f);
void menu(fila *f);
void mostrar_fila(fila *f);

int main()
{
    char texto[10];
    int n = -10;

    fila *leste, *oeste, *norte, *sul, *final;
    leste = aloca_fila();
    oeste = aloca_fila();
    norte = aloca_fila();
    sul = aloca_fila();
    final = aloca_fila();
    int flag = 0;
    //

    while (n != 0)
    {
        scanf("%s", texto);
        n = atoi(texto);

        if (n < 0)
        {
            switch (n)
            {
            case -1: //oeste
                flag = -1;
                break;
            case -2: // sul
                flag = -2;
                break;
            case -3: //norte
                flag = -3;
                break;
            case -4: // leste
                flag = -4;
                break;
            }
        }
        else
        {
            n = atoi(&texto[1]);
            if (n != 0)
            {
                switch (flag)
                {
                case -1: //oeste
                    insert(oeste, n);
                    break;
                case -2: // sul
                    insert(sul, n);
                    break;
                case -3: //norte
                    insert(norte, n);
                    break;
                case -4: // leste
                    insert(leste, n);
                    break;
                }
            }
        }
    }


    while(!empty(norte) || !empty(sul) || !empty(leste) || !empty(oeste))
    {
        if (!empty(oeste))
            insert(final,dequeue(oeste));
        if (!empty(norte))
            insert(final,dequeue(norte));
        if (!empty(sul))
            insert(final,dequeue(sul));
        if (!empty(leste))
            insert(final,dequeue(leste));
    }


    mostrar_fila(final);




    // printf("\n Mostrando fila Oeste");
    // mostrar_fila(oeste);
    // printf("\n Mostrando fila Leste");
    // mostrar_fila(leste);
    // printf("\n Mostrando fila Norte");
    // mostrar_fila(norte);
    // printf("\n Mostrando fila Sul");
    // mostrar_fila(sul);

    printf("\n");
    return 0;
}

fila *aloca_fila()
{
    fila *novo;
    novo = (fila *)calloc(1, sizeof(fila));
    return novo;
}

elemento *aloca_elemento()
{
    elemento *novo;
    novo = (elemento *)calloc(1, sizeof(elemento));
    return novo;
}

void insert(fila *f, int x)
{
    elemento *novo;
    novo = aloca_elemento();
    novo->valor = x;

    if (f->inicio == NULL && f->fim == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;
}

int dequeue(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
        return 0;

    int retorno;
    elemento *aux;

    aux = f->inicio;
    f->inicio = aux->prox;
    retorno = aux->valor;
    free(aux);
    f->tamanho--;
    if (f->tamanho == 0)
        f->fim = NULL;
    return retorno;
}

int empty(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
        return 1;
    else
        return 0;
}

int size(fila *f)
{
    return f->tamanho;
}

int front(fila *f)
{
    return f->inicio->valor;
}

void mostrar_fila(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
        printf("\n Fila vazia");
    else
    {
        elemento *aux;
        aux = f->inicio;
        printf("\n");
        while (aux != NULL)
        {
            printf("A%d ", aux->valor);
            aux = aux->prox;
        }
    }
}