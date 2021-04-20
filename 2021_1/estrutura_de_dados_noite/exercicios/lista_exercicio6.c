/*
Utilizando as seguintes estruturas, construa um programa que implemente as seguintes funções:
insert ou enqueue - insere itens numa fila (ao final).
remove ou dequeue - retira itens de uma fila (primeiro item).
empty - veriica se a fila está vazia.
size - retorna o tamanho da fila.
front - retorna o próximo item da fila sem retirar o mesmo da fila
*/
typedef struct fila
{
    int tamanho;
    struct elemento * inicio;
    struct elemento * final;
}fila;

typedef struct elemento
{
    int valor;
    struct elemento * prox;
}elemento;

