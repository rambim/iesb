/*

1)
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base.  
A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha.
Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.
Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.
Cada linha de entrada (com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. 
Cada número de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a 
segunda linha apresenta a carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. 
A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, 
cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. 
Nenhuma linha tem espaços extras no início ou no final. Veja exemplo para conferir o formato esperado.

Exemplo de entrada:
7
19
10
6
0

Exemplo de saída:
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4

*/



#include <stdio.h>
#include <stdlib.h>
#define TAM 10


void mostrar_fila();
void inicializar_vetor();
int pop_fila();
void push_fila(int numero);
int size();

int fila[TAM];
int inicio = 0;
int fim = 0;
int tamanho=0;


int main()
{
    int n = 1;
    int i;
    int numero;
    inicializar_vetor();
    while (n != 0)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            push_fila(i);
        }

        printf("\nDiscarded cards: ");
        while (size() >= 2)
        {
            numero = pop_fila();
            printf(" %d", numero);
            numero = pop_fila();
            push_fila(numero);
        }

        numero = pop_fila();
        printf("\n Remaining card: %d\n",numero);
    }

    printf("\n");
    return 0;
}



void mostrar_fila()
{
    int i;
    printf("\n Fila: ");
    for (i = 0; i < TAM; i++)
    {
        printf(" %d", fila[i]);
    }
}

void inicializar_vetor()
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        fila[i] = -1;
    }
}

void push_fila(int numero)
{
    if (inicio == fim && fila[fim] != -1)
    {
        printf("\n Fila cheia");
    }
    else
    {
        fila[fim] = numero;
        fim++;
        if (fim >= TAM)
        {
            fim = 0;
        }
        tamanho++;
    }
}

int pop_fila()
{

    int retorno;
    if (inicio == fim && fila[inicio] == -1)
    {
        printf("\n Fila vazia");
        return -1;
    }
    else
    {
        retorno = fila[inicio];
        fila[inicio] = -1;
        inicio++;
        if (inicio >= TAM)
        {
            inicio = 0;
        }
        tamanho--;
    }
    return retorno;
}

int size()
{
    return tamanho;
}